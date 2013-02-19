<?php

/**
 * Test cases for functions in utils.php.
 *
 * @group testcase
 */
final class PhutilUtilsTestCase extends PhutilTestCase {

  public function testMFilterNullMethodThrowException() {
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


  public function testMFilterWithEmptyValueFiltered() {
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


  public function testMFilterWithEmptyValueNegateFiltered() {
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


  public function testIFilterInvalidIndexThrowException() {
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


  public function testIFilterWithEmptyValueFiltered() {
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


  public function testIFilterIndexNotExistsAllFiltered() {
    $list = array(
      'a' => array('h' => 'o', 'i' => 'p', 'j' => 'q',),
      'b' => array('h' => 'o', 'i' => '', 'j' => 'q',),
    );

     $actual = ifilter($list, 'NoneExisting');
     $expected = array();

     $this->assertEqual($expected, $actual);
  }


  public function testIFilterWithEmptyValueNegateFiltered() {
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


  public function testIFilterIndexNotExistsNotFiltered() {
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

  public function testmergevMergingBasicallyWorksCorrectly() {
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

  protected function tryAssertInstancesOfArray($input) {
    assert_instances_of($input, 'array');
  }

  protected function tryAssertInstancesOfStdClass($input) {
    assert_instances_of($input, 'stdClass');
  }

  public function testAssertInstancesOf() {
    $object = new stdClass();
    $inputs = array(
      'empty' => array(),
      'stdClass' => array($object, $object),
      'PhutilUtilsTestCase' => array($object, $this),
      'array' => array(array(), array()),
      'integer' => array($object, 1),
    );

    $this->tryTestCases(
      $inputs,
      array(true, true, false, false, false),
      array($this, 'tryAssertInstancesOfStdClass'),
      'InvalidArgumentException');

    $this->tryTestCases(
      $inputs,
      array(true, false, false, true, false),
      array($this, 'tryAssertInstancesOfArray'),
      'InvalidArgumentException');
  }

  public function testAssertStringLike () {
    $this->assertEqual(
      null,
      assert_stringlike(null));

    $this->assertEqual(
      null,
      assert_stringlike(""));

    $this->assertEqual(
      null,
      assert_stringlike("Hello World"));

    $this->assertEqual(
      null,
      assert_stringlike(1));

    $this->assertEqual(
      null,
      assert_stringlike(9.9999));

    $this->assertEqual(
      null,
      assert_stringlike(true));

    $obj = new Exception('.');
    $this->assertEqual(
      null,
      assert_stringlike($obj));

    $obj = (object)array();

    try {
      assert_stringlike($obj);
    } catch (InvalidArgumentException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(
      true,
      ($caught instanceof InvalidArgumentException));

    $array = array(
             "foo" => "bar",
             "bar" => "foo",
             );

    try {
      assert_stringlike($array);
    } catch (InvalidArgumentException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(
      true,
      ($caught instanceof InvalidArgumentException));

    $tmp = new TempFile();
    $resource = fopen($tmp, 'r');

    try {
      assert_stringlike($resource);
    } catch (InvalidArgumentException $ex) {
      $caught = $ex;
    }

    fclose($resource);

    $this->assertEqual(
      true,
      ($caught instanceof InvalidArgumentException));

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
      head_key(array('a' => 0, 'b' => 1)));
    $this->assertEqual(
      'b',
      last_key(array('a' => 0, 'b' => 1)));
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
      "x\ry\nz\r\n" => array("x\ry\n", "z\r\n"),
      "x\ry\nz\r\n\n" => array("x\ry\n", "z\r\n", "\n"),
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
      "x\ry\nz\r\n" => array("x\ry", "z"),
      "x\ry\nz\r\n\n" => array("x\ry", "z", ""),
    );

    foreach ($discard_cases as $input => $expect) {
      $this->assertEqual(
        $expect,
        phutil_split_lines($input, $retain_endings = false),
        "(Discarded) ".addcslashes($input, "\r\n\\"));
    }

  }

  public function testArrayFuse() {
    $this->assertEqual(array(), array_fuse(array()));
    $this->assertEqual(array('x' => 'x'), array_fuse(array('x')));
  }

  public function testArrayInterleave() {
    $this->assertEqual(array(), array_interleave('x', array()));
    $this->assertEqual(array('y'), array_interleave('x', array('y')));

    $this->assertEqual(
      array('y', 'x', 'z'),
      array_interleave('x', array('y', 'z')));

    $this->assertEqual(
      array('y', 'x', 'z'),
      array_interleave(
        'x',
        array(
          'kangaroo' => 'y',
          'marmoset' => 'z',
        )));

    $obj1 = (object)array();
    $obj2 = (object)array();

    $this->assertEqual(
      array($obj1, $obj2, $obj1, $obj2, $obj1),
      array_interleave(
        $obj2,
        array(
          $obj1,
          $obj1,
          $obj1,
        )));

    $implode_tests = array(
      '' => array(1, 2, 3),
      'x' => array(1, 2, 3),
      'y' => array(),
      'z' => array(1),
    );

    foreach ($implode_tests as $x => $y) {
      $this->assertEqual(
        implode('', array_interleave($x, $y)),
        implode($x, $y));
    }
  }



}
