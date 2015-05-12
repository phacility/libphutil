<?php

final class PhutilPayPalAPIFuture extends FutureProxy {

  private $future;
  private $host = 'https://api-3t.paypal.com/nvp';
  private $params = array();

  private $apiUsername;
  private $apiPassword;
  private $apiSignature;

  public function __construct() {
    parent::__construct(null);
  }

  public function setHost($host) {
    $this->host = $host;
    return $this;
  }

  public function getHost() {
    return $this->host;
  }

  public function setAPIUsername($api_username) {
    $this->apiUsername = $api_username;
    return $this;
  }

  public function setAPIPassword($api_password) {
    $this->apiPassword = $api_password;
    return $this;
  }

  public function setAPISignature($api_signature) {
    $this->apiSignature = $api_signature;
    return $this;
  }

  public function setRawPayPalQuery($action, array $params = array()) {
    $this->params = array('METHOD' => $action) + $params + $this->params;
    return $this;
  }

  protected function getProxiedFuture() {
    if (!$this->future) {
      $params = $this->params;

      if (!$this->params) {
        throw new Exception(pht('You must %s!', 'setRawPayPalQuery()'));
      }

      if (!$this->apiUsername) {
        throw new Exception(pht('You must set PayPal API credentials!'));
      }

      $params['VERSION'] = '98.0';
      $params['USER'] = $this->apiUsername;
      $params['PWD'] = $this->apiPassword;
      $params['SIGNATURE'] = $this->apiSignature;

      $this->future = id(new HTTPSFuture($this->getHost(), $params))
        ->setMethod('POST');
    }

    return $this->future;
  }

  protected function didReceiveResult($result) {
    list($status, $body, $headers) = $result;

    if ($status->isError()) {
      throw $status;
    }

    $dict = array();
    parse_str($body, $dict);

    if (idx($dict, 'ACK') !== 'Success') {
      throw new Exception(
        pht('PayPal API call failed: %s', print_r($dict, true)));
    }

    return $dict;
  }

}
