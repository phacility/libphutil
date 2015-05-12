<?php

final class PhutilWordPressFuture extends FutureProxy {

  private $future;
  private $clientID;
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

  public function setClientID($client_id) {
    $this->clientID = $client_id;
    return $this;
  }

  public function setRawWordPressQuery($action, array $params = array()) {
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
        throw new Exception(pht('You must %s!', 'setRawWordPressQuery()'));
      }

      if (!$this->accessToken) {
        throw new Exception(pht('You must %s!', 'setAccessToken()'));
      }

      $uri = new PhutilURI('https://public-api.wordpress.com/');
      $uri->setPath('/rest/v1/'.ltrim($this->action, '/'));

      $future = new HTTPSFuture($uri);
      $future->setData($this->params);
      $future->setMethod($this->method);

      // NOTE: This is how WordPress.com REST API authenticates
      $future->addHeader('Authorization', 'Bearer '.$this->accessToken);

      $this->future = $future;
    }

    return $this->future;
  }

  protected function didReceiveResult($result) {
    list($status, $body, $headers) = $result;

    if ($status->isError()) {
      throw $status;
    }

    try {
      $data = phutil_json_decode($body);
    } catch (PhutilJSONParserException $ex) {
      throw new PhutilProxyException(
        pht('Expected JSON response from WordPress.com.'),
        $ex);
    }

    if (idx($data, 'error')) {
      $error = $data['error'];
      throw new Exception(
        pht('Received error from WordPress.com: %s', $error));
    }

    return $data;
  }

}
