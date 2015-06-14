<?php

/**
 * Wraps another @{class:Future} and allows you to post-process its result once
 * it resolves.
 */
abstract class FutureProxy extends Future {

  private $proxied;

  public function __construct(Future $proxied = null) {
    if ($proxied) {
      $this->setProxiedFuture($proxied);
    }
  }

  public function setProxiedFuture(Future $proxied) {
    $this->proxied = $proxied;
    return $this;
  }

  protected function getProxiedFuture() {
    if (!$this->proxied) {
      throw new Exception(pht('The proxied future has not been provided yet.'));
    }
    return $this->proxied;
  }

  public function isReady() {
    return $this->getProxiedFuture()->isReady();
  }

  public function resolve($timeout = null) {
    $this->getProxiedFuture()->resolve($timeout);
    return $this->getResult();
  }

  public function setException(Exception $ex) {
    $this->getProxiedFuture()->setException($ex);
    return $this;
  }

  public function getException() {
    return $this->getProxiedFuture()->getException();
  }

  public function getReadSockets() {
    return $this->getProxiedFuture()->getReadSockets();
  }

  public function getWriteSockets() {
    return $this->getProxiedFuture()->getWriteSockets();
  }

  protected function getResult() {
    if ($this->result === null) {
      $result = $this->getProxiedFuture()->resolve();
      $result = $this->didReceiveResult($result);
      $this->result = $result;
    }
    return $this->result;
  }

  public function start() {
    $this->getProxiedFuture()->start();
    return $this;
  }

  abstract protected function didReceiveResult($result);

}
