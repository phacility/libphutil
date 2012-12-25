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
    $this->command = $command;
    $this->error = $error;
    $this->stdout = $stdout;
    $this->stderr = $stderr;

    $summary = array();
    $summary[] = $this->summarize($message);

    $summary[] = "COMMAND";
    $summary[] = $this->summarize($command);

    $summary[] = null;
    $summary[] = "STDOUT";
    $summary[] = $this->summarize($stdout);

    $summary[] = null;
    $summary[] = "STDERR";
    $summary[] = $this->summarize($stderr);

    $summary = implode("\n", $summary);

    parent::__construct($summary);
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

  private function summarize($string) {
    if (!strlen($string)) {
      return '(empty)';
    }

    $limit = 1000;

    $len = strlen($string);
    if ($len <= $limit) {
      return $string;
    }

    $cut = $len - $limit;
    $suffix = "... (".number_format($cut)." more bytes) ...";

    if ($cut > strlen($suffix)) {
      return substr($string, 0, $limit).$suffix;
    } else {
      return $string;
    }
  }

}

