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
 * Parse a printf()-style format string in an extensible way.
 *
 * This method allows you to build a function with printf() semantics but
 * custom conversions for different datatypes. Two examples are jsprintf()
 * (which builds Javascript strings) and qsprintf() (which builds MySQL
 * strings).
 *
 * @group util
 */
function xsprintf($callback, $userdata, $argv) {
  $argc = count($argv);
  $arg  = 0;
  $pos  = 0;
  $pattern = $argv[0];
  $len  = strlen($pattern);

  $conv = false;  //  Are we inside a conversion?
  for ($pos = 0; $pos < $len; $pos++) {
    $c = $pattern[$pos];

    if ($conv) {
      //  We could make a greater effort to support formatting modifiers,
      //  but they really have no place in semantic string formatting.
      if (strpos("'-0123456789.\$+", $c) !== false) {
        throw new Exception(
          "xsprintf() does not support the `%{$c}' modifier.");
      }

      if ($c != '%') {
        $conv = false;

        $arg++;
        if ($arg >= $argc) {
          throw new Exception("Too few arguments to xsprintf().");
        }

        $callback($userdata, $pattern, $pos, $argv[$arg], $len);
      }
    }

    if ($c == '%') {
      //  If we have "%%", this encodes a literal percentage symbol, so we are
      //  no longer inside a conversion.
      $conv = !$conv;
    }
  }

  if ($arg != ($argc - 1)) {
    throw new Exception("Too many arguments to xsprintf().");
  }

  $argv[0] = $pattern;

  return call_user_func_array('sprintf', $argv);
}
