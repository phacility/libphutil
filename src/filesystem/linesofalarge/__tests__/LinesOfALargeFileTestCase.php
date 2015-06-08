<?php

final class LinesOfALargeFileTestCase extends PhutilTestCase {

  public function testBasics() {
    $this->writeAndRead(
      'abcd',
      array(
        'abcd',
      ));
  }

  public function testTerminalDelimiterPresent() {
    $this->writeAndRead(
      "bat\ncat\ndog\n",
      array(
        'bat',
        'cat',
        'dog',
      ));
  }

  public function testTerminalDelimiterAbsent() {
    $this->writeAndRead(
      "bat\ncat\ndog",
      array(
        'bat',
        'cat',
        'dog',
      ));
  }

  public function testChangeDelimiter() {
    $this->writeAndRead(
      "bat\1cat\1dog\1",
      array(
        'bat',
        'cat',
        'dog',
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
    $line = pht('The quick brown fox jumps over the lazy dog.');
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

    $this->assertTrue($caught instanceof $ex);
  }

  public function testLineFilter() {
    $write = "bat\ncat\ndog\nBat\nCat\nDog\n";
    $read = array(
      1 => 'cat',
      4 => 'Cat',
    );

    $tmp = new TempFile();
    Filesystem::writeFile($tmp, $write);

    $lines = array();
    $iterator = new PhutilCallbackFilterIterator(
      new LinesOfALargeFile($tmp),
      array($this, 'allowCatsOnly'));
    foreach ($iterator as $n => $line) {
      $lines[$n - 1] = $line;
    }

    $this->assertEqual(
      $read,
      $lines,
      pht('Write: %s', id(new PhutilUTF8StringTruncator())
        ->setMaximumGlyphs(32)
        ->truncateString($write)));
  }

  public function allowCatsOnly($line) {
    $line = strtoupper($line);
    if ($line != 'CAT') {
      return null;
    }
    return $line;
  }

  private function writeAndRead($write, $read, $delimiter = "\n") {
    $tmp = new TempFile();
    Filesystem::writeFile($tmp, $write);

    $lines = array();
    $iterator = id(new LinesOfALargeFile($tmp))->setDelimiter($delimiter);
    foreach ($iterator as $n => $line) {
      $lines[$n - 1] = $line;
    }

    $this->assertEqual(
      $read,
      $lines,
      pht('Write: %s', id(new PhutilUTF8StringTruncator())
        ->setMaximumGlyphs(32)
        ->truncateString($write)));
  }

}
