<?php

final class PhutilReadableSerializerTestCase extends PhutilTestCase {

  public function testPrintableValue() {
    $tests = array(
      array(null, 'null'),
      array(true, 'true'),
      array(false, 'false'),
      array(0, '0'),
      array(0.0, '0.0'),
      array(0.1, '0.1'),
      array('test', "'test'"),
    );
    foreach ($tests as $test) {
      list($value, $expect) = $test;
      $this->assertEqual(
        $expect,
        PhutilReadableSerializer::printableValue($value));
    }
  }

}
