<?php

final class PhutilEditorConfigTestCase extends PhutilTestCase {

  public function testGetProperty() {
    $parser = new PhutilEditorConfig($this->getTestFile());

    $tests = array(
      'default' => array(
        array(
          'indent_style' => 'space',
          'indent_size' => 2,
          'charset' => 'utf-8',
          'trim_trailing_whitespace' => true,
          'insert_final_newline' => true,
        ),
        array(),
      ),
      'file' => array(
        array(
          'indent_style' => 'space',
          'indent_size' => 3,
          'charset' => 'utf-8',
          'trim_trailing_whitespace' => true,
          'insert_final_newline' => true,
        ),
        array(),
      ),
      'file.txt' => array(
        array(
          'indent_style' => 'space',
          'indent_size' => 3,
          'charset' => 'latin1',
          'trim_trailing_whitespace' => true,
          'insert_final_newline' => true,
        ),
        array(),
      ),
      'externals/README' => array(
        array(
          'indent_style' => null,
          'indent_size' => null,
          'charset' => 'utf-8',
          'trim_trailing_whitespace' => false,
          'insert_final_newline' => false,
        ),
        array(),
      ),
      'subdir/file' => array(
        array(
          'indent_style' => 'tab',
          'indent_size' => 3,
          'charset' => 'utf-8-bom',
          'trim_trailing_whitespace' => true,
          'insert_final_newline' => true,
        ),
        array(),
      ),
      'empty/file' => array(
        array(),
        array(
          'indent_style' => null,
          'indent_size' => null,
          'charset' => null,
          'trim_trailing_whitespace' => null,
          'insert_final_newline' => null,
        ),
      ),
    );

    foreach ($tests as $path => $expected) {
      list($properties, $property) = $expected;
      $property = array_merge($properties, $property);

      $this->assertEqual(
        $properties,
        $parser->getProperties($this->getTestFile($path)));

      foreach ($property as $key => $value) {
        $this->assertEqual(
          $value,
          $parser->getProperty($this->getTestFile($path), $key));
      }
    }

    $invalid_properties = array(
      'invalid',
    );

    foreach ($invalid_properties as $invalid_property) {
      $caught = null;
      try {
        $parser->getProperty('', $invalid_property);
      } catch (Exception $ex) {
        $caught = $ex;
      }

      $this->assertTrue($caught instanceof InvalidArgumentException);
    }
  }

  private function getTestFile($path = null) {
    return dirname(__FILE__).'/editorconfig/'.$path;
  }

}
