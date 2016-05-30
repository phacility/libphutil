<?php

/**
 * Oversees a daemon and restarts it if it fails.
 */
final class PhutilDaemonOverseer extends Phobject {

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
  private $modules = array();
  private $verbose;
  private $err = 0;
  private $lastPidfile;
  private $startEpoch;
  private $autoscale = array();

  public function __construct(array $argv) {
    PhutilServiceProfiler::getInstance()->enableDiscardMode();

    $args = new PhutilArgumentParser($argv);
    $args->setTagline(pht('daemon overseer'));
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
          'help' => pht('Enable debug memory tracing.'),
        ),
        array(
          'name'  => 'verbose',
          'help'  => pht('Enable verbose activity logging.'),
        ),
        array(
          'name' => 'label',
          'short' => 'l',
          'param' => 'label',
          'help' => pht(
            'Optional process label. Makes "%s" nicer, no behavioral effects.',
            'ps'),
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
        pht('You may not instantiate more than one Overseer per process.'));
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
          pht(
            "Specified daemon PID directory ('%s') does not exist or is ".
            "not writable by the daemon user!",
            $dir));
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
        throw new Exception(pht('Unable to fork!'));
      } else if ($pid) {
        exit(0);
      }
    }

    $this->modules = PhutilDaemonOverseerModule::getAllModules();

    declare(ticks = 1);
    pcntl_signal(SIGUSR2, array($this, 'didReceiveNotifySignal'));

    pcntl_signal(SIGHUP,  array($this, 'didReceiveReloadSignal'));
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
      $config += array(
        'argv' => array(),
        'autoscale' => array(),
      );

      $daemon = new PhutilDaemonHandle(
        $this,
        $config['class'],
        $this->argv,
        array(
          'log' => $this->log,
          'argv' => $config['argv'],
          'load' => $this->libraries,
          'autoscale' => $config['autoscale'],
        ));

      $daemon->setSilent((!$this->traceMode && !$this->verbose));
      $daemon->setTraceMemory($this->traceMemory);

      $this->addDaemon($daemon, $config);
    }

    $should_reload = false;

    while (true) {
      foreach ($this->modules as $module) {
        try {
          if ($module->shouldReloadDaemons()) {
            $should_reload = true;
          }
        } catch (Exception $ex) {
          phlog($ex);
        }
      }
      if ($should_reload) {
        $this->didReceiveReloadSignal(SIGHUP);
        $should_reload = false;
      }

      $futures = array();
      foreach ($this->getDaemonHandles() as $daemon) {
        $daemon->update();
        if ($daemon->isRunning()) {
          $futures[] = $daemon->getFuture();
        }

        if ($daemon->isDone()) {
          $this->removeDaemon($daemon);
        }
      }

      $this->updatePidfile();
      $this->updateAutoscale();

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

  private function addDaemon(PhutilDaemonHandle $daemon, array $config) {
    $id = $daemon->getDaemonID();
    $this->daemons[$id] = array(
      'handle' => $daemon,
      'config' => $config,
    );

    $autoscale_group = $this->getAutoscaleGroup($daemon);
    if ($autoscale_group) {
      $this->autoscale[$autoscale_group][$id] = true;
    }

    return $this;
  }

  private function removeDaemon(PhutilDaemonHandle $daemon) {
    $id = $daemon->getDaemonID();

    $autoscale_group = $this->getAutoscaleGroup($daemon);
    if ($autoscale_group) {
      unset($this->autoscale[$autoscale_group][$id]);
    }

    unset($this->daemons[$id]);

    $daemon->didRemoveDaemon();

    return $this;
  }

  private function getAutoscaleGroup(PhutilDaemonHandle $daemon) {
    return $this->getAutoscaleProperty($daemon, 'group');
  }

  private function getAutoscaleProperty(
    PhutilDaemonHandle $daemon,
    $key,
    $default = null) {

    $id = $daemon->getDaemonID();
    $autoscale = $this->daemons[$id]['config']['autoscale'];
    return idx($autoscale, $key, $default);
  }

  public function didBeginWork(PhutilDaemonHandle $daemon) {
    $id = $daemon->getDaemonID();
    $busy = idx($this->daemons[$daemon->getDaemonID()], 'busy');
    if (!$busy) {
      $this->daemons[$id]['busy'] = time();
    }
  }

  public function didBeginIdle(PhutilDaemonHandle $daemon) {
    $id = $daemon->getDaemonID();
    unset($this->daemons[$id]['busy']);
  }

  public function updateAutoscale() {
    foreach ($this->autoscale as $group => $daemons) {
      $daemon = $this->daemons[head_key($daemons)]['handle'];
      $scaleup_duration = $this->getAutoscaleProperty($daemon, 'up', 2);
      $max_pool_size = $this->getAutoscaleProperty($daemon, 'pool', 8);
      $reserve = $this->getAutoscaleProperty($daemon, 'reserve', 0);

      // Don't scale a group if it is already at the maximum pool size.
      if (count($daemons) >= $max_pool_size) {
        continue;
      }

      $should_scale = true;
      foreach ($daemons as $daemon_id => $ignored) {
        $busy = idx($this->daemons[$daemon_id], 'busy');
        if (!$busy) {
          // At least one daemon in the group hasn't reported that it has
          // started work.
          $should_scale = false;
          break;
        }

        if ((time() - $busy) < $scaleup_duration) {
          // At least one daemon in the group was idle recently, so we have
          // not fullly
          $should_scale = false;
          break;
        }
      }

      // If we have a configured memory reserve for this pool, it tells us that
      // we should not scale up unless there's at least that much memory left
      // on the system (for example, a reserve of 0.25 means that 25% of system
      // memory must be free to autoscale).
      if ($should_scale && $reserve) {
        // On some systems this may be slightly more expensive than other
        // checks, so only do it once we're prepared to scale up.
        $memory = PhutilSystem::getSystemMemoryInformation();
        $free_ratio = ($memory['free'] / $memory['total']);

        // If we don't have enough free memory, don't scale.
        if ($free_ratio <= $reserve) {
          continue;
        }
      }

      if ($should_scale) {
        $config = $this->daemons[$daemon_id]['config'];

        $config['autoscale']['clone'] = true;

        $clone = new PhutilDaemonHandle(
          $this,
          $config['class'],
          $this->argv,
          array(
            'log' => $this->log,
            'argv' => $config['argv'],
            'load' => $this->libraries,
            'autoscale' => $config['autoscale'],
          ));

        $this->addDaemon($clone, $config);

        // Don't scale more than one pool up per iteration. Otherwise, we could
        // break the memory barrier if we have a lot of pools and scale them
        // all up at once.
        return;
      }
    }
  }

  public function didReceiveNotifySignal($signo) {
    foreach ($this->getDaemonHandles() as $daemon) {
      $daemon->didReceiveNotifySignal($signo);
    }
  }

  public function didReceiveReloadSignal($signo) {
    foreach ($this->getDaemonHandles() as $daemon) {
      $daemon->didReceiveReloadSignal($signo);
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
        'pid' => (int)$pid,
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
