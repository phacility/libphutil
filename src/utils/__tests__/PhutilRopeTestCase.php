<?php

final class PhutilRopeTestCase extends PhutilTestCase {

  public function testRopeOperations() {
    $rope = new PhutilRope();
    $rope->append('aaa');
    $rope->append('bbb');

    $this->assertEqual(6, $rope->getByteLength());
    $this->assertEqual('aaabbb', $rope->getAsString());

    $rope->removeBytesFromHead(2);

    $this->assertEqual(4, $rope->getByteLength());
    $this->assertEqual('abbb', $rope->getAsString());

    $rope->removeBytesFromHead(4);

    $this->assertEqual(0, $rope->getByteLength());
    $this->assertEqual('', $rope->getAsString());
  }

}
