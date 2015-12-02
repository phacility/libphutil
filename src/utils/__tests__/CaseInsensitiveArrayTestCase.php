<?php

final class CaseInsensitiveArrayTestCase extends PhutilTestCase {

  public function testCount() {
    $array = new CaseInsensitiveArray();
    $this->assertEqual(0, count($array));

    $array['key'] = 'foo';
    $this->assertEqual(1, count($array));

    $array['KEY'] = 'bar';
    $this->assertEqual(1, count($array));
  }

  public function testGetKeys() {
    $input = array(
      'key' => true,
      'KEY' => true,
      'kEy' => true,

      'foo' => false,
      'value' => false,
    );
    $expected = array(
      'key',
      'foo',
      'value',
    );

    $array = new CaseInsensitiveArray($input);
    $this->assertEqual($expected, $array->getKeys());
  }

  public function testOffsetExists() {
    $input = array('key' => 'value');
    $expectations = array(
      'key' => true,
      'KEY' => true,
      'kEy' => true,

      'foo' => false,
      'value' => false,
    );

    $array = new CaseInsensitiveArray($input);

    foreach ($expectations as $key => $expectation) {
      if ($expectation) {
        $this->assertTrue(isset($array[$key]));
      } else {
        $this->assertFalse(isset($array[$key]));
      }
    }
  }

  public function testOffsetGet() {
    $input = array('key' => 'value');
    $expectations = array(
      'key' => 'value',
      'KEY' => 'value',
      'kEy' => 'value',

      'foo' => null,
      'value' => null,
    );

    $array = new CaseInsensitiveArray($input);

    foreach ($expectations as $key => $expectation) {
      $this->assertEqual($expectation, @$array[$key]);
    }
  }

  public function testOffsetSet() {
    $input = array();
    $data = array(
      'key' => 'foo',
      'KEY' => 'bar',
      'kEy' => 'baz',
    );
    $expected = array('key' => 'baz');

    $array = new CaseInsensitiveArray($input);

    foreach ($data as $key => $value) {
      $array[$key] = $value;
    }

    $this->assertEqual($expected, $array->toArray());
  }

  public function testOffsetUnset() {
    $input = array('key' => 'value');
    $data = array(
      'KEY',
    );
    $expected = array();

    $array = new CaseInsensitiveArray($input);

    foreach ($data as $key) {
      unset($array[$key]);
    }

    $this->assertEqual($expected, $array->toArray());
  }

}
