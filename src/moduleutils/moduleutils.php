<?php

/**
 * @group library
 */
function phutil_get_library_root($library) {
  $bootloader = PhutilBootloader::getInstance();
  return $bootloader->getLibraryRoot($library);
}


/**
 * @group library
 */
function phutil_get_library_root_for_path($path) {
  foreach (Filesystem::walkToRoot($path) as $dir) {
    if (@file_exists($dir.'/__phutil_library_init__.php')) {
      return $dir;
    }
  }
  return null;
}

/**
 * @group library
 */
function phutil_get_library_name_for_root($path) {
  $path = rtrim(Filesystem::resolvePath($path), '/');

  $bootloader = PhutilBootloader::getInstance();
  $libraries = $bootloader->getAllLibraries();
  foreach ($libraries as $library) {
    $root = $bootloader->getLibraryRoot($library);
    if (rtrim(Filesystem::resolvePath($root), '/') == $path) {
      return $library;
    }
  }

  return null;
}

/**
 * Warns about use of deprecated behavior.
 *
 * @group library
 */
function phutil_deprecated($what, $why) {
  PhutilErrorHandler::dispatchErrorMessage(
    PhutilErrorHandler::DEPRECATED,
    $what,
    array(
      'why' => $why,
    ));
}
