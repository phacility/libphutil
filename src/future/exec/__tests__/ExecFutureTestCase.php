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

  public function testTimeout() {
    list($err) = id(new ExecFuture('sleep 32000'))->setTimeout(0.01)->resolve();

    $this->assertEqual(
      ExecFuture::TIMED_OUT_EXIT_CODE,
      $err);
  }

}
