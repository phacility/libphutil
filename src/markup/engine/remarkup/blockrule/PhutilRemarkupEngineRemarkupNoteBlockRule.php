<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngineRemarkupNoteBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getBlockPattern() {
    return "/^NOTE: /";
  }

  public function shouldMergeBlocks() {
    return false;
  }

  public function markupText($text) {
    return hsprintf(
      '<div class="remarkup-note">%s</div>',
      $this->applyRules($text));
  }
}
