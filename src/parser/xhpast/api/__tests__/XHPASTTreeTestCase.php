<?php

/**
 * @nolint We test crazy stuff here.
 */
final class XHPASTTreeTestCase extends PhutilTestCase {

  public function testEvalStaticString() {
    $this->assertEval(1,    '1');
    $this->assertEval('a',  '"a"');
    $this->assertEval(-1.1, '-1.1');
    $this->assertEval(
       array('foo', 'bar', -1, +2, -3.4, +4.3, 1e10, 1e-5, -2.3e7),
      "array('foo', 'bar', -1, +2, -3.4, +4.3, 1e10, 1e-5, -2.3e7)");
    $this->assertEval(
       array(),
      'array()');
    $this->assertEval(
       array(42 => 7, 'a' => 5, 1, 2, 3, 4, 1 => 'goo'),
      "array(42 => 7, 'a' => 5, 1, 2, 3, 4, 1 => 'goo')");
    $this->assertEval(
       array('a' => 'a', 'b' => array(1, 2, array(3))),
      "array('a' => 'a', 'b' => array(1, 2, array(3)))");
    $this->assertEval(
       array(true, false, null),
      'array(true, false, null)');

    // Duplicate keys
    $this->assertEval(
        array(0 => '1', 0 => '2'),
       "array(0 => '1', 0 => '2')");

    $this->assertEval('simple string', "'simple string'");
    $this->assertEval('42', "'42'");
    $this->assertEval('binary string', "b'binary string'");
    $this->assertEval(3.1415926, '3.1415926');
    $this->assertEval(42, '42');
    $this->assertEval(
       array(2147483648, 2147483647, -2147483648, -2147483647),
      'array(2147483648, 2147483647, -2147483648, -2147483647)');

    $this->assertEval(INF, 'INF');
    $this->assertEval(-INF, '-INF');

    $this->assertEval(0x1b, '0x1b');
    $this->assertEval(0X0A, '0X0A');

    // Octal
    $this->assertEval(010, '010');
    // TODO: this passes on < PHP 7 for some reason but fails on PHP 7 correctly
    //$this->assertEval(080, '080');  // Invalid!

    // Leading 0, but float, not octal.
    $this->assertEval(0.11e1, '0.11e1');
    $this->assertEval(0e1, '0e1');

    $this->assertEval(0, '0');

    // Static evaluation treats '$' as a literal dollar glyph.
    $this->assertEval('$asdf', '"$asdf"');

    $this->assertEval(
       '\a\b\c\d\e\f\g\h\i\j\k\l\m\n\o\p\q\r\s\t\u\v\w\x\y\z'.
       '\1\2\3\4\5\6\7\8\9\0'.
       '\!\@\#\$\%\^\&\*\(\)'.
       '\`\~\\\|\[\]\{\}\<\>\,\.\/\?\:\;\-\_\=\+',

      "'\\a\\b\\c\\d\\e\\f\\g\\h\\i\\j\\k\\l\\m\\n\\o\\p\\q".
      "\\r\\s\\t\\u\\v\\w\\x\\y\\z".
      "\\1\\2\\3\\4\\5\\6\\7\\8\\9\\0".
      "\\!\\@\\#\\$\\%\\^\\&\\*\\(\\)".
      "\\`\\~\\\\\\|\\[\\]\\{\\}\\<\\>\\,\\.\\/\\?\\:\\;\\-\\_\\=\\+".
      "'");

    // After PHP 5.4.0, "\e" means "escape", not "backslash e". We implement the
    // newer rules, but if we're running in an older version of PHP we can not
    // express them with "\e".
    $this->assertEval(chr(27), '"\\e"');

    $this->assertEval(
       "\a\b\c\d\x1B\f\g\h\i\j\k\l\m\n\o\p\q\r\s\t\u\v\w\x\y\z".
       "\1\2\3\4\5\6\7\8\9\0".
       "\!\@\#\$\%\^\&\*\(\)".
       "\`\~\\\|\[\]\{\}\<\>\,\.\/\?\:\;\-\_\=\+",

      '"\\a\\b\\c\\d\\e\\f\\g\\h\\i\\j\\k\\l\\m\\n\\o\\p\\q'.
      '\\r\\s\\t\\u\\v\\w\\x\\y\\z'.
      '\\1\\2\\3\\4\\5\\6\\7\\8\\9\\0'.
      '\\!\\@\\#\\$\\%\\^\\&\\*\\(\\)'.
      '\\`\\~\\\\\\|\\[\\]\\{\\}\\<\\>\\,\\.\\/\\?\\:\\;\\-\\_\\=\\+"');

    $this->assertEval(
      '\' "',
      "'\\' \"'");

    $this->assertEval(
      '\\ \\\\ ',
      '\'\\\\ \\\\\\\\ \'');

    $this->assertEval(
      '\ \\ ',
      "'\\ \\\\ '");

    $this->assertEval(
      '\x92',
      '\'\x92\'');

    $this->assertEval(
      "\x92",
      '"\x92"');

    $this->assertEval(
      "\x",
      '"\x"');

    $this->assertEval(
      "\x1",
      '"\x1"');

    $this->assertEval(
      "\x000 !",
      '"\x000 !"');

    $this->assertEval(
      "\x0",
      '"\x0"');

    $this->assertEval(
      "\xg",
      '"\xg"');
  }

  private function assertEval($value, $string) {
    $this->assertEqual(
      $value,
      XHPASTTree::newStatementFromString($string)->evalStatic(),
      $string);
  }

}
