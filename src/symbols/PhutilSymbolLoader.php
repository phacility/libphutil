<?php

/**
 * Query and load Phutil classes, interfaces and functions.
 *
 * `PhutilSymbolLoader` is a query object which selects symbols which satisfy
 * certain criteria, and optionally loads them. For instance, to load all
 * classes in a library:
 *
 * ```lang=php
 * $symbols = id(new PhutilSymbolLoader())
 *   ->setType('class')
 *   ->setLibrary('example')
 *   ->selectAndLoadSymbols();
 * ```
 *
 * When you execute the loading query, it returns a dictionary of matching
 * symbols:
 *
 * ```lang=php
 * array(
 *   'class$Example' => array(
 *     'type'    => 'class',
 *     'name'    => 'Example',
 *     'library' => 'libexample',
 *     'where'   => 'examples/example.php',
 *   ),
 *   // ... more ...
 * );
 * ```
 *
 * The **library** and **where** keys show where the symbol is defined. The
 * **type** and **name** keys identify the symbol itself.
 *
 * NOTE: This class must not use libphutil functions, including @{function:id}
 * and @{function:idx}.
 *
 * @task config   Configuring the Query
 * @task load     Loading Symbols
 * @task internal Internals
 */
final class PhutilSymbolLoader {

  private $type;
  private $library;
  private $base;
  private $name;
  private $concrete;
  private $pathPrefix;

  private $suppressLoad;


  /**
   * Select the type of symbol to load, either `class`, `function` or
   * `interface`.
   *
   * @param string  Type of symbol to load.
   * @return this
   *
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
   *
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
   * Restrict the symbol query to a specific path prefix; only symbols defined
   * in files below that path will be selected.
   *
   * @param string Path relative to library root, like "apps/cheese/".
   * @return this
   *
   * @task config
   */
  public function setPathPrefix($path) {
    $this->pathPrefix = str_replace(DIRECTORY_SEPARATOR, '/', $path);
    return $this;
  }


  /**
   * Restrict the symbol query to a single symbol name, e.g. a specific class
   * or function name.
   *
   * @param string Symbol name.
   * @return this
   *
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
   *
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
   *
   * @task config
   */
  public function setConcreteOnly($concrete) {
    $this->concrete = $concrete;
    return $this;
  }


/* -(  Load  )--------------------------------------------------------------- */


  /**
   * Execute the query and select matching symbols, then load them so they can
   * be used.
   *
   * @return dict A dictionary of matching symbols. See top-level class
   *              documentation for details. These symbols will be loaded
   *              and available.
   *
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

    $names = null;
    if ($this->base) {
      $names = $this->selectDescendantsOf(
        $bootloader->getClassTree(),
        $this->base);
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
        // This is the common case and we land here through `__autoload()` so
        // it's worthwhile to micro-optimize a bit because this code path is
        // very hot and we save 5-10ms per page for a very moderate increase in
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
        } else if ($names !== null) {
          $filtered_map = array();
          foreach ($names as $name => $ignored) {
            if (isset($lookup_map[$name])) {
              $filtered_map[$name] = $lookup_map[$name];
            }
          }
        } else {
          // Otherwise, start with everything.
          $filtered_map = $lookup_map;
        }

        if ($this->pathPrefix) {
          $len = strlen($this->pathPrefix);
          foreach ($filtered_map as $name => $where) {
            if (strncmp($where, $this->pathPrefix, $len) !== 0) {
              unset($filtered_map[$name]);
            }
          }
        }

        foreach ($filtered_map as $name => $where) {
          $symbols[$type.'$'.$name] = array(
            'type'        => $type,
            'name'        => $name,
            'library'     => $library,
            'where'       => $where,
          );
        }
      }
    }

    if (!$this->suppressLoad) {
      $caught = null;
      foreach ($symbols as $symbol) {
        try {
          $this->loadSymbol($symbol);
        } catch (Exception $ex) {
          $caught = $ex;
        }
      }
      if ($caught) {
        // NOTE: We try to load everything even if we fail to load something,
        // primarily to make it possible to remove functions from a libphutil
        // library without breaking library startup.
        throw $caught;
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
   * Execute the query and select matching symbols, but do not load them. This
   * will perform slightly better if you are only interested in the existence
   * of the symbols and don't plan to use them; otherwise, use
   * @{method:selectAndLoadSymbols}.
   *
   * @return dict A dictionary of matching symbols. See top-level class
   *              documentation for details.
   *
   * @task load
   */
  public function selectSymbolsWithoutLoading() {
    $this->suppressLoad = true;
    $result = $this->selectAndLoadSymbols();
    $this->suppressLoad = false;
    return $result;
  }


  /**
   * Select symbols matching the query and then instantiate them, returning
   * concrete objects. This is a convenience method which simplifies symbol
   * handling if you are only interested in building objects.
   *
   * If you want to do more than build objects, or want to build objects with
   * varying constructor arguments, use @{method:selectAndLoadSymbols} for
   * fine-grained control over results.
   *
   * This method implicitly restricts the query to match only concrete
   * classes.
   *
   * @param  list<wild>           List of constructor arguments.
   * @return map<string, object>  Map of class names to constructed objects.
   */
  public function loadObjects(array $argv = array()) {
    $symbols = $this
      ->setConcreteOnly(true)
      ->setType('class')
      ->selectAndLoadSymbols();

    $objects = array();
    foreach ($symbols as $symbol) {
      $objects[$symbol['name']] = newv($symbol['name'], $argv);
    }

    return $objects;
  }


/* -(  Internals  )---------------------------------------------------------- */


  /**
   * @task internal
   */
  private function selectDescendantsOf(array $tree, $root) {
    $result = array();

    if (empty($tree[$root])) {
      // No known descendants.
      return array();
    }

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
    // Check if we've already loaded the symbol; bail if we have.
    $name = $symbol_spec['name'];
    $is_function = ($symbol_spec['type'] == 'function');

    if ($is_function) {
      if (function_exists($name)) {
        return;
      }
    } else {
      if (class_exists($name, false) || interface_exists($name, false)) {
        return;
      }
    }

    $lib_name = $symbol_spec['library'];
    $where = $symbol_spec['where'];
    $bootloader = PhutilBootloader::getInstance();

    $bootloader->loadLibrarySource($lib_name, $where);

    // Check that we successfully loaded the symbol from wherever it was
    // supposed to be defined.

    $load_failed = null;
    if ($is_function) {
      if (!function_exists($name)) {
        $load_failed = 'function';
      }
    } else {
      if (!class_exists($name, false) && !interface_exists($name, false)) {
        $load_failed = 'class/interface';
      }
    }

    if ($load_failed !== null) {
      $lib_path = phutil_get_library_root($lib_name);
      throw new PhutilMissingSymbolException(
        $name,
        $load_failed,
        pht(
          'The symbol map for library "%s" (at "%s") claims this symbol '.
          '(of type "%s") is defined in "%s", but loading that source file '.
          'did not cause the symbol to become defined.',
          $lib_name,
          $lib_path,
          $load_failed,
          $where));
    }
  }

}
