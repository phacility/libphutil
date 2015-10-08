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

    return phutil_tag(
      'blockquote',
      array(),
      $children);
  }

}
