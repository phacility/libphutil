<?php

/*
 * Copyright 2011 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

class PhutilReadableSerializer {

  /**
   * Given a value, makes the best attempt at returning a string
   * representation of that value suitable for printing
   *
   * @param $value mixed
   * @return string
   */
  public static function printableValue($value) {
    if ($value === null) {
      return 'null';
    } else if ($value === false) {
      return 'false';
    } else if ($value === true) {
      return 'true';
    } else {
      return print_r($value, true);
    }
  }


  /**
   * Print a concise, human readable name for an object.
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
        reset($value); // Prevent key() from giving warning message.
        $str .= '{ '.key($value).' => '.
          self::printShort(head($value)).' }';
      }
      return $str;
    } else {
      return self::printableValue($value);
    }
  }

  /**
   * Dump some debug output about an object's members without the
   * potential recursive explosion of verbosity that comes with print_r.
   * To print any number of member variables, pass null for max_members.
   */
  public static function printShallow($value, $max_depth=2, $depth=0,
                                      $max_members=25, $indent='') {
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
      $value = array_slice($value, 0, $max_members);
    }

    $shallow = array();
    if ($depth < $max_depth) {
      foreach ($value as $v) {
        $shallow[] = self::printShallow($v, $max_depth, $depth + 1,
                                        $max_members, '    ');
      }
    } else {
      foreach ($value as $v) {
        // Extra indentation is for empty arrays, because they wrap on multiple
        // lines and lookup stupid without the extra indentation
        $shallow[] = self::addIndentation(self::printShort($v), $indent, 1);
      }
    }

    return self::addIndentation($ret.print_r($shallow, true), $indent, 1);
  }

  /**
   * Adds indentation to the beginning of every line starting from first_line
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
