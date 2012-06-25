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
 * operating in "receive-pack" mode, etc. It is unlikely that any reasonble
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
 *
 * @group channel
 */
final class PhutilExecChannel extends PhutilChannel {

  private $future;


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

  protected function readBytes() {
    list($stdout, $stderr) = $this->future->read();
    $this->future->discardBuffers();

    if (strlen($stderr)) {
      throw new Exception(
        "Unexpected output to stderr on exec channel: {$stderr}");
    }

    return $stdout;
  }

  public function write($bytes) {
    $this->future->write($bytes, $keep_pipe = true);
  }

  protected function writeBytes($bytes) {
    throw new Exception("ExecFuture can not write bytes directly!");
  }

  protected function getReadSockets() {
    return $this->future->getReadSockets();
  }

  protected function getWriteSockets() {
    return $this->future->getWriteSockets();
  }

}
