<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngineRemarkupQuotesBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getBlockPattern() {
    return "/^>/";
  }

  public function shouldMergeBlocks() {
    return false;
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
