<?php

/*
 * Copyright 2012 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * Improve PHP error logs and optionally route errors, exceptions and debugging
 * information to a central listener.
 *
 * This class takes over the PHP error and exception handlers when you call
 * ##PhutilErrorHandler::initialize()## and forwards all debugging information
 * to a listener you install with ##PhutilErrorHandler::setErrorListener()##.
 *
 * To use PhutilErrorHandler, which will enhance the messages printed to the
 * PHP error log, just initialize it:
 *
 *    PhutilErrorHandler::initialize();
 *
 * This will also enable @{function:phlog}, for printing development debugging
 * messages.
 *
 * To additionally install a custom listener which can print error information
 * to some other file or console, register a listener:
 *
 *    PhutilErrorHandler::setErrorListener($some_callback);
 *
 * For information on writing an error listener, see
 * @{function:phutil_error_listener_example}. Providing a listener is optional,
 * you will benefit from improved error logs even without one.
 *
 * Phabricator uses this class to drive the DarkConsole "Error Log" plugin.
 *
 * @task config Configuring Error Dispatch
 * @task internal Internals
 * @group error
 */
final class PhutilErrorHandler {

  private static $errorListener = null;
  private static $initialized = false;

  const EXCEPTION   = 'exception';
  const ERROR       = 'error';
  const PHLOG       = 'phlog';
  const DEPRECATED  = 'deprecated';


/* -(  Configuring Error Dispatch  )----------------------------------------- */


  /**
   * Registers this class as the PHP error and exception handler. This will
   * overwrite any previous handlers!
   *
   * @return void
   * @task config
   */
  public static function initialize() {
    self::$initialized = true;
    set_error_handler(array('PhutilErrorHandler', 'handleError'));
    set_exception_handler(array('PhutilErrorHandler', 'handleException'));
  }

  /**
   * Provide an optional listener callback which will receive all errors,
   * exceptions and debugging messages. It can then print them to a web console,
   * for example.
   *
   * See @{function:phutil_error_listener_example} for details about the
   * callback parameters and operation.
   *
   * @return void
   * @task config
   */
  public static function setErrorListener($listener) {
    self::$errorListener = $listener;
  }


/* -(  Internals  )---------------------------------------------------------- */


  /**
   * Determine if PhutilErrorHandler has been initialized.
   *
   * @return bool True if initialized.
   * @task internal
   */
  public static function hasInitialized() {
    return self::$initialized;
  }


  /**
   * Handles PHP errors and dispatches them forward. This is a callback for
   * ##set_error_handler()##. You should not call this function directly; use
   * @{function:phlog} to print debugging messages or ##trigger_error()## to
   * trigger PHP errors.
   *
   * This handler converts E_RECOVERABLE_ERROR messages from violated typehints
   * into @{class:InvalidArgumentException}s.
   *
   * This handler converts other E_RECOVERABLE_ERRORs into
   * @{class:RuntimeException}s.
   *
   * This handler converts E_NOTICE messages from uses of undefined variables
   * into @{class:RuntimeException}s.
   *
   * @param int Error code.
   * @param string Error message.
   * @param string File where the error occurred.
   * @param int Line on which the error occurred.
   * @param wild Error context information.
   * @return void
   * @task internal
   */
  public static function handleError($num, $str, $file, $line, $ctx) {

    // Convert typehint failures into exceptions.
    if (preg_match('/^Argument (\d+) passed to (\S+) must be/', $str)) {
      throw new InvalidArgumentException($str);
    }

    // Convert other E_RECOVERABLE_ERRORs into generic runtime exceptions.
    if ($num == E_RECOVERABLE_ERROR) {
      throw new RuntimeException($str);
    }

    // Convert uses of undefined variables into exceptions.
    if (preg_match('/^Undefined variable: /', $str)) {
      throw new RuntimeException($str);
    }

    // Convert uses of undefined properties into exceptions.
    if (preg_match('/^Undefined property: /', $str)) {
      throw new RuntimeException($str);
    }

    $trace = debug_backtrace();
    array_shift($trace);
    self::dispatchErrorMessage(
      self::ERROR,
      $str,
      array(
        'file'       => $file,
        'line'       => $line,
        'context'    => $ctx,
        'error_code' => $num,
        'trace'      => $trace,
      ));
  }

