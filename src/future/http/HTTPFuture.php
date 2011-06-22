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
 * Socket-based HTTP future, for making HTTP requests using future semantics.
 * This is an alternative to :CURLFuture which has better resolution behavior
 * (select()-based wait instead of busy wait) but fewer features. You should
 * prefer this class to :CURLFuture unless you need its advanced features (like
 * HTTP/1.1, chunked transfer encoding, gzip, etc.).
 *
 * Example Usage
 *
 *    $future = new HTTPFuture('http://www.example.com/');
 *    list($http_response_code, $response_body, $headers) = $future->resolve();
 *
 * @group futures
 */
class HTTPFuture extends Future {

  /** Remote host returned something other than an HTTP response. */
  const ERROR_MALFORMED_RESPONSE  = 1000;

  /** Future walltime exceeded the allowable walltime (see setTimeout()). */
  const ERROR_TIMEOUT             = 1001;

  /** Connection was aborted before writing was complete. */
  const ERROR_CONNECTION_ABORTED  = 1002;

  /** Connection was refused by remote host. */
  const ERROR_CONNECTION_REFUSED  = 1003;

  /** Connection failed entirely, hostname is probably invalid. */
  const ERROR_CONNECTION_FAILED   = 1004;

  protected $method   = 'GET';
  protected $uri;
  protected $data;
  protected $host;
  protected $port     = 80;
  protected $timeout  = 30.0;
  /**
   * Whether to log debugging output to scribe.  Hopefully, this will be a
   * short-term measure.
   */
  private $debug = false;
  /**
   * A string intended to uniquely identify this HTTPFuture for debugging
   * purposes.
   */
  private $debugFutureID = null;

  protected $socket;
  protected $writeBuffer;
  protected $response;
  protected $headers  = array();

  protected $stateConnected     = false;
  protected $stateWriteComplete = false;
  protected $stateReady         = false;
  protected $stateStartTime;

  public function __construct($uri, array $data = array()) {
    $this->data = $data;

    $parts = parse_url($uri);
    if (!$parts) {
      throw new Exception("Could not parse URI '{$uri}'.");
    }

    if (empty($parts['scheme']) || $parts['scheme'] !== 'http') {
      throw new Exception(
        "URI '{$uri}' must be fully qualified with 'http://' scheme.");
    }

    if (!isset($parts['host'])) {
      throw new Exception(
        "URI '{$uri}' must be fully qualified and include host name.");
    }

    $this->host = $parts['host'];
    $this->headers['Host'] = $this->host;

    if (!empty($parts['port'])) {
      $this->port = $parts['port'];
    }

    if (isset($parts['user']) || isset($parts['pass'])) {
      throw new Exception(
        "HTTP Basic Auth is not supported by HTTPFuture.");
    }

    if (isset($parts['path'])) {
      $this->uri = $parts['path'];
    } else {
      $this->uri = '/';
    }

    if (isset($parts['query'])) {
      $this->uri .= '?'.$parts['query'];
    }

  }

  public function getURI() {
    return $this->uri;
  }

  public function setHeader($header, $value) {
    $this->headers[$header] = $value;
    return $this;
  }

  public function setTimeout($timeout) {
    $this->timeout = $timeout;
    return $this;
  }

  public function setMethod($method) {
    if ($method !== 'GET' && $method !== 'POST') {
      throw new Exception('Only GET and POST are supported HTTP methods.');
    }
    $this->method = $method;
    return $this;
  }

  public function __destruct() {
    if ($this->socket) {
      @fclose($this->socket);
      $this->socket = null;
    }
  }

  public function getReadSockets() {
    if ($this->socket) {
      return array($this->socket);
    }
    return array();
  }

  public function getWriteSockets() {
    if (strlen($this->writeBuffer)) {
      return array($this->socket);
    }
    return array();
  }

  public function getDefaultUserAgent() {
    return 'HTTPFuture/1.0';
  }

  public function isReady() {
    if ($this->stateReady) {
      return true;
    }

    if (!$this->socket) {
      $this->stateStartTime = microtime(true);
      $this->socket = $this->buildSocket();
      if (!$this->socket) {
        return $this->stateReady;
      }
    }

    if (!$this->stateConnected) {
      $read   = array();
      $write  = array($this->socket);
      $except = array();
      $select = stream_select($read, $write, $except, $tv_sec = 0);
      if ($write) {
        $this->stateConnected = true;
      }
    }

    if ($this->stateConnected) {
      if (strlen($this->writeBuffer)) {
        $bytes = @fwrite($this->socket, $this->writeBuffer);
        if ($bytes === false) {
          throw new Exception("Failed to write to buffer.");
        } else if ($bytes) {
          $this->writeBuffer = substr($this->writeBuffer, $bytes);
        }
      }

      if (!strlen($this->writeBuffer)) {
        $this->stateWriteComplete = true;
      }

      while (($data = fread($this->socket, 32768)) || strlen($data)) {
        $this->response .= $data;
      }

      if ($data === false) {
        throw new Exception("Failed to read socket.");
      }
    }

    return $this->checkSocket();
  }

