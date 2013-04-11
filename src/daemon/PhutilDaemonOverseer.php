<?php

/**
 * Oversees a daemon and restarts it if it fails.
 *
 * @group daemon
 */
final class PhutilDaemonOverseer {

  const HEARTBEAT_WAIT = 120;

  private $captureBufferSize = 65536;

  private $deadline;
  private $deadlineTimeout  = 86400;
  private $restartDelay     = 60;
  private $killDelay        = 3;
  private $heartbeat;

  private $daemon;
  private $argv;
  private $childPID;
  private $signaled;
  private static $instance;

  private $traceMode;
  private $traceMemory;
  private $daemonize;
  private $phddir;
  private $conduit;
  private $conduitURI;
  private $verbose;

  public function __construct(array $argv) {
    PhutilServiceProfiler::getInstance()->enableDiscardMode();

    $original_argv = $argv;
    $args = new PhutilArgumentParser($argv);
    $args->setTagline('daemon overseer');
    $args->setSynopsis(<<<EOHELP
**launch_daemon.php** [__options__] __daemon__
    Launch and oversee an instance of __daemon__.
EOHELP
      );
    $args->parsePartial(
      array(
        array(
          'name' => 'trace',
          'help' => 'Enable debug tracing.',
        ),
        array(
          'name' => 'trace-memory',
          'help' => 'Enable debug memory tracing.',
        ),
        array(
          'name'  => 'log',
          'param' => 'file',
          'help'  => 'Send output to __file__.',
        ),
        array(
          'name'  => 'daemonize',
          'help'  => 'Run in the background.',
        ),
        array(
          'name'  => 'phd',
          'param' => 'dir',
          'help'  => 'Write PID information to __dir__.',
        ),
        array(
          'name'  => 'conduit-uri',
          'param' => 'uri',
          'help'  => 'Send logs to Conduit on __uri__.'
        ),
        array(
          'name'  => 'verbose',
          'help'  => 'Enable verbose activity logging.',
        ),
      ));
    $argv = $args->getUnconsumedArgumentVector();

    $this->daemon = array_shift($argv);
    if (!$this->daemon) {
      $args->printHelpAndExit();
    }

    if ($args->getArg('trace')) {
      $this->traceMode = true;
      array_unshift($argv, '--trace');
    }

    if ($args->getArg('trace-memory')) {
      $this->traceMode = true;
      $this->traceMemory = true;
      array_unshift($argv, '--trace-memory');
    }

    $log = $args->getArg('log');
    if ($log) {
      ini_set('error_log', $log);
      array_unshift($argv, '--log='.$log);
    }

    $verbose = $args->getArg('verbose');
    if ($verbose) {
      $this->verbose = true;
      array_unshift($argv, '--verbose');
    }

    $this->daemonize  = $args->getArg('daemonize');
    $this->phddir     = $args->getArg('phd');
    $this->conduitURI = $args->getArg('conduit-uri');
    $this->argv       = $argv;

    error_log("Bringing daemon '{$this->daemon}' online...");

    if (self::$instance) {
      throw new Exception(
        "You may not instantiate more than one Overseer per process.");
    }

    self::$instance = $this;

    if ($this->daemonize) {

      // We need to get rid of these or the daemon will hang when we TERM it
      // waiting for something to read the buffers. TODO: Learn how unix works.
      fclose(STDOUT);
      fclose(STDERR);
      ob_start();

      $pid = pcntl_fork();
      if ($pid === -1) {
        throw new Exception("Unable to fork!");
      } else if ($pid) {
        exit(0);
      }
    }

    if ($this->phddir) {
      $desc = array(
        'name'            => $this->daemon,
        'pid'             => getmypid(),
        'start'           => time(),
      );
      Filesystem::writeFile(
        $this->phddir.'/daemon.'.getmypid(),
        json_encode($desc));
    }

    if ($this->conduitURI) {
      $this->conduit = new ConduitClient($this->conduitURI);
      $this->daemonLogID = $this->conduit->callMethodSynchronous(
        'daemon.launched',
        array(
          'daemon'  => $this->daemon,
          'host'    => php_uname('n'),
          'pid'     => getmypid(),
          'argv'    => json_encode(array_slice($original_argv, 1)),
        ));
    }

    declare(ticks = 1);
    pcntl_signal(SIGUSR1, array($this, 'didReceiveKeepaliveSignal'));

    pcntl_signal(SIGINT,  array($this, 'didReceiveTerminalSignal'));
    pcntl_signal(SIGTERM, array($this, 'didReceiveTerminalSignal'));
  }

