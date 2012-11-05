<?php

/**
 * @group markup
 */
final class PhutilRemarkupRuleLinebreaks
  extends PhutilRemarkupRule {

  public function apply($text) {
    return str_replace(
      "\n",
      "<br />\n",
      $text);
  }

}
