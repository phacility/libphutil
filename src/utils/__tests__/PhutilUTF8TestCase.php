<?php

/**
 * Test cases for functions in utf8.php.
 */
final class PhutilUTF8TestCase extends PhutilTestCase {

  public function testUTF8izeASCIIIgnored() {
    $input = "this\x01 is a \x7f test string";
    $this->assertEqual($input, phutil_utf8ize($input));
  }

  public function testUTF8izeUTF8Ignored() {
    $input = "\xc3\x9c \xc3\xbc \xe6\x9d\xb1!";
    $this->assertEqual($input, phutil_utf8ize($input));
  }

  public function testUTF8izeLongStringNosegfault() {
    // For some reason my laptop is segfaulting on long inputs inside
    // preg_match(). Forestall this craziness in the common case, at least.
    phutil_utf8ize(str_repeat('x', 1024 * 1024));
    $this->assertTrue(true);
  }

  public function testUTF8izeInvalidUTF8Fixed() {
    $input =
      "\xc3 this has \xe6\x9d some invalid utf8 \xe6";
    $expect =
      "\xEF\xBF\xBD this has \xEF\xBF\xBD\xEF\xBF\xBD some invalid utf8 ".
      "\xEF\xBF\xBD";
    $result = phutil_utf8ize($input);
    $this->assertEqual($expect, $result);
  }

  public function testUTF8izeOwlIsCuteAndFerocious() {
    // This was once a ferocious owl when we used to use "?" as the replacement
    // character instead of U+FFFD, but now he is sort of not as cute or
    // ferocious.
    $input = "M(o\xEE\xFF\xFFo)M";
    $expect = "M(o\xEF\xBF\xBD\xEF\xBF\xBD\xEF\xBF\xBDo)M";
    $result = phutil_utf8ize($input);
    $this->assertEqual($expect, $result);
  }

  public function testOverlongFormFiltering() {
    $bad = "\xEF\xBF\xBD";

    $map = array(
      'quack' => 'quack',

      // This is U+1000, a valid character.
      "\xE1\x80\x80" => "\xE1\x80\x80",

      // This is a 2-byte encoding of U+0000.
      "\xC0\x80" => "{$bad}{$bad}",

      // This is a 3-byte encoding of U+0020.
      "\xE0\x80\xA0" => "{$bad}{$bad}{$bad}",

      "A \xE0\x83\x83" => "A {$bad}{$bad}{$bad}",
    );

    foreach ($map as $input => $expect) {
      $actual = phutil_utf8ize($input);
      $this->assertEqual(
        $expect,
        $actual,
        pht('Overlong form canonicalization of: %s', $input));
    }
  }

  public function testSurrogateFiltering() {
    $bad = "\xEF\xBF\xBD";

    $map = array(
      "A \xED\xA9\x98" => "A {$bad}{$bad}{$bad}",
    );

    foreach ($map as $input => $expect) {
      $actual = phutil_utf8ize($input);
      $this->assertEqual(
        $expect,
        $actual,
        pht('Surrogate filtering: %s', $input));
    }
  }


  public function testUTF8CodepointEncoding() {
    $map = array(
      0x20 => ' ',
      0x7E => '~',
      0xE9 => "\xC3\xA9",
      0x2603 => "\xE2\x98\x83",
      0x1F417 => "\xF0\x9F\x90\x97",
    );

    foreach ($map as $input => $expect) {
      $actual = phutil_utf8_encode_codepoint($input);
      $this->assertEqual(
        $expect,
        $actual,
        pht('UTF8 codepoint encoding of "%s".', $input));
    }
  }

  public function testUTF8len() {
    $strings = array(
      ''                => 0,
      'x'               => 1,
      "\xEF\xBF\xBD"    => 1,
      "x\xe6\x9d\xb1y"  => 3,
      'xyz'             => 3,
      'quack'           => 5,
    );
    foreach ($strings as $str => $expect) {
      $this->assertEqual($expect, phutil_utf8_strlen($str), 'Length of '.$str);
    }
  }

