<?php

/**
 * Format a shell command string. This function behaves like sprintf(), except
 * that all the normal conversions (like %s) will be properly escaped, and
 * additional conversions are supported:
 *
 *   %Ls
 *     List of strings that will be escaped. They will be space separated.
 *
 *   %C (Raw Command)
 *     Passes the argument through without escaping. Dangerous!
 *
 * Generally, you should invoke shell commands via execx() rather than by
 * calling csprintf() directly.
 *
 * @param  string  sprintf()-style format string.
 * @param  ...     Zero or more arguments.
 * @return string  Formatted string, escaped appropriately for shell contexts.
 * @group exec
 */
function csprintf($pattern/* , ... */) {
  $args = func_get_args();
  return xsprintf('xsprintf_command', null, $args);
}

/**
 * Version of csprintf() that takes a vector of arguments.
 *
 * @param  string  sprintf()-style format string.
 * @param  list    List of zero or more arguments to csprintf().
 * @return string  Formatted string, escaped appropriately for shell contexts.
 * @group exec
 */
function vcsprintf($pattern, array $argv) {
  array_unshift($argv, $pattern);
  return call_user_func_array('csprintf', $argv);
}


/**
 * xsprintf() callback for csprintf().
 * @group exec
 */
function xsprintf_command($userdata, &$pattern, &$pos, &$value, &$length) {
  $type = $pattern[$pos];
  $next = (strlen($pattern) > $pos + 1) ? $pattern[$pos + 1] : null;

  switch ($type) {
    case 'L':
      // Only '%Ls' is supported.
      if ($next !== 's') {
        throw new Exception("Unknown conversion %L{$next}.");
      }

      // Remove the L, leaving %s
      $pattern = substr_replace($pattern, '', $pos, 1);
      $length  = strlen($pattern);
      $type = 's';

      // Check that the value is a non-empty array.
      if (!is_array($value) || !$value) {
        throw new Exception("Expected a non-empty array for %Ls conversion.");
      }

      // Convert the list of strings to a single string.
      $value = implode(' ', array_map('escapeshellarg', $value));
      break;
    case 's':
      $value = escapeshellarg($value);
      $type = 's';
      break;
    case 'C':
      $type = 's';
      break;
  }
  $pattern[$pos] = $type;
}
