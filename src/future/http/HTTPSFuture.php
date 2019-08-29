<?php

/**
 * Very basic HTTPS future.
 */
final class HTTPSFuture extends BaseHTTPFuture {

  private static $multi;
  private static $results = array();
  private static $pool = array();
  private static $globalCABundle;

  private $handle;
  private $profilerCallID;
  private $cabundle;
  private $followLocation = true;
  private $responseBuffer = '';
  private $responseBufferPos;
  private $files = array();
  private $temporaryFiles = array();
  private $rawBody;
  private $rawBodyPos = 0;
  private $fileHandle;

  private $downloadPath;
  private $downloadHandle;
  private $parser;

  /**
   * Create a temp file containing an SSL cert, and use it for this session.
   *
   * This allows us to do host-specific SSL certificates in whatever client
   * is using libphutil. e.g. in Arcanist, you could add an "ssl_cert" key
   * to a specific host in ~/.arcrc and use that.
   *
   * cURL needs this to be a file, it doesn't seem to be able to handle a string
   * which contains the cert. So we make a temporary file and store it there.
   *
   * @param string The multi-line, possibly lengthy, SSL certificate to use.
   * @return this
   */
  public function setCABundleFromString($certificate) {
    $temp = new TempFile();
    Filesystem::writeFile($temp, $certificate);
    $this->cabundle = $temp;
    return $this;
  }

  /**
   * Set the SSL certificate to use for this session, given a path.
   *
   * @param string The path to a valid SSL certificate for this session
   * @return this
   */
  public function setCABundleFromPath($path) {
    $this->cabundle = $path;
    return $this;
  }

  /**
   * Get the path to the SSL certificate for this session.
   *
   * @return string|null
   */
  public function getCABundle() {
    return $this->cabundle;
  }

  /**
   * Set whether Location headers in the response will be respected.
   * The default is true.
   *
   * @param boolean true to follow any Location header present in the response,
   *                false to return the request directly
   * @return this
   */
  public function setFollowLocation($follow) {
    $this->followLocation = $follow;
    return $this;
  }

  /**
   * Get whether Location headers in the response will be respected.
   *
   * @return boolean
   */
  public function getFollowLocation() {
    return $this->followLocation;
  }

  /**
   * Set the fallback CA certificate if one is not specified
   * for the session, given a path.
   *
   * @param string The path to a valid SSL certificate
   * @return void
   */
  public static function setGlobalCABundleFromPath($path) {
    self::$globalCABundle = $path;
  }
  /**
   * Set the fallback CA certificate if one is not specified
   * for the session, given a string.
   *
   * @param string The certificate
   * @return void
   */
  public static function setGlobalCABundleFromString($certificate) {
    $temp = new TempFile();
    Filesystem::writeFile($temp, $certificate);
    self::$globalCABundle = $temp;
  }

  /**
   * Get the fallback global CA certificate
   *
   * @return string
   */
  public static function getGlobalCABundle() {
    return self::$globalCABundle;
  }

  /**
   * Load contents of remote URI. Behaves pretty much like
   * `@file_get_contents($uri)` but doesn't require `allow_url_fopen`.
   *
   * @param string
   * @param float
   * @return string|false
   */
  public static function loadContent($uri, $timeout = null) {
    $future = new HTTPSFuture($uri);
    if ($timeout !== null) {
      $future->setTimeout($timeout);
    }
    try {
      list($body) = $future->resolvex();
      return $body;
    } catch (HTTPFutureResponseStatus $ex) {
      return false;
    }
  }

  public function setDownloadPath($download_path) {
    $this->downloadPath = $download_path;

    if (Filesystem::pathExists($download_path)) {
      throw new Exception(
        pht(
          'Specified download path "%s" already exists, refusing to '.
          'overwrite.'));
    }

    return $this;
  }

