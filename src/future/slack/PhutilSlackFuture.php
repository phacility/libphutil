<?php

final class PhutilSlackFuture extends FutureProxy {

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

  public function setRawSlackQuery($action, array $params = array()) {
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
        throw new Exception(pht('You must %s!', 'setRawSlackQuery()'));
      }

      if (!$this->accessToken) {
        throw new Exception(pht('You must %s!', 'setAccessToken()'));
      }

      $uri = new PhutilURI('https://slack.com/');
      $uri->setPath('/api/'.$this->action);
      $uri->replaceQueryParam('token', $this->accessToken);

      $future = new HTTPSFuture($uri);
      $future->setData($this->params);
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

    $data = null;
    try {
      $data = phutil_json_decode($body);
    } catch (PhutilJSONParserException $ex) {
      throw new PhutilProxyException(
        pht('Expected JSON response from Slack.'),
        $ex);
    }

    if (idx($data, 'error')) {
      $error = $data['error'];
      throw new Exception(pht('Received error from Slack: %s', $error));
    }

    return $data;
  }

}
