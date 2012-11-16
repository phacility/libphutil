<?php

/**
 * Interface to a key-value cache like Memcache or APC. This class provides a
 * uniform interface to multiple different key-value caches and integration
 * with PhutilServiceProfiler.
 *
 * @task  kvimpl    Key-Value Cache Implementation
 * @group cache
 */
abstract class PhutilKeyValueCache {

  protected $profiler;

  public function setProfiler(PhutilServiceProfiler $profiler) {
    $this->profiler = $profiler;
    return $this;
  }

  public function isAvailable() {
    return false;
  }

  public function getKey($key, $default = null, $ttl = null) {
    $map = $this->getKeys(array($key));
    return idx($map, $key, $default);
  }

  public function setKey($key, $value, $ttl = null) {
    $this->setKeys(array($key => $value), $ttl);
  }

  public function deleteKey($key) {
    $this->deleteKeys(array($key));
  }

  abstract public function getKeys(array $keys, $ttl = null);
  abstract public function setKeys(array $keys, $ttl = null);
  abstract public function deleteKeys(array $keys);
  abstract public function destroyCache();

}
