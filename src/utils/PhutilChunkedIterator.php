<?php

/**
 * This is an iterator version of `array_chunk()`.
 */
final class PhutilChunkedIterator extends Phobject implements Iterator {

  private $iterator;
  private $size;

  private $key = 0;
  private $current;

  /**
   * @param Iterator
   * @param int
   */
  public function __construct(Iterator $iterator, $size) {
    $this->iterator = $iterator;
    $this->size = $size;
  }

  public function rewind() {
    $this->iterator->rewind();
    $this->next();
    $this->key = 0;
  }

  /**
   * @return int
   */
  public function key() {
    return $this->key;
  }

  /**
   * @return array
   */
  public function current() {
    return $this->current;
  }

  public function next() {
    $this->current = array();
    while ($this->iterator->valid()) {
      $key = $this->iterator->key();
      $this->current[$key] = $this->iterator->current();
      $this->iterator->next();
      if (count($this->current) >= $this->size) {
        break;
      }
    }
    $this->key++;
  }

  public function valid() {
    return (bool)$this->current;
  }

}
