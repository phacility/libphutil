<?php

/**
 * Format text for terminal output. This function behaves like `sprintf`,
 * except that all the normal conversions (like "%s") will be properly escaped,
 * and additional conversions are supported:
 *
 *   %B (Block)
 *     Escapes text, but preserves tabs and newlines.
 *
 *   %R (Raw String)
 *     Inserts raw, unescaped text. DANGEROUS!
 *
 * Particularly, this will escape terminal control characters.
 */
function tsprintf($pattern /* , ... */) {
  $args = func_get_args();
  $args[0] = PhutilConsoleFormatter::interpretFormat($args[0]);
  $string = xsprintf('xsprintf_terminal', null, $args);
  return new PhutilTerminalString($string);
}

/**
 * Callback for terminal encoding, see @{function:tsprintf} for use.
 */
function xsprintf_terminal($userdata, &$pattern, &$pos, &$value, &$length) {
  $type = $pattern[$pos];

  switch ($type) {
    case 's':
      $value = PhutilTerminalString::escapeStringValue($value, false);
      $type = 's';
      break;
    case 'B':
      $value = PhutilTerminalString::escapeStringValue($value, true);
      $type = 's';
      break;
    case 'R':
      $type = 's';
      break;
  }

  $pattern[$pos] = $type;
}
