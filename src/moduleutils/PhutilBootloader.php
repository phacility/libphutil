<?php

/**
 * IMPORTANT: Do not call any libphutil functions in this class, including
 * functions like @{function:id}, @{function:idx} and @{function:pht}. They
 * may not have loaded yet.
 */
final class PhutilBootloader {

  private static $instance;

  private $registeredLibraries  = array();
  private $libraryMaps          = array();
  private $extensionMaps        = array();
  private $extendedMaps = array();
  private $currentLibrary       = null;
  private $classTree            = array();
  private $inMemoryMaps         = array();

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

  public function registerInMemoryLibrary($name, $map) {
    $this->registeredLibraries[$name] = "memory:$name";
    $this->inMemoryMaps[$name] = $map;

    $this->getLibraryMap($name);
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
    if (isset($this->extendedMaps[$name])) {
      return $this->extendedMaps[$name];
    }

    if (empty($this->libraryMaps[$name])) {
      $root = $this->getLibraryRoot($name);
      $this->currentLibrary = $name;

      if (isset($this->inMemoryMaps[$name])) {
        $this->libraryMaps[$name] = $this->inMemoryMaps[$name];
      } else {
        $okay = include $root.'/__phutil_library_map__.php';
        if (!$okay) {
          throw new PhutilBootloaderException(
            "Include of '{$root}/__phutil_library_map__.php' failed!");
        }
      }

      $map = $this->libraryMaps[$name];

      $version = isset($map['__library_version__'])
        ? $map['__library_version__']
        : 1;

      switch ($version) {
        case 1:
          throw new Exception(
            'libphutil v1 libraries are no longer supported.');
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

    $map = $this->libraryMaps[$name];

    // If there's an extension map for this library, merge the maps.
    if (isset($this->extensionMaps[$name])) {
      $emap = $this->extensionMaps[$name];
      foreach (array('function', 'class', 'xmap') as $dict_key) {
        if (!isset($emap[$dict_key])) {
          continue;
        }
        $map[$dict_key] += $emap[$dict_key];
      }
    }

    $this->extendedMaps[$name] = $map;

    return $map;
  }

  public function getLibraryMapWithoutExtensions($name) {
    // This just does all the checks to make sure the library is valid, then
    // we throw away the result.
    $this->getLibraryMap($name);

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

    $this->executeInclude($root.$path.'/__phutil_library_init__.php');
  }

  public function loadLibrarySource($library, $source) {
    $path = $this->getLibraryRoot($library).'/'.$source;
    $this->executeInclude($path);
  }

  private function executeInclude($path) {
    // Include the source using `include_once`, but convert any warnings or
    // recoverable errors into exceptions.

    // Some messages, including "Declaration of X should be compatible with Y",
    // do not cause `include_once` to return an error code. Use
    // error_get_last() to make sure we're catching everything in every PHP
    // version.

    // (Also, the severity of some messages changed between versions of PHP.)

    // Note that we may enter this method after some earlier, unrelated error.
    // In this case, error_get_last() will return information for that error.
    // In PHP7 and later we could use error_clear_last() to clear that error,
    // but the function does not exist in earlier versions of PHP. Instead,
    // check if the value has changed.

    // Some parser-like errors, including "class must implement all abstract
    // methods", cause PHP to fatal immediately with an E_ERROR. In these
    // cases, include_once() does not throw and never returns. We leave
    // reporting enabled for these errors since we don't have a way to do
    // anything more graceful.

    // Likewise, some errors, including "cannot redeclare Class::method()"
    // cause PHP to fatal immediately with E_COMPILE_ERROR. Treat these like
    // the similar errors which raise E_ERROR.

    // See also T12190.

    $old_last = error_get_last();

    try {
      $old = error_reporting(E_ERROR | E_COMPILE_ERROR);
      $okay = include_once $path;
      error_reporting($old);
    } catch (Exception $ex) {
      throw $ex;
    } catch (ParseError $throwable) {
      // NOTE: As of PHP7, syntax errors may raise a ParseError (which is a
      // Throwable, not an Exception) with a useless message (like "syntax
      // error, unexpected ':'") and a trace which ends a level above this.

      // Treating this object normally results in an unusable message which
      // does not identify where the syntax error occurred. Converting it to
      // a string and taking the first line gives us something reasonable,
      // however.
      $message = (string)$throwable;
      $message = preg_split("/\n/", $message);
      $message = reset($message);

      throw new Exception($message);
    }

    if (!$okay) {
      throw new Exception("Source file \"{$path}\" failed to load.");
    }

    $new_last = error_get_last();
    if ($new_last !== null) {
      if ($new_last !== $old_last) {
        $message = $new_last['message'];
        throw new Exception(
          "Error while loading file \"{$path}\": {$message}");
      }
    }
  }

  private function loadExtension($library, $root, $path) {
    $old_functions = get_defined_functions();
    $old_functions = array_fill_keys($old_functions['user'], true);
    $old_classes = array_fill_keys(get_declared_classes(), true);
    $old_interfaces = array_fill_keys(get_declared_interfaces(), true);

    $this->executeInclude($path);

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
      $this->extensionMaps[$library]['function'][$func] = $fpath;
    }

    foreach ($add_classes + $add_interfaces as $class => $ignored) {
      $rclass = new ReflectionClass($class);
      $cpath = Filesystem::resolvePath($rclass->getFileName(), $root);
      $this->extensionMaps[$library]['class'][$class] = $cpath;

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

        $this->extensionMaps[$library]['xmap'][$class] = $xmap;
      }
    }

    // Clear the extended library cache (should one exist) so we know that
    // we need to rebuild it.
    unset($this->extendedMaps[$library]);
  }

}
