<?php

/**
 * Proxy future that implements OAuth1 request signing. For references, see:
 *
 *  RFC 5849: http://tools.ietf.org/html/rfc5849
 *  Guzzle: https://github.com/guzzle/guzzle/blob/master/src/Guzzle/Plugin/Oauth/OauthPlugin.php
 *
 */
final class PhutilOAuth1Future extends FutureProxy {

  private $uri;
  private $data;
  private $consumerKey;
  private $consumerSecret;
  private $signatureMethod;
  private $privateKey;
  private $method = 'POST';
  private $token;
  private $tokenSecret;
  private $nonce;
  private $timestamp;
  private $hasConstructedFuture;
  private $callbackURI;
  private $headers = array();
  private $timeout;

  public function setCallbackURI($callback_uri) {
    $this->callbackURI = $callback_uri;
    return $this;
  }

  public function setTimestamp($timestamp) {
    $this->timestamp = $timestamp;
    return $this;
  }

  public function setNonce($nonce) {
    $this->nonce = $nonce;
    return $this;
  }

  public function setTokenSecret($token_secret) {
    $this->tokenSecret = $token_secret;
    return $this;
  }

  public function setToken($token) {
    $this->token = $token;
    return $this;
  }

  public function setPrivateKey(PhutilOpaqueEnvelope $private_key) {
    $this->privateKey = $private_key;
    return $this;
  }

  public function setSignatureMethod($signature_method) {
    $this->signatureMethod = $signature_method;
    return $this;
  }

  public function setConsumerKey($consumer_key) {
    $this->consumerKey = $consumer_key;
    return $this;
  }

  public function setConsumerSecret(PhutilOpaqueEnvelope $consumer_secret) {
    $this->consumerSecret = $consumer_secret;
    return $this;
  }

  public function setMethod($method) {
    $this->method = $method;
    return $this;
  }

  public function setTimeout($timeout) {
    $this->timeout = $timeout;
    return $this;
  }

  public function getTimeout() {
    return $this->timeout;
  }

  public function __construct($uri, $data = array()) {
    $this->uri = new PhutilURI((string)$uri);
    $this->data = $data;
    $this->setProxiedFuture(new HTTPSFuture($uri, $data));
  }

  public function getSignature() {
    $params = array();

    // NOTE: The JIRA API uses JSON-encoded request bodies which are not
    // signed, and OAuth1 provides no real way to sign a nonparameterized
    // request body. Possibly we should split this apart into flags which
    // control which data is signed, but for now this rule seems to cover
    // all the use cases.

    if (is_array($this->data)) {
      $params = $this->data;
    }

    $params = $params
            + $this->uri->getQueryParamsAsMap()
            + $this->getOAuth1Headers();

    return $this->sign($params);
  }

  public function addHeader($name, $value) {
    // If we haven't built the future yet, hold on to the header until after
    // we do, since there might be more changes coming which will affect the
    // signature process.

    if (!$this->hasConstructedFuture) {
      $this->headers[] = array($name, $value);
    } else {
      $this->getProxiedFuture()->addHeader($name, $value);
    }
    return $this;
  }

  protected function getProxiedFuture() {
    $future = parent::getProxiedFuture();

    if (!$this->hasConstructedFuture) {
      $future->setMethod($this->method);

      $oauth_headers = $this->getOAuth1Headers();
      $oauth_headers['oauth_signature'] = $this->getSignature();

      $full_oauth_header = array();
      foreach ($oauth_headers as $header => $value) {
        $full_oauth_header[] = $header.'="'.urlencode($value).'"';
      }
      $full_oauth_header = 'OAuth '.implode(', ', $full_oauth_header);

      $future->addHeader('Authorization', $full_oauth_header);

      foreach ($this->headers as $header) {
        $future->addHeader($header[0], $header[1]);
      }
      $this->headers = array();

      $timeout = $this->getTimeout();
      if ($timeout !== null) {
        $future->setTimeout($timeout);
      }

      $this->hasConstructedFuture = true;
    }

    return $future;
  }

  protected function didReceiveResult($result) {
    return $result;
  }

