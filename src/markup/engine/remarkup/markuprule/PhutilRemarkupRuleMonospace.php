<?php

/**
 * @group markup
 */
final class PhutilRemarkupRuleMonospace
  extends PhutilRemarkupRule {

  public function apply($text) {
    // NOTE: We don't require a trailing non-boundary on the backtick syntax,
    // to permit the use case of naming and pluralizing a class, like
    // "Load all the `PhutilArray`s and then iterate over them." In theory, the
    // required \B on the leading backtick should protect us from most
    // collateral damage.

    return preg_replace_callback(
      '@##([\s\S]+?)##|\B`(.+?)`@',
      array($this, 'markupMonospacedText'),
      $text);
  }

  private function markupMonospacedText($matches) {
    $match = isset($matches[2]) ? $matches[2] : $matches[1];

    $result = '<tt>'.phutil_escape_html($match).'</tt>';

    return $this->getEngine()->storeText($result);
  }

}
