<?php

/**
 * @group markup
 */
final class PhutilRemarkupRuleBold
  extends PhutilRemarkupRule {

  public function apply($text) {
    return $this->replaceHTML(
      '@\\*\\*(.+?)\\*\\*@s',
      array($this, 'applyCallback'),
      $text);
  }

  protected function applyCallback($matches) {
    return hsprintf('<strong>%s</strong>', $matches[1]);
  }

}