  private function getOAuth1Headers() {
    if (!$this->nonce) {
      $this->nonce = Filesystem::readRandomCharacters(32);
    }
    if (!$this->timestamp) {
      $this->timestamp = time();
    }

    $oauth_headers = array(
      'oauth_consumer_key' => $this->consumerKey,
      'oauth_signature_method' => $this->signatureMethod,
      'oauth_timestamp' => $this->timestamp,
      'oauth_nonce' => $this->nonce,
      'oauth_version' => '1.0',
    );

    if ($this->callbackURI) {
      $oauth_headers['oauth_callback'] = (string)$this->callbackURI;
    }

    if ($this->token) {
      $oauth_headers['oauth_token'] = $this->token;
    }

    return $oauth_headers;
  }

  private function sign(array $params) {
    ksort($params);

    $pstr = array();
    foreach ($params as $key => $value) {
      $pstr[] = rawurlencode($key).'='.rawurlencode($value);
    }
    $pstr = implode('&', $pstr);

    $sign_uri = clone $this->uri;
    $sign_uri->setFragment('');
    $sign_uri->removeAllQueryParams();

    $sign_uri->setProtocol(phutil_utf8_strtolower($sign_uri->getProtocol()));
    $protocol = $sign_uri->getProtocol();
    switch ($protocol) {
      case 'http':
        if ($sign_uri->getPort() == 80) {
          $sign_uri->setPort(null);
        }
        break;
      case 'https':
        if ($sign_uri->getPort() == 443) {
          $sign_uri->setPort(null);
        }
        break;
    }

    $method = rawurlencode(phutil_utf8_strtoupper($this->method));
    $sign_uri = rawurlencode((string)$sign_uri);
    $pstr = rawurlencode($pstr);

    $sign_input = "{$method}&{$sign_uri}&{$pstr}";
    return $this->signString($sign_input);
  }

  private function signString($string) {
    $consumer_secret = null;
    if ($this->consumerSecret) {
      $consumer_secret = $this->consumerSecret->openEnvelope();
    }

    $key = urlencode($consumer_secret).'&'.urlencode($this->tokenSecret);

    switch ($this->signatureMethod) {
      case 'HMAC-SHA1':
        if (!$this->consumerSecret) {
          throw new Exception(
            pht(
              "Signature method '%s' requires %s!",
              'HMAC-SHA1',
              'setConsumerSecret()'));
        }

        $hash = hash_hmac('sha1', $string, $key, true);
        return base64_encode($hash);
      case 'RSA-SHA1':
        if (!$this->privateKey) {
          throw new Exception(
            pht(
              "Signature method '%s' requires %s!",
              'RSA-SHA1',
              'setPrivateKey()'));
        }

        $cert = @openssl_pkey_get_private($this->privateKey->openEnvelope());
        if (!$cert) {
          throw new Exception(pht('%s failed!', 'openssl_pkey_get_private()'));
        }

        $pkey = @openssl_get_privatekey($cert);
        if (!$pkey) {
          throw new Exception(pht('%s failed!', 'openssl_get_privatekey()'));
        }

        $signature = null;
        $ok = openssl_sign($string, $signature, $pkey, OPENSSL_ALGO_SHA1);
        if (!$ok) {
          throw new Exception(pht('%s failed!', 'openssl_sign()'));
        }

        openssl_free_key($pkey);

        return base64_encode($signature);
      case 'PLAINTEXT':
        if (!$this->consumerSecret) {
          throw new Exception(
            pht(
              "Signature method '%s' requires %s!",
              'PLAINTEXT',
              'setConsumerSecret()'));
        }
        return $key;
      default:
        throw new Exception(pht("Unknown signature method '%s'!", $string));
    }
  }

  public function resolvex() {
    $result = $this->getProxiedFuture()->resolvex();
    return $this->didReceiveResult($result);
  }

  public function resolveJSON() {
    $result = $this->getProxiedFuture()->resolvex();
    $result = $this->didReceiveResult($result);
    list($body) = $result;

    try {
      return phutil_json_decode($body);
    } catch (PhutilJSONParserException $ex) {
      throw new PhutilProxyException(pht('Expected JSON.'), $ex);
    }
  }


}
