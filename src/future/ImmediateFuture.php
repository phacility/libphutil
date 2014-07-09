<?php

/**
 * Degenerate future which returns an already-existing result without performing
 * any computation.
 */
final class ImmediateFuture extends Future {

  public function __construct($result) {
    $this->result = $result;
  }

  public function isReady() {
    return true;
  }

}
