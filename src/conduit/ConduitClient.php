<?php

final class ConduitClient extends Phobject {

  private $uri;
  private $host;
  private $connectionID;
  private $sessionKey;
  private $timeout = 300.0;
  private $username;
  private $password;
  private $publicKey;
  private $privateKey;
  private $conduitToken;
  private $oauthToken;

  const AUTH_ASYMMETRIC = 'asymmetric';

  const SIGNATURE_CONSIGN_1 = 'Consign1.0/';

  public function getConnectionID() {
    return $this->connectionID;
  }

  public function __construct($uri) {
    $this->uri = new PhutilURI($uri);
    if (!strlen($this->uri->getDomain())) {
      throw new Exception(
        pht("Conduit URI '%s' must include a valid host.", $uri));
    }
    $this->host = $this->uri->getDomain();
  }

  /**
   * Override the domain specified in the service URI and provide a specific
   * host identity.
   *
   * This can be used to connect to a specific node in a cluster environment.
   */
  public function setHost($host) {
    $this->host = $host;
    return $this;
  }

  public function getHost() {
    return $this->host;
  }

  public function setConduitToken($conduit_token) {
    $this->conduitToken = $conduit_token;
    return $this;
  }

  public function getConduitToken() {
    return $this->conduitToken;
  }

  public function setOAuthToken($oauth_token) {
    $this->oauthToken = $oauth_token;
    return $this;
  }

  public function callMethodSynchronous($method, array $params) {
    return $this->callMethod($method, $params)->resolve();
  }

  public function didReceiveResponse($method, $data) {
    if ($method == 'conduit.connect') {
      $this->sessionKey = idx($data, 'sessionKey');
      $this->connectionID = idx($data, 'connectionID');
    }
    return $data;
  }

  public function setTimeout($timeout) {
    $this->timeout = $timeout;
    return $this;
  }

  public function setSigningKeys(
    $public_key,
    PhutilOpaqueEnvelope $private_key) {

    $this->publicKey = $public_key;
    $this->privateKey = $private_key;
    return $this;
  }

  public function callMethod($method, array $params) {

    $meta = array();

    if ($this->sessionKey) {
      $meta['sessionKey'] = $this->sessionKey;
    }

    if ($this->connectionID) {
      $meta['connectionID'] = $this->connectionID;
    }

    if ($method == 'conduit.connect') {
      $certificate = idx($params, 'certificate');
      if ($certificate) {
        $token = time();
        $params['authToken'] = $token;
        $params['authSignature'] = sha1($token.$certificate);
      }
      unset($params['certificate']);
    }

    if ($this->privateKey && $this->publicKey) {
      $meta['auth.type'] = self::AUTH_ASYMMETRIC;
      $meta['auth.key'] = $this->publicKey;
      $meta['auth.host'] = $this->getHostStringForSignature();

      $signature = $this->signRequest($method, $params, $meta);
      $meta['auth.signature'] = $signature;
    }

    if ($this->conduitToken) {
      $meta['token'] = $this->conduitToken;
    }

    if ($this->oauthToken) {
      $meta['access_token'] = $this->oauthToken;
    }

    if ($meta) {
      $params['__conduit__'] = $meta;
    }

    $uri = id(clone $this->uri)->setPath('/api/'.$method);

    $data = array(
      'params'      => json_encode($params),
      'output'      => 'json',

      // This is a hint to Phabricator that the client expects a Conduit
      // response. It is not necessary, but provides better error messages in
      // some cases.
      '__conduit__' => true,
    );

    // Always use the cURL-based HTTPSFuture, for proxy support and other
    // protocol edge cases that HTTPFuture does not support.
    $core_future = new HTTPSFuture($uri, $data);
    $core_future->addHeader('Host', $this->getHostStringForHeader());

    $core_future->setMethod('POST');
    $core_future->setTimeout($this->timeout);

    if ($this->username !== null) {
      $core_future->setHTTPBasicAuthCredentials(
        $this->username,
        $this->password);
    }

    return id(new ConduitFuture($core_future))
      ->setClient($this, $method);
  }

  public function setBasicAuthCredentials($username, $password) {
    $this->username = $username;
    $this->password = new PhutilOpaqueEnvelope($password);
    return $this;
  }

  private function getHostStringForHeader() {
    return $this->newHostString(false);
  }

  private function getHostStringForSignature() {
    return $this->newHostString(true);
  }

