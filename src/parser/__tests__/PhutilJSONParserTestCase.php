<?php

final class PhutilJSONParserTestCase extends PhutilTestCase {

  public function testValidJSON() {
    $parser = new PhutilJSONParser();

    $tests = array(
      '{}' => array(),
      '[]' => array(),
      '{"foo": "bar"}' => array('foo' => 'bar'),
      '[1, "foo", true, null]' => array(1, 'foo', true, null),
    );

    foreach ($tests as $input => $expect) {
      $this->assertEqual(
        $expect,
        $parser->parse($input),
        'Parsing JSON: '.$input);
    }
  }

  public function testInvalidJSON() {
    $parser = new PhutilJSONParser();

    $tests = array(
      '',
      'null',
      'false',
      'true',
      '"quack quack I am a duck lol"',
      '{',
      '[',
      '{"foo":',
      '{"foo":"bar",}',
      '{{}',
    );

    foreach ($tests as $input) {
      $caught = null;
      try {
        $parser->parse($input);
      } catch (Exception $ex) {
        $caught = $ex;
      }
      $this->assertTrue($caught instanceof PhutilJSONParserException);
    }
  }

}
