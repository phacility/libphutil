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
 * @group   util
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
 * @return  wild    If $array[$key] exists, that value is returned. If not,
 *                  $default is returned without raising a warning.
 * @group   util
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
 *                        ##null## to preserve the original keys.
 * @return  dict          A dictionary with keys and values derived according
 *                        to whatever you passed as $method and $key_method.
 * @group   util
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
 *                        ##null## to preserve the original objects.
 * @param   string|null   Determines how **keys** will be assigned in the result
 *                        array. Use a string like 'id' to use the result of
 *                        accessing the named property as each object's key, or
 *                        ##null## to preserve the original keys.
 * @return  dict          A dictionary with keys and values derived according
 *                        to whatever you passed as $property and $key_property.
 * @group   util
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
 *                        to whatever you passed for $index and $key_index.
 * @group   util
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
 * @group   util
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
 * @group   util
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
 * often vastly more efficient than ##usort()## and similar.
 *
 *    // Sort a list of Duck objects by name.
 *    $sorted = msort($ducks, 'getName');
 *
 * It is usually significantly more efficient to define an ordering method
 * on objects and call ##msort()## than to write a comparator. It is often more
 * convenient, as well.
 *
 * NOTE: This method does not take the list by reference; it returns a new list.
 *
 * @param   list    List of objects to sort by some property.
 * @param   string  Name of a method to call on each object; the return values
 *                  will be used to sort the list.
 * @return  list    Objects ordered by the return values of the method calls.
 * @group   util
 */
function msort(array $list, $method) {
  $surrogate = mpull($list, $method);

  asort($surrogate);

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
 * @group   util
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
 * filter out the ones wth empty() results. this function works just like
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
 *
 * @return array   List of objects which pass the filter.
 * @group  util
 */
function mfilter(array $list, $method, $negate = false) {
  if (!is_string($method)) {
    throw new InvalidArgumentException('Argument method is not a string.');
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
 *
 * @return array   List of arrays which pass the filter.
 * @group  util
 */
function ifilter(array $list, $index, $negate = false) {
  if (!is_scalar($index)) {
    throw new InvalidArgumentException('Argument index is not a scalar.');
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
 * @group   util
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
 * Checks if all values of array are instances of the passed class.
 * Throws InvalidArgumentException if it isn't true for any value.
 *
 * @param  array
 * @param  string  Name of the class or 'array' to check arrays.
 * @return array   Returns passed array.
 * @group   util
 */
function assert_instances_of(array $arr, $class) {
  $is_array = !strcasecmp($class, 'array');

  foreach ($arr as $key => $object) {
    if ($is_array) {
      if (!is_array($object)) {
        $given = gettype($object);
        throw new InvalidArgumentException(
          "Array item with key '{$key}' must be of type array, ".
          "{$given} given.");
      }

    } else if (!($object instanceof $class)) {
      $given = gettype($object);
      if (is_object($object)) {
        $given = 'instance of '.get_class($object);
      }
      throw new InvalidArgumentException(
        "Array item with key '{$key}' must be an instance of {$class}, ".
        "{$given} given.");
    }
  }

  return $arr;
}


/**
 * Returns the first argument which is not strictly null, or ##null## if there
 * are no such arguments. Identical to the MySQL function of the same name.
 *
 * @param  ...         Zero or more arguments of any type.
 * @return mixed       First non-##null## arg, or null if no such arg exists.
 * @group  util
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
 * non-##empty()## argument, instead of the first argument that is strictly
 * non-##null##. If no argument is nonempty, it returns the last argument. This
 * is useful idiomatically for setting defaults:
 *
 *   $display_name = nonempty($user_name, $full_name, "Anonymous");
 *
 * @param  ...         Zero or more arguments of any type.
 * @return mixed       First non-##empty()## arg, or last arg if no such arg
 *                     exists, or null if you passed in zero args.
 * @group  util
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
 * call_user_func_array() on a class constructor, so you can instead use this
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
 *   - just use eval() lol
 *
 * These are really bad solutions to the problem because they can have side
 * effects (e.g., __wakeup()) and give you an object in an otherwise impossible
 * state. Please endeavor to keep your objects in possible states.
 *
 * If you own the classes you're doing this for, you should consider whether
 * or not restructuring your code (for instance, by creating static
 * construction methods) might make it cleaner before using newv(). Static
 * constructors can be invoked with call_user_func_array(), and may give your
 * class a cleaner and more descriptive API.
 *
 * @param  string  The name of a class.
 * @param  list    Array of arguments to pass to its constructor.
 * @return obj     A new object of the specified class, constructed by passing
 *                 the argument vector to its constructor.
 * @group util
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
 * @group util
 */
function head(array $arr) {
  return reset($arr);
}

/**
 * Returns the last element of an array. This is exactly like end() except
 * that it won't warn you if you pass some non-referencable array to
 * it -- e.g., the result of some other array operation.
 *
 * @param    array Array to retrieve the last element from.
 * @return   wild  The last value of the array.
 * @group util
 */
function last(array $arr) {
  return end($arr);
}

/**
 * Returns the first key of an array.
 *
 * @param    array       Array to retrieve the first key from.
 * @return   int|string  The first key of the array.
 * @group util
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
 * @group util
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
 * @group util
 */
function array_mergev(array $arrayv) {
  if (!$arrayv) {
    return array();
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
 * @group util
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
 * @group util
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
 * @group util
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
