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

define('__LIBPHUTIL__', true);

function phutil_require_module($library, $module) {
  PhutilBootloader::getInstance()->loadModule($library, $module);
}

function phutil_require_source($source) {
  PhutilBootloader::getInstance()->loadSource($source);
}

function phutil_register_library($library, $path) {
  PhutilBootloader::getInstance()->registerLibrary($library, $path);
}

function phutil_register_library_map(array $map) {
  PhutilBootloader::getInstance()->registerLibraryMap($map);
}

function phutil_load_library($path) {
  PhutilBootloader::getInstance()->loadLibrary($path);
}

class PhutilBootloader {

  private static $instance;

  private $registeredLibraries = array();
  private $libraryMaps         = array();
  private $moduleStack         = array();
  private $currentLibrary      = null;

  public static function getInstance() {
    if (!self::$instance) {
      self::$instance = new PhutilBootloader();
    }
    return self::$instance;
  }

  private function __construct() {
    // This method intentionally left blank.
  }

  public function registerLibrary($name, $path) {
    if (basename($path) != '__phutil_library_init__.php') {
      throw new PhutilBootloaderException(
        'Only directories with a __phutil_library_init__.php file may be '.
        'registered as libphutil libraries.');
    }
    $this->registeredLibraries[$name] = dirname($path);
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

  private function pushModuleStack($library, $module) {
    array_push($this->moduleStack, $this->getLibraryRoot($library).'/'.$module);
    return $this;
  }

  private function popModuleStack() {
    array_pop($this->moduleStack);
  }

  private function peekModuleStack() {
    return end($this->moduleStack);
  }

  public function loadLibrary($path) {
    $okay = include_once $path.'/__phutil_library_init__.php';
    if (!$okay) {
      throw new PhutilBootloaderException(
        "Include of '{$path}/__phutil_library_init__.php' failed!");
    }
  }

  public function loadModule($library, $module) {
    $this->pushModuleStack($library, $module);
    phutil_require_source('__init__.php');
    $this->popModuleStack();
  }

  public function loadSource($source) {
    $base = $this->peekModuleStack();
    $okay = include_once $base.'/'.$source;
    if (!$okay) {
      throw new PhutilBootloaderException(
        "Include of '{$base}/{$source}' failed!");
    }
  }

  public function moduleExists($library, $module) {
    $path = $this->getLibraryRoot($library);
    return @file_exists($path.'/'.$module.'/__init__.php');
  }

}

class PhutilBootloaderException extends Exception { }

phutil_register_library('phutil', __FILE__);
