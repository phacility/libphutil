<?php

/**
 * Prior to PHP 5.3, PHP does not support nested exceptions; this class provides
 * limited support for nested exceptions. Use methods on
 * @{class:PhutilErrorHandler} to unnest exceptions in a forward-compatible way.
 *
 * @concrete-extensible
 */
class PhutilProxyException extends Exception {

  private $previousException;

  public function __construct($message, $previous, $code = 0) {
    $this->previousException = $previous;

    // This may be an "Exception" or a "Throwable". The "__construct()" method
    // for the Exception is documented as taking an Exception, not a Throwable.
    // Although passing a Throwable appears to work in PHP 7.3, don't risk it.
    $is_exception = ($previous instanceof Exception);

    if (version_compare(PHP_VERSION, '5.3.0', '>=') && $is_exception) {
      parent::__construct($message, $code, $previous);
    } else {
      parent::__construct($message, $code);
    }
  }

  public function getPreviousException() {
    // NOTE: This can not be named "getPrevious()" because that method is final
    // after PHP 5.3. Similarly, the property can not be named "previous"
    // because HPHP declares a property with the same name and "protected"
    // visibility.
    return $this->previousException;
  }

}