  public function testUTF8v() {
    $strings = array(
      ''                  => array(),
      'x'                 => array('x'),
      'quack'             => array('q', 'u', 'a', 'c', 'k'),
      "x\xe6\x9d\xb1y"    => array('x', "\xe6\x9d\xb1", 'y'),

      // This is a combining character.
      "x\xCD\xA0y"        => array('x', "\xCD\xA0", 'y'),
    );
    foreach ($strings as $str => $expect) {
      $this->assertEqual($expect, phutil_utf8v($str), 'Vector of '.$str);
    }
  }

  public function testUTF8vCodepoints() {
    $strings = array(
      ''                  => array(),
      'x'                 => array(0x78),
      'quack'             => array(0x71, 0x75, 0x61, 0x63, 0x6B),
      "x\xe6\x9d\xb1y"    => array(0x78, 0x6771, 0x79),

      "\xC2\xBB"          => array(0x00BB),
      "\xE2\x98\x83"      => array(0x2603),
      "\xEF\xBF\xBF"      => array(0xFFFF),
      "\xF0\x9F\x92\xA9"  => array(0x1F4A9),

      // This is a combining character.
      "x\xCD\xA0y"        => array(0x78, 0x0360, 0x79),
    );
    foreach ($strings as $str => $expect) {
      $this->assertEqual(
        $expect,
        phutil_utf8v_codepoints($str),
        pht('Codepoint Vector of %s', $str));
    }
  }

  public function testUTF8ConsoleStrlen() {
    $strings = array(
      ''              => 0,
      "\0"            => 0,
      'x'             => 1,

      // Double-width chinese character.
      "\xe6\x9d\xb1"  => 2,

      // Combining character.
      "x\xCD\xA0y"    => 2,

      // Combining plus double-width.
      "\xe6\x9d\xb1\xCD\xA0y"  => 3,

      // Colors and formatting.
      "\x1B[1mx\x1B[m" => 1,
      "\x1B[1m\x1B[31mx\x1B[m" => 1,
    );
    foreach ($strings as $str => $expect) {
      $this->assertEqual(
        $expect,
        phutil_utf8_console_strlen($str),
        pht('Console Length of %s', $str));
    }
  }

  public function testUTF8shorten() {
    $inputs = array(
      array('1erp derp derp', 9, '', '1erp derp'),
      array('2erp derp derp', 12, '...', '2erp derp...'),
      array('derpxderpxderp', 12, '...', 'derpxderp...'),
      array("derp\xE2\x99\x83derpderp", 12, '...', "derp\xE2\x99\x83derp..."),
      array('', 12, '...', ''),
      array('derp', 12, '...', 'derp'),
      array('11111', 5, '2222', '11111'),
      array('111111', 5, '2222', '12222'),

      array('D1rp. Derp derp.', 7, '...', 'D1rp.'),

      // "D2rp." is a better shortening of this, but it's dramatically more
      // complicated to implement with the newer byte/glyph/character
      // shortening code.
      array('D2rp. Derp derp.', 5, '...', 'D2...'),
      array('D3rp. Derp derp.', 4, '...', 'D...'),
      array('D4rp. Derp derp.', 14, '...', 'D4rp. Derp...'),
      array('D5rpderp, derp derp', 16, '...', 'D5rpderp...'),
      array('D6rpderp, derp derp', 17, '...', 'D6rpderp, derp...'),

      // Strings with combining characters.
      array("Gr\xCD\xA0mpyCatSmiles", 8, '...', "Gr\xCD\xA0mpy..."),
      array("X\xCD\xA0\xCD\xA0\xCD\xA0Y", 1, '', "X\xCD\xA0\xCD\xA0\xCD\xA0"),

      array(
        'Derp, supercalafragalisticexpialadoshus',
        30,
        '...',
        'Derp, supercalafragalistice...',
      ),

      // If a string has only word-break characters in it, we should just cut
      // it, not produce only the terminal.
      array('((((((((((', 8, '...', '(((((...'),

      // Terminal is longer than requested input.
      array('derp', 3, 'quack', 'quack'),

      array(
        'O123: com/oracle/java/path/to/application/source/ThingFactory.java',
        32,
        '...',
        'O123: com/oracle/java/path/to...',
      ),
    );

    foreach ($inputs as $input) {
      list($string, $length, $terminal, $expect) = $input;
      $result = id(new PhutilUTF8StringTruncator())
        ->setMaximumGlyphs($length)
        ->setTerminator($terminal)
        ->truncateString($string);
      $this->assertEqual($expect, $result, pht('Shortening of %s', $string));
    }
  }

