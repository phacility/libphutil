<?php

final class PhutilPersonTest implements PhutilPerson {

  private $sex = PhutilPerson::SEX_UNKNOWN;

  public function getSex() {
    return $this->sex;
  }

  public function setSex($value) {
    $this->sex = $value;
    return $this;
  }

  public function __toString() {
    return 'Test ('.$this->sex.')';
  }

}
