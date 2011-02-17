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
 * @group console
 */
class PhutilConsoleFormatter {

  private static $colorCodes = array(
    'black'   => 0,
    'red'     => 1,
    'green'   => 2,
    'yellow'  => 3,
    'blue'    => 4,
    'magenta' => 5,
    'cyan'    => 6,
    'white'   => 7,
    'default' => 9,
  );
  
  private static $disableANSI = false;
  
  public static function disableANSI($disable) {
    self::$disableANSI = $disable;
  }

  public static function formatString($format /* ... */) {
    $colors = implode('|', array_keys(self::$colorCodes));

    if (self::$disableANSI) {
      $format = preg_replace('/\*\*(.*)\*\*/sU',  '\1',   $format);
      $format = preg_replace('/__(.*)__/sU',      '\1',   $format);
      $format = preg_replace('/##(.*)##/sU',      '\1',   $format);
      $format = preg_replace(
        '@<(fg|bg):('.$colors.')>(.*)</\1>@sU',
        '\3',
        $format);
    } else {
      $esc        = chr(27);
      $bold       = $esc.'[1m'.'\\1'.$esc.'[m';
      $underline  = $esc.'[4m'.'\\1'.$esc.'[m';
      $invert     = $esc.'[7m'.'\\1'.$esc.'[m';

      $format = preg_replace('/\*\*(.*)\*\*/sU',  $bold,      $format);
      $format = preg_replace('/__(.*)__/sU',      $underline, $format);
      $format = preg_replace('/##(.*)##/sU',      $invert,    $format);
      $format = preg_replace_callback(
        '@<(fg|bg):('.$colors.')>(.*)</\1>@sU',
        array('PhutilConsoleFormatter', 'replaceColorCode'),
        $format);
    }

    $args = func_get_args();
    $args[0] = $format;

    return call_user_func_array('sprintf', $args);
  }

  public static function replaceColorCode($matches) {
    $codes = self::$colorCodes;
    $offset = 30 + $codes[$matches[2]];
    $default = 39;
    if ($matches[1] == 'bg') {
      $offset += 10;
      $default += 10;
    }

    return chr(27).'['.$offset.'m'.$matches[3].chr(27).'['.$default.'m';
  }

}
