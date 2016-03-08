<?php

final class PhutilGitHubFuture extends FutureProxy {

  private $future;
  private $accessToken;
  private $action;
  private $params;
  private $method = 'GET';
  private $headers = array();

  public function __construct() {
    parent::__construct(null);
  }

  public function setAccessToken($token) {
    $this->accessToken = $token;
    return $this;
  }

  public function setRawGitHubQuery($action, array $params = array()) {
    $this->action = $action;
    $this->params = $params;
    return $this;
  }

  public function setMethod($method) {
    $this->method = $method;
    return $this;
  }

  public function addHeader($key, $value) {
    $this->headers[] = array($key, $value);
    return $this;
  }

  protected function getProxiedFuture() {
    if (!$this->future) {
      $params = $this->params;

      if (!$this->action) {
        throw new Exception(
          pht(
            'You must %s!',
            'setRawGitHubQuery()'));
      }

      if (!$this->accessToken) {
        throw new Exception(
          pht(
            'You must %s!',
            'setAccessToken()'));
      }

      $uri = new PhutilURI('https://api.github.com/');
      $uri->setPath('/'.ltrim($this->action, '/'));

      $future = new HTTPSFuture($uri);
      $future->setData($this->params);
      $future->addHeader('Authorization', 'token '.$this->accessToken);
      // NOTE: GitHub requires a 'User-Agent' header.
      $future->addHeader('User-Agent', __CLASS__);
      $future->setMethod($this->method);

      foreach ($this->headers as $header) {
        list($key, $value) = $header;
        $future->addHeader($key, $value);
      }

      $this->future = $future;
    }

    return $this->future;
  }

  protected function didReceiveResult($result) {
    list($status, $body, $headers) = $result;

    if ($status->isError()) {
      if ($this->isRateLimitResponse($status, $headers)) {
        // Do nothing, this is a rate limit.
      } else if ($this->isNotModifiedResponse($status)) {
        // Do nothing, this is a "Not Modified" response.
      } else {
        // This is an error condition we do not expect.
        throw $status;
      }
    }

    try {
      if (strlen($body)) {
        $data = phutil_json_decode($body);
      } else {
        // This can happen for 304 responses.
        $data = array();
      }
    } catch (PhutilJSONParserException $ex) {
      throw new PhutilProxyException(
        pht('Expected JSON response from GitHub.'),
        $ex);
    }

    return id(new PhutilGitHubResponse())
      ->setStatus($status)
      ->setHeaders($headers)
      ->setBody($data);
  }

  private function isNotModifiedResponse($status) {
    return ($status->getStatusCode() == 304);
  }

  private function isRateLimitResponse($status, array $headers) {
    if ($status->getStatusCode() != 403) {
      return false;
    }

    foreach ($headers as $header) {
      list($key, $value) = $header;
      if (phutil_utf8_strtolower($key) === 'x-ratelimit-remaining') {
        if (!(int)$value) {
          return true;
        }
      }
    }

    return false;
  }

}
