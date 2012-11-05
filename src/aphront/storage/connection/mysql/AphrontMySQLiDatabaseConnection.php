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

  protected function fetchAssoc($result) {
    return $result->fetch_assoc();
  }

  protected function getErrorCode($connection) {
    return $connection->errno;
  }

  protected function getErrorDescription($connection) {
    return $connection->error;
  }

}
