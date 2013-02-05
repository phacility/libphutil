<?php

final class PhutilNumber {

  private $value;
  private $decimals = 0;

  public function __construct($value) {
    $this->value = $value;
  }

  public function getNumber() {
    return $this->value;
  }

  public function setDecimals($decimals) {
    $this->decimals = $decimals;
    return $this;
  }

  public function getDecimals() {
    return $this->decimals;
  }

}
