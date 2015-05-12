<?php

final class HTTPFutureCertificateResponseStatus
  extends HTTPFutureResponseStatus {

  const ERROR_IMMUTABLE_CERTIFICATES = 1;

  protected function getErrorCodeType($code) {
    return 'Certificate';
  }

  public function isError() {
    return true;
  }

  public function isTimeout() {
    return false;
  }

  protected function getErrorCodeDescription($code) {
    return pht(
      "There was an error verifying the SSL Certificate Authority while ".
      "negotiating the SSL connection. This usually indicates you are ".
      "using a self-signed certificate.\n\n".
      "As of OSX Yosemite, certificates must be added to the OSX keychain. ".
      "You can do this with `security add-trusted-cert` from the command ".
      "line, or by visiting the site in Safari and choosing to trust the ".
      "certificate permanently.\n\n".
      'For more information, see instructions in "%s".',
      'libphutil/resources/ssl/README');
  }

}
