<?php

final class PhutilNumber {

  private $value;

  public function __construct($value) {
    $this->value = $value;
  }

  public function getNumber() {
    return $this->value;
  }

}
