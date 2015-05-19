<?php

final class PhutilSimpleOptionsLexerTestCase extends PhutilTestCase {

  public function testSimpleOptionsLexerTokens() {
    $this->assertEqual(
      array(
        array('word', 'legs', null),
        array('=', '=', null),
        array('word', '4', null),
      ),
      $this->getTokens('legs=4'));

    $this->assertEqual(
      array(
        array('word', 'legs', null),
        array('=', '=', null),
        array('word', '4', null),
        array(',', ',', null),
        array(' ', ' ', null),
        array('word', 'LEGS', null),
        array('=', '=', null),
        array('word', '4', null),
      ),
      $this->getTokens('legs=4, LEGS=4'));
  }

  public function testSimpleOptionsLexerNiceTokens() {
    $this->assertEqual(
      array(
        array('word', 'legs', null),
      ),
      $this->getNiceTokens('  legs  '));

    $this->assertEqual(
      array(
        array('word', 'a', null),
        array('word', ' ', null),
        array('word', 'b', null),
      ),
      $this->getNiceTokens('  a b  '));

    $this->assertEqual(
      array(
        array('word', 'a', null),
        array('word', 'b', null),
      ),
      $this->getNiceTokens('"a""b"'));
  }

  private function getTokens($input) {
    $lexer = new PhutilSimpleOptionsLexer();
    return $lexer->getTokens($input);
  }

  private function getNiceTokens($input) {
    $lexer = new PhutilSimpleOptionsLexer();
    return $lexer->getNiceTokens($input);
  }

}