  /**
   * Attach a file to the request.
   *
   * @param string  HTTP parameter name.
   * @param string  File content.
   * @param string  File name.
   * @param string  File mime type.
   * @return this
   */
  public function attachFileData($key, $data, $name, $mime_type) {
    if (isset($this->files[$key])) {
      throw new Exception(
        pht(
          '%s currently supports only one file attachment for each '.
          'parameter name. You are trying to attach two different files with '.
          'the same parameter, "%s".',
          __CLASS__,
          $key));
    }

    $this->files[$key] = array(
      'data' => $data,
      'name' => $name,
      'mime' => $mime_type,
    );

    return $this;
  }

  public function isReady() {
    if (isset($this->result)) {
      return true;
    }

    $uri = $this->getURI();
    $domain = id(new PhutilURI($uri))->getDomain();

    $is_download = $this->isDownload();

    // See T13396. For now, use the streaming response parser only if we're
    // downloading the response to disk.
    $use_streaming_parser = (bool)$is_download;

    if (!$this->handle) {
      $uri_object = new PhutilURI($uri);
      $proxy = PhutilHTTPEngineExtension::buildHTTPProxyURI($uri_object);

      $profiler = PhutilServiceProfiler::getInstance();
      $this->profilerCallID = $profiler->beginServiceCall(
        array(
          'type' => 'http',
          'uri' => $uri,
          'proxy' => (string)$proxy,
        ));

      if (!self::$multi) {
        self::$multi = curl_multi_init();
        if (!self::$multi) {
          throw new Exception(pht('%s failed!', 'curl_multi_init()'));
        }
      }

      if (!empty(self::$pool[$domain])) {
        $curl = array_pop(self::$pool[$domain]);
      } else {
        $curl = curl_init();
        if (!$curl) {
          throw new Exception(pht('%s failed!', 'curl_init()'));
        }
      }

      $this->handle = $curl;
      curl_multi_add_handle(self::$multi, $curl);

      curl_setopt($curl, CURLOPT_URL, $uri);

      if (defined('CURLOPT_PROTOCOLS')) {
        // cURL supports a lot of protocols, and by default it will honor
        // redirects across protocols (for instance, from HTTP to POP3). Beyond
        // being very silly, this also has security implications:
        //
        //   http://blog.volema.com/curl-rce.html
        //
        // Disable all protocols other than HTTP and HTTPS.

        $allowed_protocols = CURLPROTO_HTTPS | CURLPROTO_HTTP;
        curl_setopt($curl, CURLOPT_PROTOCOLS, $allowed_protocols);
        curl_setopt($curl, CURLOPT_REDIR_PROTOCOLS, $allowed_protocols);
      }

      if (strlen($this->rawBody)) {
        if ($this->getData()) {
          throw new Exception(
            pht(
              'You can not execute an HTTP future with both a raw request '.
              'body and structured request data.'));
        }

        // We aren't actually going to use this file handle, since we are
        // just pushing data through the callback, but cURL gets upset if
        // we don't hand it a real file handle.
        $tmp = new TempFile();
        $this->fileHandle = fopen($tmp, 'r');

        // NOTE: We must set CURLOPT_PUT here to make cURL use CURLOPT_INFILE.
        // We'll possibly overwrite the method later on, unless this is really
        // a PUT request.
        curl_setopt($curl, CURLOPT_PUT, true);
        curl_setopt($curl, CURLOPT_INFILE, $this->fileHandle);
        curl_setopt($curl, CURLOPT_INFILESIZE, strlen($this->rawBody));
        curl_setopt($curl, CURLOPT_READFUNCTION,
          array($this, 'willWriteBody'));
      } else {
        $data = $this->formatRequestDataForCURL();
        curl_setopt($curl, CURLOPT_POSTFIELDS, $data);
      }

      $headers = $this->getHeaders();

      $saw_expect = false;
      for ($ii = 0; $ii < count($headers); $ii++) {
        list($name, $value) = $headers[$ii];
        $headers[$ii] = $name.': '.$value;
        if (!strncasecmp($name, 'Expect', strlen('Expect'))) {
          $saw_expect = true;
        }
      }
      if (!$saw_expect) {
        // cURL sends an "Expect" header by default for certain requests. While
        // there is some reasoning behind this, it causes a practical problem
        // in that lighttpd servers reject these requests with a 417. Both sides
        // are locked in an eternal struggle (lighttpd has introduced a
        // 'server.reject-expect-100-with-417' option to deal with this case).
        //
        // The ostensibly correct way to suppress this behavior on the cURL side
        // is to add an empty "Expect:" header. If we haven't seen some other
        // explicit "Expect:" header, do so.
        //
        // See here, for example, although this issue is fairly widespread:
        //   http://curl.haxx.se/mail/archive-2009-07/0008.html
        $headers[] = 'Expect:';
      }
      curl_setopt($curl, CURLOPT_HTTPHEADER, $headers);

      // Set the requested HTTP method, e.g. GET / POST / PUT.
      curl_setopt($curl, CURLOPT_CUSTOMREQUEST, $this->getMethod());

      // Make sure we get the headers and data back.
      curl_setopt($curl, CURLOPT_HEADER, true);
      curl_setopt($curl, CURLOPT_WRITEFUNCTION,
        array($this, 'didReceiveDataCallback'));

      if ($this->followLocation) {
        curl_setopt($curl, CURLOPT_FOLLOWLOCATION, true);
        curl_setopt($curl, CURLOPT_MAXREDIRS, 20);
      }

      if (defined('CURLOPT_TIMEOUT_MS')) {
        // If CURLOPT_TIMEOUT_MS is available, use the higher-precision timeout.
        $timeout = max(1, ceil(1000 * $this->getTimeout()));
        curl_setopt($curl, CURLOPT_TIMEOUT_MS, $timeout);
      } else {
        // Otherwise, fall back to the lower-precision timeout.
        $timeout = max(1, ceil($this->getTimeout()));
        curl_setopt($curl, CURLOPT_TIMEOUT, $timeout);
      }

      // We're going to try to set CAINFO below. This doesn't work at all on
      // OSX around Yosemite (see T5913). On these systems, we'll use the
      // system CA and then try to tell the user that their settings were
      // ignored and how to fix things if we encounter a CA-related error.
      // Assume we have custom CA settings to start with; we'll clear this
      // flag if we read the default CA info below.

      // Try some decent fallbacks here:
      // - First, check if a bundle is set explicitly for this request, via
      //   `setCABundle()` or similar.
      // - Then, check if a global bundle is set explicitly for all requests,
      //   via `setGlobalCABundle()` or similar.
      // - Then, if a local custom.pem exists, use that, because it probably
      //   means that the user wants to override everything (also because the
      //   user might not have access to change the box's php.ini to add
      //   curl.cainfo).
      // - Otherwise, try using curl.cainfo. If it's set explicitly, it's
      //   probably reasonable to try using it before we fall back to what
      //   libphutil ships with.
      // - Lastly, try the default that libphutil ships with. If it doesn't
      //   work, give up and yell at the user.

      if (!$this->getCABundle()) {
        $caroot = dirname(phutil_get_library_root('phutil')).'/resources/ssl/';
        $ini_val = ini_get('curl.cainfo');
        if (self::getGlobalCABundle()) {
          $this->setCABundleFromPath(self::getGlobalCABundle());
        } else if (Filesystem::pathExists($caroot.'custom.pem')) {
          $this->setCABundleFromPath($caroot.'custom.pem');
        } else if ($ini_val) {
          // TODO: We can probably do a pathExists() here, even.
          $this->setCABundleFromPath($ini_val);
        } else {
          $this->setCABundleFromPath($caroot.'default.pem');
        }
      }

      if ($this->canSetCAInfo()) {
        curl_setopt($curl, CURLOPT_CAINFO, $this->getCABundle());
      }

      $verify_peer = 1;
      $verify_host = 2;

      $extensions = PhutilHTTPEngineExtension::getAllExtensions();
      foreach ($extensions as $extension) {
        if ($extension->shouldTrustAnySSLAuthorityForURI($uri_object)) {
          $verify_peer = 0;
        }
        if ($extension->shouldTrustAnySSLHostnameForURI($uri_object)) {
          $verify_host = 0;
        }
      }

      curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, $verify_peer);
      curl_setopt($curl, CURLOPT_SSL_VERIFYHOST, $verify_host);
      curl_setopt($curl, CURLOPT_SSLVERSION, 0);

      if ($proxy) {
        curl_setopt($curl, CURLOPT_PROXY, (string)$proxy);
      }

      if ($is_download) {
        $this->downloadHandle = @fopen($this->downloadPath, 'wb+');
        if (!$this->downloadHandle) {
          throw new Exception(
            pht(
              'Failed to open filesystem path "%s" for writing.',
              $this->downloadPath));
        }
      }

      if ($use_streaming_parser) {
        $streaming_parser = id(new PhutilHTTPResponseParser())
          ->setFollowLocationHeaders($this->getFollowLocation());

        if ($this->downloadHandle) {
          $streaming_parser->setWriteHandle($this->downloadHandle);
        }

        $this->parser = $streaming_parser;
      }
    } else {
      $curl = $this->handle;

      if (!self::$results) {
        // NOTE: In curl_multi_select(), PHP calls curl_multi_fdset() but does
        // not check the return value of &maxfd for -1 until recent versions
        // of PHP (5.4.8 and newer). cURL may return -1 as maxfd in some unusual
        // situations; if it does, PHP enters select() with nfds=0, which blocks
        // until the timeout is reached.
        //
        // We could try to guess whether this will happen or not by examining
        // the version identifier, but we can also just sleep for only a short
        // period of time.
        curl_multi_select(self::$multi, 0.01);
      }
    }

