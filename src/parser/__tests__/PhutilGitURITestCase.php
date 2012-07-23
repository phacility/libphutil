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
 * Test cases for @{class:PhutilGitURI} parser.
 *
 * @group util
 */
final class PhutilGitURITestCase extends ArcanistPhutilTestCase {

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
