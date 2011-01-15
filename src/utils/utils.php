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
  return array_key_exists($key, $array) ? $array[$key] : $default;
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
 * Choose an index from a list of arrays. Short for "index pull", this this
 * function works just like @{function:mpull}, except that it operates on a list
 * of arrays and selects an index from them instead of operating on a list of
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
 * @param   list    List of objects to group by some property.
 * @param   string  Name of a method, like 'getType', to call on each object
 *                  in order to determine which group it should be placed into.
 * @param   ...     Zero or more additional method names, to subgroup the
 *                  groups.
 * @return  dict    Dictionary mapping distinct method returns to lists of
 *                  all objects which returned that value.
 * @group   util
 */
function mgroup(array $list, $by /*, ... */) {
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
 * Sort a list of objects by the return value of some method. In PHP, this is
 * often vastly more efficient than usort() and similar.
 *
 *    // Sort a list of Duck objects by name.
 *    $sorted = msort($ducks, 'getName');
 *
 * It is usually significantly more efficient to define an ordering method
 * on objects and call msort() than to write a comparator. It is often more
 * convenient, as well.
 *
 * **NOTE:** This method does not take the list by reference; it returns a new
 * list.
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
 * Returns the first argument which is not strictly null, or ##null## if there
 * are no such arguments. Identical to the MySQL function of the same name.
 *
 * @param  ...         Zero or more arguments of any type.
 * @return mixed       First non-null arg, or null if no such arg exists.
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
 * Similar to coalesce(), but less strict: returns the first non-empty()
 * argument, instead of the first argument that is strictly non-null. If no
 * argument is nonempty, it returns the last argument. This is useful
 * idiomatically for setting defaults:
 *
 *   $value = nonempty($get_value, 0);
 *
 * @param  ...         Zero or more arguments of any type.
 * @return mixed       First non-empty() arg, or last arg if no such arg
 *                     exists, or null if you pased in zero args.
 * @group  util
 */
function nonempty(/* ... */) {
  $args = func_get_args();
  foreach ($args as $arg) {
    if ($arg) {
      break;
    }
  }
  return $arg;
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
 *   -just use eval() lol
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
  return $reflector->newInstanceArgs($argv);
}
