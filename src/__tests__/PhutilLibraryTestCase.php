<?php

/**
 * @concrete-extensible
 */
class PhutilLibraryTestCase extends PhutilTestCase {

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
    $root = $this->getLibraryRoot();
    $library = phutil_get_library_name_for_root($root);

    $new_library_map = id(new PhutilLibraryMapBuilder($root))
      ->buildMap();

    $bootloader = PhutilBootloader::getInstance();
    $old_library_map = $bootloader->getLibraryMapWithoutExtensions($library);
    unset($old_library_map[PhutilLibraryMapBuilder::LIBRARY_MAP_VERSION_KEY]);

    $this->assertEqual(
      $new_library_map,
      $old_library_map,
      pht(
        'The library map does not appear to be up-to-date. Try '.
        'rebuilding the map with `%s`.',
        'arc liberate'));
  }

  /**
   * Get the root directory for the library currently being tested.
   */
  protected function getLibraryRoot() {
    $caller = id(new ReflectionClass($this))->getFileName();
    return phutil_get_library_root_for_path($caller);
  }

}
