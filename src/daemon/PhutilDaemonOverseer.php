<?php

/**
 * Oversees a daemon and restarts it if it fails.
 */
final class PhutilDaemonOverseer {

  private $argv;
  private $moreArgs;
  private $inAbruptShutdown;
  private $inGracefulShutdown;
  private static $instance;

  private $daemon;
  private $daemons = array();
  private $traceMode;
  private $traceMemory;
  private $daemonize;
  private $phddir;
  private $verbose;
  private $err = 0;

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

    if (self::$instance) {
      throw new Exception(
        'You may not instantiate more than one Overseer per process.');
    }

    self::$instance = $this;

    // Check this before we daemonize, since if it's an issue the child will
    // exit immediately.
    if ($this->phddir) {
      $dir = $this->phddir;
      try {
        Filesystem::assertWritable($dir);
      } catch (Exception $ex) {
        throw new Exception(
          "Specified daemon PID directory ('{$dir}') does not exist or is ".
          "not writable by the daemon user!");
      }
    }

    if ($log) {
      // NOTE: Now that we're committed to daemonizing, redirect the error
      // log if we have a `--log` parameter. Do this at the last moment
      // so as many setup issues as possible are surfaced.
      ini_set('error_log', $log);
    }

    error_log("Bringing daemon '{$this->daemon}' online...");

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

    declare(ticks = 1);
    pcntl_signal(SIGUSR2, array($this, 'didReceiveNotifySignal'));

    pcntl_signal(SIGINT,  array($this, 'didReceiveGracefulSignal'));
    pcntl_signal(SIGTERM, array($this, 'didReceiveTerminalSignal'));
  }

  public function run() {
    $daemon = new PhutilDaemonHandle(
      $this,
      $this->daemon,
      $this->argv,
      $this->moreArgs);

    $daemon->setSilent((!$this->traceMode && !$this->verbose));
    $daemon->setTraceMemory($this->traceMemory);

    $this->daemons = array($daemon);
    while (true) {
      $futures = array();
      foreach ($this->daemons as $daemon) {
        $daemon->update();
        if ($daemon->isRunning()) {
          $futures[] = $daemon->getFuture();
        }
      }

      if ($futures) {
        $iter = id(new FutureIterator($futures))
          ->setUpdateInterval(1);
        foreach ($iter as $future) {
          break;
        }
      } else {
        if ($this->inGracefulShutdown) {
          break;
        }
        sleep(1);
      }
    }

    exit($this->err);
  }

  public function didReceiveNotifySignal($signo) {
    foreach ($this->daemons as $daemon) {
      $daemon->didReceiveNotifySignal($signo);
    }
  }

  public function didReceiveGracefulSignal($signo) {
    // If we receive SIGINT more than once, interpret it like SIGTERM.
    if ($this->inGracefulShutdown) {
      return $this->didReceiveTerminalSignal($signo);
    }
    $this->inGracefulShutdown = true;

    foreach ($this->daemons as $daemon) {
      $daemon->didReceiveGracefulSignal($signo);
    }
  }

  public function didReceiveTerminalSignal($signo) {
    $this->err = 128 + $signo;
    if ($this->inAbruptShutdown) {
      exit($this->err);
    }
    $this->inAbruptShutdown = true;

    foreach ($this->daemons as $daemon) {
      $daemon->didReceiveTerminalSignal($signo);
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
      list($pid, $command) = preg_split('/\s+/', trim($process), 2);

      $pattern = '/((launch|exec)_daemon.php|phd-daemon)/';
      $matches = null;
      if (!preg_match($pattern, $command, $matches)) {
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
        'type' => $type,
        'command' => $command,
        'pid' => (int) $pid,
      );
    }

    return $results;
  }

}
