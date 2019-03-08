<?php

/**
 * Test cases for functions in utils.php.
 */
final class PhutilUtilsTestCase extends PhutilTestCase {

  public function testMFilterNullMethodThrowException() {
    $caught = null;
    try {
      mfilter(array(), null);
    } catch (InvalidArgumentException $ex) {
      $caught = $ex;
    }

    $this->assertTrue($caught instanceof InvalidArgumentException);
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

    $this->assertTrue($caught instanceof InvalidArgumentException);
  }

  public function testIFilterWithEmptyValueFiltered() {
    $list = array(
      'a' => array('h' => 'o', 'i' => 'p', 'j' => 'q'),
      'b' => array('h' => 'o', 'i' => '', 'j' => 'q'),
      'c' => array('h' => 'o', 'i' => 'p', 'j' => 'q'),
      'd' => array('h' => 'o', 'i' => 0, 'j' => 'q'),
      'e' => array('h' => 'o', 'i' => null, 'j' => 'q'),
      'f' => array('h' => 'o', 'i' => false, 'j' => 'q'),
    );

    $actual = ifilter($list, 'i');
    $expected = array(
      'a' => array('h' => 'o', 'i' => 'p', 'j' => 'q'),
      'c' => array('h' => 'o', 'i' => 'p', 'j' => 'q'),
    );

    $this->assertEqual($expected, $actual);
  }

  public function testIFilterIndexNotExistsAllFiltered() {
    $list = array(
      'a' => array('h' => 'o', 'i' => 'p', 'j' => 'q'),
      'b' => array('h' => 'o', 'i' => '', 'j' => 'q'),
    );

     $actual = ifilter($list, 'NoneExisting');
     $expected = array();

     $this->assertEqual($expected, $actual);
  }


  public function testIFilterWithEmptyValueNegateFiltered() {
    $list = array(
      'a' => array('h' => 'o', 'i' => 'p', 'j' => 'q'),
      'b' => array('h' => 'o', 'i' => '', 'j' => 'q'),
      'c' => array('h' => 'o', 'i' => 'p', 'j' => 'q'),
      'd' => array('h' => 'o', 'i' => 0, 'j' => 'q'),
      'e' => array('h' => 'o', 'i' => null, 'j' => 'q'),
      'f' => array('h' => 'o', 'i' => false, 'j' => 'q'),
    );

    $actual = ifilter($list, 'i', true);
    $expected = array(
      'b' => array('h' => 'o', 'i' => '', 'j' => 'q'),
      'd' => array('h' => 'o', 'i' => 0, 'j' => 'q'),
      'e' => array('h' => 'o', 'i' => null, 'j' => 'q'),
      'f' => array('h' => 'o', 'i' => false, 'j' => 'q'),
    );

    $this->assertEqual($expected, $actual);
  }

