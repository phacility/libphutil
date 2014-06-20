<?php

final class PhutilJSONParserTestCase extends PhutilTestCase {

  public function testValidJSON() {
    $parser = new PhutilJSONParser();

    $tests = array(
      '{}' => array(),
      '[]' => array(),
      '{"foo": "bar"}' => array('foo' => 'bar'),
      '[1, "foo", true, null]' => array(1, 'foo', true, null),
      '{"foo": {"bar": "baz"}}' => array('foo' => array('bar' => 'baz')),
      '{"foo": "bar", "bar": ["baz"]}'
        => array('foo' => 'bar', 'bar' => array('baz')),
      '{"foo": "bar", "bar": {"baz": "foo"}}'
        => array('foo' => 'bar', 'bar' => array('baz' => 'foo')),
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
