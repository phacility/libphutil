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
 * @group testcase
 */
final class PhutilSimpleOptionsTestCase extends ArcanistPhutilTestCase {

  public function testSimpleOptionsParse() {
    $map = array(
      // Base case.
      ''  => array(),

      // Basic parsing.
      'legs=4' => array('legs' => '4'),
      'legs=4,eyes=2' => array('legs' => '4', 'eyes' => '2'),

      // Repeated keys mean last specification wins.
      'legs=4,legs=3' => array('legs' => '3'),

      // Keys with no value should map to true.
      'flag'  => array('flag' => true),
      'legs=4,flag' => array('legs' => '4', 'flag' => true),

      // Spaces should be ignored.
      '  flag  ' => array('flag' => true),
      '  legs =  4   , eyes  = 2' => array('legs' => '4', 'eyes' => '2'),

      // Case should be ignored.
      'LEGS=4' => array('legs' => '4'),
      'legs=4, LEGS=4' => array('legs' => '4'),

      // Empty values should be absent.
      'legs=' => array(),
      'legs=4,legs=,eyes=2' => array('eyes' => '2'),

      // Strings like this should not parse as simpleoptions.
      'SELECT id, name, size FROM table' => array(),
    );

    foreach ($map as $string => $expect) {
      $this->assertEqual(
        $expect,
        PhutilSimpleOptions::parse($string),
        "Correct parse of '{$string}'");
    }
  }

  public function testSimpleOptionsUnparse() {
    $map = array(
      '' => array(),
      'legs=4' => array('legs' => '4'),
      'legs=4, eyes=2' => array('legs' => '4', 'eyes' => '2'),
      'eyes=2, legs=4' => array('eyes' => '2', 'legs' => '4'),
      'legs=4, head' => array('legs' => '4', 'head' => true),
      'eyes=2' => array('legs' => '', 'eyes' => '2'),
    );

    foreach ($map as $expect => $dict) {
      $this->assertEqual(
        $expect,
        PhutilSimpleOptions::unparse($dict),
        "Correct unparse of ".print_r($dict, true));
    }

    $bogus = array(
      array('LEGS' => true),
      array('LEGS' => 4),
      array('!' => '!'),
      array('' => '2'),
    );

    foreach ($bogus as $bad_input) {
      $caught = null;
      try {
        PhutilSimpleOptions::unparse($bad_input);
      } catch (Exception $ex) {
        $caught = $ex;
      }
      $this->assertEqual(
        true,
        $caught instanceof Exception,
        "Correct throw on unparse of bad input.");
    }
  }

}
