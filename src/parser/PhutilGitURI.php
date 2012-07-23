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
 * Parser for the alternate URI scheme used by SCP and Git, which look
 * like this:
 *
 *   user@host:path
 *
 * (Git calls these URIs "scp-style" in its documentation, but most users and
 * developers are likely to run into them in the context of Git and I couldn't
 * find an official name or specification, so I'm going with "GitURI".)
 *
 * Note that these URIs can not be transformed into normal URIs because the
 * path is interpreted as relative on the remote, rather than absolute (as with
 * normal URIs).
 *
 * @group util
 */
final class PhutilGitURI {

  private $user;
  private $domain;
  private $path;

  public function __construct($uri) {
    $parts = $this->parseURI($uri);
    if ($parts) {
      $this->user     = $parts[1];
      $this->domain   = $parts[2];
      $this->path     = $parts[3];
    }
  }

  private static function parseURI($uri) {
    $user   = '(?:([^@]+)@)?';
    $domain = '([^:]+)';
    $path   = ':(.*)';

    $regexp = '/^'.$user.$domain.$path.'$/';
    $matches = null;
    $ok = preg_match($regexp, $uri, $matches);
    if ($ok) {
      return array_pad($matches, 4, '');
    }

    return null;
  }

  public function __toString() {
    $user = null;
    if ($this->user) {
      $user = $this->user.'@';
    }

    $domain = $this->domain;
    $path = $this->path;

    return $user.$domain.':'.$path;
  }

  public function setDomain($domain) {
    $this->domain = $domain;
    return $this;
  }

  public function getDomain() {
    return $this->domain;
  }

  public function setPath($path) {
    $this->path = $path;
    return $this;
  }

  public function getPath() {
    return $this->path;
  }

  public function setUser($user) {
    $this->user = $user;
    return $this;
  }

  public function getUser() {
    return $this->user;
  }

}

