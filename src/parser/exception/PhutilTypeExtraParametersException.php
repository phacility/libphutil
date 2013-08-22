<?php

final class PhutilTypeExtraParametersException extends Exception {

  private $parameters;

  public function getParameters() {
    return $this->parameters;
  }

  public function __construct(array $extra) {
    $message = pht(
      'Got unexpected parameters: %s',
      implode(', ', array_keys($extra)));

    parent::__construct($message);

    $this->parameters = $extra;
  }

}
