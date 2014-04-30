<?php

/**
 * Base class for libphutil objects. Enforces stricter object semantics than
 * PHP.
 *
 * When a program attempts to write to an undeclared object property, PHP
 * creates the property. However, in libphutil this is always an error (for
 * example, a misspelled property name).  Instead of permitting the write,
 * subclasses will throw when an undeclared property is written.
 *
 * When a program attempts to iterate an object (for example, with `foreach`),
 * PHP iterates its public members. However, in libphutil this is always an
 * error (for example, iterating over the wrong variable). Instead of
 * permitting the iteration, subclasses will throw when an object is iterated.
 *
 * (Legitimately iterable subclasses can provide a working implementation of
 * Iterator instead.)
 */
abstract class Phobject implements Iterator {

  public function __set($name, $value) {
    throw new DomainException(
      pht(
        'Attempt to write to undeclared property %s::%s.',
        get_class($this),
        $name));
  }

  public function current() {
    $this->throwOnAttemptedIteration();
  }

  public function key() {
    $this->throwOnAttemptedIteration();
  }

  public function next() {
    $this->throwOnAttemptedIteration();
  }

  public function rewind() {
    $this->throwOnAttemptedIteration();
  }

  public function valid() {
    $this->throwOnAttemptedIteration();
  }

  private function throwOnAttemptedIteration() {
    throw new DomainException(
      pht(
        'Attempting to iterate an object (of class %s) which is not '.
        'iterable.',
        get_class($this)));
  }

}
