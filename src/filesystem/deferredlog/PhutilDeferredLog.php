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
 * PHP, you can decode this encoding with @{function:stripcslashes}.
 *
 * If a variable is included in the log format but a value is never provided
 * with @{method:setData}, it will be written as "-".
 *
 * @task log        Logging
 * @task internal   Internals
 */
final class PhutilDeferredLog {

  private $file;
  private $format;
  private $data;
  private $didWrite;


/* -(  Logging  )------------------------------------------------------------ */


  /**
   * Create a new log entry, which will be written later. The format string
   * should use "%x"-style placeholders to represent data which will be added
   * later:
   *
   *   $log = new PhutilDeferredLog('/some/file.log', '[%T] %u');
   *
   * @param string The file the entry should be written to.
   * @param string The log entry format.
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
   * When the log object is destroyed, it writes if it hasn't written yet.
   * @task log
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
   * @task log
   */
  public function write() {
    if ($this->didWrite) {
      return $this;
    }

    $line = $this->format();

    $ok = @file_put_contents(
      $this->file,
      $line,
      FILE_APPEND | LOCK_EX);

    if ($ok === false) {
      throw new Exception(
        "Unable to write to logfile '{$this->file}'!");
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
    $byte = "\1";

    $line = $this->format;
    $line = addcslashes($line, $byte);
    $line = str_replace("%", $byte, $line);

    $find = array();
    $repl = array();
    foreach ($this->data as $key => $value) {
      $find[] = $byte.str_replace('%', $byte, $key);
      $repl[] = addcslashes($value, "\0..\37\\\177..\377");
    }

    $line = str_replace($find, $repl, $line);

    $line = preg_replace("/{$byte}./", '-', $line);
    $line = rtrim($line)."\n";

    return $line;
  }

}
