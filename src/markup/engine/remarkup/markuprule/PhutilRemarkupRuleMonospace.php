<?php

/**
 * @group markup
 */
final class PhutilRemarkupRuleMonospace
  extends PhutilRemarkupRule {

  public function apply($text) {
    return preg_replace_callback(
      '@##([\s\S]+?)##|\B`(.+?)`\B@',
      array($this, 'markupMonospacedText'),
      $text);
  }

  private function markupMonospacedText($matches) {
    $match = isset($matches[2]) ? $matches[2] : $matches[1];

    $result = '<tt>'.phutil_escape_html($match).'</tt>';

    return $this->getEngine()->storeText($result);
  }

}
