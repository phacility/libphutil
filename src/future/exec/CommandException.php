<?php

/**
 * Exception thrown when a system command fails.
 * @group exec
 */
final class CommandException extends Exception {

  protected $command;
  protected $stdout;
  protected $stderr;
  protected $error;

  public function __construct($message, $command, $error, $stdout, $stderr) {
    parent::__construct($message);
    $this->command = $command;
    $this->error = $error;
    $this->stdout = $stdout;
    $this->stderr = $stderr;
  }

  public function getCommand() {
    return $this->command;
  }

  public function getError() {
    return $this->error;
  }

  public function getStdout() {
    return $this->stdout;
  }

  public function getStderr() {
    return $this->stderr;
  }
}

