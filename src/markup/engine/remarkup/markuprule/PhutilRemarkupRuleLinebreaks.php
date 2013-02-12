<?php

/**
 * @group markup
 */
final class PhutilRemarkupRuleLinebreaks
  extends PhutilRemarkupRule {

  public function apply($text) {
    return phutil_escape_html_newlines($text);
  }

}
