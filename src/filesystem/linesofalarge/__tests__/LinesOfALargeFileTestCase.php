<?php

/**
 * @group testcase
 */
final class LinesOfALargeFileTestCase extends PhutilTestCase {

  public function testBasics() {
    $this->writeAndRead(
      "abcd",
      array(
        "abcd",
      ));
  }

  public function testTerminalDelimiterPresent() {
    $this->writeAndRead(
      "bat\ncat\ndog\n",
      array(
        "bat",
        "cat",
        "dog",
      ));
  }

  public function testTerminalDelimiterAbsent() {
    $this->writeAndRead(
      "bat\ncat\ndog",
      array(
        "bat",
        "cat",
        "dog",
      ));
  }

  public function testChangeDelimiter() {
    $this->writeAndRead(
      "bat\1cat\1dog\1",
      array(
        "bat",
        "cat",
        "dog",
      ),
      "\1");
  }

  public function testEmptyLines() {
    $this->writeAndRead(
      "\n\nbat\n",
      array(
        '',
        '',
        'bat',
      ));
  }

  public function testLargeFile() {
    $line = "The quick brown fox jumps over the lazy dog.";
    $n    = 100;

    $this->writeAndRead(
      str_repeat($line."\n", $n),
      array_fill(0, $n, $line));
  }

  public function testLongLine() {
    $line = str_repeat('x', 64 * 1024);
    $this->writeAndRead($line, array($line));
  }

  public function testReadFailure() {
    $caught = null;
    try {
      $f = new LinesOfALargeFile('/does/not/exist.void');
      $f->rewind();
    } catch (FilesystemException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(true, $caught instanceof $ex);
  }

  private function writeAndRead($write, $read, $delimiter = "\n") {
    $tmp = new TempFile();
    Filesystem::writeFile($tmp, $write);

    $lines = array();
    $iterator = id(new LinesOfALargeFile($tmp))->setDelimiter($delimiter);
    foreach ($iterator as $line) {
      $lines[] = $line;
    }

    $this->assertEqual(
      $read,
      $lines,
      "Write: ".phutil_utf8_shorten($write, 32));
  }

}
