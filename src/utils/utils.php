<?php

/**
 * Identity function, returns its argument unmodified.
 *
 * This is useful almost exclusively as a workaround to an oddity in the PHP
 * grammar -- this is a syntax error:
 *
 *    COUNTEREXAMPLE
 *    new Thing()->doStuff();
 *
 * ...but this works fine:
 *
 *    id(new Thing())->doStuff();
 *
 * @param   wild Anything.
 * @return  wild Unmodified argument.
 */
function id($x) {
  return $x;
}


/**
 * Access an array index, retrieving the value stored there if it exists or
 * a default if it does not. This function allows you to concisely access an
 * index which may or may not exist without raising a warning.
 *
 * @param   array   Array to access.
 * @param   scalar  Index to access in the array.
 * @param   wild    Default value to return if the key is not present in the
 *                  array.
 * @return  wild    If `$array[$key]` exists, that value is returned. If not,
 *                  $default is returned without raising a warning.
 */
function idx(array $array, $key, $default = null) {
  // isset() is a micro-optimization - it is fast but fails for null values.
  if (isset($array[$key])) {
    return $array[$key];
  }

  // Comparing $default is also a micro-optimization.
  if ($default === null || array_key_exists($key, $array)) {
    return null;
  }

  return $default;
}


/**
 * Access a sequence of array indexes, retrieving a deeply nested value if
 * it exists or a default if it does not.
 *
 * For example, `idxv($dict, array('a', 'b', 'c'))` accesses the key at
 * `$dict['a']['b']['c']`, if it exists. If it does not, or any intermediate
 * value is not itself an array, it returns the defualt value.
 *
 * @param array Array to access.
 * @param list<string> List of keys to access, in sequence.
 * @param wild Default value to return.
 * @return wild Accessed value, or default if the value is not accessible.
 */
function idxv(array $map, array $path, $default = null) {
  if (!$path) {
    return $default;
  }

  $last = last($path);
  $path = array_slice($path, 0, -1);

  $cursor = $map;
  foreach ($path as $key) {
    $cursor = idx($cursor, $key);
    if (!is_array($cursor)) {
      return $default;
    }
  }

  return idx($cursor, $last, $default);
}


/**
 * Call a method on a list of objects. Short for "method pull", this function
 * works just like @{function:ipull}, except that it operates on a list of
 * objects instead of a list of arrays. This function simplifies a common type
 * of mapping operation:
 *
 *    COUNTEREXAMPLE
 *    $names = array();
 *    foreach ($objects as $key => $object) {
 *      $names[$key] = $object->getName();
 *    }
 *
 * You can express this more concisely with mpull():
 *
 *    $names = mpull($objects, 'getName');
 *
 * mpull() takes a third argument, which allows you to do the same but for
 * the array's keys:
 *
 *    COUNTEREXAMPLE
 *    $names = array();
 *    foreach ($objects as $object) {
 *      $names[$object->getID()] = $object->getName();
 *    }
 *
 * This is the mpull version():
 *
 *    $names = mpull($objects, 'getName', 'getID');
 *
 * If you pass ##null## as the second argument, the objects will be preserved:
 *
 *    COUNTEREXAMPLE
 *    $id_map = array();
 *    foreach ($objects as $object) {
 *      $id_map[$object->getID()] = $object;
 *    }
 *
 * With mpull():
 *
 *    $id_map = mpull($objects, null, 'getID');
 *
 * See also @{function:ipull}, which works similarly but accesses array indexes
 * instead of calling methods.
 *
 * @param   list          Some list of objects.
 * @param   string|null   Determines which **values** will appear in the result
 *                        array. Use a string like 'getName' to store the
 *                        value of calling the named method in each value, or
 *                        ##null## to preserve the original objects.
 * @param   string|null   Determines how **keys** will be assigned in the result
 *                        array. Use a string like 'getID' to use the result
 *                        of calling the named method as each object's key, or
 *                        `null` to preserve the original keys.
 * @return  dict          A dictionary with keys and values derived according
 *                        to whatever you passed as `$method` and `$key_method`.
 */
function mpull(array $list, $method, $key_method = null) {
  $result = array();
  foreach ($list as $key => $object) {
    if ($key_method !== null) {
      $key = $object->$key_method();
    }
    if ($method !== null) {
      $value = $object->$method();
    } else {
      $value = $object;
    }
    $result[$key] = $value;
  }
  return $result;
}


/**
 * Access a property on a list of objects. Short for "property pull", this
 * function works just like @{function:mpull}, except that it accesses object
 * properties instead of methods. This function simplifies a common type of
 * mapping operation:
 *
 *    COUNTEREXAMPLE
 *    $names = array();
 *    foreach ($objects as $key => $object) {
 *      $names[$key] = $object->name;
 *    }
 *
 * You can express this more concisely with ppull():
 *
 *    $names = ppull($objects, 'name');
 *
 * ppull() takes a third argument, which allows you to do the same but for
 * the array's keys:
 *
 *    COUNTEREXAMPLE
 *    $names = array();
 *    foreach ($objects as $object) {
 *      $names[$object->id] = $object->name;
 *    }
 *
 * This is the ppull version():
 *
 *    $names = ppull($objects, 'name', 'id');
 *
 * If you pass ##null## as the second argument, the objects will be preserved:
 *
 *    COUNTEREXAMPLE
 *    $id_map = array();
 *    foreach ($objects as $object) {
 *      $id_map[$object->id] = $object;
 *    }
 *
 * With ppull():
 *
 *    $id_map = ppull($objects, null, 'id');
 *
 * See also @{function:mpull}, which works similarly but calls object methods
 * instead of accessing object properties.
 *
 * @param   list          Some list of objects.
 * @param   string|null   Determines which **values** will appear in the result
 *                        array. Use a string like 'name' to store the value of
 *                        accessing the named property in each value, or
 *                        `null` to preserve the original objects.
 * @param   string|null   Determines how **keys** will be assigned in the result
 *                        array. Use a string like 'id' to use the result of
 *                        accessing the named property as each object's key, or
 *                        `null` to preserve the original keys.
 * @return  dict          A dictionary with keys and values derived according
 *                        to whatever you passed as `$property` and
 *                        `$key_property`.
 */
