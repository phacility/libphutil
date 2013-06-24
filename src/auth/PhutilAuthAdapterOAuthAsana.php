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
    return id(new PhutilAsanaFuture())
      ->setAccessToken($this->getAccessToken())
      ->setRawAsanaQuery('users/me')
      ->resolve();
  }

}
