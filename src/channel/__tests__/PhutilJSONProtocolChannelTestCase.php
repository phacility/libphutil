<?php

final class PhutilJSONProtocolChannelTestCase extends PhutilTestCase {

  public function testJSONChannelBasics() {
    list($x, $y) = PhutilSocketChannel::newChannelPair();
    $xp = new PhutilJSONProtocolChannel($x);
    $yp = new PhutilJSONProtocolChannel($y);

    $dict = array(
      'rand' => mt_rand(),
      'list' => array(1, 2, 3),
      'null' => null,
    );

    $xp->write($dict);
    $xp->flush();
    $result = $yp->waitForMessage();

    $this->assertEqual(
      $dict,
      $result,
      pht('Values are identical.'));
  }

}
