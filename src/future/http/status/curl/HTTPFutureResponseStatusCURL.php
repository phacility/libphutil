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
final class HTTPFutureResponseStatusCURL extends HTTPFutureResponseStatus {

  protected function getErrorCodeType($code) {
    return 'cURL';
  }

  public function isError() {
    return true;
  }

  public function isTimeout() {
    // NOTE: The PHP error constant for this is nonsensical (this is not an
    // error):
    //
    //    PHP: CURLE_OPERATION_TIMEOUTED
    //   cURL: CURLE_OPERATION_TIMEDOUT

    return ($this->getStatusCode() == CURLE_OPERATION_TIMEOUTED);
  }

  protected function getErrorCodeDescription($code) {
    $constants = get_defined_constants();

    $constant_name = null;
    foreach ($constants as $constant => $value) {
      if ($value == $code && preg_match('/^CURLE_/', $constant)) {
        $constant_name = '<'.$constant.'> ';
        break;
      }
    }


    $map = array(
      // Apparently there's no error constant for this? In cURL it's
      // CURLE_SSL_CACERT_BADFILE but there's no corresponding constant in
      // PHP.
      77 =>
        'The SSL CA Bundle "libphutil/resources/ssl/custom.pem" could not '.
        'be read or is not formatted correctly.',
      CURLE_SSL_CONNECT_ERROR =>
        'There was an error negotiating the SSL connection. This usually '.
        'indicates that the remote host has a bad SSL certificate, or your '.
        'local host has some sort of SSL misconfiguration which prevents it '.
        'from accepting the CA. If you are using a self-signed certificate, '.
        'see instructions in "libphutil/resources/ssl/README".',
      CURLE_OPERATION_TIMEOUTED =>
        'The request took too long to complete.',

    );

    return $constant_name.idx($map, $code);
  }

}

