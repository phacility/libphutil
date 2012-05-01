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

final class PhutilDeferredLogTestCase extends ArcanistPhutilTestCase {

  public function testLogging() {
    $this->checkLog(
      "derp\n",
      "derp",
      array());

    $this->checkLog(
      "[20 Aug 1984] alincoln\n",
      "[%T] %u",
      array(
        'T' => '20 Aug 1984',
        'u' => 'alincoln',
      ));

    $this->checkLog(
      "%%%%%\n",
      "%%%%%%%%%%",
      array(
        '%' => '%',
      ));

    $this->checkLog(
      "\\000\\001\\002\n",
      "%a%b%c",
      array(
        'a' => chr(0),
        'b' => chr(1),
        'c' => chr(2),
      ));

    $this->checkLog(
      "Download: 100%\n",
      "Download: %C",
      array(
        'C' => '100%',
      ));

    $this->checkLog(
      "- bee -\n",
      "%a %b %c",
      array(
        'b' => 'bee',
      ));

    $this->checkLog(
      "\\\\\n",
      "%b",
      array(
        'b' => '\\',
      ));

    $this->checkLog(
      "a\t\\t\n",
      "%a\t%b",
      array(
        'a' => 'a',
        'b' => "\t",
      ));

    $this->checkLog(
      "\\001ab\n",
      "\1a%a",
      array(
        'a' => 'b',
      ));

  }

  public function testLogWriteFailure() {
    $caught = null;
    try {
      $log = new PhutilDeferredLog('/derp/derp/derp/derp/derp', 'derp');
      if (phutil_is_hiphop_runtime()) {
        // In HipHop exceptions thrown in destructors are not normally
        // catchable, so call __destruct() explicitly.
        $log->__destruct();
      }
    } catch (Exception $ex) {
      $caught = $ex;
    }
    $this->assertEqual(true, $caught instanceof Exception);
  }

  public function testManyWriters() {
    $root = phutil_get_library_root('phutil').'/../';
    $bin = $root.'scripts/test/deferred_log.php';

    $n_writers = 3;
    $n_lines   = 8;

    $tmp = new TempFile();

    $futures = array();
    for ($ii = 0; $ii < $n_writers; $ii++) {
      $futures[] = new ExecFuture("%s %d %s", $bin, $n_lines, (string)$tmp);
    }

    Futures($futures)->resolveAll();

    $this->assertEqual(
      str_repeat("abcdefghijklmnopqrstuvwxyz\n", $n_writers * $n_lines),
      Filesystem::readFile($tmp));
  }


  private function checkLog($expect, $format, $data) {
    $tmp = new TempFile();

    $log = new PhutilDeferredLog($tmp, $format);
    $log->setData($data);
    unset($log);

    $this->assertEqual($expect, Filesystem::readFile($tmp), $format);
  }

}
