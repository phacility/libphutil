<?php

/**
 * @group testcase
 */
final class FileFinderTestCase extends PhutilTestCase {

  protected function findFiles($root, $checksums, $type) {
    $finder = new FileFinder($root);
    $finder->setGenerateChecksums($checksums)
           ->excludePath("./exclude")
           ->withType($type)
           ->withSuffix('txt');
    $files = $finder->find();
    return $files;
  }

  public function testFinderWithChecksums() {
    $root = dirname(__FILE__) . '/data';
    $files = $this->findFiles($root, true, 'f');

    // Test whether correct files were found.
    $this->assertEqual(true,
        array_key_exists($root . '/test.txt', $files));
    $this->assertEqual(true,
        array_key_exists($root . '/file.txt', $files));
    $this->assertEqual(false,
        array_key_exists($root . '/test', $files));
    $this->assertEqual(false,
        array_key_exists($root . '/exclude/file.txt', $files));
    $this->assertEqual(false,
        array_key_exists($root . '/include_dir.txt', $files));

    foreach ($files as $file => $checksum) {
      $this->assertEqual(false, is_dir($file));
    }

    // Test checksums.
    $this->assertEqual($files[$root . '/test.txt'],
        'aea46212fa8b8d0e0e6aa34a15c9e2f5');
    $this->assertEqual($files[$root . '/file.txt'],
        '725130ba6441eadb4e5d807898e0beae');
  }

  public function testFinderWithoutChecksums() {
    $root = dirname(__FILE__) . '/data';
    $files = $this->findFiles($root, false, 'f');

    // Test whether correct files were found.
    $this->assertEqual(true, in_array('./test.txt', $files));
    $this->assertEqual(true, in_array('./file.txt', $files));
    $this->assertEqual(false, in_array('./test', $files));
    $this->assertEqual(false, in_array('./exclude/file.txt', $files));
    $this->assertEqual(false, in_array('./include_dir.txt', $files));

    foreach ($files as $file => $checksum) {
      $this->assertEqual(false, is_dir($file));
    }
  }

  public function testFinderWithDirectories() {
    $root = dirname(__FILE__) . '/data';
    $files = $this->findFiles($root, true, '');

    // Test whether the correct files were found.
    $this->assertEqual(true,
        array_key_exists($root . '/test.txt', $files));
    $this->assertEqual(true,
        array_key_exists($root . '/file.txt', $files));
    $this->assertEqual(false,
        array_key_exists($root . '/test', $files));
    $this->assertEqual(false,
        array_key_exists($root . '/exclude/file.txt', $files));
    $this->assertEqual(true,
        array_key_exists($root . '/include_dir.txt', $files));

    // Test checksums.
    $this->assertEqual($files[$root . '/test.txt'],
        'aea46212fa8b8d0e0e6aa34a15c9e2f5');
    $this->assertEqual($files[$root . '/include_dir.txt'], null);
  }

}
