<?php

final class PhutilGitHubResponse extends Phobject {

  private $status;
  private $headers;
  private $body;

  public function setStatus($status) {
    $this->status = $status;
    return $this;
  }

  public function getStatus() {
    return $this->status;
  }

  public function setBody(array $body) {
    $this->body = $body;
    return $this;
  }

  public function getBody() {
    return $this->body;
  }

  public function setHeaders(array $headers) {
    $this->headers = $headers;
    return $this;
  }

  public function getHeaders() {
    return $this->headers;
  }

  public function getHeaderValue($key, $default = null) {
    $key = phutil_utf8_strtolower($key);

    foreach ($this->headers as $header) {
      list($hkey, $value) = $header;
      if (phutil_utf8_strtolower($hkey) === $key) {
        return $value;
      }
    }

    return $default;
  }

}
