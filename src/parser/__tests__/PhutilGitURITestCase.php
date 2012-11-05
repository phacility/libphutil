<?php

/**
 * Test cases for @{class:PhutilGitURI} parser.
 *
 * @group util
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


}