  protected function buildSocket() {

    $errno = null;
    $errstr = null;
    $socket = @stream_socket_client(
      'tcp://'.$this->host.':'.$this->port,
      $errno,
      $errstr,
      $ignored_connection_timeout = 1.0,
      STREAM_CLIENT_CONNECT | STREAM_CLIENT_ASYNC_CONNECT);

    if (!$socket) {
      $this->stateReady = true;
      $this->result = $this->buildErrorResult(self::ERROR_CONNECTION_FAILED);
      return null;
    }

    $ok = stream_set_blocking($socket, 0);
    if (!$ok) {
      throw new Exception("Failed to set stream nonblocking.");
    }

    $this->writeBuffer = $this->buildHTTPRequest();

    return $socket;
  }

  protected function checkSocket() {

    $timeout = false;
    $now = microtime(true);
    if ($now - $this->stateStartTime > $this->timeout) {
      $timeout = true;
    }

    if (!feof($this->socket) && !$timeout) {
      return false;
    }

    if ($timeout) {
      $result = $this->buildErrorResult(self::ERROR_TIMEOUT);
    } else if (!$this->stateConnected) {
      $result = $this->buildErrorResult(self::ERROR_CONNECTION_REFUSED);
    } else if (!$this->stateWriteComplete) {
      $result = $this->buildErrorResult(self::ERROR_CONNECTION_FAILED);
    } else {
      $result = $this->parseHTTPResponse($this->response);
    }

    $this->result     = $result;
    $this->stateReady = true;

    return true;
  }

  protected function buildErrorResult($error) {
    return array($error, null, array());
  }

  protected function parseHTTPResponse($response) {

    static $rex_base = "@^(?P<head>.*?)\r?\n\r?\n(?P<body>.*)$@s";
    static $rex_head = "@^HTTP/\S+ (?P<code>\d+) .*?(?:\r?\n(?P<headers>.*))?$@s";
    static $rex_header = '@^(?P<name>.*?):\s*(?P<value>.*)$@';

    static $malformed = array(
      self::ERROR_MALFORMED_RESPONSE,
      null,
      array(),
    );

    $matches = null;
    if (!preg_match($rex_base, $response, $matches)) {
      return $malformed;
    }

    $head = $matches['head'];
    $body = $matches['body'];

    if (!preg_match($rex_head, $head, $matches)) {
      return $malformed;
    }

    $response_code = (int)$matches['code'];

    $headers = array();
    if (isset($matches['headers'])) {
      $head_raw = $matches['headers'];
      if (strlen($head_raw)) {
        $headers_raw = preg_split("/\r?\n/", $head_raw);
        foreach ($headers_raw as $header) {
          $m = null;
          if (preg_match($rex_header, $header, $m)) {
            $headers[] = array($m['name'], $m['value']);
          } else {
            $headers[] = array($header, null);
          }
        }
      }
    }

    return array(
      $response_code,
      $body,
      $headers,
    );
  }

  public function buildHTTPRequest() {
    $data = http_build_query($this->data);
    $length = strlen($data);

    $force_headers = array();   // These are always sent.
    $default_headers = array(); // These can be overridden with setHeader().

    $uri = $this->uri;
    if ($this->method == 'GET') {
      if ($data) {
        if (strpos($uri, '?') !== false) {
          $uri .= '&'.$data;
        } else {
          $uri .= '?'.$data;
        }
      }
      $data = null;
      $length = 0;
    } else {
      $force_headers['Content-Type'] = 'application/x-www-form-urlencoded';
      $data .= "\r\n";
    }

    $force_headers['Content-Length'] = $length;
    $default_headers['User-Agent'] = $this->getDefaultUserAgent();

    $headers = $force_headers + $this->headers + $default_headers;

    foreach ($headers as $key => $header) {
      $headers[$key] = $key.': '.$header."\r\n";
    }

    return
      "{$this->method} {$uri} HTTP/1.0\r\n".
      implode('', $headers).
      "\r\n".
      $data;
  }

}
