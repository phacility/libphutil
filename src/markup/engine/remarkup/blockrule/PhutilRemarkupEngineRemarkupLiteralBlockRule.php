<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngineRemarkupLiteralBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getBlockPattern() {
    return "/^%%%/";
  }

  public function shouldContinueWithBlock($block, $last_block) {
    // If the first code block begins with %%%, we keep matching blocks until
    // we hit a terminating %%%, regardless of their content.
    if (preg_match($this->getBlockPattern(), $last_block)) {
      if (preg_match('/%%%$/', $last_block)) {
        return false;
      }
      return true;
    }

    return false;
  }

  public function shouldMergeBlocks() {
    return true;
  }

  public function markupText($text) {
    $text = preg_replace('/%%%\s*$/', '', substr($text, 3));
    $text = $this->applyRules($text);
    return $text;
  }
}