function ppull(array $list, $property, $key_property = null) {
  $result = array();
  foreach ($list as $key => $object) {
    if ($key_property !== null) {
      $key = $object->$key_property;
    }
    if ($property !== null) {
      $value = $object->$property;
    } else {
      $value = $object;
    }
    $result[$key] = $value;
  }
  return $result;
}


/**
 * Choose an index from a list of arrays. Short for "index pull", this function
 * works just like @{function:mpull}, except that it operates on a list of
 * arrays and selects an index from them instead of operating on a list of
 * objects and calling a method on them.
 *
 * This function simplifies a common type of mapping operation:
 *
 *    COUNTEREXAMPLE
 *    $names = array();
 *    foreach ($list as $key => $dict) {
 *      $names[$key] = $dict['name'];
 *    }
 *
 * With ipull():
 *
 *    $names = ipull($list, 'name');
 *
 * See @{function:mpull} for more usage examples.
 *
 * @param   list          Some list of arrays.
 * @param   scalar|null   Determines which **values** will appear in the result
 *                        array. Use a scalar to select that index from each
 *                        array, or null to preserve the arrays unmodified as
 *                        values.
 * @param   scalar|null   Determines which **keys** will appear in the result
 *                        array. Use a scalar to select that index from each
 *                        array, or null to preserve the array keys.
 * @return  dict          A dictionary with keys and values derived according
 *                        to whatever you passed for `$index` and `$key_index`.
 */
function ipull(array $list, $index, $key_index = null) {
  $result = array();
  foreach ($list as $key => $array) {
    if ($key_index !== null) {
      $key = $array[$key_index];
    }
    if ($index !== null) {
      $value = $array[$index];
    } else {
      $value = $array;
    }
    $result[$key] = $value;
  }
  return $result;
}


/**
 * Group a list of objects by the result of some method, similar to how
 * GROUP BY works in an SQL query. This function simplifies grouping objects
 * by some property:
 *
 *    COUNTEREXAMPLE
 *    $animals_by_species = array();
 *    foreach ($animals as $animal) {
 *      $animals_by_species[$animal->getSpecies()][] = $animal;
 *    }
 *
 * This can be expressed more tersely with mgroup():
 *
 *    $animals_by_species = mgroup($animals, 'getSpecies');
 *
 * In either case, the result is a dictionary which maps species (e.g., like
 * "dog") to lists of animals with that property, so all the dogs are grouped
 * together and all the cats are grouped together, or whatever super
 * businessesey thing is actually happening in your problem domain.
 *
 * See also @{function:igroup}, which works the same way but operates on
 * array indexes.
 *
 * @param   list    List of objects to group by some property.
 * @param   string  Name of a method, like 'getType', to call on each object
 *                  in order to determine which group it should be placed into.
 * @param   ...     Zero or more additional method names, to subgroup the
 *                  groups.
 * @return  dict    Dictionary mapping distinct method returns to lists of
 *                  all objects which returned that value.
 */
function mgroup(array $list, $by /* , ... */) {
  $map = mpull($list, $by);

  $groups = array();
  foreach ($map as $group) {
    // Can't array_fill_keys() here because 'false' gets encoded wrong.
    $groups[$group] = array();
  }

  foreach ($map as $key => $group) {
    $groups[$group][$key] = $list[$key];
  }

  $args = func_get_args();
  $args = array_slice($args, 2);
  if ($args) {
    array_unshift($args, null);
    foreach ($groups as $group_key => $grouped) {
      $args[0] = $grouped;
      $groups[$group_key] = call_user_func_array('mgroup', $args);
    }
  }

  return $groups;
}


/**
 * Group a list of arrays by the value of some index. This function is the same
 * as @{function:mgroup}, except it operates on the values of array indexes
 * rather than the return values of method calls.
 *
 * @param   list    List of arrays to group by some index value.
 * @param   string  Name of an index to select from each array in order to
 *                  determine which group it should be placed into.
 * @param   ...     Zero or more additional indexes names, to subgroup the
 *                  groups.
 * @return  dict    Dictionary mapping distinct index values to lists of
 *                  all objects which had that value at the index.
 */
function igroup(array $list, $by /* , ... */) {
  $map = ipull($list, $by);

  $groups = array();
  foreach ($map as $group) {
    $groups[$group] = array();
  }

  foreach ($map as $key => $group) {
    $groups[$group][$key] = $list[$key];
  }

  $args = func_get_args();
  $args = array_slice($args, 2);
  if ($args) {
    array_unshift($args, null);
    foreach ($groups as $group_key => $grouped) {
      $args[0] = $grouped;
      $groups[$group_key] = call_user_func_array('igroup', $args);
    }
  }

  return $groups;
}


/**
 * Sort a list of objects by the return value of some method. In PHP, this is
 * often vastly more efficient than `usort()` and similar.
 *
 *    // Sort a list of Duck objects by name.
 *    $sorted = msort($ducks, 'getName');
 *
 * It is usually significantly more efficient to define an ordering method
 * on objects and call `msort()` than to write a comparator. It is often more
 * convenient, as well.
 *
 * NOTE: This method does not take the list by reference; it returns a new list.
 *
 * @param   list    List of objects to sort by some property.
 * @param   string  Name of a method to call on each object; the return values
 *                  will be used to sort the list.
 * @return  list    Objects ordered by the return values of the method calls.
 */
function msort(array $list, $method) {
  $surrogate = mpull($list, $method);

  // See T13303. A "PhutilSortVector" is technically a sortable object, so
  // a method which returns a "PhutilSortVector" is suitable for use with
  // "msort()". However, it's almost certain that the caller intended to use
  // "msortv()", not "msort()", and forgot to add a "v". Treat this as an error.

  if ($surrogate) {
    $item = head($surrogate);
    if ($item instanceof PhutilSortVector) {
      throw new Exception(
        pht(
          'msort() was passed a method ("%s") which returns '.
          '"PhutilSortVector" objects. Use "msortv()", not "msort()", to '.
          'sort a list which produces vectors.',
          $method));
    }
  }

  asort($surrogate);

  $result = array();
  foreach ($surrogate as $key => $value) {
    $result[$key] = $list[$key];
  }

  return $result;
}