  public function run() {
    if ($this->shouldRunSilently()) {
      echo "Running daemon '{$this->daemon}' silently. Use '--trace' or ".
           "'--verbose' to produce debugging output.\n";
    }

    $root = phutil_get_library_root('phutil');
    $root = dirname($root);

    $exec_dir = $root.'/scripts/daemon/exec/';

    // NOTE: PHP implements proc_open() by running 'sh -c'. On most systems this
    // is bash, but on Ubuntu it's dash. When you proc_open() using bash, you
    // get one new process (the command you ran). When you proc_open() using
    // dash, you get two new processes: the command you ran and a parent
    // "dash -c" (or "sh -c") process. This means that the child process's PID
    // is actually the 'dash' PID, not the command's PID. To avoid this, use
    // 'exec' to replace the shell process with the real process; without this,
    // the child will call posix_getppid(), be given the pid of the 'sh -c'
    // process, and send it SIGUSR1 to keepalive which will terminate it
    // immediately. We also won't be able to do process group management because
    // the shell process won't properly posix_setsid() so the pgid of the child
    // won't be meaningful.

    $exec_daemon = './exec_daemon.php';
    $argv = $this->argv;
    array_unshift($argv, 'exec', $exec_daemon, $this->daemon);
    foreach ($argv as $k => $arg) {
      $argv[$k] = escapeshellarg($arg);
    }

    $command = implode(' ', $argv);

    while (true) {
      $this->logMessage('INIT', 'Starting process.');

      $future = new ExecFuture('%C', $command);
      $future->setCWD($exec_dir);
      $future->setStdoutSizeLimit($this->captureBufferSize);
      $future->setStderrSizeLimit($this->captureBufferSize);

      $this->deadline = time() + $this->deadlineTimeout;
      $this->heartbeat = time() + self::HEARTBEAT_WAIT;

      $future->isReady();
      $this->childPID = $future->getPID();

      do {
        do {
          if ($this->traceMemory) {
            $memuse = number_format(memory_get_usage() / 1024, 1);
            $this->logMessage('RAMS', 'Overseer Memory Usage: '.$memuse.' KB');
          }

          // We need a shortish timeout here so we can run the tick handler
          // frequently in order to process signals.
          $result = $future->resolve(1);

          list($stdout, $stderr) = $future->read();
          $stdout = trim($stdout);
          $stderr = trim($stderr);
          if (strlen($stdout)) {
            $this->logMessage('STDO', $stdout, $stdout);
          }
          if (strlen($stderr)) {
            $this->logMessage('STDE', $stderr, $stderr);
          }
          $future->discardBuffers();

          if ($result !== null) {
            list($err) = $result;
            if ($err) {
              $this->logMessage(
                'FAIL',
                'Process exited with error '.$err.'.',
                $err);
            } else {
              $this->logMessage('DONE', 'Process exited successfully.');
            }
            break 2;
          }
          if ($this->heartbeat < time()) {
            $this->heartbeat = time() + self::HEARTBEAT_WAIT;
            if ($this->conduitURI) {
              try {
                $this->conduit = new ConduitClient($this->conduitURI);
                $this->conduit->callMethodSynchronous(
                  'daemon.setstatus',
                  array(
                    'daemonLogID'  => $this->daemonLogID,
                    'status'       => 'run',
                  ));
              } catch (Exception $ex) {
              }
            }
          }
        } while (time() < $this->deadline);

        $this->logMessage('HANG', 'Hang detected. Restarting process.');
        $this->annihilateProcessGroup();
      } while (false);

      $this->logMessage('WAIT', 'Waiting to restart process.');
      sleep($this->restartDelay);
    }
  }

