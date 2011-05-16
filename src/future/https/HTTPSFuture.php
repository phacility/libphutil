<?php

/*
 * Copyright 2011 Facebook, Inc.
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
 * Very basic HTTPS future.
 *
 * TODO: This class is extremely limited.
 *
 * @group futures
 */
class HTTPSFuture extends Future {

  private $timeout = 30;
  private $uri;
  private $data;

  /**
   * Set a timeout for the service call.
   *
   * @param float Maximum timeout in seconds.
   * @return this
   */
  public function setTimeout($timeout) {
    $this->timeout = $timeout;
    return $this;
  }

  public function __construct($uri, array $data = array()) {
    $this->uri = $uri;
    $this->data = $data;
  }

  public function isReady() {
    if (isset($this->result)) {
      return true;
    }

    $uri = $this->uri;
    $data = $this->data;

    $curl = curl_init();
    curl_setopt($curl, CURLOPT_URL, $uri);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
    if ($data) {
      curl_setopt($curl, CURLOPT_POSTFIELDS, http_build_query($data));
    }
    $timeout = max(1, ceil($this->timeout));
    curl_setopt($curl, CURLOPT_TIMEOUT, $timeout);
    $result = curl_exec($curl);

    $err = curl_errno($curl);

    if ($err) {
      $this->result = array(2000 + $err, curl_error($curl));
    } else {
      $this->result = array(200, $result);
    }

    curl_close($curl);

    return true;
  }
}
