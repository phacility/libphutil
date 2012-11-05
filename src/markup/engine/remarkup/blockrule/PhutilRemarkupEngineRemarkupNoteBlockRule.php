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
    return
      '<div class="remarkup-note">'.
        $this->applyRules($text).
      '</div>';
  }
}
