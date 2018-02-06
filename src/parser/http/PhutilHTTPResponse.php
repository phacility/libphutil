<?php

final class PhutilHTTPResponse
  extends Phobject {

  private $headers = array();
  private $body;
  private $status;

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
    $this->body->append($bytes);
  }

  public function getBody() {
    return $this->body->getAsString();
  }

}
