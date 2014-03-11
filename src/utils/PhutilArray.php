<?php

/**
 * Abstract base class for implementing objects that behave like arrays. This
 * class wraps a basic array and provides trivial implementations for
 * `Countable`, `ArrayAccess` and `Iterator`, so subclasses need only implement
 * specializations.
 */
abstract class PhutilArray
  extends Phobject
  implements Countable, ArrayAccess, Iterator {

  protected $data = array();


  public function __construct(array $initial_value = array()) {
    $this->data = $initial_value;
  }


/* -(  Conversion  )--------------------------------------------------------- */


  public function toArray() {
    return iterator_to_array($this, true);
  }


/* -(  Countable Interface  )------------------------------------------------ */


  public function count() {
    return count($this->data);
  }


/* -(  Iterator Interface  )------------------------------------------------- */


  public function current() {
    return current($this->data);
  }

  public function key() {
    return key($this->data);
  }

  public function next() {
    return next($this->data);
  }

  public function rewind() {
    reset($this->data);
  }

  public function valid() {
    return (key($this->data) !== null);
  }


/* -(  ArrayAccess Interface  )---------------------------------------------- */


  public function offsetExists($key) {
    return array_key_exists($key, $this->data);
  }

  public function offsetGet($key) {
    return $this->data[$key];
  }

  public function offsetSet($key, $value) {
    $this->data[$key] = $value;
  }

  public function offsetUnset($key) {
    unset($this->data[$key]);
  }

}
