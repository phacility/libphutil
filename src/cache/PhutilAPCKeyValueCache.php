<?php

/**
 * Interface to the APC key-value cache. This is a very high-performance cache
 * which is local to the current machine.
 */
final class PhutilAPCKeyValueCache extends PhutilKeyValueCache {


/* -(  Key-Value Cache Implementation  )------------------------------------- */


  public function isAvailable() {
    return function_exists('apc_fetch') &&
           ini_get('apc.enabled') &&
           (ini_get('apc.enable_cli') || php_sapi_name() != 'cli');
  }

  public function getKeys(array $keys, $ttl = null) {
    $results = array();
    $fetched = false;
    foreach ($keys as $key) {
      $result = apc_fetch($key, $fetched);
      if ($fetched) {
        $results[$key] = $result;
      }
    }
    return $results;
  }

  public function setKeys(array $keys, $ttl = null) {
    // NOTE: Although modern APC supports passing an array to `apc_store()`,
    // it is not supported by older version of APC or by HPHP.

    foreach ($keys as $key => $value) {
      apc_store($key, $value, $ttl);
    }

    return $this;
  }

  public function deleteKeys(array $keys) {
    foreach ($keys as $key) {
      apc_delete($key);
    }

    return $this;
  }

  public function destroyCache() {
    apc_clear_cache('user');

    return $this;
  }

}
