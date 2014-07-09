<?php

/**
 * Test cases for @{class:PhutilQueryStringParser} parser.
 */
final class PhutilQueryStringParserTestCase extends PhutilTestCase {

  public function testQueryStringParsing() {
    $map = array(
      '' => array(),
      'foo=bar&foobar=barfoo' => array(
        'foo' => 'bar',
        'foobar' => 'barfoo',
      ),
      'a]b[]=1&a]=2&a[[]=3&a[b]b=4&[][a]=5' => array(
        'a]b[]' => '1',
        'a]' => '2',
        'a[[]' => '3',
        'a[b]b' => '4',
        '[][a]' => '5',
      ),
      'foo[][]=bar&bar[1][3]=foo' => array(
        'foo' => array(
          0 => array(
            0 => 'bar',
          ),
        ),
        'bar' => array(
          1 => array(
            3 => 'foo',
          ),
        ),
      ),
      'foo[][]=bar&a]b[]=1' => array(
        'foo' => array(
          0 => array(
            0 => 'bar',
          ),
        ),
        'a]b[]' => '1',
      ),
      'a&&b' => array(
        'a' => '',
        'b' => '',
      ),
      'a[b][]=foo&a[b][]=bar' => array(
        'a' => array(
          'b' => array(
            0 => 'foo',
            1 => 'bar',
          ),
        ),
      ),
      'a=1&a=2' => array(
        'a' => '2',
      ),
      'a=1&a[]=2' => array(
        'a' => array(
          0 => '2',
        ),
      ),
      'a=1&a[b]=2&a[]=3' => array(
        'a' => array(
          'b' => '2',
          0 => '3',
        ),
      ),
      'a%20b=%20' => array(
        'a b' => ' ',
      ),
      'a.b=c' => array(
        'a.b' => 'c',
      ),
      'a=b=c' => array(
        'a' => 'b=c',
      ),
    );

    $parser = new PhutilQueryStringParser();

    foreach ($map as $query_string => $expected) {
      $this->assertEqual(
        $expected,
        $parser->parseQueryString($query_string));
    }
  }

  public function testQueryStringListParsing() {
    $map = array(
      '' => array(),
      '&' => array(),
      '=' => array(
        array('', ''),
      ),
      '=&' => array(
        array('', ''),
      ),
      'a=b' => array(
        array('a', 'b'),
      ),
      'a[]=b' => array(
        array('a[]', 'b'),
      ),
      'a=' => array(
        array('a', ''),
      ),
      '. [=1' => array(
        array('. [', '1'),
      ),
      'a=b&c=d' => array(
        array('a', 'b'),
        array('c', 'd'),
      ),
      'a=b&a=c' => array(
        array('a', 'b'),
        array('a', 'c'),
      ),
      '&a=b&' => array(
        array('a', 'b'),
      ),
      '=a' => array(
        array('', 'a'),
      ),
      '&&&' => array(
      ),
      'a%20b=c%20d' => array(
        array('a b', 'c d'),
      ),
    );

    $parser = new PhutilQueryStringParser();

    foreach ($map as $query_string => $expected) {
      $this->assertEqual(
        $expected,
        $parser->parseQueryStringToPairList($query_string));
    }
  }

}
