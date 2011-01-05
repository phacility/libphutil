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

class PhutilLibraryMapRegistry {

  protected static $map = array();
  protected static $library;

  public static function findDescendantsOfClass($class) {
    foreach (array_keys(__phutil_library_registry('list')) as $library) {
      if (empty(self::$map[$library])) {
        self::loadLibraryMap($library);
      }
    }
    $children = array();
    foreach (self::$map as $library => $map) {
      foreach ($map['requires_class'] as $child => $parent) {
        if ($parent == $class) {
          $children[] = $child;
        }
      }
      foreach ($map['requires_interface'] as $child => $parent) {
        if ($parent == $class) {
          $children[] = $child;
        }
      }
    }

    $descendants = array(
      $children,
    );
    foreach ($children as $child) {
      $descendants[] = self::findDescendantsOfClass($child);
    }
    return call_user_func_array('array_merge', $descendants);
  }

  public static function findClassesDeclaredInModule($library, $module) {
    if (empty(self::$map[$library])) {
      $map = self::loadLibraryMap($library);
    } else {
      $map = self::$map[$library];
    }

    $results = array();
    foreach ($map['class'] as $class => $declared) {
      if ($declared == $module) {
        $results[] = $class;
      }
    }

    return $results;
  }

  public static function register(array $map) {
    self::$map[self::$library] = $map;
  }

  public static function loadLibraryMap($library) {
    if (!empty(self::$map[$library])) {
      return self::$map[$library];
    }
    self::$library = $library;
    $root = __phutil_library_registry('find', $library);
    $okay = @include_once $root.'/__phutil_library_map__.php';
    if (!$okay) {
      throw new Exception("Unable to load library map for '{$library}'.");
    }
    return self::$map[$library];
  }

  public static function findClass($library, $class, $search = true) {
    return self::findSymbolOfType('class', $library, $class, $search);
  }

  public static function findFunction($library, $function, $search = true) {
    return self::findSymbolOfType('function', $library, $function, $search);
  }

  public static function findSymbolOfType($type, $library, $symbol, $search) {
    if ($library) {
      $map = self::loadLibraryMap($library);
      if (isset($map[$library][$type][$symbol])) {
        return self::getSpec($type, $library, $symbol);
      }
    }

    if (!$search) {
      return false;
    }

    foreach (self::$map as $library => $map) {
      if (isset($map[$type][$symbol])) {
        return self::getSpec($type, $library, $symbol);
      }
    }

    foreach (array_keys(__phutil_library_registry('list')) as $library) {
      if (empty(self::$map[$library])) {
        $map = self::loadLibraryMap($library);
        if (isset($map[$type][$symbol])) {
          return self::getSpec($type, $library, $symbol);
        }
      }
    }

    return false;
  }

  private static function getSpec($type, $library, $symbol) {
    if ($type == 'function') {
      return self::getFunctionSpec($library, $symbol);
    } else {
      return self::getClassSpec($library, $symbol);
    }
  }

  private static function getFunctionSpec($library, $function) {
    $map = self::$map[$library];
    return array(
      'library' => $library,
      'module'  => $map['function'][$function],
    );
  }

  private static function getClassSpec($library, $class) {
    $map = self::$map[$library];
    $module = $map['class'][$class];
    $parent = null;
    $interface = array();

    if (!empty($map['requires_class'][$class])) {
      $parent = $map['requires_class'][$class];
    }

    if (!empty($map['requires_interface'][$class])) {
      $interface = $map['requires_interface'][$class];
    }

    return array(
      'library'             => $library,
      'module'              => $module,
      'requires_class'      => $parent,
      'requires_interface'  => $interface,
    );
  }

}
