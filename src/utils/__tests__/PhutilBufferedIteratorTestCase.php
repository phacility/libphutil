<?php

/**
 * Test cases for @{class:PhutilExampleBufferedIterator}.
 */
final class PhutilBufferedIteratorTestCase extends PhutilTestCase {

  public function testBufferedIterator() {
    $expect = array_fill(0, 23, 'example');

    $iterator = new PhutilExampleBufferedIterator();
    $iterator->setPageSize(3);
    $iterator->setExampleData($expect);

    $results = array();
    foreach ($iterator as $key => $value) {
      $results[$key] = $value;
    }

    $this->assertEqual(
      $expect,
      $results);
  }

}
