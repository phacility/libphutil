<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngineRemarkupInlineBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getMatchingLineCount(array $lines, $cursor) {
    return 1;
  }

  public function markupText($text) {
    return $this->applyRules($text);
  }

}
