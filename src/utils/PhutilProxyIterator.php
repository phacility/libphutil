<?php

abstract class PhutilProxyIterator
  extends Phobject
  implements Iterator {

  private $iterator;
  private $key;
  private $value;
  private $valid;

  public function __construct(Iterator $iterator) {
    $this->iterator = $iterator;
  }

  protected function didReadValue($value) {
    return $value;
  }


/* -(  Iterator Implementation  )-------------------------------------------- */


  final public function rewind() {
    $this->iterator->rewind();
    $this->update();
  }

  final public function valid() {
    return $this->valid;
  }

  final public function current() {
    return $this->value;
  }

  final public function key() {
    return $this->key;
  }

  final public function next() {
    $this->iterator->next();
    $this->update();
  }

  private function update() {
    $this->key = $this->iterator->key();
    $this->valid = $this->iterator->valid();

    if ($this->valid) {
      $value = $this->iterator->current();
      $value = $this->didReadValue($value);
      $this->value = $value;
    }
  }

}