  public function testUTF8StringTruncator() {
    $cases = array(
      array(
        "o\xCD\xA0o\xCD\xA0o\xCD\xA0o\xCD\xA0o\xCD\xA0",
        6,
        "o\xCD\xA0!",
        6,
        "o\xCD\xA0o\xCD\xA0!",
        6,
        "o\xCD\xA0o\xCD\xA0o\xCD\xA0o\xCD\xA0o\xCD\xA0",
      ),
      array(
        "X\xCD\xA0\xCD\xA0\xCD\xA0Y",
        6,
        '!',
        6,
        "X\xCD\xA0\xCD\xA0\xCD\xA0Y",
        6,
        "X\xCD\xA0\xCD\xA0\xCD\xA0Y",
      ),
      array(
        "X\xCD\xA0\xCD\xA0\xCD\xA0YZ",
        6,
        '!',
        5,
        "X\xCD\xA0\xCD\xA0\xCD\xA0!",
        2,
        "X\xCD\xA0\xCD\xA0\xCD\xA0!",
      ),
      array(
        "\xE2\x98\x83\xE2\x98\x83\xE2\x98\x83\xE2\x98\x83",
        4,
        "\xE2\x98\x83!",
        3,
        "\xE2\x98\x83\xE2\x98\x83!",
        3,
        "\xE2\x98\x83\xE2\x98\x83!",
      ),
    );

    foreach ($cases as $case) {
      list($input, $b_len, $b_out, $p_len, $p_out, $g_len, $g_out) = $case;

      $result = id(new PhutilUTF8StringTruncator())
        ->setMaximumBytes($b_len)
        ->setTerminator('!')
        ->truncateString($input);
      $this->assertEqual($b_out, $result, pht('byte-short of %s', $input));

      $result = id(new PhutilUTF8StringTruncator())
        ->setMaximumCodepoints($p_len)
        ->setTerminator('!')
        ->truncateString($input);
      $this->assertEqual($p_out, $result, pht('codepoint-short of %s', $input));

      $result = id(new PhutilUTF8StringTruncator())
        ->setMaximumGlyphs($g_len)
        ->setTerminator('!')
        ->truncateString($input);
      $this->assertEqual($g_out, $result, pht('glyph-short of %s', $input));
    }
  }

  public function testUTF8LargeTruncation() {
    // This is testing that our performance is reasonable when truncating a
    // large input into a small output. Runtime should be on the order of the
    // output size, not the input size.

    $whale = "\xF0\x9F\x90\xB3";
    $input = str_repeat($whale, 1024 * 1024);

    $result = id(new PhutilUTF8StringTruncator())
      ->setMaximumBytes(16)
      ->setTerminator('!')
      ->truncateString($input);

    $this->assertEqual(
      str_repeat($whale, 3).'!',
      $result,
      pht('Large truncation.'));
  }

  public function testUTF8Wrap() {
    $inputs = array(
      array(
        'aaaaaaa',
        3,
        array(
          'aaa',
          'aaa',
          'a',
        ),
      ),
      array(
        'aa<b>aaaaa',
        3,
        array(
          'aa<b>a',
          'aaa',
          'a',
        ),
      ),
      array(
        'aa&amp;aaaa',
        3,
        array(
          'aa&amp;',
          'aaa',
          'a',
        ),
      ),
      array(
        "aa\xe6\x9d\xb1aaaa",
        3,
        array(
          "aa\xe6\x9d\xb1",
          'aaa',
          'a',
        ),
      ),
      array(
        '',
        80,
        array(
        ),
      ),
      array(
        'a',
        80,
        array(
          'a',
        ),
      ),
    );

    foreach ($inputs as $input) {
      list($string, $width, $expect) = $input;
      $this->assertEqual(
        $expect,
        phutil_utf8_hard_wrap_html($string, $width),
        pht("Wrapping of '%s'.", $string));
    }
  }

