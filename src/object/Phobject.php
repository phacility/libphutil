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

  public function __get($name) {
    throw new DomainException(
      pht(
        'Attempt to read from undeclared property %s.',
        get_class($this).'::'.$name));
    }

  public function __set($name, $value) {
    throw new DomainException(
      pht(
        'Attempt to write to undeclared property %s.',
        get_class($this).'::'.$name));
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
        'Attempting to iterate an object (of class %s) which is not iterable.',
        get_class($this)));
  }


  /**
   * Read the value of a class constant.
   *
   * This is the same as just typing `self::CONSTANTNAME`, but throws a more
   * useful message if the constant is not defined and allows the constant to
   * be limited to a maximum length.
   *
   * @param string Name of the constant.
   * @param int|null Maximum number of bytes permitted in the value.
   * @return string Value of the constant.
   */
  public function getPhobjectClassConstant($key, $byte_limit = null) {
    $class = new ReflectionClass($this);

    $const = $class->getConstant($key);
    if ($const === false) {
      throw new Exception(
        pht(
          '"%s" class "%s" must define a "%s" constant.',
          __CLASS__,
          get_class($this),
          $key));
    }

    if ($byte_limit !== null) {
      if (!is_string($const) || (strlen($const) > $byte_limit)) {
        throw new Exception(
          pht(
            '"%s" class "%s" has an invalid "%s" property. Field constants '.
            'must be strings and no more than %s bytes in length.',
            __CLASS__,
            get_class($this),
            $key,
            new PhutilNumber($byte_limit)));
      }
    }

    return $const;
  }

}
