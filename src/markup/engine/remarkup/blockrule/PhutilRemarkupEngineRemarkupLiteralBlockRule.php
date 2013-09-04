<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngineRemarkupLiteralBlockRule
  extends PhutilRemarkupEngineMultiLineEnclosedBlockRule {

  public function getBlockSpecifier() {
    return '%%%';
  }

  public function markupText($text) {
    $spec = $this->getBlockSpecifier();
    $text = preg_replace("/{$spec}\s*$/", '', substr($text, 3));
    if ($this->getEngine()->isTextMode()) {
      return $text;
    }

    $text = phutil_split_lines($text, $retain_endings = true);
    return phutil_implode_html(phutil_tag('br', array()), $text);
  }

}
