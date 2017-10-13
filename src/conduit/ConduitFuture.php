<?php

final class ConduitFuture extends FutureProxy {

  private $client;
  private $conduitMethod;
  private $profilerCallID;

  public function setClient(ConduitClient $client, $method) {
    $this->client = $client;
    $this->conduitMethod = $method;
    return $this;
  }

  public function isReady() {
    if ($this->profilerCallID === null) {
      $profiler = PhutilServiceProfiler::getInstance();

      $this->profilerCallID = $profiler->beginServiceCall(
        array(
          'type'    => 'conduit',
          'method'  => $this->conduitMethod,
          'size'    => $this->getProxiedFuture()->getHTTPRequestByteLength(),
        ));
    }

    return parent::isReady();
  }

  protected function didReceiveResult($result) {
    if ($this->profilerCallID !== null) {
      $profiler = PhutilServiceProfiler::getInstance();
      $profiler->endServiceCall(
        $this->profilerCallID,
        array());
    }

    list($status, $body, $headers) = $result;
    if ($status->isError()) {
      throw $status;
    }

    $raw = $body;

    $shield = 'for(;;);';
    if (!strncmp($raw, $shield, strlen($shield))) {
      $raw = substr($raw, strlen($shield));
    }

    $data = null;
    try {
      $data = phutil_json_decode($raw);
    } catch (PhutilJSONParserException $ex) {
      throw new PhutilProxyException(
        pht(
          'Host returned HTTP/200, but invalid JSON data in response to '.
          'a Conduit method call.'),
        $ex);
    }

    if ($data['error_code']) {
      throw new ConduitClientException(
        $data['error_code'],
        $data['error_info']);
    }

    $result = $data['result'];

    $result = $this->client->didReceiveResponse(
      $this->conduitMethod,
      $result);

    return $result;
  }

}
