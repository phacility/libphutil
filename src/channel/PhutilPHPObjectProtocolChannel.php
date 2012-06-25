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
 * Channel that transmits PHP objects using PHP serialization. This channel
 * is binary safe.
 *
 * @task protocol Protocol Implementation
 */
final class PhutilPHPObjectProtocolChannel extends PhutilProtocolChannel {

  const MODE_LENGTH = 'length';
  const MODE_OBJECT = 'object';

  private $mode                   = self::MODE_LENGTH;
  private $byteLengthOfNextChunk  = 4;
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
          $len = substr($this->buf, 0, 4);
          $this->buf = substr($this->buf, 4);

          $this->mode = self::MODE_OBJECT;
          $this->byteLengthOfNextChunk = head(unpack('N', $len));
          break;
        case self::MODE_OBJECT:
          $data = substr($this->buf, 0, $this->byteLengthOfNextChunk);
          $this->buf = substr($this->buf, $this->byteLengthOfNextChunk);

          $obj = @unserialize($data);
          if ($obj === false) {
            throw new Exception("Failed to unserialize object: {$data}");
          } else {
            $objects[] = $obj;
          }

          $this->mode = self::MODE_LENGTH;
          $this->byteLengthOfNextChunk = 4;
          break;
      }
    }

    return $objects;
  }

}
