<?php

/**
 * String-like object which reduces the cost of managing large strings. This
 * is particularly useful for buffering large amounts of data that is being
 * passed to `fwrite()`.
 */
final class PhutilRope extends Phobject {

  private $length = 0;
  private $buffers = array();

  // This is is arbitrary, it's just the maximum size I'm reliably able to
  // fwrite() to a pipe on OSX. In theory, we could tune this slightly based
  // on the pipe buffer size, but any value similar to this shouldn't affect
  // performance much.
  private $segmentSize = 16384;

  /**
   * Append a string to the rope.
   *
   * @param string String to append.
   * @return this
   */
  public function append($string) {
    if (!strlen($string)) {
      return $this;
    }

    $len = strlen($string);
    $this->length += $len;

    if ($len <= $this->segmentSize) {
      $this->buffers[] = $string;
    } else {
      for ($cursor = 0; $cursor < $len; $cursor += $this->segmentSize) {
        $this->buffers[] = substr($string, $cursor, $this->segmentSize);
      }
    }

    return $this;
  }


  /**
   * Get the length of the rope.
   *
   * @return int Length of the rope in bytes.
   */
  public function getByteLength() {
    return $this->length;
  }


  /**
   * Get an arbitrary, nonempty prefix of the rope.
   *
   * @return string Some rope prefix.
   */
  public function getAnyPrefix() {
    $result = reset($this->buffers);
    if ($result === false) {
      return null;
    }

    return $result;
  }


  /**
   * Get prefix bytes of the rope, up to some maximum size.
   *
   * @param int Maximum number of bytes to read.
   * @return string Bytes.
   */
  public function getPrefixBytes($length) {
    $result = array();

    $remaining_bytes = $length;
    foreach ($this->buffers as $buf) {
      $length = strlen($buf);
      if ($length <= $remaining_bytes) {
        $result[] = $buf;
        $remaining_bytes -= $length;
      } else {
        $result[] = substr($buf, 0, $remaining_bytes);
        $remaining_bytes = 0;
      }
      if (!$remaining_bytes) {
        break;
      }
    }

    return implode('', $result);
  }


  /**
   * Return the entire rope as a normal string.
   *
   * @return string Normal string.
   */
  public function getAsString() {
    return implode('', $this->buffers);
  }


  /**
   * Remove a specified number of bytes from the head of the rope.
   *
   * @param int Bytes to remove.
   * @return this
   */
  public function removeBytesFromHead($remove) {
    if ($remove <= 0) {
      throw new InvalidArgumentException(
        pht('Length must be larger than 0!'));
    }

    $remaining_bytes = $remove;
    foreach ($this->buffers as $key => $buf) {
      $len = strlen($buf);
      if ($len <= $remaining_bytes) {
        unset($this->buffers[$key]);
        $remaining_bytes -= $len;
        if (!$remaining_bytes) {
          break;
        }
      } else {
        $this->buffers[$key] = substr($buf, $remaining_bytes);
        break;
      }
    }

    if ($this->buffers) {
      $this->length -= $remove;
    } else {
      $this->length = 0;
    }

    return $this;
  }

}
