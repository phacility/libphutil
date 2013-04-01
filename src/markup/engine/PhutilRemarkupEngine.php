<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngine extends PhutilMarkupEngine {

  const MODE_DEFAULT = 0;
  const MODE_TEXT = 1;

  private $blockRules = array();
  private $config = array();
  private $mode;
  private $metadata = array();
  private $states = array();
  private $postprocessRules = array();

  public function setConfig($key, $value) {
    $this->config[$key] = $value;
    return $this;
  }

  public function getConfig($key, $default = null) {
    return idx($this->config, $key, $default);
  }

  public function setMode($mode) {
    $this->mode = $mode;
    return $this;
  }

  public function isTextMode() {
    return $this->mode & self::MODE_TEXT;
  }

  public function setBlockRules(array $rules) {
    assert_instances_of($rules, 'PhutilRemarkupEngineBlockRule');
    $this->blockRules = $rules;
    foreach ($this->blockRules as $rule) {
      $rule->setEngine($this);
    }

    $post_rules = array();
    foreach ($this->blockRules as $block_rule) {
      foreach ($block_rule->getMarkupRules() as $rule) {
        $key = $rule->getPostprocessKey();
        if ($key !== null) {
          $post_rules[$key] = $rule;
        }
      }
    }

    $this->postprocessRules = $post_rules;

    return $this;
  }

  public function getTextMetadata($key, $default = null) {
    if (isset($this->metadata[$key])) {
      return $this->metadata[$key];
    }
    return idx($this->metadata, $key, $default);
  }

  public function setTextMetadata($key, $value) {
    $this->metadata[$key] = $value;
    return $this;
  }

  public function storeText($text) {
    if ($this->isTextMode()) {
      $text = phutil_safe_html($text);
    }
    return $this->storage->store($text);
  }

  public function overwriteStoredText($token, $new_text) {
    if ($this->isTextMode()) {
      $new_text = phutil_safe_html($new_text);
    }
    $this->storage->overwrite($token, $new_text);
    return $this;
  }

  public function markupText($text) {
    return $this->postprocessText($this->preprocessText($text));
  }

  public function pushState($state) {
    if (empty($this->states[$state])) {
      $this->states[$state] = 0;
    }
    $this->states[$state]++;
    return $this;
  }

  public function popState($state) {
    if (empty($this->states[$state])) {
      throw new Exception("State '{$state}' pushed more than popped!");
    }
    $this->states[$state]--;
    if (!$this->states[$state]) {
      unset($this->states[$state]);
    }
    return $this;
  }

  public function getState($state) {
    return !empty($this->states[$state]);
  }

  public function preprocessText($text) {
    $this->metadata = array();
    $this->storage = new PhutilRemarkupBlockStorage();

    // Apply basic block and paragraph normalization to the text. NOTE: We don't
    // strip trailing whitespace because it is semantic in some contexts,
    // notably inlined diffs that the author intends to show as a code block.
    $text = preg_replace("/\r\n?/", "\n", $text);
    $text = preg_split("/\n\n/", $text);

    $block_rules = $this->blockRules;

    $blocks = array();
    $last = null;
    $last_block = null;
    foreach ($text as $block) {

      $action = null;
      if ($last !== null) {
        if ($block_rules[$last]->shouldContinueWithBlock($block, $last_block)) {
          $action = 'merge';
        }
      }

      if (!$action) {
        foreach ($block_rules as $key => $block_rule) {
          if (!$block_rule->shouldMatchBlock(trim($block, "\n"))) {
            continue;
          }
          if (($last !== null) &&
              ($key == $last) &&
              $block_rule->shouldMergeBlocks()) {
            $action = 'merge';
          } else {
            $action = 'append';
          }
          $last = $key;
          break;
        }
      }

      $last_block = $block;

      switch ($action) {
        case 'merge':
          end($blocks);
          $last_block_key = key($blocks);
          $blocks[$last_block_key]['block'] .= "\n\n".$block;
          $last_block = $blocks[$last_block_key]['block'];
          break;
        case 'append':
          $blocks[] = array(
            'rule'  => $block_rules[$last],
            'block' => $block,
          );
          break;
        default:
          throw new Exception("Block in text did not match any block rule.");
      }
    }

    $output = array();
    foreach ($blocks as $block) {
      $output[] = $block['rule']->markupText($block['block']);
    }

    $map = $this->storage->getMap();
    unset($this->storage);
    $metadata = $this->metadata;

    if ($this->isTextMode()) {
      $output = implode("\n\n", $output)."\n";
    } else {
      $output = phutil_implode_html("\n\n", $output);
    }

    return array(
      'output'    => $output,
      'storage'   => $map,
      'metadata'  => $metadata,
    );
  }

  public function postprocessText(array $dict) {
    $this->metadata = idx($dict, 'metadata', array());

    $this->storage = new PhutilRemarkupBlockStorage();
    $this->storage->setMap(idx($dict, 'storage', array()));

    foreach ($this->blockRules as $block_rule) {
      $block_rule->postprocess();
    }

    foreach ($this->postprocessRules as $rule) {
      $rule->didMarkupText();
    }

    return $this->restoreText(idx($dict, 'output'));
  }

  public function restoreText($text) {
    return $this->storage->restore($text);
  }
}
