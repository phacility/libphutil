<?php

final class PhutilTsprintfTestCase extends PhutilTestCase {

  public function testTsprintf() {
    $this->assertEqual(
      '<NUL>',
      (string)tsprintf('%s', "\0"));

    $this->assertEqual(
      '<ESC>[31mred<ESC>[39m',
      (string)tsprintf('%s', "\x1B[31mred\x1B[39m"));

    $block = "1\r\n2\r3\n4";

    $this->assertEqual(
      '1<CR><LF>2<CR>3<LF>4',
      (string)tsprintf('%s', $block));
    $this->assertEqual(
      "1\r\n2<CR>3\n4",
      (string)tsprintf('%B', $block));
  }

}
