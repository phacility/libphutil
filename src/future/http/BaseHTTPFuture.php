<?php

/**
 * Execute HTTP requests with a future-oriented API. For example:
 *
 *   $future = new HTTPFuture('http://www.example.com/');
 *   list($status, $body, $headers) = $future->resolve();
 *
 * This is an abstract base class which defines the API that HTTP futures
 * conform to. Concrete implementations are available in @{class:HTTPFuture}
 * and @{class:HTTPSFuture}. All futures return a <status, body, header> tuple
 * when resolved; status is an object of class @{class:HTTPFutureResponseStatus}
 * and may represent any of a wide variety of errors in the transport layer,
 * a support library, or the actual HTTP exchange.
 *
 * @task create Creating a New Request
 * @task config Configuring the Request
 * @task resolve Resolving the Request
 * @task internal Internals
 */
abstract class BaseHTTPFuture extends Future {

  private $method   = 'GET';
  private $timeout  = 300.0;
  private $headers  = array();
  private $uri;
  private $data;
  private $expect;


/* -(  Creating a New Request  )--------------------------------------------- */


  /**
   * Build a new future which will make an HTTP request to a given URI, with
   * some optional data payload. Since this class is abstract you can't actually
   * instantiate it; instead, build a new @{class:HTTPFuture} or
   * @{class:HTTPSFuture}.
   *
   * @param string Fully-qualified URI to send a request to.
   * @param mixed  String or array to include in the request. Strings will be
   *               transmitted raw; arrays will be encoded and sent as
   *               'application/x-www-form-urlencoded'.
   * @task create
   */
  final public function __construct($uri, $data = array()) {
    $this->setURI((string)$uri);
    $this->setData($data);
  }


/* -(  Configuring the Request  )-------------------------------------------- */


  /**
   * Set a timeout for the service call. If the request hasn't resolved yet,
   * the future will resolve with a status that indicates the request timed
   * out. You can determine if a status is a timeout status by calling
   * isTimeout() on the status object.
   *
   * @param float Maximum timeout, in seconds.
   * @return this
   * @task config
   */
  public function setTimeout($timeout) {
    $this->timeout = $timeout;
    return $this;
  }


  /**
   * Get the currently configured timeout.
   *
   * @return float Maximum number of seconds the request will execute for.
   * @task config
   */
  public function getTimeout() {
    return $this->timeout;
  }


  /**
   * Select the HTTP method (e.g., "GET", "POST", "PUT") to use for the request.
   * By default, requests use "GET".
   *
   * @param string HTTP method name.
   * @return this
   * @task config
   */
  final public function setMethod($method) {
    static $supported_methods = array(
      'GET'     => true,
      'POST'    => true,
      'PUT'     => true,
      'DELETE'  => true,
    );

    if (empty($supported_methods[$method])) {
      throw new Exception(
        pht(
          "The HTTP method '%s' is not supported. Supported HTTP methods ".
          "are: %s.",
          $method,
          implode(', ', array_keys($supported_methods))));
    }

    $this->method = $method;
    return $this;
  }


  /**
   * Get the HTTP method the request will use.
   *
   * @return string HTTP method name, like "GET".
   * @task config
   */
  final public function getMethod() {
    return $this->method;
  }


  /**
   * Set the URI to send the request to. Note that this is also a constructor
   * parameter.
   *
   * @param string URI to send the request to.
   * @return this
   * @task config
   */
  public function setURI($uri) {
    $this->uri = (string)$uri;
    return $this;
  }


  /**
   * Get the fully-qualified URI the request will be made to.
   *
   * @return string URI the request will be sent to.
   * @task config
   */
  public function getURI() {
    return $this->uri;
  }


  /**
   * Provide data to send along with the request. Note that this is also a
   * constructor parameter; it may be more convenient to provide it there. Data
   * must be a string (in which case it will be sent raw) or an array (in which
   * case it will be encoded and sent as 'application/x-www-form-urlencoded').
   *
   * @param mixed Data to send with the request.
   * @return this
   * @task config
   */
  public function setData($data) {
    if (!is_string($data) && !is_array($data)) {
      throw new Exception(pht('Data parameter must be an array or string.'));
    }
    $this->data = $data;
    return $this;
  }


  /**
   * Get the data which will be sent with the request.
   *
   * @return mixed Data which will be sent.
   * @task config
   */
  public function getData() {
    return $this->data;
  }


  /**
   * Add an HTTP header to the request. The same header name can be specified
   * more than once, which will cause multiple headers to be sent.
   *
   * @param string Header name, like "Accept-Language".
   * @param string Header value, like "en-us".
   * @return this
   * @task config
   */
  public function addHeader($name, $value) {
    $this->headers[] = array($name, $value);
    return $this;
  }


  /**
   * Get headers which will be sent with the request. Optionally, you can
   * provide a filter, which will return only headers with that name. For
   * example:
   *
   *   $all_headers = $future->getHeaders();
   *   $just_user_agent = $future->getHeaders('User-Agent');
   *
   * In either case, an array with all (or all matching) headers is returned.
   *
   * @param string|null Optional filter, which selects only headers with that
   *                    name if provided.
   * @return array      List of all (or all matching) headers.
   * @task config
   */
  public function getHeaders($filter = null) {
    $filter = strtolower($filter);

    $result = array();
    foreach ($this->headers as $header) {
      list($name, $value) = $header;
      if (!$filter || ($filter == strtolower($name))) {
        $result[] = $header;
      }
    }

    return $result;
  }

