<?php

/**
 * @group markup
 * @stable
 */
abstract class PhutilRemarkupRule {

  private $engine;

  public function setEngine(PhutilRemarkupEngine $engine) {
    $this->engine = $engine;
    return $this;
  }

  public function getEngine() {
    return $this->engine;
  }

  abstract public function apply($text);

  public function didMarkupText() {
    return;
  }
}
