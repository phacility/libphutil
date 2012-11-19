<?php

/**
 * Interface to the APC key-value cache. This is a very high-performance cache
 * which is local to the current machine.
 *
 * @group cache
 */
final class PhutilKeyValueCacheAPC extends PhutilKeyValueCache {


/* -(  Key-Value Cache Implementation  )------------------------------------- */


  public function isAvailable() {
    return function_exists('apc_fetch') &&
           ini_get('apc.enabled') &&
           (ini_get('apc.enable_cli') || php_sapi_name() != 'cli');
  }

  public function getKeys(array $keys, $ttl = null) {
    $call_id = null;
    if ($this->getProfiler()) {
      $call_id = $this->getProfiler()->beginServiceCall(
        array(
          'type' => 'kvcache-get',
          'name' => 'apc',
          'keys' => $keys,
        ));
    }

    $results = array();
    $fetched = false;
    foreach ($keys as $key) {
      $result = apc_fetch($key, $fetched);
      if ($fetched) {
        $results[$key] = $result;
      }
    }

    if ($call_id) {
      $this->getProfiler()->endServiceCall(
        $call_id,
        array(
          'hits' => array_keys($results),
        ));
    }

    return $results;
  }

  public function setKeys(array $keys, $ttl = null) {
    $call_id = null;
    if ($this->getProfiler()) {
      $call_id = $this->getProfiler()->beginServiceCall(
        array(
          'type' => 'kvcache-set',
          'name' => 'apc',
          'keys' => array_keys($keys),
          'ttl'  => $ttl,
        ));
    }

    if ($ttl === null) {
      apc_store($keys);
    } else {
      apc_store($keys, null, $ttl);
    }

    if ($call_id) {
      $this->getProfiler()->endServiceCall($call_id, array());
    }

    return $this;
  }

  public function deleteKeys(array $keys) {
    $call_id = null;
    if ($this->getProfiler()) {
      $call_id = $this->getProfiler()->beginServiceCall(
        array(
          'type' => 'kvcache-del',
          'name' => 'apc',
          'keys' => $keys,
        ));
    }

    foreach ($keys as $key) {
      apc_delete($key);
    }

    if ($call_id) {
      $this->getProfiler()->endServiceCall($call_id, array());
    }

    return $this;
  }

  public function destroyCache() {
    apc_clear_cache('user');

    return $this;
  }

}
