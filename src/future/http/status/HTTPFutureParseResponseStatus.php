<?php

final class HTTPFutureParseResponseStatus extends HTTPFutureResponseStatus {

  const ERROR_MALFORMED_RESPONSE = 1;

  private $rawResponse;

  public function __construct($code, $raw_response) {
    $this->rawResponse = $raw_response;
    parent::__construct($code);
  }

  protected function getErrorCodeType($code) {
    return 'Parse';
  }

  public function isError() {
    return true;
  }

  public function isTimeout() {
    return false;
  }

  protected function getErrorCodeDescription($code) {
    return pht(
      'The remote host returned something other than an HTTP response: %s',
      $this->rawResponse);
  }

}
