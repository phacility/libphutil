<?php

final class LinesOfALargeExecFutureTestCase extends PhutilTestCase {

  // Most of the core functionality of LinesOfALarge is covered by the
  // LinesOfALargeFile test case, try to just cover exec-specific stuff here.

  public function testExecBasics() {
    $this->writeAndRead(
      "cat\ndog\nbird\n",
      array(
        'cat',
        'dog',
        'bird',
      ));
  }

  public function testExecLargeFile() {
    $line = pht('The quick brown fox jumps over the lazy dog.');
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
    $this->assertTrue($caught instanceof CommandException);
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
      pht('Write: %s', id(new PhutilUTF8StringTruncator())
        ->setMaximumGlyphs(32)
        ->truncateString($write)));
  }

}
