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

}
