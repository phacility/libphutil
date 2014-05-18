<?php

final class PhutilTypeCheckException extends Exception {

  public function __construct(
    PhutilTypeSpec $type,
    $value,
    $name = null,
    $err = null) {

    if ($name !== null) {
      $invalid = pht(
        "Parameter '%s' has invalid type.",
        $name);
    } else {
      $invalid = pht('Parameter has invalid type.');
    }

    if ($type->getType() == 'regex') {
      if (is_string($value)) {
        $message = pht(
          "Expected a regular expression, but '%s' is not valid: %s",
          $value,
          $err);
      } else {
        $message = pht(
          'Expected a regular expression, but value is not valid: %s',
          $err);
      }
    } else {
      $message = pht(
        "Expected type '%s', got type '%s'.",
        $type->toString(),
        PhutilTypeSpec::getTypeOf($value));
    }

    parent::__construct($invalid.' '.$message);
  }

}
