<?php

abstract class PhutilBinaryAnalyzer
  extends Phobject {

  public function getBinaryName() {
    return $this->getBinaryKey();
  }

  public function getBinaryKey() {
    return $this->getPhobjectClassConstant('BINARY');
  }

  public function isBinaryAvailable() {
    return Filesystem::binaryExists($this->getBinaryName());
  }

  abstract protected function newBinaryVersion();

  protected function newBinaryPath() {
    return Filesystem::resolveBinary($this->getBinaryName());
  }

  final public function getBinaryVersion() {
    return $this->newBinaryVersion();
  }

  final public function requireBinaryVersion() {
    $version = $this->getBinaryVersion();
    $binary = $this->getBinaryName();
    if ($version === null) {
      throw new Exception(
        pht(
          'Unable to determine the installed version of binary "%s". This '.
          'version is required.',
          $binary));
    }
    return $version;
  }

  final public function getBinaryPath() {
    return $this->newBinaryPath();
  }

  final public static function getAllBinaries() {
    return id(new PhutilClassMapQuery())
      ->setAncestorClass(__CLASS__)
      ->setUniqueMethod('getBinaryKey')
      ->setSortMethod('getBinaryName')
      ->execute();
  }

  final public static function getForBinary($binary) {
    $map = self::getAllBinaries();

    $analyzer = idx($map, $binary);
    if (!$analyzer) {
      throw new Exception(
        pht(
          'No analyzer is available for binary "%s".',
          $binary));
    }

    return $analyzer;
  }

}
