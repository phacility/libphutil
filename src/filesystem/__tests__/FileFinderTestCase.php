<?php

final class FileFinderTestCase extends PhutilTestCase {

  protected function getFinder() {
    $finder = new FileFinder(dirname(__FILE__).'/data');
    $finder->excludePath('./exclude')
      ->excludePath('subdir.txt');
    return $finder;
  }

  public function testFinderWithChecksums() {
    foreach (array('php', 'shell') as $mode) {
      $files = $this->getFinder()
        ->setGenerateChecksums(true)
        ->withType('f')
        ->withPath('*')
        ->withSuffix('txt')
        ->setForceMode($mode)
        ->find();

      // Test whether correct files were found.
      $this->assertTrue(array_key_exists('test.txt', $files));
      $this->assertTrue(array_key_exists('file.txt', $files));
      $this->assertTrue(
        array_key_exists(
          'include_dir.txt/subdir.txt/alsoinclude.txt',
          $files));
      $this->assertFalse(array_key_exists('test', $files));
      $this->assertTrue(array_key_exists('.hidden.txt', $files));
      $this->assertFalse(array_key_exists('exclude/file.txt', $files));
      $this->assertFalse(array_key_exists('include_dir.txt', $files));

      foreach ($files as $file => $checksum) {
        $this->assertFalse(is_dir($file));
      }

      // Test checksums.
      $this->assertEqual(
        $files['test.txt'],
        'aea46212fa8b8d0e0e6aa34a15c9e2f5');
      $this->assertEqual(
        $files['file.txt'],
        '725130ba6441eadb4e5d807898e0beae');
      $this->assertEqual(
        $files['.hidden.txt'],
        'b6cfc9ce9afe12b258ee1c19c235aa27');
      $this->assertEqual(
        $files['include_dir.txt/subdir.txt/alsoinclude.txt'],
        '91e5c1ad76ff229c6456ac92e74e1d9f');
    }
  }

  public function testFinderWithoutChecksums() {
    foreach (array('php', 'shell') as $mode) {
      $files = $this->getFinder()
        ->withType('f')
        ->withPath('*')
        ->withSuffix('txt')
        ->setForceMode($mode)
        ->find();

      // Test whether correct files were found.
      $this->assertTrue(in_array('test.txt', $files));
      $this->assertTrue(in_array('file.txt', $files));
      $this->assertTrue(in_array('.hidden.txt', $files));
      $this->assertTrue(
        in_array('include_dir.txt/subdir.txt/alsoinclude.txt', $files));
      $this->assertFalse(in_array('test', $files));
      $this->assertFalse(in_array('exclude/file.txt', $files));
      $this->assertFalse(in_array('include_dir.txt', $files));

      foreach ($files as $file => $checksum) {
        $this->assertFalse(is_dir($file));
      }
    }
  }

  public function testFinderWithFilesAndDirectories() {
    foreach (array('php', 'shell') as $mode) {
      $files = $this->getFinder()
        ->setGenerateChecksums(true)
        ->withPath('*')
        ->withSuffix('txt')
        ->setForceMode($mode)
        ->find();

      // Test whether the correct files were found.
      $this->assertTrue(array_key_exists('test.txt', $files));
      $this->assertTrue(array_key_exists('file.txt', $files));
      $this->assertTrue(
        array_key_exists(
          'include_dir.txt/subdir.txt/alsoinclude.txt',
          $files));
      $this->assertFalse(array_key_exists('test', $files));
      $this->assertTrue(array_key_exists('.hidden.txt', $files));
      $this->assertFalse(array_key_exists('exclude/file.txt', $files));
      $this->assertTrue(array_key_exists('include_dir.txt', $files));

      // Test checksums.
      $this->assertEqual($files['test.txt'],
          'aea46212fa8b8d0e0e6aa34a15c9e2f5');
      $this->assertEqual($files['include_dir.txt'], null);
    }
  }

  public function testFinderWithDirectories() {
    foreach (array('php', 'shell') as $mode) {
      $directories = $this->getFinder()
        ->withType('d')
        ->setForceMode($mode)
        ->find();

      sort($directories);
      $directories = array_values($directories);

      $this->assertEqual(
        array(
          'include_dir.txt',
          'include_dir.txt/subdir.txt',
        ),
        $directories,
        pht('FileFinder of directories in "%s" mode', $mode));
    }
  }

  public function testFinderWithPath() {
    foreach (array('php', 'shell') as $mode) {
      $files = $this->getFinder()
        ->setGenerateChecksums(true)
        ->withType('f')
        ->withPath('*/include_dir.txt/subdir.txt/alsoinclude.txt')
        ->withSuffix('txt')
        ->setForceMode($mode)
        ->find();

      // Test whether the correct files were found.
      $this->assertTrue(
        array_key_exists(
          'include_dir.txt/subdir.txt/alsoinclude.txt',
          $files));
      // Ensure that only the one file was found.
      $this->assertEqual(1, count($files));
    }
  }

  public function testFinderWithNames() {
    foreach (array('php', 'shell') as $mode) {
      $files = $this->getFinder()
        ->withType('f')
        ->withPath('*')
        ->withName('test')
        ->setForceMode($mode)
        ->find();

      // Test whether the correct files were found.
      $this->assertTrue(in_array('test', $files));
      $this->assertFalse(in_array('exclude/test', $files));
      $this->assertTrue(in_array('include_dir.txt/test', $files));
      $this->assertTrue(in_array('include_dir.txt/subdir.txt/test', $files));
      $this->assertEqual(3, count($files));
    }
  }

}
