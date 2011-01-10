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

function phutil_autoload_class($class, $library = null) {
  if (class_exists($class, false) || interface_exists($class, false)) {
    return true;
  }

  $spec = PhutilLibraryMapRegistry::findClass($library, $class, $search = true);

  if (!$spec) {
    return false;
  }

  if ($spec['requires_class']) {
    if (!class_exists($spec['requires_class'], $autoload = false)) {
      phutil_autoload_class($spec['requires_class'], $spec['library']);
    }
  }

  foreach ($spec['requires_interface'] as $interface) {
    if (!interface_exists($interface, $autoload = false)) {
      phutil_autoload_class($interface, $spec['library']);
    }
  }

  try {
    $require_module = 'phutil_require_module';
    $require_module($spec['library'], $spec['module']);
  } catch (PhutilLibraryLoadException $ex) {
    return false;
  }

  return (class_exists($class, false) || interface_exists($class, false));
}

function phutil_autoload_function($function, $library = null) {
  if (function_exists($function)) {
    return true;
  }

  $spec = PhutilLibraryMapRegistry::findFunction(
    $library,
    $function,
    $search = true);

  if (!$spec) {
    return false;
  }

  try {
    $require_module = 'phutil_require_module';
    $require_module($spec['library'], $spec['module']);
  } catch (PhutilLibraryLoadException $ex) {
    return false;
  }

  return function_exists($function);
}

function phutil_find_class_descendants($class) {
  return PhutilLibraryMapRegistry::findDescendantsOfClass($class);
}

function phutil_find_classes_declared_in_module($library, $module) {
  return PhutilLibraryMapRegistry::findClassesDeclaredInModule(
    $library,
    $module);
}

function phutil_register_library_map(array $map) {
  PhutilLibraryMapRegistry::register($map);
}
