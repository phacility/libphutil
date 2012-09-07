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
 * Test cases for functions in utils.php.
 *
 * @group testcase
 */
final class PhutilUtilsTestCase extends PhutilTestCase {

  public function testMFilter_nullMethod_throwException() {
    $caught = null;
    try {
      mfilter(array(), null);
    } catch (InvalidArgumentException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(
      true,
      ($caught instanceof InvalidArgumentException));
  }


  public function testMFilter_withEmptyValue_filtered() {
    $a = new MFilterTestHelper('o', 'p', 'q');
    $b = new MFilterTestHelper('o', '', 'q');
    $c = new MFilterTestHelper('o', 'p', 'q');

    $list = array(
      'a' => $a,
      'b' => $b,
      'c' => $c,
    );

    $actual = mfilter($list, 'getI');
    $expected = array(
     'a' => $a,
     'c' => $c,
    );

    $this->assertEqual($expected, $actual);
  }


  public function testMFilter_withEmptyValueNegate_filtered() {
    $a = new MFilterTestHelper('o', 'p', 'q');
    $b = new MFilterTestHelper('o', '', 'q');
    $c = new MFilterTestHelper('o', 'p', 'q');

    $list = array(
      'a' => $a,
      'b' => $b,
      'c' => $c,
    );

    $actual = mfilter($list, 'getI', true);
    $expected = array(
      'b' => $b,
    );

    $this->assertEqual($expected, $actual);
  }


  public function testIFilter_invalidIndex_throwException() {
    $caught = null;
    try {
      ifilter(array(), null);
    } catch (InvalidArgumentException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(
      true,
      ($caught instanceof InvalidArgumentException));
  }


  public function testIFilter_withEmptyValue_filtered() {
    $list = array(
      'a' => array('h' => 'o', 'i' => 'p', 'j' => 'q',),
      'b' => array('h' => 'o', 'i' => '', 'j' => 'q',),
      'c' => array('h' => 'o', 'i' => 'p', 'j' => 'q',),
      'd' => array('h' => 'o', 'i' => 0, 'j' => 'q',),
      'e' => array('h' => 'o', 'i' => null, 'j' => 'q',),
      'f' => array('h' => 'o', 'i' => false, 'j' => 'q',),
    );

    $actual = ifilter($list, 'i');
    $expected = array(
      'a' => array('h' => 'o', 'i' => 'p', 'j' => 'q',),
      'c' => array('h' => 'o', 'i' => 'p', 'j' => 'q',),
    );

    $this->assertEqual($expected, $actual);
  }


  public function testIFilter_indexNotExists_allFiltered() {
    $list = array(
      'a' => array('h' => 'o', 'i' => 'p', 'j' => 'q',),
      'b' => array('h' => 'o', 'i' => '', 'j' => 'q',),
    );

     $actual = ifilter($list, 'NoneExisting');
     $expected = array();

     $this->assertEqual($expected, $actual);
  }


  public function testIFilter_withEmptyValueNegate_filtered() {
    $list = array(
      'a' => array('h' => 'o', 'i' => 'p', 'j' => 'q',),
      'b' => array('h' => 'o', 'i' => '', 'j' => 'q',),
      'c' => array('h' => 'o', 'i' => 'p', 'j' => 'q',),
      'd' => array('h' => 'o', 'i' => 0, 'j' => 'q',),
      'e' => array('h' => 'o', 'i' => null, 'j' => 'q',),
      'f' => array('h' => 'o', 'i' => false, 'j' => 'q',),
    );

    $actual = ifilter($list, 'i', true);
    $expected = array(
      'b' => array('h' => 'o', 'i' => '', 'j' => 'q',),
      'd' => array('h' => 'o', 'i' => 0, 'j' => 'q',),
      'e' => array('h' => 'o', 'i' => null, 'j' => 'q',),
      'f' => array('h' => 'o', 'i' => false, 'j' => 'q',),
    );

    $this->assertEqual($expected, $actual);
  }


  public function testIFilter_indexNotExists_notFiltered() {
    $list = array(
      'a' => array('h' => 'o', 'i' => 'p', 'j' => 'q',),
      'b' => array('h' => 'o', 'i' => '', 'j' => 'q',),
    );

    $actual = ifilter($list, 'NoneExisting', true);
    $expected = array(
      'a' => array('h' => 'o', 'i' => 'p', 'j' => 'q',),
      'b' => array('h' => 'o', 'i' => '', 'j' => 'q',),
    );

    $this->assertEqual($expected, $actual);
  }

  public function testmergev_merging_basicallyWorksCorrectly() {
    $this->assertEqual(
      array(),
      array_mergev(
        array(
          // <empty>
        )));

    $this->assertEqual(
      array(),
      array_mergev(
        array(
          array(),
          array(),
          array(),
        )));

    $this->assertEqual(
      array(1, 2, 3, 4, 5),
      array_mergev(
        array(
          array(1, 2),
          array(3),
          array(),
          array(4, 5),
        )));
  }

  public function testNonempty() {
    $this->assertEqual(
      'zebra',
      nonempty(false, null, 0, '', array(), 'zebra'));

    $this->assertEqual(
      null,
      nonempty());

    $this->assertEqual(
      false,
      nonempty(null, false));

    $this->assertEqual(
      null,
      nonempty(false, null));
  }

  public function testCoalesce() {
    $this->assertEqual(
      'zebra',
      coalesce(null, 'zebra'));

    $this->assertEqual(
      null,
      coalesce());

    $this->assertEqual(
      false,
      coalesce(false, null));

    $this->assertEqual(
      false,
      coalesce(null, false));
  }

  public function testHeadLast() {
    $this->assertEqual(
      'a',
      head(explode('.', 'a.b')));
    $this->assertEqual(
      'b',
      last(explode('.', 'a.b')));
  }

  public function testHeadKeyLastKey() {
    $this->assertEqual(
      'a',
      head_key(array('a' => 0, 'b' => 1))
      );
    $this->assertEqual(
      'b',
      last_key(array('a' => 0, 'b' => 1))
      );
    $this->assertEqual(NULL, head_key(array()));
    $this->assertEqual(NULL, last_key(array()));
  }

  public function testID() {
    $this->assertEqual(true, id(true));
    $this->assertEqual(false, id(false));
  }

  public function testIdx() {
    $array = array(
      'present' => true,
      'null' => null,
    );
    $this->assertEqual(true, idx($array, 'present'));
    $this->assertEqual(true, idx($array, 'present', false));
    $this->assertEqual(null, idx($array, 'null'));
    $this->assertEqual(null, idx($array, 'null', false));
    $this->assertEqual(null, idx($array, 'missing'));
    $this->assertEqual(false, idx($array, 'missing', false));
  }

  public function testSplitLines() {
    $retain_cases = array(
      "" => array(""),
      "x" => array("x"),
      "x\n" => array("x\n"),
      "\n" => array("\n"),
      "\n\n\n" => array("\n", "\n", "\n"),
      "\r\n" => array("\r\n"),
      "x\r\ny\n" => array("x\r\n", "y\n"),
      "x\ry\nz\r\n" => array("x\r", "y\n", "z\r\n"),
      "x\ry\nz\r\n\n" => array("x\r", "y\n", "z\r\n", "\n"),
    );

    foreach ($retain_cases as $input => $expect) {
      $this->assertEqual(
        $expect,
        phutil_split_lines($input, $retain_endings = true),
        "(Retained) ".addcslashes($input, "\r\n\\"));
    }

    $discard_cases = array(
      "" => array(""),
      "x" => array("x"),
      "x\n" => array("x"),
      "\n" => array(""),
      "\n\n\n" => array("", "", ""),
      "\r\n" => array(""),
      "x\r\ny\n" => array("x", "y"),
      "x\ry\nz\r\n" => array("x", "y", "z"),
      "x\ry\nz\r\n\n" => array("x", "y", "z", ""),
    );

    foreach ($discard_cases as $input => $expect) {
      $this->assertEqual(
        $expect,
        phutil_split_lines($input, $retain_endings = false),
        "(Discarded) ".addcslashes($input, "\r\n\\"));
    }

  }

}
