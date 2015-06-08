<?php

/**
 * Test cases for @{class:PhutilURI} parser.
 */
final class PhutilURITestCase extends PhutilTestCase {

  public function testURIParsing() {
    $uri = new PhutilURI('http://user:pass@host:99/path/?query=value#fragment');
    $this->assertEqual('http', $uri->getProtocol(), pht('protocol'));
    $this->assertEqual('user', $uri->getUser(), pht('user'));
    $this->assertEqual('pass', $uri->getPass(), pht('password'));
    $this->assertEqual('host', $uri->getDomain(), pht('domain'));
    $this->assertEqual('99', $uri->getPort(), pht('port'));

    $this->assertEqual('/path/', $uri->getPath(), pht('path'));
    $this->assertEqual(
      array(
        'query' => 'value',
      ),
      $uri->getQueryParams(),
      'query params');
    $this->assertEqual('fragment', $uri->getFragment(), pht('fragment'));
    $this->assertEqual(
      'http://user:pass@host:99/path/?query=value#fragment',
      (string)$uri,
      'uri');


    $uri = new PhutilURI('ssh://git@example.com/example/example.git');
    $this->assertEqual('ssh', $uri->getProtocol(), pht('protocol'));
    $this->assertEqual('git', $uri->getUser(), pht('user'));
    $this->assertEqual('', $uri->getPass(), pht('password'));
    $this->assertEqual('example.com', $uri->getDomain(), pht('domain'));
    $this->assertEqual('', $uri->getPort(), 'port');

    $this->assertEqual('/example/example.git', $uri->getPath(), pht('path'));
    $this->assertEqual(
      array(),
      $uri->getQueryParams(),
      pht('query parameters'));
    $this->assertEqual('', $uri->getFragment(), pht('fragment'));
    $this->assertEqual(
      'ssh://git@example.com/example/example.git',
      (string)$uri,
      'uri');


    $uri = new PhutilURI('http://0@domain.com/');
    $this->assertEqual('0', $uri->getUser());
    $this->assertEqual('http://0@domain.com/', (string)$uri);

    $uri = new PhutilURI('http://0:0@domain.com/');
    $this->assertEqual('0', $uri->getUser());
    $this->assertEqual('0', $uri->getPass());
    $this->assertEqual('http://0:0@domain.com/', (string)$uri);

    $uri = new PhutilURI('http://%20:%20@domain.com/');
    $this->assertEqual(' ', $uri->getUser());
    $this->assertEqual(' ', $uri->getPass());
    $this->assertEqual('http://%20:%20@domain.com/', (string)$uri);

    $uri = new PhutilURI('http://%40:%40@domain.com/');
    $this->assertEqual('@', $uri->getUser());
    $this->assertEqual('@', $uri->getPass());
    $this->assertEqual('http://%40:%40@domain.com/', (string)$uri);

    // These tests are covering cases where cURL and parse_url() behavior
    // may differ in potentially dangerous ways. See T6755 for discussion.

    // In general, we defuse these attacks by emitting URIs which escape
    // special characters so that they are interpreted unambiguously by
    // cURL in the same way that parse_url() interpreted them.

    $uri = new PhutilURI('http://u:p@evil.com?@good.com');
    $this->assertEqual('u', $uri->getUser());
    $this->assertEqual('p', $uri->getPass());
    $this->assertEqual('evil.com', $uri->getDomain());
    $this->assertEqual('http://u:p@evil.com?%40good.com=', (string)$uri);

    $uri = new PhutilURI('http://good.com#u:p@evil.com/');
    $this->assertEqual('good.com#u', $uri->getUser());
    $this->assertEqual('p', $uri->getPass());
    $this->assertEqual('evil.com', $uri->getDomain());
    $this->assertEqual('http://good.com%23u:p@evil.com/', (string)$uri);

    $uri = new PhutilURI('http://good.com?u:p@evil.com/');
    $this->assertEqual('', $uri->getUser());
    $this->assertEqual('', $uri->getPass());
    $this->assertEqual('good.com', $uri->getDomain());
    $this->assertEqual('http://good.com?u%3Ap%40evil.com%2F=', (string)$uri);

  }

  public function testURIGeneration() {
    $uri = new PhutilURI('http://example.com');
    $uri->setPath('bar');
    $this->assertEqual('http://example.com/bar', $uri->__toString());
  }

  public function testStrictURIParsingOfHosts() {
    $uri = new PhutilURI('http://&amp;/');
    $this->assertEqual('', $uri->getDomain());
  }

  public function testStrictURIParsingOfLeadingWhitespace() {
    $uri = new PhutilURI(' http://example.com/');
    $this->assertEqual('', $uri->getDomain());
  }

  public function testAppendPath() {
    $uri = new PhutilURI('http://example.com');
    $uri->appendPath('foo');
    $this->assertEqual('http://example.com/foo', $uri->__toString());
    $uri->appendPath('bar');
    $this->assertEqual('http://example.com/foo/bar', $uri->__toString());

    $uri = new PhutilURI('http://example.com');
    $uri->appendPath('/foo/');
    $this->assertEqual('http://example.com/foo/', $uri->__toString());
    $uri->appendPath('/bar/');
    $this->assertEqual('http://example.com/foo/bar/', $uri->__toString());

    $uri = new PhutilURI('http://example.com');
    $uri->appendPath('foo');
    $this->assertEqual('http://example.com/foo', $uri->__toString());
    $uri->appendPath('/bar/');
    $this->assertEqual('http://example.com/foo/bar/', $uri->__toString());
  }

  public function testUnusualURIs() {
    $uri = new PhutilURI('file:///path/to/file');
    $this->assertEqual('file', $uri->getProtocol(), pht('protocol'));
    $this->assertEqual('', $uri->getDomain(), pht('domain'));
    $this->assertEqual('/path/to/file', $uri->getPath(), pht('path'));

    $uri = new PhutilURI('idea://open?x=/');
    $this->assertEqual('idea', $uri->getProtocol(), pht('protocol'));
    $this->assertEqual('open', $uri->getDomain(), pht('domain'));
    $this->assertEqual('', $uri->getPath(), pht('path'));
    $this->assertEqual(
      array(
        'x' => '/',
      ),
      $uri->getQueryParams());
  }

  public function testDefaultPorts() {
    $uri = new PhutilURI('http://www.example.com');
    $this->assertEqual('80', $uri->getPortWithProtocolDefault());

    $uri = new PhutilURI('https://www.example.com');
    $this->assertEqual('443', $uri->getPortWithProtocolDefault());

    $uri = new PhutilURI('ssh://git@example.com/example/example.git');
    $this->assertEqual('22', $uri->getPortWithProtocolDefault());

    $uri = new PhutilURI('unknown://www.example.com');
    $this->assertEqual('', $uri->getPortWithProtocolDefault());
  }

}
