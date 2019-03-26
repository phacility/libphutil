<?php

final class PhutilRemarkupQuotesBlockRule extends PhutilRemarkupBlockRule {

  public function getMatchingLineCount(array $lines, $cursor) {
    $pos = $cursor;

    if (preg_match('/^>/', $lines[$pos])) {
      do {
        ++$pos;
      } while (isset($lines[$pos]) && preg_match('/^>/', $lines[$pos]));
    }

    return ($pos - $cursor);
  }

  public function supportsChildBlocks() {
    return true;
  }

  public function extractChildText($text) {
    $text = phutil_split_lines($text, true);
    foreach ($text as $key => $line) {
      $text[$key] = substr($line, 1);
    }

    // If every line in the block is empty or begins with at least one leading
    // space, strip the initial space off each line. When we quote text, we
    // normally add "> " (with a space) to the beginning of each line, which
    // can disrupt some other rules. If the block appears to have this space
    // in front of each line, remove it.

    $strip_space = true;
    foreach ($text as $key => $line) {
      $len = strlen($line);

      if (!$len) {
        // We'll still strip spaces if there are some completely empty
        // lines, they may have just had trailing whitespace trimmed.
        continue;
      }

      if ($line[0] == ' ' || $line[0] == "\n") {
        continue;
      }

      // The first character of this line is something other than a space, so
      // we can't strip spaces.
      $strip_space = false;
      break;
    }

    if ($strip_space) {
      foreach ($text as $key => $line) {
        $len = strlen($line);
        if (!$len) {
          continue;
        }

        if ($line[0] !== ' ') {
          continue;
        }

        $text[$key] = substr($line, 1);
      }
    }

    return array('', implode('', $text));
  }

  public function markupText($text, $children) {
    if ($this->getEngine()->isTextMode()) {
      $lines = rtrim($children, "\n");
      $lines = phutil_split_lines($lines);
      foreach ($lines as $key => $line) {
        if (isset($line[0]) && ($line[0] == '>')) {
          $line = '>'.$line;
        } else {
          $line = '> '.$line;
        }
        $lines[$key] = $line;
      }
      return implode('', $lines);
    }

    $attributes = array();
    if ($this->getEngine()->isHTMLMailMode()) {
      $style = array(
        'border-left: 3px solid #a7b5bf;',
        'color: #464c5c;',
        'font-style: italic;',
        'margin: 4px 0 12px 0;',
        'padding: 4px 12px;',
        'background-color: #f8f9fc;',
      );

      $attributes['style'] = implode(' ', $style);
    }

    return phutil_tag(
      'blockquote',
      $attributes,
      $children);
  }

}
