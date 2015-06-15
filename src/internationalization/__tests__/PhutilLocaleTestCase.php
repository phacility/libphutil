<?php

final class PhutilLocaleTestCase extends PhutilTestCase {

  public function testLoadAllLocales() {
    PhutilLocale::loadAllLocales();
    $this->assertTrue(true);
  }

}
