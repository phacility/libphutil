<?php

final class PhutilShellLexerTestCase extends PhutilTestCase {

  public function testShellLexer() {
    $dir = dirname(__FILE__).'/shell';
    foreach (Filesystem::listDirectory($dir, $hidden = false) as $file) {
      $data = Filesystem::readFile($dir.'/'.$file);
      $data = rtrim($data, "\n");
      $this->runLexer($file, $data);
    }
  }

  private function runLexer($file, $data) {
    $lexer = new PhutilShellLexer();

    $initial_state = 'start';

    $caught = null;
    $tokens = null;
    try {
      $tokens = $lexer->getTokens($data, $initial_state);
    } catch (Exception $ex) {
      $caught = $ex;
    }

    $argv = null;
    try {
      $argv = $lexer->splitArguments($data);
    } catch (Exception $ex) {
      // Ignore; not diagnostically useful.
    }

    switch ($file) {
      case 'basic.txt':
        $this->assertEqual(null, $caught);
        $this->assertEqual(
          array(
            array('arg', 'arg1', null),
            array(' ', ' ', null),
            array('arg', 'arg2', null),
            array(' ', ' ', null),
            array('arg', 'arg3', null),
          ),
          $tokens,
          $file);
        $this->assertEqual(
          array(
            'arg1',
            'arg2',
            'arg3',
          ),
          $argv,
          $file);
        break;
      case 'escape.txt':
        $this->assertEqual(null, $caught);
        $this->assertEqual(
          array(
            array("'", "'", null),
            array('arg', '\\', null),
            array("'", "'", null),
            array(' ', ' ', null),
            array('"', '"', null),
            array('esc', '\\"', null),
            array('"', '"', null),
          ),
          $tokens,
          $file);
        $this->assertEqual(
          array(
            '\\',
            '"',
          ),
          $argv,
          $file);
        break;
      case 'slashes.txt':
        $this->assertEqual(null, $caught);
        $this->assertEqual(
          array(
            array('arg', 'a', null),
            array('esc', '\\ ', null),
            array('arg', 'b', null),
            array(' ', ' ', null),
            array("'", "'", null),
            array('arg', 'a\\b', null),
            array("'", "'", null),
            array(' ', ' ', null),
            array('"', '"', null),
            array('arg', 'a', null),
            array('arg', '\\b', null),
            array('"', '"', null),
            array(' ', ' ', null),
            array('"', '"', null),
            array('esc', '\\$', null),
            array('esc', '\\`', null),
            array('esc', '\\\\', null),
            array('esc', '\\"', null),
            array('esc', '\\'."\n", null),
            array('arg', 'xyz', null),
            array('"', '"', null),
          ),
          $tokens,
          $file);
        $this->assertEqual(
          array(
            'a b',
            'a\\b',
            'a\\b',
            '$`\\"'."\n".'xyz',
          ),
          $argv,
          $file);
        break;
      case 'spaces.txt':
        $this->assertEqual(
          array(
            array('arg', 'arg1', null),
            array(' ', '   ', null),
            array('arg', 'arg2', null),
            array(' ', '   ', null),
            array('arg', 'arg3', null),
          ),
          $tokens,
          $file);
        $this->assertEqual(
          array(
            'arg1',
            'arg2',
            'arg3',
          ),
          $argv,
          $file);
        break;
      case 'strings.txt':
        $this->assertEqual(null, $caught);
        $this->assertEqual(
          array(
            array('arg', 'a', null),
            array(' ', ' ', null),
            array("'", "'", null),
            array('arg', 'b', null),
            array("'", "'", null),
            array(' ', ' ', null),
            array('"', '"', null),
            array('arg', 'c', null),
            array('"', '"', null),
            array(' ', ' ', null),
            array("'", "'", null),
            array('arg', 'd', null),
            array("'", "'", null),
            array("'", "'", null),
            array('arg', 'e', null),
            array("'", "'", null),
            array(' ', ' ', null),
            array('"', '"', null),
            array('arg', 'f', null),
            array('"', '"', null),
            array('"', '"', null),
            array('arg', 'g', null),
            array('"', '"', null),
            array(' ', ' ', null),
            array('"', '"', null),
            array('arg', 'h', null),
            array('"', '"', null),
            array('"', '"', null),
            array('arg', "'", null),
            array('"', '"', null),
            array('"', '"', null),
            array('arg', 'i', null),
            array('"', '"', null),
          ),
          $tokens,
          $file);
        $this->assertEqual(
          array(
            'a',
            'b',
            'c',
            'de',
            'fg',
            'h\'i',
          ),
          $argv,
          $file);
        break;
      case 'unterminated.txt':
        $this->assertEqual(null, $caught);
        $this->assertEqual(
          array(
            'start',
            'string1',
          ),
          $lexer->getLexerState(),
          $file);
        $this->assertEqual(
          null,
          $argv,
          $file);
        break;
      default:
        throw new Exception(pht("No assertion block for test '%s'!", $file));
    }
  }


}
