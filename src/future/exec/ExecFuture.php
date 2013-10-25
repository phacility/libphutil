<?php

/**
 * Execute system commands in parallel using futures.
 *
 * ExecFuture is a future, which means it runs asynchronously and represents
 * a value which may not exist yet. See @{article:Using Futures} for an
 * explanation of futures. When an ExecFuture resolves, it returns the exit
 * code, stdout and stderr of the process it executed.
 *
 * ExecFuture is the core command execution implementation in libphutil, but is
 * exposed through a number of APIs. See @{article:Command Execution} for more
 * discussion about executing system commands.
 *
 * @task create   Creating ExecFutures
 * @task resolve  Resolving Execution
 * @task config   Configuring Execution
 * @task info     Command Information
 * @task interact Interacting With Commands
 * @task internal Internals
 * @group exec
 */
final class ExecFuture extends Future {

  protected $pipes        = array();
  protected $proc         = null;
  protected $start        = null;
  protected $timeout      = null;
  protected $procStatus   = null;

  protected $stdout       = null;
  protected $stderr       = null;
  protected $stdin        = null;
  protected $closePipe    = true;

  protected $stdoutPos    = 0;
  protected $stderrPos    = 0;
  protected $command      = null;
  protected $env          = null;
  protected $cwd;

  protected $stdoutSizeLimit = PHP_INT_MAX;
  protected $stderrSizeLimit = PHP_INT_MAX;

  private $profilerCallID;
  private $killedByTimeout;

  protected static $descriptorSpec = array(
    0 => array('pipe', 'r'),  // stdin
    1 => array('pipe', 'w'),  // stdout
    2 => array('pipe', 'w'),  // stderr
  );


/* -(  Creating ExecFutures  )----------------------------------------------- */


  /**
   * Create a new ExecFuture.
   *
   *   $future = new ExecFuture('wc -l %s', $file_path);
   *
   * @param string  ##sprintf()##-style command string which will be passed
   *                through @{function:csprintf} with the rest of the arguments.
   * @param ...     Zero or more additional arguments for @{function:csprintf}.
   * @return ExecFuture ExecFuture for running the specified command.
   * @task create
   */
  public function __construct($command) {
    $argv = func_get_args();
    $this->command = call_user_func_array('csprintf', $argv);
  }


/* -(  Command Information  )------------------------------------------------ */


  /**
   * Retrieve the raw command to be executed.
   *
   * @return string Raw command.
   * @task info
   */
  public function getCommand() {
    return $this->command;
  }


  /**
   * Retrieve the byte limit for the stderr buffer.
   *
   * @return int Maximum buffer size, in bytes.
   * @task info
   */
  public function getStderrSizeLimit() {
    return $this->stderrSizeLimit;
  }


  /**
   * Retrieve the byte limit for the stdout buffer.
   *
   * @return int Maximum buffer size, in bytes.
   * @task info
   */
  public function getStdoutSizeLimit() {
    return $this->stdoutSizeLimit;
  }


  /**
   * Get the process's pid. This only works after execution is initiated, e.g.
   * by a call to start().
   *
   * @return int Process ID of the executing process.
   * @task info
   */
  public function getPID() {
    $status = $this->procGetStatus();
    return $status['pid'];
  }


/* -(  Configuring Execution  )---------------------------------------------- */


  /**
   * Set a maximum size for the stdout read buffer. To limit stderr, see
   * @{method:setStderrSizeLimit}. The major use of these methods is to use less
   * memory if you are running a command which sometimes produces huge volumes
   * of output that you don't really care about.
   *
   * NOTE: Setting this to 0 means "no buffer", not "unlimited buffer".
   *
   * @param int Maximum size of the stdout read buffer.
   * @return this
   * @task config
   */
  public function setStdoutSizeLimit($limit) {
    $this->stdoutSizeLimit = $limit;
    return $this;
  }


  /**
   * Set a maximum size for the stderr read buffer.
   * See @{method:setStdoutSizeLimit} for discussion.
   *
   * @param int Maximum size of the stderr read buffer.
   * @return this
   * @task config
   */
  public function setStderrSizeLimit($limit) {
    $this->stderrSizeLimit = $limit;
    return $this;
  }


