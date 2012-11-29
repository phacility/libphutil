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
 *
 * @group util
 */
final class PhutilSimpleOptions {

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

    $vars = explode(',', $input);
    foreach ($vars as $var) {
      if (strpos($var, '=') !== false) {
        list($key, $value) = explode('=', $var, 2);
        $value = trim($value);
      } else {
        list($key, $value) = array($var, true);
      }
      $key = $this->normalizeKey($key);
      if (!$this->isValidKey($key)) {
        // If there are bad keys, just bail, so we don't get silly results for
        // parsing inputs like "SELECT id, name, size FROM table".
        return array();
      }
      if (!strlen($value)) {
        unset($result[$key]);
        continue;
      }
      $result[$key] = $value;
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
   * @return  string  Unparsed option list.
   */
  public function unparse(array $options) {
    $result = array();
    foreach ($options as $name => $value) {
      if (!$this->isValidKey($name)) {
        throw new Exception(
          "SimpleOptions: keys '{$name}' is not valid.");
      }
      if (!strlen($value)) {
        continue;
      }
      if ($value === true) {
        $result[] = $name;
      } else {
        $result[] = $name.'='.$value;
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


  private function isValidKey($key) {
    if (!$this->caseSensitive) {
      $regexp = '/^[a-z]+$/';
    } else {
      $regexp = '/^[a-z]+$/i';
    }

    return (bool)preg_match($regexp, $key);
  }

  private function normalizeKey($key) {
    $key = trim($key);
    if (!$this->caseSensitive) {
      $key = strtolower($key);
    }
    return $key;
  }

}
