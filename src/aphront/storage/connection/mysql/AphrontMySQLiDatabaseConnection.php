<?php

/**
 * @phutil-external-symbol class mysqli
 */
final class AphrontMySQLiDatabaseConnection
  extends AphrontBaseMySQLDatabaseConnection {

  public function escapeUTF8String($string) {
    $this->validateUTF8String($string);
    return $this->escapeBinaryString($string);
  }

  public function escapeBinaryString($string) {
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
        'About to call new mysqli(), but the PHP MySQLi extension is not '.
        'available!');
    }

    $user = $this->getConfiguration('user');
    $host = $this->getConfiguration('host');
    $port = $this->getConfiguration('port');
    $database = $this->getConfiguration('database');

    $pass = $this->getConfiguration('pass');
    if ($pass instanceof PhutilOpaqueEnvelope) {
      $pass = $pass->openEnvelope();
    }

    // If the host is "localhost", the port is ignored and mysqli attempts to
    // connect over a socket.
    if ($port) {
      if ($host === 'localhost' || $host === null) {
        $host = '127.0.0.1';
      }
    }

    $conn = @new mysqli(
      $host,
      $user,
      $pass,
      $database,
      $port);

    $errno = $conn->connect_errno;
    if ($errno) {
      $error = $conn->connect_error;
      throw new AphrontConnectionQueryException(
        "Attempt to connect to {$user}@{$host} failed with error ".
        "#{$errno}: {$error}.", $errno);
    }

    $ok = @$conn->set_charset('utf8mb4');
    if (!$ok) {
      $ok = $conn->set_charset('utf8');
    }

    return $conn;
  }

  protected function rawQuery($raw_query) {
    return @$this->requireConnection()->query($raw_query);
  }

  protected function rawQueries(array $raw_queries) {
    $conn = $this->requireConnection();

    $have_result = false;
    $results = array();

    foreach ($raw_queries as $key => $raw_query) {
      if (!$have_result) {
        // End line in front of semicolon to allow single line comments at the
        // end of queries.
        $have_result = $conn->multi_query(implode("\n;\n\n", $raw_queries));
      } else {
        $have_result = $conn->next_result();
      }

      array_shift($raw_queries);

      $result = $conn->store_result();
      if (!$result && !$this->getErrorCode($conn)) {
        $result = true;
      }
      $results[$key] = $this->processResult($result);
    }

    if ($conn->more_results()) {
      throw new Exception('There are some results left in the result set.');
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
