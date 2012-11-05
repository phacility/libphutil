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
      $lines[] = $this->applyRules(preg_replace('/^>/', '', $line));
    }
    return '<blockquote>'.implode('<br />', $lines).'</blockquote>';
  }
}
