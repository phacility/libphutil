<?php

final class PhutilAWSException extends Exception {

  private $httpStatus;
  private $requestID;
  private $params;

  public function __construct($http_status, array $params) {
    $this->httpStatus = $http_status;
    $this->requestID = idx($params, 'RequestID');

    $this->params = $params;

    $desc = array();
    $desc[] = pht('AWS Request Failed');
    $desc[] = pht('HTTP Status Code: %d', $http_status);

    if ($this->requestID) {
      $desc[] = pht('AWS Request ID: %s', $this->requestID);
      $errors = idx($params, 'Errors');
      if ($errors) {
        $desc[] = pht('AWS Errors:');
        foreach ($errors as $error) {
          list($code, $message) = $error;
          $desc[] = "    - {$code}: {$message}\n";
        }
      }
    } else {
      $desc[] = pht('Response Body: %s', idx($params, 'body'));
    }

    $desc = implode("\n", $desc);

    parent::__construct($desc);
  }

  public function getRequestID() {
    return $this->requestID;
  }

  public function getHTTPStatus() {
    return $this->httpStatus;
  }

}
