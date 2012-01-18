<?php

/*
 * Copyright 2012 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @group aws
 */
abstract class PhutilAWSFuture extends FutureProxy {

  private $future;
  private $awsAccessKey;
  private $awsPrivateKey;
  private $builtRequest;
  private $params;

  abstract public function getHost();

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

  public function setRawAWSQuery($action, array $params = array()) {
    $this->params = $params;
    $this->params['Action'] = $action;
    return $this;
  }

  public function getAWSKeys() {
    return $this->AWSKeys;
  }

  protected function getProxiedFuture() {
    if (!$this->future) {
      $params = $this->params;

      if (!$this->params) {
        throw new Exception("You must setRawAWSQuery()!");
      }

      if (!$this->getAWSAccessKey()) {
        throw new Exception("You must setAWSKeys()!");
      }

      $params['AWSAccessKeyId'] = $this->getAWSAccessKey();
      $params['Version']        = '2011-12-15';
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
      if (!($status instanceof HTTPFutureResponseStatusHTTP)) {
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
