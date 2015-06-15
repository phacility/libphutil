<?php

final class PhutilDirectoryFixture extends Phobject {

  protected $path;

  public static function newFromArchive($archive) {
    $obj = self::newEmptyFixture();
    execx(
      'tar -C %s -xzvvf %s',
      $obj->getPath(),
      Filesystem::resolvePath($archive));
    return $obj;
  }

  public static function newEmptyFixture() {
    $obj = new PhutilDirectoryFixture();
    $obj->path = Filesystem::createTemporaryDirectory();
    return $obj;
  }

  private function __construct() {
    // <restricted>
  }

  public function __destruct() {
    Filesystem::remove($this->path);
  }

  public function getPath($to_file = null) {
    return $this->path.'/'.ltrim($to_file, '/');
  }

  public function saveToArchive($path) {
    $tmp = new TempFile();

    execx(
      'tar -C %s -czvvf %s .',
      $this->getPath(),
      $tmp);

    $ok = rename($tmp, Filesystem::resolvePath($path));
    if (!$ok) {
      throw new FilesystemException($path, pht('Failed to overwrite file.'));
    }

    return $this;
  }

}
