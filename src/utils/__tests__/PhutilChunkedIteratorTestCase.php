<?php

/**
 * Test cases for @{class:PhutilChunkedIterator}.
 */
final class PhutilChunkedIteratorTestCase extends PhutilTestCase {

  public function testChunkedIterator() {
    $expect = array(
      array(0 => 1, 1 => 3),
      array(2 => 5),
    );

    $iterator = new PhutilChunkedIterator(
      new ArrayIterator(array(1, 3, 5)),
      2);

    $this->assertEqual(
      $expect,
      iterator_to_array($iterator));

    for ($i = 0; $i < 2; $i++) {
      foreach ($iterator as $key => $actual) {
        $this->assertEqual(idx($expect, $key), $actual);
      }
    }
  }

}
