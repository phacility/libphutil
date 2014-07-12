<?php

/**
 * Truncate a UTF-8 string to a some maximum number of bytes, codepoints, or
 * glyphs.
 *
 * This class takes some UTF-8 string as input, and emits a valid UTF-8 string
 * which is no longer than given byte, codepoint, or glyph limits.
 *
 *   $short = id(new PhutilUTF8StringTruncator())
 *     ->setMaximumGlyphs(80)
 *     ->truncateString($long);
 *
 * Byte limits restrict the number of bytes the result may contain. They are
 * appropriate when you care about how much storage a string requires.
 *
 * Codepoint limits restrict the number of codepoints the result may contain.
 * Since codepoints may have up to 4 bytes, the resulting strings may require
 * have more than this many bytes. This kind of limit is appropriate when you
 * are using UTF-8 storage, like MySQL.
 *
 * Glyph limits restrict the display size of the string. Because a single glyph
 * may have an arbitrary number of combining characters, this does not impose
 * a storage size limit on the string: a string with only one glyph may require
 * an arbitrarily large number of bytes.
 *
 * You can set more than one limit; the smallest limit will be used.
 *
 * NOTE: This function makes a best effort to apply some reasonable rules but
 * will not work well for the full range of unicode languages.
 */
final class PhutilUTF8StringTruncator extends Phobject {

  private $maximumBytes;
  private $maximumCodepoints;
  private $maximumGlyphs;
  private $minimumLimit;

  private $terminator = "\xE2\x80\xA6";
  private $terminatorBytes = 3;
  private $terminatorCodepoints = 1;
  private $terminatorGlyphs = 1;

  public function setMaximumBytes($maximum_bytes) {
    $this->maximumBytes = $maximum_bytes;
    $this->didUpdateMaxima();
    return $this;
  }

  public function setMaximumCodepoints($maximum_codepoints) {
    $this->maximumCodepoints = $maximum_codepoints;
    $this->didUpdateMaxima();
    return $this;
  }

  public function setMaximumGlyphs($maximum_glyphs) {
    $this->maximumGlyphs = $maximum_glyphs;
    $this->didUpdateMaxima();
    return $this;
  }

  private function didUpdateMaxima() {
    $this->minimumLimit = INF;

    if ($this->maximumBytes) {
      $this->minimumLimit = min($this->minimumLimit, $this->maximumBytes);
    }

    if ($this->maximumCodepoints) {
      $this->minimumLimit = min($this->minimumLimit, $this->maximumCodepoints);
    }

    if ($this->maximumGlyphs) {
      $this->minimumLimit = min($this->minimumLimit, $this->maximumGlyphs);
    }
  }

  public function setTerminator($terminator) {
    $this->terminator = $terminator;
    $this->terminatorBytes = strlen($terminator);
    $this->terminatorCodepoints = count(phutil_utf8v($terminator));
    $this->terminatorGlyphs = count(phutil_utf8v_combined($terminator));
    return $this;
  }

