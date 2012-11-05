<?php

/**
 * @group markup
 */
final class PhutilRemarkupRuleDel
  extends PhutilRemarkupRule {

  public function apply($text) {
    return preg_replace(
      '@(?<!~)~~([^\s~].*?~*)~~@s',
      '<del>\1</del>',
      $text);
  }

}
