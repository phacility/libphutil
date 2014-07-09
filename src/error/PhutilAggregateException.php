<?php

/**
 * Exception that aggregates other exceptions into a single exception. For
 * example, if you have several objects which can perform a task and just want
 * at least one of them to succeed, you can do something like this:
 *
 *   $exceptions = array();
 *   $success = false;
 *   foreach ($engines as $engine) {
 *     try {
 *       $engine->doSomething();
 *       $success = true;
 *       break;
 *     } catch (Exception $ex) {
 *       $exceptions[get_class($engine)] = $ex;
 *     }
 *   }
 *
 *   if (!$success) {
 *     throw new PhutilAggregateException("All engines failed:", $exceptions);
 *   }
 *
 * @concrete-extensible
 */
class PhutilAggregateException extends Exception {

  private $exceptions = array();

  public function __construct($message, array $other_exceptions) {
    // We don't call assert_instances_of($other_exceptions, 'Exception') to not
    // throw another exception in this exception.

    $this->exceptions = $other_exceptions;

    $full_message = array();
    $full_message[] = $message;
    foreach ($other_exceptions as $key => $exception) {
      $ex_message =
        (is_string($key) ? $key.': ' : '').
        get_class($exception).': '.
        $exception->getMessage();
      $ex_message = '    - '.str_replace("\n", "\n      ", $ex_message);

      $full_message[] = $ex_message;
    }

    parent::__construct(implode("\n", $full_message), count($other_exceptions));
  }

  public function getExceptions() {
    return $this->exceptions;
  }

}
