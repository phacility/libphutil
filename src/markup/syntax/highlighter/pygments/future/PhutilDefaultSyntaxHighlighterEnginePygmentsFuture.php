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
final class PhutilDefaultSyntaxHighlighterEnginePygmentsFuture
  extends FutureProxy {

  private $source;

  public function __construct(Future $proxied, $source) {
    parent::__construct($proxied);
    $this->source = $source;
  }

  protected function didReceiveResult($result) {
    list($err, $stdout, $stderr) = $result;

    if (!$err && strlen($stdout)) {
      // Strip off fluff Pygments adds.
      $stdout = preg_replace(
        '@^<div class="highlight"><pre>(.*)</pre></div>\s*$@s',
        '\1',
        $stdout);
      return $stdout;
    }

    throw new PhutilSyntaxHighlighterException($stderr, $err);
  }

}
