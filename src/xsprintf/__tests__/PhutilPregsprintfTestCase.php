<?php

final class PhutilPregsprintfTestCase extends PhutilTestCase {

  public function testPregsprintf() {
    $this->assertEqual(
      chr(7).'foobar'.chr(7),
      pregsprintf('%s', '', 'foobar'));

    $this->assertEqual(
      chr(7).'\.\*\[a\-z\]'.chr(7),
      pregsprintf('%s', '', '.*[a-z]'));

    $this->assertEqual(
      chr(7).'.*[a-z]'.chr(7),
      pregsprintf('%R', '', '.*[a-z]'));

    $this->assertEqual(
      chr(7).'^abc\.\*xyz.*$'.chr(7).'siU',
      pregsprintf('^abc%sxyz%R$', 'siU', '.*', '.*'));
  }

}
