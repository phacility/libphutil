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
 * Query and load Phutil classes, interfaces and functions. PhutilSymbolLoader
 * is a query object which selects symbols which satisfy certain criteria, and
 * optionally loads them. For instance, to load all classes in a module:
 *
 *    id(new PhutilSymbolLoader())
 *      ->setType('class')
 *      ->setLibrary('example')
 *      ->setModule('some/module')
 *      ->selectAndLoadSymbols();
 * 
 * @group library
 */
final class PhutilSymbolLoader {

  private $type;
  private $library;
  private $base;
  private $module;
  private $name;

  private $suppressLoad;

  public function setType($type) {
    $this->type = $type;
    return $this;
  }

  public function setLibrary($library) {
    // Validate the library name; this throws if the library in not loaded.
    $bootloader = PhutilBootloader::getInstance();
    $bootloader->getLibraryRoot($library);

    $this->library = $library;
    return $this;
  }

  public function setModule($module) {
    $this->module = $module;
    return $this;
  }

  public function setName($name) {
    $this->name = $name;
    return $this;
  }

  public function setAncestorClass($base) {
    $this->base = $base;
    return $this;
  }

  public function selectSymbolsWithoutLoading() {
    $this->suppressLoad = true;
    $result = $this->selectAndLoadSymbols();
    $this->suppressLoad = false;
    return $result;
  }

  public function selectAndLoadSymbols() {
    $map = array();

    $bootloader = PhutilBootloader::getInstance();

    if ($this->library) {
      $libraries = array($this->library);
    } else {
      $libraries = $bootloader->getAllLibraries();
    }

    if ($this->type) {
      $types = array($this->type);
    } else {
      $types = array(
        'class',
        'function',
      );
    }

    $symbols = array();
    foreach ($libraries as $library) {
      $map = $bootloader->getLibraryMap($library);
      foreach ($types as $type) {
        foreach ($map[$type] as $name => $module) {
          if ($this->name && ($name != $this->name)) {
            continue;
          }
          if ($this->module && ($module != $this->module)) {
            continue;
          }
          $symbol = array(
            'type'    => $type,
            'name'    => $name,
            'library' => $library,
            'module'  => $module,
          );
          if (!empty($map['requires_class'][$name])) {
            $symbol['requires_class'] = $map['requires_class'][$name];
          }
          if (!empty($map['requires_interface'][$name])) {
            $symbol['requires_interface'] = $map['requires_interface'][$name];
          }
          $symbols[$type.'$'.$name] = $symbol;
        }
      }
    }

    if ($this->base) {
      $tree = array();
      $libraries = $bootloader->getAllLibraries();
      foreach ($libraries as $library) {
        $map = $bootloader->getLibraryMap($library);
        foreach ($map['requires_class'] as $child => $parent) {
          $tree[$parent][] = $child;
        }
        foreach ($map['requires_interface'] as $child => $parents) {
          foreach ($parents as $parent) {
            $tree[$parent][] = $child;
          }
        }
      }

      $names = $this->selectDescendantsOf($tree, $this->base);
      foreach ($symbols as $symbol_key => $symbol) {
        $type = $symbol['type'];
        if ($type == 'class' || $type == 'interface') {
          if (isset($names[$symbol['name']])) {
            continue;
          }
        }
        unset($symbols[$symbol_key]);
      }
    }

    if (!$this->suppressLoad) {
      foreach ($symbols as $symbol) {
        $this->loadSymbol($symbol);
      }
    }

    return $symbols;
  }
  
  private function selectDescendantsOf($tree, $root) {
    $result = array();
    foreach ($tree[$root] as $child) {
      $result[$child] = true;
      if (!empty($tree[$child])) {
        $result += $this->selectDescendantsOf($tree, $child);
      }
    }
    return $result;
  }

  public static function loadClass($class_name) {
    $symbols = id(new PhutilSymbolLoader())
      ->setType('class')
      ->setName($class_name)
      ->selectAndLoadSymbols();
    if (!$symbols) {
      throw new PhutilMissingSymbolException($class_name);
    }
  }

  private function loadSymbol(array $symbol_spec) {
    if ($symbol_spec['type'] == 'function') {
      $this->loadFunctionSymbol($symbol_spec);
    } else {
      $this->loadClassOrInterfaceSymbol($symbol_spec);
    }
  }

  private function loadFunctionSymbol(array $symbol_spec) {
    $name = $symbol_spec['name'];
    if (function_exists($name)) {
      return;
    }
    $bootloader = PhutilBootloader::getInstance();
    $bootloader->loadModule($symbol_spec['library'], $symbol_spec['module']);
    if (!function_exists($name)) {
      throw new PhutilMissingSymbolException();
    }
  }

  private function loadClassOrInterfaceSymbol(array $symbol_spec) {
    $name = $symbol_spec['name'];
    if (class_exists($name, false) || interface_exists($name, false)) {
      return;
    }
    $bootloader = PhutilBootloader::getInstance();
    $bootloader->loadModule($symbol_spec['library'], $symbol_spec['module']);
    if (!class_exists($name, false) && !interface_exists($name, false)) {
      throw new PhutilMissingSymbolException($name);
    }
  }

}
