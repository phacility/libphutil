<?php

/**
 * Authentication adapter for Mozilla's Persona.
 */
final class PhutilPersonaAuthAdapter extends PhutilAuthAdapter {

  private $audience;
  private $assertion;
  private $accountData;

  public function setAssertion($assertion) {
    $this->assertion = $assertion;
    return $this;
  }

  public function setAudience($audience) {
    $this->audience = $audience;
    return $this;
  }

  public function getAdapterDomain() {
    return 'verifier.login.persona.org';
  }

  public function getAdapterType() {
    return 'persona';
  }

  public function getAccountEmail() {
    return $this->getAccountID();
  }

  public function getAccountID() {
    if ($this->accountData === null) {
      $verify_uri = 'https://verifier.login.persona.org/verify';
      $data = array(
        'audience' => $this->audience,
        'assertion' => $this->assertion,
      );

      list($body) = id(new HTTPSFuture($verify_uri, json_encode($data)))
        ->setMethod('POST')
        ->addHeader('Content-Type', 'application/json')
        ->resolvex();

      $response = null;
      try {
        $response = phutil_json_decode($body);
      } catch (PhutilJSONParserException $ex) {
        throw new PhutilProxyException(
          pht('Unexpected Persona response.'),
          $ex);
      }

      $audience = idx($response, 'audience');
      if ($audience != $this->audience) {
        throw new Exception(pht('Mismatched Persona audience: %s', $audience));
      }

      if (idx($response, 'status') !== 'okay') {
        $reason = idx($response, 'reason', pht('Unknown'));
        throw new Exception(pht('Persona login failed: %s', $reason));
      }

      $this->accountData = $response;
    }

    return idx($this->accountData, 'email');
  }

}
