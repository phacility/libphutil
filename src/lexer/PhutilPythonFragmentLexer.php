<?php

/**
 * Python lexer which can handle fragments of source code, e.g. for syntax
 * highlighting of inline snippets. This is largely based on Pygments:
 *
 * https://bitbucket.org/birkenfeld/pygments-main/src/default/pygments/lexers/agile.py
 *
 * This lexer is not suitable for parser construction; it always lexes any
 * input stream, even if the input is not Python.
 */
final class PhutilPythonFragmentLexer extends PhutilLexer {

  protected function getRawRules() {
    $keywords = array(
      'as',
      'assert',
      'break',
      'continue',
      'del',
      'elif',
      'else',
      'except',
      'exec',
      'finally',
      'for',
      'global',
      'if',
      'lambda',
      'pass',
      'print',
      'raise',
      'return',
      'try',
      'while',
      'with',
      'yield(\s+from)?',
    );

    $builtins = array(
      '__import__',
      'abs',
      'all',
      'any',
      'apply',
      'basestring',
      'bin',
      'bool',
      'buffer',
      'bytearray',
      'bytes',
      'callable',
      'chr',
      'classmethod',
      'cmp',
      'coerce',
      'compile',
      'complex',
      'delattr',
      'dict',
      'dir',
      'divmod',
      'enumerate',
      'eval',
      'execfile',
      'exit',
      'file',
      'filter',
      'float',
      'frozenset',
      'getattr',
      'globals',
      'hasattr',
      'hash',
      'hex',
      'id',
      'input',
      'int',
      'intern',
      'isinstance',
      'issubclass',
      'iter',
      'len',
      'list',
      'locals',
      'long',
      'map',
      'max',
      'min',
      'next',
      'object',
      'oct',
      'open',
      'ord',
      'pow',
      'property',
      'range',
      'raw_input',
      'reduce',
      'reload',
      'repr',
      'reversed',
      'round',
      'set',
      'setattr',
      'slice',
      'sorted',
      'staticmethod',
      'str',
      'sum',
      'super',
      'tuple',
      'type',
      'unichr',
      'unicode',
      'vars',
      'xrange',
      'zip',
    );

    $pseudo_builtins = array(
      'Ellipsis',
      'False',
      'None',
      'NotImplemented',
      'True',
      'self',
    );

    $exceptions = array(
      'ArithmeticError',
      'AssertionError',
      'AttributeError',
      'BaseException',
      'DeprecationWarning',
      'EOFError',
      'EnvironmentError',
      'Exception',
      'FloatingPointError',
      'FutureWarning',
      'GeneratorExit',
      'IOError',
      'ImportError',
      'ImportWarning',
      'IndentationError',
      'IndexError',
      'KeyError',
      'KeyboardInterrupt',
      'LookupError',
      'MemoryError',
      'NameError',
      'NotImplemented',
      'NotImplementedError',
      'OSError',
      'OverflowError',
      'OverflowWarning',
      'PendingDeprecationWarning',
      'ReferenceError',
      'RuntimeError',
      'RuntimeWarning',
      'StandardError',
      'StopIteration',
      'SyntaxError',
      'SyntaxWarning',
      'SystemError',
      'SystemExit',
      'TabError',
      'TypeError',
      'UnboundLocalError',
      'UnicodeDecodeError',
      'UnicodeEncodeError',
      'UnicodeError',
      'UnicodeTranslateError',
      'UnicodeWarning',
      'UserWarning',
      'VMSError',
      'ValueError',
      'Warning',
      'WindowsError',
      'ZeroDivisionError',
    );

    $nonsemantic_rules = array(
      array('[^\\S\\n]+', null),
      array('#[^\\n]*', 'c'),
    );

    $stringescape = array(
      array(
        '\\\\([\\\\abfnrtv"\']|\n|N{.*?}|u[a-fA-F0-9]{4}|'.
        'U[a-fA-F0-9]{8}|x[a-fA-F0-9]{2}|[0-7]{1,3})',
        'se',
      ),
    );

    $nl = array(
      array('\\n', 's'),
    );

    $strings = array(
      array(
        '%(\\(\\w+\\))?[-#0 +]*([0-9]+|[*])?(\\.([0-9]+|[*]))?'.
        '[hlL]?[diouxXeEfFgGcrs%]',
        'si',
      ),
      array('[^\\\\\'"%\\n]+', 's'),
      // quotes, percents, and backslashes must be parsed one at a time
      array('[\'"\\\\]', 's'),
      // unhandled string formatting sign
      array('%', 's'),
      // newlines are an error (use $nl rules)
      array('', null, '!pop'),
    );

    $dqs = array_merge(array(
      array('"', 's', '!pop'),
      // included here for raw strings
      array('(?:\\\\\\\\|\\\\\'|\\\\n)', 's'),
    ), $strings);

    $sqs = array_merge(array(
      array('\'', 's', '!pop'),
      // included here for raw strings
      array('(?:\\\\\\\\|\\\\\'|\\\\n)', 's'),
    ), $strings);

    $tdqs = array_merge(array(
      array('"""', 's', '!pop'),
    ), $nl, $strings);

    $tsqs = array_merge(array(
      array('\'\'\'', 's', '!pop'),
    ), $nl, $strings);

    return array(
      'start' => array_merge(array(
        array('\\n', null),
        // TODO: Docstrings should match only at the start of a line
        array('""".*?"""', 'sd'),
        array('\'\'\'.*?\'\'\'', 'sd'),
      ), $nonsemantic_rules, array(
        array('[]{}:(),;[]', 'p'),
        array('\\\\\\n', null),
        array('\\\\', null),
        array('(?:in|is|and|or|not)\\b', 'ow'),
        array('(?:!=|==|<<|>>|[-~+/*%=<>&^|.])', 'o'),
        array('(?:'.implode('|', $keywords).')\\b', 'k'),
        array('def(?=\\s)', 'k', 'funcname'),
        array('class(?=\\s)', 'k', 'classname'),
        array('from(?=\\s)', 'kn', 'fromimport'),
        array('import(?=\\s)', 'kn', 'import'),
        array('(?<!\\.)(?:'.implode('|', $builtins).')\\b', 'nb'),
        array('(?<!\\.)(?:'.implode('|', $pseudo_builtins).')\\b', 'bp'),
        array('(?<!\\.)(?:'.implode('|', $exceptions).')\\b', 'ne'),
        array('`[^\\n]*?`', 'sb'),
        array('(?:[rR]|[uU][rR]|[rR][uU])"""', 's', 'tdqs_raw'),
        array('(?:[rR]|[uU][rR]|[rR][uU])\'\'\'', 's', 'tsqs_raw'),
        array('(?:[rR]|[uU][rR]|[rR][uU])"', 's', 'dqs_raw'),
        array('(?:[rR]|[uU][rR]|[rR][uU])\'', 's', 'sqs_raw'),
        array('[uU]?"""', 's', 'tdqs'),
        array('[uU]?\'\'\'', 's', 'tsqs'),
        array('[uU]?"', 's', 'dqs'),
        array('[uU]?\'', 's', 'sqs'),
        array('@[\\w.]+', 'nd'),
        array('[a-zA-Z_]\\w*', 'n'),
        array('(\\d+\\.\\d*|\\d*\\.\\d+)([eE][+-]?[0-9]+)?j?', 'mf'),
        array('\\d+[eE][+-]?[0-9]+j?', 'mf'),
        array('0[0-7]+j?', 'mo'),
        array('0[bB][01]+', 'mb'),
        array('0[xX][a-fA-F0-9]+', 'mh'),
        array('\\d+L', 'il'),
        array('\\d+j?', 'mi'),
        array('.', null),
      )),

      'funcname' => array_merge($nonsemantic_rules, array(
        array('[a-zA-Z_]\w*', 'nf', '!pop'),
        array('', null, '!pop'),
      )),

      'classname' => array_merge($nonsemantic_rules, array(
        array('[a-zA-Z_]\w*', 'nc', '!pop'),
        array('', null, '!pop'),
      )),

      'fromimport' => array_merge($nonsemantic_rules, array(
        array('import\b', 'kn', '!pop'),
        // if None occurs here, it's "raise x from None", since None can
        // never be a module name
        array('None\b', 'bp', '!pop'),
        // sadly, in "raise x from y" y will be highlighted as namespace too
        array('[a-zA-Z_.][\w.]*', 'nn'),
        array('', null, '!pop'),
      )),

      'import' => array_merge($nonsemantic_rules, array(
        array('as\b', 'kn'),
        array(',', 'o'),
        array('[a-zA-Z_.][\w.]*', 'nn'),
        array('', null, '!pop'),
      )),

      'dqs_raw' => $dqs,
      'sqs_raw' => $sqs,
      'dqs' => array_merge($stringescape, $dqs),
      'sqs' => array_merge($stringescape, $sqs),
      'tdqs_raw' => $tdqs,
      'tsqs_raw' => $tsqs,
      'tdqs' => array_merge($stringescape, $tdqs),
      'tsqs' => array_merge($stringescape, $tsqs),
    );
  }

}
