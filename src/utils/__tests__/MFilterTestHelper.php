<?php

final class MFilterTestHelper extends Phobject {

  private $h;
  private $i;
  private $j;

  public function __construct($h_value, $i_value, $j_value) {
    $this->h = $h_value;
    $this->i = $i_value;
    $this->j = $j_value;
  }

  public function getH() {
    return $this->h;
  }

  public function getI() {
    return $this->i;
  }

  public function getJ() {
    return $this->j;
  }

}
