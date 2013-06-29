<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngineRemarkupLiteralBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getMatchingLineCount(array $lines, $cursor) {
    $num_lines = 0;

    if (preg_match("/^%%%/", $lines[$cursor])) {
      $num_lines++;
      $cursor++;

      while (isset($lines[$cursor])) {
        if (!preg_match("/^%%%$/", $lines[$cursor])) {
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
    $text = preg_replace('/%%%\s*$/', '', substr($text, 3));
    $text = $this->applyRules($text);
    return $text;
  }
}
