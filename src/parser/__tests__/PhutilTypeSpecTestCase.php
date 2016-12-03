<?php

final class PhutilTypeSpecTestCase extends PhutilTestCase {

  public function testTypeSpecParse() {
    $good = array(
      'int',
      'int|null',
      'string',
      'SomeClass',
      'map<string, string>',
      'int  | null',
      'list  < string   >',
      'int (must be even)',
      'optional int',
      'int?',
      'int|null?',
      'optional int? (minimum 300)',
      'list<wild>',
      'list<list<list<map<string, string>>>> (easy)',
      '\\SomeClass',
      '\\Namespace\\SomeClass',
      '\\NamespaceA\\NamespaceB\\NamespaceC',
      'NamespaceA\\NamespaceB\\NamespaceC',
    );

    $bad = array(
      '<list>',
      'list<>',
      'list<string, string>',
      'map|map',
      'int optional',
      '(derp)',
      'list<string (capital letters), string>',
      'int?|string',
      '\\',
      '\\\\',
      '\\SomeClass\\',
      'SomeClass\\',
    );

    $good = array_fill_keys($good, true);
    $bad = array_fill_keys($bad, false);

    foreach ($good + $bad as $input => $expect) {
      $caught = null;
      try {
        PhutilTypeSpec::newFromString($input);
      } catch (Exception $ex) {
        $caught = $ex;
      }

      $this->assertEqual(
        $expect,
        ($caught === null),
        $input);
    }
  }

  public function testTypeSpecStringify() {
    $types = array(
      'int',
      'list<int>',
      'map<int, int>',
      'list<list<string>>',
      'map<string, map<int, string>>',
      'int|null',
      'int|string|null',
      'list<int|string>',
      'list<SomeObject>',
      'optional int',
      'int (even)',
    );

    foreach ($types as $type) {
      $this->assertEqual(
        $type,
        PhutilTypeSpec::newFromString($type)->toString());
    }
  }

  public function testCanonicalize() {
    $tests = array(
      'int?'        => 'optional int',
      'int  | null' => 'int|null',
      'list  < map <  int , string > >  ?' => 'optional list<map<int, string>>',
      'int   (  x  )' => 'int (  x  )',
    );

    foreach ($tests as $input => $expect) {
      $this->assertEqual(
        $expect,
        PhutilTypeSpec::newFromString($input)->toString(),
        $input);
    }
  }

  public function testGetCommonParentClass() {
    $map = array(
      'stdClass'  => array(
        array('stdClass', 'stdClass'),
      ),
      false       => array(
        array('Exception', 'stdClass'),
      ),
      'Exception' => array(
        array('Exception', 'RuntimeException'),
        array('LogicException', 'RuntimeException'),
        array('BadMethodCallException', 'OutOfBoundsException'),
      ),
    );

    foreach ($map as $expect => $tests) {
      if (is_int($expect)) {
        $expect = (bool)$expect;
      }

      foreach ($tests as $input) {
        list($class_a, $class_b) = $input;

        $this->assertEqual(
          $expect,
          PhutilTypeSpec::getCommonParentClass($class_a, $class_b),
          print_r($input, true));
      }
    }
  }

  public function testGetTypeOf() {
    $map = array(
      'int'                     => 1,
      'string'                  => 'asdf',
      'float'                   => 1.5,
      'bool'                    => true,
      'null'                    => null,
      'map<wild, wild>'         => array(),
      'list<string>'            => array('a', 'b'),
      'list<int>'               => array(1, 2, 3),
      'map<string, int>'        => array('x' => 3),
      'map<int, list<string>>'  => array(1 => array('x', 'y')),
      'stdClass'                => new stdClass(),
      'list<Exception>'         => array(
        new Exception(),
        new LogicException(),
        new RuntimeException(),
      ),
      'map<string, stdClass>'   => array('x' => new stdClass()),
    );

    foreach ($map as $expect => $input) {
      $this->assertEqual(
        $expect,
        PhutilTypeSpec::getTypeOf($input),
        print_r($input, true));

      PhutilTypeSpec::newFromString($expect)->check($input);
    }
  }

  public function testTypeCheckFailures() {
    $map = array(
      'int'                     => 'string',
      'string'                  => 32,
      'null'                    => true,
      'bool'                    => null,
      'map<wild, wild>'         => 16,
      'list<string>'            => array('y' => 'z'),
      'int|null'                => 'ducks',
      'stdClass'                => new Exception(),
      'list<RuntimeException>'  => array(new Exception()),
    );

    foreach ($map as $type => $value) {
      $caught = null;
      try {
        PhutilTypeSpec::newFromString($type)->check($value);
      } catch (PhutilTypeCheckException $ex) {
        $caught = $ex;
      }

      $this->assertTrue($caught instanceof PhutilTypeCheckException);
    }
  }

  public function testCheckMap() {
    $spec = array(
      'count' => 'int',
      'color' => 'optional string',
    );

    // Valid

    PhutilTypeSpec::checkMap(
      array(
        'count' => 1,
      ),
      $spec);

    // Valid, with optional parameter.

    PhutilTypeSpec::checkMap(
      array(
        'count' => 3,
        'color' => 'red',
      ),
      $spec);

    // Parameter "count" is required but missing.

    $caught = null;
    try {
      PhutilTypeSpec::checkMap(
        array(),
        $spec);
    } catch (Exception $ex) {
      $caught = $ex;
    }

    $this->assertTrue($caught instanceof PhutilTypeMissingParametersException);

    // Parameter "size" is specified but does not exist.

    $caught = null;
    try {
      PhutilTypeSpec::checkMap(
        array(
          'count' => 4,
          'size' => 'large',
        ),
        $spec);
    } catch (Exception $ex) {
      $caught = $ex;
    }

    $this->assertTrue($caught instanceof PhutilTypeExtraParametersException);
  }

  public function testRegexValidation() {
    PhutilTypeSpec::checkMap(
      array(
        'regex' => '/.*/',
      ),
      array(
        'regex' => 'regex',
      ));

    $caught = null;
    try {
      PhutilTypeSpec::checkMap(
        array(
          'regex' => '.*',
        ),
        array(
          'regex' => 'regex',
        ));
    } catch (PhutilTypeCheckException $ex) {
      $caught = $ex;
    }

    $this->assertTrue($caught instanceof PhutilTypeCheckException);
  }

  public function testScalarOrListRegexp() {
    PhutilTypeSpec::checkMap(
      array(
        'regex' => '/.*/',
      ),
      array(
        'regex' => 'regex | list<regex>',
      ));

    PhutilTypeSpec::checkMap(
      array(
        'regex' => array('/.*/'),
      ),
      array(
        'regex' => 'regex | list<regex>',
      ));

    PhutilTypeSpec::checkMap(
      array(
        'regex' => '/.*/',
      ),
      array(
        'regex' => 'list<regex> | regex',
      ));

    PhutilTypeSpec::checkMap(
      array(
        'regex' => array('/.*/'),
      ),
      array(
        'regex' => 'list<regex> | regex',
      ));

    $this->assertTrue(true);
  }

  public function testMixedVector() {
    // This is a test case for an issue where we would not infer the type
    // of a vector containing a mixture of scalar and nonscalar elements
    // correctly.

    $caught = null;
    try {
      PhutilTypeSpec::checkMap(
        array(
          'key' => array('!', (object)array()),
        ),
        array(
          'key' => 'list<X>',
        ));
    } catch (PhutilTypeCheckException $ex) {
      $caught = $ex;
    }

    $this->assertTrue($caught instanceof PhutilTypeCheckException);
  }

}
