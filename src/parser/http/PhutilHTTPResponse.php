<?php

final class PhutilHTTPResponse
  extends Phobject {

  private $headers = array();
  private $body;
  private $status;
  private $writeHandle;

  public function __construct() {
    $this->body = new PhutilRope();
  }

  public function setHeaders(array $headers) {
    $this->headers = $headers;
    return $this;
  }

  public function getHeaders() {
    return $this->headers;
  }

  public function setStatus(HTTPFutureResponseStatus $status) {
    $this->status = $status;
    return $this;
  }

  public function getStatus() {
    return $this->status;
  }

  public function appendBody($bytes) {
    if ($this->writeHandle !== null) {
      $result = @fwrite($this->writeHandle, $bytes);
      if ($result !== strlen($bytes)) {
        throw new Exception(
          pht('Failed to write response to disk. (Maybe the disk is full?)'));
      }
    } else {
      $this->body->append($bytes);
    }
  }

  public function getBody() {
    if ($this->writeHandle !== null) {
      return null;
    }

    return $this->body->getAsString();
  }

  public function setWriteHandle($write_handle) {
    $this->writeHandle = $write_handle;
    return $this;
  }

  public function getWriteHandle() {
    return $this->writeHandle;
  }

}
