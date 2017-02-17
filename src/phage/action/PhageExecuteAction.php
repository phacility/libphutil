<?php

final class PhageExecuteAction
  extends PhageAction {

  private $command;
  private $label;

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

}
