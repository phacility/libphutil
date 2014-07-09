<?php

final class PhutilTwitchFuture extends FutureProxy {

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

  public function setRawTwitchQuery($action, array $params = array()) {
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
        throw new Exception('You must setRawTwitchQuery()!');
      }

      if (!$this->accessToken) {
        throw new Exception('You must setAccessToken()!');
      }

      $uri = new PhutilURI('https://api.twitch.tv/');
      $uri->setPath('/kraken/'.ltrim($this->action, '/'));
      $uri->setQueryParam('oauth_token', $this->accessToken);

      $future = new HTTPSFuture($uri);
      $future->setData($this->params);
      $future->setMethod($this->method);

      // NOTE: This is how the Twitch API is versioned.
      $future->addHeader('Accept', 'application/vnd.twitchtv.2+json');

      // NOTE: This is required to avoid rate limiting.
      $future->addHeader('Client-ID', $this->clientID);

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
      throw new Exception("Expected JSON response from Twitch, got: {$body}");
    }

    if (idx($data, 'error')) {
      $error = $data['error'];
      throw new Exception("Received error from Twitch: {$error}");
    }

    return $data;
  }

}
