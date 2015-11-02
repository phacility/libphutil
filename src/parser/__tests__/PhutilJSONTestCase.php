<?php

final class PhutilJSONTestCase extends PhutilTestCase {

  public function testEmptyArrayEncoding() {
    $serializer = new PhutilJSON();

    $expect = <<<EOJSON
{
  "x": []
}

EOJSON;

    $this->assertEqual(
      $expect,
      $serializer->encodeFormatted(array('x' => array())),
      pht('Empty arrays should serialize as `%s`, not `%s`.', '[]', '{}'));
  }

}
