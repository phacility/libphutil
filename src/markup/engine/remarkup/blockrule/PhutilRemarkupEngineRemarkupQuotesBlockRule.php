<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngineRemarkupQuotesBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getMatchingLineCount(array $lines, $cursor) {
    $num_lines = 0;

    if (preg_match("/^>/", $lines[$cursor])) {
      $num_lines++;
      $cursor++;

      while (isset($lines[$cursor])) {
        if (strlen(trim($lines[$cursor]))) {
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
    $lines = array();
    foreach (explode("\n", $text) as $line) {
      $lines[] = $this->applyRules(preg_replace('/^>\s*/', '', $line));
    }

    if ($this->getEngine()->isTextMode()) {
      return '> '.implode("\n> ", $lines);
    }

    return hsprintf(
      '<blockquote><p>%s</p></blockquote>',
      phutil_implode_html(phutil_tag('br'), $lines));
  }
}
