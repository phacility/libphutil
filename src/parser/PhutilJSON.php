<?php

/**
 * Utilities for wrangling JSON.
 *
 * @task pretty Formatting JSON Objects
 * @task internal Internals
 */
final class PhutilJSON extends Phobject {


/* -(  Formatting JSON Objects  )-------------------------------------------- */


  /**
   * Encode an object in JSON and pretty-print it. This generates a valid JSON
   * object with human-readable whitespace and indentation.
   *
   * @param   dict    An object to encode in JSON.
   * @return  string  Pretty-printed object representation.
   */
  public function encodeFormatted(array $object) {
    return $this->encodeFormattedObject($object, 0)."\n";
  }


  /**
   * Encode a list in JSON and pretty-print it, discarding keys.
   *
   * @param list<wild> List to encode in JSON.
   * @return string Pretty-printed list representation.
   */
  public function encodeAsList(array $list) {
    return $this->encodeFormattedArray($list, 0)."\n";
  }


/* -(  Internals  )---------------------------------------------------------- */


  /**
   * Pretty-print a JSON object.
   *
   * @param   dict    Object to format.
   * @param   int     Current depth, for indentation.
   * @return  string  Pretty-printed value.
   * @task internal
   */
  private function encodeFormattedObject($object, $depth) {
    if (empty($object)) {
      return '{}';
    }

    $pre = $this->getIndent($depth);
    $key_pre = $this->getIndent($depth + 1);
    $keys = array();
    $vals = array();
    $max = 0;
    foreach ($object as $key => $val) {
      $ekey = $this->encodeFormattedValue((string)$key, 0);
      $max = max($max, strlen($ekey));
      $keys[] = $ekey;
      $vals[] = $this->encodeFormattedValue($val, $depth + 1);
    }
    $key_lines = array();
    foreach ($keys as $k => $key) {
      $key_lines[] = $key_pre.$key.': '.$vals[$k];
    }
    $key_lines = implode(",\n", $key_lines);

    $out  = "{\n";
    $out .= $key_lines;
    $out .= "\n";
    $out .= $pre.'}';

    return $out;
  }


  /**
   * Pretty-print a JSON list.
   *
   * @param   list    List to format.
   * @param   int     Current depth, for indentation.
   * @return  string  Pretty-printed value.
   * @task internal
   */
  private function encodeFormattedArray($array, $depth) {
    if (empty($array)) {
      return '[]';
    }

    $pre = $this->getIndent($depth);
    $val_pre = $this->getIndent($depth + 1);

    $vals = array();
    foreach ($array as $val) {
      $vals[] = $val_pre.$this->encodeFormattedValue($val, $depth + 1);
    }
    $val_lines = implode(",\n", $vals);

    $out  = "[\n";
    $out .= $val_lines;
    $out .= "\n";
    $out .= $pre.']';

    return $out;
  }


  /**
   * Pretty-print a JSON value.
   *
   * @param   dict    Value to format.
   * @param   int     Current depth, for indentation.
   * @return  string  Pretty-printed value.
   * @task internal
   */
  private function encodeFormattedValue($value, $depth) {
    if (is_array($value)) {
      if (phutil_is_natural_list($value)) {
        return $this->encodeFormattedArray($value, $depth);
      } else {
        return $this->encodeFormattedObject($value, $depth);
      }
    } else {
      if (defined('JSON_UNESCAPED_SLASHES')) {
        // If we have a new enough version of PHP, disable escaping of slashes
        // when pretty-printing values. Escaping slashes can defuse an attack
        // where the attacker embeds "</script>" inside a JSON string, but that
        // isn't relevant when rendering JSON for human viewers.
        return json_encode($value, JSON_UNESCAPED_SLASHES);
      } else {
        return json_encode($value);
      }
    }
  }


  /**
   * Render a string corresponding to the current indent depth.
   *
   * @param   int     Current depth.
   * @return  string  Indentation.
   * @task internal
   */
  private function getIndent($depth) {
    if (!$depth) {
      return '';
    } else {
      return str_repeat('  ', $depth);
    }
  }

}
