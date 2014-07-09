<?php

final class PhutilJSONTestCase extends PhutilTestCase {

  public function testEmptyArrayEncoding() {
    $serializer = new PhutilJSON();

    $expect = <<<EOJSON
{
  "x" : []
}

EOJSON;

    $this->assertEqual(
      $expect,
      $serializer->encodeFormatted(array('x' => array())),
      'Empty arrays should serialize as [], not {}.');
  }

}
