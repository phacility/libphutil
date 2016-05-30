<?php

final class PhutilDaemonHandle extends Phobject {

  const EVENT_DID_LAUNCH    = 'daemon.didLaunch';
  const EVENT_DID_LOG       = 'daemon.didLogMessage';
  const EVENT_DID_HEARTBEAT = 'daemon.didHeartbeat';
  const EVENT_WILL_GRACEFUL = 'daemon.willGraceful';
  const EVENT_WILL_EXIT     = 'daemon.willExit';

  private $overseer;
  private $daemonClass;
  private $argv;
  private $config;
  private $pid;
  private $daemonID;
  private $deadline;
  private $heartbeat;
  private $stdoutBuffer;
  private $restartAt;
  private $silent;
  private $shouldRestart = true;
  private $shouldShutdown;
  private $future;
  private $traceMemory;

  public function __construct(
    PhutilDaemonOverseer $overseer,
    $daemon_class,
    array $argv,
    array $config) {

    $this->overseer = $overseer;
    $this->daemonClass = $daemon_class;
    $this->argv = $argv;
    $this->config = $config;
    $this->restartAt = time();

    $this->daemonID = $this->generateDaemonID();
    $this->dispatchEvent(
      self::EVENT_DID_LAUNCH,
      array(
        'argv' => $this->argv,
        'explicitArgv' => idx($this->config, 'argv'),
      ));
  }

  public function isRunning() {
    return (bool)$this->future;
  }

  public function isDone() {
    return (!$this->shouldRestart && !$this->isRunning());
  }

  public function getFuture() {
    return $this->future;
  }

  public function setSilent($silent) {
    $this->silent = $silent;
    return $this;
  }

  public function getSilent() {
    return $this->silent;
  }

  public function setTraceMemory($trace_memory) {
    $this->traceMemory = $trace_memory;
    return $this;
  }

  public function getTraceMemory() {
    return $this->traceMemory;
  }

  public function update() {
    $this->updateMemory();

    if (!$this->isRunning()) {
      if (!$this->shouldRestart) {
        return;
      }
      if (!$this->restartAt || (time() < $this->restartAt)) {
        return;
      }
      if ($this->shouldShutdown) {
        return;
      }
      $this->startDaemonProcess();
    }

    $future = $this->future;

    $result = null;
    if ($future->isReady()) {
      $result = $future->resolve();
    }

    list($stdout, $stderr) = $future->read();
    $future->discardBuffers();

    if (strlen($stdout)) {
      $this->didReadStdout($stdout);
    }

    $stderr = trim($stderr);
    if (strlen($stderr)) {
      foreach (phutil_split_lines($stderr, false) as $line) {
        $this->logMessage('STDE', $line);
      }
    }

    if ($result !== null) {
      list($err) = $result;

      if ($err) {
        $this->logMessage('FAIL', pht('Process exited with error %s.', $err));
      } else {
        $this->logMessage('DONE', pht('Process exited normally.'));
      }

      $this->future = null;

      if ($this->shouldShutdown) {
        $this->restartAt = null;
      } else {
        $this->scheduleRestart();
      }
    }

    $this->updateHeartbeatEvent();
    $this->updateHangDetection();
  }

  private function updateHeartbeatEvent() {
    if ($this->heartbeat > time()) {
      return;
    }

    $this->heartbeat = time() + $this->getHeartbeatEventFrequency();
    $this->dispatchEvent(self::EVENT_DID_HEARTBEAT);
  }

  private function updateHangDetection() {
    if (!$this->isRunning()) {
      return;
    }

    if (time() > $this->deadline) {
      $this->logMessage('HANG', pht('Hang detected. Restarting process.'));
      $this->annihilateProcessGroup();
      $this->scheduleRestart();
    }
  }

  private function scheduleRestart() {
    $this->logMessage('WAIT', pht('Waiting to restart process.'));
    $this->restartAt = time() + self::getWaitBeforeRestart();
  }

  /**
   * Generate a unique ID for this daemon.
   *
   * @return string A unique daemon ID.
   */
  private function generateDaemonID() {
    return substr(getmypid().':'.Filesystem::readRandomCharacters(12), 0, 12);
  }

  public function getDaemonID() {
    return $this->daemonID;
  }

  public function getPID() {
    return $this->pid;
  }

  private function getCaptureBufferSize() {
    return 65535;
  }

  private function getRequiredHeartbeatFrequency() {
    return 86400;
  }

  public static function getWaitBeforeRestart() {
    return 5;
  }

  public static function getHeartbeatEventFrequency() {
    return 120;
  }

  private function getKillDelay() {
    return 3;
  }

  private function getDaemonCWD() {
    $root = dirname(phutil_get_library_root('phutil'));
    return $root.'/scripts/daemon/exec/';
  }

