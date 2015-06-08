<?php

final class PhutilConsoleWrapTestCase extends PhutilTestCase {

  public function testWrap() {
    $dir = dirname(__FILE__).'/wrap/';
    $files = Filesystem::listDirectory($dir);
    foreach ($files as $file) {
      if (preg_match('/.txt$/', $file)) {
        $this->assertEqual(
          Filesystem::readFile($dir.$file.'.expect'),
          phutil_console_wrap(Filesystem::readFile($dir.$file)),
          $file);
      }
    }
  }

  public function testConsoleWrap() {
    $this->assertEqual(
        phutil_console_format(
          "<bg:red>** %s **</bg> abc abc abc abc abc abc abc abc abc abc ".
          "abc abc abc abc abc abc abc\nabc abc abc abc abc abc abc abc abc ".
          "abc abc!",
          pht('ERROR')),
      phutil_console_wrap(
        phutil_console_format(
          '<bg:red>** %s **</bg> abc abc abc abc abc abc abc abc abc abc '.
          'abc abc abc abc abc abc abc abc abc abc abc abc abc abc abc abc '.
          'abc abc!',
          pht('ERROR'))),
      pht('ANSI escape sequences should not contribute toward wrap width.'));
  }

  public function testWrapIndent() {
    $turtles = <<<EOTURTLES
                    turtle turtle turtle turtle turtle turtle turtle turtle
                    turtle turtle turtle turtle turtle turtle turtle turtle
                    turtle turtle turtle turtle
EOTURTLES;

    $this->assertEqual(
      $turtles,
      phutil_console_wrap(
        rtrim(str_repeat('turtle ', 20)),
        $indent = 20));
  }

}
