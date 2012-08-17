<?php

/*
 * Copyright 2012 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @group testcase
 */
final class FutureIteratorTestCase extends ArcanistPhutilTestCase {

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
