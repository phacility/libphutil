<?php

final class FileFinderTestCase extends PhutilTestCase {

  private function newFinder() {
    return id(new FileFinder(dirname(__FILE__).'/data'))
      ->excludePath('./exclude')
      ->excludePath('subdir.txt');
  }

  public function testFinderWithChecksums() {
    $this->assertFinder(
      pht('Basic Checksums'),
      $this->newFinder()
        ->setGenerateChecksums(true)
        ->withType('f')
        ->withPath('*')
        ->withSuffix('txt'),
      array(
        '.hidden.txt' =>
          'b6cfc9ce9afe12b258ee1c19c235aa27',
        'file.txt' =>
          '725130ba6441eadb4e5d807898e0beae',
        'include_dir.txt/anotherfile.txt' =>
          '91e5c1ad76ff229c6456ac92e74e1d9f',
        'include_dir.txt/subdir.txt/alsoinclude.txt' =>
          '91e5c1ad76ff229c6456ac92e74e1d9f',
        'test.txt' =>
          'aea46212fa8b8d0e0e6aa34a15c9e2f5',
      ));
  }

  public function testFinderWithoutChecksums() {
    $this->assertFinder(
      pht('Basic No Checksums'),
      $this->newFinder()
        ->withType('f')
        ->withPath('*')
        ->withSuffix('txt'),
      array(
        '.hidden.txt',
        'file.txt',
        'include_dir.txt/anotherfile.txt',
        'include_dir.txt/subdir.txt/alsoinclude.txt',
        'test.txt',
      ));
  }

  public function testFinderWithFilesAndDirectories() {
    $this->assertFinder(
      pht('With Files And Directories'),
      $this->newFinder()
        ->setGenerateChecksums(true)
        ->withPath('*')
        ->withSuffix('txt'),
      array(
        '.hidden.txt' =>
          'b6cfc9ce9afe12b258ee1c19c235aa27',
        'file.txt' =>
          '725130ba6441eadb4e5d807898e0beae',
        'include_dir.txt' => null,
        'include_dir.txt/anotherfile.txt' =>
          '91e5c1ad76ff229c6456ac92e74e1d9f',
        'include_dir.txt/subdir.txt' => null,
        'include_dir.txt/subdir.txt/alsoinclude.txt' =>
          '91e5c1ad76ff229c6456ac92e74e1d9f',
        'test.txt' =>
          'aea46212fa8b8d0e0e6aa34a15c9e2f5',
      ));
  }

  public function testFinderWithDirectories() {
    $this->assertFinder(
      pht('Just Directories'),
      $this->newFinder()
        ->withType('d'),
      array(
        'include_dir.txt',
        'include_dir.txt/subdir.txt',
      ));
  }

  public function testFinderWithPath() {
    $this->assertFinder(
      pht('With Path'),
      $this->newFinder()
        ->setGenerateChecksums(true)
        ->withType('f')
        ->withPath('*/include_dir.txt/subdir.txt/alsoinclude.txt')
        ->withSuffix('txt'),
      array(
        'include_dir.txt/subdir.txt/alsoinclude.txt' =>
          '91e5c1ad76ff229c6456ac92e74e1d9f',
      ));
  }

  public function testFinderWithNames() {
    $this->assertFinder(
      pht('With Names'),
      $this->newFinder()
        ->withType('f')
        ->withPath('*')
        ->withName('test'),
      array(
        'include_dir.txt/subdir.txt/test',
        'include_dir.txt/test',
        'test',
      ));
  }

  public function testFinderWithNameAndSuffix() {
    $this->assertFinder(
      pht('With Name and Suffix'),
      $this->newFinder()
        ->withType('f')
        ->withName('alsoinclude.txt')
        ->withSuffix('txt'),
      array(
        'include_dir.txt/subdir.txt/alsoinclude.txt',
      ));
  }

  private function assertFinder($label, FileFinder $finder, $expect) {
    $modes = array(
      'php',
      'shell',
    );
    foreach ($modes as $mode) {
      $actual = id(clone $finder)
        ->setForceMode($mode)
        ->find();

      if ($finder->getGenerateChecksums()) {
        ksort($actual);
      } else {
        sort($actual);
      }

      $this->assertEqual(
        $expect,
        $actual,
        pht('Test Case "%s" in Mode "%s"', $label, $mode));
    }
  }

}
