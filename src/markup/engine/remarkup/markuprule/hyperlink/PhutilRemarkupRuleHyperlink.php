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

class PhutilRemarkupRuleHyperlink
  extends PhutilRemarkupRule {

  public function apply($text) {

    $text = preg_replace_callback(
      '@[<](\w{3,}://.+?)[>]@',
      array($this, 'markupHyperlink'),
      $text);

    $text = preg_replace_callback(
      '@(?<=^|\s)(\w{3,}://\S+)(?=\s|$)@',
      array($this, 'markupHyperlinkUngreedy'),
      $text);

    return $text;
  }

  public function markupHyperlink($matches) {
    return $this->getEngine()->storeText(
      phutil_render_tag(
        'a',
        array(
          'href'    => $matches[1],
          'target'  => '_blank',
        ),
        phutil_escape_html($matches[1])));
  }

  public function markupHyperlinkUngreedy($matches) {
    $match = $matches[1];
    $tail = null;
    $trailing = null;
    if (preg_match('/[;,.:!?]+$/', $match, $trailing)) {
      $tail = $trailing[0];
      $match = substr($match, 0, -strlen($tail));
    }
    return $this->markupHyperlink(array(null, $match)).$tail;
  }

}
