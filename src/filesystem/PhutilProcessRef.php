<?php

final class PhutilProcessRef
  extends Phobject {

  private $pid;
  private $command;
  private $isOverseer;
  private $instance;
  private $argv;

  public function setPID($pid) {
    $this->pid = $pid;
    return $this;
  }

  public function getPID() {
    return $this->pid;
  }

  public function getCommand() {
    if (!$this->command) {
      $this->command = phutil_string_cast(csprintf('%LR', $this->argv));
    }

    return $this->command;
  }

  public function getIsOverseer() {
    if ($this->isOverseer === null) {
      $this->isOverseer = $this->getCommandMatch(
        array(
          array('phd-daemon'),
          array('php', 'phd-daemon'),
        ));
    }

    return $this->isOverseer;
  }

  public function setInstance($instance) {
    $this->instance = $instance;
    return $this;
  }

  public function getInstance() {
    return $this->instance;
  }

  private function getCommandMatch(array $patterns) {
    $argv = $this->getArgv();

    foreach ($patterns as $pattern) {
      $pattern = array_values($pattern);
      $is_match = true;
      for ($ii = 0; $ii < count($pattern); $ii++) {
        if (basename($argv[$ii]) !== $pattern[$ii]) {
          $is_match = false;
          break;
        }
      }

      if ($is_match) {
        return true;
      }
    }

    return false;
  }

  public function setArgv(array $argv) {
    $this->argv = $argv;
    return $this;
  }

  public function getArgv() {
    return $this->argv;
  }

}
