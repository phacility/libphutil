<?php

final class PhutilInfrastructureTestCase extends PhutilTestCase {
  /**
   * This is more of an acceptance test case instead of a unit test. It verifies
   * that all symbols can be loaded correctly. It can catch problems like
   * missing methods in descendants of abstract base classes.
   */
  public function testEverythingImplemented() {
    id(new PhutilSymbolLoader())->selectAndLoadSymbols();
    $this->assertTrue(true);
  }
}
