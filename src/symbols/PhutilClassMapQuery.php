<?php

/**
 * Load a map of concrete subclasses of some abstract parent class.
 *
 * libphutil is extensively modular through runtime introspection of class
 * maps. This method makes querying class maps easier.
 *
 * There are several common patterns used with modular class maps:
 *
 *   - A `getUniqueKey()` method which returns a unique scalar key identifying
 *     the class.
 *   - An `expandVariants()` method which potentially returns multiple
 *     instances of the class with different configurations.
 *   - A `getSortName()` method which sorts results.
 *   - Caching of the map.
 *
 * This class provides support for these mechanisms.
 *
 * Using the unique key mechanism with @{method:setUniqueMethod} allows you to
 * use a more human-readable, storage-friendly key to identify objects, allows
 * classes to be freely renamed, and enables variant expansion.
 *
 * Using the expansion mechanism with @{method:setExpandMethod} allows you to
 * have multiple similar modular instances, or configuration-driven instances.
 *
 * Even if they have no immediate need for either mechanism, class maps should
 * generally provide unique keys in their initial design so they are more
 * flexible later on. Adding unique keys later can require database migrations,
 * while adding an expansion mechanism is trivial if a class map already has
 * unique keys.
 *
 * This class automatically caches class maps and does not need to be wrapped
 * in caching logic.
 *
 * @task config Configuring the Query
 * @task exec Executing the Query
 * @task cache Managing the Map Cache
 */
final class PhutilClassMapQuery extends Phobject {

  private $ancestorClass;
  private $expandMethod;
  private $filterMethod;
  private $filterNull = false;
  private $uniqueMethod;
  private $sortMethod;

  // NOTE: If you add more configurable properties here, make sure that
  // cache key construction in getCacheKey() is updated properly.

  private static $cache = array();


/* -(  Configuring the Query  )---------------------------------------------- */


  /**
   * Set the ancestor class or interface name to load the concrete descendants
   * of.
   *
   * @param string Ancestor class or interface name.
   * @return this
   * @task config
   */
  public function setAncestorClass($class) {
    $this->ancestorClass = $class;
    return $this;
  }


  /**
   * Provide a method to select a unique key for each instance.
   *
   * If you provide a method here, the map will be keyed with these values,
   * instead of with class names. Exceptions will be raised if entries are
   * not unique.
   *
   * You must provide a method here to use @{method:setExpandMethod}.
   *
   * @param string  Name of the unique key method.
   * @param bool    If true, then classes which return `null` will be filtered
   *                from the results.
   * @return this
   * @task config
   */
  public function setUniqueMethod($unique_method, $filter_null = false) {
    $this->uniqueMethod = $unique_method;
    $this->filterNull   = $filter_null;
    return $this;
  }


  /**
   * Provide a method to expand each concrete subclass into available instances.
   *
   * With some class maps, each class is allowed to provide multiple entries
   * in the map by returning alternatives from some method with a default
   * implementation like this:
   *
   *   public function generateVariants() {
   *     return array($this);
   *   }
   *
   * For example, a "color" class may really generate and configure several
   * instances in the final class map:
   *
   *   public function generateVariants() {
   *     return array(
   *       self::newColor('red'),
   *       self::newColor('green'),
   *       self::newColor('blue'),
   *     );
   *   }
   *
   * This allows multiple entires in the final map to share an entire
   * implementation, rather than requiring that they each have their own unique
   * subclass.
   *
   * This pattern is most useful if several variants are nearly identical (so
   * the stub subclasses would be essentially empty) or the available variants
   * are driven by configuration.
   *
   * If a class map uses this pattern, it must also provide a unique key for
   * each instance with @{method:setUniqueMethod}.
   *
   * @param string Name of the expansion method.
   * @return this
   * @task config
   */
  public function setExpandMethod($expand_method) {
    $this->expandMethod = $expand_method;
    return $this;
  }


  /**
   * Provide a method to sort the final map.
   *
   * The map will be sorted using @{function:msort} and passing this method
   * name.
   *
   * @param string Name of the sorting method.
   * @return this
   * @task config
   */
  public function setSortMethod($sort_method) {
    $this->sortMethod = $sort_method;
    return $this;
  }


