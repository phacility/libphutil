<?php

final class PhutilJSONParserException extends Exception {

  private $sourceLine;
  private $sourceChar;
  private $sourceToken;
  private $expected;

  public function __construct(
    $message,
    $line = null,
    $char = null,
    $token = null,
    $expected = null) {

    $this->sourceLine = $line;
    $this->sourceChar = $char;
    $this->sourceToken = $token;
    $this->expected = $expected;

    parent::__construct(
      pht('Parse error on line %d at column %d: %s', $line, $char, $message));
  }

  public function getSourceLine() {
    return $this->sourceLine;
  }

  public function getSourceChar() {
    return $this->sourceChar;
  }

  public function getSourceToken() {
    return $this->sourceToken;
  }

  public function getExpectedTokens() {
    return $this->expected;
  }

}
