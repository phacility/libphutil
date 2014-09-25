<?php

/**
 * Oversees a daemon and restarts it if it fails.
 */
final class PhutilDaemonOverseer {

  const EVENT_DID_LAUNCH    = 'daemon.didLaunch';
  const EVENT_DID_LOG       = 'daemon.didLogMessage';
  const EVENT_DID_HEARTBEAT = 'daemon.didHeartbeat';
  const EVENT_WILL_GRACEFUL = 'daemon.willGraceful';
  const EVENT_WILL_EXIT     = 'daemon.willExit';

  const HEARTBEAT_WAIT      = 120;
  const RESTART_WAIT        = 5;

  private $captureBufferSize = 65536;

  private $deadline;
  private $deadlineTimeout  = 86400;
  private $killDelay        = 3;
  private $heartbeat;

  private $daemon;
  private $argv;
  private $moreArgs;
  private $childPID;
  private $inAbruptShutdown;
  private $inGracefulShutdown;
  private static $instance;

  private $traceMode;
  private $traceMemory;
  private $daemonize;
  private $phddir;
  private $verbose;
  private $daemonID;

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
    $args->parseStandardArguments();
    $args->parsePartial(
      array(
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
          'name'  => 'verbose',
          'help'  => 'Enable verbose activity logging.',
        ),
        array(
          'name' => 'load-phutil-library',
          'param' => 'library',
          'repeat' => true,
          'help' => 'Load __library__.',
        ),
      ));
    $argv = array();

    $more = $args->getUnconsumedArgumentVector();

    $this->daemon = array_shift($more);
    if (!$this->daemon) {
      $args->printHelpAndExit();
    }

    if ($args->getArg('trace')) {
      $this->traceMode = true;
      $argv[] = '--trace';
    }

    if ($args->getArg('trace-memory')) {
      $this->traceMode = true;
      $this->traceMemory = true;
      $argv[] = '--trace-memory';
    }

    if ($args->getArg('load-phutil-library')) {
      foreach ($args->getArg('load-phutil-library') as $library) {
        $argv[] = '--load-phutil-library='.$library;
      }
    }

    $log = $args->getArg('log');
    if ($log) {
      ini_set('error_log', $log);
      $argv[] = '--log='.$log;
    }

    $verbose = $args->getArg('verbose');
    if ($verbose) {
      $this->verbose = true;
      $argv[] = '--verbose';
    }

    $this->daemonize  = $args->getArg('daemonize');
    $this->phddir     = $args->getArg('phd');
    $this->argv       = $argv;
    $this->moreArgs   = coalesce($more, array());

    error_log("Bringing daemon '{$this->daemon}' online...");

    if (self::$instance) {
      throw new Exception(
        'You may not instantiate more than one Overseer per process.');
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
        throw new Exception('Unable to fork!');
      } else if ($pid) {
        exit(0);
      }
    }

    if ($this->phddir) {
      $desc = array(
        'name'            => $this->daemon,
        'argv'            => $this->moreArgs,
        'pid'             => getmypid(),
        'start'           => time(),
      );
      Filesystem::writeFile(
        $this->phddir.'/daemon.'.getmypid(),
        json_encode($desc));
    }

    $this->daemonID = $this->generateDaemonID();
    $this->dispatchEvent(
      self::EVENT_DID_LAUNCH,
      array(
        'argv' => array_slice($original_argv, 1),
        'explicitArgv' => $this->moreArgs,
      ));

    declare(ticks = 1);
    pcntl_signal(SIGUSR1, array($this, 'didReceiveKeepaliveSignal'));
    pcntl_signal(SIGUSR2, array($this, 'didReceiveNotifySignal'));

    pcntl_signal(SIGINT,  array($this, 'didReceiveGracefulSignal'));
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

    // Format the exec command, which looks something like:
    //
    //   exec ./exec_daemon DaemonName --trace -- --no-discovery

    $argv = array();
    $argv[] = csprintf('exec ./exec_daemon.php %s', $this->daemon);
    foreach ($this->argv as $k => $arg) {
      $argv[] = csprintf('%s', $arg);
    }
    $argv[] = '--';
    foreach ($this->moreArgs as $k => $arg) {
      $argv[] = csprintf('%s', $arg);
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
            $this->logMessage('STDO', $stdout);
          }
          if (strlen($stderr)) {
            $this->logMessage('STDE', $stderr);
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
            $this->dispatchEvent(self::EVENT_DID_HEARTBEAT);
          }
        } while (time() < $this->deadline);

        $this->logMessage('HANG', 'Hang detected. Restarting process.');
        $this->annihilateProcessGroup();
      } while (false);

      if ($this->inGracefulShutdown) {
        // If we just exited because of a graceful shutdown, break now.
        break;
      }

      $this->logMessage('WAIT', 'Waiting to restart process.');
      sleep(self::RESTART_WAIT);

      if ($this->inGracefulShutdown) {
        // If we were awakend by a graceful shutdown, break now.
        break;
      }
    }

    // This is a clean exit after a graceful shutdown.
    $this->dispatchEvent(self::EVENT_WILL_EXIT);
    exit(0);
  }

  public function didReceiveNotifySignal($signo) {
    $pid = $this->childPID;
    if ($pid) {
      posix_kill($pid, $signo);
    }
  }

  public function didReceiveKeepaliveSignal($signo) {
    $this->deadline = time() + $this->deadlineTimeout;
  }

  public function didReceiveGracefulSignal($signo) {
    // If we receive SIGINT more than once, interpret it like SIGTERM.
    if ($this->inGracefulShutdown) {
      return $this->didReceiveTerminalSignal($signo);
    }
    $this->inGracefulShutdown = true;

    $signame = phutil_get_signal_name($signo);
    if ($signame) {
      $sigmsg = pht(
        'Graceful shutdown in response to signal %d (%s).',
        $signo,
        $signame);
    } else {
      $sigmsg = pht(
        'Graceful shutdown in response to signal %d.',
        $signo);
    }

    $this->logMessage('DONE', $sigmsg, $signo);

    $this->gracefulProcessGroup();
  }

  public function didReceiveTerminalSignal($signo) {
    if ($this->inAbruptShutdown) {
      exit(128 + $signo);
    }
    $this->inAbruptShutdown = true;

    $signame = phutil_get_signal_name($signo);
    if ($signame) {
      $sigmsg = "Shutting down in response to signal {$signo} ({$signame}).";
    } else {
      $sigmsg = "Shutting down in response to signal {$signo}.";
    }

    $this->logMessage('EXIT', $sigmsg, $signo);

    @fflush(STDOUT);
    @fflush(STDERR);
    @fclose(STDOUT);
    @fclose(STDERR);
    $this->annihilateProcessGroup();

    $this->dispatchEvent(self::EVENT_WILL_EXIT);

    exit(128 + $signo);
  }

  private function logMessage($type, $message, $context = null) {
    if (!$this->shouldRunSilently()) {
      echo date('Y-m-d g:i:s A').' ['.$type.'] '.$message."\n";
    }

    $this->dispatchEvent(
      self::EVENT_DID_LOG,
      array(
        'type' => $type,
        'message' => $message,
        'context' => $context,
      ));
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


  private function gracefulProcessGroup() {
    $pid = $this->childPID;
    $pgid = posix_getpgid($pid);
    if ($pid && $pgid) {
      exec("kill -INT -{$pgid}");
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
   *       'pid' => 12345,
   *     ),
   *     12346 => array(
   *       'type' => 'daemon',
   *       'command' => 'php exec_daemon.php ...',
   *       'pid' => 12346,
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
      if (!preg_match('/((launch|exec)_daemon.php|phd-daemon)/',
                      $command,
                      $matches)) {
        continue;
      }

      switch ($matches[1]) {
        case 'exec_daemon.php':
          $type = 'daemon';
          break;
        case 'launch_daemon.php':
        case 'phd-daemon':
        default:
          $type = 'overseer';
          break;
      }

      $results[(int)$pid] = array(
        'type'    => $type,
        'command' => $command,
        'pid' => (int) $pid,
      );
    }

    return $results;
  }


  /**
   * Generate a unique ID for this daemon.
   *
   * @return string A unique daemon ID.
   */
  private function generateDaemonID() {
    return substr(getmypid().':'.Filesystem::readRandomCharacters(12), 0, 12);
  }


  /**
   * Dispatch an event to event listeners.
   *
   * @param  string Event type.
   * @param  dict   Event parameters.
   * @return void
   */
  private function dispatchEvent($type, array $params = array()) {
    $data = array(
      'id' => $this->daemonID,
      'daemonClass' => $this->daemon,
      'childPID' => $this->childPID,
    ) + $params;

    $event = new PhutilEvent($type, $data);

    try {
      PhutilEventEngine::dispatchEvent($event);
    } catch (Exception $ex) {
      phlog($ex);
    }
  }

}
