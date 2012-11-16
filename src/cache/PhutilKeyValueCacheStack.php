<?php

/**
 * Stacks multiple caches on top of each other, with readthrough semantics:
 *
 *   - For reads, we try each cache in order until we find all the keys.
 *   - For writes, we set the keys in each cache.
 *
 * @task  kvimpl    Key-Value Cache Implementation
 * @group cache
 */
final class PhutilKeyValueCacheStack extends PhutilKeyValueCache {


  /**
   * Forward list of caches in the stack (from the nearest cache to the farthest
   * cache).
   */
  private $cachesForward;


  /**
   * Backward list of caches in the stack (from the farthest cache to the
   * nearest cache).
   */
  private $cachesBackward;


/* -(  Key-Value Cache Implementation  )------------------------------------- */


  /**
   * @task kvimpl
   */
  public function setProfiler(PhutilServiceProfiler $profiler) {
    foreach ($this->cachesForward as $cache) {
      $cache->setProfiler($profiler);
    }
  }


  /**
   * @task kvimpl
   */
  public function setCaches(array $caches) {
    assert_instances_of($caches, 'PhutilKeyValueCache');
    $this->cachesForward  = $caches;
    $this->cachesBackward = array_reverse($caches);
  }


  /**
   * @task kvimpl
   */
  public function getKey($key, $default = null, $ttl = null) {
    $missed = array();
    foreach ($this->cachesForward as $cache) {
      $result = $cache->getKey($key);
      if ($result !== null) {
        while ($cache = array_pop($missed)) {
          $cache->setKey($key, $result, $ttl);
        }
        return $result;
      }
      $missed[] = $cache;
    }
    return $default;
  }


  /**
   * @task kvimpl
   */
  public function setKey($key, $value, $ttl = null) {
    foreach ($this->cachesBackward as $cache) {
      $cache->setKey($key, $value, $ttl);
    }
  }


  /**
   * @task kvimpl
   */
  public function deleteKey($key) {
    foreach ($this->cachesBackward as $cache) {
      $cache->deleteKey($key);
    }
  }


  /**
   * @task kvimpl
   */
  public function getKeys(array $keys, $ttl = null) {
    $remaining = array_combine($keys, $keys);
    $results = array();
    $missed = array();
    foreach ($this->cachesForward as $cache) {
      $result = $cache->getKeys($remaining);
      $remaining = array_diff_key($remaining, $result);
      $results += $result;
      if (!$remaining) {
        while ($cache = array_pop($missed)) {
          // TODO: This sets too many results in the closer caches, although it
          // probably isn't a big deal in most cases; normally we're just
          // filling the request cache.
          $cache->setKeys($result, $ttl);
        }
        break;
      }
      $missed[] = $cache;
    }

    return $results;
  }


  /**
   * @task kvimpl
   */
  public function setKeys(array $keys, $ttl = null) {
    foreach ($this->cachesBackward as $cache) {
      $cache->setKeys($keys, $ttl);
    }
  }


  /**
   * @task kvimpl
   */
  public function deleteKeys(array $keys) {
    foreach ($this->cachesBackward as $cache) {
      $cache->deleteKeys($keys);
    }
  }


  /**
   * @task kvimpl
   */
  public function destroyCache() {
    foreach ($this->cachesBackward as $cache) {
      $cache->destroyCache();
    }
  }

}
