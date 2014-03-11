<?php

/**
 * Array-like object with a default value that is populated when nonexistent
 * keys are accessed. This is particularly useful to avoid constructs like this:
 *
 *   $counts = array();
 *   foreach ($fruit as $fruit) {
 *     if (!isset($counts[$fruit])) {
 *       $counts[$fruit] = 0;
 *     }
 *     $counts[$fruit] += 1;
 *   }
 *
 * Instead, you can use PhutilArrayWithDefaultValue:
 *
 *   $counts = new PhutilArrayWithDefaultValue();
 *   foreach ($fruits as $fruit) {
 *     $counts[$fruit] += 1;
 *   }
 *
 * NOTE: You must use the `+= 1` operator, not `++`, because PHP is the crown
 * jewel of programming languages.
 *
 * Normally, the default value is `0` to allow the object to be used to count
 * things or build bitmasks. You can change the default with
 * @{method:setDefaultValue}.
 */
final class PhutilArrayWithDefaultValue extends PhutilArray {

  private $defaultValue = 0;

  public function setDefaultValue($default_value) {
    $this->defaultValue = $default_value;
    return $this;
  }

  public function offsetExists($key) {
    return true;
  }

  public function offsetGet($key) {
    if (!parent::offsetExists($key)) {
      $this->offsetSet($key, $this->defaultValue);
    }
    return parent::offsetGet($key);
  }

}
