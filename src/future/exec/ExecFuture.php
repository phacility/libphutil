<?php

/*
 * Copyright 2011 Facebook, Inc.
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
 * Execute system commands in parallel using futures.
 *
 *  // execx() API: synchronous, throws on nonzero exit code
 *  list($stdout, $stderr) = execx('wc -l %s', $file);
 *
 *  // exec_manual() API: synchronous, returns exit code
 *  list($err, $stdout, $stderr) = exec_manual('wc -l %s', $file);
 *
 *  // Raw ExecFuture API: asynchronous
 *  $future = new ExecFuture(
 *    csprintf('wc -l %s'),
 *    $file);
 *
 *  list($err, $stdout, $stderr) = $future->resolve();
 *
 *  // ...or, throw on nonzero exit with 'resolvex()'.
 *  list($stdout, $stderr) = $future->resolvex();
 *
 * @group exec
 */
class ExecFuture extends Future {

  const TIMED_OUT_EXIT_CODE = 142;

  protected $pipes        = array();
  protected $proc         = null;
  protected $start        = null;
  protected $timeout      = null;
  protected $procStatus   = null;

  protected $stdout       = null;
  protected $stderr       = null;
  protected $stdin        = null;
  protected $closePipe    = false;

  protected $stdoutPos    = 0;
  protected $stderrPos    = 0;
  protected $command      = null;
  protected $cwd;

  protected $stdoutSizeLimit = PHP_INT_MAX;
  protected $stderrSizeLimit = PHP_INT_MAX;

  protected static $echoMode = array();
  protected static $descriptorSpec = array(
    0 => array('pipe', 'r'),  // stdin
    1 => array('pipe', 'w'),  // stdout
    2 => array('pipe', 'w'),  // stderr
  );

  public static function pushEchoMode($mode) {
    self::$echoMode[] = $mode;
  }

  public static function popEchoMode() {
    array_pop(self::$echoMode);
  }

  public static function peekEchoMode() {
    return end(self::$echoMode);
  }

  public function setStdoutSizeLimit($limit) {
    $this->stdoutSizeLimit = $limit;
  }

  public function getStdoutSizeLimit() {
    return $this->stdoutSizeLimit;
  }

  public function setStderrSizeLimit($limit) {
    $this->stderrSizeLimit = $limit;
  }

  public function getStderrSizeLimit() {
    return $this->stderrSizeLimit;
  }

  public function setCWD($cwd) {
    $this->cwd = $cwd;
    return $this;
  }

  public function getPID() {
    $status = $this->procGetStatus();
    return $status['pid'];
  }

  private function procGetStatus() {
    // After the process exits, we only get one chance to read proc_get_status()
    // before it starts returning garbage. Make sure we don't throw away the
    // last good read.
    if ($this->procStatus) {
      if (!$this->procStatus['running']) {
        return $this->procStatus;
      }
    }
    $this->procStatus = proc_get_status($this->proc);
    return $this->procStatus;
  }

  public function __construct($command) {
    $argv = func_get_args();
    $this->command = call_user_func_array('csprintf', $argv);
  }

  public function __destruct() {
    foreach ($this->pipes as $pipe) {
      if (isset($pipe)) {
        @fclose($pipe);
      }
    }
    $this->pipes  = array(null, null, null);
    if ($this->proc) {
      @proc_close($this->proc);
      $this->proc = null;
    }
    $this->stdin  = null;
  }

  public function getCommand() {
    return $this->command;
  }

  public function read() {
    if ($this->start) {
      $this->isReady(); // Sync
    }

    $result = array(
      (string)substr($this->stdout, $this->stdoutPos),
      (string)substr($this->stderr, $this->stderrPos),
    );

    $this->stdoutPos = strlen($this->stdout);
    $this->stderrPos = strlen($this->stderr);

    return $result;
  }

  public function write($data, $keep_pipe = false) {
    $this->stdin .= $data;

    if (!$keep_pipe) {
      $this->closePipe = true;
    }

    if ($this->start) {
      $this->isReady(); // Sync
    }

    return $this;
  }

  public function discardBuffers() {
    $this->stdout = '';
    $this->stderr = '';
    $this->stdoutPos = 0;
    $this->stderrPos = 0;

    return $this;
  }

  public function getReadSockets() {
    list($stdin, $stdout, $stderr) = $this->pipes;
    $sockets = array();
    if (isset($stdout) && !feof($stdout)) {
      $sockets[] = $stdout;
    }
    if (isset($stderr) && !feof($stderr)) {
      $sockets[] = $stderr;
    }
    return $sockets;
  }

