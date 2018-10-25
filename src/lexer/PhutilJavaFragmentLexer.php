<?php

final class PhutilJavaFragmentLexer extends PhutilLexer {

  protected function getRawRules() {
    $keywords = array(
      'assert',
      'break',
      'case',
      'catch',
      'continue',
      'default',
      'do',
      'else',
      'finally',
      'for',
      'if',
      'goto',
      'instanceof',
      'new',
      'return',
      'switch',
      'this',
      'throw',
      'try',
      'while',
    );

    $declarations = array(
      'abstract',
      'const',
      'enum',
      'extends',
      'final',
      'implements',
      'native',
      'private',
      'protected',
      'public',
      'static',
      'strictfp',
      'super',
      'synchronized',
      'throws',
      'transient',
      'volatile',
    );

    $types = array(
      'boolean',
      'byte',
      'char',
      'double',
      'float',
      'int',
      'long',
      'short',
      'void',
    );

    $constants = array(
      'true',
      'false',
      'null',
    );

    $nonsemantic_rules = array(
      array('\s+', null),
      array('//.*?\\n', 'c'),
      array('/\\*.*?\\*/', 'c'),
    );

    return array(
      'start' => array_merge(
        $nonsemantic_rules,
        array(
          array('('.implode('|', $keywords).')\\b', 'k'),
          array('@[^\\W\\d][\\w.]*', 'nd'),
          array('('.implode('|', $declarations).')\\b', 'k'),
          array('('.implode('|', $types).')\\b', 'kt'),
          array('(package|import\\s+static|import)\\b', 'kn', 'import'),
          array('('.implode('|', $constants).')\\b', 'kc'),
          array('(class|interface)\\b', 'kd', 'class'),
          array('"(\\\\.|[^"\\\\]+)*"', 's'),
          array("'(\\\\.|[^\\\\]|\\\\u[0-9a-f-A-F]{4})'", 's'),
          array('([^\\W\\d]|\\$)[\\w$]*:', 'nl'),
          array('([^\\W\\d]|\\$)[\\w$]*', 'n'),
          array(
            '(([0-9][0-9_]*\\.([0-9][0-9_]*)?|'.
            '\\.[0-9][0-9_]*)([eE][+-]?[0-9][0-9_]*)?[fFdD]?|'.
            '[0-9][eE][+-]?[0-9][0-9_]*[fFdD]?|'.
            '[0-9]([eE][+-]?[0-9][0-9_]*)?[fFdD]|'.
            '0[xX]([0-9a-fA-F][0-9a-fA-F_]*\\.?|'.
            '([0-9a-fA-F][0-9a-fA-F_]*)?\\.[0-9a-fA-F][0-9a-fA-F_]*)'.
            '[pP][+-]?[0-9][0-9_]*[fFdD]?)',
            'mf',
          ),
          array('0[xX][0-9a-fA-F][0-9a-fA-F_]*[lL]?', 'mh'),
          array('0[bB][01][01_]*[lL]?', 'mb'),
          array('0[0-7_]+[lL]?', 'mo'),
          array('(0|[1-9][0-9_]*[lL]?)', 'mi'),
          array('([~^*!%&\\[\\](){}<>|+=:;,./?-])', 'o'),
          array('(\S+|\s+)', null),
        )),
      'class' => array_merge(
        $nonsemantic_rules,
        array(
          array('([^\W\d]|\$)[\w$]*', 'nc', '!pop'),
          array('', null, '!pop'),
        )),
      'import' => array_merge(
        $nonsemantic_rules,
        array(
          array('[\w.]+\*?', 'nn', '!pop'),
          array('', null, '!pop'),
        )),
    );
  }

}