/**
 * Sort a list of objects by a sort vector.
 *
 * This sort is stable, well-behaved, and more efficient than `usort()`.
 *
 * @param list List of objects to sort.
 * @param string Name of a method to call on each object. The method must
 *   return a @{class:PhutilSortVector}.
 * @return list Objects ordered by the vectors.
 */
function msortv(array $list, $method) {
  $surrogate = mpull($list, $method);

  $index = 0;
  foreach ($surrogate as $key => $value) {
    if (!($value instanceof PhutilSortVector)) {
      throw new Exception(
        pht(
          'Objects passed to "%s" must return sort vectors (objects of '.
          'class "%s") from the specified method ("%s"). One object (with '.
          'key "%s") did not.',
          'msortv()',
          'PhutilSortVector',
          $method,
          $key));
    }

    // Add the original index to keep the sort stable.
    $value->addInt($index++);

    $surrogate[$key] = (string)$value;
  }

  asort($surrogate, SORT_STRING);

  $result = array();
  foreach ($surrogate as $key => $value) {
    $result[$key] = $list[$key];
  }

  return $result;
}


/**
 * Sort a list of arrays by the value of some index. This method is identical to
 * @{function:msort}, but operates on a list of arrays instead of a list of
 * objects.
 *
 * @param   list    List of arrays to sort by some index value.
 * @param   string  Index to access on each object; the return values
 *                  will be used to sort the list.
 * @return  list    Arrays ordered by the index values.
 */
function isort(array $list, $index) {
  $surrogate = ipull($list, $index);

  asort($surrogate);

  $result = array();
  foreach ($surrogate as $key => $value) {
    $result[$key] = $list[$key];
  }

  return $result;
}


/**
 * Filter a list of objects by executing a method across all the objects and
 * filter out the ones with empty() results. this function works just like
 * @{function:ifilter}, except that it operates on a list of objects instead
 * of a list of arrays.
 *
 * For example, to remove all objects with no children from a list, where
 * 'hasChildren' is a method name, do this:
 *
 *   mfilter($list, 'hasChildren');
 *
 * The optional third parameter allows you to negate the operation and filter
 * out nonempty objects. To remove all objects that DO have children, do this:
 *
 *   mfilter($list, 'hasChildren', true);
 *
 * @param  array        List of objects to filter.
 * @param  string       A method name.
 * @param  bool         Optionally, pass true to drop objects which pass the
 *                      filter instead of keeping them.
 * @return array        List of objects which pass the filter.
 */
function mfilter(array $list, $method, $negate = false) {
  if (!is_string($method)) {
    throw new InvalidArgumentException(pht('Argument method is not a string.'));
  }

  $result = array();
  foreach ($list as $key => $object) {
    $value = $object->$method();

    if (!$negate) {
      if (!empty($value)) {
        $result[$key] = $object;
      }
    } else {
      if (empty($value)) {
        $result[$key] = $object;
      }
    }
  }

  return $result;
}


/**
 * Filter a list of arrays by removing the ones with an empty() value for some
 * index. This function works just like @{function:mfilter}, except that it
 * operates on a list of arrays instead of a list of objects.
 *
 * For example, to remove all arrays without value for key 'username', do this:
 *
 *   ifilter($list, 'username');
 *
 * The optional third parameter allows you to negate the operation and filter
 * out nonempty arrays. To remove all arrays that DO have value for key
 * 'username', do this:
 *
 *   ifilter($list, 'username', true);
 *
 * @param  array        List of arrays to filter.
 * @param  scalar       The index.
 * @param  bool         Optionally, pass true to drop arrays which pass the
 *                      filter instead of keeping them.
 * @return array        List of arrays which pass the filter.
 */
function ifilter(array $list, $index, $negate = false) {
  if (!is_scalar($index)) {
    throw new InvalidArgumentException(pht('Argument index is not a scalar.'));
  }

  $result = array();
  if (!$negate) {
    foreach ($list as $key => $array) {
      if (!empty($array[$index])) {
        $result[$key] = $array;
      }
    }
  } else {
    foreach ($list as $key => $array) {
      if (empty($array[$index])) {
        $result[$key] = $array;
      }
    }
  }

  return $result;
}


/**
 * Selects a list of keys from an array, returning a new array with only the
 * key-value pairs identified by the selected keys, in the specified order.
 *
 * Note that since this function orders keys in the result according to the
 * order they appear in the list of keys, there are effectively two common
 * uses: either reducing a large dictionary to a smaller one, or changing the
 * key order on an existing dictionary.
 *
 * @param  dict    Dictionary of key-value pairs to select from.
 * @param  list    List of keys to select.
 * @return dict    Dictionary of only those key-value pairs where the key was
 *                 present in the list of keys to select. Ordering is
 *                 determined by the list order.
 */
function array_select_keys(array $dict, array $keys) {
  $result = array();
  foreach ($keys as $key) {
    if (array_key_exists($key, $dict)) {
      $result[$key] = $dict[$key];
    }
  }
  return $result;
}


/**
 * Checks if all values of array are instances of the passed class. Throws
 * `InvalidArgumentException` if it isn't true for any value.
 *
 * @param  array
 * @param  string  Name of the class or 'array' to check arrays.
 * @return array   Returns passed array.
 */
function assert_instances_of(array $arr, $class) {
  $is_array = !strcasecmp($class, 'array');

  foreach ($arr as $key => $object) {
    if ($is_array) {
      if (!is_array($object)) {
        $given = gettype($object);
        throw new InvalidArgumentException(
          pht(
            "Array item with key '%s' must be of type array, %s given.",
            $key,
            $given));
      }

    } else if (!($object instanceof $class)) {
      $given = gettype($object);
      if (is_object($object)) {
        $given = pht('instance of %s', get_class($object));
      }
      throw new InvalidArgumentException(
        pht(
          "Array item with key '%s' must be an instance of %s, %s given.",
          $key,
          $class,
          $given));
    }
  }

  return $arr;
}

/**
 * Assert that two arrays have the exact same keys, in any order.
 *
 * @param map Array with expected keys.
 * @param map Array with actual keys.
 * @return void
 */
