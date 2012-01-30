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
final class PhutilRemarkupEngineRemarkupHeaderBlockRule
  extends PhutilRemarkupEngineBlockRule {

  const KEY_HEADER_TOC = 'headers.toc';

  public function getBlockPattern() {
    return '/^(={1,5})(.*?)\\1?\s*$/';
  }

  public function shouldMergeBlocks() {
    return false;
  }

  public function markupText($text) {
    $text = trim($text);

    $level = 1;
    for ($ii = 0; $ii < min(5, strlen($text)); $ii++) {
      if ($text[$ii] == '=') {
        ++$level;
      } else {
        break;
      }
    }
    $text = trim($text, ' =');

    $engine = $this->getEngine();
    $use_anchors = $engine->getConfig('header.generate-toc');

    $anchor = null;
    if ($use_anchors) {
      $anchor = $this->generateAnchor($level - 1, $text);
    }

    return '<h'.$level.'>'.$anchor.$this->applyRules($text).'</h'.$level.'>';
  }

  private function generateAnchor($level, $text) {
    $anchor = strtolower($text);
    $anchor = preg_replace('/[^a-z0-9]/', '-', $anchor);
    $anchor = preg_replace('/--+/', '-', $anchor);
    $anchor = trim($anchor, '-');
    $anchor = substr($anchor, 0, 24);
    $anchor = trim($anchor, '-');
    $base = $anchor;

    $key = self::KEY_HEADER_TOC;
    $engine = $this->getEngine();
    $anchors = $engine->getTextMetadata($key, array());

    $suffix = 1;
    while (!strlen($anchor) || isset($anchors[$anchor])) {
      $anchor = $base.'-'.$suffix;
      $anchor = trim($anchor, '-');
      $suffix++;
    }

    $anchors[$anchor] = array($level, $text);
    $engine->setTextMetadata($key, $anchors);

    return phutil_render_tag(
      'a',
      array(
        'name' => $anchor,
      ),
      '');
  }

  public static function renderTableOfContents(PhutilRemarkupEngine $engine) {

    $key = self::KEY_HEADER_TOC;
    $anchors = $engine->getTextMetadata($key, array());

    if (count($anchors) < 2) {
      // Don't generate a TOC if there are no headers, or if there's only
      // one header (since such a TOC would be silly).
      return null;
    }

    $depth = 0;
    $toc = array();
    foreach ($anchors as $anchor => $info) {
      list($level, $name) = $info;

      while ($depth < $level) {
        $toc[] = '<ul>';
        $depth++;
      }
      while ($depth > $level) {
        $toc[] = '</ul>';
        $depth--;
      }

      $toc[] = phutil_render_tag(
        'li',
        array(),
        phutil_render_tag(
          'a',
          array(
            'href' => '#'.$anchor,
          ),
          phutil_escape_html($name)));
    }
    while ($depth > 0) {
      $toc[] = '</ul>';
      $depth--;
    }

    return implode("\n", $toc);
  }

}
