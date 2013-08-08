<?php

final class PhutilAuthAdapterOAuthJIRA extends PhutilAuthAdapterOAuth1 {

  private $jiraBaseURI;

  public function setJIRABaseURI($jira_base_uri) {
    $this->jiraBaseURI = $jira_base_uri;
    return $this;
  }

  public function getJIRABaseURI() {
    return $this->jiraBaseURI;
  }

  public function getAccountID() {
    var_dump($this->getHandshakeData());
    throw new Exception("TODO: NOT IMPLEMENTED");
  }

  public function getAdapterType() {
    return 'jira';
  }

  public function getAdapterDomain() {
    $uri = new PhutilURI($this->jiraBaseURI);

    $domain = $uri->getDomain();
    if ($uri->getPort()) {
      $domain .= ':'.$uri->getPort();
    }

    if ($uri->getPath() && $uri->getPath() != '/') {
      $domain .= $uri->getPath();
    }

    return $domain;
  }

  protected function getSignatureMethod() {
    return 'RSA-SHA1';
  }

  protected function getRequestTokenURI() {
    return $this->getJIRAURI('plugins/servlet/oauth/request-token');
  }

  protected function getAuthorizeTokenURI() {
    return $this->getJIRAURI('plugins/servlet/oauth/authorize');
  }

  protected function getValidateTokenURI() {
    return $this->getJIRAURI('plugins/servlet/oauth/access-token');
  }

  private function getJIRAURI($path) {
    return rtrim($this->jiraBaseURI, '/').'/'.ltrim($path, '/');
  }

  public static function newJIRAKeypair() {
    $config = array(
      'digest_alg' => 'sha512',
      'private_key_bits' => 4096,
      'private_key_type' => OPENSSL_KEYTYPE_RSA,
    );

    $res = openssl_pkey_new($config);
    if (!$res) {
      throw new Exception('openssl_pkey_new() failed!');
    }

    $private_key = null;
    $ok = openssl_pkey_export($res, $private_key);
    if (!$ok) {
      throw new Exception('openssl_pkey_export() failed!');
    }

    $public_key = openssl_pkey_get_details($res);
    if (!$ok || empty($public_key['key'])) {
      throw new Exception('openssl_pkey_get_details() failed!');
    }
    $public_key = $public_key['key'];

    return array($public_key, $private_key);
  }


}
