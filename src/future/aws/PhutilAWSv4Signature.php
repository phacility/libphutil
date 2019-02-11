<?php

final class PhutilAWSv4Signature extends Phobject {

  private $accessKey;
  private $secretKey;
  private $signingKey;
  private $signContent;

  private $date;

  private $region;
  private $service;

  public function setAccessKey($access_key) {
    $this->accessKey = $access_key;
    return $this;
  }

  public function setSecretKey(PhutilOpaqueEnvelope $secret_key) {
    $this->secretKey = $secret_key;
    return $this;
  }

  public function setDate($date) {
    $this->date = $date;
    return $this;
  }

  public function getDate() {
    if ($this->date === null) {
      $this->date = gmdate('Ymd\THis\Z', time());
    }
    return $this->date;
  }

  public function setRegion($region) {
    $this->region = $region;
    return $this;
  }

  public function getRegion() {
    return $this->region;
  }

  public function setService($service) {
    $this->service = $service;
    return $this;
  }

  public function getService() {
    return $this->service;
  }

  public function setSigningKey($signing_key) {
    $this->signingKey = $signing_key;
    return $this;
  }

  public function getSigningKey() {
    if ($this->signingKey === null) {
      $this->signingKey = $this->computeSigningKey();
    }

    return $this->signingKey;
  }

  private function getAlgorithm() {
    return 'AWS4-HMAC-SHA256';
  }

  public function setSignContent($sign_content) {
    $this->signContent = $sign_content;
    return $this;
  }

  public function getSignContent() {
    return $this->signContent;
  }

  private function getHost(HTTPSFuture $future) {
    $uri = new PhutilURI($future->getURI());
    return $uri->getDomain();
  }

  private function getPath(HTTPSFuture $future) {
    $uri = new PhutilURI($future->getURI());
    return $uri->getPath();
  }

  public function signRequest(HTTPSFuture $future) {
    $body_signature = $this->getBodySignature($future);

    if ($this->getSignContent()) {
      $future->addHeader('X-Amz-Content-sha256', $body_signature);
    }

    $future->addHeader('X-Amz-Date', $this->getDate());

    $request_signature = $this->getCanonicalRequestSignature(
      $future,
      $body_signature);

    $string_to_sign = $this->getStringToSign($request_signature);

    $signing_key = $this->getSigningKey();

    $signature = hash_hmac('sha256', $string_to_sign, $signing_key);

    $algorithm = $this->getAlgorithm();
    $credential = $this->getCredential();
    $signed_headers = $this->getSignedHeaderList($future);

    $authorization =
      $algorithm.' '.
      'Credential='.$credential.','.
      'SignedHeaders='.$signed_headers.','.
      'Signature='.$signature;

    $future->addHeader('Authorization', $authorization);

    return $future;
  }

  private function getBodySignature(HTTPSFuture $future) {
    $http_body = $future->getData();

    if (is_array($http_body)) {
      $http_body = '';
    }

    return hash('sha256', $http_body);
  }

  private function getCanonicalRequestSignature(
    HTTPSFuture $future,
    $body_signature) {

    $http_method = $future->getMethod();

    $path = $this->getPath($future);
    $path = rawurlencode($path);
    $path = str_replace('%2F', '/', $path);

    $canonical_parameters = $this->getCanonicalParameterList($future);
    $canonical_headers = $this->getCanonicalHeaderList($future);
    $signed_headers = $this->getSignedHeaderList($future);

    $canonical_request =
      $http_method."\n".
      $path."\n".
      $canonical_parameters."\n".
      $canonical_headers."\n".
      "\n".
      $signed_headers."\n".
      $body_signature;

    return hash('sha256', $canonical_request);
  }

  private function getStringToSign($request_signature) {
    $algorithm = $this->getAlgorithm();
    $date = $this->getDate();
    $scope_parts = $this->getScopeParts();
    $scope = implode('/', $scope_parts);

    $string_to_sign =
      $algorithm."\n".
      $date."\n".
      $scope."\n".
      $request_signature;

    return $string_to_sign;
  }

  private function getScopeParts() {
    return array(
      substr($this->getDate(), 0, 8),
      $this->getRegion(),
      $this->getService(),
      'aws4_request',
    );
  }

  private function computeSigningKey() {
    $secret_key = $this->secretKey;
    if (!$secret_key) {
      throw new Exception(
        pht(
          'You must either provide a signing key with setSigningKey(), or '.
          'provide a secret key with setSecretKey().'));
    }

    // NOTE: This part of the algorithm uses the raw binary hashes, and the
    // result is not human-readable.
    $raw_hash = true;

    $signing_key = 'AWS4'.$secret_key->openEnvelope();

    $scope_parts = $this->getScopeParts();
    foreach ($scope_parts as $scope_part) {
      $signing_key = hash_hmac('sha256', $scope_part, $signing_key, $raw_hash);
    }

    return $signing_key;
  }

  private function getCanonicalHeaderList(HTTPSFuture $future) {
    $headers = $this->getCanonicalHeaderMap($future);

    $canonical_headers = array();
    foreach ($headers as $header => $header_value) {
      $canonical_headers[] = $header.':'.trim($header_value);
    }

    return implode("\n", $canonical_headers);
  }

  private function getCanonicalHeaderMap(HTTPSFuture $future) {
    $headers = $future->getHeaders();
    $headers[] = array(
      'Host',
      $this->getHost($future),
    );

    $header_map = array();
    foreach ($headers as $header) {
      list($key, $value) = $header;
      $key = phutil_utf8_strtolower($key);
      $header_map[$key] = $value;
    }

    ksort($header_map);

    return $header_map;
  }

  private function getSignedHeaderList(HTTPSFuture $future) {
    $headers = $this->getCanonicalHeaderMap($future);
    return implode(';', array_keys($headers));
  }

  private function getCanonicalParameterList(HTTPSFuture $future) {
    $uri = new PhutilURI($future->getURI());
    $params = $uri->getQueryParamsAsMap();

    ksort($params);
    $canonical_parameters = phutil_build_http_querystring($params);

    return $canonical_parameters;
  }

  private function getCredential() {
    $access_key = $this->accessKey;
    if (!strlen($access_key)) {
      throw new PhutilInvalidStateException('setAccessKey');
    }

    $parts = $this->getScopeParts();
    array_unshift($parts, $access_key);

    return implode('/', $parts);
  }

}
