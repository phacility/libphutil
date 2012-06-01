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
final class LinesOfALargeExecFutureTestCase extends ArcanistPhutilTestCase {

  // Most of the core functionality of LinesOfALarge is covered by the
  // LinesOfALargeFile test case, try to just cover exec-specific stuff here.

  public function testExecBasics() {
    $this->writeAndRead(
      "cat\ndog\nbird\n",
      array(
        "cat",
        "dog",
        "bird",
      ));
  }

  public function testExecLargeFile() {
    $line = "The quick brown fox jumps over the lazy dog.";
    $n    = 100;

    $this->writeAndRead(
      str_repeat($line."\n", $n),
      array_fill(0, $n, $line));
  }

  public function testExecLongLine() {
    $line = str_repeat('x', 64 * 1024);
    $this->writeAndRead($line, array($line));
  }

  public function testExecException() {
    $caught = null;
    try {
      $future = new ExecFuture('does-not-exist.exe.sh');
      foreach (new LinesOfALargeExecFuture($future) as $line) {
        // ignore
      }
    } catch (Exception $ex) {
      $caught = $ex;
    }
    $this->assertEqual(true, $caught instanceof CommandException);
  }

  private function writeAndRead($write, $read) {
    $future = new ExecFuture('cat');
    $future->write($write);

    $lines = array();
    foreach (new LinesOfALargeExecFuture($future) as $line) {
      $lines[] = $line;
    }

    $this->assertEqual(
      $read,
      $lines,
      "Write: ".phutil_utf8_shorten($write, 32));
  }

}
