<?php

final class PhutilProcessRef
  extends Phobject {

  private $pid;
  private $command;
  private $isOverseer;
  private $instance;

  public function setPID($pid) {
    $this->pid = $pid;
    return $this;
  }

  public function getPID() {
    return $this->pid;
  }

  public function setCommand($command) {
    $this->command = $command;
    return $this;
  }

  public function getCommand() {
    return $this->command;
  }

  public function setIsOverseer($is_overseer) {
    $this->isOverseer = $is_overseer;
    return $this;
  }

  public function getIsOverseer() {
    return $this->isOverseer;
  }

  public function setInstance($instance) {
    $this->instance = $instance;
    return $this;
  }

  public function getInstance() {
    return $this->instance;
  }

}
