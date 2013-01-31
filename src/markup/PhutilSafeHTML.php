<?php

final class PhutilSafeHTML {

  private $content;

  public function __construct($content) {
    $this->content = (string)$content;
  }

  public function __toString() {
    return $this->getHTMLContent();
  }

  public function getHTMLContent() {
    return $this->content;
  }

  public function appendHTML($html /* , ... */) {
    foreach (func_get_args() as $html) {
      $this->content .= phutil_escape_html($html);
    }
    return $this;
  }

}