    do {
      $active = null;
      $result = curl_multi_exec(self::$multi, $active);
    } while ($result == CURLM_CALL_MULTI_PERFORM);

    while ($info = curl_multi_info_read(self::$multi)) {
      if ($info['msg'] == CURLMSG_DONE) {
        self::$results[(int)$info['handle']] = $info;
      }
    }

    if (!array_key_exists((int)$curl, self::$results)) {
      return false;
    }

    // The request is complete, so release any temporary files we wrote
    // earlier.
    $this->temporaryFiles = array();

    $info = self::$results[(int)$curl];
    $result = $this->responseBuffer;
    $err_code = $info['result'];

    if ($err_code) {
      if (($err_code == CURLE_SSL_CACERT) && !$this->canSetCAInfo()) {
        $status = new HTTPFutureCertificateResponseStatus(
          HTTPFutureCertificateResponseStatus::ERROR_IMMUTABLE_CERTIFICATES,
          $uri);
      } else {
        $status = new HTTPFutureCURLResponseStatus($err_code, $uri);
      }

      $body = null;
      $headers = array();
      $this->result = array($status, $body, $headers);
    } else if ($this->parser) {
      $streaming_parser = $this->parser;
      try {
        $responses = $streaming_parser->getResponses();
        $final_response = last($responses);
        $result = array(
          $final_response->getStatus(),
          $final_response->getBody(),
          $final_response->getHeaders(),
        );
      } catch (HTTPFutureParseResponseStatus $ex) {
        $result = array($ex, null, array());
      }

      $this->result = $result;
    } else {
      // cURL returns headers of all redirects, we strip all but the final one.
      $redirects = curl_getinfo($curl, CURLINFO_REDIRECT_COUNT);
      $result = preg_replace('/^(.*\r\n\r\n){'.$redirects.'}/sU', '', $result);
      $this->result = $this->parseRawHTTPResponse($result);
    }

