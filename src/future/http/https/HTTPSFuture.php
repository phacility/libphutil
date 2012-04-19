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
 * Very basic HTTPS future.
 *
 * TODO: This class is extremely limited.
 *
 * @group futures
 */
final class HTTPSFuture extends BaseHTTPFuture {

  private static $handle;

  public function isReady() {
    if (isset($this->result)) {
      return true;
    }

    $uri = $this->getURI();
    $data = $this->getData();

    // NOTE: If possible, we reuse the handle so we can take advantage of
    // keepalives. This means every option has to be set every time, because
    // cURL will not clear the settings between requests.

    if (!self::$handle) {
      self::$handle = curl_init();
    }
    $curl = self::$handle;

    curl_setopt($curl, CURLOPT_URL, $uri);
    if ($data) {

      // NOTE: PHP's cURL implementation has a piece of magic which treats
      // parameters as file paths if they begin with '@'. This means that
      // an array like "array('name' => '@/usr/local/secret')" will attempt to
      // read that file off disk and send it to the remote server. This behavior
      // is pretty surprising, and it can easily become a relatively severe
      // security vulnerability which allows an attacker to read any file the
      // HTTP process has access to. Since this feature is very dangerous and
      // not particularly useful, we prevent its use.
      //
      // After PHP 5.2.0, it is sufficient to pass a string to avoid this
      // "feature" (it is only invoked in the array version). Prior to
      // PHP 5.2.0, we block any request which have string data beginning with
      // '@' (they would not work anyway).

      if (is_array($data)) {
        // Explicitly build a query string to prevent "@" security problems.
        $data = http_build_query($data, '', '&');
      }

      if ($data[0] == '@' && version_compare(phpversion(), '5.2.0', '<')) {
        throw new Exception(
          "Attempting to make an HTTP request including string data that ".
          "begins with '@'. Prior to PHP 5.2.0, this reads files off disk, ".
          "which creates a wide attack window for security vulnerabilities. ".
          "Upgrade PHP or avoid making cURL requests which begin with '@'.");
      }
      curl_setopt($curl, CURLOPT_POSTFIELDS, $data);
    } else {
      curl_setopt($curl, CURLOPT_POSTFIELDS, null);
    }

    $headers = $this->getHeaders();
    if ($headers) {
      for ($ii = 0; $ii < count($headers); $ii++) {
        list($name, $value) = $headers[$ii];
        $headers[$ii] = $name.': '.$value;
      }
      curl_setopt($curl, CURLOPT_HTTPHEADER, $headers);
    } else {
      curl_setopt($curl, CURLOPT_HTTPHEADER, array());
    }

    // Set the requested HTTP method, e.g. GET / POST / PUT.
    curl_setopt($curl, CURLOPT_CUSTOMREQUEST, $this->getMethod());

    // Make sure we get the headers and data back.
    curl_setopt($curl, CURLOPT_HEADER, true);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);

    if (defined('CURLOPT_TIMEOUT_MS')) {
      // If CURLOPT_TIMEOUT_MS is available, use the higher-precision timeout.
      $timeout = max(1, ceil(1000 * $this->getTimeout()));
      curl_setopt($curl, CURLOPT_TIMEOUT_MS, $timeout);
    } else {
      // Otherwise, fall back to the lower-precision timeout.
      $timeout = max(1, ceil($this->getTimeout()));
      curl_setopt($curl, CURLOPT_TIMEOUT, $timeout);
    }

    $ini_val = ini_get('curl.cainfo');
    if (!$ini_val) {
      $caroot = dirname(phutil_get_library_root('phutil')).'/resources/ssl/';
      if (Filesystem::pathExists($caroot.'custom.pem')) {
        $cabundle = $caroot.'custom.pem';
      } else {
        $cabundle = $caroot.'default.pem';
      }
      curl_setopt($curl, CURLOPT_CAINFO, $cabundle);
    }
    curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, true);

    $result = curl_exec($curl);
    $err_code = curl_errno($curl);

    if ($err_code) {
      $status = new HTTPFutureResponseStatusCURL($err_code);
      $body = null;
      $headers = array();
      $this->result = array($status, $body, $headers);
    } else {
      $this->result = $this->parseRawHTTPResponse($result);
    }

    // NOTE: Don't call curl_close(), we want to use keepalive if possible.

    return true;
  }
}
