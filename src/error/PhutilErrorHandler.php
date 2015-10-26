<?php

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
 * @task config   Configuring Error Dispatch
 * @task exutil   Exception Utilities
 * @task trap     Error Traps
 * @task internal Internals
 */
final class PhutilErrorHandler extends Phobject {

  private static $errorListener = null;
  private static $initialized = false;
  private static $traps = array();

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
    set_error_handler(array(__CLASS__, 'handleError'));
    set_exception_handler(array(__CLASS__, 'handleException'));
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


/* -(  Exception Utilities  )------------------------------------------------ */


  /**
   * Gets the previous exception of a nested exception. Prior to PHP 5.3 you
   * can use @{class:PhutilProxyException} to nest exceptions; after PHP 5.3
   * all exceptions are nestable.
   *
   * @param   Exception|Throwable       Exception to unnest.
   * @return  Exception|Throwable|null  Previous exception, if one exists.
   * @task    exutil
   */
  public static function getPreviousException($ex) {
    if (method_exists($ex, 'getPrevious')) {
      return $ex->getPrevious();
    }
    if (method_exists($ex, 'getPreviousException')) {
      return $ex->getPreviousException();
    }
    return null;
  }


  /**
   * Find the most deeply nested exception from a possibly-nested exception.
   *
   * @param   Exception|Throwable     A possibly-nested exception.
   * @return  Exception|Throwable     Deepest exception in the nest.
   * @task    exutil
   */
  public static function getRootException($ex) {
    $root = $ex;
    while (self::getPreviousException($root)) {
      $root = self::getPreviousException($root);
    }
    return $root;
  }


/* -(  Trapping Errors  )---------------------------------------------------- */


  /**
   * Adds an error trap. Normally you should not invoke this directly;
   * @{class:PhutilErrorTrap} registers itself on construction.
   *
   * @param PhutilErrorTrap Trap to add.
   * @return void
   * @task trap
   */
  public static function addErrorTrap(PhutilErrorTrap $trap) {
    $key = $trap->getTrapKey();
    self::$traps[$key] = $trap;
  }


