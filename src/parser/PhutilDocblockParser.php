<?php

/**
 * Parse a docblock comment from source code into raw text documentation and
 * metadata (like "@author" and "@return").
 */
final class PhutilDocblockParser extends Phobject {

  public function extractDocblocks($text) {
    $blocks = array();

    $matches = null;
    $match = preg_match_all(
      '@(/\*\*.*?\*/)@s',
      $text,
      $matches,
      PREG_OFFSET_CAPTURE | PREG_PATTERN_ORDER);

    if (!$match) {
      return $blocks;
    }

    // Build a map of character offset -> line number.
    $map = array();
    $lines = explode("\n", $text);
    $num = 1;
    foreach ($lines as $line) {
      $len = strlen($line) + 1;
      for ($jj = 0; $jj < $len; $jj++) {
        $map[] = $num;
      }
      ++$num;
    }

    foreach ($matches[0] as $match) {
      list($data, $offset) = $match;
      $blocks[] = array($data, $map[$offset]);
    }

    return $blocks;
  }

  public function parse($docblock) {
    // Strip off comments.
    $docblock = trim($docblock);
    $docblock = preg_replace('@^/\*\*@', '', $docblock);
    $docblock = preg_replace('@\*/$@', '', $docblock);
    $docblock = preg_replace('@^\s*\*@m', '', $docblock);

    // Normalize multi-line @specials.
    $lines = explode("\n", $docblock);
    $last = false;
    foreach ($lines as $k => $line) {

      // NOTE: We allow "@specials" to be preceded by up to two whitespace
      // characters; more than that and we assume the block is a code block.
      // Broadly, there's ambiguity between a special like:
      //
      //     <... lots of indentation ...> @author alincoln
      //
      // ...and a code block like:
      //
      //     <... lots of indentation ...> @def square(x, y):
      //
      // Because standard practice is to indent the entire block one level,
      // we allow that and one additional space before assuming something is
      // a code block.

      if (preg_match('/^\s{0,2}@\w/i', $line)) {
        $last = $k;
        $lines[$last] = trim($line);
      } else if (preg_match('/^\s*$/', $line)) {
        $last = false;
      } else if ($last !== false) {
        $lines[$last] = $lines[$last].' '.trim($line);
        unset($lines[$k]);
      }
    }

    $docblock = implode("\n", $lines);

    $special = array();

    // Parse @specials.
    $matches = null;
    $have_specials = preg_match_all(
      '/^@([\w-]+)[ \t]*([^\n]*)/m',
      $docblock,
      $matches,
      PREG_SET_ORDER);

    if ($have_specials) {
      $docblock = preg_replace(
        '/^@([\w-]+)[ \t]*([^\n]*)?\n*/m',
        '',
        $docblock);
      foreach ($matches as $match) {
        list($_, $type, $data) = $match;
        $data = trim($data);

        // For flags like "@stable" which don't have any string data, set the
        // value to true.
        if (!strlen($data)) {
          $data = true;
        }

        if (!isset($special[$type])) {
          $special[$type] = $data;
        } else {
          if (!is_array($special[$type])) {
            $special[$type] = (array)$special[$type];
          }
          $special[$type][] = $data;
        }
      }
    }

    // Convert `array(true, true, true)` to `true`.
    foreach ($special as $type => $data) {
      if (is_array($data)) {
        $all_trues = true;

        foreach ($data as $value) {
          if ($value !== true) {
            $all_trues = false;
            break;
          }
        }

        if ($all_trues) {
          $special[$type] = true;
        }
      }
    }

    $docblock = str_replace("\t", '  ', $docblock);

    // Smush the whole docblock to the left edge.
    $min_indent = 80;
    $indent = 0;
    foreach (array_filter(explode("\n", $docblock)) as $line) {
      for ($ii = 0; $ii < strlen($line); $ii++) {
        if ($line[$ii] != ' ') {
          break;
        }
        $indent++;
      }
      $min_indent = min($indent, $min_indent);
    }

    $docblock = preg_replace(
      '/^'.str_repeat(' ', $min_indent).'/m',
      '',
      $docblock);
    $docblock = rtrim($docblock);
    // Trim any empty lines off the front, but leave the indent level if there
    // is one.
    $docblock = preg_replace('/^\s*\n/', '', $docblock);

    return array($docblock, $special);
  }

}
