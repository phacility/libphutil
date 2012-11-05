<?php

/**
 * @group markup
 */
final class PhutilRemarkupRuleEscapeHTML
  extends PhutilRemarkupRule {

  public function apply($text) {
    return phutil_escape_html($text);
  }

}
