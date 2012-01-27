<?php

/*
 * Copyright 2012 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * Wraps another Future and allows you to post-process its result once it
 * resolves.
 *
 * @group futures
 * @stable
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
      throw new Exception("The proxied future has not been provided yet.");
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
