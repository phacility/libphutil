<?php

/**
 * Lexer for simple options, like:
 *
 *   eyes=2, legs=4
 *
 * Values may be quoted and escaped:
 *
 *   eyes="one, or two", legs="{^,\",^}"
 *
 * @group lexer
 */
final class PhutilSimpleOptionsLexer extends PhutilLexer {

  public function getNiceTokens($input) {
    $tokens = $this->getTokens($input);

    foreach ($tokens as $key => $token) {
      list($type, $value) = $token;
      switch ($type) {
        case 'esc':
          $tokens[$key][0] = 'word';
          $tokens[$key][1] = substr($value, 1);
          break;
      }
    }

    $tokens = $this->mergeTokens($tokens);

    // NOTE: Strip these only after merging tokens, so "a b" merges into two
    // words, "a" and "b", not a single "ab" word.
    foreach ($tokens as $key => $token) {
      list($type, $value) = $token;
      switch ($type) {
        case "'":
        case '"':
        case ' ':
          unset($tokens[$key]);
          break;
      }
    }

    return array_values($tokens);
  }

  protected function getRawRules() {
    return array(
      'start' => array(
        array('\s+', ' '),
        array("'", "'", 'string1'),
        array('"', '"', 'string2'),
        array(',', ','),
        array('=', '='),
        array('[^\\s\'"=,]+', 'word'),
      ),
      'string1' => array(
        array('[^\'\\\\]+', 'word'),
        array("'", "'", '!pop'),
        array('\\\\.', 'esc'),
      ),
      'string2' => array(
        array('[^"\\\\]+', 'word'),
        array('"', '"', '!pop'),
        array('\\\\.', 'esc'),
      ),
    );
  }
}
