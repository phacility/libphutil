<?php

/*
 * Copyright 2012 Facebook, Inc.
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
 *    $symbols = id(new PhutilSymbolLoader())
 *      ->setType('class')
 *      ->setLibrary('example')
 *      ->setModule('some/module')
 *      ->selectAndLoadSymbols();
 *
 * When you execute the loading query, it returns a dictionary of matching
 * symbols:
 *
 *    array(
 *      'class$Example' => array(
 *        'type'    => 'class',
 *        'name'    => 'Example',
 *        'library' => 'libexample',
 *        'module'  => 'examples/example',
 *      ),
 *      // ... more ...
 *    );
 *
 * The **library** and **module** keys show where the symbol is defined. The
 * **type** and **name** keys identify the symbol itself.
 *
 * @task config   Configuring the Query
 * @task load     Loading Symbols
 * @task internal Internals
 *
 * @group library
 */
final class PhutilSymbolLoader {

  private $type;
  private $library;
  private $base;
  private $module;
  private $name;
  private $concrete;

  private $suppressLoad;


  /**
   * Select the type of symbol to load, either ##class## or ##function##.
   *
   * @param string  Type of symbol to load.
   * @return this
   * @task config
   */
  public function setType($type) {
    $this->type = $type;
    return $this;
  }


  /**
   * Restrict the symbol query to a specific library; only symbols from this
   * library will be loaded.
   *
   * @param string Library name.
   * @return this
   * @task config
   */
  public function setLibrary($library) {
    // Validate the library name; this throws if the library in not loaded.
    $bootloader = PhutilBootloader::getInstance();
    $bootloader->getLibraryRoot($library);

    $this->library = $library;
    return $this;
  }


  /**
   * Restrict the symbol query to a single module.
   *
   * @param string Module name.
   * @return this
   * @task config
   */
  public function setModule($module) {
    $this->module = $module;
    return $this;
  }


  /**
   * Restrict the symbol query to a single symbol name, e.g. a specific class
   * or function name.
   *
   * @param string Symbol name.
   * @return this
   * @task config
   */
  public function setName($name) {
    $this->name = $name;
    return $this;
  }


  /**
   * Restrict the symbol query to only descendants of some class. This will
   * strictly select descendants, the base class will not be selected. This
   * implies loading only classes.
   *
   * @param string Base class name.
   * @return this
   * @task config
   */
  public function setAncestorClass($base) {
    $this->base = $base;
    return $this;
  }


  /**
   * Restrict the symbol query to only concrete symbols; this will filter out
   * abstract classes.
   *
   * NOTE: This currently causes class symbols to load, even if you run
   * @{method:selectSymbolsWithoutLoading}.
   *
   * @param bool True if the query should load only concrete symbols.
   * @return this
   * @task config
   */
  public function setConcreteOnly($concrete) {
    $this->concrete = $concrete;
    return $this;
  }


/* -(  Load  )--------------------------------------------------------------- */


  /**
   * Execute the query and select matching symbols, then load the modules where
   * they are defined so they can be used.
   *
   * @return dict A dictionary of matching symbols. See top-level class
   *              documentation for details. These symbols will be loaded
   *              and available.
   * @task load
   */
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
        if ($type == 'interface') {
          $lookup_map = $map['class'];
        } else {
          $lookup_map = $map[$type];
        }

        // As an optimization, we filter the list of candidate symbols in
        // several passes, applying a name-based filter first if possible since
        // it is highly selective and guaranteed to match at most one symbol.
        // This is the common case and we land here through __autoload() so it's
        // worthwhile to microoptimize a bit because this code path is very hot
        // and we save 5-10ms per page for a very moderate increase in
        // complexity.


        if ($this->name) {
          // If we have a name filter, just pick the matching name out if it
          // exists.
          if (isset($lookup_map[$this->name])) {
            $filtered_map = array(
              $this->name => $lookup_map[$this->name],
            );
          } else {
            $filtered_map = array();
          }
        } else {
          // Otherwise, start with everything.
          $filtered_map = $lookup_map;
        }

        if ($this->module) {
          foreach ($lookup_map as $name => $module) {
            if ($module != $this->module) {
              unset($filtered_map[$name]);
            }
          }
        }

        foreach ($filtered_map as $name => $module) {
          $symbol = array(
            'type'       => $type,
            'name'       => $name,
            'library'    => $library,
            'module'     => $module,
            'standalone' => !empty($map['standalone']),
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

    if ($this->concrete) {
      // Remove 'abstract' classes.
      foreach ($symbols as $key => $symbol) {
        if ($symbol['type'] == 'class') {
          $reflection = new ReflectionClass($symbol['name']);
          if ($reflection->isAbstract()) {
            unset($symbols[$key]);
          }
        }
      }
    }

    return $symbols;
  }


  /**
   * Execute the query and select matching symbols, but do not load the modules
   * where they are defined. This will perform slightly better if you are only
   * interested in the existence of the symbols and don't plan to use them;
   * otherwise, use ##selectAndLoadSymbols()##.
   *
   * @return dict A dictionary of matching symbols. See top-level class
   *              documentation for details.
   * @task load
   */
  public function selectSymbolsWithoutLoading() {
    $this->suppressLoad = true;
    $result = $this->selectAndLoadSymbols();
    $this->suppressLoad = false;
    return $result;
  }


  /**
   * Load one class by name from any available library. Useful for autoload,
   * etc. Throws @{class:PhutilMissingSymbolException} if the class can not
   * be loaded.
   *
   * @param string Class name to load.
   * @return void
   * @task load
   */
  public static function loadClass($class_name) {
    $symbols = id(new PhutilSymbolLoader())
      ->setType('class')
      ->setName($class_name)
      ->selectAndLoadSymbols();
    if (!$symbols) {
      throw new PhutilMissingSymbolException($class_name);
    }
  }


/* -(  Internals  )---------------------------------------------------------- */


  /**
   * @task internal
   */
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


  /**
   * @task internal
   */
  private function loadSymbol(array $symbol_spec) {
    if ($symbol_spec['type'] == 'function') {
      $this->loadFunctionSymbol($symbol_spec);
    } else {
      $this->loadClassOrInterfaceSymbol($symbol_spec);
    }
  }


  /**
   * @task internal
   */
  private function loadFunctionSymbol(array $symbol_spec) {
    $name = $symbol_spec['name'];
    if (function_exists($name)) {
      return;
    }
    $bootloader = PhutilBootloader::getInstance();
    $bootloader->loadModule($symbol_spec['library'], $symbol_spec['module']);
    if (!function_exists($name)) {
      throw new PhutilMissingSymbolException($name);
    }
  }

  /**
   * @task internal
   */
  private function loadClassOrInterfaceSymbol(array $symbol_spec) {
    $name = $symbol_spec['name'];
    if (class_exists($name, false) || interface_exists($name, false)) {
      return;
    }
    $bootloader = PhutilBootloader::getInstance();
    if (empty($symbol_spec['standalone'])) {
      $bootloader->loadModule($symbol_spec['library'], $symbol_spec['module']);
    } else {
      $bootloader->loadClass(
        $name,
        $symbol_spec['library'],
        $symbol_spec['module']);
    }
    if (!class_exists($name, false) && !interface_exists($name, false)) {
      throw new PhutilMissingSymbolException($name);
    }
  }

}
