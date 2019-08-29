<?php

abstract class PhutilProgressSink
  extends Phobject {

  private $isRunning;
  private $totalWork;
  private $completedWork;

  public function __construct() {
    $this->isRunning = true;
  }

  public function __destruct() {
    if ($this->isRunning) {
      $this->didFailWork();
    }
  }

  final public function setTotalWork($total_work) {
    $this->totalWork = $total_work;
    return $this;
  }

  final public function getTotalWork() {
    return $this->totalWork;
  }

  final public function getCompletedWork() {
    return $this->completedWork;
  }

  final public function didMakeProgress($amount = 1) {
    if ($this->isRunning) {
      $this->completedWork += $amount;
      $this->publishProgress();
    }
  }

  final public function didCompleteWork() {
    $this->isRunning = false;
    $this->publishCompletion();
  }

  final public function didFailWork() {
    $this->isRunning = false;
    $this->publishFailure();
  }

  abstract protected function publishProgress();
  abstract protected function publishCompletion();
  abstract protected function publishFailure();

}
