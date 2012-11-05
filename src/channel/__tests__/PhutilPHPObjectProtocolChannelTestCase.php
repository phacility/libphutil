<?php

final class PhutilPHPObjectProtocolChannelTestCase extends PhutilTestCase {

  public function testPHPObjectChannelBasics() {
    list($x, $y) = PhutilSocketChannel::newChannelPair();
    $xp = new PhutilPHPObjectProtocolChannel($x);
    $yp = new PhutilPHPObjectProtocolChannel($y);

    $object = (object)array(
      'key' => mt_rand(),
    );

    $xp->write($object);
    $xp->flush();
    $result = $yp->waitForMessage();

    $this->assertEqual(
      true,
      (array)$object === (array)$result,
      "Values are identical.");

    $this->assertEqual(
      false,
      $object === $result,
      "Objects are not the same.");
  }

}