  public function testIFilterIndexNotExistsNotFiltered() {
    $list = array(
      'a' => array('h' => 'o', 'i' => 'p', 'j' => 'q'),
      'b' => array('h' => 'o', 'i' => '', 'j' => 'q'),
    );

    $actual = ifilter($list, 'NoneExisting', true);
    $expected = array(
      'a' => array('h' => 'o', 'i' => 'p', 'j' => 'q'),
      'b' => array('h' => 'o', 'i' => '', 'j' => 'q'),
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

    $not_valid = array(
      'scalar' => array(1),
      'array plus scalar' => array(array(), 1),
      'null' => array(null),
    );

    foreach ($not_valid as $key => $invalid_input) {
      $caught = null;
      try {
        array_mergev($invalid_input);
      } catch (InvalidArgumentException $ex) {
        $caught = $ex;
      }

      $this->assertTrue(
        ($caught instanceof InvalidArgumentException),
        pht('%s invalid on %s', 'array_mergev()', $key));
    }
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
      __CLASS__ => array($object, $this),
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

  public function testAssertStringLike() {
    $this->assertEqual(
      null,
      assert_stringlike(null));

    $this->assertEqual(
      null,
      assert_stringlike(''));

    $this->assertEqual(
      null,
      assert_stringlike('Hello World'));

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

    $this->assertTrue($caught instanceof InvalidArgumentException);

    $array = array(
      'foo' => 'bar',
      'bar' => 'foo',
    );

    try {
      assert_stringlike($array);
    } catch (InvalidArgumentException $ex) {
      $caught = $ex;
    }

    $this->assertTrue($caught instanceof InvalidArgumentException);

    $tmp = new TempFile();
    $resource = fopen($tmp, 'r');

    try {
      assert_stringlike($resource);
    } catch (InvalidArgumentException $ex) {
      $caught = $ex;
    }

    fclose($resource);

    $this->assertTrue($caught instanceof InvalidArgumentException);
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
    $this->assertEqual(null, head_key(array()));
    $this->assertEqual(null, last_key(array()));
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
      '' => array(''),
      'x' => array('x'),
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
        pht('(Retained) %s', addcslashes($input, "\r\n\\")));
    }

    $discard_cases = array(
      '' => array(''),
      'x' => array('x'),
      "x\n" => array('x'),
      "\n" => array(''),
      "\n\n\n" => array('', '', ''),
      "\r\n" => array(''),
      "x\r\ny\n" => array('x', 'y'),
      "x\ry\nz\r\n" => array("x\ry", 'z'),
      "x\ry\nz\r\n\n" => array("x\ry", 'z', ''),
    );

    foreach ($discard_cases as $input => $expect) {
      $this->assertEqual(
        $expect,
        phutil_split_lines($input, $retain_endings = false),
        pht('(Discarded) %s', addcslashes($input, "\r\n\\")));
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

  public function testLoggableString() {
    $this->assertEqual(
      '',
      phutil_loggable_string(''));

    $this->assertEqual(
      "a\\nb",
      phutil_loggable_string("a\nb"));

    $this->assertEqual(
      "a\\x01b",
      phutil_loggable_string("a\x01b"));

    $this->assertEqual(
      "a\\x1Fb",
      phutil_loggable_string("a\x1Fb"));
  }

  public function testPhutilUnits() {
    $cases = array(
      '0 seconds in seconds' => 0,
      '1 second in seconds' => 1,
      '2 seconds in seconds' => 2,
      '100 seconds in seconds' => 100,
      '2 minutes in seconds' => 120,
      '1 hour in seconds' => 3600,
      '1 day in seconds' => 86400,
      '3 days in seconds' => 259200,
      '128 bits in bytes' => 16,
      '1 byte in bytes' => 1,
      '8 bits in bytes' => 1,
      '1 minute in milliseconds' => 60000,
      '2 minutes in microseconds' => 120000000,
    );

    foreach ($cases as $input => $expect) {
      $this->assertEqual(
        $expect,
        phutil_units($input),
        'phutil_units("'.$input.'")');
    }

    $bad_cases = array(
      'quack',
      '3 years in seconds',
      '1 day in days',
      '-1 minutes in seconds',
      '1.5 minutes in seconds',
      '7 bits in bytes',
      '2 hours in bytes',
      '1 dram in bytes',
      '24 bits in seconds',
    );

    foreach ($bad_cases as $input) {
      $caught = null;
      try {
        phutil_units($input);
      } catch (InvalidArgumentException $ex) {
        $caught = $ex;
      }

      $this->assertTrue(
        ($caught instanceof InvalidArgumentException),
        'phutil_units("'.$input.'")');
    }
  }

  public function testPhutilJSONDecode() {
    $valid_cases = array(
      '{}' => array(),
      '[]' => array(),
      '[1, 2]' => array(1, 2),
      '{"a":"b"}' => array('a' => 'b'),
    );

    foreach ($valid_cases as $input => $expect) {
      $result = phutil_json_decode($input);
      $this->assertEqual($expect, $result, 'phutil_json_decode('.$input.')');
    }

    $invalid_cases = array(
      '',
      '"a"',
      '{,}',
      'null',
      '"null"',
    );

    foreach ($invalid_cases as $input) {
      $caught = null;
      try {
        phutil_json_decode($input);
      } catch (Exception $ex) {
        $caught = $ex;
      }
      $this->assertTrue($caught instanceof PhutilJSONParserException);
    }
  }

  public function testPhutilINIDecode() {
    // Skip the test if we are using an older version of PHP that doesn't
    // have the `parse_ini_string` function.
    try {
      phutil_ini_decode('');
    } catch (PhutilMethodNotImplementedException $ex) {
      $this->assertSkipped($ex->getMessage());
    }

    $valid_cases = array(
      '' => array(),
      'foo=' => array('foo' => ''),
      'foo=bar' => array('foo' => 'bar'),
      'foo = bar' => array('foo' => 'bar'),
      "foo = bar\n" => array('foo' => 'bar'),
      "foo\nbar = baz" => array('bar' => 'baz'),

      "[foo]\nbar = baz" => array('foo' => array('bar' => 'baz')),
      "[foo]\n[bar]\nbaz = foo" => array(
        'foo' => array(),
        'bar' => array('baz' => 'foo'),
      ),
      "[foo]\nbar = baz\n\n[bar]\nbaz = foo" => array(
        'foo' => array('bar' => 'baz'),
        'bar' => array('baz' => 'foo'),
      ),

      "; Comment\n[foo]\nbar = baz" => array('foo' => array('bar' => 'baz')),
      "# Comment\n[foo]\nbar = baz" => array('foo' => array('bar' => 'baz')),

      "foo = true\n[bar]\nbaz = false"
        => array('foo' => true, 'bar' => array('baz' => false)),
      "foo = 1\nbar = 1.234" => array('foo' => 1, 'bar' => 1.234),
      'x = {"foo": "bar"}' => array('x' => '{"foo": "bar"}'),
    );

    foreach ($valid_cases as $input => $expect) {
      $result = phutil_ini_decode($input);
      $this->assertEqual($expect, $result, 'phutil_ini_decode('.$input.')');
    }

    $invalid_cases = array(
      '[' => new PhutilINIParserException(),
    );

    foreach ($invalid_cases as $input => $expect) {
      $caught = null;
      try {
        phutil_ini_decode($input);
      } catch (Exception $ex) {
        $caught = $ex;
      }
      $this->assertTrue($caught instanceof $expect);
    }
  }

  public function testCensorCredentials() {
    $cases = array(
      '' => '',
      'abc' => 'abc',

      // NOTE: We're liberal about censoring here, since we can't tell
      // if this is a truncated password at the end of an input string
      // or a domain name. The version with a "/" isn't censored.
      'http://example.com' => 'http://********',
      'http://example.com/' => 'http://example.com/',

      'http://username@example.com' => 'http://********@example.com',
      'http://user:pass@example.com' => 'http://********@example.com',

      // We censor these because they might be truncated credentials at the end
      // of the string.
      'http://user' => 'http://********',
      "http://user\n" => "http://********\n",

      'svn+ssh://user:pass@example.com' => 'svn+ssh://********@example.com',
    );

    foreach ($cases as $input => $expect) {
      $this->assertEqual(
        $expect,
        phutil_censor_credentials($input),
        pht('Credential censoring for: %s', $input));
    }
  }

  public function testVarExport() {
    // Constants
    $this->assertEqual('null', phutil_var_export(null));
    $this->assertEqual('true', phutil_var_export(true));
    $this->assertEqual('false', phutil_var_export(false));
    $this->assertEqual("'quack'", phutil_var_export('quack'));
    $this->assertEqual('1234567', phutil_var_export(1234567));

    // Arrays
    $this->assertEqual(
      'array()',
      phutil_var_export(array()));
    $this->assertEqual(
      implode("\n", array(
        'array(',
        '  1,',
        '  2,',
        '  3,',
        ')',
      )),
      phutil_var_export(array(1, 2, 3)));
    $this->assertEqual(
      implode("\n", array(
        'array(',
        "  'foo' => 'bar',",
        "  'bar' => 'baz',",
        ')',
      )),
      phutil_var_export(array('foo' => 'bar', 'bar' => 'baz')));
    $this->assertEqual(
      implode("\n", array(
        'array(',
        "  'foo' => array(",
        "    'bar' => array(",
        "      'baz' => array(),",
        '    ),',
        '  ),',
        ')',
      )),
      phutil_var_export(
        array('foo' => array('bar' => array('baz' => array())))));

    // NOTE: Object behavior differs across PHP versions. Older versions of
    // PHP export objects as "stdClass::__set_state(array())". Newer versions
    // of PHP (7.3+) export objects as "(object) array()".
  }

  public function testFnmatch() {
    $cases = array(
      '' => array(
        array(''),
        array('.', '/'),
      ),
      '*' => array(
        array('file'),
        array('dir/', '/dir'),
      ),
      '**' => array(
        array('file', 'dir/', '/dir', 'dir/subdir/file'),
        array(),
      ),
      '**/file' => array(
        array('file', 'dir/file', 'dir/subdir/file', 'dir/subdir/subdir/file'),
        array('file/', 'file/dir'),
      ),
      'file.*' => array(
        array('file.php', 'file.a', 'file.'),
        array('files.php', 'file.php/blah'),
      ),
      'fo?' => array(
        array('foo', 'fot'),
        array('fooo', 'ffoo', 'fo/', 'foo/'),
      ),
      'fo{o,t}' => array(
        array('foo', 'fot'),
        array('fob', 'fo/', 'foo/'),
      ),
      'fo{o,\\,}' => array(
        array('foo', 'fo,'),
        array('foo/', 'fo,/'),
      ),
      'fo{o,\\\\}' => array(
        array('foo', 'fo\\'),
        array('foo/', 'fo\\/'),
      ),
      '/foo' => array(
        array('/foo'),
        array('foo', '/foo/'),
      ),

      // Tests for various `fnmatch` flags.
      '*.txt' => array(
        array(
          'file.txt',

          // FNM_PERIOD
          '.secret-file.txt',
        ),
        array(
          // FNM_PATHNAME
          'dir/file.txt',

          // FNM_CASEFOLD
          'file.TXT',
        ),
        '\\*.txt' => array(
          array(
            // FNM_NOESCAPE
            '*.txt',
          ),
          array(
            'file.txt',
          ),
        ),
      ),
    );

    $invalid = array(
      '{',
      'asdf\\',
    );

    foreach ($cases as $input => $expect) {
      list($matches, $no_matches) = $expect;

      foreach ($matches as $match) {
        $this->assertTrue(
          phutil_fnmatch($input, $match),
          pht('Expecting "%s" to match "%s".', $input, $match));
      }

      foreach ($no_matches as $no_match) {
        $this->assertFalse(
          phutil_fnmatch($input, $no_match),
          pht('Expecting "%s" not to match "%s".', $input, $no_match));
      }
    }

    foreach ($invalid as $input) {
      $caught = null;
      try {
        phutil_fnmatch($input, '');
      } catch (Exception $ex) {
        $caught = $ex;
      }

      $this->assertTrue($caught instanceof InvalidArgumentException);
    }
  }

  public function testJSONEncode() {
    $in = array(
      'example' => "Not Valid UTF8: \x80",
    );

    $caught = null;
    try {
      $value = phutil_json_encode($in);
    } catch (Exception $ex) {
      $caught = $ex;
    }

    $this->assertTrue(($caught instanceof Exception));
  }

  public function testHashComparisons() {
    $tests = array(
      array('1', '12', false),
      array('0', '0e123', false),
      array('0e123', '0e124', false),
      array('', '0', false),
      array('000', '0e0', false),
      array('001', '002', false),
      array('0', '', false),
      array('987654321', '123456789', false),
      array('A', 'a', false),
      array('123456789', '123456789', true),
      array('hunter42', 'hunter42', true),
    );

    foreach ($tests as $key => $test) {
      list($u, $v, $expect) = $test;
      $actual = phutil_hashes_are_identical($u, $v);
      $this->assertEqual(
        $expect,
        $actual,
        pht('Test Case: "%s" vs "%s"', $u, $v));
    }
  }

  public function testVectorSortInt() {
    $original = array(
      ~PHP_INT_MAX,
      -2147483648,
      -5,
      -3,
      -1,
      0,
      1,
      2,
      3,
      100,
      PHP_INT_MAX,
    );

    $items = $this->shuffleMap($original);

    foreach ($items as $key => $value) {
      $items[$key] = (string)id(new PhutilSortVector())
        ->addInt($value);
    }

    asort($items, SORT_STRING);

    $this->assertEqual(
      array_keys($original),
      array_keys($items));
  }

  public function testVectorSortString() {
    $original = array(
      '',
      "\1",
      'A',
      'AB',
      'Z',
      "Z\1",
      'ZZZ',
    );

    $items = $this->shuffleMap($original);

    foreach ($items as $key => $value) {
      $items[$key] = (string)id(new PhutilSortVector())
        ->addString($value);
    }

    asort($items, SORT_STRING);

    $this->assertEqual(
      array_keys($original),
      array_keys($items));
  }

  private function shuffleMap(array $map) {
    $keys = array_keys($map);
    shuffle($keys);
    return array_select_keys($map, $keys);
  }

  public function testQueryStringEncoding() {
    $expect = array();

    // As a starting point, we expect every character to encode as an "%XX"
    // escaped version.
    foreach (range(0, 255) as $byte) {
      $c = chr($byte);
      $expect[$c] = sprintf('%%%02X', $byte);
    }

    // We expect these characters to not be escaped.
    $ranges = array(
      range('a', 'z'),
      range('A', 'Z'),
      range('0', '9'),
      array('-', '.', '_', '~'),
    );

    foreach ($ranges as $range) {
      foreach ($range as $preserve_char) {
        $expect[$preserve_char] = $preserve_char;
      }
    }

    foreach (range(0, 255) as $byte) {
      $c = chr($byte);

      $expect_c = $expect[$c];
      $expect_str = "{$expect_c}={$expect_c}";

      $actual_str = phutil_build_http_querystring(array($c => $c));

      $this->assertEqual(
        $expect_str,
        $actual_str,
        pht('HTTP querystring for byte "%s".', sprintf('0x%02x', $byte)));
    }
  }

  public function testNaturalList() {
    $cases = array(
      array(true, array()),
      array(true, array(0 => true, 1 => true, 2 => true)),
      array(true, array('a', 'b', 'c')),
      array(false, array(0 => true, 2 => true, 1 => true)),
      array(false, array(1 => true)),
      array(false, array('sound' => 'quack')),
    );

    foreach ($cases as $case) {
      list($expect, $value) = $case;
      $this->assertEqual($expect, phutil_is_natural_list($value));
    }
  }


}
