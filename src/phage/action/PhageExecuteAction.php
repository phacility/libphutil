<?php

final class PhageExecuteAction
  extends PhageAction {

  private $command;
  private $label;
  private $timeout;

  private $exitCode;
  private $didTimeout;

  public function isContainerAction() {
    return false;
  }

  public function setCommand(PhutilCommandString $command) {
    $this->command = $command;
    return $this;
  }

  public function getCommand() {
    return $this->command;
  }

  public function setLabel($label) {
    $this->label = $label;
    return $this;
  }

  public function getLabel() {
    return $this->label;
  }

  public function setTimeout($timeout) {
    $this->timeout = $timeout;
    return $this;
  }

  public function getTimeout() {
    return $this->timeout;
  }

  public function setExitCode($exit_code) {
    $this->exitCode = $exit_code;
    return $this;
  }

  public function getExitCode() {
    return $this->exitCode;
  }

  public function setDidTimeout($did_timeout) {
    $this->didTimeout = $did_timeout;
    return $this;
  }

  public function getDidTimeout() {
    return $this->didTimeout;
  }

}
