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
    id(new PhutilSymbolLoader())
      ->setLibrary($this->getLibraryName())
      ->selectAndLoadSymbols();
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

    $identical = ($new_library_map === $old_library_map);
    if (!$identical) {
      $differences = $this->getMapDifferences(
        $old_library_map,
        $new_library_map);
      sort($differences);
    } else {
      $differences = array();
    }

    $this->assertTrue(
      $identical,
      pht(
        "The library map is out of date. Rebuild it with `%s`.\n".
        "These entries differ: %s.",
        'arc liberate',
        implode(', ', $differences)));
  }


  private function getMapDifferences($old, $new) {
    $changed = array();

    $all = $old + $new;
    foreach ($all as $key => $value) {
      $old_exists = array_key_exists($key, $old);
      $new_exists = array_key_exists($key, $new);

      // One map has it and the other does not, so mark it as changed.
      if ($old_exists != $new_exists) {
        $changed[] = $key;
        continue;
      }

      $oldv = idx($old, $key);
      $newv = idx($new, $key);
      if ($oldv === $newv) {
        continue;
      }

      if (is_array($oldv) && is_array($newv)) {
        $child_changed = $this->getMapDifferences($oldv, $newv);
        foreach ($child_changed as $child) {
          $changed[] = $key.'.'.$child;
        }
      } else {
        $changed[] = $key;
      }
    }

    return $changed;
  }


  /**
   * This is more of an acceptance test case instead of a unit test. It verifies
   * that methods in subclasses have the same visibility as the method in the
   * parent class.
   */
  public function testMethodVisibility() {
    $symbols = id(new PhutilSymbolLoader())
      ->setLibrary($this->getLibraryName())
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
        $method_name = $method->getName();

        foreach (array_merge($parents, $interfaces) as $extends) {
          if ($extends->hasMethod($method_name)) {
            $xmethod = $extends->getMethod($method_name);

            if (!$this->compareVisibility($xmethod, $method)) {
              $failures[] = pht(
                'Class "%s" implements method "%s" with the wrong visibility. '.
                'The method has visibility "%s", but it is defined in parent '.
                '"%s" with visibility "%s". In Phabricator, a method which '.
                'overrides another must always have the same visibility.',
                $class_name,
                $method_name,
                $this->getVisibility($method),
                $extends->getName(),
                $this->getVisibility($xmethod));
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
   * Get the name of the library currently being tested.
   */
  protected function getLibraryName() {
    return phutil_get_library_name_for_root($this->getLibraryRoot());
  }

  /**
   * Get the root directory for the library currently being tested.
   */
  protected function getLibraryRoot() {
    $caller = id(new ReflectionClass($this))->getFileName();
    return phutil_get_library_root_for_path($caller);
  }

  private function compareVisibility(
    ReflectionMethod $parent_method,
    ReflectionMethod $method) {

    static $bitmask;

    if ($bitmask === null) {
      $bitmask  = ReflectionMethod::IS_PUBLIC;
      $bitmask += ReflectionMethod::IS_PROTECTED;
      $bitmask += ReflectionMethod::IS_PRIVATE;
    }

    $parent_modifiers = $parent_method->getModifiers();
    $modifiers = $method->getModifiers();
    return !(($parent_modifiers ^ $modifiers) & $bitmask);
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
