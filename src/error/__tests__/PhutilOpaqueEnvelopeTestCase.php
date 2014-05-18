<?php

final class PhutilOpaqueEnvelopeTestCase extends PhutilTestCase {

  public function testOpaqueEnvelope() {

    // NOTE: When run via "arc diff", this test's trace may include portions of
    // the diff itself, and thus this source code. Since we look for the secret
    // in traces later on, split it apart here so that invocation via
    // "arc diff" doesn't create a false test failure.

    $secret = 'hunter'.'2';

    $envelope = new PhutilOpaqueEnvelope($secret);

    $this->assertFalse(strpos(var_export($envelope, true), $secret));

    $this->assertFalse(strpos(print_r($envelope, true), $secret));

    ob_start();
    var_dump($envelope);
    $dump = ob_get_clean();

    $this->assertFalse(strpos($dump, $secret));

    try {
      $this->throwTrace($envelope);
    } catch (Exception $ex) {
      $trace = $ex->getTrace();
      $this->assertFalse(strpos(print_r($trace, true), $secret));
    }

    $backtrace = $this->getBacktrace($envelope);
    $this->assertFalse(strpos(print_r($backtrace, true), $secret));

    $this->assertEqual($secret, $envelope->openEnvelope());
  }

  private function throwTrace($v) {
    throw new Exception('!');
  }

  private function getBacktrace($v) {
    return debug_backtrace();
  }

}
