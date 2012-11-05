<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngineRemarkupInlineBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getBlockPattern() {
    return "/.*/";
  }

  public function shouldMergeBlocks() {
    return true;
  }

  public function markupText($text) {
    return $this->applyRules($text);
  }

}
