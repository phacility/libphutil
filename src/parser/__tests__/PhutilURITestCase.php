<?php

/**
 * Test cases for @{class:PhutilURI} parser.
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
    $this->assertEqual('file', $uri->getProtocol(), 'protocol');
    $this->assertEqual('', $uri->getDomain(), 'domain');
    $this->assertEqual('/path/to/file', $uri->getPath(), 'path');

    $uri = new PhutilURI('idea://open?x=/');
    $this->assertEqual('idea', $uri->getProtocol(), 'protocol');
    $this->assertEqual('open', $uri->getDomain(), 'domain');
    $this->assertEqual('', $uri->getPath(), 'path');
    $this->assertEqual(
      array(
        'x' => '/',
      ),
      $uri->getQueryParams());
  }

}
