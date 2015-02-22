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

  private $config;
  private $daemons = array();
  private $traceMode;
  private $traceMemory;
  private $daemonize;
  private $piddir;
  private $log;
  private $libraries = array();
  private $verbose;
  private $err = 0;
  private $lastPidfile;
  private $startEpoch;

  public function __construct(array $argv) {
    PhutilServiceProfiler::getInstance()->enableDiscardMode();

    $args = new PhutilArgumentParser($argv);
    $args->setTagline('daemon overseer');
    $args->setSynopsis(<<<EOHELP
**launch_daemon.php** [__options__] __daemon__
    Launch and oversee an instance of __daemon__.
EOHELP
      );
    $args->parseStandardArguments();
    $args->parse(
      array(
        array(
          'name' => 'trace-memory',
          'help' => 'Enable debug memory tracing.',
        ),
        array(
          'name'  => 'verbose',
          'help'  => 'Enable verbose activity logging.',
        ),
        array(
          'name' => 'label',
          'short' => 'l',
          'param' => 'label',
          'help' => pht(
            'Optional process label. Makes "ps" nicer, no behavioral effects.'),
        ),
      ));
    $argv = array();

    if ($args->getArg('trace')) {
      $this->traceMode = true;
      $argv[] = '--trace';
    }

    if ($args->getArg('trace-memory')) {
      $this->traceMode = true;
      $this->traceMemory = true;
      $argv[] = '--trace-memory';
    }
    $verbose = $args->getArg('verbose');
    if ($verbose) {
      $this->verbose = true;
      $argv[] = '--verbose';
    }

    $label = $args->getArg('label');
    if ($label) {
      $argv[] = '-l';
      $argv[] = $label;
    }

    $this->argv = $argv;

    if (function_exists('posix_isatty') && posix_isatty(STDIN)) {
      fprintf(STDERR, pht('Reading daemon configuration from stdin...')."\n");
    }
    $config = @file_get_contents('php://stdin');
    $config = id(new PhutilJSONParser())->parse($config);

    $this->libraries = idx($config, 'load');
    $this->log = idx($config, 'log');
    $this->daemonize = idx($config, 'daemonize');
    $this->piddir = idx($config, 'piddir');

    $this->config = $config;

    if (self::$instance) {
      throw new Exception(
        'You may not instantiate more than one Overseer per process.');
    }

    self::$instance = $this;

    $this->startEpoch = time();

    // Check this before we daemonize, since if it's an issue the child will
    // exit immediately.
    if ($this->piddir) {
      $dir = $this->piddir;
      try {
        Filesystem::assertWritable($dir);
      } catch (Exception $ex) {
        throw new Exception(
          "Specified daemon PID directory ('{$dir}') does not exist or is ".
          "not writable by the daemon user!");
      }
    }

    if (!idx($config, 'daemons')) {
      throw new PhutilArgumentUsageException(
        pht('You must specify at least one daemon to start!'));
    }

    if ($this->log) {
      // NOTE: Now that we're committed to daemonizing, redirect the error
      // log if we have a `--log` parameter. Do this at the last moment
      // so as many setup issues as possible are surfaced.
      ini_set('error_log', $this->log);
    }

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

    declare(ticks = 1);
    pcntl_signal(SIGUSR2, array($this, 'didReceiveNotifySignal'));

    pcntl_signal(SIGINT,  array($this, 'didReceiveGracefulSignal'));
    pcntl_signal(SIGTERM, array($this, 'didReceiveTerminalSignal'));
  }

  public function addLibrary($library) {
    $this->libraries[] = $library;
    return $this;
  }

  public function run() {
    $this->daemons = array();

    foreach ($this->config['daemons'] as $config) {
      $daemon = new PhutilDaemonHandle(
        $this,
        $config['class'],
        $this->argv,
        array(
          'log' => $this->log,
          'argv' => $config['argv'],
          'load' => $this->libraries,
        ));

      $daemon->setSilent((!$this->traceMode && !$this->verbose));
      $daemon->setTraceMemory($this->traceMemory);

      $this->daemons[] = array(
        'config' => $config,
        'handle' => $daemon,
      );
    }

    while (true) {
      $futures = array();
      foreach ($this->getDaemonHandles() as $daemon) {
        $daemon->update();
        if ($daemon->isRunning()) {
          $futures[] = $daemon->getFuture();
        }
      }

      $this->updatePidfile();

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
    foreach ($this->getDaemonHandles() as $daemon) {
      $daemon->didReceiveNotifySignal($signo);
    }
  }

  public function didReceiveGracefulSignal($signo) {
    // If we receive SIGINT more than once, interpret it like SIGTERM.
    if ($this->inGracefulShutdown) {
      return $this->didReceiveTerminalSignal($signo);
    }
    $this->inGracefulShutdown = true;

    foreach ($this->getDaemonHandles() as $daemon) {
      $daemon->didReceiveGracefulSignal($signo);
    }
  }

  public function didReceiveTerminalSignal($signo) {
    $this->err = 128 + $signo;
    if ($this->inAbruptShutdown) {
      exit($this->err);
    }
    $this->inAbruptShutdown = true;

    foreach ($this->getDaemonHandles() as $daemon) {
      $daemon->didReceiveTerminalSignal($signo);
    }
  }

  private function getDaemonHandles() {
    return ipull($this->daemons, 'handle');
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

  private function updatePidfile() {
    if (!$this->piddir) {
      return;
    }

    $daemons = array();

    foreach ($this->daemons as $daemon) {
      $handle = $daemon['handle'];
      $config = $daemon['config'];

      if (!$handle->isRunning()) {
        continue;
      }

      $daemons[] = array(
        'pid' => $handle->getPID(),
        'id' => $handle->getDaemonID(),
        'config' => $config,
      );
    }

    $pidfile = array(
      'pid' => getmypid(),
      'start' => $this->startEpoch,
      'config' => $this->config,
      'daemons' => $daemons,
    );

    if ($pidfile !== $this->lastPidfile) {
      $this->lastPidfile = $pidfile;
      $pidfile_path = $this->piddir.'/daemon.'.getmypid();
      Filesystem::writeFile($pidfile_path, json_encode($pidfile));
    }
  }

}
