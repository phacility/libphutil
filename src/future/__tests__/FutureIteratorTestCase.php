<?php

final class FutureIteratorTestCase extends PhutilTestCase {

  public function testAddingFuture() {
    $future1 = new ExecFuture('cat');
    $future2 = new ExecFuture('cat');

    $iterator = new FutureIterator(array($future1));
    $iterator->limit(2);

    $results = array();
    foreach ($iterator as $future) {
      if ($future === $future1) {
        $iterator->addFuture($future2);
      }
      $results[] = $future->resolve();
    }

    $this->assertEqual(2, count($results));
  }

}
