<?php

/**
 * Object that writes to a logfile when it is destroyed. This allows you to add
 * more data to the log as execution unfolds, while still ensuring a write in
 * normal circumstances (see below for discussion of cases where writes may not
 * occur).
 *
 * Create the object with a logfile and format:
 *
 *   $log = new PhutilDeferredLog('/path/to/access.log', "[%T]\t%u");
 *
 * Update the log with information as it becomes available:
 *
 *   $log->setData(
 *     array(
 *       'T' => date('c'),
 *       'u' => $username,
 *    ));
 *
 * The log will be appended when the object's destructor is called, or when you
 * invoke @{method:write}. Note that programs can exit without invoking object
 * destructors (e.g., in the case of an unhandled exception, memory exhaustion,
 * or SIGKILL) so writes are not guaranteed. You can call @{method:write} to
 * force an explicit write to disk before the destructor is called.
 *
 * Log variables will be written with bytes 0x00-0x1F, 0x7F-0xFF, and backslash
 * escaped using C-style escaping. Since this range includes tab, you can use
 * tabs as field separators to ensure the file format is easily parsable. In
 * PHP, you can decode this encoding with `stripcslashes`.
 *
 * If a variable is included in the log format but a value is never provided
 * with @{method:setData}, it will be written as "-".
 *
 * @task log        Logging
 * @task write      Writing the Log
 * @task internal   Internals
 */
final class PhutilDeferredLog extends Phobject {

  private $file;
  private $format;
  private $data;
  private $didWrite;
  private $failQuietly;


/* -(  Logging  )------------------------------------------------------------ */


  /**
   * Create a new log entry, which will be written later. The format string
   * should use "%x"-style placeholders to represent data which will be added
   * later:
   *
   *   $log = new PhutilDeferredLog('/some/file.log', '[%T] %u');
   *
   * @param string|null The file the entry should be written to, or null to
   *                    create a log object which does not write anywhere.
   * @param string      The log entry format.
   * @task log
   */
  public function __construct($file, $format) {
    $this->file = $file;
    $this->format = $format;
    $this->data = array();
    $this->didWrite = false;
  }


  /**
   * Add data to the log. Provide a map of variables to replace in the format
   * string. For example, if you use a format string like:
   *
   *   "[%T]\t%u"
   *
   * ...you might add data like this:
   *
   *   $log->setData(
   *     array(
   *       'T' => date('c'),
   *       'u' => $username,
   *     ));
   *
   * When the log is written, the "%T" and "%u" variables will be replaced with
   * the values you provide.
   *
   * @param dict  Map of variables to values.
   * @return this
   * @task log
   */
  public function setData(array $map) {
    $this->data = $map + $this->data;
    return $this;
  }


  /**
   * Get existing log data.
   *
   * @param   string  Log data key.
   * @param   wild    Default to return if data does not exist.
   * @return  wild    Data, or default if data does not exist.
   * @task log
   */
  public function getData($key, $default = null) {
    return idx($this->data, $key, $default);
  }


  /**
   * Set the path where the log will be written. You can pass `null` to prevent
   * the log from writing.
   *
   * NOTE: You can not change the file after the log writes.
   *
   * @param string|null File where the entry should be written to, or null to
   *                    prevent writes.
   * @return this
   * @task log
   */
  public function setFile($file) {
    if ($this->didWrite) {
      throw new Exception(
        pht('You can not change the logfile after a write has occurred!'));
    }
    $this->file = $file;
    return $this;
  }

  public function getFile() {
    return $this->file;
  }


  /**
   * Set quiet (logged) failure, instead of the default loud (exception)
   * failure. Throwing exceptions from destructors which exit at the end of a
   * request can result in difficult-to-debug behavior.
   */
  public function setFailQuietly($fail_quietly) {
    $this->failQuietly = $fail_quietly;
    return $this;
  }


/* -(  Writing the Log  )---------------------------------------------------- */


  /**
   * When the log object is destroyed, it writes if it hasn't written yet.
   * @task write
   */
  public function __destruct() {
    $this->write();
  }


  /**
   * Write the log explicitly, if it hasn't been written yet. Normally you do
   * not need to call this method; it will be called when the log object is
   * destroyed. However, you can explicitly force the write earlier by calling
   * this method.
   *
   * A log object will never write more than once, so it is safe to call this
   * method even if the object's destructor later runs.
   *
   * @return this
   * @task write
   */
  public function write() {
    if ($this->didWrite) {
      return $this;
    }

    // Even if we aren't going to write, format the line to catch any errors
    // and invoke possible __toString() calls.
    $line = $this->format();

    try {
      if ($this->file !== null) {
        $dir = dirname($this->file);
        if (!Filesystem::pathExists($dir)) {
          Filesystem::createDirectory($dir, 0755, true);
        }

        $ok = @file_put_contents(
          $this->file,
          $line,
          FILE_APPEND | LOCK_EX);

        if ($ok === false) {
          throw new Exception(
            pht(
              'Unable to write to logfile "%s"!',
              $this->file));
        }
      }
    } catch (Exception $ex) {
      if ($this->failQuietly) {
        phlog($ex);
      } else {
        throw $ex;
      }
    }

    $this->didWrite = true;
    return $this;
  }


/* -(  Internals  )---------------------------------------------------------- */


  /**
   * Format the log string, replacing "%x" variables with values.
   *
   * @return string Finalized, log string for writing to disk.
   * @task internals
   */
  private function format() {

    // Always convert '%%' to literal '%'.
    $map = array('%' => '%') + $this->data;

    $result = '';
    $saw_percent = false;
    foreach (phutil_utf8v($this->format) as $c) {
      if ($saw_percent) {
        $saw_percent = false;
        if (array_key_exists($c, $map)) {
          $result .= addcslashes($map[$c], "\0..\37\\\177..\377");
        } else {
          $result .= '-';
        }
      } else if ($c == '%') {
        $saw_percent = true;
      } else {
        $result .= $c;
      }
    }

    return rtrim($result)."\n";
  }

}
