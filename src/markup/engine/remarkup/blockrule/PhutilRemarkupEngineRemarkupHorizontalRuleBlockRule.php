<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngineRemarkupHorizontalRuleBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getBlockPattern() {
    return "/^_{3,}$|^\*\s?\*\s?\*(\s|\*)*$|^\-\s?\-\s?\-(\s|\-)*$/";
  }

  public function shouldMergeBlocks() {
    return false;
  }

  public function markupText($text) {
    return phutil_tag('hr', array());
  }


}
