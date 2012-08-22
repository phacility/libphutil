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
 * @group testcase
 */
final class PhutilPHPFragmentLexerHighlighterTestCase
  extends ArcanistPhutilTestCase {

  public function testLexer() {
    $highlighter = new PhutilLexerSyntaxHighlighter();
    $highlighter->setConfig('language', 'php');
    $highlighter->setConfig('lexer', new PhutilPHPFragmentLexer());


    $path = dirname(__FILE__).'/phpfragment/';
    foreach (Filesystem::listDirectory($path, $include_hidden = false) as $f) {
      if (preg_match('/.test$/', $f)) {
        $expect = preg_replace('/.test$/', '.expect', $f);
        $source = Filesystem::readFile($path.'/'.$f);

        $this->assertEqual(
          Filesystem::readFile($path.'/'.$expect),
          $highlighter->getHighlightFuture($source)->resolve(),
          $f);
      }
    }
  }

}
