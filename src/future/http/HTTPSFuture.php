<?php

/**
 * Very basic HTTPS future.
 *
 * TODO: This class is extremely limited.
 *
 * @group futures
 */
final class HTTPSFuture extends BaseHTTPFuture {

  private static $multi;
  private static $results = array();
  private static $pool = array();

  private $handle;
  private $profilerCallID;
  private $cabundle;

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
   * Load contents of remote URI. Behaves pretty much like
   *  `@file_get_contents($uri)` but doesn't require `allow_url_fopen`.
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

  public function isReady() {
    if (isset($this->result)) {
      return true;
    }

    $uri = $this->getURI();
    $domain = id(new PhutilURI($uri))->getDomain();

    if (!$this->handle) {
      $profiler = PhutilServiceProfiler::getInstance();
      $this->profilerCallID = $profiler->beginServiceCall(
        array(
          'type' => 'http',
          'uri' => $uri,
        ));

      if (!self::$multi) {
        self::$multi = curl_multi_init();
        if (!self::$multi) {
          throw new Exception('curl_multi_init() failed!');
        }
      }

      if (!empty(self::$pool[$domain])) {
        $curl = array_pop(self::$pool[$domain]);
      } else {
        $curl = curl_init();
        if (!$curl) {
          throw new Exception('curl_init() failed!');
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

      $data = $this->getData();
      if ($data) {

        // NOTE: PHP's cURL implementation has a piece of magic which treats
        // parameters as file paths if they begin with '@'. This means that
        // an array like "array('name' => '@/usr/local/secret')" will attempt to
        // read that file off disk and send it to the remote server. This
        // behavior is pretty surprising, and it can easily become a relatively
        // severe security vulnerability which allows an attacker to read any
        // file the HTTP process has access to. Since this feature is very
        // dangerous and not particularly useful, we prevent its use.
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

      $saw_expect = false;
      for ($ii = 0; $ii < count($headers); $ii++) {
        list($name, $value) = $headers[$ii];
        $headers[$ii] = $name.': '.$value;
        if (!strncasecmp($name, 'Expect')) {
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
      curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
      curl_setopt($curl, CURLOPT_FOLLOWLOCATION, true);
      curl_setopt($curl, CURLOPT_MAXREDIRS, 20);

      if (defined('CURLOPT_TIMEOUT_MS')) {
        // If CURLOPT_TIMEOUT_MS is available, use the higher-precision timeout.
        $timeout = max(1, ceil(1000 * $this->getTimeout()));
        curl_setopt($curl, CURLOPT_TIMEOUT_MS, $timeout);
      } else {
        // Otherwise, fall back to the lower-precision timeout.
        $timeout = max(1, ceil($this->getTimeout()));
        curl_setopt($curl, CURLOPT_TIMEOUT, $timeout);
      }

      // Try some decent fallbacks here:
      // - First, check if a cabundle path is already set (e.g. externally).
      // - Then, if a local custom.pem exists, use that, because it probably
      //   means that the user wants to override everything (also because the
      //   user might not have access to change the box's php.ini to add
      //   curl.cainfo.
      // - Otherwise, try using curl.cainfo. If it's set explicitly, it's
      //   probably reasonable to try using it before we fall back to what
      //   libphutil ships with.
      // - Lastly, try the default that libphutil ships with. If it doesn't
      //   work, give up and yell at the user.

      if (!$this->getCABundle()) {
        $caroot = dirname(phutil_get_library_root('phutil')).'/resources/ssl/';
        $ini_val = ini_get('curl.cainfo');
        if (Filesystem::pathExists($caroot.'custom.pem')) {
          $this->setCABundleFromPath($caroot.'custom.pem');
        } else if ($ini_val) {
          // TODO: We can probably do a pathExists() here, even.
          $this->setCABundleFromPath($ini_val);
        } else {
          $this->setCABundleFromPath($caroot.'default.pem');
        }
      }

      curl_setopt($curl, CURLOPT_CAINFO, $this->getCABundle());
      curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, true);
      curl_setopt($curl, CURLOPT_SSLVERSION, 0);
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

    $info = self::$results[(int)$curl];
    $result = curl_multi_getcontent($curl);
    $err_code = $info['result'];

    if ($err_code) {
      $status = new HTTPFutureResponseStatusCURL($err_code, $uri);
      $body = null;
      $headers = array();
      $this->result = array($status, $body, $headers);
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
    self::$pool[$domain][] = $curl;

    $profiler = PhutilServiceProfiler::getInstance();
    $profiler->endServiceCall($this->profilerCallID, array());

    return true;
  }
}
