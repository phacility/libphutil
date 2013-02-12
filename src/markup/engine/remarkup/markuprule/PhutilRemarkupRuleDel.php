<?php

/**
 * @group markup
 */
final class PhutilRemarkupRuleDel
  extends PhutilRemarkupRule {

  public function apply($text) {
    return $this->replaceHTML(
      '@(?<!~)~~([^\s~].*?~*)~~@s',
      array($this, 'applyCallback'),
      $text);
  }

  protected function applyCallback($matches) {
    return hsprintf('<del>%s</del>', $matches[1]);
  }

}
