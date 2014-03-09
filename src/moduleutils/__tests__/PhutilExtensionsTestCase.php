<?php

final class PhutilExtensionsTestCase extends PhutilTestCase {

  public function testPhutilExtensions() {
    $root = dirname(phutil_get_library_root('phutil'));
    $path = array(
      $root,
      'support',
      'phutiltestlib',
    );
    $path = implode(DIRECTORY_SEPARATOR, $path);
    phutil_load_library($path);

    $this->assertTrue(class_exists('PhutilTestClassA'));
    $this->assertTrue(class_exists('PhutilTestClassB'));
    $this->assertTrue(class_exists('PhutilTestClassC'));

    $symbols = id(new PhutilSymbolLoader())
      ->setAncestorClass('PhutilTestClassA')
      ->setConcreteOnly(true)
      ->selectAndLoadSymbols();

    $this->assertEqual(2, count($symbols));
  }

}
