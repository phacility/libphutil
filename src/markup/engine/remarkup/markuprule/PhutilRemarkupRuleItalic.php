<?php

/**
 * @group markup
 */
final class PhutilRemarkupRuleItalic
  extends PhutilRemarkupRule {

  public function apply($text) {
    return preg_replace(
      '@(?<!:)//(.+?)//@s',
      '<em>\1</em>',
      $text);
  }

}