  /**
   * Set the status codes that are expected in the response.
   * If set, isError on the status object will return true for status codes
   * that are not in the input array. Otherwise, isError will be true for any
   * HTTP status code outside the 2xx range (notwithstanding other errors such
   * as connection or transport issues).
   *
   * @param array|null List of expected HTTP status codes.
   *
   * @return this
   * @task config
   */
  public function setExpectStatus($status_codes) {
    $this->expect = $status_codes;
    return $this;
  }

  /**
   * Return list of expected status codes, or null if not set.
   *
   * @return array|null List of expected status codes.
   */
  public function getExpectStatus() {
    return $this->expect;
  }


  /**
   * Add a HTTP basic authentication header to the request.
   *
   * @param string                Username to authenticate with.
   * @param PhutilOpaqueEnvelope  Password to authenticate with.
   * @return this
   * @task config
   */
  public function setHTTPBasicAuthCredentials(
    $username,
    PhutilOpaqueEnvelope $password) {

    $password_plaintext = $password->openEnvelope();
    $credentials = base64_encode($username.':'.$password_plaintext);

    return $this->addHeader('Authorization', 'Basic '.$credentials);
  }

  public function getHTTPRequestByteLength() {
    // NOTE: This isn't very accurate, but it's only used by the "--trace"
    // call profiler to help pick out huge requests.
    $data = $this->getData();

    if (is_scalar($data)) {
      return strlen($data);
    }

    return strlen(http_build_query($data, '', '&'));
  }


/* -(  Resolving the Request  )---------------------------------------------- */


  /**
   * Exception-oriented @{method:resolve}. Throws if the status indicates an
   * error occurred.
   *
   * @return tuple  HTTP request result <body, headers> tuple.
   * @task resolve
   */
  final public function resolvex() {
    $result = $this->resolve();

    list($status, $body, $headers) = $result;
    if ($status->isError()) {
      throw $status;
    }

    return array($body, $headers);
  }


/* -(  Internals  )---------------------------------------------------------- */


  /**
   * Parse a raw HTTP response into a <status, body, headers> tuple.
   *
   * @param string Raw HTTP response.
   * @return tuple Valid resolution tuple.
   * @task internal
   */
  protected function parseRawHTTPResponse($raw_response) {
    $rex_base = "@^(?P<head>.*?)\r?\n\r?\n(?P<body>.*)$@s";
    $rex_head = "@^HTTP/\S+ (?P<code>\d+) ?(?P<status>.*?)".
                "(?:\r?\n(?P<headers>.*))?$@s";

    // We need to parse one or more header blocks in case we got any
    // "HTTP/1.X 100 Continue" nonsense back as part of the response. This
    // happens with HTTPS requests, at the least.
    $response = $raw_response;
    while (true) {
      $matches = null;
      if (!preg_match($rex_base, $response, $matches)) {
        return $this->buildMalformedResult($raw_response);
      }

      $head = $matches['head'];
      $body = $matches['body'];

      if (!preg_match($rex_head, $head, $matches)) {
        return $this->buildMalformedResult($raw_response);
      }

      $response_code = (int)$matches['code'];
      $response_status = strtolower($matches['status']);
      if ($response_code == 100) {
        // This is HTTP/1.X 100 Continue, so this whole chunk is moot.
        $response = $body;
      } else if (($response_code == 200) &&
                 ($response_status == 'connection established')) {
        // When tunneling through an HTTPS proxy, we get an initial header
        // block like "HTTP/1.X 200 Connection established", then newlines,
        // then the normal response. Drop this chunk.
        $response = $body;
      } else {
        $headers = $this->parseHeaders(idx($matches, 'headers'));
        break;
      }
    }

    $status = new HTTPFutureHTTPResponseStatus(
      $response_code,
      $body,
      $headers,
      $this->expect);

    return array($status, $body, $headers);
  }

  /**
   * Parse an HTTP header block.
   *
   * @param string Raw HTTP headers.
   * @return list List of HTTP header tuples.
   * @task internal
   */
  protected function parseHeaders($head_raw) {
    $rex_header = '@^(?P<name>.*?):\s*(?P<value>.*)$@';

    $headers = array();

    if (!$head_raw) {
      return $headers;
    }

    $headers_raw = preg_split("/\r?\n/", $head_raw);
    foreach ($headers_raw as $header) {
      $m = null;
      if (preg_match($rex_header, $header, $m)) {
        $headers[] = array($m['name'], $m['value']);
      } else {
        $headers[] = array($header, null);
      }
    }

    return $headers;
  }


  /**
   * Find value of the first header with given name.
   *
   * @param list List of headers from `resolve()`.
   * @param string Case insensitive header name.
   * @return string Value of the header or null if not found.
   * @task resolve
   */
  public static function getHeader(array $headers, $search) {
    assert_instances_of($headers, 'array');
    foreach ($headers as $header) {
      list($name, $value) = $header;
      if (strcasecmp($name, $search) == 0) {
        return $value;
      }
    }
    return null;
  }


  /**
   * Build a result tuple indicating a parse error resulting from a malformed
   * HTTP response.
   *
   * @return tuple Valid resolution tuple.
   * @task internal
   */
  protected function buildMalformedResult($raw_response) {
    $body = null;
    $headers = array();

    $status = new HTTPFutureParseResponseStatus(
      HTTPFutureParseResponseStatus::ERROR_MALFORMED_RESPONSE,
      $raw_response);
    return array($status, $body, $headers);
  }

}
