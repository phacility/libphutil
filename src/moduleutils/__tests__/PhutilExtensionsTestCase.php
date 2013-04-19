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

    $this->assertEqual(true, class_exists('PhutilTestClassA'));
    $this->assertEqual(true, class_exists('PhutilTestClassB'));
    $this->assertEqual(true, class_exists('PhutilTestClassC'));

    $symbols = id(new PhutilSymbolLoader())
      ->setAncestorClass('PhutilTestClassA')
      ->setConcreteOnly(true)
      ->selectAndLoadSymbols();

    $this->assertEqual(2, count($symbols));
  }

}
