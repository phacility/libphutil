<?php

final class PhutilPHPFragmentLexerTestCase extends PhutilTestCase {

  public function testPHPFragmentLexer() {
    $dir = dirname(__FILE__).'/php';
    foreach (Filesystem::listDirectory($dir, $hidden = false) as $file) {
      $data = Filesystem::readFile($dir.'/'.$file);
      $this->runLexer($file, $data);
    }
  }

  private function runLexer($file, $data) {
    $lexer = new PhutilPHPFragmentLexer();

    $initial_state = 'start';
    switch ($file) {
      case 'pop-from-php.txt':
        $initial_state = 'php';
        break;
      case 'trailing-backslash-1.txt':
      case 'trailing-backslash-2.txt':
      case 'trailing-backslash-b.txt':
        // It's important these test cases not have trailing newlines.
        $data = rtrim($data);
        break;
    }

    $caught = null;
    $tokens = null;
    try {
      $tokens = $lexer->getTokens($data, $initial_state);
    } catch (Exception $ex) {
      $caught = $ex;
    }

    switch ($file) {
      case 'basics.txt':
        $this->assertEqual(null, $caught);
        $this->assertEqual(
          array(
            array('cp', '<?php', null),
            array(null, ' ', null),
            array('nf', 'f', null),
            array('o', '(', null),
            array('o', ')', null),
            array('o', ';', null),
            array(null, "\n", null),
          ),
          $tokens,
          $file);
        break;
      case 'catch.txt':
        $this->assertEqual(null, $caught);
        $this->assertEqual(
          array(
            array('cp', '<?php', null),
            array(null, "\n\n", null),
            array('k', 'try', null),
            array(null, ' ', null),
            array('o', '{', null),
            array('o', '}', null),
            array(null, ' ', null),
            array('k', 'catch', null),
            array(null, ' ', null),
            array('o', '(', null),
            array('nc', 'Z', null),
            array(null, ' ', null),
            array('nv', '$ex', null),
            array('o', ')', null),
            array(null, ' ', null),
            array('o', '{', null),
            array('o', '}', null),
            array(null, "\n", null),
          ),
          $tokens,
          $file);
        break;
      case 'comments.txt':
        $this->assertEqual(null, $caught);
        $tokens = $lexer->mergeTokens($tokens);
        $this->assertEqual(
          array(
            array('cp', '<?php', null),
            array(null, "\n\n", null),
            array('cm', '/**/', null),
            array(null, "\n\n", null),
            array('sd', '/** doc */', null),
            array(null, "\n\n", null),
            array('cm', '/* m */', null),
            array(null, "\n\n", null),
            array('c', '//* m */', null),
            array(null, "\n\n", null),
            array('c', '// a', null),
            array(null, "\n\n", null),
            array('c', '// b', null),
            array(null, "\n\n", null),
            array('c', '// c ', null),
            array('cp', '?>', null),
            array(null, "\n\nd\n", null),
          ),
          $tokens,
          $file);
        break;
      case 'extendsimplements.txt':
        $this->assertEqual(null, $caught);
        $this->assertEqual(
          array(
            array('cp', '<?php', null),
            array(null, "\n\n", null),
            array('k', 'class', null),
            array(null, ' ', null),
            array('no', 'C', null),
            array(null, ' ', null),
            array('k', 'extends', null),
            array(null, ' ', null),
            array('nc', 'A', null),
            array(null, ' ', null),
            array('k', 'implements', null),
            array(null, ' ', null),
            array('nc', 'I', null),
            array('o', ',', null),
            array(null, ' ', null),
            array('nc', 'J', null),
            array(null, ' ', null),
            array('o', '{', null),
            array('o', '}', null),
            array(null, "\n", null),
          ),
          $tokens,
          $file);
        break;
      case 'haltcompiler.txt':
        $this->assertEqual(null, $caught);
        $this->assertEqual(
          array(
            array('cp', '<?php', null),
            array(null, "\n\n", null),
            array('cp', '__halt_compiler', null),
            array('o', '(', null),
            array('o', ')', null),
            array('o', ';', null),
            array(null, "\n\nderp derp derp\n", null),
          ),
          $tokens,
          $file);
        break;
      case 'heredocs.txt':
        $this->assertEqual(null, $caught);
        $this->assertEqual(
          array(
            array('cp', '<?php', null),
            array(null, "\n\n", null),
            array('s', "<<<H\na\nH;\n", null),
            array(null, "\n", null),
            array('s', "<<<H\nb\nH;\n", null),
            array(null, "\n", null),
            array('s', "<<<'H'\nc\nH;\n", null),
            array(null, "\n", null),
            array('s', "<<<\"H\"\nd\nH;\n", null),
          ),
          $tokens,
          $file);
        break;
      case 'symbols.txt':
        $this->assertEqual(null, $caught);
        $this->assertEqual(
          array(
            array('cp', '<?php', null),
            array(null, "\n\n", null),
            array('k', 'public', null),
            array(null, ' ', null),
            array('k', 'function', null),
            array(null, ' ', null),
            array('no', 'f', null),
            array('o', '(', null),
            array('o', ')', null),
            array(null, ' ', null),
            array('o', '{', null),
            array(null, "\n  ", null),
            array('nf', 'g', null),
            array('o', '(', null),
            array('o', ')', null),
            array('o', ';', null),
            array(null, "\n  ", null),
            array('nc', 'H', null),
            array('o', '::', null),
            array('nf', 'i', 'H'),
            array('o', '(', null),
            array('o', ')', null),
            array('o', ';', null),
            array(null, "\n  ", null),
            array('nc', 'J', null),
            array('o', '::', null),
            array('na', 'C', 'J'),
            array('o', ';', null),
            array(null, "\n  ", null),
            array('k', 'new', null),
            array(null, ' ', null),
            array('nc', 'K', null),
            array('o', '(', null),
            array('o', ')', null),
            array('o', ';', null),
            array(null, "\n", null),
            array('o', '}', null),
            array(null, "\n", null),
          ),
          $tokens,
          $file);
        break;
      case 'case-insensitive.txt':
        $this->assertEqual(null, $caught);
        $this->assertEqual(
          array(
            array('cp', '<?php', null),
            array(null, "\n", null),
            array('k', 'CLASS', null),
            array(null, ' ', null),
            array('no', 'C', null),
            array(null, ' ', null),
            array('k', 'EXTENDS', null),
            array(null, ' ', null),
            array('nc', 'stdClass', null),
            array(null, ' ', null),
            array('k', 'IMPLEMENTS', null),
            array(null, ' ', null),
            array('nc', 'I', null),
            array(null, ' ', null),
            array('o', '{', null),
            array(null, "\n  ", null),
            array('k', 'FUNCTION', null),
            array(null, ' ', null),
            array('no', 'f', null),
            array('o', '(', null),
            array('o', ')', null),
            array(null, ' ', null),
            array('o', '{', null),
            array(null, "\n  ", null),
            array('o', '}', null),
            array(null, "\n", null),
            array('o', '}', null),
            array(null, "\n", null),
            array('nv', '$c', null),
            array(null, ' ', null),
            array('o', '=', null),
            array(null, ' ', null),
            array('k', 'NEW', null),
            array(null, ' ', null),
            array('nc', 'C', null),
            array('o', ';', null),
            array(null, "\n", null),
            array('k', 'TRY', null),
            array(null, ' ', null),
            array('o', '{', null),
            array(null, "\n  ", null),
            array('k', 'IF', null),
            array(null, ' ', null),
            array('o', '(', null),
            array('nv', '$c', null),
            array(null, ' ', null),
            array('k', 'instanceOf', null),
            array(null, ' ', null),
            array('nc', 'C', null),
            array('o', ')', null),
            array(null, ' ', null),
            array('o', '{', null),
            array(null, "\n    ", null),
            array('no', 'ECHO', null),
            array(null, ' ', null),
            array('kc', '__line__', null),
            array('o', ';', null),
            array(null, "\n  ", null),
            array('o', '}', null),
            array(null, "\n", null),
            array('o', '}', null),
            array(null, ' ', null),
            array('k', 'CATCH', null),
            array(null, ' ', null),
            array('o', '(', null),
            array('nc', 'Exception', null),
            array(null, ' ', null),
            array('nv', '$ex', null),
            array('o', ')', null),
            array(null, ' ', null),
            array('o', '{', null),
            array(null, "\n", null),
            array('o', '}', null),
            array(null, "\n\n", null),
            array('no', 'echo', null),
            array(null, ' ', null),
            array('s', "<<<EOT\neot;\nEOT;\n", null),
          ),
          $tokens,
          $file);
        break;
      case 'pop-from-php.txt':
        $this->assertEqual(null, $caught);
        $this->assertEqual(
          array(
            array('cp', '?>', null),
            array(null, "\n", null),
          ),
          $tokens,
          $file);
        break;
      case 'trailing-backslash-1.txt':
      case 'trailing-backslash-2.txt':
      case 'trailing-backslash-b.txt':
        $this->assertEqual(null, $caught);
        break;
      default:
        throw new Exception(pht("No assertion block for test '%s'!", $file));
    }
  }


}
