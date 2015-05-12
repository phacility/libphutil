<?php

/**
 * Channel that transmits PHP objects using PHP serialization. This channel
 * is binary safe.
 *
 * @task protocol Protocol Implementation
 */
final class PhutilPHPObjectProtocolChannel extends PhutilProtocolChannel {

  const MODE_LENGTH = 'length';
  const MODE_OBJECT = 'object';

  /**
   * Size of the "length" frame of the protocol in bytes.
   */
  const SIZE_LENGTH = 4;

  private $mode                   = self::MODE_LENGTH;
  private $byteLengthOfNextChunk  = self::SIZE_LENGTH;
  private $buf                    = '';


/* -(  Protocol Implementation  )-------------------------------------------- */


  /**
   * Encode a message for transmission over the channel. The message should
   * be any serializable PHP object. The entire object will be serialized, so
   * avoid transmitting objects which connect to large graphs of other objects,
   * etc.
   *
   * This channel can transmit class instances, but the receiving end must be
   * running the same version of the code. There are no builtin safeguards
   * to protect against versioning problems in object serialization.
   *
   * Objects are transmitted as:
   *
   *   <len><serialized PHP object>
   *
   * ...where <len> is a 4-byte unsigned big-endian integer.
   *
   * @task protocol
   */
  protected function encodeMessage($message) {
    $message = serialize($message);
    $len = pack('N', strlen($message));
    return "{$len}{$message}";
  }


  /**
   * Decode a message received from the other end of the channel.
   *
   * @task protocol
   */
  protected function decodeStream($data) {
    $this->buf .= $data;

    $objects = array();
    while (strlen($this->buf) >= $this->byteLengthOfNextChunk) {
      switch ($this->mode) {
        case self::MODE_LENGTH:
          $len = substr($this->buf, 0, self::SIZE_LENGTH);
          $this->buf = substr($this->buf, self::SIZE_LENGTH);

          $this->mode = self::MODE_OBJECT;
          $this->byteLengthOfNextChunk = head(unpack('N', $len));
          break;
        case self::MODE_OBJECT:
          $data = substr($this->buf, 0, $this->byteLengthOfNextChunk);
          $this->buf = substr($this->buf, $this->byteLengthOfNextChunk);

          $obj = @unserialize($data);
          if ($obj === false) {
            throw new Exception(pht('Failed to unserialize object: %s', $data));
          } else {
            $objects[] = $obj;
          }

          $this->mode = self::MODE_LENGTH;
          $this->byteLengthOfNextChunk = self::SIZE_LENGTH;
          break;
      }
    }

    return $objects;
  }

}
