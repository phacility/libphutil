<?php

final class PhutilDefaultSyntaxHighlighter {

  public function setConfig($key, $value) {
    return $this;
  }

  public function getHighlightFuture($source) {
    $result = hsprintf('%s', $source);
    return new ImmediateFuture($result);
  }

}
