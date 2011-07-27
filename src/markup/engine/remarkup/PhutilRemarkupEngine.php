<?php

/*
 * Copyright 2011 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


/**
 * @group markup
 */
final class PhutilRemarkupEngine extends PhutilMarkupEngine {

  private $blockRules = array();
  private $config = array();
  private $metadata = array();

  public function setConfig($key, $value) {
    $this->config[$key] = $value;
    return $this;
  }

  public function getConfig($key, $default = null) {
    return idx($this->config, $key, $default);
  }

  public function setBlockRules(array $rules) {
    $this->blockRules = $rules;
    return $this;
  }

  public function getTextMetadata($key, $default = null) {
    return idx($this->metadata, $key, $default);
  }

  public function setTextMetadata($key, $value) {
    $this->metadata[$key] = $value;
    return $this;
  }

  public function storeText($text) {
    return $this->storage->store($text);
  }

  public function overwriteStoredText($token, $new_text) {
    $this->storage->overwrite($token, $new_text);
    return $this;
  }

  public function markupText($text) {
    return $this->postProcessText($this->preprocessText($text));
  }

  private function setupProcessing() {
    $this->metadata = array();
    $this->storage = new PhutilRemarkupBlockStorage();

    $block_rules = $this->blockRules;
    if (empty($block_rules)) {
      throw new Exception("Remarkup engine not configured with block rules.");
    }
    foreach ($block_rules as $rule) {
      $rule->setEngine($this);
    }
  }

  public function preprocessText($text) {
    $this->setupProcessing();

    // Apply basic block and paragraph normalization to the text.
    $text = preg_replace("/\r\n?/", "\n", $text);
    $text = preg_replace("/[ \t]*$/m", '', $text);
    $text = preg_split("/\n\n/", $text);

    $block_rules = $this->blockRules;

    $blocks = array();
    $last   = null;
    foreach ($text as $block) {
      $match = false;
      foreach ($block_rules as $key => $block_rule) {
        if (!$block_rule->shouldMatchBlock(trim($block, "\n"))) {
          continue;
        }
        if (($last !== null) &&
            ($key == $last) &&
            $block_rule->shouldMergeBlocks()) {
          end($blocks);
          $last_block_key = key($blocks);
          $blocks[$last_block_key]['block'] .= "\n\n".$block;
        } else {
          $blocks[] = array(
            'rule'  => $block_rule,
            'block' => $block,
          );
        }
        $last = $key;
        $match = true;
        break;
      }
      if (!$match) {
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

    return array(
      'output'    => implode("\n\n", $output),
      'storage'   => $map,
      'metadata'  => $metadata,
    );
  }

  public function postprocessText(array $dict) {
    $this->setupProcessing();

    $this->metadata = idx($dict, 'metadata', array());
    $this->storage->setMap(idx($dict, 'storage', array()));

    foreach ($this->blockRules as $block_rule) {
      $block_rule->postprocess();
    }

    return $this->storage->restore(idx($dict, 'output'));
  }
}
