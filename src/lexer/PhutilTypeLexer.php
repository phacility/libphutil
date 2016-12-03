<?php

/**
 * Lexer for a simple type grammar. See @{class:PhutilTypeSpec} for a
 * description.
 */
final class PhutilTypeLexer extends PhutilLexer {

  protected function getRawRules() {
    return array(
      'start' => array(
        array('\s+', ' '),
        array('\\|', '|'),
        array('<', '<'),
        array('>', '>'),
        array(',', ','),
        array('\\?', '?'),
        array('optional', 'opt'),
        array('map', 'map'),
        array('list', 'list'),
        array('int|float|bool|string|null|callable|wild|regex', 'k'),
        array('\\\\?[a-zA-Z_\x7f-\xff]+(\\\\[a-zA-Z_\x7f-\xff]+)*', 'k'),
        array('\\(', '(', 'comment'),
      ),
      'comment' => array(
        array('\\)', ')', '!pop'),
        array('[^\\)]+', 'cm'),
      ),
    );
  }

}
