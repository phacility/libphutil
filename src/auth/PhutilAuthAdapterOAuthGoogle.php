<?php

final class PhutilAuthAdapterOAuthGoogle extends PhutilAuthAdapterOAuth {

  public function getAdapterType() {
    return 'google';
  }

  public function getAdapterDomain() {
    return 'google.com';
  }

  public function getAccountID() {
    return $this->getOAuthAccountData('email');
  }

  public function getAccountEmail() {
    return $this->getOAuthAccountData('email');
  }

  public function getAccountName() {
    // Guess account name from email address, this is just a hint anyway.
    $email = $this->getAccountEmail();
    $email = explode('@', $email);
    $email = head($email);
    return $email;
  }

  public function getAccountImageURI() {
    return $this->getOAuthAccountData('picture');
  }

  public function getAccountURI() {
    return 'https://plus.google.com/'.$this->getOAuthAccountData('id');
  }

  public function getAccountRealName() {
    return $this->getOAuthAccountData('name');
  }

  protected function getAuthenticateBaseURI() {
    return 'https://accounts.google.com/o/oauth2/auth';
  }

  protected function getTokenBaseURI() {
    return 'https://accounts.google.com/o/oauth2/token';
  }

  public function getScope() {
    $scopes = array(
      'https://www.googleapis.com/auth/userinfo.email',
      'https://www.googleapis.com/auth/userinfo.profile',
    );

    return implode(' ', $scopes);
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
    $uri = new PhutilURI('https://www.googleapis.com/oauth2/v1/userinfo');
    $uri->setQueryParam('access_token', $this->getAccessToken());

    $future = new HTTPSFuture($uri);
    list($body) = $future->resolvex();

    $data = json_decode($body, true);
    if (!is_array($data)) {
      throw new Exception(
        "Expected valid JSON response from Google account data request, ".
        "got: ".$body);
    }

    return $data;
  }

}
