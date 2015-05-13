<?php

final class PhutilInvalidStateException extends Exception {
  private $callee;
  private $function;

  public function __construct($function, $callee = null) {
    if ($callee === null) {
      $callee = idx(debug_backtrace(), 1);
      $callee = idx($callee, 'function');
    }

    $this->callee   = $callee;
    $this->function = $function;

    parent::__construct(
      pht(
        'Call %s before calling %s!',
        $this->function.'()',
        $this->callee.'()'));
  }

  public function getCallee() {
    return $this->callee;
  }

  public function getFunction() {
    return $this->function;
  }
}
