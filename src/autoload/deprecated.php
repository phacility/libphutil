<?php

function phutil_autoload_class($class) {
  PhutilSymbolLoader::loadClass($class);
  return true;
}