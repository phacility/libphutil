<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngineRemarkupNoteBlockRule
  extends PhutilRemarkupEngineBlockRule {

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

  public function markupText($text) {
    $matches = array();
    preg_match($this->getRegEx(), $text, $matches);
    switch ($matches[0]) {
      case 'NOTE: ':
        $class_suffix = 'note';
        $truncate = 0;
        break;
      case '(NOTE) ':
        $class_suffix = 'note';
        $truncate = 7;
        break;
      case 'IMPORTANT: ':
        $class_suffix = 'important';
        $truncate = 0;
        break;
      case '(IMPORTANT) ':
        $class_suffix = 'important';
        $truncate = 12;
        break;
      case 'WARNING: ':
        $class_suffix = 'warning';
        $truncate = 0;
        break;
      case '(WARNING) ':
        $class_suffix = 'warning';
        $truncate = 10;
        break;
    }
    $text_mode = $this->getEngine()->isTextMode();
    if ($truncate && !$text_mode) {
      $text = substr($text, $truncate);
    }
    $text = $this->applyRules(rtrim($text));

    if ($text_mode) {
      return $text;
    }

    return phutil_tag(
      'div',
      array(
        'class' => 'remarkup-'.$class_suffix
      ),
      $text);
  }

  private function getRegEx() {
    return "/^(NOTE: |IMPORTANT: |WARNING: |".
           "\(NOTE\) |\(WARNING\) |\(IMPORTANT\) )/";
  }
}
