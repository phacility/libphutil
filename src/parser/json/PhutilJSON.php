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

/**
 * Utilities for wrangling JSON.
 *
 */
final class PhutilJSON {

  /**
   * Encode an object in JSON and pretty-print it.
   *
   * @param   dict    An object to encode in JSON.
   * @return  string  Pretty-printed object representation.
   */
  public function encodeFormatted(array $object) {
    return $this->encodeFormattedObject($object, 0)."\n";
  }

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
      $key_lines[] = $key_pre.str_pad($key, $max).' : '.$vals[$k];
    }
    $key_lines = implode(",\n", $key_lines);

    $out  = "{\n";
    $out .= $key_lines;
    $out .= "\n";
    $out .= $pre.'}';

    return $out;
  }

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

  private function encodeFormattedValue($value, $depth) {
    if (is_array($value)) {
      if (array_keys($value) === range(0, count($value) - 1)) {
        return $this->encodeFormattedArray($value, $depth);
      } else {
        return $this->encodeFormattedObject($value, $depth);
      }
    } else {
      return json_encode($value, true);
    }
  }

  private function getIndent($depth) {
    if (!$depth) {
      return '';
    } else {
      return str_repeat('  ', $depth);
    }
  }
}
