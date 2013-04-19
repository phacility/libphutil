<?php

define('__LIBPHUTIL__', true);

/**
 * @group library
 */
function phutil_register_library($library, $path) {
  PhutilBootloader::getInstance()->registerLibrary($library, $path);
}

/**
 * @group library
 */
function phutil_register_library_map(array $map) {
  PhutilBootloader::getInstance()->registerLibraryMap($map);
}

/**
 * @group library
 */
function phutil_load_library($path) {
  PhutilBootloader::getInstance()->loadLibrary($path);
}

/**
 * @group library
 */
final class PhutilBootloader {

  private static $instance;

  private $registeredLibraries  = array();
  private $libraryMaps          = array();
  private $currentLibrary       = null;
  private $classTree            = array();

  public static function getInstance() {
    if (!self::$instance) {
      self::$instance = new PhutilBootloader();
    }
    return self::$instance;
  }

  private function __construct() {
    // This method intentionally left blank.
  }

  public function getClassTree() {
    return $this->classTree;
  }

  public function registerLibrary($name, $path) {
    if (basename($path) != '__phutil_library_init__.php') {
      throw new PhutilBootloaderException(
        'Only directories with a __phutil_library_init__.php file may be '.
        'registered as libphutil libraries.');
    }

    $path = dirname($path);

    // Detect attempts to load the same library multiple times from different
    // locations. This might mean you're doing something silly like trying to
    // include two different versions of something, or it might mean you're
    // doing something subtle like running a different version of 'arc' on a
    // working copy of Arcanist.
    if (isset($this->registeredLibraries[$name])) {
      $old_path = $this->registeredLibraries[$name];
      if ($old_path != $path) {
        throw new PhutilLibraryConflictException($name, $old_path, $path);
      }
    }

    $this->registeredLibraries[$name] = $path;

    // For libphutil v2 libraries, load all functions when we load the library.

    if (!class_exists('PhutilSymbolLoader', false)) {
      $root = $this->getLibraryRoot('phutil');
      $this->executeInclude($root.'/symbols/PhutilSymbolLoader.php');
    }

    $loader = new PhutilSymbolLoader();
    $loader
      ->setLibrary($name)
      ->setType('function');

    try {
      $loader->selectAndLoadSymbols();
    } catch (PhutilBootloaderException $ex) {
      // Ignore this, it happens if a global function's file is removed or
      // similar. Worst case is that we fatal when calling the function, which
      // is no worse than fataling here.
    } catch (PhutilMissingSymbolException $ex) {
      // Ignore this, it happens if a global function is removed. Everything
      // else loaded so proceed forward: worst case is a fatal when we
      // hit a function call to a function which no longer exists, which is
      // no worse than fataling here.
    }

    if (empty($_SERVER['PHUTIL_DISABLE_RUNTIME_EXTENSIONS'])) {
      $extdir = $path.DIRECTORY_SEPARATOR.'extensions';
      if (Filesystem::pathExists($extdir)) {
        $extensions = id(new FileFinder($extdir))
          ->withSuffix('php')
          ->withType('f')
          ->withFollowSymlinks(true)
          ->setForceMode('php')
          ->find();

        foreach ($extensions as $extension) {
          $this->loadExtension(
            $name,
            $path,
            $extdir.DIRECTORY_SEPARATOR.$extension);
        }
      }
    }

    return $this;
  }

  public function registerLibraryMap(array $map) {
    $this->libraryMaps[$this->currentLibrary] = $map;
    return $this;
  }

  public function getLibraryMap($name) {
    if (empty($this->libraryMaps[$name])) {
      $root = $this->getLibraryRoot($name);
      $this->currentLibrary = $name;
      $okay = include $root.'/__phutil_library_map__.php';
      if (!$okay) {
        throw new PhutilBootloaderException(
          "Include of '{$root}/__phutil_library_map__.php' failed!");
      }

      $map = $this->libraryMaps[$name];

      // NOTE: We can't use "idx()" here because it may not be loaded yet.
      $version = isset($map['__library_version__'])
        ? $map['__library_version__']
        : 1;

      switch ($version) {
        case 1:
          throw new Exception(
            "libphutil v1 libraries are no longer supported.");
        case 2:
          // NOTE: In version 2 of the library format, all parents (both
          // classes and interfaces) are stored in the 'xmap'. The value is
          // either a string for a single parent (the common case) or an array
          // for multiple parents.
          foreach ($map['xmap'] as $child => $parents) {
            foreach ((array)$parents as $parent) {
              $this->classTree[$parent][] = $child;
            }
          }
          break;
        default:
          throw new Exception("Unsupported library version '{$version}'!");
      }
    }
    return $this->libraryMaps[$name];
  }

  public function getLibraryRoot($name) {
    if (empty($this->registeredLibraries[$name])) {
      throw new PhutilBootloaderException(
        "The phutil library '{$name}' has not been loaded!");
    }
    return $this->registeredLibraries[$name];
  }

  public function getAllLibraries() {
    return array_keys($this->registeredLibraries);
  }

  public function loadLibrary($path) {
    $root = null;
    if (!empty($_SERVER['PHUTIL_LIBRARY_ROOT'])) {
      if ($path[0] != '/') {
        $root = $_SERVER['PHUTIL_LIBRARY_ROOT'];
      }
    }
    $okay = $this->executeInclude($root.$path.'/__phutil_library_init__.php');
    if (!$okay) {
      throw new PhutilBootloaderException(
        "Include of '{$path}/__phutil_library_init__.php' failed!");
    }
  }

  public function loadLibrarySource($library, $source) {
    $path = $this->getLibraryRoot($library).'/'.$source;
    $okay = $this->executeInclude($path);
    if (!$okay) {
      throw new PhutilBootloaderException("Include of '{$path}' failed!");
    }
  }

