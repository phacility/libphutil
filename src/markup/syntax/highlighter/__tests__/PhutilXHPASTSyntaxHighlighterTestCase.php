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
final class PhutilXHPASTSyntaxHighlighterTestCase
  extends ArcanistPhutilTestCase {

  private function highlight($source) {
    $highlighter = new PhutilXHPASTSyntaxHighlighter();
    $future = $highlighter->getHighlightFuture($source);
    return $future->resolve();
  }

  private function read($file) {
    $path = dirname(__FILE__).'/xhpast/'.$file;
    return Filesystem::readFile($path);
  }

  public function testBuiltinClassnames() {
    $this->assertEqual(
      $this->read('builtin-classname.expect'),
      $this->highlight($this->read('builtin-classname.source')),
      'Builtin classnames should not be marked as linkable symbols.');
    $this->assertEqual(
      $this->read('trailing-comment.expect'),
      $this->highlight($this->read('trailing-comment.source')),
      'Trailing comments should not be dropped.');
  }

}
