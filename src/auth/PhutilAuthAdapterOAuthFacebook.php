<?php

final class PhutilAuthAdapterOAuthFacebook extends PhutilAuthAdapterOAuth {

  public function getAdapterType() {
    return 'facebook';
  }

  public function getAdapterDomain() {
    return 'facebook.com';
  }

  public function getAccountID() {
    return $this->getOAuthAccountData('id');
  }

  public function getAccountEmail() {
    return $this->getOAuthAccountData('email');
  }

  public function getAccountName() {
    $link = $this->getOAuthAccountData('link');
    if (!$link) {
      return null;
    }

    $matches = null;
    if (!preg_match('@/([^/]+)$@', $link, $matches)) {
      return null;
    }

    return $matches[1];
  }

  public function getAccountImageURI() {
    return $this->getOAuthAccountData('picture', 'data', 'url');
  }

  public function getAccountURI() {
    return $this->getOAuthAccountData('link');
  }

  public function getAccountRealName() {
    return $this->getOAuthAccountData('name');
  }

  protected function getAuthenticateBaseURI() {
    return 'https://www.facebook.com/dialog/oauth';
  }

  protected function getTokenBaseURI() {
    return 'https://graph.facebook.com/oauth/access_token';
  }

  protected function loadOAuthAccountData() {
    $fields = array(
      'id',
      'name',
      'email',
      'link',
      'security_settings',
      'picture',
    );

    $uri = new PhutilURI('https://graph.facebook.com/me');
    $uri->setQueryParam('access_token', $this->getAccessToken());
    $uri->setQueryParam('fields', implode(',', $fields));
    list($body) = id(new HTTPSFuture($uri))->resolvex();

    $data = json_decode($body, true);
    if (!is_array($data)) {
      throw new Exception(
        "Expected valid JSON response from Facebook account data request, ".
        "got: ".$body);
    }

    return $data;
  }

}
