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
 * @group conduit
 */
class ConduitFuture extends HTTPFuture {

  protected $traceMode;
  protected $traceName;
  protected $startTime;
  protected $endTime;

  protected $client;
  protected $conduitMethod;

  public function setClient(ConduitClient $client, $method) {
    $this->client = $client;
    $this->conduitMethod = $method;
    return $this;
  }

  public function setTraceMode($trace_mode) {
    $this->traceMode = $trace_mode;
    return $this;
  }

  public function setTraceName($trace_name) {
    $this->traceName = $trace_name;
    return $this;
  }

  public function setStartTime($time) {
    $this->startTime = $time;
    return $this;
  }

  protected function getResult() {
    $result = parent::getResult();

    if (empty($this->endTime)) {
      $this->endTime = microtime(true);
      $time = (int)(1000 * ($this->endTime - $this->startTime));
      $time = number_format($time).' ms';
      if ($this->traceMode) {
        echo "[Conduit] <<< Completed {$this->traceName} in {$time}.\n";
      }
    }

    if ($result[0] !== 200) {
      throw new Exception(
        "Host returned an HTTP error response #{$result[0]} in response ".
        "to a Conduit method call.");
    }

    $data = json_decode($result[1], true);
    if (!is_array($data)) {
      throw new Exception(
        "Host returned HTTP/200, but invalid JSON data in response to ".
        "a Conduit method call:\n{$result[1]}");
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
