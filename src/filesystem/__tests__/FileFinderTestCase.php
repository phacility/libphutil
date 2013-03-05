<?php

/**
 * @group testcase
 */
final class FileFinderTestCase extends PhutilTestCase {

  protected function findFiles($root, $checksums, $type, $path, $mode) {
    $finder = new FileFinder($root);
    $finder->setGenerateChecksums($checksums)
           ->excludePath("./exclude")
           ->excludePath("subdir.txt")
           ->withType($type)
           ->withPath($path)
           ->withSuffix('txt')
           ->setForceMode($mode);
    $files = $finder->find();
    return $files;
  }

  public function testFinderWithChecksums() {
    $root = dirname(__FILE__) . '/data';
    foreach (array("php", "shell") as $mode) {
      $files = $this->findFiles($root, true, 'f', '*', $mode);

      // Test whether correct files were found.
      $this->assertEqual(true,
          array_key_exists('test.txt', $files));
      $this->assertEqual(true,
          array_key_exists('file.txt', $files));
      $this->assertEqual(true,
          array_key_exists('include_dir.txt/subdir.txt/alsoinclude.txt',
              $files));
      $this->assertEqual(false,
          array_key_exists('test', $files));
      $this->assertEqual(true,
          array_key_exists('.hidden.txt', $files));
      $this->assertEqual(false,
          array_key_exists('exclude/file.txt', $files));
      $this->assertEqual(false,
          array_key_exists('include_dir.txt', $files));

      foreach ($files as $file => $checksum) {
        $this->assertEqual(false, is_dir($file));
      }

      // Test checksums.
      $this->assertEqual($files['test.txt'],
          'aea46212fa8b8d0e0e6aa34a15c9e2f5');
      $this->assertEqual($files['file.txt'],
          '725130ba6441eadb4e5d807898e0beae');
      $this->assertEqual($files['.hidden.txt'],
          'b6cfc9ce9afe12b258ee1c19c235aa27');
      $this->assertEqual($files['include_dir.txt/subdir.txt/alsoinclude.txt'],
          '91e5c1ad76ff229c6456ac92e74e1d9f');
    }
  }

  public function testFinderWithoutChecksums() {
    $root = dirname(__FILE__) . '/data';
    foreach (array("php", "shell") as $mode) {
      $files = $this->findFiles($root, false, 'f', '*', $mode);

      // Test whether correct files were found.
      $this->assertEqual(true, in_array('test.txt', $files));
      $this->assertEqual(true, in_array('file.txt', $files));
      $this->assertEqual(true, in_array('.hidden.txt', $files));
      $this->assertEqual(true,
          in_array('include_dir.txt/subdir.txt/alsoinclude.txt', $files));
      $this->assertEqual(false, in_array('test', $files));
      $this->assertEqual(false, in_array('exclude/file.txt', $files));
      $this->assertEqual(false, in_array('include_dir.txt', $files));

      foreach ($files as $file => $checksum) {
        $this->assertEqual(false, is_dir($file));
      }
    }
  }

  public function testFinderWithDirectories() {
    $root = dirname(__FILE__) . '/data';
    foreach (array("php", "shell") as $mode) {
      $files = $this->findFiles($root, true, '', '*', $mode);

      // Test whether the correct files were found.
      $this->assertEqual(true,
          array_key_exists('test.txt', $files));
      $this->assertEqual(true,
          array_key_exists('file.txt', $files));
      $this->assertEqual(true,
          array_key_exists('include_dir.txt/subdir.txt/alsoinclude.txt',
              $files));
      $this->assertEqual(false,
          array_key_exists('test', $files));
      $this->assertEqual(true,
          array_key_exists('.hidden.txt', $files));
      $this->assertEqual(false,
          array_key_exists('exclude/file.txt', $files));
      $this->assertEqual(true,
          array_key_exists('include_dir.txt', $files));

      // Test checksums.
      $this->assertEqual($files['test.txt'],
          'aea46212fa8b8d0e0e6aa34a15c9e2f5');
      $this->assertEqual($files['include_dir.txt'], null);
    }
  }

  public function testFinderWithPath() {
    $root = dirname(__FILE__) . '/data';
    foreach (array("php", "shell") as $mode) {
      $files = $this->findFiles($root, true, 'f',
          '*/include_dir.txt/subdir.txt/alsoinclude.txt', $mode);

      // Test whether the correct files were found.
      $this->assertEqual(true,
          array_key_exists('include_dir.txt/subdir.txt/alsoinclude.txt',
              $files));
      // Ensure that only the one file was found.
      $this->assertEqual(1, count($files));
    }
  }

}
