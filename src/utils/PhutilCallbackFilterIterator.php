<?php

/**
 * NOTE: This class has the same purpose as `CallbackFilterIterator` in PHP 5.4.
 */
final class PhutilCallbackFilterIterator extends FilterIterator {
  private $callback;

  /**
   * @param Iterator
   * @param callable Signature: (mixed $current): bool.
   */
  public function __construct(Iterator $iterator, $callback) {
    parent::__construct($iterator);
    if (!is_callable($callback)) {
      throw new Exception(pht('Callback must be callable.'));
    }
    $this->callback = $callback;
  }

  public function accept() {
    return call_user_func($this->callback, $this->current());
  }

}
