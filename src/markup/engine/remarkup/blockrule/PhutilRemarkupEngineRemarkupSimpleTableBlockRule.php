<?php

/*
 * Copyright 2012 Facebook, Inc.
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
final class PhutilRemarkupEngineRemarkupSimpleTableBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getBlockPattern() {
    return '/^(\|.*+\n?)+$/';
  }

  public function shouldMergeBlocks() {
    return false;
  }

  public function markupText($text) {
    $matches = array();

    $rows = array();
    foreach (explode("\n", $text) as $line) {
      // Ignore ending delimiters.
      $line = rtrim($line, '|');

      preg_match_all('/\|([^|]*)/', $line, $matches);
      $headings = true;
      $cells = array();
      foreach ($matches[1] as $cell) {
        $cell = trim($cell);

        // Cell isn't empty and doesn't look like heading.
        if (!preg_match('/^(|--+)$/', $cell)) {
          $headings = false;
        }
        $cells[] = array('type' => 'td', 'content' => $cell);
      }

      if (!$headings) {
        $rows[] = $cells;
      } else if ($rows) {
        // Mark previous row with headings.
        foreach ($cells as $i => $cell) {
          if ($cell['content']) {
            $rows[last_key($rows)][$i]['type'] = 'th';
          }
        }
      }
    }

    if (!$rows) {
      return $this->applyRules($text);
    }

    $out = array();
    $out[] = "<table class=\"remarkup-table\">\n";
    foreach ($rows as $cells) {
      $out[] = '<tr>';
      foreach ($cells as $cell) {
        $out[] = '<'.$cell['type'].'>';
        $out[] = $this->applyRules($cell['content']);
        $out[] = '</'.$cell['type'].'>';
      }
      $out[] = "</tr>\n";
    }
    $out[] = "</table>\n";

    return implode($out);
  }

}
