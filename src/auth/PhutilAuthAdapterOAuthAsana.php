<?php

final class PhutilAuthAdapterOAuthAsana extends PhutilAuthAdapterOAuth {

  public function getAdapterType() {
    return 'asana';
  }

  public function getAdapterDomain() {
    return 'asana.com';
  }

  public function getAccountID() {
    return $this->getOAuthAccountData('id');
  }

  public function getAccountEmail() {
    return $this->getOAuthAccountData('email');
  }

  public function getAccountName() {
    return null;
  }

  public function getAccountImageURI() {
    return $this->getOAuthAccountData('photo');
  }

  public function getAccountURI() {
    return null;
  }

  public function getAccountRealName() {
    return $this->getOAuthAccountData('name');
  }

  protected function getAuthenticateBaseURI() {
    return 'https://app.asana.com/-/oauth_authorize';
  }

  protected function getTokenBaseURI() {
    return 'https://app.asana.com/-/oauth_token';
  }

  public function getScope() {
    return null;
  }

  public function getExtraAuthenticateParameters() {
    return array(
      'response_type' => 'code',
    );
  }

  public function getExtraTokenParameters() {
    return array(
      'grant_type' => 'authorization_code',
    );
  }

  protected function loadOAuthAccountData() {
    $uri = new PhutilURI('https://app.asana.com/api/1.0/users/me');

    $future = new HTTPSFuture($uri);
    $future->addHeader('Authorization', 'Bearer '.$this->getAccessToken());
    list($body) = $future->resolvex();

    $data = json_decode($body, true);
    if (!is_array($data)) {
      throw new Exception(
        "Expected valid JSON response from Google account data request, ".
        "got: ".$body);
    }

    return $data['data'];
  }

}
