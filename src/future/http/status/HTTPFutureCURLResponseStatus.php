<?php

final class HTTPFutureCURLResponseStatus extends HTTPFutureResponseStatus {

  protected function getErrorCodeType($code) {
    return 'cURL';
  }

  public function isError() {
    return true;
  }

  public function isTimeout() {
    // NOTE: The PHP error constant for this is nonsensical (this is not an
    // error):
    //
    //    PHP: CURLE_OPERATION_TIMEOUTED
    //   cURL: CURLE_OPERATION_TIMEDOUT

    return ($this->getStatusCode() == CURLE_OPERATION_TIMEOUTED);
  }

  protected function getErrorCodeDescription($code) {
    $constants = get_defined_constants();

    $constant_name = null;
    foreach ($constants as $constant => $value) {
      if ($value == $code && preg_match('/^CURLE_/', $constant)) {
        $constant_name = '<'.$constant.'> ';
        break;
      }
    }

    $map = array(
      CURLE_COULDNT_RESOLVE_HOST => pht(
        'There was an error resolving the server hostname. Check that you are '.
        'connected to the internet and that DNS is correctly configured. (Did '.
        'you add the domain to `%s` on some other machine, but not this one?)',
        '/etc/hosts'),

      CURLE_SSL_CACERT => pht(
        'There was an error verifying the SSL Certificate Authority while '.
        'negotiating the SSL connection. This usually indicates that you are '.
        'using a self-signed certificate but have not added your CA to the '.
        'CA bundle. See instructions in "%s".',
        'libphutil/resources/ssl/README'),

      // Apparently there's no error constant for this? In cURL it's
      // CURLE_SSL_CACERT_BADFILE but there's no corresponding constant in
      // PHP.
      77 => pht(
        'The SSL CA Bundles that we tried to use could not be read or are '.
        'not formatted correctly.'),

      CURLE_SSL_CONNECT_ERROR => pht(
        'There was an error negotiating the SSL connection. This usually '.
        'indicates that the remote host has a bad SSL certificate, or your '.
        'local host has some sort of SSL misconfiguration which prevents it '.
        'from accepting the CA. If you are using a self-signed certificate, '.
        'see instructions in "%s".',
        'libphutil/resources/ssl/README'),

      CURLE_OPERATION_TIMEOUTED => pht(
        'The request took too long to complete.'),

      CURLE_SSL_PEER_CERTIFICATE => pht(
        'There was an error verifying the SSL connection. This usually '.
        'indicates that the remote host has an SSL certificate for a '.
        'different domain name than you are connecting with. Make sure the '.
        'certificate you have installed is signed for the correct domain.'),
    );

    $default_message = pht(
      'The cURL library raised an error while making a request. You may be '.
      'able to find more information about this error (error code: %d) '.
      'on the cURL site: %s',
      $code,
      'http://curl.haxx.se/libcurl/c/libcurl-errors.html#'.
      preg_replace('/[^A-Z]/', '', $constant_name));

    $detailed_message = idx($map, $code, $default_message);

    return $constant_name.$detailed_message;
  }

}