  private function executeInclude($path) {
    // Suppress warning spew if the file does not exist; we'll throw an
    // exception instead. We still emit error text in the case of syntax errors.
    $old = error_reporting(E_ALL & ~E_WARNING);
    $okay = include_once $path;
    error_reporting($old);

    return $okay;
  }

  private function loadExtension($library, $root, $path) {

    $old_functions = get_defined_functions();
    $old_functions = array_fill_keys($old_functions['user'], true);
    $old_classes = array_fill_keys(get_declared_classes(), true);
    $old_interfaces = array_fill_keys(get_declared_interfaces(), true);

    $ok = $this->executeInclude($path);
    if (!$ok) {
      throw new PhutilBootloaderException(
        "Include of extension file '{$path}' failed!");
    }

    $new_functions = get_defined_functions();
    $new_functions = array_fill_keys($new_functions['user'], true);
    $new_classes = array_fill_keys(get_declared_classes(), true);
    $new_interfaces = array_fill_keys(get_declared_interfaces(), true);

    $add_functions = array_diff_key($new_functions, $old_functions);
    $add_classes = array_diff_key($new_classes, $old_classes);
    $add_interfaces = array_diff_key($new_interfaces, $old_interfaces);

    // NOTE: We can't trust the path we loaded to be the location of these
    // symbols, because it might have loaded other paths.

    foreach ($add_functions as $func => $ignored) {
      $rfunc = new ReflectionFunction($func);
      $fpath = Filesystem::resolvePath($rfunc->getFileName(), $root);
      $this->libraryMaps[$library]['function'][$func] = $fpath;
    }

    foreach ($add_classes + $add_interfaces as $class => $ignored) {
      $rclass = new ReflectionClass($class);
      $cpath = Filesystem::resolvePath($rclass->getFileName(), $root);
      $this->libraryMaps[$library]['class'][$class] = $cpath;

      $xmap = $rclass->getInterfaceNames();
      $parent = $rclass->getParentClass();
      if ($parent) {
        $xmap[] = $parent->getName();
      }

      if ($xmap) {
        foreach ($xmap as $parent_class) {
          $this->classTree[$parent_class][] = $class;
        }

        if (count($xmap) == 1) {
          $xmap = head($xmap);
        }

        $this->libraryMaps[$library]['xmap'][$class] = $xmap;
      }
    }
  }

}

/**
 * @group library
 */
final class PhutilBootloaderException extends Exception { }


/**
 * Thrown when you attempt to load two different copies of a library with the
 * same name. Trying to load the second copy of the library will trigger this,
 * and the library will not be loaded.
 *
 * This means you've either done something silly (like tried to explicitly load
 * two different versions of the same library into the same program -- this
 * won't work because they'll have namespace conflicts), or your configuration
 * might have some problems which caused two parts of your program to try to
 * load the same library but end up loading different copies of it, or there
 * may be some subtle issue like running 'arc' in a different Arcanist working
 * directory. (Some bootstrapping workflows like that which run low-level
 * library components on other copies of themselves are expected to fail.)
 *
 * To resolve this, you need to make sure your program loads no more than one
 * copy of each libphutil library, but exactly how you approach this depends on
 * why it's happening in the first place.
 *
 * @task info Getting Exception Information
 * @task construct Creating Library Conflict Exceptions
 * @group library
 */
final class PhutilLibraryConflictException extends Exception {

  private $library;
  private $oldPath;
  private $newPath;

  /**
   * Create a new library conflict exception.
   *
   * @param string The name of the library which conflicts with an existing
   *               library.
   * @param string The path of the already-loaded library.
   * @param string The path of the attempting-to-load library.
   *
   * @task construct
   */
  public function __construct($library, $old_path, $new_path) {
    $this->library = $library;
    $this->oldPath = $old_path;
    $this->newPath = $new_path;

    $message = "Library conflict! The library '{$library}' has already been ".
               "loaded (from '{$old_path}') but is now being loaded again ".
               "from a new location ('{$new_path}'). You can not load ".
               "multiple copies of the same library into a program.";

    parent::__construct($message);
  }

  /**
   * Retrieve the name of the library in conflict.
   *
   * @return string The name of the library which conflicts with an existing
   *                library.
   * @task info
   */
  public function getLibrary() {
    return $this->library;
  }


  /**
   * Get the path to the library which has already been loaded earlier in the
   * program's execution.
   *
   * @return string The path of the already-loaded library.
   * @task info
   */
  public function getOldPath() {
    return $this->oldPath;
  }

  /**
   * Get the path to the library which is causing this conflict.
   *
   * @return string The path of the attempting-to-load library.
   * @task info
   */
  public function getNewPath() {
    return $this->newPath;
  }
}


/**
 * @group library
 */
function __phutil_autoload($class_name) {
  try {
    $loader = new PhutilSymbolLoader();
    $symbols = $loader
      ->setType('class')
      ->setName($class_name)
      ->selectAndLoadSymbols();
    if (!$symbols) {
      throw new PhutilMissingSymbolException(
        $class_name,
        'class or interface',
        "the class or interface '{$class_name}' is not defined in the library ".
        "map for any loaded phutil library.");
    }
  } catch (PhutilMissingSymbolException $ex) {
    // If there are other SPL autoloaders installed, we need to give them a
    // chance to load the class. Throw the exception if we're the last
    // autoloader; if not, swallow it and let them take a shot.
    $autoloaders = spl_autoload_functions();
    $last = end($autoloaders);
    if ($last == '__phutil_autoload') {
      throw $ex;
    }
  }
}

spl_autoload_register('__phutil_autoload', $throw = true);

phutil_register_library('phutil', __FILE__);