function assert_same_keys(array $expect, array $actual) {
  foreach ($expect as $key => $value) {
    if (isset($actual[$key]) || array_key_exists($key, $actual)) {
      continue;
    }

    throw new InvalidArgumentException(
      pht(
        'Expected to find key "%s", but it is not present.',
        $key));

  }

  foreach ($actual as $key => $value) {
    if (isset($expect[$key]) || array_key_exists($key, $expect)) {
      continue;
    }

    throw new InvalidArgumentException(
      pht(
        'Found unexpected surplus key "%s" where no such key was expected.',
        $key));
  }
}

/**
 * Assert that passed data can be converted to string.
 *
 * @param  string    Assert that this data is valid.
 * @return void
 *
 * @task   assert
 */
function assert_stringlike($parameter) {
  switch (gettype($parameter)) {
    case 'string':
    case 'NULL':
    case 'boolean':
    case 'double':
    case 'integer':
      return;
    case 'object':
      if (method_exists($parameter, '__toString')) {
        return;
      }
      break;
    case 'array':
    case 'resource':
    case 'unknown type':
    default:
      break;
  }

  throw new InvalidArgumentException(
    pht(
      'Argument must be scalar or object which implements %s!',
      '__toString()'));
}

/**
 * Returns the first argument which is not strictly null, or `null` if there
 * are no such arguments. Identical to the MySQL function of the same name.
 *
 * @param  ...         Zero or more arguments of any type.
 * @return mixed       First non-`null` arg, or null if no such arg exists.
 */
function coalesce(/* ... */) {
  $args = func_get_args();
  foreach ($args as $arg) {
    if ($arg !== null) {
      return $arg;
    }
  }
  return null;
}


/**
 * Similar to @{function:coalesce}, but less strict: returns the first
 * non-`empty()` argument, instead of the first argument that is strictly
 * non-`null`. If no argument is nonempty, it returns the last argument. This
 * is useful idiomatically for setting defaults:
 *
 *   $display_name = nonempty($user_name, $full_name, "Anonymous");
 *
 * @param  ...         Zero or more arguments of any type.
 * @return mixed       First non-`empty()` arg, or last arg if no such arg
 *                     exists, or null if you passed in zero args.
 */
function nonempty(/* ... */) {
  $args = func_get_args();
  $result = null;
  foreach ($args as $arg) {
    $result = $arg;
    if ($arg) {
      break;
    }
  }
  return $result;
}


/**
 * Invokes the "new" operator with a vector of arguments. There is no way to
 * `call_user_func_array()` on a class constructor, so you can instead use this
 * function:
 *
 *   $obj = newv($class_name, $argv);
 *
 * That is, these two statements are equivalent:
 *
 *   $pancake = new Pancake('Blueberry', 'Maple Syrup', true);
 *   $pancake = newv('Pancake', array('Blueberry', 'Maple Syrup', true));
 *
 * DO NOT solve this problem in other, more creative ways! Three popular
 * alternatives are:
 *
 *   - Build a fake serialized object and unserialize it.
 *   - Invoke the constructor twice.
 *   - just use `eval()` lol
 *
 * These are really bad solutions to the problem because they can have side
 * effects (e.g., __wakeup()) and give you an object in an otherwise impossible
 * state. Please endeavor to keep your objects in possible states.
 *
 * If you own the classes you're doing this for, you should consider whether
 * or not restructuring your code (for instance, by creating static
 * construction methods) might make it cleaner before using `newv()`. Static
 * constructors can be invoked with `call_user_func_array()`, and may give your
 * class a cleaner and more descriptive API.
 *
 * @param  string  The name of a class.
 * @param  list    Array of arguments to pass to its constructor.
 * @return obj     A new object of the specified class, constructed by passing
 *                 the argument vector to its constructor.
 */
function newv($class_name, array $argv) {
  $reflector = new ReflectionClass($class_name);
  if ($argv) {
    return $reflector->newInstanceArgs($argv);
  } else {
    return $reflector->newInstance();
  }
}


/**
 * Returns the first element of an array. Exactly like reset(), but doesn't
 * choke if you pass it some non-referenceable value like the return value of
 * a function.
 *
 * @param    array Array to retrieve the first element from.
 * @return   wild  The first value of the array.
 */
function head(array $arr) {
  return reset($arr);
}

/**
 * Returns the last element of an array. This is exactly like `end()` except
 * that it won't warn you if you pass some non-referencable array to
 * it -- e.g., the result of some other array operation.
 *
 * @param    array Array to retrieve the last element from.
 * @return   wild  The last value of the array.
 */
function last(array $arr) {
  return end($arr);
}

/**
 * Returns the first key of an array.
 *
 * @param    array       Array to retrieve the first key from.
 * @return   int|string  The first key of the array.
 */
function head_key(array $arr) {
  reset($arr);
  return key($arr);
}

/**
 * Returns the last key of an array.
 *
 * @param    array       Array to retrieve the last key from.
 * @return   int|string  The last key of the array.
 */
function last_key(array $arr) {
  end($arr);
  return key($arr);
}

/**
 * Merge a vector of arrays performantly. This has the same semantics as
 * array_merge(), so these calls are equivalent:
 *
 *   array_merge($a, $b, $c);
 *   array_mergev(array($a, $b, $c));
 *
 * However, when you have a vector of arrays, it is vastly more performant to
 * merge them with this function than by calling array_merge() in a loop,
 * because using a loop generates an intermediary array on each iteration.
 *
 * @param list Vector of arrays to merge.
 * @return list Arrays, merged with array_merge() semantics.
 */
function array_mergev(array $arrayv) {
  if (!$arrayv) {
    return array();
  }

  foreach ($arrayv as $key => $item) {
    if (!is_array($item)) {
      throw new InvalidArgumentException(
        pht(
          'Expected all items passed to `%s` to be arrays, but '.
          'argument with key "%s" has type "%s".',
          __FUNCTION__.'()',
          $key,
          gettype($item)));
    }
  }

  return call_user_func_array('array_merge', $arrayv);
}


/**
 * Split a corpus of text into lines. This function splits on "\n", "\r\n", or
 * a mixture of any of them.
 *
 * NOTE: This function does not treat "\r" on its own as a newline because none
 * of SVN, Git or Mercurial do on any OS.
 *
 * @param string Block of text to be split into lines.
 * @param bool If true, retain line endings in result strings.
 * @return list List of lines.
 */