  /**
   * Removes an error trap. Normally you should not invoke this directly;
   * @{class:PhutilErrorTrap} deregisters itself on destruction.
   *
   * @param PhutilErrorTrap Trap to remove.
   * @return void
   * @task trap
   */
  public static function removeErrorTrap(PhutilErrorTrap $trap) {
    $key = $trap->getTrapKey();
    unset(self::$traps[$key]);
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

    foreach (self::$traps as $trap) {
      $trap->addError($num, $str, $file, $line, $ctx);
    }

    if ((error_reporting() & $num) == 0) {
      // Respect the use of "@" to silence warnings: if this error was
      // emitted from a context where "@" was in effect, the
      // value returned by error_reporting() will be 0. This is the
      // recommended way to check for this, see set_error_handler() docs
      // on php.net.
      return false;
    }

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

    // Convert undefined constants into exceptions. Usually this means there
    // is a missing `$` and the program is horribly broken.
    if (preg_match('/^Use of undefined constant /', $str)) {
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
   * @param Exception|Throwable Uncaught exception object.
   * @return void
   * @task internal
   */
  public static function handleException($ex) {
    self::dispatchErrorMessage(
      self::EXCEPTION,
      $ex,
      array(
        'file'  => $ex->getFile(),
        'line'  => $ex->getLine(),
        'trace' => self::getExceptionTrace($ex),
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
    $lines = explode("\n", self::formatStacktrace($trace));
    foreach ($lines as $line) {
      error_log($line);
    }
  }


  /**
   * Format a stacktrace for output.
   *
   * @param trace A stacktrace, e.g. from debug_backtrace();
   * @return string Human-readable trace.
   * @task internal
   */
  public static function formatStacktrace($trace) {
    $result = array();

    $libinfo = self::getLibraryVersions();
    if ($libinfo) {
      foreach ($libinfo as $key => $dict) {
        $info = array();
        foreach ($dict as $dkey => $dval) {
          $info[] = $dkey.'='.$dval;
        }
        $libinfo[$key] = $key.'('.implode(', ', $info).')';
      }
      $result[] = implode(', ', $libinfo);
    }

    foreach ($trace as $key => $entry) {
      $line = '  #'.$key.' ';
      if (!empty($entry['xid'])) {
        if ($entry['xid'] != 1) {
          $line .= '<#'.$entry['xid'].'> ';
        }
      }
      if (isset($entry['class'])) {
        $line .= $entry['class'].'::';
      }
      $line .= idx($entry, 'function', '');

      if (isset($entry['args'])) {
        $args = array();
        foreach ($entry['args'] as $arg) {

          // NOTE: Print out object types, not values. Values sometimes contain
          // sensitive information and are usually not particularly helpful
          // for debugging.

          $type = (gettype($arg) == 'object')
            ? get_class($arg)
            : gettype($arg);
          $args[] = $type;
        }
        $line .= '('.implode(', ', $args).')';
      }

      if (isset($entry['file'])) {
        $file = self::adjustFilePath($entry['file']);
        $line .= ' called at ['.$file.':'.$entry['line'].']';
      }

      $result[] = $line;
    }
    return implode("\n", $result);
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
    $timestamp = strftime('%Y-%m-%d %H:%M:%S');

    switch ($event) {
      case self::ERROR:
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
      case self::EXCEPTION:
        $messages = array();
        $current = $value;
        do {
          $messages[] = '('.get_class($current).') '.$current->getMessage();
        } while ($current = self::getPreviousException($current));
        $messages = implode(' {>} ', $messages);

        if (strlen($messages) > 4096) {
          $messages = substr($messages, 0, 4096).'...';
        }

        $default_message = sprintf(
          '[%s] EXCEPTION: %s at [%s:%d]',
          $timestamp,
          $messages,
          self::adjustFilePath(self::getRootException($value)->getFile()),
          self::getRootException($value)->getLine());

        $metadata['default_message'] = $default_message;
        error_log($default_message);
        self::outputStacktrace($metadata['trace']);
        break;
      case self::PHLOG:
        $default_message = sprintf(
          '[%s] PHLOG: %s at [%s:%d]',
          $timestamp,
          PhutilReadableSerializer::printShort($value),
          $metadata['file'],
          $metadata['line']);

        $metadata['default_message'] = $default_message;
        error_log($default_message);
        break;
      case self::DEPRECATED:
        $default_message = sprintf(
          '[%s] DEPRECATED: %s is deprecated; %s',
          $timestamp,
          $value,
          $metadata['why']);

        $metadata['default_message'] = $default_message;
        error_log($default_message);
        break;
      default:
        error_log(pht('Unknown event %s', $event));
        break;
    }

    if (self::$errorListener) {
      static $handling_error;
      if ($handling_error) {
        error_log(
          'Error handler was reentered, some errors were not passed to the '.
          'listener.');
        return;
      }
      $handling_error = true;
      call_user_func(self::$errorListener, $event, $value, $metadata);
      $handling_error = false;
    }
  }

  public static function adjustFilePath($path) {
    // Compute known library locations so we can emit relative paths if the
    // file resides inside a known library. This is a little cleaner to read,
    // and limits the number of false positives we get about full path
    // disclosure via HackerOne.

    $bootloader = PhutilBootloader::getInstance();
    $libraries = $bootloader->getAllLibraries();
    $roots = array();
    foreach ($libraries as $library) {
      $root = $bootloader->getLibraryRoot($library);
      // For these libraries, the effective root is one level up.
      switch ($library) {
        case 'phutil':
        case 'arcanist':
        case 'phabricator':
          $root = dirname($root);
          break;
      }

      if (!strncmp($root, $path, strlen($root))) {
        return '<'.$library.'>'.substr($path, strlen($root));
      }
    }

    return $path;
  }

  public static function getLibraryVersions() {
    $libinfo = array();

    $bootloader = PhutilBootloader::getInstance();
    foreach ($bootloader->getAllLibraries() as $library) {
      $root = phutil_get_library_root($library);
      $try_paths = array(
        $root,
        dirname($root),
      );
      $libinfo[$library] = array();

      $get_refs = array('master');
      foreach ($try_paths as $try_path) {
        // Try to read what the HEAD of the repository is pointed at. This is
        // normally the name of a branch ("ref").
        $try_file = $try_path.'/.git/HEAD';
        if (@file_exists($try_file)) {
          $head = @file_get_contents($try_file);
          $matches = null;
          if (preg_match('(^ref: refs/heads/(.*)$)', trim($head), $matches)) {
            $libinfo[$library]['head'] = trim($matches[1]);
            $get_refs[] = trim($matches[1]);
          } else {
            $libinfo[$library]['head'] = trim($head);
          }
          break;
        }
      }

      // Try to read which commit relevant branch heads are at.
      foreach (array_unique($get_refs) as $ref) {
        foreach ($try_paths as $try_path) {
          $try_file = $try_path.'/.git/refs/heads/'.$ref;
          if (@file_exists($try_file)) {
            $hash = @file_get_contents($try_file);
            if ($hash) {
              $libinfo[$library]['ref.'.$ref] = substr(trim($hash), 0, 12);
              break;
            }
          }
        }
      }

      // Look for extension files.
      $custom = @scandir($root.'/extensions/');
      if ($custom) {
        $count = 0;
        foreach ($custom as $custom_path) {
          if (preg_match('/\.php$/', $custom_path)) {
            $count++;
          }
        }
        if ($count) {
          $libinfo[$library]['custom'] = $count;
        }
      }
    }

    ksort($libinfo);

    return $libinfo;
  }

  /**
   * Get a full trace across all proxied and aggregated exceptions.
   *
   * This attempts to build a set of stack frames which completely represent
   * all of the places an exception came from, even if it came from multiple
   * origins and has been aggregated or proxied.
   *
   * @param Exception|Throwable Exception to retrieve a trace for.
   * @return list<wild> List of stack frames.
   */
  public static function getExceptionTrace($ex) {
    $id = 1;

    // Keep track of discovered exceptions which we need to build traces for.
    $stack = array(
      array($id, $ex),
    );

    $frames = array();
    while ($info = array_shift($stack)) {
      list($xid, $ex) = $info;

      // We're going from top-level exception down in bredth-first order, but
      // want to build a trace in approximately standard order (deepest part of
      // the call stack to most shallow) so we need to reverse each list of
      // frames and then reverse everything at the end.

      $ex_frames = array_reverse($ex->getTrace());
      $ex_frames = array_values($ex_frames);
      $last_key = (count($ex_frames) - 1);
      foreach ($ex_frames as $frame_key => $frame) {
        $frame['xid'] = $xid;

        // If this is a child/previous exception and we're on the deepest frame
        // and missing file/line data, fill it in from the exception itself.
        if ($xid > 1 && ($frame_key == $last_key)) {
          if (empty($frame['file'])) {
            $frame['file'] = $ex->getFile();
            $frame['line'] = $ex->getLine();
          }
        }

        // Since the exceptions are likely to share the most shallow frames,
        // try to add those to the trace only once.
        if (isset($frame['file']) && isset($frame['line'])) {
          $signature = $frame['file'].':'.$frame['line'];
          if (empty($frames[$signature])) {
            $frames[$signature] = $frame;
          }
        } else {
          $frames[] = $frame;
        }
      }

      // If this is a proxy exception, add the proxied exception.
      $prev = self::getPreviousException($ex);
      if ($prev) {
        $stack[] = array(++$id, $prev);
      }

      // If this is an aggregate exception, add the child exceptions.
      if ($ex instanceof PhutilAggregateException) {
        foreach ($ex->getExceptions() as $child) {
          $stack[] = array(++$id, $child);
        }
      }
    }

    return array_values(array_reverse($frames));
  }

}
