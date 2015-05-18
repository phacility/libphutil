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
      '{"": ""}' => array('' => ''),
      '{"test":"\u00c9v\u00e9nement"}'
        => array('test' => "\xC3\x89v\xC3\xA9nement"),
      '["\u00c9v\u00e9nement"]' => array("\xC3\x89v\xC3\xA9nement"),
      '{"test":"http:\/\/foo\\\\zomg"}'
        => array('test' => 'http://foo\\zomg'),
      '["http:\/\/foo\\\\zomg"]' => array('http://foo\\zomg'),
      Filesystem::readFile(dirname(__FILE__).'/json/base64.json') => array(
        'action' => 'candidate.create',
        'actionId' => '80653a26cc46357ff79ff83b47e27c3cb7a668bd',
        'params' => array(
          'attachments' => array(
            Filesystem::readFile(dirname(__FILE__).'/json/base64.data'),
          ),
        ),
      ),
    );

    foreach ($tests as $input => $expect) {
      $this->assertEqual(
        $expect,
        $parser->parse($input),
        pht('Parsing JSON: %s', $input));
    }
  }

  public function testInvalidJSON() {
    $parser = new PhutilJSONParser();

    $tests = array(
      '{' => array(
        'line' => 1,
        'char' => 1,
        'token' => 'EOF',
      ),
      '[' => array(
        'line' => 1,
        'char' => 1,
        'token' => 'EOF',
      ),
      '{"foo":' => array(
        'line' => 1,
        'char' => 7,
        'token' => 'EOF',
      ),
      '{"foo":"bar",}' => array(
        'line' => 1,
        'char' => 13,
        'token' => '}',
      ),
      '{{}' => array(
        'line' => 1,
        'char' => 1,
        'token' => '{',
      ),
      '{}}' => array(
        'line' => 1,
        'char' => 2,
        'token' => '}',
      ),
      "{\"foo\":\"bar\",\n\"bar\":\"baz\",}" => array(
        'line' => 2,
        'char' => 12,
        'token' => '}',
      ),
      "{'foo': 'bar'}" => array(
        'line' => 1,
        'char' => 1,
        'token' => 'INVALID',
      ),
      "{\"foo\": \"bar\nbaz\"}" => array(
        'line' => 1,
        'char' => 7,
        'token' => 'INVALID',
      ),
      '{"foo": "bar\z"}' => array(
        'line' => 1,
        'char' => 7,
        'token' => 'INVALID',
      ),
    );

    foreach ($tests as $input => $expected) {
      $caught = null;
      try {
        $parser->parse($input);
      } catch (Exception $ex) {
        $caught = $ex;
      }
      $this->assertTrue($caught instanceof PhutilJSONParserException);
      $this->assertEqual($expected['line'], $caught->getSourceLine());
      $this->assertEqual($expected['char'], $caught->getSourceChar());
      $this->assertEqual($expected['token'], $caught->getSourceToken());
    }
  }

  public function testDuplicateKeys() {
    $parser = new PhutilJSONParser();

    $tests = array(
      '{"foo": "bar", "foo": "baz"}' => array('foo' => 'baz'),
    );

    foreach ($tests as $input => $expect) {
      $parser->setAllowDuplicateKeys(true);
      $this->assertEqual(
        $expect,
        $parser->parse($input),
        pht('Parsing JSON: %s', $input));

      $parser->setAllowDuplicateKeys(false);
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