function phutil_split_lines($corpus, $retain_endings = true) {
  if (!strlen($corpus)) {
    return array('');
  }

  // Split on "\r\n" or "\n".
  if ($retain_endings) {
    $lines = preg_split('/(?<=\n)/', $corpus);
  } else {
    $lines = preg_split('/\r?\n/', $corpus);
  }

  // If the text ends with "\n" or similar, we'll end up with an empty string
  // at the end; discard it.
  if (end($lines) == '') {
    array_pop($lines);
  }

  if ($corpus instanceof PhutilSafeHTML) {
    return array_map('phutil_safe_html', $lines);
  }

  return $lines;
}


/**
 * Simplifies a common use of `array_combine()`. Specifically, this:
 *
 *   COUNTEREXAMPLE:
 *   if ($list) {
 *     $result = array_combine($list, $list);
 *   } else {
 *     // Prior to PHP 5.4, array_combine() failed if given empty arrays.
 *     $result = array();
 *   }
 *
 * ...is equivalent to this:
 *
 *   $result = array_fuse($list);
 *
 * @param   list  List of scalars.
 * @return  dict  Dictionary with inputs mapped to themselves.
 */
function array_fuse(array $list) {
  if ($list) {
    return array_combine($list, $list);
  }
  return array();
}


/**
 * Add an element between every two elements of some array. That is, given a
 * list `A, B, C, D`, and some element to interleave, `x`, this function returns
 * `A, x, B, x, C, x, D`. This works like `implode()`, but does not concatenate
 * the list into a string. In particular:
 *
 *   implode('', array_interleave($x, $list));
 *
 * ...is equivalent to:
 *
 *   implode($x, $list);
 *
 * This function does not preserve keys.
 *
 * @param wild  Element to interleave.
 * @param list  List of elements to be interleaved.
 * @return list Original list with the new element interleaved.
 */
function array_interleave($interleave, array $array) {
  $result = array();
  foreach ($array as $item) {
    $result[] = $item;
    $result[] = $interleave;
  }
  array_pop($result);
  return $result;
}

function phutil_is_windows() {
  // We can also use PHP_OS, but that's kind of sketchy because it returns
  // "WINNT" for Windows 7 and "Darwin" for Mac OS X. Practically, testing for
  // DIRECTORY_SEPARATOR is more straightforward.
  return (DIRECTORY_SEPARATOR != '/');
}

function phutil_is_hiphop_runtime() {
  return (array_key_exists('HPHP', $_ENV) && $_ENV['HPHP'] === 1);
}

/**
 * Converts a string to a loggable one, with unprintables and newlines escaped.
 *
 * @param string  Any string.
 * @return string String with control and newline characters escaped, suitable
 *                for printing on a single log line.
 */
function phutil_loggable_string($string) {
  if (preg_match('/^[\x20-\x7E]+$/', $string)) {
    return $string;
  }

  $result = '';

  static $c_map = array(
    '\\' => '\\\\',
    "\n" => '\\n',
    "\r" => '\\r',
    "\t" => '\\t',
  );

  $len = strlen($string);
  for ($ii = 0; $ii < $len; $ii++) {
    $c = $string[$ii];
    if (isset($c_map[$c])) {
      $result .= $c_map[$c];
    } else {
      $o = ord($c);
      if ($o < 0x20 || $o == 0x7F) {
        $result .= '\\x'.sprintf('%02X', $o);
      } else {
        $result .= $c;
      }
    }
  }

  return $result;
}


/**
 * Perform an `fwrite()` which distinguishes between EAGAIN and EPIPE.
 *
 * PHP's `fwrite()` is broken, and never returns `false` for writes to broken
 * nonblocking pipes: it always returns 0, and provides no straightforward
 * mechanism for distinguishing between EAGAIN (buffer is full, can't write any
 * more right now) and EPIPE or similar (no write will ever succeed).
 *
 * See: https://bugs.php.net/bug.php?id=39598
 *
 * If you call this method instead of `fwrite()`, it will attempt to detect
 * when a zero-length write is caused by EAGAIN and return `0` only if the
 * write really should be retried.
 *
 * @param resource  Socket or pipe stream.
 * @param string    Bytes to write.
 * @return bool|int Number of bytes written, or `false` on any error (including
 *                  errors which `fwrite()` can not detect, like a broken pipe).
 */
function phutil_fwrite_nonblocking_stream($stream, $bytes) {
  if (!strlen($bytes)) {
    return 0;
  }

  $result = @fwrite($stream, $bytes);
  if ($result !== 0) {
    // In cases where some bytes are witten (`$result > 0`) or
    // an error occurs (`$result === false`), the behavior of fwrite() is
    // correct. We can return the value as-is.
    return $result;
  }

  // If we make it here, we performed a 0-length write. Try to distinguish
  // between EAGAIN and EPIPE. To do this, we're going to `stream_select()`
  // the stream, write to it again if PHP claims that it's writable, and
  // consider the pipe broken if the write fails.

  // (Signals received signals during the "fwrite()" do not appear to affect
  // anything, see D20083.)

  $read = array();
  $write = array($stream);
  $except = array();

  $result = @stream_select($read, $write, $except, 0);
  if ($result === false) {
    // See T13243. If the select is interrupted by a signal, it may return
    // "false" indicating an underlying EINTR condition. In this case, the
    // results (notably, "$write") are not usable because "stream_select()"
    // didn't update them.

    // In this case, treat this stream as blocked and tell the caller to
    // retry, since EINTR is the only condition we're currently aware of that
    // can cause "fwrite()" to return "0" and "stream_select()" to return
    // "false" on the same stream.
    return 0;
  }

  if (!$write) {
    // The stream isn't writable, so we conclude that it probably really is
    // blocked and the underlying error was EAGAIN. Return 0 to indicate that
    // no data could be written yet.
    return 0;
  }

  // If we make it here, PHP **just** claimed that this stream is writable, so
  // perform a write. If the write also fails, conclude that these failures are
  // EPIPE or some other permanent failure.
  $result = @fwrite($stream, $bytes);
  if ($result !== 0) {
    // The write worked or failed explicitly. This value is fine to return.
    return $result;
  }

  // We performed a 0-length write, were told that the stream was writable, and
  // then immediately performed another 0-length write. Conclude that the pipe
  // is broken and return `false`.
  return false;
}


