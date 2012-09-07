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
final class PhutilConsoleWrapTestCase extends PhutilTestCase {

  public function testWrap() {
    $dir = dirname(__FILE__).'/wrap/';
    $files = Filesystem::listDirectory($dir);
    foreach ($files as $file) {
      if (preg_match('/.txt$/', $file)) {
        $this->assertEqual(
          Filesystem::readFile($dir.$file.'.expect'),
          phutil_console_wrap(Filesystem::readFile($dir.$file)),
          $file);
      }
    }
  }

  public function testConsoleWrap() {
    $this->assertEqual(
        phutil_console_format(
          "<bg:red>** ERROR **</bg> abc abc abc abc abc abc abc abc abc abc ".
          "abc abc abc abc abc abc abc\nabc abc abc abc abc abc abc abc abc ".
          "abc abc!"),
      phutil_console_wrap(
        phutil_console_format(
          "<bg:red>** ERROR **</bg> abc abc abc abc abc abc abc abc abc abc ".
          "abc abc abc abc abc abc abc abc abc abc abc abc abc abc abc abc ".
          "abc abc!")),
      'ANSI escape sequences should not contribute toward wrap width.');
  }

  public function testWrapIndent() {
    $turtles = <<<EOTURTLES
                    turtle turtle turtle turtle turtle turtle turtle turtle
                    turtle turtle turtle turtle turtle turtle turtle turtle
                    turtle turtle turtle turtle
EOTURTLES;

    $this->assertEqual(
      $turtles,
      phutil_console_wrap(
        rtrim(str_repeat('turtle ', 20)),
        $indent = 20));
  }


}