  public function testUTF8NonHTMLWrap() {
    $inputs = array(
      array(
        'aaaaaaa',
        3,
        array(
          'aaa',
          'aaa',
          'a',
        ),
      ),
      array(
        'abracadabra!',
        4,
        array(
          'abra',
          'cada',
          'bra!',
        ),
      ),
      array(
        '',
        10,
        array(
        ),
      ),
      array(
        'a',
        20,
        array(
          'a',
        ),
      ),
      array(
        "aa\xe6\x9d\xb1aaaa",
        3,
        array(
          "aa\xe6\x9d\xb1",
          'aaa',
          'a',
        ),
      ),
      array(
        "mmm\nmmm\nmmmm",
        3,
        array(
          'mmm',
          'mmm',
          'mmm',
          'm',
        ),
      ),
    );

    foreach ($inputs as $input) {
      list($string, $width, $expect) = $input;
      $this->assertEqual(
        $expect,
        phutil_utf8_hard_wrap($string, $width),
        pht("Wrapping of '%s'", $string));
    }
  }

  public function testUTF8ConvertParams() {
    $caught = null;
    try {
      phutil_utf8_convert('', 'utf8', '');
    } catch (Exception $ex) {
      $caught = $ex;
    }
    $this->assertTrue((bool)$caught, pht('Requires source encoding.'));

    $caught = null;
    try {
      phutil_utf8_convert('', '', 'utf8');
    } catch (Exception $ex) {
      $caught = $ex;
    }
    $this->assertTrue((bool)$caught, pht('Requires target encoding.'));
  }


  public function testUTF8Convert() {
    if (!function_exists('mb_convert_encoding')) {
      $this->assertSkipped(pht('Requires %s extension.', 'mbstring'));
    }

    // "[ae]gis se[n]or [(c)] 1970 [+/-] 1 [degree]"
    $input = "\xE6gis SE\xD1OR \xA9 1970 \xB11\xB0";
    $expect = "\xC3\xA6gis SE\xC3\x91OR \xC2\xA9 1970 \xC2\xB11\xC2\xB0";
    $output = phutil_utf8_convert($input, 'UTF-8', 'ISO-8859-1');

    $this->assertEqual($expect, $output, pht('Conversion from ISO-8859-1.'));

    $caught = null;
    try {
      phutil_utf8_convert('xyz', 'moon language', 'UTF-8');
    } catch (Exception $ex) {
      $caught = $ex;
    }

    $this->assertTrue((bool)$caught, pht('Conversion with bogus encoding.'));
  }


  public function testUTF8ucwords() {
    $tests = array(
      '' => '',
      'x' => 'X',
      'X' => 'X',
      'five short graybles' => 'Five Short Graybles',
      'xXxSNiPeRKiLLeRxXx' => 'XXxSNiPeRKiLLeRxXx',
    );

    foreach ($tests as $input => $expect) {
      $this->assertEqual(
        $expect,
        phutil_utf8_ucwords($input),
        'phutil_utf8_ucwords("'.$input.'")');
    }
  }

  public function testUTF8strtolower() {
    $tests = array(
      '' => '',
      'a' => 'a',
      'A' => 'a',
      '!' => '!',
      'OMG!~ LOLolol ROFLwaffle11~' => 'omg!~ lololol roflwaffle11~',
      "\xE2\x98\x83" => "\xE2\x98\x83",
    );

    foreach ($tests as $input => $expect) {
      $this->assertEqual(
        $expect,
        phutil_utf8_strtolower($input),
        'phutil_utf8_strtolower("'.$input.'")');
    }
  }

