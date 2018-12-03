<?php

final class PhutilQueryString extends Phobject {

  private $escaper;
  private $argv;

  public function __construct(PhutilQsprintfInterface $escaper, array $argv) {
    $this->escaper = $escaper;
    $this->argv = $argv;

    // This makes sure we throw immediately if there are errors in the
    // parameters.
    $this->getMaskedString();
  }

  public function __toString() {
    return $this->getMaskedString();
  }

  public function getUnmaskedString() {
    return $this->renderString(true);
  }

  public function getMaskedString() {
    return $this->renderString(false);
  }

  private function renderString($unmasked) {
    return xsprintf(
      'xsprintf_query',
      array(
        'escaper' => $this->escaper,
        'unmasked' => $unmasked,
      ),
      $this->argv);
  }

}
