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

final class PhutilOpaqueEnvelopeTestCase extends ArcanistPhutilTestCase {

  public function testOpaqueEnvelope() {

    // NOTE: When run via "arc diff", this test's trace may include portions of
    // the diff itself, and thus this source code. Since we look for the secret
    // in traces later on, split it apart here so that invocation via
    // "arc diff" doesn't create a false test failure.

    $secret = 'hunter'.'2';

    $envelope = new PhutilOpaqueEnvelope($secret);

    $this->assertEqual(
      false,
      strpos(var_export($envelope, true), $secret));

    $this->assertEqual(
      false,
      strpos(print_r($envelope, true), $secret));

    ob_start();
    var_dump($envelope);
    $dump = ob_get_clean();

    $this->assertEqual(
      false,
      strpos($dump, $secret));

    try {
      $this->throwTrace($envelope);
    } catch (Exception $ex) {
      $trace = $ex->getTrace();
      $this->assertEqual(
        false,
        strpos(print_r($trace, true), $secret));
    }

    $backtrace = $this->getBacktrace($envelope);
    $this->assertEqual(
      false,
      strpos(print_r($backtrace, true), $secret));

    $this->assertEqual($secret, $envelope->openEnvelope());
  }

  private function throwTrace($v) {
    throw new Exception("!");
  }

  private function getBacktrace($v) {
    return debug_backtrace();
  }

}
