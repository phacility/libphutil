<?php

final class PhutilTranslationTestCase extends PhutilTestCase {

  public function testLoadAllTranslations() {
    PhutilTranslation::loadAllTranslations();
    $this->assertTrue(true);
  }

}
