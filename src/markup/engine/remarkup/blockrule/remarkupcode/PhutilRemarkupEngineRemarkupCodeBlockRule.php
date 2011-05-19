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
class PhutilRemarkupEngineRemarkupCodeBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getBlockPattern() {
    return "/^\s{2,}/";
  }

  public function shouldMatchBlock($block) {
    if (!preg_match($this->getBlockPattern(), $block)) {
      return false;
    }

    if (preg_match('@^[a-z]+://\S+$@', trim($block))) {
      return false;
    }

    return true;
  }

  public function shouldMergeBlocks() {
    return true;
  }

  public function markupText($text) {
    $lines = explode("\n", $text);

    $lang = 'php';
    $aux_class = '';
    do {
      $first_line = reset($lines);

      $matches = null;
      if (preg_match('/^\s{2,}lang\s*=\s*(.*)$/i', $first_line, $matches)) {
        $lang = $matches[1];
        array_shift($lines);
        continue;
      }

      if (preg_match('/^\s{2,}COUNTEREXAMPLE$/i', $first_line, $matches)) {
        $aux_class = ' remarkup-counterexample';
        array_shift($lines);
        continue;
      }

    } while (false);

    // Normalize the text back to a 0-level indent.
    $min_indent = 80;
    foreach ($lines as $line) {
      for ($ii = 0; $ii < strlen($line); $ii++) {
        if ($line[$ii] != ' ') {
          $min_indent = min($ii, $min_indent);
          break;
        }
      }
    }
    if ($min_indent) {
      $indent_string = str_repeat(' ', $min_indent);
      $text = preg_replace(
        '/^'.$indent_string.'/m',
        '',
        implode("\n", $lines));
    }

    $engine = new PhutilDefaultSyntaxHighlighterEngine();
    $engine->setConfig(
      'pygments.enabled',
      $this->getEngine()->getConfig('pygments.enabled'));
    return
      '<code class="remarkup-code'.$aux_class.'">'.
        $engine->highlightSource($lang, $text).
      '</code>';
  }
}