/**
 * Convert a human-readable unit description into a numeric one. This function
 * allows you to replace this:
 *
 *   COUNTEREXAMPLE
 *   $ttl = (60 * 60 * 24 * 30); // 30 days
 *
 * ...with this:
 *
 *   $ttl = phutil_units('30 days in seconds');
 *
 * ...which is self-documenting and difficult to make a mistake with.
 *
 * @param   string  Human readable description of a unit quantity.
 * @return  int     Quantity of specified unit.
 */
function phutil_units($description) {
  $matches = null;
  if (!preg_match('/^(\d+) (\w+) in (\w+)$/', $description, $matches)) {
    throw new InvalidArgumentException(
      pht(
        'Unable to parse unit specification (expected a specification in the '.
        'form "%s"): %s',
        '5 days in seconds',
        $description));
  }

  $quantity = (int)$matches[1];
  $src_unit = $matches[2];
  $dst_unit = $matches[3];

  $is_divisor = false;

  switch ($dst_unit) {
    case 'seconds':
      switch ($src_unit) {
        case 'second':
        case 'seconds':
          $factor = 1;
          break;
        case 'minute':
        case 'minutes':
          $factor = 60;
          break;
        case 'hour':
        case 'hours':
          $factor = 60 * 60;
          break;
        case 'day':
        case 'days':
          $factor = 60 * 60 * 24;
          break;
        default:
          throw new InvalidArgumentException(
            pht(
              'This function can not convert from the unit "%s".',
              $src_unit));
      }
      break;

    case 'bytes':
      switch ($src_unit) {
        case 'byte':
        case 'bytes':
          $factor = 1;
          break;
        case 'bit':
        case 'bits':
          $factor = 8;
          $is_divisor = true;
          break;
        default:
          throw new InvalidArgumentException(
            pht(
              'This function can not convert from the unit "%s".',
              $src_unit));
      }
      break;

    case 'milliseconds':
      switch ($src_unit) {
        case 'second':
        case 'seconds':
          $factor = 1000;
          break;
        case 'minute':
        case 'minutes':
          $factor = 1000 * 60;
          break;
        case 'hour':
        case 'hours':
          $factor = 1000 * 60 * 60;
          break;
        case 'day':
        case 'days':
          $factor = 1000 * 60 * 60 * 24;
          break;
        default:
          throw new InvalidArgumentException(
            pht(
              'This function can not convert from the unit "%s".',
              $src_unit));
      }
      break;

    case 'microseconds':
      switch ($src_unit) {
        case 'second':
        case 'seconds':
          $factor = 1000000;
          break;
        case 'minute':
        case 'minutes':
          $factor = 1000000 * 60;
          break;
        case 'hour':
        case 'hours':
          $factor = 1000000 * 60 * 60;
          break;
        case 'day':
        case 'days':
          $factor = 1000000 * 60 * 60 * 24;
          break;
        default:
          throw new InvalidArgumentException(
            pht(
              'This function can not convert from the unit "%s".',
              $src_unit));
      }
      break;

    default:
      throw new InvalidArgumentException(
        pht(
          'This function can not convert into the unit "%s".',
          $dst_unit));
  }

  if ($is_divisor) {
    if ($quantity % $factor) {
      throw new InvalidArgumentException(
        pht(
          '"%s" is not an exact quantity.',
          $description));
    }
    return (int)($quantity / $factor);
  } else {
    return $quantity * $factor;
  }
}


/**
 * Compute the number of microseconds that have elapsed since an earlier
 * timestamp (from `microtime(true)`).
 *
 * @param double Microsecond-precision timestamp, from `microtime(true)`.
 * @return int Elapsed microseconds.
 */
function phutil_microseconds_since($timestamp) {
  if (!is_float($timestamp)) {
    throw new Exception(
      pht(
        'Argument to "phutil_microseconds_since(...)" should be a value '.
        'returned from "microtime(true)".'));
  }

  $delta = (microtime(true) - $timestamp);
  $delta = 1000000 * $delta;
  $delta = (int)$delta;

  return $delta;
}


/**
 * Decode a JSON dictionary.
 *
 * @param   string    A string which ostensibly contains a JSON-encoded list or
 *                    dictionary.
 * @return  mixed     Decoded list/dictionary.
 */
function phutil_json_decode($string) {
  $result = @json_decode($string, true);

  if (!is_array($result)) {
    // Failed to decode the JSON. Try to use @{class:PhutilJSONParser} instead.
    // This will probably fail, but will throw a useful exception.
    $parser = new PhutilJSONParser();
    $result = $parser->parse($string);
  }

  return $result;
}


/**
 * Encode a value in JSON, raising an exception if it can not be encoded.
 *
 * @param wild A value to encode.
 * @return string JSON representation of the value.
 */
function phutil_json_encode($value) {
  $result = @json_encode($value);
  if ($result === false) {
    $reason = phutil_validate_json($value);
    if (function_exists('json_last_error')) {
      $err = json_last_error();
      if (function_exists('json_last_error_msg')) {
        $msg = json_last_error_msg();
        $extra = pht('#%d: %s', $err, $msg);
      } else {
        $extra = pht('#%d', $err);
      }
    } else {
      $extra = null;
    }

    if ($extra) {
      $message = pht(
        'Failed to JSON encode value (%s): %s.',
        $extra,
        $reason);
    } else {
      $message = pht(
        'Failed to JSON encode value: %s.',
        $reason);
    }

    throw new Exception($message);
  }

  return $result;
}


/**
 * Produce a human-readable explanation why a value can not be JSON-encoded.
 *
 * @param wild Value to validate.
 * @param string Path within the object to provide context.
 * @return string|null Explanation of why it can't be encoded, or null.
 */
