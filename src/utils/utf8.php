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
 * Convert a string into valid UTF-8. This function is quite slow.
 *
 * When invalid byte subsequences are encountered, they will be replaced with
 * U+FFFD, the Unicode replacement character.
 *
 * @param   string  String to convert to valid UTF-8.
 * @return  string  String with invalid UTF-8 byte subsequences replaced with
 *                  U+FFFD.
 * @group utf8
 */
function phutil_utf8ize($string) {
  if (phutil_is_utf8($string)) {
    return $string;
  }

  // There is no function to do this in iconv, mbstring or ICU to do this, so
  // do it (very very slowly) in pure PHP.

  // TODO: Provide an optional fast C implementation ala fb_utf8ize() if this
  // ever shows up in profiles?

  $result = array();

  $regex =
    "/([\x01-\x7F]".
    "|[\xC2-\xDF][\x80-\xBF]".
    "|[\xE0-\xEF][\x80-\xBF][\x80-\xBF]".
    "|[\xF0-\xF4][\x80-\xBF][\x80-\xBF][\x80-\xBF])".
    "|(.)/";

  $offset = 0;
  $matches = null;
  while (preg_match($regex, $string, $matches, 0, $offset)) {
    if (!isset($matches[2])) {
      $result[] = $matches[1];
    } else {
      // Unicode replacement character, U+FFFD.
      $result[] = "\xEF\xBF\xBD";
    }
    $offset += strlen($matches[0]);
  }

  return implode('', $result);
}


/**
 * Determine if a string is valid UTF-8.
 *
 * @param string  Some string which may or may not be valid UTF-8.
 * @return bool    True if the string is valid UTF-8.
 * @group utf8
 */
function phutil_is_utf8($string) {
  if (function_exists('mb_check_encoding')) {
    // If mbstring is available, this is significantly faster than using PHP
    // regexps.
    return mb_check_encoding($string, 'UTF-8');
  }

  $regex =
    "/^(".
      "[\x01-\x7F]+".
    "|([\xC2-\xDF][\x80-\xBF])".
    "|([\xE0-\xEF][\x80-\xBF][\x80-\xBF])".
    "|([\xF0-\xF4][\x80-\xBF][\x80-\xBF][\x80-\xBF]))*\$/";

  return preg_match($regex, $string);
}


/**
 * Find the character length of a UTF-8 string.
 *
 * @param string A valid utf-8 string.
 * @return int   The character length of the string.
 * @group utf8
 */
function phutil_utf8_strlen($string) {
  if (function_exists('mb_strlen')) {
    return mb_strlen($string, 'UTF-8');
  }

  // TODO: This is terrifically slow.
  return count(phutil_utf8v($string));
}


/**
 * Split a UTF-8 string into an array of characters.
 *
 * @param string A valid utf-8 string.
 * @return list  A list of characters in the string.
 * @group utf8
 */
function phutil_utf8v($string) {
  // TODO: Investigate the performance of this. It may also make sense to bundle
  // an optional performance extension with libphutil since even the C library
  // functions can be made ~10x faster.

  if ($string === '') {
    return array();
  }

  // TODO: Can't figure out how to make mb_split() work for this.

  static $have_utf8_support_for_pcre;
  if ($have_utf8_support_for_pcre === null) {
    $have_utf8_support_for_pcre = @preg_match('/./u', 'x');
  }

  if ($have_utf8_support_for_pcre) {
    return preg_split('/(?<!^)(?!$)/u', $string);
  }

  $regex =
    "/([\x01-\x7F]".
    "|[\xC2-\xDF][\x80-\xBF]".
    "|[\xE0-\xEF][\x80-\xBF][\x80-\xBF]".
    "|[\xF0-\xF4][\x80-\xBF][\x80-\xBF][\x80-\xBF])".
    "/";

  $matches = null;
  $ok = preg_match_all($regex, $string, $matches);
  if (!$ok) {
    throw new Exception("Invalid UTF-8 string passed to phutil_utf8v().");
  }

  return $matches[1];
}
