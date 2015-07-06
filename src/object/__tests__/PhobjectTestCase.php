<?php

final class PhobjectTestCase extends PhutilTestCase {

  public function testThrowOnUndeclaredProperty() {
    $object = new PhutilTestPhobject();

    $caught = null;
    try {
      $object->duck;
    } catch (Exception $ex) {
      $caught = $ex;
    }
    $this->assertTrue($caught instanceof DomainException);

    $caught = null;
    try {
      $object->duck = 'quack';
    } catch (Exception $ex) {
      $caught = $ex;
    }
    $this->assertTrue($caught instanceof DomainException);
  }

  public function testThrowOnIteration() {
    $object = new PhutilTestPhobject();

    $caught = null;
    try {
      foreach ($object as $item) {
        // ...
      }
    } catch (Exception $ex) {
      $caught = $ex;
    }

    $this->assertTrue($caught instanceof DomainException);
  }

}
