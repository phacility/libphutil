<?php

final class PhutilRemarkupNoteBlockRule extends PhutilRemarkupBlockRule {

  public function getMatchingLineCount(array $lines, $cursor) {
    $num_lines = 0;

    if (preg_match($this->getRegEx(), $lines[$cursor])) {
      $num_lines++;
      $cursor++;

      while (isset($lines[$cursor])) {
        if (trim($lines[$cursor])) {
          $num_lines++;
          $cursor++;
          continue;
        }
        break;
      }
    }

    return $num_lines;
  }

  public function markupText($text, $children) {
    $matches = array();
    preg_match($this->getRegEx(), $text, $matches);

    if (idx($matches, 'showword')) {
      $word = $matches['showword'];
      $show = true;
    } else {
      $word = $matches['hideword'];
      $show = false;
    }

    $class_suffix = phutil_utf8_strtolower($word);

    // This is the "(IMPORTANT)" or "NOTE:" part.
    $word_part = rtrim(substr($text, 0, strlen($matches[0])));

    // This is the actual text.
    $text_part = substr($text, strlen($matches[0]));
    $text_part = $this->applyRules(rtrim($text_part));

    $text_mode = $this->getEngine()->isTextMode();
    if ($text_mode) {
      return $word_part.' '.$text_part;
    }

    if ($show) {
      $content = array(
        phutil_tag(
          'span',
          array(
            'class' => 'remarkup-note-word',
          ),
          $word_part),
        ' ',
        $text_part,
      );
    } else {
      $content = $text_part;
    }

    return phutil_tag(
      'div',
      array(
        'class' => 'remarkup-'.$class_suffix,
      ),
      $content);
  }

  private function getRegEx() {
    $words = array(
      'NOTE',
      'IMPORTANT',
      'WARNING',
    );

    foreach ($words as $k => $word) {
      $words[$k] = preg_quote($word, '/');
    }
    $words = implode('|', $words);

    return
      '/^(?:'.
      '(?:\((?P<hideword>'.$words.')\))'.
      '|'.
      '(?:(?P<showword>'.$words.'):))\s*'.
      '/';
  }
}
