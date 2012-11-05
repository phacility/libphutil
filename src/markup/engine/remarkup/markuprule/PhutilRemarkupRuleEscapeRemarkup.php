<?php

/**
 * @group markup
 */
final class PhutilRemarkupRuleEscapeRemarkup
  extends PhutilRemarkupRule {

  public function apply($text) {
    if (strpos($text, "\1") === false) {
      return $text;
    }

    $replace = $this->getEngine()->storeText("\1");

    return str_replace("\1", $replace, $text);
  }

}
