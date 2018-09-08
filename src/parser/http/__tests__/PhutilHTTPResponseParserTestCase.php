<?php

final class PhutilHTTPResponseParserTestCase
  extends PhutilTestCase {

  public function testSimpleParsing() {
    $input = <<<EORESPONSE
HTTP/1.0 200 OK
Duck: Quack

I am the very model of a modern major general.
EORESPONSE;

    $this->assertParse(
      array(
        array(
          'headers' => array(
            array('Duck', 'Quack'),
          ),
          'body' => 'I am the very model of a modern major general.',
        ),
      ),
      $input);

    $input = <<<EORESPONSE
HTTP/1.0 200 Connection Established
X-I-Am-A-Proxy-Server: Hello

HTTP/1.0 100 Continue
X-Everything-Is-Fine: true

HTTP/1.1 302 Found
Location: Over-There

HTTP/1.0 404 Not Found

Not all who wander are lost.
EORESPONSE;

    $this->assertParse(
      array(
        array(
          'code' => 200,
          'headers' => array(
            array('X-I-Am-A-Proxy-Server', 'Hello'),
          ),
          'body' => '',
        ),
        array(
          'code' => 100,
          'headers' => array(
            array('X-Everything-Is-Fine', 'true'),
          ),
          'body' => '',
        ),
        array(
          'code' => 302,
          'headers' => array(
            array('Location', 'Over-There'),
          ),
          'body' => '',
        ),
        array(
          'code' => 404,
          'headers' => array(),
          'body' => 'Not all who wander are lost.',
        ),
      ),
      $input,
      id(new PhutilHTTPResponseParser())
        ->setFollowLocationHeaders(true));

    $input = <<<EORESPONSE
HTTP/1.0 200
Reason: none

This response has no "reason-phrase", which is unusual but valid.
EORESPONSE;

    $this->assertParse(
      array(
        array(
          'code' => 200,
          'headers' => array(
            array('Reason', 'none'),
          ),
          'body' =>
            'This response has no "reason-phrase", which is unusual but valid.',
        ),
      ),
      $input,
      id(new PhutilHTTPResponseParser()));
  }

  private function assertParse(array $expect, $input, $parser = null) {
    if ($parser === null) {
      $parser = new PhutilHTTPResponseParser();
    }

    // Submit the input in little bits to try to catch any weird parser bugs.
    $length = strlen($input);
    $pos = 0;
    while ($pos < $length) {
      $next_len = mt_rand(1, 32);
      $piece = substr($input, $pos, $next_len);
      $pos = $pos + $next_len;

      $parser->readBytes($piece);
    }

    $responses = $parser->getResponses();

    $this->assertEqual(count($expect), count($responses));

    $expect = array_values($expect);
    $responses = array_values($responses);

    for ($ii = 0; $ii < count($expect); $ii++) {
      $expect_map = $expect[$ii];
      $actual = $responses[$ii];

      foreach ($expect_map as $key => $spec) {
        switch ($key) {
          case 'headers':
            $this->assertEqual($spec, $actual->getHeaders());
            break;
          case 'body':
            $this->assertEqual($spec, $actual->getBody());
            break;
          case 'code':
            $status = $actual->getStatus();
            $this->assertTrue($status instanceof HTTPFutureHTTPResponseStatus);
            $this->assertEqual($spec, $status->getStatusCode());
            break;
          default:
            throw new Exception(
              pht(
                'Unknown HTTPResponseParser test ("%s").',
                $key));
        }
      }
    }
  }

}
