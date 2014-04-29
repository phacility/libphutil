<?php

/**
 * @covers PhutilGitURI
 */
final class PhutilGitURITestCase extends PhutilTestCase {

  public function testGitURIParsing() {
    $uri = new PhutilGitURI('git@host.com:path/to/something');
    $this->assertEqual('git', $uri->getUser());
    $this->assertEqual('host.com', $uri->getDomain());
    $this->assertEqual('path/to/something', $uri->getPath());
    $this->assertEqual('git@host.com:path/to/something', (string)$uri);

    $uri = new PhutilGitURI('host.com:path/to/something');
    $this->assertEqual('', $uri->getUser());
    $this->assertEqual('host.com', $uri->getDomain());
    $this->assertEqual('path/to/something', $uri->getPath());
    $this->assertEqual('host.com:path/to/something', (string)$uri);
  }

  public function testStrictGitURIParsingOfLeadingWhitespace() {
    $uri = new PhutilURI(' user@example.com');
    $this->assertEqual('', $uri->getDomain());
  }


}
