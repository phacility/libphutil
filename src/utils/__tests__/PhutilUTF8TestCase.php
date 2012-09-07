<?php

/*
 * Copyright 2012 Facebook, Inc.
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
 * Test cases for functions in utf8.php.
 *
 * @group testcase
 */
final class PhutilUTF8TestCase extends PhutilTestCase {

  public function testUTF8ize_ASCII_ignored() {
    $input = "this\x01 is a \x7f test string";
    $this->assertEqual($input, phutil_utf8ize($input));
  }

  public function testUTF8ize_UTF8_ignored() {
    $input = "\xc3\x9c \xc3\xbc \xe6\x9d\xb1!";
    $this->assertEqual($input, phutil_utf8ize($input));
  }

  public function testUTF8ize_LongString_nosegfault() {
    // For some reason my laptop is segfaulting on long inputs inside
    // preg_match(). Forestall this craziness in the common case, at least.
    phutil_utf8ize(str_repeat('x', 1024 * 1024));
    $this->assertEqual(true, true);
  }

  public function testUTF8ize_invalidUTF8_fixed() {
    $input =
      "\xc3 this has \xe6\x9d some invalid utf8 \xe6";
    $expect =
      "\xEF\xBF\xBD this has \xEF\xBF\xBD\xEF\xBF\xBD some invalid utf8 ".
      "\xEF\xBF\xBD";
    $result = phutil_utf8ize($input);
    $this->assertEqual($expect, $result);
  }

  public function testUTF8ize_owl_isCuteAndFerocious() {
    // This was once a ferocious owl when we used to use "?" as the replacement
    // character instead of U+FFFD, but now he is sort of not as cute or
    // ferocious.
    $input = "M(o\xEE\xFF\xFFo)M";
    $expect = "M(o\xEF\xBF\xBD\xEF\xBF\xBD\xEF\xBF\xBDo)M";
    $result = phutil_utf8ize($input);
    $this->assertEqual($expect, $result);
  }

  public function testUTF8len() {
    $strings = array(
      ''                => 0,
      'x'               => 1,
      "\xEF\xBF\xBD"    => 1,
      "x\xe6\x9d\xb1y"  => 3,
      "xyz"             => 3,
      'quack'           => 5,
    );
    foreach ($strings as $str => $expect) {
      $this->assertEqual($expect, phutil_utf8_strlen($str), 'Length of '.$str);
    }
  }

  public function testUTF8v() {
    $strings = array(
      ''                  => array(),
      'x'                 => array('x'),
      'quack'             => array('q', 'u', 'a', 'c', 'k'),
      "x\xe6\x9d\xb1y"    => array('x', "\xe6\x9d\xb1", 'y'),

      // TODO: This test does not pass. phutil_utf8v() should merge combining
      // characters.
      // "x\xCD\xA0y"        => array("x\xCD\xA0", 'y'),
    );
    foreach ($strings as $str => $expect) {
      $this->assertEqual($expect, phutil_utf8v($str), 'Vector of '.$str);
    }
  }

  public function testUTF8shorten() {
    $inputs = array(
      array("1erp derp derp", 9, "", "1erp derp"),
      array("2erp derp derp", 12, "...", "2erp derp..."),
      array("derpxderpxderp", 12, "...", "derpxderp..."),
      array("derp\xE2\x99\x83derpderp", 12, "...", "derp\xE2\x99\x83derp..."),
      array("", 12, "...", ""),
      array("derp", 12, "...", "derp"),
      array("11111", 5, "2222", "11111"),
      array("111111", 5, "2222", "12222"),

      array("D1rp. Derp derp.", 7, "...", "D1rp."),
      array("D2rp. Derp derp.", 5, "...", "D2rp."),
      array("D3rp. Derp derp.", 4, "...", "D..."),
      array("D4rp. Derp derp.", 14, "...", "D4rp. Derp..."),
      array("D5rpderp, derp derp", 16, "...", "D5rpderp..."),
      array("D6rpderp, derp derp", 17, "...", "D6rpderp, derp..."),

      // This behavior is maybe a little bad, but it seems mostly reasonable,
      // at least for latin languages.
      array("Derp, supercalafragalisticexpialadoshus", 30, "...",
              "Derp..."),

      // If a string has only word-break characters in it, we should just cut
      // it, not produce only the terminal.
      array("((((((((((", 8, '...', '(((((...'),
    );

    foreach ($inputs as $input) {
      list($string, $length, $terminal, $expect) = $input;
      $result = phutil_utf8_shorten($string, $length, $terminal);
      $this->assertEqual($expect, $result, 'Shortening of '.$string);
    }

    try {
      phutil_utf8_shorten('derp', 3, 'quack');
      $caught = false;
    } catch (Exception $ex) {
      $caught = true;
    }

    $this->assertEqual(true, $caught, 'Expect exception for terminal.');
  }

  public function testUTF8Wrap() {
    $inputs = array(
      array(
        'aaaaaaa',
        3,
        array(
          'aaa',
          'aaa',
          'a',
        )),
      array(
        'aa<b>aaaaa',
        3,
        array(
          'aa<b>a',
          'aaa',
          'a',
        )),
      array(
        'aa&amp;aaaa',
        3,
        array(
          'aa&amp;',
          'aaa',
          'a',
        )),
      array(
        "aa\xe6\x9d\xb1aaaa",
        3,
        array(
          "aa\xe6\x9d\xb1",
          'aaa',
          'a',
        )),
      array(
        '',
        80,
        array(
        )),
      array(
        'a',
        80,
        array(
          'a',
        )),
    );

    foreach ($inputs as $input) {
      list($string, $width, $expect) = $input;
      $this->assertEqual(
        $expect,
        phutil_utf8_hard_wrap_html($string, $width),
        "Wrapping of '".$string."'");
    }
  }

  public function testUTF8ConvertParams() {
    $caught = null;
    try {
      phutil_utf8_convert('', 'utf8', '');
    } catch (Exception $ex) {
      $caught = $ex;
    }
    $this->assertEqual(true, (bool)$caught, 'Requires source encoding.');

    $caught = null;
    try {
      phutil_utf8_convert('', '', 'utf8');
    } catch (Exception $ex) {
      $caught = $ex;
    }
    $this->assertEqual(true, (bool)$caught, 'Requires target encoding.');
  }

  public function testUTF8Convert() {
    if (!function_exists('mb_convert_encoding')) {
      $this->assertSkipped("Requires mbstring extension.");
    }

    // "[ae]gis se[n]or [(c)] 1970 [+/-] 1 [degree]"
    $input = "\xE6gis SE\xD1OR \xA9 1970 \xB11\xB0";
    $expect = "\xC3\xA6gis SE\xC3\x91OR \xC2\xA9 1970 \xC2\xB11\xC2\xB0";
    $output = phutil_utf8_convert($input, 'UTF-8', 'ISO-8859-1');

    $this->assertEqual($expect, $output, 'Conversion from ISO-8859-1.');


    $caught = null;
    try {
      phutil_utf8_convert('xyz', 'moon language', 'UTF-8');
    } catch (Exception $ex) {
      $caught = $ex;
    }

    $this->assertEqual(true, (bool)$caught, 'Conversion with bogus encoding.');
  }

}
