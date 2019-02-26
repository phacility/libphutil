<?php

define('__LIBPHUTIL__', true);

$root = dirname(__FILE__);
require_once $root.'/moduleutils/core.php';
require_once $root.'/moduleutils/PhutilBootloader.php';
require_once $root.'/moduleutils/PhutilBootloaderException.php';
require_once $root.'/moduleutils/PhutilLibraryConflictException.php';

function __phutil_autoload($class_name) {
  // Occurs in PHP 5.2 with `call_user_func(array($this, 'self::f'))`.
  if ($class_name === 'self' || $class_name === 'parent') {
    return;
  }

  try {
    $loader = new PhutilSymbolLoader();
    $symbols = $loader
      ->setType('class')
      ->setName($class_name)
      ->selectAndLoadSymbols();

    if (!$symbols) {
      throw new PhutilMissingSymbolException(
        $class_name,
        pht('class or interface'),
        pht(
          'The class or interface "%s" is not defined in the library '.
          'map of any loaded library.',
          $class_name));
    }
  } catch (PhutilMissingSymbolException $ex) {
    $should_throw = true;

    foreach (debug_backtrace() as $backtrace) {
      if (empty($backtrace['function'])) {
        continue;
      }

      switch ($backtrace['function']) {
        case 'class_exists':
        case 'interface_exists':
        case 'method_exists':
        case 'property_exists':
        case 'trait_exists':
          $should_throw = false;
          break;
      }
    }

    if (!$should_throw) {
      return false;
    }

    // If there are other SPL autoloaders installed, we need to give them a
    // chance to load the class. Throw the exception if we're the last
    // autoloader; if not, swallow it and let them take a shot.
    $autoloaders = spl_autoload_functions();
    $last = end($autoloaders);
    if ($last == __FUNCTION__) {
      throw $ex;
    }
  }
}

spl_autoload_register('__phutil_autoload', $throw = true);

phutil_register_library('phutil', __FILE__);
