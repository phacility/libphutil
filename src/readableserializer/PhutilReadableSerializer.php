<?php

/**
 * Serialize PHP values and objects into a human-readable format, useful for
 * displaying errors.
 *
 * @task print Printing PHP Values
 * @task internal Internals
 */
final class PhutilReadableSerializer extends Phobject {


/* -(  Printing PHP Values  )------------------------------------------------ */


  /**
   * Given a value, makes the best attempt at returning a string representation
   * of that value suitable for printing. This method returns a //complete//
   * representation of the value; use @{method:printShort} or
   * @{method:printShallow} to summarize values.
   *
   * @param wild Any value.
   * @return string Human-readable representation of the value.
   * @task print
   */
  public static function printableValue($value) {
    if ($value === null) {
      return 'null';
    } else if ($value === false) {
      return 'false';
    } else if ($value === true) {
      return 'true';
    } else if (is_float($value) && (int)$value == $value) {
      return $value.'.0';
    } else if (is_string($value)) {
      return "'".$value."'";
    } else {
      return print_r($value, true);
    }
  }


  /**
   * Print a concise, human readable representation of a value.
   *
   * @param wild Any value.
   * @return string Human-readable short representation of the value.
   * @task print
   */
  public static function printShort($value) {
    if (is_object($value)) {
      return 'Object '.get_class($value);
    } else if (is_array($value)) {
      $str = 'Array ';
      if ($value) {
        if (count($value) > 1) {
          $str .= 'of size '.count($value).' starting with: ';
        }
        reset($value); // Prevent key() from giving warning message in HPHP.
        $str .= '{ '.self::printShort(key($value)).' => '.
          self::printShort(head($value)).' }';
      }
      return $str;
    } else {
      // NOTE: Avoid PhutilUTF8StringTruncator here since the data may not be
      // UTF8 anyway, it's slow for large inputs, and it might not be loaded
      // yet.
      $limit = 1024;
      $str = self::printableValue($value);
      if (strlen($str) > $limit) {
        if (is_string($value)) {
          $str = "'".substr($str, 1, $limit)."...'";
        } else {
          $str = substr($str, 0, $limit).'...';
        }
      }

      return $str;
    }
  }


  /**
   * Dump some debug output about an object's members without the
   * potential recursive explosion of verbosity that comes with `print_r()`.
   *
   * To print any number of member variables, pass null for `$max_members`.
   *
   * @param wild Any value.
   * @param int Maximum depth to print for nested arrays and objects.
   * @param int Maximum number of values to print at each level.
   * @return string Human-readable shallow representation of the value.
   * @task print
   */
  public static function printShallow(
    $value,
    $max_depth = 2,
    $max_members = 25) {

    return self::printShallowRecursive($value, $max_depth, $max_members, 0, '');
  }


/* -(  Internals  )---------------------------------------------------------- */


  /**
   * Implementation for @{method:printShallow}.
   *
   * @param wild Any value.
   * @param int Maximum depth to print for nested arrays and objects.
   * @param int Maximum number of values to print at each level.
   * @param int Current depth.
   * @param string Indentation string.
   * @return string Human-readable shallow representation of the value.
   * @task internal
   */
  private static function printShallowRecursive(
    $value,
    $max_depth,
    $max_members,
    $depth,
    $indent) {

    if (!is_object($value) && !is_array($value)) {
      return self::addIndentation(self::printableValue($value), $indent, 1);
    }

    $ret = '';
    if (is_object($value)) {
      $ret = get_class($value)."\nwith members ";
      $value = array_filter(@(array)$value);

      // Remove null characters that magically appear around keys for
      // member variables of parent classes.
      $transformed = array();
      foreach ($value as $key => $x) {
        $transformed[str_replace("\0", ' ', $key)] = $x;
      }
      $value = $transformed;
    }

    if ($max_members !== null) {
      $value = array_slice($value, 0, $max_members, $preserve_keys = true);
    }

    $shallow = array();
    if ($depth < $max_depth) {
      foreach ($value as $k => $v) {
        $shallow[$k] = self::printShallowRecursive(
          $v,
          $max_depth,
          $max_members,
          $depth + 1,
          '    ');
      }
    } else {
      foreach ($value as $k => $v) {
        // Extra indentation is for empty arrays, because they wrap on multiple
        // lines and lookup stupid without the extra indentation
        $shallow[$k] = self::addIndentation(self::printShort($v), $indent, 1);
      }
    }

    return self::addIndentation($ret.print_r($shallow, true), $indent, 1);
  }


  /**
   * Adds indentation to the beginning of every line starting from
   * `$first_line`.
   *
   * @param string Printed value.
   * @param string String to indent with.
   * @param int Index of first line to indent.
   * @return string
   * @task internal
   */
  private static function addIndentation($value, $indent, $first_line) {
    $lines = explode("\n", $value);
    $out = array();
    foreach ($lines as $index => $line) {
      $out[] = $index >= $first_line ? $indent.$line : $line;
    }

    return implode("\n", $out);
  }

}
