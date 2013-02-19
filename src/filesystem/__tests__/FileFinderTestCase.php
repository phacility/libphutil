<?php

/**
 * @group testcase
 */
final class FileFinderTestCase extends PhutilTestCase {

  private $root;
  private $files;

  protected function findFiles($root, $checksums) {
    $finder = new FileFinder($root);
    $finder->setGenerateChecksums($checksums)
           ->excludePath("./exclude")
           ->withType('f')
           ->withSuffix('txt');
    $files = $finder->find();
    return $files;
  }

  public function testFinderWithChecksums() {
    $this->root = dirname(__FILE__) . '/data/';
    $this->files = $this->findFiles($this->root, true);

    // Test whether correct files were found.
    $this->assertEqual(true,
        array_key_exists($this->root . '/test.txt', $this->files));
    $this->assertEqual(true,
        array_key_exists($this->root . '/file.txt', $this->files));
    $this->assertEqual(false,
        array_key_exists($this->root . '/test', $this->files));
    $this->assertEqual(false,
        array_key_exists($this->root . '/exclude/file.txt', $this->files));

    foreach ($this->files as $file => $checksum) {
      $this->assertEqual(false, is_dir($file));
    }

    // Test checksums.
    $this->assertEqual($this->files[$this->root . '/test.txt'],
        'aea46212fa8b8d0e0e6aa34a15c9e2f5');
    $this->assertEqual($this->files[$this->root . '/file.txt'],
        '725130ba6441eadb4e5d807898e0beae');
  }

  public function testFinderWithoutChecksums() {
    $this->root = dirname(__FILE__) . '/data/';
    $this->files = $this->findFiles($this->root, false);

    // Test whether correct files were found.
    $this->assertEqual(true, in_array('./test.txt', $this->files));
    $this->assertEqual(true, in_array('./file.txt', $this->files));
    $this->assertEqual(false, in_array('./test', $this->files));
    $this->assertEqual(false, in_array('./exclude/file.txt', $this->files));

    foreach ($this->files as $file => $checksum) {
      $this->assertEqual(false, is_dir($file));
    }
  }

}
