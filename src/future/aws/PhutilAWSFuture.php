<?php

abstract class PhutilAWSFuture extends FutureProxy {

  private $future;
  private $awsAccessKey;
  private $awsPrivateKey;
  private $awsRegion;
  private $builtRequest;
  private $params;

  abstract public function getServiceName();

  public function __construct() {
    parent::__construct(null);
  }

  public function setAWSKeys($access, $private) {
    $this->awsAccessKey = $access;
    $this->awsPrivateKey = $private;
    return $this;
  }

  public function getAWSAccessKey() {
    return $this->awsAccessKey;
  }

  public function getAWSPrivateKey() {
    return $this->awsPrivateKey;
  }

  public function getAWSRegion() {
    return $this->awsRegion;
  }

  public function setAWSRegion($region) {
    $this->awsRegion = $region;
    return $this;
  }

  public function getHost() {
    $host = $this->getServiceName().'.'.$this->awsRegion.'.amazonaws.com';
    return $host;
  }

  public function setRawAWSQuery($action, array $params = array()) {
    $this->params = $params;
    $this->params['Action'] = $action;
    return $this;
  }

  protected function getProxiedFuture() {
    if (!$this->future) {
      $params = $this->params;

      if (!$this->params) {
        throw new Exception('You must setRawAWSQuery()!');
      }

      if (!$this->getAWSAccessKey()) {
        throw new Exception('You must setAWSKeys()!');
      }

      $params['AWSAccessKeyId'] = $this->getAWSAccessKey();
      $params['Version']        = '2013-10-15';
      $params['Timestamp']      = date('c');

      $params = $this->sign($params);

      $uri = new PhutilURI('http://'.$this->getHost().'/');
      $uri->setQueryParams($params);

      $this->future = new HTTPFuture($uri);
    }

    return $this->future;
  }

  protected function didReceiveResult($result) {
    list($status, $body, $headers) = $result;

    try {
      $xml = @(new SimpleXMLElement($body));
    } catch (Exception $ex) {
      $xml = null;
    }

    if ($status->isError() || !$xml) {
      if (!($status instanceof HTTPFutureHTTPResponseStatus)) {
        throw $status;
      }

      $params = array(
        'body' => $body,
      );
      if ($xml) {
        $params['RequestID'] = $xml->RequestID[0];
        foreach ($xml->Errors[0] as $error) {
          $params['Errors'][] = array($error->Code, $error->Message);
        }
      }

      throw new PhutilAWSException($status->getStatusCode(), $params);
    }

    return $xml;
  }

  /**
   * http://bit.ly/wU0JFh
   */
  private function sign(array $params) {

    $params['SignatureMethod'] = 'HmacSHA256';
    $params['SignatureVersion'] = '2';

    ksort($params);

    $pstr = array();
    foreach ($params as $key => $value) {
      $pstr[] = rawurlencode($key).'='.rawurlencode($value);
    }
    $pstr = implode('&', $pstr);

    $sign = "GET"."\n".
            strtolower($this->getHost())."\n".
            "/"."\n".
            $pstr;

    $hash = hash_hmac(
      'sha256',
      $sign,
      $this->getAWSPrivateKey(),
      $raw_ouput = true);

    $params['Signature'] = base64_encode($hash);

    return $params;
  }

}
