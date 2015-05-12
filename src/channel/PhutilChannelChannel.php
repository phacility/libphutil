<?php

/**
 * Channel that wraps some other channel. This class is not interesting on its
 * own and just serves as a no-op proxy, but extending it allows you to compose
 * channels to mutate their characteristics (for instance, to add protocol
 * semantics with @{class:PhutilProtocolChannel}).
 *
 * The implementation of this class is entirely uninteresting.
 */
abstract class PhutilChannelChannel extends PhutilChannel {

  private $channel;

  public function __construct(PhutilChannel $channel) {
    parent::__construct();
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

  public function closeWriteChannel() {
    return $this->channel->closeWriteChannel();
  }

  public function isOpenForReading() {
    return $this->channel->isOpenForReading();
  }

  public function isOpenForWriting() {
    return $this->channel->isOpenForWriting();
  }

  protected function readBytes($length) {
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

  public function setReadBufferSize($size) {
    $this->channel->setReadBufferSize($size);
    return $this;
  }

  public function isReadBufferEmpty() {
    return $this->channel->isReadBufferEmpty();
  }

  public function isWriteBufferEmpty() {
    return $this->channel->isWriteBufferEmpty();
  }

  public function getWriteBufferSize() {
    return $this->channel->getWriteBufferSize();
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
      pht(
        'Do not call %s or %s directly on a %s. Instead, call %s or %s.',
        'readBytes()',
        'writeBytes()',
        __CLASS__,
        'read()',
        'write()'));
  }

}
