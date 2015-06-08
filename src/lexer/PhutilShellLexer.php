<?php

/**
 * Lexer for shell-like argument strings. Somewhat similar to Python's shlex.
 */
final class PhutilShellLexer extends PhutilLexer {

  /**
   * Convert a shell command string into an argument vector. For example, this
   * converts a string like:
   *
   *   a 'b c' "d"'"'"e" f\ g "\""
   *
   * ...into this argument vector:
   *
   *   array(
   *     "a",
   *     "b c",
   *     "d\"e",
   *     "f g",
   *     "\"",
   *   );
   *
   * @param   string  Shell command string.
   * @return  array   Parsed argument vector.
   */
  public function splitArguments($string) {
    $tokens = $this->getTokens($string);
    if (count($this->getLexerState()) > 1) {
      throw new UnexpectedValueException(
        pht('Unterminated string in argument list!'));
    }

    foreach ($tokens as $key => $token) {
      switch ($token[0]) {
        case "'":
        case '"':
          unset($tokens[$key]);
          break;
        case 'esc':
          $tokens[$key][0] = 'arg';
          $tokens[$key][1] = substr($token[1], 1);
          break;
        default:
          break;
      }
    }

    $tokens = $this->mergeTokens(array_values($tokens));

    $argv = array();
    foreach ($tokens as $token) {
      if ($token[0] == 'arg') {
        $argv[] = $token[1];
      }
    }

    return $argv;
  }

  protected function getRawRules() {
    return array(
      'start' => array(
        array('\s+', ' '),
        array("'", "'", 'string1'),
        array('"', '"', 'string2'),
        array('\\\\.', 'esc'),
        array('[^\\s\'"\\\\]+', 'arg'),
      ),
      'string1' => array(
        // NOTE: In a single-quoted string, backslash is not an escape.
        array('[^\']+', 'arg'),
        array("'", "'", '!pop'),
      ),
      'string2' => array(
        // NOTE: In a double-quoted string, backslash IS an escape, but only
        // for some characters: ", $, `, \ and newline.
        array('[^"\\\\]+', 'arg'),
        array('"', '"', '!pop'),
        array('\\\\["$`\\\\\\n]', 'esc'),
        array('\\\\.', 'arg'),
      ),
    );
  }

}
