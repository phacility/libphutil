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
 * Highlights source code with a rainbow of colors, regardless of the language.
 * This highlighter is useless, absurd, and extremely slow.
 *
 * @group markup
 */
final class PhutilRainbowSyntaxHighlighter {

  private $config = array();

  public function setConfig($key, $value) {
    $this->config[$key] = $value;
    return $this;
  }

  public function getHighlightFuture($source) {

    $color = 0;
    $colors = array(
      'rbw_r',
      'rbw_o',
      'rbw_y',
      'rbw_g',
      'rbw_b',
      'rbw_i',
      'rbw_v',
    );

    $result = array();
    foreach (phutil_utf8v($source) as $character) {
      if ($character == ' ' || $character == "\n") {
        $result[] = $character;
        continue;
      }
      $result[] =
        '<span class="'.$colors[$color].'">'.
          phutil_escape_html($character).
        '</span>';
      $color = ($color + 1) % count($colors);
    }

    $result = implode('', $result);
    return new ImmediateFuture($result);
  }
}
