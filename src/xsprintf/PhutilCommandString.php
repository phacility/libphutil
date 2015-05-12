<?php

final class PhutilCommandString extends Phobject {

  private $argv;
  private $escapingMode = false;

  const MODE_DEFAULT = 'default';
  const MODE_POWERSHELL = 'powershell';

  public function __construct(array $argv) {
    $this->argv = $argv;

    $this->escapingMode = self::MODE_DEFAULT;

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

  public function setEscapingMode($escaping_mode) {
    $this->escapingMode = $escaping_mode;
    return $this;
  }

  private function renderString($unmasked) {
    return xsprintf(
      'xsprintf_command',
      array(
        'unmasked' => $unmasked,
        'mode' => $this->escapingMode,
      ),
      $this->argv);
  }

  public static function escapeArgument($value, $mode) {
    switch ($mode) {
      case self::MODE_DEFAULT:
        return escapeshellarg($value);
      case self::MODE_POWERSHELL:
        return self::escapePowershell($value);
      default:
        throw new Exception(pht('Unknown escaping mode!'));
    }
  }

  private static function escapePowershell($value) {
    // These escape sequences are from http://ss64.com/ps/syntax-esc.html

    // Replace backticks first.
    $value = str_replace('`', '``', $value);

    // Now replace other required notations.
    $value = str_replace("\0", '`0', $value);
    $value = str_replace(chr(7), '`a', $value);
    $value = str_replace(chr(8), '`b', $value);
    $value = str_replace("\f", '`f', $value);
    $value = str_replace("\n", '`n', $value);
    $value = str_replace("\r", '`r', $value);
    $value = str_replace("\t", '`t', $value);
    $value = str_replace("\v", '`v', $value);
    $value = str_replace('#', '`#', $value);
    $value = str_replace("'", '`\'', $value);
    $value = str_replace('"', '`"', $value);

    // The rule on dollar signs is mentioned further down the page, and
    // they only need to be escaped when using double quotes (which we are).
    $value = str_replace('$', '`$', $value);

    return '"'.$value.'"';
  }

}
