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
final class ExecFutureTestCase extends ArcanistPhutilTestCase {

  public function testEmptyWrite() {

    // NOTE: This is mostly testing that we don't hang while doing an empty
    // write.

    list($stdout) = id(new ExecFuture('cat'))->write('')->resolvex();

    $this->assertEqual('', $stdout);
  }

  public function testKeepPipe() {

    // NOTE: This is mosty testing the semantics of $keep_pipe in write().

    list($stdout) = id(new ExecFuture('cat'))
      ->write('', true)
      ->start()
      ->write('x', true)
      ->write('y', true)
      ->write('z', false)
      ->resolvex();

    $this->assertEqual('xyz', $stdout);
  }

  public function testLargeBuffer() {

    // NOTE: This is mostly a coverage test to hit branches where we're still
    // flushing a buffer.

    $data = str_repeat('x', 1024 * 1024 * 4);
    list($stdout) = id(new ExecFuture('cat'))->write($data)->resolvex();

    $this->assertEqual($data, $stdout);
  }

  public function testBufferLimit() {
    $data = str_repeat('x', 1024 * 1024);
    list($stdout) = id(new ExecFuture('cat'))
      ->setStdoutSizeLimit(1024)
      ->write($data)
      ->resolvex();

    $this->assertEqual(substr($data, 0, 1024), $stdout);
  }

  public function testResolveTimeoutTestShouldRunLessThan1Sec() {

    // NOTE: This tests interactions between the resolve() timeout and the
    // ExecFuture timeout, which are similar but not identical.

    $future = id(new ExecFuture('sleep 32000'))->start();
    $future->setTimeout(32000);

    // We expect this to return in 0.01s.
    $result = $future->resolve(0.01);
    $this->assertEqual($result, null);

    // We expect this to now force the time out / kill immediately. If we don't
    // do this, we'll hang when exiting until our subprocess exits (32000
    // seconds!)
    $future->setTimeout(0.01);
    $future->resolve();
  }


  public function testTimeoutTestShouldRunLessThan1Sec() {

    // NOTE: This is partly testing that we choose appropriate select wait
    // times; this test should run for significantly less than 1 second.

    $future = new ExecFuture('sleep 32000');
    list($err) = $future->setTimeout(0.01)->resolve();

    $this->assertEqual(true, $err > 0);
    $this->assertEqual(true, $future->getWasKilledByTimeout());
  }

  public function testMultipleTimeoutsTestShouldRunLessThan1Sec() {
    $futures = array();
    for ($ii = 0; $ii < 4; $ii++) {
      $futures[] = id(new ExecFuture('sleep 32000'))->setTimeout(0.01);
    }

    foreach (Futures($futures) as $future) {
      list ($err) = $future->resolve();

      $this->assertEqual(true, $err > 0);
      $this->assertEqual(true, $future->getWasKilledByTimeout());
    }
  }

}
