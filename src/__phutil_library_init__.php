<?php

define('__LIBPHUTIL__', true);

require_once(__DIR__.'/moduleutils/core.php');
require_once(__DIR__.'/moduleutils/PhutilBootloader.php');
require_once(__DIR__.'/moduleutils/PhutilBootloaderException.php');
require_once(__DIR__.'/moduleutils/PhutilLibraryConflictException.php');

function __phutil_autoload($class_name) {
  // Occurs in PHP 5.2 with call_user_func(array($this, 'self::f')).
  if ($class_name == 'self' || $class_name == 'parent') {
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
