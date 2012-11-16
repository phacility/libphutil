<?php

/**
 * @task  memcache Managing Memcache
 * @group cache
 */
final class PhutilKeyValueCacheMemcache extends PhutilKeyValueCache {

  private $servers = array();
  private $connections = array();

  public function isAvailable() {
    return function_exists('memcache_pconnect');
  }

  public function getKeys(array $keys, $ttl = null) {

    $buckets = $this->bucketKeys($keys);
    $results = array();
    $call_id = null;

    foreach ($buckets as $bucket => $bucket_keys) {
      $conn = $this->getConnection($bucket);

      if ($this->profiler) {
        $call_id = $this->profiler->beginServiceCall(
          array(
            'type' => 'kvcache-get',
            'name' => 'memcache',
            'keys' => $bucket_keys,
          ));
      }

      $result = $conn->get($bucket_keys);

      if ($call_id) {
        $this->profiler->endServiceCall(
          $call_id,
          array(
            'hits' => array_keys($result),
          ));
      }

      $results += $result;
    }

    return $results;
  }

  public function setKeys(array $keys, $ttl = null) {
    $buckets = $this->bucketKeys(array_keys($keys));
    $call_id = null;

    foreach ($buckets as $bucket => $bucket_keys) {
      $conn = $this->getConnection($bucket);

      foreach ($bucket_keys as $key) {
        if ($this->profiler) {
          $call_id = $this->profiler->beginServiceCall(
            array(
              'type' => 'kvcache-set',
              'name' => 'memcache',
              'keys' => array($key),
            ));
        }

        $conn->set($key, $keys[$key], 0, $ttl);

        if ($call_id) {
          $this->profiler->endServiceCall($call_id, array());
        }
      }
    }
  }

  public function deleteKeys(array $keys) {
    $buckets = $this->bucketKeys($keys);
    $call_id = null;

    foreach ($buckets as $bucket => $bucket_keys) {
      $conn = $this->getConnection($bucket);
      foreach ($bucket_keys as $key) {
        if ($this->profiler) {
          $call_id = $this->profiler->beginServiceCall(
            array(
              'type' => 'kvcache-del',
              'name' => 'memcache',
              'keys' => array($key),
            ));
        }

        $conn->delete($key);

        if ($call_id) {
          $this->profiler->endServiceCall($call_id, array());
        }
      }
    }
  }

  public function destroyCache() {
    foreach ($this->servers as $key => $spec) {
      $this->getConnection($key)->flush();
    }
  }


/* -(  Managing Memcache  )-------------------------------------------------- */


  private function bucketKeys(array $keys) {
    $buckets = array();
    $n = count($this->servers);

    if (!$n) {
      throw new Exception("Call setServers() before using Memcache!");
    }

    foreach ($keys as $key) {
      $bucket = (int)((crc32($key) & 0x7FFFFFFF) % $n);
      $buckets[$bucket][] = $key;
    }

    return $buckets;
  }

  public function setServers(array $servers) {
    $this->servers = array_values($servers);
    return $this;
  }

  private function getConnection($server) {
    if (empty($this->connections[$server])) {
      $spec = $this->servers[$server];
      $host = $spec['host'];
      $port = $spec['port'];

      $call_id = null;
      if ($this->profiler) {
        $call_id = $this->profiler->beginServiceCall(
          array(
            'type' => 'kvcache-connect',
            'name' => 'memcache',
            'host' => $host,
          ));
      }

      $conn = memcache_pconnect($host, $spec['port']);

      if ($call_id) {
        $this->profiler->endServiceCall($call_id, array());
      }

      if (!$conn) {
        throw new Exception(
          "Unable to connect to memcache server ({$host}@{$port})!");
      }

      $this->connections[$server] = $conn;
    }
    return $this->connections[$server];
  }

}
