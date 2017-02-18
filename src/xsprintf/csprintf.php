<?php

/**
 * Format a shell command string. This function behaves like `sprintf`, except
 * that all the normal conversions (like "%s") will be properly escaped, and
 * additional conversions are supported:
 *
 *   %Ls
 *     List of strings that will be escaped. They will be space separated.
 *
 *   %LR
 *     List of "readable" strings. They will be space separated.
 *
 *   %P
 *     Password (or other sensitive parameter) to escape. Pass a
 *     @{class:PhutilOpaqueEnvelope}.
 *
 *   %C (Raw Command)
 *     Passes the argument through without escaping. Dangerous!
 *
 *   %R
 *     A more "readable" version of "%s". This will try to print the command
 *     without any escaping if it contains only characters which are safe
 *     in any context. The intent is to produce prettier human-readable
 *     commands.
 *
 * Generally, you should invoke shell commands via @{function:execx} rather
 * than by calling @{function:csprintf} directly.
 *
 * @param  string  sprintf()-style format string.
 * @param  ...     Zero or more arguments.
 * @return PhutilCommandString  Formatted string, escaped appropriately for
 *   shell contexts.
 */
function csprintf($pattern /* , ... */) {
  $args = func_get_args();
  return new PhutilCommandString($args);
}

/**
 * Version of @{function:csprintf} that takes a vector of arguments.
 *
 * @param  string  sprintf()-style format string.
 * @param  list    List of zero or more arguments to csprintf().
 * @return PhutilCommandString  Formatted string, escaped appropriately for
 *   shell contexts.
 */
function vcsprintf($pattern, array $argv) {
  array_unshift($argv, $pattern);
  return call_user_func_array('csprintf', $argv);
}

/**
 * @{function:xsprintf} callback for @{function:csprintf}.
 */
function xsprintf_command($userdata, &$pattern, &$pos, &$value, &$length) {
  $type = $pattern[$pos];
  $next = (strlen($pattern) > $pos + 1) ? $pattern[$pos + 1] : null;

  $is_unmasked = !empty($userdata['unmasked']);

  if (empty($userdata['mode'])) {
    $mode = PhutilCommandString::MODE_DEFAULT;
  } else {
    $mode = $userdata['mode'];
  }

  if ($value instanceof PhutilCommandString) {
    if ($is_unmasked) {
      $value = $value->getUnmaskedString();
    } else {
      $value = $value->getMaskedString();
    }
  }

  switch ($type) {
    case 'L':
      // Remove the L.
      $pattern = substr_replace($pattern, '', $pos, 1);
      $length  = strlen($pattern);
      $type = 's';

      // Check that the value is a non-empty array.
      if (!is_array($value)) {
        throw new InvalidArgumentException(
          pht('Expected an array for %%L%s conversion.', $next));
      }

      switch ($next) {
        case 's':
          $values = array();
          foreach ($value as $val) {
            $values[] = csprintf('%s', $val);
          }
          $value = implode(' ', $values);
          break;

        case 'R':
          $values = array();
          foreach ($value as $val) {
            $values[] = csprintf('%R', $val);
          }
          $value = implode(' ', $values);
          break;

        default:
          throw new XsprintfUnknownConversionException("%L{$next}");
      }
      break;

    case 'R':
      if (!preg_match('(^[a-zA-Z0-9:/@._+-]+$)', $value)) {
        $value = PhutilCommandString::escapeArgument($value, $mode);
      }
      $type = 's';
      break;
    case 's':
      $value = PhutilCommandString::escapeArgument($value, $mode);
      $type = 's';
      break;
    case 'P':
      if (!($value instanceof PhutilOpaqueEnvelope)) {
        throw new InvalidArgumentException(
          pht('Expected %s for %%P conversion.', 'PhutilOpaqueEnvelope'));
      }
      if ($is_unmasked) {
        $value = $value->openEnvelope();
      } else {
        $value = '********';
      }
      $value = PhutilCommandString::escapeArgument($value, $mode);
      $type = 's';
      break;
    case 'C':
      $type = 's';
      break;
  }

  $pattern[$pos] = $type;
}