  /**
   * Set the current working directory to use when executing the command.
   *
   * @param string Directory to set as CWD before executing the command.
   * @return this
   * @task config
   */
  public function setCWD($cwd) {
    $this->cwd = $cwd;
    return $this;
  }


  /**
   * Set the environment variables to use when executing the command.
   *
   * @param array Environment variables to use when executing the command.
   * @return this
   * @task config
   */
  public function setEnv($env, $wipe_process_env = false) {
    if ($wipe_process_env) {
      $this->env = $env;
    } else {
      $this->env = $env + $_ENV;
    }
    return $this;
  }


/* -(  Interacting With Commands  )------------------------------------------ */


  /**
   * Read and return output from stdout and stderr, if any is available. This
   * method keeps a read cursor on each stream, but the entire streams are
   * still returned when the future resolves. You can call read() again after
   * resolving the future to retrieve only the parts of the streams you did not
   * previously read:
   *
   *   $future = new ExecFuture('...');
   *   // ...
   *   list($stdout) = $future->read(); // Returns output so far
   *   list($stdout) = $future->read(); // Returns new output since first call
   *   // ...
   *   list($stdout) = $future->resolvex(); // Returns ALL output
   *   list($stdout) = $future->read(); // Returns unread output
   *
   * NOTE: If you set a limit with @{method:setStdoutSizeLimit} or
   * @{method:setStderrSizeLimit}, this method will not be able to read data
   * past the limit.
   *
   * NOTE: If you call @{method:discardBuffers}, all the stdout/stderr data
   * will be thrown away and the cursors will be reset.
   *
   * @return pair <$stdout, $stderr> pair with new output since the last call
   *              to this method.
   * @task interact
   */
  public function read() {
    $stdout = $this->readStdout();

    $result = array(
      $stdout,
      (string)substr($this->stderr, $this->stderrPos),
    );

    $this->stderrPos = strlen($this->stderr);

    return $result;
  }

  public function readStdout() {
    if ($this->start) {
      $this->isReady(); // Sync
    }

    $result = (string)substr($this->stdout, $this->stdoutPos);
    $this->stdoutPos = strlen($this->stdout);
    return $result;
  }


  /**
   * Write data to stdin of the command.
   *
   * @param string Data to write.
   * @param bool If true, keep the pipe open for writing. By default, the pipe
   *             will be closed as soon as possible so that commands which
   *             listen for EOF will execute. If you want to keep the pipe open
   *             past the start of command execution, do an empty write with
   *             `$keep_pipe = true` first.
   * @return this
   * @task interact
   */
  public function write($data, $keep_pipe = false) {
    $this->stdin .= $data;
    $this->closePipe = !$keep_pipe;

    return $this;
  }


  /**
   * Permanently discard the stdout and stderr buffers and reset the read
   * cursors. This is basically useful only if you are streaming a large amount
   * of data from some process:
   *
   *   $future = new ExecFuture('zcat huge_file.gz');
   *   do {
   *     $done = $future->resolve(0.1);   // Every 100ms,
   *     list($stdout) = $future->read(); // read output...
   *     echo $stdout;                    // send it somewhere...
   *     $future->discardBuffers();       // and then free the buffers.
   *   } while ($done === null);
   *
   * Conceivably you might also need to do this if you're writing a client using
   * ExecFuture and ##netcat##, but you probably should not do that.
   *
   * NOTE: This completely discards the data. It won't be available when the
   * future resolves. This is almost certainly only useful if you need the
   * buffer memory for some reason.
   *
   * @return this
   * @task interact
   */
  public function discardBuffers() {
    $this->discardStdoutBuffer();

    $this->stderr = '';
    $this->stderrPos = 0;

    return $this;
  }

  public function discardStdoutBuffer() {
    $this->stdout = '';
    $this->stdoutPos = 0;
    return $this;
  }