function phutil_validate_json($value, $path = '') {
  if ($value === null) {
    return;
  }

  if ($value === true) {
    return;
  }

  if ($value === false) {
    return;
  }

  if (is_int($value)) {
    return;
  }

  if (is_float($value)) {
    return;
  }

  if (is_array($value)) {
    foreach ($value as $key => $subvalue) {
      if (strlen($path)) {
        $full_key = $path.' > ';
      } else {
        $full_key = '';
      }

      if (!phutil_is_utf8($key)) {
        $full_key = $full_key.phutil_utf8ize($key);
        return pht(
          'Dictionary key "%s" is not valid UTF8, and cannot be JSON encoded.',
          $full_key);
      }

      $full_key .= $key;
      $result = phutil_validate_json($subvalue, $full_key);
      if ($result !== null) {
        return $result;
      }
    }
  }

  if (is_string($value)) {
    if (!phutil_is_utf8($value)) {
      $display = substr($value, 0, 256);
      $display = phutil_utf8ize($display);
      if (!strlen($path)) {
        return pht(
          'String value is not valid UTF8, and can not be JSON encoded: %s',
          $display);
      } else {
        return pht(
          'Dictionary value at key "%s" is not valid UTF8, and cannot be '.
          'JSON encoded: %s',
          $path,
          $display);
      }
    }
  }

  return;
}


/**
 * Decode an INI string.
 *
 * @param  string
 * @return mixed
 */
function phutil_ini_decode($string) {
  $results = null;
  $trap = new PhutilErrorTrap();

  try {
    $have_call = false;
    if (function_exists('parse_ini_string')) {
      if (defined('INI_SCANNER_RAW')) {
        $results = @parse_ini_string($string, true, INI_SCANNER_RAW);
        $have_call = true;
      }
    }

    if (!$have_call) {
      throw new PhutilMethodNotImplementedException(
        pht(
          '%s is not compatible with your version of PHP (%s). This function '.
          'is only supported on PHP versions newer than 5.3.0.',
          __FUNCTION__,
          phpversion()));
    }

    if ($results === false) {
      throw new PhutilINIParserException(trim($trap->getErrorsAsString()));
    }

    foreach ($results as $section => $result) {
      if (!is_array($result)) {
        // We JSON decode the value in ordering to perform the following
        // conversions:
        //
        //   - `'true'` => `true`
        //   - `'false'` => `false`
        //   - `'123'` => `123`
        //   - `'1.234'` => `1.234`
        //
        $result = json_decode($result, true);

        if ($result !== null && !is_array($result)) {
          $results[$section] = $result;
        }

        continue;
      }

      foreach ($result as $key => $value) {
        $value = json_decode($value, true);

        if ($value !== null && !is_array($value)) {
          $results[$section][$key] = $value;
        }
      }
    }
  } catch (Exception $ex) {
    $trap->destroy();
    throw $ex;
  }

  $trap->destroy();
  return $results;
}


/**
 * Attempt to censor any plaintext credentials from a string.
 *
 * The major use case here is to censor usernames and passwords from command
 * output. For example, when `git fetch` fails, the output includes credentials
 * for authenticated HTTP remotes.
 *
 * @param   string  Some block of text.
 * @return  string  A similar block of text, but with credentials that could
 *                  be identified censored.
 */
function phutil_censor_credentials($string) {
  return preg_replace(',(?<=://)([^/@\s]+)(?=@|$),', '********', $string);
}


/**
 * Returns a parsable string representation of a variable.
 *
 * This function is intended to behave similarly to PHP's `var_export` function,
 * but the output is intended to follow our style conventions.
 *
 * @param  wild    The variable you want to export.
 * @return string
 */
function phutil_var_export($var) {
  // `var_export(null, true)` returns `"NULL"` (in uppercase).
  if ($var === null) {
    return 'null';
  }

  // PHP's `var_export` doesn't format arrays very nicely. In particular:
  //
  //   - An empty array is split over two lines (`"array (\n)"`).
  //   - A space separates "array" and the first opening brace.
  //   - Non-associative arrays are returned as associative arrays with an
  //     integer key.
  //
  if (is_array($var)) {
    if (count($var) === 0) {
      return 'array()';
    }

    // Don't show keys for non-associative arrays.
    $show_keys = !phutil_is_natural_list($var);

    $output = array();
    $output[] = 'array(';

    foreach ($var as $key => $value) {
      // Adjust the indentation of the value.
      $value = str_replace("\n", "\n  ", phutil_var_export($value));
      $output[] = '  '.
        ($show_keys ? var_export($key, true).' => ' : '').
        $value.',';
    }

    $output[] = ')';
    return implode("\n", $output);
  }

  // Let PHP handle everything else.
  return var_export($var, true);
}


/**
 * An improved version of `fnmatch`.
 *
 * @param  string  A glob pattern.
 * @param  string  A path.
 * @return bool
 */
function phutil_fnmatch($glob, $path) {
  // Modify the glob to allow `**/` to match files in the root directory.
  $glob = preg_replace('@(?:(?<!\\\\)\\*){2}/@', '{,*/,**/}', $glob);

  $escaping = false;
  $in_curlies = 0;
  $regex = '';

  for ($i = 0; $i < strlen($glob); $i++) {
    $char = $glob[$i];
    $next_char = ($i < strlen($glob) - 1) ? $glob[$i + 1] : null;

    $escape = array('$', '(', ')', '+', '.', '^', '|');
    $mapping = array();

    if ($escaping) {
      $escape[] = '*';
      $escape[] = '?';
      $escape[] = '{';
    } else {
      $mapping['*'] = $next_char === '*' ? '.*' : '[^/]*';
      $mapping['?'] = '[^/]';
      $mapping['{'] = '(';

      if ($in_curlies) {
        $mapping[','] = '|';
        $mapping['}'] = ')';
      }
    }

    if (in_array($char, $escape)) {
      $regex .= "\\{$char}";
    } else if ($replacement = idx($mapping, $char)) {
      $regex .= $replacement;
    } else if ($char === '\\') {
      if ($escaping) {
        $regex .= '\\\\';
      }
      $escaping = !$escaping;
      continue;
    } else {
      $regex .= $char;
    }

    if ($char === '{' && !$escaping) {
      $in_curlies++;
    } else if ($char === '}' && $in_curlies && !$escaping) {
      $in_curlies--;
    }

    $escaping = false;
  }

  if ($in_curlies || $escaping) {
    throw new InvalidArgumentException(pht('Invalid glob pattern.'));
  }

  $regex = '(\A'.$regex.'\z)';
  return (bool)preg_match($regex, $path);
}