  public function didReceiveKeepaliveSignal($signo) {
    $this->deadline = time() + $this->deadlineTimeout;
  }

  public function didReceiveTerminalSignal($signo) {
    if ($this->signaled) {
      exit(128 + $signo);
    }

    echo "\n>>> Shutting down...\n";
    fflush(STDOUT);
    fflush(STDERR);
    fclose(STDOUT);
    fclose(STDERR);
    $this->signaled = true;
    $this->annihilateProcessGroup();

    if ($this->conduitURI) {
      try {
        $this->conduit = new ConduitClient($this->conduitURI);
        $this->conduit->callMethodSynchronous(
          'daemon.setstatus',
          array(
            'daemonLogID'  => $this->daemonLogID,
            'status'       => 'exit',
          ));
      } catch (Exception $ex) {
      }
    }
    exit(128 + $signo);
  }

  private function logMessage($type, $message, $remote = null) {
    if (!$this->shouldRunSilently()) {
      echo date('Y-m-d g:i:s A').' ['.$type.'] '.$message."\n";
    }
    if ($this->conduit) {
      // TODO: This is kind of sketchy to do without any timeouts since a
      // conduit server hang could throw a wrench into things.
      try {
        $this->conduit->callMethodSynchronous(
          'daemon.log',
          array(
            'daemonLogID'  => $this->daemonLogID,
            'type'         => $type,
            'message'      => $remote,
          ));
      } catch (Exception $ex) {
        // TOOD: Send this somewhere useful instead of eating it.
      }
    }
  }

  private function shouldRunSilently() {
    if ($this->traceMode || $this->verbose) {
      return false;
    } else {
      return true;
    }
  }

  private function annihilateProcessGroup() {
    $pid = $this->childPID;
    $pgid = posix_getpgid($pid);
    if ($pid && $pgid) {

      // NOTE: On Ubuntu, 'kill' does not recognize the use of "--" to
      // explicitly delineate PID/PGIDs from signals. We don't actually need it,
      // so use the implicit "kill -TERM -pgid" form instead of the explicit
      // "kill -TERM -- -pgid" form.
      exec("kill -TERM -{$pgid}");
      sleep($this->killDelay);

      // On OSX, we'll get a permission error on stderr if the SIGTERM was
      // successful in ending the life of the process group, presumably because
      // all that's left is the daemon itself as a zombie waiting for us to
      // reap it. However, we still need to issue this command for process
      // groups that resist SIGTERM. Rather than trying to figure out if the
      // process group is still around or not, just SIGKILL unconditionally and
      // ignore any error which may be raised.
      exec("kill -KILL -{$pgid} 2>/dev/null");
      $this->childPID = null;
    }
  }


  /**
   * Identify running daemons by examining the process table. This isn't
   * completely reliable, but can be used as a fallback if the pid files fail
   * or we end up with stray daemons by other means.
   *
   * Example output (array keys are process IDs):
   *
   *   array(
   *     12345 => array(
   *       'type' => 'overseer',
   *       'command' => 'php launch_daemon.php --daemonize ...',
   *     ),
   *     12346 => array(
   *       'type' => 'daemon',
   *       'command' => 'php exec_daemon.php ...',
   *     ),
   *  );
   *
   * @return dict   Map of PIDs to process information, identifying running
   *                daemon processes.
   */
  public static function findRunningDaemons() {
    $results = array();

    list($err, $processes) = exec_manual('ps -o pid,command -a -x -w -w -w');
    if ($err) {
      return $results;
    }

    $processes = array_filter(explode("\n", trim($processes)));
    foreach ($processes as $process) {
      list($pid, $command) = explode(' ', $process, 2);

      $matches = null;
      if (!preg_match('/(launch|exec)_daemon.php/', $command, $matches)) {
        continue;
      }

      $results[(int)$pid] = array(
        'type'    => ($matches[1] == 'launch') ? 'overseer' : 'daemon',
        'command' => $command,
      );
    }

    return $results;
  }

}
