<?php

/**
 * Syntax highlighting lexer for JSON fragments.
 */
final class PhutilJSONFragmentLexer extends PhutilLexer {

  protected function getRawRules() {
    return array(
      'start' => array(
        array('"', 's', 'double-quoted-string'),
        array('\s+', null),
        array('[\\[\\]{},:]', 'o'),
        array('(?:true|false|null)', 'k'),
        array('-?\d+(\.\d+([eE][-+]?\d+)?)?', 'mf'),
        array('.', null),
      ),
      'double-quoted-string' => array(
        array('[^"\\\\]+', 's'),
        array('"', 's', '!pop'),
        array('\\\\u[0-9a-fA-F]{4}', 'k'),
        array('\\\\.', 'k'),
      ),
    );
  }

}