/**
 * Compare two hashes for equality.
 *
 * This function defuses two attacks: timing attacks and type juggling attacks.
 *
 * In a timing attack, the attacker observes that strings which match the
 * secret take slightly longer to fail to match because more characters are
 * compared. By testing a large number of strings, they can learn the secret
 * character by character. This defuses timing attacks by always doing the
 * same amount of work.
 *
 * In a type juggling attack, an attacker takes advantage of PHP's type rules
 * where `"0" == "0e12345"` for any exponent. A portion of of hexadecimal
 * hashes match this pattern and are vulnerable. This defuses this attack by
 * performing bytewise character-by-character comparison.
 *
 * It is questionable how practical these attacks are, but they are possible
 * in theory and defusing them is straightforward.
 *
 * @param string First hash.
 * @param string Second hash.
 * @return bool True if hashes are identical.
 */
function phutil_hashes_are_identical($u, $v) {
  if (!is_string($u)) {
    throw new Exception(pht('First hash argument must be a string.'));
  }

  if (!is_string($v)) {
    throw new Exception(pht('Second hash argument must be a string.'));
  }

  if (strlen($u) !== strlen($v)) {
    return false;
  }

  $len = strlen($v);

  $bits = 0;
  for ($ii = 0; $ii < $len; $ii++) {
    $bits |= (ord($u[$ii]) ^ ord($v[$ii]));
  }

  return ($bits === 0);
}


/**
 * Build a query string from a dictionary.
 *
 * @param map<string, string> Dictionary of parameters.
 * @return string HTTP query string.
 */
function phutil_build_http_querystring(array $parameters) {
  $pairs = array();
  foreach ($parameters as $key => $value) {
    $pairs[] = array($key, $value);
  }

  return phutil_build_http_querystring_from_pairs($pairs);
}

/**
 * Build a query string from a list of parameter pairs.
 *
 * @param list<pair<string, string>> List of pairs.
 * @return string HTTP query string.
 */
function phutil_build_http_querystring_from_pairs(array $pairs) {
  // We want to encode in RFC3986 mode, but "http_build_query()" did not get
  // a flag for that mode until PHP 5.4.0. This is equivalent to calling
  // "http_build_query()" with the "PHP_QUERY_RFC3986" flag.

  $query = array();
  foreach ($pairs as $pair_key => $pair) {
    if (!is_array($pair) || (count($pair) !== 2)) {
      throw new Exception(
        pht(
          'HTTP parameter pair (with key "%s") is not valid: each pair must '.
          'be an array with exactly two elements.',
          $pair_key));
    }

    list($key, $value) = $pair;
    list($key, $value) = phutil_http_parameter_pair($key, $value);
    $query[] = rawurlencode($key).'='.rawurlencode($value);
  }
  $query = implode('&', $query);

  return $query;
}

/**
 * Typecheck and cast an HTTP key-value parameter pair.
 *
 * Scalar values are converted to strings. Nonscalar values raise exceptions.
 *
 * @param scalar HTTP parameter key.
 * @param scalar HTTP parameter value.
 * @return pair<string, string> Key and value as strings.
 */
function phutil_http_parameter_pair($key, $value) {
  try {
    assert_stringlike($key);
  } catch (InvalidArgumentException $ex) {
    throw new PhutilProxyException(
      pht('HTTP query parameter key must be a scalar.'),
      $ex);
  }

  $key = phutil_string_cast($key);

  try {
    assert_stringlike($value);
  } catch (InvalidArgumentException $ex) {
    throw new PhutilProxyException(
      pht(
        'HTTP query parameter value (for key "%s") must be a scalar.',
        $key),
      $ex);
  }

  $value = phutil_string_cast($value);

  return array($key, $value);
}

function phutil_decode_mime_header($header) {
  if (function_exists('iconv_mime_decode')) {
    return iconv_mime_decode($header, 0, 'UTF-8');
  }

  if (function_exists('mb_decode_mimeheader')) {
    return mb_decode_mimeheader($header);
  }

  throw new Exception(
    pht(
      'Unable to decode MIME header: install "iconv" or "mbstring" '.
      'extension.'));
}

/**
 * Perform a "(string)" cast without disabling standard exception behavior.
 *
 * When PHP invokes "__toString()" automatically, it fatals if the method
 * raises an exception. In older versions of PHP (until PHP 7.1), this fatal is
 * fairly opaque and does not give you any information about the exception
 * itself, although newer versions of PHP at least include the exception
 * message.
 *
 * This is documented on the "__toString()" manual page:
 *
 *   Warning
 *   You cannot throw an exception from within a __toString() method. Doing
 *   so will result in a fatal error.
 *
 * However, this only applies to implicit invocation by the language runtime.
 * Application code can safely call `__toString()` directly without any effect
 * on exception handling behavior. Very cool.
 *
 * We also reject arrays. PHP casts them to the string "Array". This behavior
 * is, charitably, evil.
 *
 * @param wild Any value which aspires to be represented as a string.
 * @return string String representation of the provided value.
 */
function phutil_string_cast($value) {
  if (is_array($value)) {
    throw new Exception(
      pht(
        'Value passed to "phutil_string_cast()" is an array; arrays can '.
        'not be sensibly cast to strings.'));
  }

  if (is_object($value)) {
    $string = $value->__toString();

    if (!is_string($string)) {
      throw new Exception(
        pht(
          'Object (of class "%s") did not return a string from "__toString()".',
          get_class($value)));
    }

    return $string;
  }

  return (string)$value;
}


/**
 * Return a short, human-readable description of an object's type.
 *
 * This is mostly useful for raising errors like "expected x() to return a Y,
 * but it returned a Z".
 *
 * This is similar to "get_type()", but describes objects and arrays in more
 * detail.
 *
 * @param wild Anything.
 * @return string Human-readable description of the value's type.
 */
function phutil_describe_type($value) {
  return PhutilTypeSpec::getTypeOf($value);
}


/**
 * Test if a list has the natural numbers (1, 2, 3, and so on) as keys, in
 * order.
 *
 * @return bool True if the list is a natural list.
 */
function phutil_is_natural_list(array $list) {
  $expect = 0;

  foreach ($list as $key => $item) {
    if ($key !== $expect) {
      return false;
    }
    $expect++;
  }

  return true;
}
