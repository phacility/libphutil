<?php

/**
 * An exception thrown when a method is called on a class which does not
 * provide an implementation for the called method. This is sometimes the case
 * when a base class expects subclasses to provide their own implementations,
 * for example.
 */
final class PhutilMethodNotImplementedException extends Exception {

  public function __construct($message = null) {
    if ($message) {
      parent::__construct($message);
    } else {
      $caller = idx(debug_backtrace(), 1);

      if (isset($caller['object'])) {
        $class = get_class($caller['object']);
      } else {
        $class = idx($caller, 'class');
      }

      $function = idx($caller, 'function');

      if ($class) {
        parent::__construct(
          pht('Method %s in class %s is not implemented!', $function, $class));
      } else {
        parent::__construct(pht('Function %s is not implemented!', $function));
      }
    }
  }

}
