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
  phutil_module_stack('push', $library, $module);
  phutil_require_source('__init__.php');
  phutil_module_stack('pop');
}

function phutil_require_source($source) {
  $base = phutil_module_stack('peek');
  require_once $base.'/'.$source;
}

function phutil_module_exists($library, $module) {
  $path = __phutil_library_registry('find', $library).$module.'/__init__.php';
  return @file_exists($path);
}

function phutil_module_stack($op, $library = null, $module = null) {
  static $stack = array();
  switch ($op) {
    case 'push':
      $stack[] = __phutil_library_registry('find', $library).$module;
      break;
    case 'peek':
      return end($stack);
    case 'pop':
      array_pop($stack);
      break;
  }
}

function phutil_register_library($library, $path) {
  if (basename($path) != '__phutil_library_init__.php') {
    throw new Exception(
      'Only directories with a __phutil_library_init__.php file may be '.
      'registered as libphutil libraries.');
  }
  return __phutil_library_registry('register', $library, dirname($path));
}

function phutil_load_library($path) {
  require_once $path.'/__phutil_library_init__.php';
}

phutil_register_library('phutil', __FILE__);

function __phutil_library_registry($op, $library = null, $path = null) {
  static $dict = array();
  switch ($op) {
    case 'register':
      $dict[$library] = $path.'/';
      break;
    case 'find':
      return $dict[$library];
    case 'list':
      return $dict;
  }
}

