<?php

final class PhutilPersonTest extends Phobject implements PhutilPerson {

  private $gender = PhutilPerson::GENDER_UNKNOWN;

  public function getGender() {
    return $this->gender;
  }

  public function setGender($value) {
    $this->gender = $value;
    return $this;
  }

  public function __toString() {
    return pht('Test (%s)', $this->gender);
  }

}
