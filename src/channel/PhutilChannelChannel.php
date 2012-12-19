<?php

/**
 * Channel that wraps some other channel. This class is not interesting on its
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
    $this->didConstruct();
  }

  protected function didConstruct() {
    // Hook for subclasses.
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

  public function isOpenForReading() {
    return $this->channel->isOpenForReading();
  }

  public function isOpenForWriting() {
    return $this->channel->isOpenForWriting();
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
