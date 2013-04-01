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
    $this->updateRules();
    return $this;
  }

  final protected function getEngine() {
    return $this->engine;
  }

  public function setMarkupRules(array $rules) {
    assert_instances_of($rules, 'PhutilRemarkupRule');
    $this->rules = $rules;
    $this->updateRules();
    return $this;
  }

  private function updateRules() {
    $engine = $this->getEngine();
    if ($engine) {
      foreach ($this->rules as $rule) {
        $rule->setEngine($engine);
      }
    }
    return $this;
  }

  final public function getMarkupRules() {
    return $this->rules;
  }

  final public function postprocess() {
    $this->didMarkupText();
  }

  final protected function applyRules($text) {
    foreach ($this->getMarkupRules() as $rule) {
      $text = $rule->apply($text);
    }
    return $text;
  }

  protected function renderRemarkupTable(array $out_rows) {
    assert_instances_of($out_rows, 'array');

    if ($this->getEngine()->isTextMode()) {
      $lengths = array();
      foreach ($out_rows as $r => $row) {
        foreach ($row['content'] as $c => $cell) {
          $text = $this->getEngine()->restoreText($cell['content']);
          $lengths[$c][$r] = phutil_utf8_strlen($text);
        }
      }
      $max_lengths = array_map('max', $lengths);

      $out = array();
      foreach ($out_rows as $r => $row) {
        $headings = false;
        foreach ($row['content'] as $c => $cell) {
          $length = $max_lengths[$c] - $lengths[$c][$r];
          $out[] = '| '.$cell['content'].str_repeat(' ', $length).' ';
          if ($cell['type'] == 'th') {
            $headings = true;
          }
        }
        $out[] = "|\n";

        if ($headings) {
          foreach ($row['content'] as $c => $cell) {
            $char = ($cell['type'] == 'th' ? '-' : ' ');
            $out[] = '| '.str_repeat($char, $max_lengths[$c]).' ';
          }
          $out[] = "|\n";
        }
      }

      return rtrim(implode('', $out), "\n");
    }

    $out = array();
    $out[] = "\n";
    foreach ($out_rows as $row) {
      $cells = array();
      foreach ($row['content'] as $cell) {
        $cells[] = phutil_tag($cell['type'], array(), $cell['content']);
      }
      $out[] = phutil_tag($row['type'], array(), $cells);
      $out[] = "\n";
    }

    return phutil_tag('table', array('class' => 'remarkup-table'), $out);
  }

}
