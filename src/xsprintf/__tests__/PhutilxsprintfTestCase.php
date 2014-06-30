<?php

final class PhutilxsprintfTestCase extends PhutilTestCase {

  public function testhgsprintf() {
    $this->assertEqual(
      "'version-1'",
      hgsprintf('%s', 'version-1'));

    $this->assertEqual(
      "'single\\'quote'",
      hgsprintf('%s', "single'quote"));

    $this->assertEqual(
      "'back\\\\slash'",
      hgsprintf('%s', 'back\\slash'));

    $this->assertEqual(
      "'33%'",
      hgsprintf('%R', hgsprintf('%s', '33%')));
  }

}
