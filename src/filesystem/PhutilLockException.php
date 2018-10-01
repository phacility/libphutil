<?php

final class PhutilLockException extends Exception {

  private $hint;

  public function setHint($hint) {
    $this->hint = $hint;
    return $this;
  }

  public function getHint() {
    return $this->hint;
  }

}
