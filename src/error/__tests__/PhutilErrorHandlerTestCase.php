<?php

final class PhutilErrorHandlerTestCase extends PhutilTestCase {

  public function testProxyException() {
    $a = new Exception('a');
    $b = new PhutilProxyException('b', $a);
    $c = new PhutilProxyException('c', $b);

    $this->assertEqual($a, $b->getPrevious());
    $this->assertEqual($a, PhutilErrorHandler::getRootException($b));
    $this->assertEqual($a, PhutilErrorHandler::getPreviousException($b));

    $this->assertEqual($a, PhutilErrorHandler::getRootException($c));
    $this->assertEqual($b, PhutilErrorHandler::getPreviousException($c));
  }

  public function testSilenceHandler() {
    // Errors should normally be logged.
    $this->assertTrue(strlen($this->emitError()) > 0);

    // The "@" operator should silence errors.
    $this->assertTrue(@strlen($this->emitError()) === 0);
  }

  private function emitError() {
    $temporary_log = new TempFile();

    $old_log = ini_get('error_log');
    ini_set('error_log', (string)$temporary_log);

      trigger_error(pht('(A synthetic error emitted during a unit test.)'));

    ini_set('error_log', $old_log);
    return Filesystem::readFile($temporary_log);
  }


}