  public function testUTF8strtoupper() {
    $tests = array(
      '' => '',
      'a' => 'A',
      'A' => 'A',
      '!' => '!',
      'Cats have 9 lives.' => 'CATS HAVE 9 LIVES.',
      "\xE2\x98\x83" => "\xE2\x98\x83",
    );

    foreach ($tests as $input => $expect) {
      $this->assertEqual(
        $expect,
        phutil_utf8_strtoupper($input),
        'phutil_utf8_strtoupper("'.$input.'")');
    }
  }

  public function testUTF8IsCombiningCharacter() {
    $character = "\xCD\xA0";
    $this->assertEqual(
      true,
      phutil_utf8_is_combining_character($character));

    $character = 'a';
    $this->assertEqual(
      false,
      phutil_utf8_is_combining_character($character));
  }

  public function testUTF8vCombined() {
    // Empty string.
    $string = '';
    $this->assertEqual(array(), phutil_utf8v_combined($string));

    // Single character.
    $string = 'x';
    $this->assertEqual(array('x'), phutil_utf8v_combined($string));

    // No combining characters.
    $string = 'cat';
    $this->assertEqual(array('c', 'a', 't'), phutil_utf8v_combined($string));

    // String with a combining character in the middle.
    $string = "ca\xCD\xA0t";
    $this->assertEqual(
      array('c', "a\xCD\xA0", 't'),
      phutil_utf8v_combined($string));

    // String starting with a combined character.
    $string = "c\xCD\xA0at";
    $this->assertEqual(
      array("c\xCD\xA0", 'a', 't'),
      phutil_utf8v_combined($string));

    // String with trailing combining character.
    $string = "cat\xCD\xA0";
    $this->assertEqual(
      array('c', 'a', "t\xCD\xA0"),
      phutil_utf8v_combined($string));

    // String with muliple combined characters.
    $string = "c\xCD\xA0a\xCD\xA0t\xCD\xA0";
    $this->assertEqual(
      array("c\xCD\xA0", "a\xCD\xA0", "t\xCD\xA0"),
      phutil_utf8v_combined($string));

    // String with multiple combining characters.
    $string = "ca\xCD\xA0\xCD\xA0t";
    $this->assertEqual(
      array('c', "a\xCD\xA0\xCD\xA0", 't'),
      phutil_utf8v_combined($string));

    // String beginning with a combining character.
    $string = "\xCD\xA0\xCD\xA0c";
    $this->assertEqual(
      array(" \xCD\xA0\xCD\xA0", 'c'),
      phutil_utf8v_combined($string));
  }

  public function testUTF8BMPSegfaults() {
    // This test case fails by segfaulting, or passes by not segfaulting. See
    // the function implementation for details.
    $input = str_repeat("\xEF\xBF\xBF", 1024 * 32);
    phutil_is_utf8_with_only_bmp_characters($input);

    $this->assertTrue(true);
  }

  public function testCJK() {
    $map = array(
      '' => false,
      'a' => false,
      '.' => false,
      "\xE2\x98\x83" => false,
      "\xE5\xA0\xB1" => true,
    );

    foreach ($map as $input => $expect) {
      $actual = phutil_utf8_is_cjk($input);

      $this->assertEqual($expect, $actual, pht('CJK: "%s"', $input));
    }
  }

