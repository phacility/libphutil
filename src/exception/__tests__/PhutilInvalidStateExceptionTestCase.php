<?php

final class PhutilInvalidStateExceptionTestCase extends PhutilTestCase {

  public function testException() {
    try {
      throw new PhutilInvalidStateException('someMethod');
    } catch (PhutilInvalidStateException $ex) {
      $this->assertEqual(
        __FUNCTION__,
        $ex->getCallee());
      $this->assertEqual(
        'someMethod',
        $ex->getFunction());
    }
  }
}
