<?php

/**
 * A case-insensitive associative array.
 *
 * This class represents an associative array in which the keys are considered
 * to be case insensitive. This means that `$array['key']` and `$array['KEY']`
 * will refer to the same array element.
 *
 * ```lang=php
 * $array = new CaseInsensitiveArray();
 *
 * $array['key'] = 'value';
 * echo $array['KEY']; // 'value'
 *
 * $array['kEy'] = 'foobar';
 * var_dump($array->toArray()); // array('key' => 'foobar')
 * ```
 *
 * Note that it is not possible to reuse case variants of a key. That is, if
 * the array contains key `xyz` then it is not possible to use any of the
 * following case variants as an array key: `xyZ`, `xYz`, `xYZ`, `Xyz`, `XyZ`,
 * `XYz`, `XYZ`. In order to use a case variant as a key, it is necessary to
 * first unset the original case variant.
 *
 * ```lang=php
 * $array = new CaseInsensitiveArray(array('key' => 'foo', 'KEY' => 'bar'));
 * var_dump($array->toArray()); // array('key' => 'bar')
 *
 * $array['KEY'] = 'baz';
 * var_dump($array->toArray()); // array('key' => 'baz')
 *
 * unset($array['key']);
 * $array['KEY'] = 'baz';
 * var_dump($array->toArray()); // array('KEY' => 'baz')
 * ```
 */
final class CaseInsensitiveArray extends PhutilArray {

  /**
   * Mapping between original and case-invariant keys.
   *
   * All keys in the parent `PhutilArray` are indexed using the case-invariant
   * key rather than the original key.
   *
   * @var map<string, string>
   */
  private $keys = array();

  /**
   * Construct a new array object.
   *
   * @param array  The input array.
   */
  public function __construct(array $data = array()) {
    foreach ($data as $key => $value) {
      $this->offsetSet($key, $value);
    }
  }

  public function getKeys() {
    return array_values($this->keys);
  }

  public function offsetExists($key) {
    $key = $this->transformKey($key);
    return array_key_exists($key, $this->keys);
  }

  public function offsetGet($key) {
    $key = $this->transformKey($key);
    return parent::offsetGet($this->keys[$key]);
  }

  public function offsetSet($key, $value) {
    $transformed_key = $this->transformKey($key);

    if (isset($this->keys[$transformed_key])) {
      // If the key already exists, reuse it and override the
      // existing value.
      $key = $this->keys[$transformed_key];
    } else {
      // If the key doesn't yet, create a new array element.
      $this->keys[$transformed_key] = $key;
    }

    parent::offsetSet($key, $value);
  }

  public function offsetUnset($key) {
    $key = $this->transformKey($key);

    parent::offsetUnset($this->keys[$key]);
    unset($this->keys[$key]);
  }

  /**
   * Transform an array key.
   *
   * This method transforms an array key to be case-invariant. We //could//
   * just call [[http://php.net/manual/en/function.strtolower.php |
   * `strtolower`]] directly, but this method allows us to contain the key
   * transformation logic within a single method, should it ever change.
   *
   * Theoretically, we should be able to use any of the following functions
   * for the purpose of key transformations:
   *
   *   - [[http://php.net/manual/en/function.strtolower.php | `strtolower`]]
   *   - [[http://php.net/manual/en/function.strtoupper.php | `strtoupper`]]
   *   - Some creative use of other
   *   [[http://php.net/manual/en/book.strings.php | string transformation]]
   *   functions.
   *
   * @param  string  The input key.
   * @return string  The transformed key.
   */
  private function transformKey($key) {
    return phutil_utf8_strtolower($key);
  }

}
