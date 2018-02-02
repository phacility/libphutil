<?php

final class FileFinderTestCase extends PhutilTestCase {

  private function newFinder($directory = null) {
    if (!$directory) {
      $directory = dirname(__FILE__).'/data';
    }

    return id(new FileFinder($directory))
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

  public function testFinderWithGlobMagic() {
    // Fill a temporary directory with all this magic garbage so we don't have
    // to check a bunch of files with backslashes in their names into version
    // control.
    $tmp_dir = Filesystem::createTemporaryDirectory();

    $crazy_magic = array(
      'backslash\\.\\*',
      'star-*.*',
      'star-*.txt',
      'star.t*t',
      'star.tesseract',
    );

    foreach ($crazy_magic as $sketchy_path) {
      Filesystem::writeFile($tmp_dir.'/'.$sketchy_path, '.');
    }

    $this->assertFinder(
      pht('Glob Magic, Literal .t*t'),
      $this->newFinder($tmp_dir)
        ->withType('f')
        ->withSuffix('t*t'),
      array(
        'star.t*t',
      ));

    $this->assertFinder(
      pht('Glob Magic, .tesseract'),
      $this->newFinder($tmp_dir)
        ->withType('f')
        ->withSuffix('tesseract'),
      array(
        'star.tesseract',
      ));

    $this->assertFinder(
      pht('Glob Magic, Name'),
      $this->newFinder($tmp_dir)
        ->withType('f')
        ->withName('star-*'),
      array());

    $this->assertFinder(
      pht('Glob Magic, Name + Suffix'),
      $this->newFinder($tmp_dir)
        ->withType('f')
        ->withName('star-*.*'),
      array(
        'star-*.*',
      ));

    $this->assertFinder(
      pht('Glob Magic, Backslash Suffix'),
      $this->newFinder($tmp_dir)
        ->withType('f')
        ->withSuffix('\\*'),
      array(
        'backslash\\.\\*',
      ));

    $this->assertFinder(
      pht('Glob Magic, With Globs'),
      $this->newFinder($tmp_dir)
        ->withType('f')
        ->withNameGlob('star-*'),
      array(
        'star-*.*',
        'star-*.txt',
      ));

    $this->assertFinder(
      pht('Glob Magic, With Globs + Suffix'),
      $this->newFinder($tmp_dir)
        ->withType('f')
        ->withNameGlob('star-*')
        ->withSuffix('txt'),
      array(
        'star-*.txt',
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
