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
 * Simple syntax highlighter for the ".diviner" format, which is just Remarkup
 * with a specific ruleset. This should also work alright for Remarkup.
 *
 * @group markup
 */
class PhutilDivinerSyntaxHighlighter {

  private $config = array();

  public function setConfig($key, $value) {
    $this->config[$key] = $value;
    return $this;
  }

  public function getHighlightFuture($source) {

    $source = phutil_escape_html($source);

    // This highlighter isn't perfect but tries to do an okay job at getting
    // some of the basics at least. There's lots of room for improvement.

    // Highlight "@{class:...}" links to other documentation pages.
    $source = $this->highlightPattern('/@{([\w@]+?):([^}]+?)}/', $source, 'nc');

    // Highlight "@title", "@group", etc.
    $source = $this->highlightPattern('/^@(\w+)/m', $source, 'k');

    // Highlight bold, italic and monospace.
    $source = $this->highlightPattern('@\\*\\*(.+?)\\*\\*@s', $source, 's');
    $source = $this->highlightPattern('@(?<!:)//(.+?)//@s', $source, 's');
    $source = $this->highlightPattern('@##(.+?)##@s', $source, 's');

    // Highlight stuff that looks like headers.
    $source = $this->highlightPattern('/^=(.*)$/m', $source, 'nv');

    return new ImmediateFuture($source);
  }

  private function highlightPattern($regexp, $source, $class) {
    $source = preg_replace(
      $regexp,
      '<span class="'.$class.'">\\0</span>',
      $source);

    return $source;
  }
}