  public function truncateString($string) {
    // First, check if the string has fewer bytes than the most restrictive
    // limit. Codepoints and glyphs always take up at least one byte, so we can
    // just return the string unmodified if we're under all of the limits.
    $byte_len = strlen($string);
    if ($byte_len <= $this->minimumLimit) {
      return $string;
    }

    // If we need the vector of codepoints, build it.
    $string_pv = null;
    if ($this->maximumCodepoints) {
      $string_pv = phutil_utf8v($string);
      $point_len = count($string_pv);
    }

    // We always need the combined vector, even if we're only doing byte or
    // codepoint truncation, because we don't want to truncate to half of a
    // combining character.
    $string_gv = phutil_utf8v_combined($string);
    $glyph_len = count($string_gv);

    // Now, check if we're still over the limits. For example, a string may
    // be over the raw byte limit but under the glyph limit if it contains
    // several multibyte characters.

    $too_long = false;
    if ($this->maximumBytes && ($byte_len > $this->maximumBytes)) {
      $too_long = true;
    }
    if ($this->maximumCodepoints && ($point_len > $this->maximumCodepoints)) {
      $too_long = true;
    }
    if ($this->maximumGlyphs && ($glyph_len > $this->maximumGlyphs)) {
      $too_long = true;
    }

    if (!$too_long) {
      return $string;
    }

    // This string is legitimately longer than at least one of the limits, so
    // we need to truncate it. Find the minimum cutoff point: this is the last
    // glyph we can possibly return while satisfying the limits and having space
    // for the terminator.

    $cutoff = $glyph_len;
    if ($this->maximumBytes) {
      if ($byte_len <= $this->maximumBytes) {
        $cutoff = $glyph_len;
      } else {
        $bytes = $this->terminatorBytes;
        for ($ii = 0; $ii < $glyph_len; $ii++) {
          $bytes += strlen($string_gv[$ii]);
          if ($bytes > $this->maximumBytes) {
            $cutoff = $ii;
            break;
          }
        }
      }
    }

    if ($this->maximumCodepoints) {
      if ($point_len <= $this->maximumCodepoints) {
        $cutoff = min($cutoff, $glyph_len);
      } else {
        $points = 0;
        for ($ii = 0; $ii < $glyph_len; $ii++) {
          $glyph_bytes = strlen($string_gv[$ii]);
          while ($points < $point_len) {
            $glyph_bytes -= strlen($string_pv[$points]);
            $points++;
            if ($glyph_bytes <= 0) {
              break;
            }
          }
          $points_total = $points + $this->terminatorCodepoints;
          if ($points_total > $this->maximumCodepoints) {
            $cutoff = min($cutoff, $ii);
            break;
          }
        }
      }
    }

    if ($this->maximumGlyphs) {
      if ($glyph_len <= $this->maximumGlyphs) {
        $cutoff = min($cutoff, $glyph_len);
      } else {
        $cutoff = min($cutoff, $this->maximumGlyphs - $this->terminatorGlyphs);
      }
    }

    // If we don't have enough characters for anything, just return the
    // terminator.
    if ($cutoff <= 0) {
      return $this->terminator;
    }

    // Otherwise, we're going to try to cut the string off somewhere reasonable
    // rather than somewhere arbitrary.

    // NOTE: This is not complete, and there are many other word boundary
    // characters and reasonable places to break words in the UTF-8 character
    // space. For now, this gives us reasonable behavior for latin languages. We
    // don't necessarily have access to PCRE+Unicode so there isn't a great way
    // for us to look up character attributes.

    // If we encounter these, prefer to break on them instead of cutting the
    // string off in the middle of a word.
    static $break_characters = array(
      ' '   => true,
      "\n"  => true,
      ';'   => true,
      ':'   => true,
      '['   => true,
      '('   => true,
      ','   => true,
      '-'   => true,
    );

    // If we encounter these, shorten to this character exactly without
    // appending the terminal.
    static $stop_characters = array(
      '.'   => true,
      '!'   => true,
      '?'   => true,
    );

    // Search backward in the string, looking for reasonable places to break it.
    $word_boundary = null;
    $stop_boundary = null;

    // If we do a word break with a terminal, we have to look beyond at least
    // the number of characters in the terminal. If the terminal is longer than
    // the required length, we'll skip this whole block and return it on its
    // own.

    // Only search backward for a while. At some point we don't get a better
    // result by looking through the whole string, and if this is "MMM..." or
    // a non-latin language without word break characters we're just wasting
    // time.

    $search = max(0, $cutoff - 256);
    for ($ii = min($cutoff, $glyph_len - 1); $ii >= $search; $ii--) {
      $c = $string_gv[$ii];

      if (isset($break_characters[$c])) {
        $word_boundary = $ii;
      } else if (isset($stop_characters[$c])) {
        $stop_boundary = $ii + 1;
        break;
      } else {
        if ($word_boundary !== null) {
          break;
        }
      }
    }

    if ($stop_boundary !== null) {
      // We found a character like ".". Cut the string there, without appending
      // the terminal.
      $string_part = array_slice($string_gv, 0, $stop_boundary);
      return implode('', $string_part);
    }

    // If we didn't find any boundary characters or we found ONLY boundary
    // characters, just break at the maximum character length.
    if ($word_boundary === null || $word_boundary === 0) {
      $word_boundary = $cutoff;
    }

    $string_part = array_slice($string_gv, 0, $word_boundary);
    $string_part = implode('', $string_part);

    return $string_part.$this->terminator;
  }

}
