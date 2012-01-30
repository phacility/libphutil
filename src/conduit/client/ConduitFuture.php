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
final class ConduitFuture extends FutureProxy {

  protected $client;
  protected $conduitMethod;

  public function setClient(ConduitClient $client, $method) {
    $this->client = $client;
    $this->conduitMethod = $method;
    return $this;
  }

  protected function didReceiveResult($result) {
    list($status, $body, $headers) = $result;
    if ($status->isError()) {
      throw $status;
    }

    $raw = $body;

    $shield = 'for(;;);';
    if (!strncmp($raw, $shield, strlen($shield))) {
      $raw = substr($raw, strlen($shield));
    }

    $data = json_decode($raw, true);
    if (!is_array($data)) {
      throw new Exception(
        "Host returned HTTP/200, but invalid JSON data in response to ".
        "a Conduit method call:\n{$raw}");
    }

    if ($data['error_code']) {
      throw new ConduitClientException(
        $data['error_code'],
        $data['error_info']);
    }

    $result = $data['result'];

    $result = $this->client->didReceiveResponse(
      $this->conduitMethod,
      $result);

    return $result;
  }

}
