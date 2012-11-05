<?php

/**
 * @group markup
 */
final class PhutilDefaultSyntaxHighlighter {

  public function setConfig($key, $value) {
    return $this;
  }

  public function getHighlightFuture($source) {
    $result = phutil_escape_html($source);
    return new ImmediateFuture($result);
  }
}
