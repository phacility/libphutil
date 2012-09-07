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
 * Test cases for @{class:PhutilDefaultSyntaxHighlighterEngine}.
 *
 * @group testcase
 */
final class PhutilDefaultSyntaxHighlighterEngineTestCase
  extends PhutilTestCase {

  public function testFilenameGreediness() {
    $names = array(
      'x.php'       => 'php',
      '/x.php'      => 'php',
      'x.y.php'     => 'php',
      '/x.y/z.php'  => 'php',
      '/x.php/'     => null,
    );

    $engine = new PhutilDefaultSyntaxHighlighterEngine();
    foreach ($names as $path => $language) {
      $detect = $engine->getLanguageFromFilename($path);
      $this->assertEqual($language, $detect, 'Language detect for '.$path);
    }
  }

}
