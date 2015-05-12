<?php

final class PhutilLanguageGuesserTestCase extends PhutilTestCase {

  public function testGuessing() {
    $dir = dirname(__FILE__).'/languageguesser/';
    foreach (Filesystem::listDirectory($dir, $hidden = false) as $test) {
      $source = Filesystem::readFile($dir.$test);

      if (strpos($test, '.') !== false) {
        $expect = head(explode('.', $test));
      } else {
        $expect = null;
      }

      $this->assertEqual(
        $expect,
        PhutilLanguageGuesser::guessLanguage($source),
        pht("Guessed language for '%s'.", $test));
    }
  }

}