    curl_multi_remove_handle(self::$multi, $curl);
    unset(self::$results[(int)$curl]);

    // NOTE: We want to use keepalive if possible. Return the handle to a
    // pool for the domain; don't close it.
    if ($this->shouldReuseHandles()) {
      self::$pool[$domain][] = $curl;
    }

    if ($is_download) {
      if ($this->downloadHandle) {
        fflush($this->downloadHandle);
        fclose($this->downloadHandle);
        $this->downloadHandle = null;
      }
    }

    $profiler = PhutilServiceProfiler::getInstance();
    $profiler->endServiceCall($this->profilerCallID, array());

    return true;
  }


  /**
   * Callback invoked by cURL as it reads HTTP data from the response. We save
   * the data to a buffer.
   */
  public function didReceiveDataCallback($handle, $data) {
    if ($this->parser) {
      $this->parser->readBytes($data);
    } else {
      $this->responseBuffer .= $data;
    }

    return strlen($data);
  }


  /**
   * Read data from the response buffer.
   *
   * NOTE: Like @{class:ExecFuture}, this method advances a read cursor but
   * does not discard the data. The data will still be buffered, and it will
   * all be returned when the future resolves. To discard the data after
   * reading it, call @{method:discardBuffers}.
   *
   * @return string Response data, if available.
   */
  public function read() {
    if ($this->isDownload()) {
      throw new Exception(
        pht(
          'You can not read the result buffer while streaming results '.
          'to disk: there is no in-memory buffer to read.'));
    }

    if ($this->parser) {
      throw new Exception(
        pht(
          'Streaming reads are not currently supported by the streaming '.
          'parser.'));
    }

    $result = substr($this->responseBuffer, $this->responseBufferPos);
    $this->responseBufferPos = strlen($this->responseBuffer);
    return $result;
  }


  /**
   * Discard any buffered data. Normally, you call this after reading the
   * data with @{method:read}.
   *
   * @return this
   */
  public function discardBuffers() {
    if ($this->isDownload()) {
      throw new Exception(
        pht(
          'You can not discard the result buffer while streaming results '.
          'to disk: there is no in-memory buffer to discard.'));
    }

    if ($this->parser) {
      throw new Exception(
        pht(
          'Buffer discards are not currently supported by the streaming '.
          'parser.'));
    }

    $this->responseBuffer = '';
    $this->responseBufferPos = 0;
    return $this;
  }


  /**
   * Produces a value safe to pass to `CURLOPT_POSTFIELDS`.
   *
   * @return wild   Some value, suitable for use in `CURLOPT_POSTFIELDS`.
   */
  private function formatRequestDataForCURL() {
    // We're generating a value to hand to cURL as CURLOPT_POSTFIELDS. The way
    // cURL handles this value has some tricky caveats.

    // First, we can return either an array or a query string. If we return
    // an array, we get a "multipart/form-data" request. If we return a
    // query string, we get an "application/x-www-form-urlencoded" request.

    // Second, if we return an array we can't duplicate keys. The user might
    // want to send the same parameter multiple times.

    // Third, if we return an array and any of the values start with "@",
    // cURL includes arbitrary files off disk and sends them to an untrusted
    // remote server. For example, an array like:
    //
    //   array('name' => '@/usr/local/secret')
    //
    // ...will attempt to read that file off disk and transmit its contents with
    // the request. This behavior is pretty surprising, and it can easily
    // become a relatively severe security vulnerability which allows an
    // attacker to read any file the HTTP process has access to. Since this
    // feature is very dangerous and not particularly useful, we prevent its
    // use. Broadly, this means we must reject some requests because they
    // contain an "@" in an inconvenient place.

    // Generally, to avoid the "@" case and because most servers usually
    // expect "application/x-www-form-urlencoded" data, we try to return a
    // string unless there are files attached to this request.

    $data = $this->getData();
    $files = $this->files;

    $any_data = ($data || (is_string($data) && strlen($data)));
    $any_files = (bool)$this->files;

    if (!$any_data && !$any_files) {
      // No files or data, so just bail.
      return null;
    }

    if (!$any_files) {
      // If we don't have any files, just encode the data as a query string,
      // make sure it's not including any files, and we're good to go.
      if (is_array($data)) {
        $data = phutil_build_http_querystring($data);
      }

      $this->checkForDangerousCURLMagic($data, $is_query_string = true);

      return $data;
    }

    // If we've made it this far, we have some files, so we need to return
    // an array. First, convert the other data into an array if it isn't one
    // already.

    if (is_string($data)) {
      // NOTE: We explicitly don't want fancy array parsing here, so just
      // do a basic parse and then convert it into a dictionary ourselves.
      $parser = new PhutilQueryStringParser();
      $pairs = $parser->parseQueryStringToPairList($data);

      $map = array();
      foreach ($pairs as $pair) {
        list($key, $value) = $pair;
        if (array_key_exists($key, $map)) {
          throw new Exception(
            pht(
              'Request specifies two values for key "%s", but parameter '.
              'names must be unique if you are posting file data due to '.
              'limitations with cURL.',
              $key));
        }
        $map[$key] = $value;
      }

      $data = $map;
    }

    foreach ($data as $key => $value) {
      $this->checkForDangerousCURLMagic($value, $is_query_string = false);
    }

    foreach ($this->files as $name => $info) {
      if (array_key_exists($name, $data)) {
        throw new Exception(
          pht(
            'Request specifies a file with key "%s", but that key is also '.
            'defined by normal request data. Due to limitations with cURL, '.
            'requests that post file data must use unique keys.',
            $name));
      }

      $tmp = new TempFile($info['name']);
      Filesystem::writeFile($tmp, $info['data']);
      $this->temporaryFiles[] = $tmp;

      // In 5.5.0 and later, we can use CURLFile. Prior to that, we have to
      // use this "@" stuff.

      if (class_exists('CURLFile', false)) {
        $file_value = new CURLFile((string)$tmp, $info['mime'], $info['name']);
      } else {
        $file_value = '@'.(string)$tmp;
      }

      $data[$name] = $file_value;
    }

    return $data;
  }


  /**
   * Detect strings which will cause cURL to do horrible, insecure things.
   *
   * @param string  Possibly dangerous string.
   * @param bool    True if this string is being used as part of a query string.
   * @return void
   */
  private function checkForDangerousCURLMagic($string, $is_query_string) {
    if (empty($string[0]) || ($string[0] != '@')) {
      // This isn't an "@..." string, so it's fine.
      return;
    }

    if ($is_query_string) {
      if (version_compare(phpversion(), '5.2.0', '<')) {
        throw new Exception(
          pht(
            'Attempting to make an HTTP request, but query string data begins '.
            'with "%s". Prior to PHP 5.2.0 this reads files off disk, which '.
            'creates a wide attack window for security vulnerabilities. '.
            'Upgrade PHP or avoid making cURL requests which begin with "%s".',
            '@',
            '@'));
      }

      // This is safe if we're on PHP 5.2.0 or newer.
      return;
    }

    throw new Exception(
      pht(
        'Attempting to make an HTTP request which includes file data, but the '.
        'value of a query parameter begins with "%s". PHP interprets these '.
        'values to mean that it should read arbitrary files off disk and '.
        'transmit them to remote servers. Declining to make this request.',
        '@'));
  }


  /**
   * Determine whether CURLOPT_CAINFO is usable on this system.
   */
  private function canSetCAInfo() {
    // We cannot set CAInfo on OSX after Yosemite.

    $osx_version = PhutilExecutionEnvironment::getOSXVersion();
    if ($osx_version) {
      if (version_compare($osx_version, 14, '>=')) {
        return false;
      }
    }

    return true;
  }


  /**
   * Write a raw HTTP body into the request.
   *
   * You must write the entire body before starting the request.
   *
   * @param string Raw body.
   * @return this
   */
  public function write($raw_body) {
    $this->rawBody = $raw_body;
    return $this;
  }


  /**
   * Callback to pass data to cURL.
   */
  public function willWriteBody($handle, $infile, $len) {
    $bytes = substr($this->rawBody, $this->rawBodyPos, $len);
    $this->rawBodyPos += $len;
    return $bytes;
  }

  private function shouldReuseHandles() {
    $curl_version = curl_version();
    $version = idx($curl_version, 'version');

    // NOTE: cURL 7.43.0 has a bug where the POST body length is not recomputed
    // properly when a handle is reused. For this version of cURL, disable
    // handle reuse and accept a small performance penalty. See T8654.
    if ($version == '7.43.0') {
      return false;
    }

    return true;
  }

  private function isDownload() {
   return ($this->downloadPath !== null);
  }

}
