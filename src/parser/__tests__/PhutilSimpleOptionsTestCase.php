<?php

/**
 * @group testcase
 */
final class PhutilSimpleOptionsTestCase extends PhutilTestCase {

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
      $parser = new PhutilSimpleOptions();
      $this->assertEqual(
        $expect,
        $parser->parse($string),
        "Correct parse of '{$string}'");
    }
  }

  public function testSimpleOptionsCaseParse() {
    $map = array(
      'legs=4, LEGS=8, LeGs' => array(
        'legs' => '4',
        'LEGS' => '8',
        'LeGs' => true,
      ),
    );

    foreach ($map as $string => $expect) {
      $parser = new PhutilSimpleOptions();
      $parser->setCaseSensitive(true);
      $this->assertEqual(
        $expect,
        $parser->parse($string),
        "Correct case-sensitive parse of '{$string}'");
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
      $parser = new PhutilSimpleOptions();
      $this->assertEqual(
        $expect,
        $parser->unparse($dict),
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
        $parser = new PhutilSimpleOptions();
        $parser->unparse($bad_input);
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
