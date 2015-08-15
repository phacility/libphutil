<?php

/**
 * PHP lexer which can handle fragments of source code, e.g. for syntax
 * highlighting of inline snippets. This is largely based on Pygments, but
 * alters some rules to better annotate symbols from source fragments.
 *
 * This lexer is not suitable for parser construction; it always lexes any
 * input stream, even if the input is not PHP.
 */
final class PhutilPHPFragmentLexer extends PhutilLexer {

  protected function getRawRules() {
    $keywords = array(
      'abstract',
      'and',
      'array',
      'as',
      'break',
      'case',
      'catch',
      'callable',
      'class',
      'clone',
      'const',
      'continue',
      'default',
      'declare',
      'do',
      'else',
      'elseif',
      'enddeclare',
      'endfor',
      'endforeach',
      'endif',
      'endswitch',
      'endwhile',
      'extends',
      'final',
      'for',
      'foreach',
      'function',
      'global',
      'goto',
      'if',
      'implements',
      'include',
      'include_once',
      'insteadof',
      'instanceof',
      'interface',
      'list',
      'namespace',
      'new',
      'not',
      'or',
      'parent',
      'private',
      'protected',
      'public',
      'require',
      'require_once',
      'return',
      'self',
      'static',
      'switch',
      'throw',
      'try',
      'use',
      'var',
      'while',
      'xor',
    );

    $constants = array(
      '__CLASS__',
      '__COMPILER_HALT_OFFSET__',
      '__DIR__',
      '__FILE__',
      '__FUNCTION__',
      '__LINE__',
      '__METHOD__',
      '__NAMESPACE__',
      '__TRAIT__',
      'true',
      'false',
      'null',
    );

    $nonsemantic_rules = array(
      array('\\s+', null),
      array('(#|//)', 'c', 'line_comment'),

      // This prevents the doc comment rule from over-consuming when we see
      // an empty coment.
      array('/\\*\\*/', 'cm'),
      array('/\\*\\*.*?\\*/', 'sd'),
      array('/\\*.*?\\*/', 'cm'),

      // Unterminated multi-line comment.
      array('/\\*.*$', 'cm'),
    );

    $identifier_pattern = "[a-zA-Z_\x7f-\xff][a-zA-Z0-9_\x7f-\xff]*";
    $identifier_ns_pattern = "[\\\\a-zA-Z_\x7f-\xff][\\\\a-zA-Z0-9_\x7f-\xff]*";

    return array(
      'start' => array(
        array('<\\?(?i:php)?', 'cp', 'php'),
        array('[^<]+', null),
        array('<', null),
      ),

      'php' => array_merge(array(
        array('\\?>', 'cp', '!pop'),
        array(
          '<<<([\'"]?)('.$identifier_pattern.')\\1\\n.*?\\n\\2\\;?\\n',
          's',
        ),
      ), $nonsemantic_rules, array(
        array('(?i:__halt_compiler)\\b', 'cp', 'halt_compiler'),
        array('(->|::)', 'o', 'attr'),
        array('[~!%^&*+=|:.<>/?@-]+', 'o'),
        array('[\\[\\]{}();,]', 'o'),

        // After 'new', try to match an unadorned symbol.
        array('(?i:new|instanceof)\\b', 'k', 'possible_classname'),
        array('(?i:function)\\b', 'k', 'function_definition'),

        // After 'extends' or 'implements', match a list of classes/interfaces.
        array('(?i:extends|implements)\\b', 'k', 'class_list'),

        array('(?i:catch)\\b', 'k', 'catch'),

        array('(?i:'.implode('|', $keywords).')\\b', 'k'),
        array('(?i:'.implode('|', $constants).')\\b', 'kc'),

        array('\\$+'.$identifier_pattern, 'nv'),

        // Match "f(" as a function and "C::" as a class. These won't work
        // if you put a comment between the symbol and the operator, but
        // that's a bizarre usage.
        array($identifier_ns_pattern.'(?=\s*[\\(])', 'nf'),
        array(
          $identifier_ns_pattern.'(?=\s*::)',
          'nc',
          'context_attr',
          array(
            'context' => 'push',
          ),
        ),

        array($identifier_ns_pattern, 'no'),
        array('(\\d+\\.\\d*|\\d*\\.\\d+)([eE][+-]?[0-9]+)?', 'mf'),
        array('\\d+[eE][+-]?[0-9]+', 'mf'),
        array('0[0-7]+', 'mo'),
        array('0[xX][a-fA-F0-9]+', 'mh'),
        array('0[bB][0-1]+', 'm'),
        array('\d+', 'mi'),
        array("'", 's1', 'string1'),
        array('`', 'sb', 'stringb'),
        array('"', 's2', 'string2'),
        array('.', null),
      )),

      // We've just matched a class name, with a "::" lookahead. The name of
      // the class is on the top of the context stack. We want to try to match
      // the attribute or method (e.g., "X::C" or "X::f()").
      'context_attr' => array_merge($nonsemantic_rules, array(
        array('::', 'o'),
        array(
          $identifier_pattern.'(?=\s*[\\(])',
          'nf',
          '!pop',
          array(
            'context' => 'pop',
          ),
        ),
        array(
          $identifier_pattern,
          'na',
          '!pop',
          array(
            'context' => 'pop',
          ),
        ),
        array(
          '',
          null,
          '!pop',
          array(
            'context' => 'discard',
          ),
        ),
      )),

      // After '->' or '::', a symbol is an attribute name. Note that we end
      // up in 'context_attr' instead of here in some cases.
      'attr' => array_merge($nonsemantic_rules, array(
        array($identifier_pattern, 'na', '!pop'),
        array('', null, '!pop'),
      )),

      // After 'new', a symbol is a class name.
      'possible_classname' => array_merge($nonsemantic_rules, array(
        array($identifier_ns_pattern, 'nc', '!pop'),
        array('', null, '!pop'),
      )),

      'string1' => array(
        array('[^\'\\\\]+', 's1'),
        array("'", 's1', '!pop'),
        array('\\\\.', 'k'),
        array('\\\\$', 'k'),
      ),

      'stringb' => array(
        array('[^`\\\\]+', 'sb'),
        array('`', 'sb', '!pop'),
        array('\\\\.', 'k'),
        array('\\\\$', 'k'),
      ),

      'string2' => array(
        array('[^"\\\\]+', 's2'),
        array('"', 's2', '!pop'),
        array('\\\\.', 'k'),
        array('\\\\$', 'k'),
      ),

      // In a function definition (after "function"), we don't link the name
      // as a "nf" (name.function) since it is its own definition.
      'function_definition' => array_merge($nonsemantic_rules, array(
        array('&', 'o'),
        array('\\(', 'o', '!pop'),
        array($identifier_pattern, 'no', '!pop'),
        array('', null, '!pop'),
      )),

      // For "//" and "#" comments, we need to break out if we see "?" followed
      // by ">".
      'line_comment' => array(
        array('[^?\\n]+', 'c'),
        array('\\n', null, '!pop'),
        array('(?=\\?>)', null, '!pop'),
        array('\\?', 'c'),
      ),

      // We've seen __halt_compiler. Grab the '();' afterward and then eat
      // the rest of the file as raw data.
      'halt_compiler' => array_merge($nonsemantic_rules, array(
        array('[()]', 'o'),

        array(';', 'o', 'compiler_halted'),
        array('\\?>', 'o', 'compiler_halted'),

        // Just halt on anything else.
        array('', null, 'compiler_halted'),
      )),

      // __halt_compiler has taken effect.
      'compiler_halted' => array(
        array('.+', null),
      ),

      'class_list' => array_merge($nonsemantic_rules, array(
        array(',', 'o'),
        array('(?i:implements)', 'k'),
        array($identifier_ns_pattern, 'nc'),
        array('', null, '!pop'),
      )),

      'catch' => array_merge($nonsemantic_rules, array(
        array('\\(', 'o'),
        array($identifier_ns_pattern, 'nc'),
        array('', null, '!pop'),
      )),
    );
  }

}
