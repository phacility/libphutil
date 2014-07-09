<?php

/**
 * @task  xaction Transaction Management
 */
abstract class AphrontDatabaseConnection implements PhutilQsprintfInterface {

  private $transactionState;

  abstract public function getInsertID();
  abstract public function getAffectedRows();
  abstract public function selectAllResults();
  abstract public function executeRawQuery($raw_query);
  abstract public function executeRawQueries(array $raw_queries);
  abstract public function close();

  public function queryData($pattern/* , $arg, $arg, ... */) {
    $args = func_get_args();
    array_unshift($args, $this);
    return call_user_func_array('queryfx_all', $args);
  }

  public function query($pattern/* , $arg, $arg, ... */) {
    $args = func_get_args();
    array_unshift($args, $this);
    return call_user_func_array('queryfx', $args);
  }


  public function supportsAsyncQueries() {
    return false;
  }

  public function supportsParallelQueries() {
    return false;
  }

  public function asyncQuery($raw_query) {
    throw new Exception('Async queries are not supported.');
  }

  public static function resolveAsyncQueries(array $conns, array $asyncs) {
    throw new Exception('Async queries are not supported.');
  }


/* -(  Transaction Management  )--------------------------------------------- */


  /**
   * Begin a transaction, or set a savepoint if the connection is already
   * transactional.
   *
   * @return this
   * @task xaction
   */
  public function openTransaction() {
    $state = $this->getTransactionState();
    $point = $state->getSavepointName();
    $depth = $state->getDepth();

    $new_transaction = ($depth == 0);
    if ($new_transaction) {
      $this->query('START TRANSACTION');
    } else {
      $this->query('SAVEPOINT '.$point);
    }

    $state->increaseDepth();

    return $this;
  }


  /**
   * Commit a transaction, or stage a savepoint for commit once the entire
   * transaction completes if inside a transaction stack.
   *
   * @return this
   * @task xaction
   */
  public function saveTransaction() {
    $state = $this->getTransactionState();
    $depth = $state->decreaseDepth();

    if ($depth == 0) {
      $this->query('COMMIT');
    }

    return $this;
  }


  /**
   * Rollback a transaction, or unstage the last savepoint if inside a
   * transaction stack.
   *
   * @return this
   */
  public function killTransaction() {
    $state = $this->getTransactionState();
    $depth = $state->decreaseDepth();

    if ($depth == 0) {
      $this->query('ROLLBACK');
    } else {
      $this->query('ROLLBACK TO SAVEPOINT '.$state->getSavepointName());
    }

    return $this;
  }


  /**
   * Returns true if the connection is transactional.
   *
   * @return bool True if the connection is currently transactional.
   * @task xaction
   */
  public function isInsideTransaction() {
    $state = $this->getTransactionState();
    return ($state->getDepth() > 0);
  }


  /**
   * Get the current @{class:AphrontDatabaseTransactionState} object, or create
   * one if none exists.
   *
   * @return AphrontDatabaseTransactionState Current transaction state.
   * @task xaction
   */
  protected function getTransactionState() {
    if (!$this->transactionState) {
      $this->transactionState = new AphrontDatabaseTransactionState();
    }
    return $this->transactionState;
  }


  /**
   * @task xaction
   */
  public function beginReadLocking() {
    $this->getTransactionState()->beginReadLocking();
    return $this;
  }


  /**
   * @task xaction
   */
  public function endReadLocking() {
    $this->getTransactionState()->endReadLocking();
    return $this;
  }


  /**
   * @task xaction
   */
  public function isReadLocking() {
    return $this->getTransactionState()->isReadLocking();
  }


  /**
   * @task xaction
   */
  public function beginWriteLocking() {
    $this->getTransactionState()->beginWriteLocking();
    return $this;
  }


  /**
   * @task xaction
   */
  public function endWriteLocking() {
    $this->getTransactionState()->endWriteLocking();
    return $this;
  }


  /**
   * @task xaction
   */
  public function isWriteLocking() {
    return $this->getTransactionState()->isWriteLocking();
  }

}
