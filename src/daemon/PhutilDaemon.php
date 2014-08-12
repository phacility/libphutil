<?php

/**
 * Scaffolding for implementing robust background processing scripts.
 *
 * @stable
 */
abstract class PhutilDaemon {

  private $argv;
  private $traceMode;
  private $traceMemory;
  private $verbose;
  private $notifyReceived;
  private $inGracefulShutdown;

  final public function setVerbose($verbose) {
    $this->verbose = $verbose;
    return $this;
  }

  final public function getVerbose() {
    return $this->verbose;
  }

  private static $sighandlerInstalled;

  final public function __construct(array $argv) {

    declare(ticks = 1);
    $this->argv = $argv;

    if (!self::$sighandlerInstalled) {
      self::$sighandlerInstalled = true;
      pcntl_signal(SIGTERM, __CLASS__.'::exitOnSignal');
    }

    pcntl_signal(SIGINT,  array($this, 'onGracefulSignal'));
    pcntl_signal(SIGUSR2, array($this, 'onNotifySignal'));

    // Without discard mode, this consumes unbounded amounts of memory. Keep
    // memory bounded.
    PhutilServiceProfiler::getInstance()->enableDiscardMode();
  }

  final public function stillWorking() {
    if (!posix_isatty(STDOUT)) {
      posix_kill(posix_getppid(), SIGUSR1);
    }
    if ($this->traceMemory) {
      $memuse = number_format(memory_get_usage() / 1024, 1);
      $daemon = get_class($this);
      fprintf(STDERR, '%s', "<RAMS> {$daemon} Memory Usage: {$memuse} KB\n");
    }
  }

  final public function shouldExit() {
    return $this->inGracefulShutdown;
  }

  final protected function sleep($duration) {
    $this->notifyReceived = false;
    $this->willSleep($duration);
    $this->stillWorking();
    while ($duration > 0 &&
      !$this->notifyReceived &&
      !$this->shouldExit()) {
      sleep(min($duration, 60));
      $duration -= 60;
      $this->stillWorking();
    }
  }

  protected function willSleep($duration) {
    return;
  }

  public static function exitOnSignal($signo) {
    // Normally, PHP doesn't invoke destructors when existing in response to
    // a signal. This forces it to do so, so we have a fighting chance of
    // releasing any locks, leases or resources on our way out.
    exit(128 + $signo);
  }

  final protected function getArgv() {
    return $this->argv;
  }

  final public function execute() {
    $this->willRun();
    $this->run();
  }

  abstract protected function run();

  final public function setTraceMemory() {
    $this->traceMemory = true;
    return $this;
  }

  final public function getTraceMemory() {
    return $this->traceMemory;
  }

  final public function setTraceMode() {
    $this->traceMode = true;
    PhutilServiceProfiler::installEchoListener();
    PhutilConsole::getConsole()->getServer()->setEnableLog(true);
    $this->didSetTraceMode();
    return $this;
  }

  final public function getTraceMode() {
    return $this->traceMode;
  }

  final public function onGracefulSignal($signo) {
    $this->inGracefulShutdown = true;
  }

  final public function onNotifySignal($signo) {
    $this->notifyReceived = true;
    $this->onNotify($signo);
  }

  protected function onNotify($signo) {
    // This is a hook for subclasses.
  }

  protected function willRun() {
    // This is a hook for subclasses.
  }

  protected function didSetTraceMode() {
    // This is a hook for subclasses.
  }

  final protected function log($message) {
    if ($this->verbose) {
      $daemon = get_class($this);
      fprintf(STDERR, '%s', "<VERB> {$daemon} {$message}\n");
    }
  }

}
