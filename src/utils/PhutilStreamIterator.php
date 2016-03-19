<?php

final class PhutilStreamIterator
  extends Phobject
  implements Iterator {

  private $stream;
  private $started = false;
  private $naturalKey;
  private $data;

  public function __construct($stream) {
    $this->stream = $stream;
  }

/* -(  Iterator Implementation  )-------------------------------------------- */


  public function rewind() {
    if ($this->started) {
      // When you first foreach() an iterator the rewind() method gets called
      // so we have to work the first time.
      throw new Exception(
        pht('Stream iterators can not be rewound!'));
    }

    $this->started = true;
    $this->naturalKey = -1;
    $this->next();
  }

  public function valid() {
    return ($this->data !== null);
  }

  public function current() {
    return $this->data;
  }

  public function key() {
    return $this->naturalKey;
  }

  public function next() {
    $stream = $this->stream;

    if (!$stream) {
      return;
    }

    if (feof($stream)) {
      fclose($stream);
      $this->stream = null;
      $this->data = null;
      return;
    }

    $bytes = fread($stream, 64 * 1024);
    if ($bytes === false) {
      throw new Exception(
        pht('Failed to fread() from request input stream.'));
    }

    $this->data = $bytes;
    $this->naturalKey++;
  }

}
