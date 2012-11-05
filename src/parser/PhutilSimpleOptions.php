<?php

/**
 * Utilities for parsing simple option lists used in Remarkup, like codeblocks:
 *
 *   lang=text
 *   lang=php, name=example.php, lines=30, counterexample
 *
 * @task parse Parsing Simple Options
 * @task unparse Unparsing Simple Options
 * @task internal Internals
 *
 * @group util
 */
final class PhutilSimpleOptions {


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
  public static function parse($input) {
    $result = array();

    $vars = explode(',', $input);
    foreach ($vars as $var) {
      if (strpos($var, '=') !== false) {
        list($key, $value) = explode('=', $var, 2);
        $value = trim($value);
      } else {
        list($key, $value) = array($var, true);
      }
      $key = trim($key);
      $key = strtolower($key);
      if (!self::isValidKey($key)) {
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
  public static function unparse(array $options) {
    $result = array();
    foreach ($options as $name => $value) {
      if (!self::isValidKey($name)) {
        throw new Exception(
          "SimpleOptions: keys must contain only lowercase letters.");
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


/* -(  Internals  )---------------------------------------------------------- */


  private static function isValidKey($key) {
    return (bool)preg_match('/^[a-z]+$/', $key);
  }

}
