<?php

final class PhutilAsanaFuture extends FutureProxy {

  private $future;
  private $accessToken;
  private $action;
  private $params;
  private $method = 'GET';

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

  protected function getProxiedFuture() {
    if (!$this->future) {
      $params = $this->params;

      if (!$this->action) {
        throw new Exception('You must setRawAsanaQuery()!');
      }

      if (!$this->accessToken) {
        throw new Exception('You must setAccessToken()!');
      }

      $uri = new PhutilURI('https://app.asana.com/');
      $uri->setPath('/api/1.0/'.ltrim($this->action, '/'));

      $future = new HTTPSFuture($uri);
      $future->setData($this->params);
      $future->addHeader('Authorization', 'Bearer '.$this->accessToken);
      $future->setMethod($this->method);

      $this->future = $future;
    }

    return $this->future;
  }

  protected function didReceiveResult($result) {
    list($status, $body, $headers) = $result;

    if ($status->isError()) {
      throw $status;
    }

    $data = json_decode($body, true);
    if (!is_array($data)) {
      throw new Exception("Expected JSON response from Asana, got: {$body}");
    }

    if (idx($data, 'errors')) {
      $errors = print_r($data['errors'], true);
      throw new Exception("Received errors from Asana: {$errors}");
    }

    return $data['data'];
  }

}