  /**
   * Returns true if this future was killed by a timeout configured with
   * @{method:setTimeout}.
   *
   * @return bool True if the future was killed for exceeding its time limit.
   */
  public function getWasKilledByTimeout() {
    return $this->killedByTimeout;
  }


/* -(  Configuring Execution  )---------------------------------------------- */


  /**
   * Set a hard limit on execution time. If the command runs longer, it will
   * be killed and the future will resolve with an error code. You can test
   * if a future was killed by a timeout with @{method:getWasKilledByTimeout}.
   *
   * @param int Maximum number of seconds this command may execute for.
   * @return this
   * @task config
   */
  public function setTimeout($seconds) {
    $this->timeout = $seconds;
    return $this;
  }


/* -(  Resolving Execution  )------------------------------------------------ */


  /**
   * Resolve a command you expect to exit with return code 0. Works like
   * @{method:resolve}, but throws if $err is nonempty. Returns only
   * $stdout and $stderr. See also @{function:execx}.
   *
   *   list($stdout, $stderr) = $future->resolvex();
   *
   * @param  float Optional timeout after which resolution will pause and
   *               execution will return to the caller.
   * @return pair  <$stdout, $stderr> pair.
   * @task resolve
   */
  public function resolvex($timeout = null) {
    list($err, $stdout, $stderr) = $this->resolve($timeout);
    if ($err) {
      $cmd = $this->command;
      throw new CommandException(
        "Command failed with error #{$err}!",
        $cmd,
        $err,
        $stdout,
        $stderr);
    }
    return array($stdout, $stderr);
  }


  /**
   * Resolve a command you expect to return valid JSON. Works like
   * @{method:resolvex}, but also throws if stderr is nonempty, or stdout is not
   * valid JSON. Returns a PHP array, decoded from the JSON command output.
   *
   * @param  float Optional timeout after which resolution will pause and
   *               execution will return to the caller.
   * @return array PHP array, decoded from JSON command output.
   * @task resolve
   */
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

  /**
   * Resolve the process by abruptly terminating it.
   *
   * @return list List of <err, stdout, stderr> results.
   * @task resolve
   */
  public function resolveKill() {
    if (defined('SIGKILL')) {
      $signal = SIGKILL;
    } else {
      $signal = 9;
    }

    proc_terminate($this->proc, $signal);
    $this->result = array(
      128 + $signal,
      $this->stdout,
      $this->stderr);
    $this->closeProcess();

    return $this->result;
  }


/* -(  Internals  )---------------------------------------------------------- */


  /**
   * Provides read sockets to the future core.
   *
   * @return list List of read sockets.
   * @task internal
   */
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
   * Provides write sockets to the future core.
   *
   * @return list List of write sockets.
   * @task internal
   */
  public function getWriteSockets() {
    list($stdin, $stdout, $stderr) = $this->pipes;
    $sockets = array();
    if (isset($stdin) && strlen($this->stdin) && !feof($stdin)) {
      $sockets[] = $stdin;
    }
    return $sockets;
  }


