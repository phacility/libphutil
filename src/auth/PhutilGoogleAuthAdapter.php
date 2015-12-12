<?php

/**
 * Authentication adapter for Google OAuth2.
 */
final class PhutilGoogleAuthAdapter extends PhutilOAuthAuthAdapter {

  public function getAdapterType() {
    return 'google';
  }

  public function getAdapterDomain() {
    return 'google.com';
  }

  public function getAccountID() {
    $emails = $this->getOAuthAccountData('emails', array());
    foreach ($emails as $email) {
      if (idx($email, 'type') == 'account') {
        return idx($email, 'value');
      }
    }

    throw new Exception(
      pht(
        'Expected to retrieve an "account" email from Google Plus API call '.
        'to identify account, but failed.'));
  }

  public function getAccountEmail() {
    return $this->getAccountID();
  }

  public function getAccountName() {
    // Guess account name from email address, this is just a hint anyway.
    $email = $this->getAccountEmail();
    $email = explode('@', $email);
    $email = head($email);
    return $email;
  }

  public function getAccountImageURI() {
    $image = $this->getOAuthAccountData('image', array());
    $uri = idx($image, 'url');

    // Change the "sz" parameter ("size") from the default to 100 to ask for
    // a 100x100px image.
    if ($uri !== null) {
      $uri = new PhutilURI($uri);
      $uri->setQueryParam('sz', 100);
      $uri = (string)$uri;
    }

    return $uri;
  }

  public function getAccountURI() {
    return $this->getOAuthAccountData('url');
  }

  public function getAccountRealName() {
    $name = $this->getOAuthAccountData('name', array());

    // TODO: This could probably be made cleaner by looking up the API, but
    // this should work to unbreak logins.

    $parts = array();
    $parts[] = idx($name, 'givenName');
    unset($name['givenName']);
    $parts[] = idx($name, 'familyName');
    unset($name['familyName']);
    $parts = array_merge($parts, $name);
    $parts = array_filter($parts);

    return implode(' ', $parts);
  }

  protected function getAuthenticateBaseURI() {
    return 'https://accounts.google.com/o/oauth2/auth';
  }

  protected function getTokenBaseURI() {
    return 'https://accounts.google.com/o/oauth2/token';
  }

  public function getScope() {
    $scopes = array(
      'email',
      'profile',
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
    $uri = new PhutilURI('https://www.googleapis.com/plus/v1/people/me');
    $uri->setQueryParam('access_token', $this->getAccessToken());

    $future = new HTTPSFuture($uri);
    list($status, $body) = $future->resolve();

    if ($status->isError()) {
      $this->tryToThrowSpecializedError($status, $body);
      throw $status;
    }

    try {
      return phutil_json_decode($body);
    } catch (PhutilJSONParserException $ex) {
      throw new PhutilProxyException(
        pht('Expected valid JSON response from Google account data request.'),
        $ex);
    }
  }

  private function tryToThrowSpecializedError($status, $raw_body) {
    if (!($status instanceof HTTPFutureHTTPResponseStatus)) {
      return;
    }

    if ($status->getStatusCode() != 403) {
      return;
    }

    $body = phutil_json_decode($raw_body);
    if (!$body) {
      return;
    }

    if (empty($body['error']['errors'][0])) {
      return;
    }

    $error = $body['error']['errors'][0];
    $domain = idx($error, 'domain');
    $reason = idx($error, 'reason');

    if ($domain == 'usageLimits' && $reason == 'accessNotConfigured') {
      throw new PhutilAuthConfigurationException(
        pht(
          'Google returned an "%s" error. This usually means you need to '.
          'enable the "Google+ API" in your Google Cloud Console, under '.
          '"APIs".'.
          "\n\n".
          'Around March 2014, Google made some API changes which require this '.
          'configuration adjustment.'.
          "\n\n".
          'Normally, you can resolve this issue by going to %s, then '.
          'clicking "API Project", then "APIs & auth", then turning the '.
          '"Google+ API" on. The names you see on the console may be '.
          'different depending on how your integration is set up. If you '.
          'are not sure, you can hunt through the projects until you find '.
          'the one associated with the right Application ID under '.
          '"Credentials". The Application ID this install is using is "%s".'.
          "\n\n".
          '(If you are unable to log into Phabricator, you can use '.
          '"%s" to recover access to an administrator account.)'.
          "\n\n".
          'Full HTTP Response'.
          "\n\n%s",
          'accessNotConfigured',
          'https://console.developers.google.com/',
          $this->getClientID(),
          'bin/auth recover',
          $raw_body));
    }
  }

}
