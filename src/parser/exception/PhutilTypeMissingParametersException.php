<?php

final class PhutilTypeMissingParametersException extends Exception {

  private $parameters;

  public function getParameters() {
    return $this->parameters;
  }

  public function __construct(array $missing) {
    $message = pht(
      'Missing required parameters: %s',
      implode(', ', $missing));

    parent::__construct($message);

    $this->parameters = $missing;
  }

}
