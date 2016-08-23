<?php

/**
 * Test cases for @{class:PhutilDocblockParser}.
 */
final class PhutilDocblockParserTestCase extends PhutilTestCase {

  public function testParser() {
    $root = dirname(__FILE__).'/docblock/';
    foreach (Filesystem::listDirectory($root, $hidden = false) as $file) {
      $this->parseDocblock($root.$file);
    }
  }

  private function parseDocblock($doc_file) {
    $contents = Filesystem::readFile($doc_file);
    $file = basename($doc_file);

    $parser = new PhutilDocblockParser();
    list($docblock, $specials) = $parser->parse($contents);

    switch ($file) {
      case 'embedded-specials.docblock':
        $this->assertEqual(array(), $specials);
        $this->assertEqual(
          "So long as a @special does not appear at the beginning of a line,\n".
          "it is parsed as normal text.",
          $docblock);
        break;
      case 'indented-block.docblock':
        $this->assertEqual(array(), $specials);
        $this->assertEqual(
          'Cozy lummox gives smart squid who asks for job pen.',
          $docblock);
        break;
      case 'indented-text.docblock':
        $this->assertEqual(array(), $specials);
        $this->assertEqual(
          'Cozy lummox gives smart squid who asks for job pen.',
          $docblock);
        break;
      case 'multiline-special.docblock':
        $this->assertEqual(
          array(
            'special' => 'x y z',
          ),
          $specials);
        $this->assertEqual(
          '',
          $docblock);
        break;
      case 'multi-specials.docblock':
        $this->assertEqual(
          array(
            'special' => array('north', 'south'),
            'stable' => true,
          ),
          $specials);
        $this->assertEqual(
          '',
          $docblock);
        break;
      case 'specials.docblock':
        $this->assertEqual(
          array(
            'type' => 'type',
            'task' => 'task',
            'special' => array('dot', 'dot', 'dash'),
          ),
          $specials);
        $this->assertEqual(
          '',
          $docblock);
        break;
      case 'linebreak-breaks-specials.docblock':
        $this->assertEqual(
          array(
            'title' => 'title',
          ),
          $specials);
        $this->assertEqual(
          'This is normal text, not part of the @title.',
          $docblock);
        break;
      case 'specials-with-hyphen.docblock':
        $this->assertEqual(
          array(
            'repeat-hyphen'     => array('a', 'b'),
            'multiline-hyphen'  => 'mmm nnn',
            'normal-hyphen'     => 'x',
          ),
          $specials);
        break;
      case 'indented-specials.docblock':
        $this->assertEqual(
          array(
            'title' => 'sendmail',
            'special' => 'only a little bit indented',
          ),
          $specials);
        break;
      case 'flag-specials.docblock':
        $this->assertEqual(
          "stuff above\n\nstuff in the middle\n\nstuff below",
          $docblock);
        $this->assertEqual(
          array(
            'flag' => true,
            'stuff' => true,
            'zebra' => true,
            'apple' => true,
          ),
          $specials);
        break;
      case 'mixed-types.docblock':
        $this->assertEqual(
          array(
            'special' => array('squirrels', true),
          ),
          $specials);
        break;
      default:
        throw new Exception(pht("No test case to handle file '%s'!", $file));
    }
  }

}
