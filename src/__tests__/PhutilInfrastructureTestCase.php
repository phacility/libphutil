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

  /**
   * This is more of an acceptance test case instead of a unit test. It verifies
   * that all the library map is up-to-date.
   */
  public function testLibraryMap() {
    $library = phutil_get_current_library_name();
    $root = phutil_get_library_root($library);

    $new_library_map = id(new PhutilLibraryMapBuilder($root))
      ->buildMap();

    $bootloader = PhutilBootloader::getInstance();
    $old_library_map = $bootloader->getLibraryMapWithoutExtensions($library);
    unset($old_library_map[PhutilLibraryMapBuilder::LIBRARY_MAP_VERSION_KEY]);

    $this->assertEqual(
      $new_library_map,
      $old_library_map,
      'The library map does not appear to be up-to-date. Try '.
      'rebuilding the map with `arc liberate`.');
  }

}
