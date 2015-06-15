<?php

/**
 * Utilities for parsing simple option lists used in Remarkup, like codeblocks:
 *
 *   lang=text
 *   lang=php, name=example.php, lines=30, counterexample
 *
 * @task parse    Parsing Simple Options
 * @task unparse  Unparsing Simple Options
 * @task config   Parser Configuration
 * @task internal Internals
 */
final class PhutilSimpleOptions extends Phobject {

  private $caseSensitive;


/* -(  Parsing Simple Options  )--------------------------------------------- */


  /**
   * Convert a simple option list into a dict. For example:
   *
   *    legs=4, eyes=2
   *
   * ...becomes:
   *
   *    array(
   *      'legs' => '4',
   *      'eyes' => '2',
   *    );
   *
   * @param   string  Input option list.
   * @return  dict    Parsed dictionary.
   * @task parse
   */
  public function parse($input) {
    $result = array();

    $lexer = new PhutilSimpleOptionsLexer();
    $tokens = $lexer->getNiceTokens($input);

    $state = 'key';
    $pairs = array();
    foreach ($tokens as $token) {
      list($type, $value) = $token;
      switch ($state) {
        case 'key':
          if ($type != 'word') {
            return array();
          }
          if (!strlen($value)) {
            return array();
          }
          $key = $this->normalizeKey($value);
          $state = '=';
          break;
        case '=':
          if ($type == '=') {
            $state = 'value';
            break;
          }
          if ($type == ',') {
            $pairs[] = array($key, true);
            $state = 'key';
            break;
          }
          return array();
        case 'value':
          if ($type == ',') {
            $pairs[] = array($key, null);
            $state = 'key';
            break;
          }
          if ($type != 'word') {
            return array();
          }
          $pairs[] = array($key, $value);
          $state = ',';
          break;
        case ',':
          if ($type == 'word') {
            $pair = array_pop($pairs);
            $pair[1] .= $value;
            $pairs[] = $pair;
            break;
          }
          if ($type != ',') {
            return array();
          }
          $state = 'key';
          break;
      }
    }

    if ($state == '=') {
      $pairs[] = array($key, true);
    }
    if ($state == 'value') {
      $pairs[] = array($key, null);
    }

    $result = array();
    foreach ($pairs as $pair) {
      list($key, $value) = $pair;
      if ($value === null) {
        unset($result[$key]);
      } else {
        $result[$key] = $value;
      }
    }

    return $result;
  }


/* -(  Unparsing Simple Options  )------------------------------------------- */


  /**
   * Convert a dictionary into a simple option list. For example:
   *
   *    array(
   *      'legs' => '4',
   *      'eyes' => '2',
   *    );
   *
   * ...becomes:
   *
   *    legs=4, eyes=2
   *
   * @param   dict    Input dictionary.
   * @param   string  Additional characters to escape.
   * @return  string  Unparsed option list.
   */
  public function unparse(array $options, $escape = '') {
    $result = array();
    foreach ($options as $name => $value) {
      $name = $this->normalizeKey($name);
      if (!strlen($value)) {
        continue;
      }
      if ($value === true) {
        $result[] = $this->quoteString($name, $escape);
      } else {
        $qn = $this->quoteString($name, $escape);
        $qv = $this->quoteString($value, $escape);
        $result[] = $qn.'='.$qv;
      }
    }
    return implode(', ', $result);
  }


/* -(  Parser Configuration  )----------------------------------------------- */


  /**
   * Configure case sensitivity of the parser. By default, the parser is
   * case insensitive, so "legs=4" has the same meaning as "LEGS=4". If you
   * set it to be case sensitive, the keys have different meanings.
   *
   * @param bool  True to make the parser case sensitive, false (default) to
   *              make it case-insensitive.
   * @return this
   * @task config
   */
  public function setCaseSensitive($case_sensitive) {
    $this->caseSensitive = $case_sensitive;
    return $this;
  }


/* -(  Internals  )---------------------------------------------------------- */


  private function normalizeKey($key) {
    if (!strlen($key)) {
      throw new Exception(pht('Empty key is invalid!'));
    }
    if (!$this->caseSensitive) {
      $key = strtolower($key);
    }
    return $key;
  }

  private function quoteString($string, $escape) {
    if (preg_match('/[^a-zA-Z0-9]/', $string)) {
      $string = '"'.addcslashes($string, '\\\'"'.$escape).'"';
    }
    return $string;
  }

}
