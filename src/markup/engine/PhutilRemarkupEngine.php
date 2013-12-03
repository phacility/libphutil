<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngine extends PhutilMarkupEngine {

  const MODE_DEFAULT = 0;
  const MODE_TEXT = 1;

  /**
   * @var PhutilRemarkupEngineBlockRule[]
   */
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

    $rules = msort($rules, 'getPriority');

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
    $text        = phutil_split_lines($text, true);
    $block_rules = $this->blockRules;
    $blocks      = array();
    $cursor      = 0;
    $prev_block  = array();

    while (isset($text[$cursor])) {
      $starting_cursor = $cursor;
      foreach ($block_rules as $block_rule) {
        $num_lines = $block_rule->getMatchingLineCount($text, $cursor);

        if ($num_lines) {
          if ($blocks) {
            $prev_block = last($blocks);
          }

          $curr_block = array(
            "start" => $cursor,
            "num_lines" => $num_lines,
            "rule" => $block_rule,
            "is_empty" => self::isEmptyBlock($text, $cursor, $num_lines),
          );

          if ($prev_block
            && self::shouldMergeBlocks($text, $prev_block, $curr_block)) {
            $blocks[last_key($blocks)]["num_lines"] += $curr_block["num_lines"];
            $blocks[last_key($blocks)]["is_empty"] =
              $blocks[last_key($blocks)]["is_empty"] && $curr_block["is_empty"];
          } else {
            $blocks[] = $curr_block;
          }

          $cursor += $num_lines;
          break;
        }
      }

      if ($starting_cursor === $cursor) {
        throw new Exception("Block in text did not match any block rule.");
      }
    }

    $output = array();
    foreach ($blocks as $block) {
      $output[] = $block['rule']->markupText(
        implode('', array_slice($text, $block['start'], $block['num_lines'])));
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

  private static function shouldMergeBlocks($text, $prev_block, $curr_block) {
    $block_rules = ipull(array($prev_block, $curr_block), "rule");

    $default_rule = "PhutilRemarkupEngineRemarkupDefaultBlockRule";
    try {
      assert_instances_of($block_rules, $default_rule);

      // If the last block was empty keep merging
      if ($prev_block['is_empty']) {
        return true;
      }

      // If this line is blank keep merging
      if ($curr_block['is_empty']) {
        return true;
      }

      // If the current line and the last line have content, keep merging
      if (strlen(trim($text[$curr_block["start"] - 1]))) {
        if (strlen(trim($text[$curr_block["start"]]))) {
          return true;
        }
      }
    } catch (Exception $e) {

    }

    return false;
  }

  private static function isEmptyBlock($text, $start, $num_lines) {
    for ($cursor = $start; $cursor < $start + $num_lines; $cursor++) {
      if (strlen(trim($text[$cursor]))) {
        return false;
      }
    }
    return true;
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

    return $this->restoreText(idx($dict, 'output'), $this->isTextMode());
  }

  public function restoreText($text) {
    return $this->storage->restore($text, $this->isTextMode());
  }
}