  private function newExecFuture() {
    $class = $this->daemonClass;
    $argv = $this->argv;
    $buffer_size = $this->getCaptureBufferSize();

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

    return id(new ExecFuture('exec ./exec_daemon.php %s %Ls', $class, $argv))
      ->setCWD($this->getDaemonCWD())
      ->setStdoutSizeLimit($buffer_size)
      ->setStderrSizeLimit($buffer_size)
      ->write(json_encode($this->config));
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
      'daemonClass' => $this->daemonClass,
      'childPID' => $this->pid,
    ) + $params;

    $event = new PhutilEvent($type, $data);

    try {
      PhutilEventEngine::dispatchEvent($event);
    } catch (Exception $ex) {
      phlog($ex);
    }
  }

  private function annihilateProcessGroup() {
    $pid = $this->pid;
    $pgid = posix_getpgid($pid);
    if ($pid && $pgid) {
      posix_kill(-$pgid, SIGTERM);
      sleep($this->getKillDelay());
      posix_kill(-$pgid, SIGKILL);
      $this->pid = null;
    }
  }

  private function updateMemory() {
    if ($this->traceMemory) {
      $this->logMessage(
        'RAMS',
        pht(
          'Overseer Memory Usage: %s KB',
          new PhutilNumber(memory_get_usage() / 1024, 1)));
    }
  }

  private function startDaemonProcess() {
    $this->logMessage('INIT', pht('Starting process.'));

    $this->deadline = time() + $this->getRequiredHeartbeatFrequency();
    $this->heartbeat = time() + self::getHeartbeatEventFrequency();
    $this->stdoutBuffer = '';

    $this->future = $this->newExecFuture();
    $this->future->start();

    $this->pid = $this->future->getPID();
  }

  private function didReadStdout($data) {
    $this->stdoutBuffer .= $data;
    while (true) {
      $pos = strpos($this->stdoutBuffer, "\n");
      if ($pos === false) {
        break;
      }
      $message = substr($this->stdoutBuffer, 0, $pos);
      $this->stdoutBuffer = substr($this->stdoutBuffer, $pos + 1);

      try {
        $structure = phutil_json_decode($message);
      } catch (PhutilJSONParserException $ex) {
        $structure = array();
      }

      switch (idx($structure, 0)) {
        case PhutilDaemon::MESSAGETYPE_STDOUT:
          $this->logMessage('STDO', idx($structure, 1));
          break;
        case PhutilDaemon::MESSAGETYPE_HEARTBEAT:
          $this->deadline = time() + $this->getRequiredHeartbeatFrequency();
          break;
        case PhutilDaemon::MESSAGETYPE_BUSY:
          $this->overseer->didBeginWork($this);
          break;
        case PhutilDaemon::MESSAGETYPE_IDLE:
          $this->overseer->didBeginIdle($this);
          break;
        case PhutilDaemon::MESSAGETYPE_DOWN:
          // The daemon is exiting because it doesn't have enough work and it
          // is trying to scale the pool down. We should not restart it.
          $this->shouldRestart = false;
          $this->shouldShutdown = true;
          break;
        default:
          // If we can't parse this or it isn't a message we understand, just
          // emit the raw message.
          $this->logMessage('STDO', pht('<Malformed> %s', $message));
          break;
      }
    }
  }

  public function didReceiveNotifySignal($signo) {
    $pid = $this->pid;
    if ($pid) {
      posix_kill($pid, $signo);
    }
  }

  public function didReceiveReloadSignal($signo) {
    $signame = phutil_get_signal_name($signo);
    if ($signame) {
      $sigmsg = pht(
        'Reloading in response to signal %d (%s).',
        $signo,
        $signame);
    } else {
      $sigmsg = pht(
        'Reloading in response to signal %d.',
        $signo);
    }

    $this->logMessage('RELO', $sigmsg, $signo);

    // This signal means "stop the current process gracefully, then launch
    // a new identical process once it exits". This can be used to update
    // daemons after code changes (the new processes will run the new code)
    // without aborting any running tasks.

    // We SIGINT the daemon but don't set the shutdown flag, so it will
    // naturally be restarted after it exits, as though it had exited after an
    // unhandled exception.

    posix_kill($this->pid, SIGINT);
  }

  public function didReceiveGracefulSignal($signo) {
    $this->shouldShutdown = true;
    $this->shouldRestart = false;

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

    posix_kill($this->pid, SIGINT);
  }

  public function didReceiveTerminalSignal($signo) {
    $this->shouldShutdown = true;
    $this->shouldRestart = false;

    $signame = phutil_get_signal_name($signo);
    if ($signame) {
      $sigmsg = pht(
        'Shutting down in response to signal %s (%s).',
        $signo,
        $signame);
    } else {
      $sigmsg = pht('Shutting down in response to signal %s.', $signo);
    }

    $this->logMessage('EXIT', $sigmsg, $signo);
    $this->annihilateProcessGroup();
  }

  private function logMessage($type, $message, $context = null) {
    if (!$this->getSilent()) {
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

  public function didRemoveDaemon() {
    $this->dispatchEvent(self::EVENT_WILL_EXIT);
  }

}
