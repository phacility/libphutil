<?php

/**
 * @group markup
 */
final class PhutilRemarkupRuleBold
  extends PhutilRemarkupRule {

  public function apply($text) {
    return preg_replace(
      '@\\*\\*(.+?)\\*\\*@s',
      '<strong>\1</strong>',
      $text);
  }

}
