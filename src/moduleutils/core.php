<?php

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
