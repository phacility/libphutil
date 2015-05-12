<?php

/**
 * Wraps a @{class:PhutilChannel} and implements a message-oriented protocol
 * on top of it. A protocol channel behaves like a normal channel, except that
 * @{method:read} and @{method:write} are message-oriented and the protocol
 * channel handles encoding and parsing messages for transmission.
 *
 * @task io       Reading and Writing
 * @task protocol Protocol Implementation
 * @task wait     Waiting for Activity
 */
abstract class PhutilProtocolChannel extends PhutilChannelChannel {

  private $messages = array();


/* -(  Reading and Writing  )------------------------------------------------ */


  /**
   * Read a message from the channel, if a message is available.
   *
   * @return wild A message, or null if no message is available.
   *
   * @task io
   */
  public function read() {
    $data = parent::read();

    if (strlen($data)) {
      $messages = $this->decodeStream($data);
      foreach ($messages as $message) {
        $this->addMessage($message);
      }
    }

    if (!$this->messages) {
      return null;
    }

    return array_shift($this->messages);
  }


  /**
   * Write a message to the channel.
   *
   * @param wild    Some message.
   * @return this
   *
   * @task io
   */
  public function write($message) {
    $bytes = $this->encodeMessage($message);
    return parent::write($bytes);
  }


  /**
   * Add a message to the queue. While you normally do not need to do this,
   * you can use it to inject out-of-band messages.
   *
   * @param wild    Some message.
   * @return this
   *
   * @task io
   */
  public function addMessage($message) {
    $this->messages[] = $message;
    return $this;
  }


/* -(  Protocol Implementation  )-------------------------------------------- */


  /**
   * Encode a message for transmission.
   *
   * @param   wild    Some message.
   * @return  string  The message serialized into a wire format for
   *                  transmission.
   *
   * @task protocol
   */
  abstract protected function encodeMessage($message);


  /**
   * Decode bytes from the underlying channel into zero or more complete
   * messages. The messages should be returned.
   *
   * This method is called as data is available. It will receive incoming
   * data only once, and must buffer any data which represents only part of
   * a message. Once a complete message is received, it can return the message
   * and discard that part of the buffer.
   *
   * Generally, a protocol channel should maintain a read buffer, implement
   * a parser in this method, and store parser state on the object to be able
   * to process incoming data in small chunks.
   *
   * @param   string      One or more bytes from the underlying channel.
   * @return  list<wild>  Zero or more parsed messages.
   *
   * @task protocol
   */
  abstract protected function decodeStream($data);


/* -(  Waiting for Activity  )----------------------------------------------- */


  /**
   * Wait for a message, blocking until one is available.
   *
   * @return wild A message.
   *
   * @task wait
   */
  public function waitForMessage() {
    while (true) {
      $is_open = $this->update();
      $message = $this->read();
      if ($message !== null) {
        return $message;
      }

      if (!$is_open) {
        break;
      }

      self::waitForAny(array($this));
    }

    throw new Exception(pht('Channel closed while waiting for message!'));
  }

}
