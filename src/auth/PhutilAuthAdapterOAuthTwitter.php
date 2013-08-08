<?php

final class PhutilAuthAdapterOAuthTwitter extends PhutilAuthAdapterOAuth1 {

  public function getAccountID() {
    return idx($this->getHandshakeData(), 'user_id');
  }

  public function getAdapterType() {
    return 'twitter';
  }

  public function getAdapterDomain() {
    return 'twitter.com';
  }

  protected function getRequestTokenURI() {
    return 'https://api.twitter.com/oauth/request_token';
  }

  protected function getAuthorizeTokenURI() {
    return 'https://api.twitter.com/oauth/authorize';
  }

  protected function getValidateTokenURI() {
    return 'https://api.twitter.com/oauth/access_token';
  }

}
