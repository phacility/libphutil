<?php

/**
 * Format a Javascript string, using JSON to export complex values. This
 * function behaves like `sprintf`, except that all the normal conversions
 * (like "%s") will be properly escaped, and additional conversions are
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
 */
function jsprintf($pattern /* , ... */) {
  $args = func_get_args();
  return xsprintf('xsprintf_javascript', null, $args);
}

function vjsprintf($pattern, array $argv) {
  array_unshift($argv, $pattern);
  return xsprintf('xsprintf_javascript', null, $argv);
}

/**
 * @{function:xsprintf} callback for JavaScript encoding.
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
        throw new RangeException(
          pht(
            "You are passing an integer to %s which is so large it can ".
            "not be represented without loss of precision by Javascript's ".
            "native %s class. Use %%# instead.",
            'jsprintf()',
            'Number'));
      }
      break;
  }

  $pattern[$pos] = $type;
}
