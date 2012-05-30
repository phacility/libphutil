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
 * @group conduit
 */
final class ConduitClient {

  protected $protocol;
  protected $host;
  protected $path;
  protected $port;
  protected $connectionID;
  protected $profilerCallID;

  protected $sessionKey;
  private $timeout = 300.0;

  public function getConnectionID() {
    return $this->connectionID;
  }

  public function __construct($uri) {
    $this->protocol = parse_url($uri, PHP_URL_SCHEME);
    $this->host = parse_url($uri, PHP_URL_HOST);
    $this->path = parse_url($uri, PHP_URL_PATH);
    $this->port = parse_url($uri, PHP_URL_PORT);

    if (!$this->host) {
      throw new Exception("Conduit URI '{$uri}' must include a valid host.");
    }

    $this->path = trim($this->path, '/').'/';
  }

  public function callMethodSynchronous($method, array $params) {
    return $this->callMethod($method, $params)->resolve();
  }

  public function didReceiveResponse($method, $data) {
    if ($this->profilerCallID !== null) {
      $profiler = PhutilServiceProfiler::getInstance();
      $profiler->endServiceCall(
        $this->profilerCallID,
        array());
    }

    if ($method == 'conduit.connect') {
      $this->sessionKey = idx($data, 'sessionKey');
      $this->connectionID = idx($data, 'connectionID');
    }
    return $data;
  }

  public function setTimeout($timeout) {
    $this->timeout = $timeout;
    return $this;
  }

  public function callMethod($method, array $params) {

    $meta = array();

    if ($this->sessionKey) {
      $meta['sessionKey'] = $this->sessionKey;
    }

    if ($this->connectionID) {
      $meta['connectionID'] = $this->connectionID;
    }

    if ($method == 'conduit.connect') {
      $certificate = idx($params, 'certificate');
      if ($certificate) {
        $token = time();
        $params['authToken'] = $token;
        $params['authSignature'] = sha1($token.$certificate);
      }
      unset($params['certificate']);
    }

    if ($meta) {
      $params['__conduit__'] = $meta;
    }

    $port = null;
    if ($this->port) {
      $port = ':'.$this->port;
    }

    $uri = $this->protocol.'://'.$this->host.$port.'/'.$this->path.$method;

    $data = array(
      'params'      => json_encode($params),
      'output'      => 'json',

      // This is a hint to Phabricator that the client expects a Conduit
      // response. It is not necessary, but provides better error messages in
      // some cases.
      '__conduit__' => true,
    );

    // NOTE: If we're on Windows, the socket-based HTTPFuture won't work
    // properly. In theory it may be fixable, but the easier fix is just to use
    // the cURL-based HTTPSFuture for HTTP. We'll lose the ability to
    // parallelize requests but things will work correctly.
    $use_https_future = ($this->protocol == 'https') || phutil_is_windows();

    if ($use_https_future) {
      $core_future = new HTTPSFuture($uri, $data);
    } else {
      $core_future = new HTTPFuture($uri, $data);
    }

    $core_future->setMethod('POST');
    $core_future->setTimeout($this->timeout);

    $profiler = PhutilServiceProfiler::getInstance();
    $this->profilerCallID = $profiler->beginServiceCall(
      array(
        'type'    => 'conduit',
        'method'  => $method,
      ));

    $conduit_future = new ConduitFuture($core_future);
    $conduit_future->setClient($this, $method);
    $conduit_future->isReady();

    return $conduit_future;
  }

}
