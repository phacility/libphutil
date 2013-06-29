<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngineRemarkupHorizontalRuleBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getMatchingLineCount(array $lines, $cursor) {
    $num_lines = 0;
    $pattern = "/^_{3,}$|^\*\s?\*\s?\*(\s|\*)*$|^\-\s?\-\s?\-(\s|\-)*$/";
    if (preg_match($pattern, rtrim($lines[$cursor], "\n\r"))) {
      $num_lines++;
      $cursor++;
      while (isset($lines[$cursor]) && !strlen(trim($lines[$cursor]))) {
        $num_lines++;
        $cursor++;
      }
    }

    return $num_lines;
  }

  public function markupText($text) {
    return phutil_tag('hr', array());
  }


}
