<?php

final class PhutilRemarkupHorizontalRuleBlockRule
  extends PhutilRemarkupBlockRule {

  /**
   * This rule executes at priority `300`, so it can preempt the list block
   * rule and claim blocks which begin `---`.
   */
  public function getPriority() {
    return 300;
  }

  public function getMatchingLineCount(array $lines, $cursor) {
    $num_lines = 0;
    $pattern = '/^_{3,}$|^\*\s?\*\s?\*(\s|\*)*$|^\-\s?\-\s?\-(\s|\-)*$/';
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

  public function markupText($text, $children) {
    return phutil_tag('hr', array('class' => 'remarkup-hr'));
  }

}
