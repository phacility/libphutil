<?php

/**
 * String escaped for terminal output. See @{function:tsprintf}.
 */
final class PhutilTerminalString extends Phobject {

  private $string;

  public function __construct($string) {
    $this->string = $string;
  }

  public function __toString() {
    return $this->string;
  }

  public function applyWrap() {
    $string = (string)$this;
    $string = phutil_console_wrap($string);
    return new self($string);
  }

  public function applyIndent($depth, $with_prefix = true) {
    $string = (string)$this;
    $string = phutil_console_wrap($string, $depth, $with_prefix);
    return new self($string);
  }

  public static function escapeStringValue($value, $allow_whitespace) {
    if ($value instanceof PhutilTerminalString) {
      return (string)$value;
    }

    $value = (string)$value;

    static $escape_map;
    if ($escape_map === null) {
      $escape_map = array(
        chr(0x00) => '<NUL>',
        chr(0x07) => '<BEL>',
        chr(0x08) => '<BS>',
        chr(0x09) => '<TAB>',
        chr(0x0A) => '<LF>',
        chr(0x0D) => '<CR>',
        chr(0x1B) => '<ESC>',
        chr(0x7F) => '<DEL>',
      );

      for ($ii = 0; $ii < 32; $ii++) {
        $c = chr($ii);
        if (empty($escape_map[$c])) {
          $escape_map[$c] = sprintf('<0x%02X>', $ii);
        }
      }
    }

    $map = $escape_map;
    if ($allow_whitespace) {
      unset($map["\r"]);
      unset($map["\n"]);
      unset($map["\t"]);
    }

    $value = str_replace(array_keys($map), array_values($map), $value);

    // In this mode, we additionally escape any <CR> which is not immediately
    // followed by <LF>.
    if ($allow_whitespace) {
      $value = preg_replace('/\r(?!\n)/', '<CR>', $value);
    }

    return $value;
  }
}
