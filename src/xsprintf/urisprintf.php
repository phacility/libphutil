<?php

/**
 * Format a URI. This function behaves like `sprintf`, except that all the
 * normal conversions (like "%s") will be properly escaped, and additional
 * conversions are supported:
 *
 *   %s (String)
 *     Escapes text for use in a URI.
 *
 *   %p (Path Component)
 *     Escapes text for use in a URI path component.
 *
 *   %R (Raw String)
 *     Inserts raw, unescaped text. DANGEROUS!
 */
function urisprintf($pattern /* , ... */) {
  $args = func_get_args();
  return xsprintf('xsprintf_uri', null, $args);
}

function vurisprintf($pattern, array $argv) {
  array_unshift($argv, $pattern);
  return call_user_func_array('urisprintf', $argv);
}

/**
 * @{function:urisprintf} callback for URI encoding.
 */
function xsprintf_uri($userdata, &$pattern, &$pos, &$value, &$length) {
  $type = $pattern[$pos];

  switch ($type) {
    case 's':
      $value = phutil_escape_uri($value);
      $type = 's';
      break;

    case 'p':
      $value = phutil_escape_uri_path_component($value);
      $type = 's';
      break;

    case 'R':
      $type = 's';
      break;
  }

  $pattern[$pos] = $type;
}
