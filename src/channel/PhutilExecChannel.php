<?php

/**
 * Channel on an underlying @{class:ExecFuture}. For a description of channels,
 * see @{class:PhutilChannel}.
 *
 * For example, you can open a channel on `nc` like this:
 *
 *   $future = new ExecFuture('nc example.com 80');
 *   $channel = new PhutilExecChannel($future);
 *
 *   $channel->write("GET / HTTP/1.0\n\n");
 *   while (true) {
 *     echo $channel->read();
 *
 *     PhutilChannel::waitForAny(array($channel));
 *     if (!$channel->update()) {
 *       // Break out of the loop when the channel closes.
 *       break;
 *     }
 *   }
 *
 * This script makes an HTTP request to "example.com". This example is heavily
 * contrived. In most cases, @{class:ExecFuture} and other futures constructs
 * offer a much easier way to solve problems which involve system commands, and
 * @{class:HTTPFuture} and other HTTP constructs offer a much easier way to
 * solve problems which involve HTTP.
 *
 * @{class:PhutilExecChannel} is generally useful only when a program acts like
 * a server but performs I/O on stdin/stdout, and you need to act like a client
 * or interact with the program at the same time as you manage traditional
 * socket connections. Examples are Mercurial operating in "cmdserve" mode, git
 * operating in "receive-pack" mode, etc. It is unlikely that any reasonable
 * use of this class is concise enough to make a short example out of, so you
 * get a contrived one instead.
 *
 * See also @{class:PhutilSocketChannel}, for a similar channel that uses
 * sockets for I/O.
 *
 * Since @{class:ExecFuture} already supports buffered I/O and socket selection,
 * the implementation of this class is fairly straightforward.
 *
 * @task construct Construction
 */
final class PhutilExecChannel extends PhutilChannel {

  private $future;
  private $stderrHandler;


/* -(  Construction  )------------------------------------------------------- */


  /**
   * Construct an exec channel from a @{class:ExecFuture}. The future should
   * **NOT** have been started yet (e.g., with `isReady()` or `start()`),
   * because @{class:ExecFuture} closes stdin by default when futures start.
   * If stdin has been closed, you will be unable to write on the channel.
   *
   * @param ExecFuture Future to use as an underlying I/O source.
   * @task construct
   */
  public function __construct(ExecFuture $future) {
    parent::__construct();

    // Make an empty write to keep the stdin pipe open. By default, futures
    // close this pipe when they start.
    $future->write('', $keep_pipe = true);

    // Start the future so that reads and writes work immediately.
    $future->isReady();

    $this->future = $future;
  }

  public function __destruct() {
    if (!$this->future->isReady()) {
      $this->future->resolveKill();
    }
  }

  public function update() {
    $this->future->isReady();
    return parent::update();
  }

  public function isOpen() {
    return !$this->future->isReady();
  }

  protected function readBytes($length) {
    list($stdout, $stderr) = $this->future->read();
    $this->future->discardBuffers();

    if (strlen($stderr)) {
      if ($this->stderrHandler) {
        call_user_func($this->stderrHandler, $this, $stderr);
      } else {
        throw new Exception(
          pht('Unexpected output to stderr on exec channel: %s', $stderr));
      }
    }

    return $stdout;
  }

  public function write($bytes) {
    $this->future->write($bytes, $keep_pipe = true);
  }

  public function closeWriteChannel() {
    $this->future->write('', $keep_pipe = false);
  }

  protected function writeBytes($bytes) {
    throw new Exception(pht('%s can not write bytes directly!', 'ExecFuture'));
  }

  protected function getReadSockets() {
    return $this->future->getReadSockets();
  }

  protected function getWriteSockets() {
    return $this->future->getWriteSockets();
  }

  public function isReadBufferEmpty() {
    // Check both the channel and future read buffers, since either could have
    // data.
    return parent::isReadBufferEmpty() && $this->future->isReadBufferEmpty();
  }

  public function setReadBufferSize($size) {
    // NOTE: We may end up using 2x the buffer size here, one inside
    // ExecFuture and one inside the Channel. We could tune this eventually, but
    // it should be fine for now.
    parent::setReadBufferSize($size);
    $this->future->setReadBufferSize($size);
    return $this;
  }

  public function isWriteBufferEmpty() {
    return $this->future->isWriteBufferEmpty();
  }

  public function getWriteBufferSize() {
    return $this->future->getWriteBufferSize();
  }

  /**
   * If the wrapped @{class:ExecFuture} outputs data to stderr, we normally
   * throw an exception. Instead, you can provide a callback handler that will
   * be invoked and passed the data. It should have this signature:
   *
   *   function f(PhutilExecChannel $channel, $stderr) {
   *     // ...
   *   }
   *
   * The `$channel` will be this channel object, and `$stderr` will be a string
   * with bytes received over stderr.
   *
   * You can set a handler which does nothing to effectively ignore and discard
   * any output on stderr.
   *
   * @param callable Handler to invoke when stderr data is received.
   * @return this
   */
  public function setStderrHandler($handler) {
    $this->stderrHandler = $handler;
    return $this;
  }

}
