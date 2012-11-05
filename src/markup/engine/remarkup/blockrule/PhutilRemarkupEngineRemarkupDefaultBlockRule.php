<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngineRemarkupDefaultBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getBlockPattern() {
    return "/.*/";
  }

  public function shouldMergeBlocks() {
    return false;
  }

  public function markupText($text) {
    $text = $this->applyRules($text);

    $lines = explode("\n", trim($text));

    $implode_on = $this->getEngine()->getConfig('preserve-linebreaks')
      ? '<br />'
      : '';

    return '<p>'.trim(implode($implode_on."\n", $lines)).'</p>';
  }

}
