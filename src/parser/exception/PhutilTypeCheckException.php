<?php

final class PhutilTypeCheckException extends Exception {

  public function __construct(PhutilTypeSpec $type, $value, $name = null) {
    if ($name !== null) {
      $message = pht(
        "Parameter '%s' has invalid type. Expected type '%s', got type '%s'.",
        $type->toString(),
        PhutilTypeSpec::getTypeOf($value));
    } else {
      $message = pht(
        "Parameter has invalid type. Expected type '%s', got type '%s'.",
        $type->toString(),
        PhutilTypeSpec::getTypeOf($value));
    }

    parent::__construct($message);
  }

}