  /**
   * Reads some bytes from a stream, discarding output once a certain amount
   * has been accumulated.
   *
   * @param resource $stream
   *    Stream to read from.
   * @param int $limit
   *    Maximum number of bytes to return from $stream. If additional bytes
   *    are available, they will be read and discarded.
   * @param string $description
   *    Human-readable description of stream, for exception message.
   * @return string
   *    The data read from the stream.
   * @throws Exception
   *    The stream was not readable.
   */
  protected function readAndDiscard($stream, $limit, $description) {
    $output = '';

    do {
      $data = fread($stream, 4096);
      if (false === $data) {
        throw new Exception('Failed to read from '.$description);
      }

      $read_bytes = strlen($data);

      if ($read_bytes > 0 && $limit > 0) {
        if ($read_bytes > $limit) {
          $data = substr($data, 0, $limit);
        }
        $output .= $data;
        $limit -= strlen($data);
      }
    } while ($read_bytes > 0);

    return $output;
  }

  public function getWriteSockets() {
    list($stdin, $stdout, $stderr) = $this->pipes;
    $sockets = array();
    if (isset($stdin) && strlen($this->stdin) && !feof($stdin)) {
      $sockets[] = $stdin;
    }
    return $sockets;
  }

  public function isReady() {

    if (!$this->pipes) {

      if (self::peekEchoMode()) {
        echo "  >>> \$ {$this->command}\n";
      }

      $pipes = array();
      $proc = proc_open(
        $this->command,
        self::$descriptorSpec,
        $pipes,
        $this->cwd);
      if (!is_resource($proc)) {
        throw new Exception('Failed to open process.');
      }

      $this->start = time();
      $this->pipes = $pipes;
      $this->proc  = $proc;

      list($stdin, $stdout, $stderr) = $pipes;

      if ((!stream_set_blocking($stdout, false)) ||
          (!stream_set_blocking($stderr, false)) ||
          (!stream_set_blocking($stdin,  false))) {
        $this->__destruct();
        throw new Exception('Failed to set streams nonblocking.');
      }

      return false;
    }

    if (!$this->proc) {
      return true;
    }

    list($stdin, $stdout, $stderr) = $this->pipes;

    if (isset($this->stdin) && strlen($this->stdin)) {
      $bytes = fwrite($stdin, $this->stdin);
      if ($bytes === false) {
        throw new Exception('Unable to write to stdin!');
      } else if ($bytes) {
        $this->stdin = substr($this->stdin, $bytes);
      }

      if (!strlen($this->stdin) && $this->closePipe) {
        @fclose($stdin);
        $this->pipes[0] = null;
      }
    } else {
      if ($this->closePipe) {
        @fclose($stdin);
      }
      $this->pipes[0] = null;
    }

    //  Read status before reading pipes so that we can never miss data that
    //  arrives between our last read and the process exiting.
    $status = $this->procGetStatus();

    $this->stdout .= $this->readAndDiscard(
      $stdout,
      $this->getStdoutSizeLimit() - strlen($this->stdout),
      'stdout');
    $this->stderr .= $this->readAndDiscard(
      $stderr,
      $this->getStderrSizeLimit() - strlen($this->stderr),
      'stderr');

    if (!$status['running']) {
      $this->result = array(
        $status['exitcode'],
        $this->stdout,
        $this->stderr,
      );
      $this->__destruct();
      return true;
    }

    if ($this->timeout && ((time() - $this->start) >= $this->timeout)) {
      if (defined('SIGKILL')) {
        $signal = SIGKILL;
      } else {
        $signal = 9;
      }
      proc_terminate($this->proc, $signal);
      $this->result = array(
        self::TIMED_OUT_EXIT_CODE,
        $this->stdout,
        $this->stderr."\n".
        "(This process was prematurely terminated by timeout.)");
     $this->__destruct();
     return true;
    }

  }

  public function setTimeout($seconds) {
    $this->timeout = $seconds;
    return $this;
  }

  public function resolve($timeout = null) {
    if (null === $timeout) {
      $timeout = $this->timeout;
    }
    return parent::resolve($timeout);
  }

  public function resolvex($timeout = null) {
    list($err, $stdout, $stderr) = $this->resolve($timeout);
    if ($err) {
      $cmd = $this->command;
      throw new CommandException(
        "Command '{$cmd}' failed with error #{$err}:\n".
        "stdout:\n{$stdout}\n".
        "stderr:\n{$stderr}\n",
        $cmd,
        $err,
        $stdout,
        $stderr);
    }
    return array($stdout, $stderr);
  }

  public function resolveJSON($timeout = null) {
    list($stdout, $stderr) = $this->resolvex($timeout);
    if (strlen($stderr)) {
      $cmd = $this->command;
      throw new CommandException(
        "JSON command '{$cmd}' emitted text to stderr when none was expected: ".
        $stderr,
        $cmd,
        0,
        $stdout,
        $stderr);
    }
    $object = json_decode($stdout, true);
    if (!is_array($object)) {
      $cmd = $this->command;
      throw new CommandException(
        "JSON command '{$cmd}' did not produce a valid JSON object on stdout: ".
        $stdout,
        $cmd,
        0,
        $stdout,
        $stderr);
    }
    return $object;
  }
}
