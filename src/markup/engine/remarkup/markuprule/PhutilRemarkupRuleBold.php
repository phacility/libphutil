<?php

/**
 * @group markup
 */
final class PhutilRemarkupRuleBold
  extends PhutilRemarkupRule {

  public function apply($text) {
    if ($this->getEngine()->isTextMode()) {
      return $text;
    }

    return $this->replaceHTML(
      '@\\*\\*(.+?)\\*\\*@s',
      array($this, 'applyCallback'),
      $text);
  }

  protected function applyCallback($matches) {
    return hsprintf('<strong>%s</strong>', $matches[1]);
  }

}
