<?php

/**
 * Parse a `sprintf()`-style format string in an extensible way.
 *
 * This method allows you to build a function with `sprintf()` semantics but
 * custom conversions for different datatypes. Three examples are
 * @{function:jsprintf} (which builds JavaScript strings),
 * @{function:qsprintf} (which builds MySQL strings), and
 * @{function:csprintf} (which builds command line strings).
 *
 * To build a new `xsprintf`-family function, provide a callback which conforms
 * to the specification described in @{function:xsprintf_callback_example}. The
 * callback will be invoked each time a conversion (like "%Z") is encountered
 * in the string. For instance, if you call `xsprintf()` like this...
 *
 *    $result = xsprintf(
 *      'xsprintf_callback_example',
 *      $userdata = null,
 *      array(
 *        'The %M is made of %C.',
 *        'moon',
 *        'cheese',
 *      ));
 *
 * ...the callback will be invoked twice, at string positions 5 ("M") and 19
 * ("C"), with values "moon" and "cheese" respectively.
 *
 * @param   string  The name of a callback to pass conversions to.
 * @param   wild    Optional userdata to pass to the callback. For
 *                  @{function:qsprintf}, this is the database connection.
 * @param   list    List of arguments, with the `sprintf()` pattern in
 *                  position 0.
 * @return  string  Formatted string.
 */
function xsprintf($callback, $userdata, array $argv) {
  $argc = count($argv);
  $arg = 0;
  $pos = 0;
  $pattern = $argv[0];
  $len = strlen($pattern);

  $conv = false; //  Are we inside a conversion?
  for ($pos = 0; $pos < $len; $pos++) {
    $c = $pattern[$pos];

    if ($conv) {
      // We could make a greater effort to support formatting modifiers,
      // but they really have no place in semantic string formatting.
      if (strpos("'-0123456789.\$+", $c) !== false) {
        throw new InvalidArgumentException(
          pht(
            '%s does not support the "%s" modifier.',
            'xsprintf()',
            "%{$c}"));
      }

      if ($c !== '%') {
        $conv = false;

        $arg++;
        if ($arg >= $argc) {
          throw new BadFunctionCallException(
            pht(
              'Too few arguments to %s.',
              'xsprintf()'));
        }

        if ($callback !== null) {
          $callback($userdata, $pattern, $pos, $argv[$arg], $len);
        }
      }
    }

    if ($c === '%') {
      // If we have "%%", this encodes a literal percentage symbol, so we are
      // no longer inside a conversion.
      $conv = !$conv;
    }
  }

  if ($arg !== ($argc - 1)) {
    throw new BadFunctionCallException(
      pht(
        'Too many arguments to %s.',
        'xsprintf()'));
  }

  $argv[0] = $pattern;
  return call_user_func_array('sprintf', $argv);
}

/**
 * Example @{function:xsprintf} callback. When you call `xsprintf`, you must
 * pass a callback like this one. `xsprintf` will invoke the callback when it
 * encounters a conversion (like "%Z") in the pattern string.
 *
 * Generally, this callback should examine `$pattern[$pos]` (which will contain
 * the conversion character, like 'Z'), escape `$value` appropriately, and then
 * replace `$pattern[$pos]` with an 's' so `sprintf` prints the escaped value
 * as a string. However, more sophisticated behaviors are possible --
 * particularly, consuming multiple characters to allow for conversions like
 * "%Ld". In this case, the callback needs to `substr_replace` the entire
 * conversion with 's' and then update `$length`.
 *
 * For example implementations, see @{function:xsprintf_command},
 * @{function:xsprintf_javascript} and @{function:xsprintf_query}.
 *
 * @param   wild    Arbitrary, optional userdata. This is whatever userdata
 *                  was passed to @{function:xsprintf}.
 * @param   string  The pattern string being parsed.
 * @param   int     The current character position in the string.
 * @param   wild    The value to convert.
 * @param   int     The string length.
 */
function xsprintf_callback_example(
  $userdata,
  &$pattern,
  &$pos,
  &$value,
  &$length) {
  throw new RuntimeException(
    pht(
      'This function exists only to document the call signature '.
      'for %s callbacks.',
      'xsprintf()'));
}
