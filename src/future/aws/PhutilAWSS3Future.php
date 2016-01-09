<?php

final class PhutilAWSS3Future extends PhutilAWSFuture {

  private $bucket;

  public function getServiceName() {
    return 's3';
  }

  public function setBucket($bucket) {
    $this->bucket = $bucket;
    return $this;
  }

  public function getBucket() {
    return $this->bucket;
  }

  public function setParametersForGetObject($key) {
    $bucket = $this->getBucket();

    $this->setHTTPMethod('GET');
    $this->setPath($bucket.'/'.$key);

    return $this;
  }

  protected function didReceiveResult($result) {
    list($status, $body, $headers) = $result;

    if (!$status->isError()) {
      return $body;
    }

    if ($status->getStatusCode() === 404) {
      return null;
    }

    return parent::didReceiveResult($result);
  }

}
