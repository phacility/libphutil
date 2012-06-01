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
 * Test cases for @{class:PhutilDocblockParser}.
 *
 * @group testcase
 */
final class PhutilDocblockParserTestCase extends ArcanistPhutilTestCase {

  public function testParser() {
    $root = dirname(__FILE__).'/docblock/';
    foreach (Filesystem::listDirectory($root, $hidden = false) as $file) {
      $this->parseDocblock($root.$file);
    }
  }

  private function parseDocblock($doc_file) {
    $contents = Filesystem::readFile($doc_file);
    $file = basename($doc_file);

    $parser = new PhutilDocblockParser();
    list($docblock, $specials) = $parser->parse($contents);

    switch ($file) {
      case 'embedded-specials.docblock':
        $this->assertEqual(array(), $specials);
        $this->assertEqual(
          "So long as a @special does not appear at the beginning of a line,\n".
          "it is parsed as normal text.",
          $docblock);
        break;
      case 'indented-block.docblock':
        $this->assertEqual(array(), $specials);
        $this->assertEqual(
          "Cozy lummox gives smart squid who asks for job pen.",
          $docblock);
        break;
      case 'indented-text.docblock':
        $this->assertEqual(array(), $specials);
        $this->assertEqual(
          "Cozy lummox gives smart squid who asks for job pen.",
          $docblock);
        break;
      case 'multiline-special.docblock':
        $this->assertEqual(
          array(
            'special' => "x y z",
          ),
          $specials);
        $this->assertEqual(
          "",
          $docblock);
        break;
      case 'multi-specials.docblock':
        $this->assertEqual(
          array(
            'special' => "north\nsouth",
          ),
          $specials);
        $this->assertEqual(
          "",
          $docblock);
        break;
      case 'specials.docblock':
        $this->assertEqual(
          array(
            'type' => 'type',
            'task' => 'task',
          ),
          $specials);
        $this->assertEqual(
          "",
          $docblock);
        break;
      case 'linebreak-breaks-specials.docblock':
        $this->assertEqual(
          array(
            'title' => 'title',
          ),
          $specials);
        $this->assertEqual(
          "This is normal text, not part of the @title.",
          $docblock);
        break;
      case 'specials-with-hyphen.docblock':
        $this->assertEqual(
          array(
            'repeat-hyphen'     => "a\nb",
            'multiline-hyphen'  => "mmm nnn",
            'normal-hyphen'     => "x",
          ),
          $specials);
        break;
      case 'indented-specials.docblock':
        $this->assertEqual(
          array(
            'title' => 'sendmail',
          ),
          $specials);
        break;
      case 'flag-specials.docblock':
        $this->assertEqual(
          "stuff above\n\nstuff in the middle\n\nstuff below",
          $docblock);
        $this->assertEqual(
          array(
            'flag' => true,
            'stuff' => true,
            'zebra' => true,
            'apple' => true,
          ),
          $specials);
        break;
      default:
        throw new Exception("No test case to handle file '{$file}'!");
    }
  }
}
