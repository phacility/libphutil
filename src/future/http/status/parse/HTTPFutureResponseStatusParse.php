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
 * @group futures
 */
final class HTTPFutureResponseStatusParse extends HTTPFutureResponseStatus {

  const ERROR_MALFORMED_RESPONSE = 1;

  public function __construct($code, $raw_response) {
    $this->rawResponse = $raw_response;
    parent::__construct($code);
  }

  protected function getErrorCodeType($code) {
    return 'Parse';
  }

  public function isError() {
    return true;
  }

  public function isTimeout() {
    return false;
  }

  protected function getErrorCodeDescription($code) {
    return
      "The remote host returned something other than an HTTP response: ".
      $this->rawResponse;
  }

}

