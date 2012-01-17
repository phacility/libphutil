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
final class HTTPFutureResponseStatusTransport extends HTTPFutureResponseStatus {

  const ERROR_TIMEOUT             = 1;
  const ERROR_CONNECTION_ABORTED  = 2;
  const ERROR_CONNECTION_REFUSED  = 3;
  const ERROR_CONNECTION_FAILED   = 4;

  protected function getErrorCodeType($code) {
    return 'Transport';
  }

  public function isError() {
    return true;
  }

  public function isTimeout() {
    return ($this->getStatusCode() == self::ERROR_TIMEOUT);
  }

  protected function getErrorCodeDescription($code) {
    $map = array(
      self::ERROR_TIMEOUT =>
        'The request took too long to complete.',
      self::ERROR_CONNECTION_ABORTED =>
        'The remote host closed the connection before the request completed.',
      self::ERROR_CONNECTION_REFUSED =>
        'The remote host refused the connection. This usually means the '.
        'host is not running an HTTP server, or the network is blocking '.
        'connections from this machine. Verify you can connect to the '.
        'remote host from this host.',
      self::ERROR_CONNECTION_FAILED =>
        'Connection could not be initiated. This usually indicates a DNS '.
        'problem: verify the domain name is correct, that you can '.
        'perform a DNS lookup for it from this machine. (Did you add the '.
        'domain to `/etc/hosts` on some other machine, but not this one?)',
    );
    return idx($map, $code);
  }

}

