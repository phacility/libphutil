<?php

final class PhutilHashingIterator
  extends PhutilProxyIterator
  implements Iterator {

  private $hash;
  private $algorithm;

  public function setAlgorithm($algorithm) {
    $this->algorithm = $algorithm;
    return $this;
  }

  public function getAlgorithm() {
    return $this->algorithm;
  }

  public function getHash() {
    $hash = $this->getHashResource();
    return hash_final($hash, $raw_output = false);
  }

  protected function didReadValue($value) {
    $hash = $this->getHashResource();

    hash_update($hash, $value);

    return $value;
  }

  private function getHashResource() {
    if (!$this->hash) {
      $algorithm = $this->getAlgorithm();
      $this->hash = hash_init($algorithm);
    }
    return $this->hash;
  }

}
