<?php

/**
 * @group library
 */
function phutil_autoload_class($class) {
  PhutilSymbolLoader::loadClass($class);
  return true;
}