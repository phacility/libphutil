<?php

final class PhutilHTMLParserTestCase
  extends PhutilTestCase {

  public function testHTMLParser() {

    $root = dirname(__FILE__).'/data/';
    $tests = Filesystem::listDirectory($root, $include_hidden = false);

    foreach ($tests as $test) {
      $path = $root.$test;
      $data = Filesystem::readFile($path);

      $parts = explode("\n~~~~~~~~~~\n", $data);
      if (count($parts) !== 2) {
        throw new Exception(
          pht(
            'Expected "~~~~~~~~~~" delimiter in test "%s".',
            $test));
      }

      $input = $parts[0];

      $expect = $parts[1];
      $expect = phutil_json_decode($parts[1]);

      $document = id(new PhutilHTMLParser())
        ->parseDocument($input);

      // We're just testing the child list of the root node since this
      // reduces the amount of boilerplate in the test cases.
      $list = array();
      foreach ($document->getChildren() as $child) {
        $list[] = $child->toDictionary();
      }

      $this->assertEqual(
        $expect,
        $list,
        pht('DOM tree for "%s".', $test));
    }
  }

  public function testSelectChildrenWithTags() {
    $input = '<a></a><b></b><a /><c /><a /><x></x><y /><a /><d>x</d><a /><e>';
    $document = id(new PhutilHTMLParser())
      ->parseDocument($input);

    $children = $document->selectChildrenWithTags(array('a'));

    $list = array();
    foreach ($children as $child) {
      $list[] = $child->toDictionary();
    }

    $this->assertEqual(
      array(
        array(
          'tag' => 'a',
          'attributes' => array(),
          'children' => array(),
        ),
        array(
          'content' => '<b></b>',
        ),
        array(
          'tag' => 'a',
          'attributes' => array(),
          'children' => array(),
        ),
        array(
          'content' => '<c />',
        ),
        array(
          'tag' => 'a',
          'attributes' => array(),
          'children' => array(),
        ),
        array(
          'content' => '<x></x><y />',
        ),
        array(
          'tag' => 'a',
          'attributes' => array(),
          'children' => array(),
        ),
        array(
          'content' => '<d>x</d>',
        ),
        array(
          'tag' => 'a',
          'attributes' => array(),
          'children' => array(),
        ),
        array(
          'content' => '<e>',
        ),
      ),
      $list,
      pht('Child selection of: %s.', $input));
  }

}
