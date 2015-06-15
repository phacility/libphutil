<?php

/**
 * A 'future' or 'promise' is an object which represents the result of some
 * pending computation. For a more complete overview of futures, see
 * @{article:Using Futures}.
 */
abstract class Future extends Phobject {

  protected static $handlerInstalled = null;

  protected $result;
  protected $exception;

  /**
   * Is this future's process complete? Specifically, can this future be
   * resolved without blocking?
   *
   * @return bool  If true, the external process is complete and resolving this
   *               future will not block.
   */
  abstract public function isReady();

  /**
   * Resolve a future and return its result, blocking until the result is ready
   * if necessary.
   *
   * @param  float Optional timeout after which resolution will pause and
   *               execution will return to the caller.
   * @return mixed Future result, or null if the timeout is hit.
   */
  public function resolve($timeout = null) {
    $start = microtime(true);
    $wait  = $this->getDefaultWait();
    do {
      $this->checkException();
      if ($this->isReady()) {
        break;
      }

      $read = $this->getReadSockets();
      $write = $this->getWriteSockets();

      if ($timeout !== null) {
        $elapsed = microtime(true) - $start;

        if ($elapsed > $timeout) {
          $this->checkException();
          return null;
        } else {
          $wait = $timeout - $elapsed;
        }
      }

      if ($read || $write) {
        self::waitForSockets($read, $write, $wait);
      }
    } while (true);

    $this->checkException();
    return $this->getResult();
  }

  public function setException(Exception $ex) {
    $this->exception = $ex;
    return $this;
  }

  public function getException() {
    return $this->exception;
  }


  /**
   * If an exception was set by setException(), throw it.
   */
  private function checkException() {
    if ($this->exception) {
      throw $this->exception;
    }
  }


  /**
   * Retrieve a list of sockets which we can wait to become readable while
   * a future is resolving. If your future has sockets which can be
   * `select()`ed, return them here (or in @{method:getWriteSockets}) to make
   * the resolve loop  do a `select()`. If you do not return sockets in either
   * case, you'll get a busy wait.
   *
   * @return list  A list of sockets which we expect to become readable.
   */
  public function getReadSockets() {
    return array();
  }


  /**
   * Retrieve a list of sockets which we can wait to become writable while a
   * future is resolving. See @{method:getReadSockets}.
   *
   * @return list  A list of sockets which we expect to become writable.
   */
  public function getWriteSockets() {
    return array();
  }


  /**
   * Wait for activity on one of several sockets.
   *
   * @param  list  List of sockets expected to become readable.
   * @param  list  List of sockets expected to become writable.
   * @param  float Timeout, in seconds.
   * @return void
   */
  public static function waitForSockets(
    array $read_list,
    array $write_list,
    $timeout = 1) {
    if (!self::$handlerInstalled) {
      //  If we're spawning child processes, we need to install a signal handler
      //  here to catch cases like execing '(sleep 60 &) &' where the child
      //  exits but a socket is kept open. But we don't actually need to do
      //  anything because the SIGCHLD will interrupt the stream_select(), as
      //  long as we have a handler registered.
      if (function_exists('pcntl_signal')) {
        if (!pcntl_signal(SIGCHLD, array(__CLASS__, 'handleSIGCHLD'))) {
          throw new Exception(pht('Failed to install signal handler!'));
        }
      }
      self::$handlerInstalled = true;
    }

    $timeout_sec = (int)$timeout;
    $timeout_usec = (int)(1000000 * ($timeout - $timeout_sec));

    $exceptfds = array();
    $ok = @stream_select(
      $read_list,
      $write_list,
      $exceptfds,
      $timeout_sec,
      $timeout_usec);

    if ($ok === false) {
      // Hopefully, means we received a SIGCHLD. In the worst case, we degrade
      // to a busy wait.
    }
  }

  public static function handleSIGCHLD($signo) {
    // This function is a dummy, we just need to have some handler registered
    // so that PHP will get interrupted during stream_select(). If we don't
    // register a handler, stream_select() won't fail.
  }


  /**
   * Retrieve the final result of the future. This method will be called after
   * the future is ready (as per @{method:isReady}) but before results are
   * passed back to the caller. The major use of this function is that you can
   * override it in subclasses to do postprocessing or error checking, which is
   * particularly useful if building application-specific futures on top of
   * primitive transport futures (like @{class:CurlFuture} and
   * @{class:ExecFuture}) which can make it tricky to hook this logic into the
   * main pipeline.
   *
   * @return mixed   Final resolution of this future.
   */
  protected function getResult() {
    return $this->result;
  }

  /**
   * Default amount of time to wait on stream select for this future. Normally
   * 1 second is fine, but if the future has a timeout sooner than that it
   * should return the amount of time left before the timeout.
   */
  public function getDefaultWait() {
    return 1;
  }

  public function start() {
    $this->isReady();
    return $this;
  }

}
