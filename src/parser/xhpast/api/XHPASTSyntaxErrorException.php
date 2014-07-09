<?php

final class XHPASTSyntaxErrorException extends Exception {

  protected $errorLine;

  public function __construct($line, $message) {
    $this->errorLine = $line;
    parent::__construct($message);
  }

  public function getErrorLine() {
    return $this->errorLine;
  }

}