  /**
   * Build a string describing the host for this request.
   *
   * This method builds strings in two modes: with explicit ports for request
   * signing (which always include the port number) and with implicit ports
   * for use in the "Host:" header of requests (which omit the port number if
   * the port is the same as the default port for the protocol).
   *
   * This implicit port behavior is similar to what browsers do, so it is less
   * likely to get us into trouble with webserver configurations.
   *
   * @param bool True to include the port explicitly.
   * @return string String describing the host for the request.
   */
  private function newHostString($with_explicit_port) {
    $host = $this->getHost();

    $uri = new PhutilURI($this->uri);
    $protocol = $uri->getProtocol();
    $port = $uri->getPort();

    $implicit_ports = array(
      'https' => 443,
    );
    $default_port = 80;

    $implicit_port = idx($implicit_ports, $protocol, $default_port);

    if ($with_explicit_port) {
      if (!$port) {
        $port = $implicit_port;
      }
    } else {
      if ($port == $implicit_port) {
        $port = null;
      }
    }

    if (!$port) {
      $result = $host;
    } else {
      $result = $host.':'.$port;
    }

    return $result;
  }

  private function signRequest(
    $method,
    array $params,
    array $meta) {

    $input = self::encodeRequestDataForSignature(
      $method,
      $params,
      $meta);

    $signature = null;
    $result = openssl_sign(
      $input,
      $signature,
      $this->privateKey->openEnvelope());
    if (!$result) {
      throw new Exception(
        pht('Unable to sign Conduit request with signing key.'));
    }

    return self::SIGNATURE_CONSIGN_1.base64_encode($signature);
  }

  public static function verifySignature(
    $method,
    array $params,
    array $meta,
    $openssl_public_key) {

    $auth_type = idx($meta, 'auth.type');
    switch ($auth_type) {
      case self::AUTH_ASYMMETRIC:
        break;
      default:
        throw new Exception(
          pht(
            'Unable to verify request signature, specified "%s" '.
            '("%s") is unknown.',
            'auth.type',
            $auth_type));
    }

    $public_key = idx($meta, 'auth.key');
    if (!strlen($public_key)) {
      throw new Exception(
        pht(
          'Unable to verify request signature, no "%s" present in '.
          'request protocol information.',
          'auth.key'));
    }

    $signature = idx($meta, 'auth.signature');
    if (!strlen($signature)) {
      throw new Exception(
        pht(
          'Unable to verify request signature, no "%s" present '.
          'in request protocol information.',
          'auth.signature'));
    }

    $prefix = self::SIGNATURE_CONSIGN_1;
    if (strncmp($signature, $prefix, strlen($prefix)) !== 0) {
      throw new Exception(
        pht(
          'Unable to verify request signature, signature format is not '.
          'known.'));
    }
    $signature = substr($signature, strlen($prefix));

    $input = self::encodeRequestDataForSignature(
      $method,
      $params,
      $meta);

    $signature = base64_decode($signature);

    $trap = new PhutilErrorTrap();
      $result = @openssl_verify(
        $input,
        $signature,
        $openssl_public_key);
      $err = $trap->getErrorsAsString();
    $trap->destroy();

    if ($result === 1) {
      // Signature is good.
      return true;
    } else if ($result === 0) {
      // Signature is bad.
      throw new Exception(
        pht(
          'Request signature verification failed: signature is not correct.'));
    } else {
      // Some kind of error.
      if (strlen($err)) {
        throw new Exception(
          pht(
            'OpenSSL encountered an error verifying the request signature: %s',
            $err));
      } else {
        throw new Exception(
          pht(
            'OpenSSL encountered an unknown error verifying the request: %s',
            $err));
      }
    }
  }

  private static function encodeRequestDataForSignature(
    $method,
    array $params,
    array $meta) {

    unset($meta['auth.signature']);

    $structure = array(
      'method' => $method,
      'protocol' => $meta,
      'parameters' => $params,
    );

    return self::encodeRawDataForSignature($structure);
  }

  public static function encodeRawDataForSignature($data) {
    $out = array();

    if (is_array($data)) {
      if (phutil_is_natural_list($data)) {
        $out[] = 'A';
        $out[] = count($data);
        $out[] = ':';
        foreach ($data as $value) {
          $out[] = self::encodeRawDataForSignature($value);
        }
      } else {
        ksort($data);
        $out[] = 'O';
        $out[] = count($data);
        $out[] = ':';
        foreach ($data as $key => $value) {
          $out[] = self::encodeRawDataForSignature($key);
          $out[] = self::encodeRawDataForSignature($value);
        }
      }
    } else if (is_string($data)) {
      $out[] = 'S';
      $out[] = strlen($data);
      $out[] = ':';
      $out[] = $data;
    } else if (is_int($data)) {
      $out[] = 'I';
      $out[] = strlen((string)$data);
      $out[] = ':';
      $out[] = (string)$data;
    } else if (is_null($data)) {
      $out[] = 'N';
      $out[] = ':';
    } else if ($data === true) {
      $out[] = 'B1:';
    } else if ($data === false) {
      $out[] = 'B0:';
    } else {
      throw new Exception(
        pht(
          'Unexpected data type in request data: %s.',
          gettype($data)));
    }

    return implode('', $out);
  }

}
