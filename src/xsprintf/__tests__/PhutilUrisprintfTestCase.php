<?php

final class PhutilUrisprintfTestCase extends PhutilTestCase {

  public function testUrisprintf() {
    $this->assertEqual(
      'x.com?a=huh%3F',
      urisprintf('x.com?a=%s', 'huh?'));

    $this->assertEqual(
      '/a/origin%252Fmaster/z/',
      urisprintf('/a/%p/z/', 'origin/master'));

    $this->assertEqual(
      'y.com?%21&%23',
      vurisprintf('y.com?%s&%s', array('!', '#')));
  }

}
