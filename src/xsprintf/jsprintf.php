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
 * Format a Javascript string, using JSON to export complex values. This
 * function behaves like sprintf(), except that all the normal conversions
 * (like %s) will be properly escaped, and additional conversions are
 * supported:
 *
 *   %O (Object)
 *     Converts the argument to a JSON object.
 *
 *   %A (Array)
 *     Converts the argument to a JSON array.
 *
 *   %b (Boolean)
 *     Converts a value to either `true' or `false'.
 *
 *   %# (FBID)
 *     JavaScript has issues with 64-bit numbers so we use this as our
 *     transport mechanism from PHP to JavaScript
 *
 *   %J (Javascript)
 *     Inserts raw, unescaped Javascript. This is DANGEROUS because it WILL
 *     NOT BE ESCAPED.
 *
 * @group markup
 */
function jsprintf($pattern /*, ... */) {
  $args = func_get_args();
  return xsprintf('xsprintf_javascript', null, $args);
}


/**
 * @group markup
 */
function vjsprintf($pattern, array $argv) {
  array_unshift($argv, $pattern);
  return xsprintf('xsprintf_javascript', null, $argv);
}


/**
 * xsprintf() callback for javascript encoding.
 * @group markup
 */
function xsprintf_javascript($userdata, &$pattern, &$pos, &$value, &$length) {

  $type = $pattern[$pos];

  switch ($type) {
    case '#':
    case 's':
      $value = json_encode((string)$value);
      $type = 's';
      break;

    case 'A':
      if (!is_array($value)) {
        $value = array();
      }

      $value = json_encode(array_values($value));
      $type = 's';
      break;

    case 'O':
      if ($value !== null) {
        $value = (object)$value;
      }

      $value = json_encode($value);
      $type = 's';
      break;

    case 'J':
      $type = 's';
      break;

    case 'b':
      $value = $value ? 'true' : 'false';
      $type = 's';
      break;

    case 'd':
      if ($value > 0x1FFFFFFFFFFFFF) {
        throw new Exception(
          "You are passing an integer to jsprintf() which is so large it can ".
          "not be represented without loss of precision by Javascript's ".
          "native Number class. Use %# instead.");
      }
      break;
  }

  $pattern[$pos]  = $type;
}
