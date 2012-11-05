<?php

/**
 * Test cases for @{class:PhutilURI} parser.
 *
 * @group testcase
 */
final class PhutilURITestCase extends PhutilTestCase {

  public function testURIParsing() {
    $uri = new PhutilURI('http://user:pass@host:99/path/?query=value#fragment');
    $this->assertEqual('http', $uri->getProtocol(), 'protocol');
    $this->assertEqual('user', $uri->getUser(), 'user');
    $this->assertEqual('pass', $uri->getPass(), 'pass');
    $this->assertEqual('host', $uri->getDomain(), 'domain');
    $this->assertEqual('99', $uri->getPort(), 'port');

    $this->assertEqual('/path/', $uri->getPath(), 'path');
    $this->assertEqual(
      array(
        'query' => 'value',
      ),
      $uri->getQueryParams(),
      'query params');
    $this->assertEqual('fragment', $uri->getFragment(), 'fragment');
    $this->assertEqual(
      'http://user:pass@host:99/path/?query=value#fragment',
      (string)$uri,
      'uri');


    $uri = new PhutilURI('ssh://git@example.com/example/example.git');
    $this->assertEqual('ssh', $uri->getProtocol(), 'protocol');
    $this->assertEqual('git', $uri->getUser(), 'user');
    $this->assertEqual('', $uri->getPass(), 'pass');
    $this->assertEqual('example.com', $uri->getDomain(), 'domain');
    $this->assertEqual('', $uri->getPort(), 'port');

    $this->assertEqual('/example/example.git', $uri->getPath(), 'path');
    $this->assertEqual(array(), $uri->getQueryParams(), 'query params');
    $this->assertEqual('', $uri->getFragment(), 'fragment');
    $this->assertEqual(
      'ssh://git@example.com/example/example.git',
      (string)$uri,
      'uri');
  }


}
