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
abstract class HTTPFutureResponseStatus extends Exception {

  private $statusCode;
  private $uri;

  public function __construct($status_code, $uri = null) {
    $this->statusCode = $status_code;
    $this->uri = (string)$uri;

    $type = $this->getErrorCodeType($status_code);
    $description = $this->getErrorCodeDescription($status_code);

    $uri_info = '';
    if ($this->uri) {
      $uri_info = ' ('.$this->uri.')';
    }

    $message = rtrim("[{$type}/{$status_code}]{$uri_info} {$description}");

    parent::__construct($message);
  }


  final public function getStatusCode() {
    return $this->statusCode;
  }

  final public function getURI() {
    return $this->uri;
  }

  abstract public function isError();
  abstract public function isTimeout();

  abstract protected function getErrorCodeType($code);
  abstract protected function getErrorCodeDescription($code);

}

