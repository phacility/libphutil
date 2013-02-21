<?php

/**
 * @group storage
 *
 * @phutil-external-symbol class mysqli
 */
final class AphrontMySQLiDatabaseConnection
  extends AphrontMySQLDatabaseConnectionBase {

  public function escapeString($string) {
    return $this->requireConnection()->escape_string($string);
  }

  public function getInsertID() {
    return $this->requireConnection()->insert_id;
  }

  public function getAffectedRows() {
    return $this->requireConnection()->affected_rows;
  }

  protected function closeConnection() {
    $this->requireConnection()->close();
  }

  protected function connect() {
    if (!class_exists('mysqli', false)) {
      throw new Exception(
        "About to call new mysqli(), but the PHP MySQLi extension is not ".
        "available!");
    }

    $user = $this->getConfiguration('user');
    $host = $this->getConfiguration('host');
    $database = $this->getConfiguration('database');

    $pass = $this->getConfiguration('pass');
    if ($pass instanceof PhutilOpaqueEnvelope) {
      $pass = $pass->openEnvelope();
    }

    $conn = @new mysqli(
      $host,
      $user,
      $pass,
      $database);

    $errno = $conn->connect_errno;
    if ($errno) {
      $error = $conn->connect_error;
      throw new AphrontQueryConnectionException(
        "Attempt to connect to {$user}@{$host} failed with error ".
        "#{$errno}: {$error}.", $errno);
    }

    $conn->set_charset('utf8');

    return $conn;
  }

  protected function rawQuery($raw_query) {
    return @$this->requireConnection()->query($raw_query);
  }

  protected function rawQueries(array $raw_queries) {
    $conn = $this->requireConnection();

    if (!$conn->multi_query(implode('; ', $raw_queries))) {
      $ex = $this->processResult(false);
      return array_fill_keys(array_keys($raw_queries), $ex);
    }

    $results = array();

    $processed_all = false;
    foreach ($raw_queries as $key => $raw_query) {
      $result = $conn->store_result();
      if ($this->getErrorCode($conn)) {
        $result = false;
      }
      $results[$key] = $this->processResult($result);

      if (!$conn->more_results()) {
        $processed_all = true;
        break;
      }
      $conn->next_result();
    }

    if (!$processed_all) {
      throw new Exception("There are some results left in the result set.");
    }

    return $results;
  }

  protected function freeResult($result) {
    $result->free_result();
  }

  protected function fetchAssoc($result) {
    return $result->fetch_assoc();
  }

  protected function getErrorCode($connection) {
    return $connection->errno;
  }

  protected function getErrorDescription($connection) {
    return $connection->error;
  }

  public function supportsAsyncQueries() {
    return defined('MYSQLI_ASYNC');
  }

  public function asyncQuery($raw_query) {
    $this->checkWrite($raw_query);
    $async = $this->beginAsyncConnection();
    $async->query($raw_query, MYSQLI_ASYNC);
    return $async;
  }

  public static function resolveAsyncQueries(array $conns, array $asyncs) {
    assert_instances_of($conns, 'AphrontMySQLiDatabaseConnection');
    assert_instances_of($asyncs, 'mysqli');

    $read = $error = $reject = array();
    foreach ($asyncs as $async) {
      $read[] = $error[] = $reject[] = $async;
    }

    if (!mysqli::poll($read, $error, $reject, 0)) {
      return array();
    }

    $results = array();
    foreach ($read as $async) {
      $key = array_search($async, $asyncs, $strict = true);
      $conn = $conns[$key];
      $conn->endAsyncConnection($async);
      $results[$key] = $conn->processResult($async->reap_async_query());
    }
    return $results;
  }

}
