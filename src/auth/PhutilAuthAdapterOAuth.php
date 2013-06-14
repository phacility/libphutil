<?php

abstract class PhutilAuthAdapterOAuth extends PhutilAuthAdapter {

  private $clientID;
  private $clientSecret;
  private $redirectURI;
  private $scope;
  private $state;
  private $code;

  private $accessTokenData;
  private $oauthAccountData;

  abstract protected function getAuthenticateBaseURI();
  abstract protected function getTokenBaseURI();
  abstract protected function loadOAuthAccountData();

  public function getAuthenticateURI() {
    $uri = new PhutilURI($this->getAuthenticateBaseURI());
    $uri->setQueryParam('client_id', $this->getClientID());
    $uri->setQueryParam('scope', $this->getScope());
    $uri->setQueryParam('redirect_uri', $this->getRedirectURI());
    if ($this->supportsStateParameter()) {
      $uri->setQueryParam('state', $this->getState());
    }
    foreach ($this->getExtraAuthenticateParameters() as $key => $value) {
      $uri->setQueryParam($key, $value);
    }

    return (string)$uri;
  }

  public function getAdapterType() {
    $this_class = get_class($this);
    $type_name = str_replace('PhutilAuthAdapterOAuth', '', $this_class);
    return strtolower($type_name);
  }

  public function supportsStateParameter() {
    return true;
  }

  public function setState($state) {
    $this->state = $state;
    return $this;
  }

  public function getState() {
    return $this->state;
  }

  public function setCode($code) {
    $this->code = $code;
    return $this;
  }

  public function getCode() {
    return $this->code;
  }

  public function setRedirectURI($redirect_uri) {
    $this->redirectURI = $redirect_uri;
    return $this;
  }

  public function getRedirectURI() {
    return $this->redirectURI;
  }

  public function getExtraAuthenticateParameters() {
    return array();
  }

  public function getExtraTokenParameters() {
    return array();
  }

  public function setScope($scope) {
    $this->scope = $scope;
    return $this;
  }

  public function getScope() {
    return $this->scope;
  }

  public function setClientSecret(PhutilOpaqueEnvelope $client_secret) {
    $this->clientSecret = $client_secret;
    return $this;
  }

  public function getClientSecret() {
    return $this->clientSecret;
  }

  public function setClientID($client_id) {
    $this->clientID = $client_id;
    return $this;
  }

  public function getClientID() {
    return $this->clientID;
  }

  public function getAccessToken() {
    return $this->getAccessTokenData('access_token');
  }

  protected function getAccessTokenData($key, $default = null) {
    if ($this->accessTokenData === null) {
      $this->accessTokenData = $this->loadAccessTokenData();
    }

    return idx($this->accessTokenData, $key, $default);
  }

  protected function loadAccessTokenData() {
    $code = $this->getCode();
    if (!$code) {
      throw new Exception(
        "Call setCode() before accessing adapter information.");
    }

    $uri = $this->getTokenBaseURI();
    $query_data = array(
      'client_id'       => $this->getClientID(),
      'client_secret'   => $this->getClientSecret()->openEnvelope(),
      'redirect_uri'    => $this->getRedirectURI(),
      'code'            => $this->getCode(),
    ) + $this->getExtraTokenParameters();

    $future = new HTTPSFuture($uri, $query_data);
    $future->setMethod('POST');
    list($body) = $future->resolvex();

    $data = $this->readAccessTokenResponse($body);

    if (isset($data['error'])) {
      throw new Exception(
        "Access token error: ".$data['error']);
    }

    return $data;
  }

  protected function readAccessTokenResponse($body) {
    // NOTE: Most providers either return JSON or HTTP query strings, so try
    // both mechanisms. If your provider does something else, override this
    // method.

    $data = json_decode($body, true);

    if (!is_array($data)) {
      $data = array();
      parse_str($body, $data);
    }

    if (empty($data['access_token']) &&
        empty($data['error'])) {
      throw new Exception(
        "Failed to decode OAuth access token response: {$body}");
    }

    return $data;
  }

  protected function getOAuthAccountData($key, $default = null) {
    if ($this->oauthAccountData === null) {
      $this->oauthAccountData = $this->loadOAuthAccountData();
    }

    return idx($this->oauthAccountData, $key, $default);
  }

}