  public function testUTF8BMP() {
    $tests = array(
      ''  => array(
        true,
        true,
        pht('empty string'),
      ),
      'a' => array(
        true,
        true,
        'a',
      ),
      "a\xCD\xA0\xCD\xA0" => array(
        true,
        true,
        pht('%s with combining', 'a'),
      ),
      "\xE2\x98\x83" => array(
        true,
        true,
        pht('snowman'),
      ),

      // This is the last character in BMP, U+FFFF.
      "\xEF\xBF\xBF" => array(
        true,
        true,
        'U+FFFF',
      ),

      // This isn't valid.
      "\xEF\xBF\xC0" => array(
        false,
        false,
        pht('Invalid, byte range.'),
      ),

      // This is an invalid nonminimal representation.
      "\xF0\x81\x80\x80" => array(
        false,
        false,
        pht('Nonminimal 4-byte character.'),
      ),

      // This is the first character above BMP, U+10000.
      "\xF0\x90\x80\x80" => array(
        true,
        false,
        'U+10000',
      ),
      "\xF0\x9D\x84\x9E" => array(
        true,
        false,
        'gclef',
      ),

      "musical \xF0\x9D\x84\x9E g-clef" => array(
        true,
        false,
        pht('gclef text'),
      ),
      "\xF0\x9D\x84" => array(
        false,
        false,
        pht('Invalid, truncated.'),
      ),

      "\xE0\x80\x80" => array(
        false,
        false,
        pht('Nonminimal 3-byte character.'),
      ),

      // Partial BMP characters.
      "\xCD" => array(
        false,
        false,
        pht('Partial 2-byte character.'),
      ),
      "\xE0\xA0" => array(
        false,
        false,
        pht('Partial BMP 0xE0 character.'),
      ),
      "\xE2\x98" => array(
        false,
        false,
        pht('Partial BMP cahracter.'),
      ),
    );

    foreach ($tests as $input => $test) {
      list($expect_utf8, $expect_bmp, $test_name) = $test;

      // Depending on what's installed on the system, this may use an
      // extension.
      $this->assertEqual(
        $expect_utf8,
        phutil_is_utf8($input),
        pht('is_utf(%s)', $test_name));

      // Also test this against the pure PHP implementation, explicitly.
      $this->assertEqual(
        $expect_utf8,
        phutil_is_utf8_slowly($input),
        pht('is_utf_slowly(%s)', $test_name));

      $this->assertEqual(
        $expect_bmp,
        phutil_is_utf8_with_only_bmp_characters($input),
        pht('is_utf_bmp(%s)', $test_name));
    }
  }

  public function testSystemLocaleManagement() {
    $original_locale = phutil_get_system_locale();
    $this->assertTrue(
      (strlen($original_locale) > 0),
      pht('System has some identifiable locale.'));

    $this->assertFalse(
      phutil_is_system_locale_available('duck.quack'),
      pht('Imaginary locale should be unavailable.'));

    $this->assertEqual(
      $original_locale,
      phutil_get_system_locale(),
      pht('Testing locale availability should not change the locale.'));

    $this->assertTrue(
      phutil_is_system_locale_available($original_locale),
      pht('The current locale should be available.'));

    $caught = null;
    try {
      phutil_set_system_locale('duck.quack');
    } catch (Exception $ex) {
      $caught = $ex;
    }

    $this->assertTrue(
      ($caught instanceof Exception),
      pht('Setting an imaginary locale should raise an exception.'));

    // We need two locales for the next part because one of them might be the
    // current locale, and we want to make sure we can actually change the
    // locale value.

    // If the current locale was "zz_ZZ", and then we do this:
    //
    //   set_locale("zz_ZZ");
    //   assert("zz_ZZ" == get_locale());
    //
    // ...the test could pass even if "set_locale(...)" does nothing.

    $has_us = phutil_is_system_locale_available('en_US.UTF-8');
    $has_gb = phutil_is_system_locale_available('en_GB.UTF-8');
    if (!$has_us || !$has_gb) {
      $this->assertSkipped(
        pht(
          'System does not have en_US + en_GB to do locale adjustment '.
          'tests.'));
    }

    phutil_set_system_locale('en_US.UTF-8');
    $this->assertEqual(
      'en_US.UTF-8',
      phutil_get_system_locale(),
      pht('Set locale to en_US.'));

    phutil_set_system_locale('en_GB.UTF-8');
    $this->assertEqual(
      'en_GB.UTF-8',
      phutil_get_system_locale(),
      pht('Set locale to en_GB.'));

    // Put things back the way they were.
    phutil_set_system_locale($original_locale);
  }

}
