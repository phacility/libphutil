<?php

/**
 * Format a regular expression. Supports the following conversions:
 *
 *  %s String
 *    Escapes a string using `preg_quote`.
 *
 *  %R Raw
 *    Inserts a raw regular expression.
 *
 * @param  string  sprintf()-style format string.
 * @param  string  Flags to use with the regular expression.
 * @param  ...     Zero or more arguments.
 * @return string  Formatted string.
 */
function pregsprintf($pattern /* , ... */) {
  $args  = func_get_args();
  $flags = head(array_splice($args, 1, 1));

  $delim    = chr(7);
  $userdata = array('delimiter' => $delim);

  $pattern = xsprintf('xsprintf_regex', $userdata, $args);
  return $delim.$pattern.$delim.$flags;
}

/**
 * @{function:xsprintf} callback for regular expressions.
 */
function xsprintf_regex($userdata, &$pattern, &$pos, &$value, &$length) {
  $delim = idx($userdata, 'delimiter');
  $type  = $pattern[$pos];

  switch ($type) {
    case 's':
      $value = preg_quote($value, $delim);
      break;
    case 'R':
      $type = 's';
      break;
  }

  $pattern[$pos] = $type;
}
