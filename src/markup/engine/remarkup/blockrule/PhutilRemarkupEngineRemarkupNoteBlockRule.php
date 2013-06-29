<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngineRemarkupNoteBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getMatchingLineCount(array $lines, $cursor) {
    $num_lines = 0;

    if (preg_match("/^NOTE: /", $lines[$cursor])) {
      $num_lines++;
      $cursor++;

      while(isset($lines[$cursor])) {
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
    $text = rtrim($this->applyRules($text));

    if ($this->getEngine()->isTextMode()) {
      return $text;
    }

    return hsprintf('<div class="remarkup-note">%s</div>', $text);
  }
}
