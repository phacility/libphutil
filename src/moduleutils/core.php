<?php

function phutil_register_library($library, $path) {
  PhutilBootloader::getInstance()->registerLibrary($library, $path);
}

function phutil_register_library_map(array $map) {
  PhutilBootloader::getInstance()->registerLibraryMap($map);
}

function phutil_load_library($path) {
  PhutilBootloader::getInstance()->loadLibrary($path);
}
