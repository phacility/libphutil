<?php

final class FilesystemTestCase extends PhutilTestCase {

  public function testBinaryExists() {
    // Test for the `which` binary on Linux, and the `where` binary on Windows,
    // because `which which` is cute.

    if (phutil_is_windows()) {
      $exists = 'where';
    } else {
      $exists = 'which';
    }

    $this->assertEqual(
      true,
      Filesystem::binaryExists($exists));

    // We don't expect to find this binary on any system.

    $this->assertEqual(
      false,
      Filesystem::binaryExists('halting-problem-decider'));
  }

  public function testResolveBinary() {
    // Test to make sure resolveBinary() returns the full path to the `which`
    // and `where` binaries.

    if (phutil_is_windows()) {
      $binary = 'where';
    } else {
      $binary = 'which';
    }

    $path = Filesystem::resolveBinary($binary);
    $this->assertFalse(null === $path);
    $this->assertTrue(file_exists($path));
    $this->assertFalse(is_dir($path));

    $this->assertEqual(null,
      Filesystem::resolveBinary('halting-problem-decider'));
  }

  public function testWriteUniqueFile() {
    $tmp = new TempFile();
    $dir = dirname($tmp);

    // Writing an empty file should work.
    $f = Filesystem::writeUniqueFile($dir, '');
    $this->assertEqual('', Filesystem::readFile($f));

    // File name should be unique.
    $g = Filesystem::writeUniqueFile($dir, 'quack');
    $this->assertTrue($f != $g);
  }

  public function testReadRandomBytes() {
    $number_of_bytes = 1024;
    $data = Filesystem::readRandomBytes($number_of_bytes);
    $this->assertTrue(strlen($data) == $number_of_bytes);

    $data1 = Filesystem::readRandomBytes(128);
    $data2 = Filesystem::readRandomBytes(128);
    $this->assertFalse($data1 == $data2);

    $caught = null;
    try {
      Filesystem::readRandomBytes(0);
    } catch (Exception $ex) {
      $caught = $ex;
    }
    $this->assertTrue($caught instanceof Exception);
  }

}
