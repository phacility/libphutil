<?php

final class PhutilCommandString extends Phobject {

  private $argv;

  public function __construct(array $argv) {
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
      'xsprintf_command',
      array(
        'unmasked' => $unmasked,
      ),
      $this->argv);
  }

}