  /**
   * Handles PHP exceptions and dispatches them forward. This is a callback for
   * ##set_exception_handler()##. You should not call this function directly;
   * to print exceptions, pass the exception object to @{function:phlog}.
   *
   * @param Exception Uncaught exception object.
   * @return void
   * @task internal
   */
  public static function handleException(Exception $ex) {
    self::dispatchErrorMessage(
      self::EXCEPTION,
      $ex,
      array(
        'file'  => $ex->getFile(),
        'line'  => $ex->getLine(),
        'trace' => $ex->getTrace(),
        'catch_trace' => debug_backtrace(),
      ));

    // Normally, PHP exits with code 255 after an uncaught exception is thrown.
    // However, if we install an exception handler (as we have here), it exits
    // with code 0 instead. Script execution terminates after this function
    // exits in either case, so exit explicitly with the correct exit code.
    exit(255);
  }

  /**
   * Output a stacktrace to the PHP error log.
   *
   * @param trace A stacktrace, e.g. from debug_backtrace();
   * @return void
   * @task internal
   */
  public static function outputStacktrace($trace) {
    foreach ($trace as $key => $entry) {
      $line = '  #'.$key.' ';
      if (isset($entry['class'])) {
        $line .= $entry['class'].'::';
      }
      $line .= idx($entry, 'function', '');

      if (isset($entry['args'])) {
        $args = array();
        foreach ($entry['args'] as $arg) {
          $args[] = PhutilReadableSerializer::printShort($arg);
        }
        $line .= '('.implode(', ', $args).')';
      }

      if (isset($entry['file'])) {
        $line .= ' called at ['.$entry['file'].':'.$entry['line'].']';
      }
      error_log($line);
    }
  }

  /**
   * All different types of error messages come here before they are
   * dispatched to the listener; this method also prints them to the PHP error
   * log.
   *
   * @param const Event type constant.
   * @param wild Event value.
   * @param dict Event metadata.
   * @return void
   * @task internal
   */
  public static function dispatchErrorMessage($event, $value, $metadata) {
    $timestamp = strftime("%F %T");

    switch ($event) {
      case PhutilErrorHandler::ERROR:
        if (error_reporting() === 0) {
          // Respect the use of "@" to silence warnings: if this error was
          // emitted from a context where "@" was in effect, the
          // value returned by error_reporting() will be 0. This is the
          // recommended way to check for this, see set_error_handler() docs
          // on php.net.
          break;
        }
        $default_message = sprintf(
          '[%s] ERROR %d: %s at [%s:%d]',
          $timestamp,
          $metadata['error_code'],
          $value,
          $metadata['file'],
          $metadata['line']);

        $metadata['default_message'] = $default_message;
        error_log($default_message);
        self::outputStacktrace($metadata['trace']);
        break;
      case PhutilErrorHandler::EXCEPTION:
        $default_message = sprintf(
          '[%s] EXCEPTION: %s at [%s:%d]',
          $timestamp,
          '('.get_class($value).') '.$value->getMessage(),
          $value->getFile(),
          $value->getLine());

        $metadata['default_message'] = $default_message;
        error_log($default_message);
        self::outputStacktrace($value->getTrace());
        break;
      case PhutilErrorHandler::PHLOG:
        $default_message = sprintf(
          '[%s] PHLOG: %s at [%s:%d]',
          $timestamp,
          PhutilReadableSerializer::printShort($value),
          $metadata['file'],
          $metadata['line']);

        $metadata['default_message'] = $default_message;
        error_log($default_message);
        break;
      case PhutilErrorHandler::DEPRECATED:
        $default_message = sprintf(
          '[%s] DEPRECATED: %s is deprecated; %s',
          $timestamp,
          $value,
          $metadata['why']);

        $metadata['default_message'] = $default_message;
        error_log($default_message);
        break;
      default:
        error_log('Unknown event '.$event);
        break;
    }

    if (self::$errorListener) {
      static $handling_error;
      if ($handling_error) {
        error_log(
          "Error handler was reentered, some errors were not passed to the ".
          "listener.");
        return;
      }
      $handling_error = true;
      call_user_func(self::$errorListener, $event, $value, $metadata);
      $handling_error = false;
    }
  }
}
