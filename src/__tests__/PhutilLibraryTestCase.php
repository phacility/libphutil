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
   * This is more of an acceptance test case instead of a unit test. It verifies
   * that methods in subclasses have the same visibility as the method in the
   * parent class.
   */
  public function testMethodVisibility() {
    $symbols = id(new PhutilSymbolLoader())
      ->selectSymbolsWithoutLoading();

    $classes = array();
    foreach ($symbols as $symbol) {
      if ($symbol['type'] == 'class') {
        $classes[$symbol['name']] = new ReflectionClass($symbol['name']);
      }
    }

    $failures = array();

    foreach ($classes as $class_name => $class) {
      $parents = array();
      $parent = $class;
      while ($parent = $parent->getParentClass()) {
        $parents[] = $parent;
      }

      $interfaces = $class->getInterfaces();

      foreach ($class->getMethods() as $method) {
        $visibility = $this->getVisibility($method);
        $method_name = $method->getName();

        foreach (array_merge($parents, $interfaces) as $extends) {
          if ($extends->hasMethod($method_name)) {
            $xmethod = $extends->getMethod($method_name);
            $xvisibility = $this->getVisibility($xmethod);

            if ($xvisibility != $visibility) {
              $failures[] = pht(
                'Class "%s" implements method "%s" with the wrong visibility. '.
                'The method has visibility "%s", but it is defined in parent '.
                '"%s" with visibility "%s". In Phabricator, a method which '.
                'overrides another must always have the same visibility.',
                $class_name,
                $method_name,
                $visibility,
                $extends->getName(),
                $xvisibility);
            }

            // We found a declaration somewhere, so stop looking.
            break;
          }
        }
      }
    }

    $this->assertTrue(
      empty($failures),
      "\n\n".implode("\n\n", $failures));
  }

  /**
   * Get the root directory for the library currently being tested.
   */
  protected function getLibraryRoot() {
    $caller = id(new ReflectionClass($this))->getFileName();
    return phutil_get_library_root_for_path($caller);
  }

  private function getVisibility(ReflectionMethod $method) {
    if ($method->isPrivate()) {
      return 'private';
    } else if ($method->isProtected()) {
      return 'protected';
    } else {
      return 'public';
    }
  }

}
