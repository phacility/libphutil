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

  public function testMoreRopeOperations() {
    $rope = new PhutilRope();
    $rope->append('aaa');
    $rope->append('bbb');
    $rope->append('ccc');
    $rope->append('rrrrddddddddd');
    $rope->removeBytesFromHead(4);

    $string = $rope->getAsString();
    $this->assertEqual('bbcccrrrrddddddddd', $string);
    $this->assertEqual(strlen($string), $rope->getByteLength());

    $rope = new PhutilRope();
    $rope->append('aaa');
    $rope->append('bbb');
    $rope->removeBytesFromHead(6);

    $string = $rope->getAsString();
    $this->assertEqual('', $string);
    $this->assertEqual(0, $rope->getByteLength());


    $rope = new PhutilRope();
    $rope->append('a');
    $rope->append('b');
    $rope->append('c');
    $rope->removeBytesFromHead(1024);

    $string = $rope->getAsString();
    $this->assertEqual('', $string);
    $this->assertEqual(0, $rope->getByteLength());
  }
}
