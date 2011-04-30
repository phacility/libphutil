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
class PhutilDefaultSyntaxHighlighterEngine
  extends PhutilSyntaxHighlighterEngine {

  private $config = array();

  public function setConfig($key, $value) {
    $this->config[$key] = $value;
    return $this;
  }

  public function highlightSource($name, $source) {

    $name = explode('.', $name);
    $lang = end($name);

    try {
      switch ($lang) {
        case 'php':
          return id(new PhutilXHPASTSyntaxHighlighter())
            ->highlightSource($source);
        default:
          if (!empty($this->config['pygments.enabled'])) {
            $future = new ExecFuture('pygmentize -f html -l %s', $lang);
            $future->write($source);
            list($err, $stdout, $stderr) = $future->resolve();
            if (!$err && strlen($stdout)) {
              // Strip off fluff Pygments adds.
              $stdout = preg_replace(
                '@^<div class="highlight"><pre>(.*)</pre></div>\s*$@s',
                '\1',
                $stdout);
              return $stdout;
            }
          }
          return phutil_escape_html($source);
      }
    } catch (Exception $ex) {
      return phutil_escape_html($source);
    }
  }
}
