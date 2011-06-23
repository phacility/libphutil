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
 * Test cases for functions in utf8.php.
 *
 * @group testcase
 */
class PhutilUTF8TestCase extends ArcanistPhutilTestCase {

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
    );
    foreach ($strings as $str => $expect) {
      $this->assertEqual($expect, phutil_utf8v($str), 'Vector of '.$str);
    }
  }

}
