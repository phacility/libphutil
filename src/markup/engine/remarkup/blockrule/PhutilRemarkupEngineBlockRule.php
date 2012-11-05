<?php

/**
 * @group markup
 * @stable
 */
abstract class PhutilRemarkupEngineBlockRule {

  private $engine;
  private $rules = array();

  abstract public function getBlockPattern();
  abstract public function shouldMergeBlocks();
  abstract public function markupText($text);

  protected function didMarkupText() {
    return;
  }

  public function shouldMatchBlock($block) {
    return preg_match($this->getBlockPattern(), $block);
  }

  public function shouldContinueWithBlock($block, $last_block) {
    return false;
  }

  final public function setEngine(PhutilRemarkupEngine $engine) {
    $this->engine = $engine;
    return $this;
  }

  final protected function getEngine() {
    return $this->engine;
  }

  public function setMarkupRules(array $rules) {
    assert_instances_of($rules, 'PhutilRemarkupRule');
    $this->rules = $rules;
    return $this;
  }

  final private function getMarkupRules() {
    return $this->rules;
  }

  final public function postprocess() {
    $engine = $this->getEngine();
    $this->didMarkupText();
    foreach ($this->getMarkupRules() as $rule) {
      $rule->setEngine($engine);
      $rule->didMarkupText();
    }
  }

  final protected function applyRules($text) {
    $engine = $this->getEngine();
    foreach ($this->getMarkupRules() as $rule) {
      $rule->setEngine($engine);
      $text = $rule->apply($text);
    }
    return $text;
  }


}
