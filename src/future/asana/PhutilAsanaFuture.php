<?php

final class PhutilAsanaFuture extends FutureProxy {

  private $future;
  private $accessToken;
  private $action;
  private $params;
  private $method = 'GET';
  private $timeout;

  public function __construct() {
    parent::__construct(null);
  }

  public function setAccessToken($token) {
    $this->accessToken = $token;
    return $this;
  }

  public function setRawAsanaQuery($action, array $params = array()) {
    $this->action = $action;
    $this->params = $params;
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

  protected function getProxiedFuture() {
    if (!$this->future) {
      $params = $this->params;

      if (!$this->action) {
        throw new Exception(
          pht(
            'You must %s!',
            'setRawAsanaQuery()'));
      }

      if (!$this->accessToken) {
        throw new Exception(
          pht(
            'You must %s!',
            'setAccessToken()'));
      }

      $uri = new PhutilURI('https://app.asana.com/');
      $uri->setPath('/api/1.0/'.ltrim($this->action, '/'));

      $future = new HTTPSFuture($uri);
      $future->setData($this->params);
      $future->addHeader('Authorization', 'Bearer '.$this->accessToken);
      $future->setMethod($this->method);

      $timeout = $this->getTimeout();
      if ($timeout !== null) {
        $future->setTimeout($timeout);
      }

      $this->future = $future;
    }

    return $this->future;
  }

  protected function didReceiveResult($result) {
    list($status, $body, $headers) = $result;

    if ($status->isError()) {
      throw $status;
    }

    $data = null;
    try {
      $data = phutil_json_decode($body);
    } catch (PhutilJSONParserException $ex) {
      throw new PhutilProxyException(
        pht('Expected JSON response from Asana.'),
        $ex);
    }

    if (idx($data, 'errors')) {
      $errors = print_r($data['errors'], true);
      throw new Exception(
        pht(
          'Received errors from Asana: %s',
          $errors));
    }

    return $data['data'];
  }

}
