<?php

final class PhageExecuteAction
  extends PhageAction {

  private $command;
  private $label;
  private $exitCode;

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

  public function setExitCode($exit_code) {
    $this->exitCode = $exit_code;
    return $this;
  }

  public function getExitCode() {
    return $this->exitCode;
  }

}
