<?php

/**
 * Key-value cache implemented in the current request. All storage is local
 * to this request (i.e., the current page) and destroyed after the request
 * exits. This means the first request to this cache for a given key on a page
 * will ALWAYS miss.
 *
 * This cache exists mostly to support unit tests. In a well-designed
 * applications, you generally should not be fetching the same data over and
 * over again in one request, so this cache should be of limited utility.
 * If using this cache improves application performance, especially if it
 * improves it significantly, it may indicate an architectural problem in your
 * application.
 *
 * @group cache
 */
final class PhutilKeyValueCacheInRequest extends PhutilKeyValueCache {

  private $cache = array();
  private $ttl = array();


/* -(  Key-Value Cache Implementation  )------------------------------------- */


  public function isAvailable() {
    return true;
  }

  public function getKeys(array $keys) {
    $call_id = null;
    if ($this->getProfiler()) {
      $call_id = $this->getProfiler()->beginServiceCall(
        array(
          'type' => 'kvcache-get',
          'name' => 'request',
          'keys' => $keys,
        ));
    }

    $results = array();
    $fetched = false;
    $now = time();
    foreach ($keys as $key) {
      if (!isset($this->cache[$key]) && !array_key_exists($key, $this->cache)) {
        continue;
      }
      if (isset($this->ttl[$key]) && ($this->ttl[$key] < $now)) {
        continue;
      }
      $results[$key] = $this->cache[$key];
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
          'name' => 'request',
          'keys' => array_keys($keys),
        ));
    }

    $this->cache = $keys + $this->cache;
    if ($ttl) {
      $end = time() + $ttl;
      foreach ($keys as $key => $value) {
        $this->ttl[$key] = $end;
      }
    } else {
      foreach ($keys as $key => $value) {
        unset($this->ttl[$key]);
      }
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
          'name' => 'request',
          'keys' => $keys,
        ));
    }

    foreach ($keys as $key) {
      unset($this->cache[$key]);
      unset($this->ttl[$key]);
    }

     if ($call_id) {
      $this->getProfiler()->endServiceCall($call_id, array());
    }

    return $this;
  }

  public function destroyCache() {
    $this->cache = array();
    $this->ttl = array();

    return $this;
  }

}
