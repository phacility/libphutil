<?php

/*
 * Copyright 2011 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