  /**
   * Provide a method to filter the map.
   *
   * @param string Name of the filtering method.
   * @return this
   * @task config
   */
  public function setFilterMethod($filter_method) {
    $this->filterMethod = $filter_method;
    return $this;
  }


/* -(  Executing the Query  )------------------------------------------------ */


  /**
   * Execute the query as configured.
   *
   * @return map<string, object> Realized class map.
   * @task exec
   */
  public function execute() {
    $cache_key = $this->getCacheKey();

    if (!isset(self::$cache[$cache_key])) {
      self::$cache[$cache_key] = $this->loadMap();
    }

    return self::$cache[$cache_key];
  }


  /**
   * Delete all class map caches.
   *
   * @return void
   * @task exec
   */
  public static function deleteCaches() {
    self::$cache = array();
  }


  /**
   * Generate the core query results.
   *
   * This method is used to fill the cache.
   *
   * @return map<string, object> Realized class map.
   * @task exec
   */
  private function loadMap() {
    $ancestor = $this->ancestorClass;
    if (!strlen($ancestor)) {
      throw new PhutilInvalidStateException('setAncestorClass');
    }

    if (!class_exists($ancestor) && !interface_exists($ancestor)) {
      throw new Exception(
        pht(
          'Trying to execute a class map query for descendants of class '.
          '"%s", but no such class or interface exists.',
          $ancestor));
    }

    $expand = $this->expandMethod;
    $filter = $this->filterMethod;
    $unique = $this->uniqueMethod;
    $sort = $this->sortMethod;

    if (strlen($expand)) {
      if (!strlen($unique)) {
        throw new Exception(
          pht(
            'Trying to execute a class map query for descendants of class '.
            '"%s", but the query specifies an "expand method" ("%s") without '.
            'specifying a "unique method". Class maps which support expansion '.
            'must have unique keys.',
            $ancestor,
            $expand));
      }
    }

    $objects = id(new PhutilSymbolLoader())
      ->setAncestorClass($ancestor)
      ->loadObjects();

    // Apply the "expand" mechanism, if it is configured.
    if (strlen($expand)) {
      $list = array();
      foreach ($objects as $object) {
        foreach (call_user_func(array($object, $expand)) as $instance) {
          $list[] = $instance;
        }
      }
    } else {
      $list = $objects;
    }

    // Apply the "unique" mechanism, if it is configured.
    if (strlen($unique)) {
      $map = array();
      foreach ($list as $object) {
        $key = call_user_func(array($object, $unique));

        if ($key === null && $this->filterNull) {
          continue;
        }

        if (empty($map[$key])) {
          $map[$key] = $object;
          continue;
        }

        throw new Exception(
          pht(
            'Two objects (of classes "%s" and "%s", descendants of ancestor '.
            'class "%s") returned the same key from "%s" ("%s"), but each '.
            'object in this class map must be identified by a unique key.',
            get_class($object),
            get_class($map[$key]),
            $ancestor,
            $unique.'()',
            $key));
      }
    } else {
      $map = $list;
    }

    // Apply the "filter" mechanism, if it is configured.
    if (strlen($filter)) {
      $map = mfilter($map, $filter);
    }

    // Apply the "sort" mechanism, if it is configured.
    if (strlen($sort)) {
      if ($map) {
        // The "sort" method may return scalars (which we want to sort with
        // "msort()"), or may return PhutilSortVector objects (which we want
        // to sort with "msortv()").
        $item = call_user_func(array(head($map), $sort));

        // Since we may be early in the stack, use a string to avoid triggering
        // autoload in old versions of PHP.
        $vector_class = 'PhutilSortVector';
        if ($item instanceof $vector_class) {
          $map = msortv($map, $sort);
        } else {
          $map = msort($map, $sort);
        }
      }
    }

    return $map;
  }


/* -(  Managing the Map Cache  )--------------------------------------------- */


  /**
   * Return a cache key for this query.
   *
   * @return string Cache key.
   * @task cache
   */
  public function getCacheKey() {
    $parts = array(
      $this->ancestorClass,
      $this->uniqueMethod,
      $this->filterNull,
      $this->expandMethod,
      $this->filterMethod,
      $this->sortMethod,
    );
    return implode(':', $parts);
  }

}
