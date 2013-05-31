<?php

/**
 * @group testcase
 */
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
    $this->assertEqual(false, null === $path);
    $this->assertEqual(true, file_exists($path));
    $this->assertEqual(false, is_dir($path));

    $this->assertEqual(null,
      Filesystem::resolveBinary('halting-problem-decider'));
  }

}
