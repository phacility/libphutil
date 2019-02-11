<?php

/**
 * libphutil log function for development debugging. Takes any argument and
 * forwards it to registered listeners. This is essentially a more powerful
 * version of `error_log()`.
 *
 * @param  wild  Any value you want printed to the error log or other registered
 *               logs/consoles.
 * @param  ...   Other values to be logged.
 * @return wild  Passed $value.
 */
function phlog($value/* , ... */) {
  // Get the caller information.
  $trace = debug_backtrace();
  $metadata = array(
    'file' => $trace[0]['file'],
    'line' => $trace[0]['line'],
    'trace' => $trace,
  );

  foreach (func_get_args() as $event) {
    $data = $metadata;
    if (($event instanceof Exception) || ($event instanceof Throwable)) {
      $type = PhutilErrorHandler::EXCEPTION;
      // If this is an exception, proxy it and generate a composite trace which
      // shows both where the phlog() was called and where the exception was
      // originally thrown from.
      $proxy = new PhutilProxyException('', $event);
      $trace = PhutilErrorHandler::getExceptionTrace($proxy);
      $data['trace'] = $trace;
    } else {
      $type = PhutilErrorHandler::PHLOG;
    }

    PhutilErrorHandler::dispatchErrorMessage($type, $event, $data);
  }

  return $value;
}

/**
 * Example @{class:PhutilErrorHandler} error listener callback. When you call
 * `PhutilErrorHandler::setErrorListener()`, you must pass a callback function
 * with the same signature as this one.
 *
 * NOTE: @{class:PhutilErrorHandler} handles writing messages to the error
 * log, so you only need to provide a listener if you have some other console
 * (like Phabricator's DarkConsole) which you //also// want to send errors to.
 *
 * NOTE: You will receive errors which were silenced with the `@` operator. If
 * you don't want to display these, test for `@` being in effect by checking if
 * `error_reporting() === 0` before displaying the error.
 *
 * @param  const  A PhutilErrorHandler constant, like PhutilErrorHandler::ERROR,
 *                which indicates the event type (e.g. error, exception,
 *                user message).
 * @param  wild   The event value, like the Exception object for an exception
 *                event, an error string for an error event, or some user object
 *                for user messages.
 * @param  dict   A dictionary of metadata about the event. The keys 'file',
 *                'line' and 'trace' are always available. Other keys may be
 *                present, depending on the event type.
 * @return void
 */
function phutil_error_listener_example($event, $value, array $metadata) {
  throw new Exception(pht('This is just an example function!'));
}
