<?php

final class PhutilPostmarkFuture extends FutureProxy {

  private $future;
  private $accessToken;
  private $method;
  private $parameters;

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

  public function setMethod($method, array $parameters) {
    $this->method = $method;
    $this->parameters = $parameters;
    return $this;
  }

  protected function getProxiedFuture() {
    if (!$this->future) {
      if ($this->accessToken === null) {
        throw new PhutilInvalidStateException('setAccessToken');
      }

      if ($this->method === null || $this->parameters === null) {
        throw new PhutilInvalidStateException('setMethod');
      }

      $uri = id(new PhutilURI('https://api.postmarkapp.com/'))
        ->setPath('/'.$this->method);

      $request_body = phutil_json_encode($this->parameters);

      $future = id(new HTTPSFuture($uri))
        ->setData($request_body)
        ->setMethod('POST')
        ->addHeader('X-Postmark-Server-Token', $this->accessToken)
        ->addHeader('Accept', 'application/json')
        ->addHeader('Content-Type', 'application/json');

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
        pht('Expected JSON response from Postmark.'),
        $ex);
    }

    if (idx($data, 'ErrorCode')) {
      $error = $data['ErrorCode'];
      throw new Exception(
        pht(
          'Received error from Postmark: (%s) %s',
          $error,
          idx($data, 'Message')));
    }

    return $data;
  }

}
