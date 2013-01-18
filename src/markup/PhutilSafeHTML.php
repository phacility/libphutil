<?php

final class PhutilSafeHTML {

  private $content;

  public function __construct($content) {
    $this->content = $content;
  }

  public function __toString() {
    return $this->getHTMLContent();
  }

  public function getHTMLContent() {
    return (string)$this->content;
  }

}
