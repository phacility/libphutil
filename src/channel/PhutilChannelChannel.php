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
 * Channel that wraps some other channel. This class is not interesting on is
 * own and just serves as a no-op proxy, but extending it allows you to compose
 * channels to mutate their characteristics (for instance, to add protocol
 * semantics with @{class:PhutilProtocolChannel}).
 *
 * The implementation of this class is entirely uninteresting.
 *
 * @group channel
 */
abstract class PhutilChannelChannel extends PhutilChannel {

  private $channel;

  public function __construct(PhutilChannel $channel) {
    $this->channel = $channel;
  }

  public function read() {
    return $this->channel->read();
  }

  public function write($message) {
    $this->channel->write($message);
    return $this;
  }

  public function update() {
    return $this->channel->update();
  }

  public function isOpen() {
    return $this->channel->isOpen();
  }

  protected function readBytes() {
    $this->throwOnRawByteOperations();
  }

  protected function writeBytes($bytes) {
    $this->throwOnRawByteOperations();
  }

  protected function getReadSockets() {
    return $this->channel->getReadSockets();
  }

  protected function getWriteSockets() {
    return $this->channel->getWriteSockets();
  }

  protected function isReadBufferEmpty() {
    return $this->channel->isReadBufferEmpty();
  }

  protected function isWriteBufferEmpty() {
    return $this->channel->isWriteBufferEmpty();
  }

  public function flush() {
    $this->channel->flush();
    return $this;
  }

  protected function getUnderlyingChannel() {
    return $this->channel;
  }

  private function throwOnRawByteOperations() {

    // NOTE: You should only be able to end up here if you subclass this class
    // and implement your subclass incorrectly, since the byte methods are
    // protected.

    throw new Exception(
      "Do not call readBytes() or writeBytes() directly on a ".
      "PhutilChannelChannel. Instead, call read() or write().");
  }

}