  /**
   * Reads some bytes from a stream, discarding output once a certain amount
   * has been accumulated.
   *
   * @param resource  Stream to read from.
   * @param int       Maximum number of bytes to return from $stream. If
   *                  additional bytes are available, they will be read and
   *                  discarded.
   * @param string    Human-readable description of stream, for exception
   *                  message.
   * @return string   The data read from the stream.
   * @task internal
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


  /**
   * Begin or continue command execution.
   *
   * @return bool True if future has resolved.
   * @task internal
   */
  public function isReady() {

    // NOTE: We have soft dependencies on PhutilServiceProfiler and
    // PhutilErrorTrap here. These depencies are soft to avoid the need to
    // build them into the Phage agent. Under normal circumstances, these
    // classes are always available.

    if (!$this->pipes) {

      // NOTE: See note above about Phage.
      if (class_exists('PhutilServiceProfiler')) {
        $profiler = PhutilServiceProfiler::getInstance();
        $this->profilerCallID = $profiler->beginServiceCall(
          array(
            'type'    => 'exec',
            'command' => (string)$this->command,
          ));
      }

      if (!$this->start) {
        // We might already have started the timer via initating resolution.
        $this->start = microtime(true);
      }

      $unmasked_command = $this->command;
      if ($unmasked_command instanceof PhutilCommandString) {
        $unmasked_command = $unmasked_command->getUnmaskedString();
      }

      $pipes = array();

      // NOTE: See note above about Phage.
      if (class_exists('PhutilErrorTrap')) {
        $trap = new PhutilErrorTrap();
      } else {
        $trap = null;
      }

      $proc = @proc_open(
        $unmasked_command,
        self::$descriptorSpec,
        $pipes,
        $this->cwd,
        $this->env);

      if ($trap) {
        $err = $trap->getErrorsAsString();
        $trap->destroy();
      } else {
        $err = error_get_last();
      }

      if (!is_resource($proc)) {
        throw new Exception("Failed to proc_open(): {$err}");
      }

      $this->pipes = $pipes;
      $this->proc  = $proc;

      list($stdin, $stdout, $stderr) = $pipes;

      if (!phutil_is_windows()) {

        // On Windows, there's no such thing as nonblocking interprocess I/O.
        // Just leave the sockets blocking and hope for the best. Some features
        // will not work.

        if ((!stream_set_blocking($stdout, false)) ||
            (!stream_set_blocking($stderr, false)) ||
            (!stream_set_blocking($stdin,  false))) {
          $this->__destruct();
          throw new Exception('Failed to set streams nonblocking.');
        }
      }

      $this->tryToCloseStdin();

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
    }

    $this->tryToCloseStdin();

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
      $this->closeProcess();
      return true;
    }

    $elapsed = (microtime(true) - $this->start);
    if ($this->timeout && ($elapsed >= $this->timeout)) {
      $this->killedByTimeout = true;
      $this->resolveKill();
      return true;
    }

  }


  /**
   * @return void
   * @task internal
   */
  public function __destruct() {
    if (!$this->proc) {
      return;
    }

    // NOTE: If we try to proc_close() an open process, we hang indefinitely. To
    // avoid this, kill the process explicitly if it's still running.

    $status = $this->procGetStatus();
    if ($status['running']) {
      $this->resolveKill();
    } else {
      $this->closeProcess();
    }
  }


  /**
   * Close and free resources if necessary.
   *
   * @return void
   * @task internal
   */
  private function closeProcess() {
    foreach ($this->pipes as $pipe) {
      if (isset($pipe)) {
        @fclose($pipe);
      }
    }
    $this->pipes = array(null, null, null);
    if ($this->proc) {
      @proc_close($this->proc);
      $this->proc = null;
    }
    $this->stdin  = null;

    if ($this->profilerCallID !== null) {
      $profiler = PhutilServiceProfiler::getInstance();
      $profiler->endServiceCall(
        $this->profilerCallID,
        array(
          'err' => $this->result ? idx($this->result, 0) : null,
        ));
      $this->profilerCallID = null;
    }
  }


  /**
   * Execute proc_get_status(), but avoid pitfalls.
   *
   * @return dict Process status.
   * @task internal
   */
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

  /**
   * Try to close stdin, if we're done using it. This keeps us from hanging if
   * the process on the other end of the pipe is waiting for EOF.
   *
   * @return void
   * @task internal
   */
  private function tryToCloseStdin() {
    if (!$this->closePipe) {
      // We've been told to keep the pipe open by a call to write(..., true).
      return;
    }

    if (strlen($this->stdin)) {
      // We still have bytes to write.
      return;
    }

    list($stdin) = $this->pipes;
    if (!$stdin) {
      // We've already closed stdin.
      return;
    }

    // There's nothing stopping us from closing stdin, so close it.

    @fclose($stdin);
    $this->pipes[0] = null;
  }

  public function getDefaultWait() {
    $wait = parent::getDefaultWait();

    if ($this->timeout) {
      if (!$this->start) {
        $this->start = microtime(true);
      }
      $elapsed = (microtime(true) - $this->start);
      $wait = max(0, min($this->timeout - $elapsed, $wait));
    }

    return $wait;
  }


}
