<?php

/*
 * Copyright 2012 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
