<?php

/**
 * Basic URI parser object.
 *
 * @group util
 */
final class PhutilURI {

  private $protocol;
  private $user;
  private $pass;
  private $domain;
  private $port;
  private $path;
  private $query = array();
  private $fragment;

  public function __construct($uri) {
    $parts = parse_url($uri);
    if ($parts) {
      // stringyness is to preserve API compatibility and
      // allow the tests to continue passing
      $this->protocol = idx($parts, 'scheme', '');
      $this->user     = idx($parts, 'user', '');
      $this->pass     = idx($parts, 'pass', '');
      $this->domain   = idx($parts, 'host', '');
      $this->port     = (string)idx($parts, 'port', '');
      $this->path     = idx($parts, 'path', '');
      $query = idx($parts, 'query');
      if ($query) {
        parse_str($query, $this->query);
      }
      $this->fragment = idx($parts, 'fragment', '');
    }
  }

  public function __toString() {
    $prefix = null;
    if ($this->protocol || $this->domain || $this->port) {
      $protocol = nonempty($this->protocol, 'http');

      $auth = '';
      if ($this->user && $this->pass) {
        $auth = $this->user.':'.$this->pass.'@';
      } else if ($this->user) {
        $auth = $this->user.'@';
      }

      $prefix = $protocol.'://'.$auth.$this->domain;
      if ($this->port) {
        $prefix .= ':'.$this->port;
      }
    }

    if ($this->query) {
      $query = '?'.http_build_query($this->query);
    } else {
      $query = null;
    }

    if (strlen($this->getFragment())) {
      $fragment = '#'.$this->getFragment();
    } else {
      $fragment = null;
    }


    return $prefix.$this->getPath().$query.$fragment;
  }

  public function setQueryParam($key, $value) {
    if ($value === null) {
      unset($this->query[$key]);
    } else {
      $this->query[$key] = $value;
    }
    return $this;
  }

  public function setQueryParams(array $params) {
    $this->query = $params;
    return $this;
  }

  public function getQueryParams() {
    return $this->query;
  }

  public function setProtocol($protocol) {
    $this->protocol = $protocol;
    return $this;
  }
  public function getProtocol() {
    return $this->protocol;
  }

  public function setDomain($domain) {
    $this->domain = $domain;
    return $this;
  }

  public function getDomain() {
    return $this->domain;
  }

  public function setPort($port) {
    $this->port = $port;
    return $this;
  }
  public function getPort() {
    return $this->port;
  }

  public function setPath($path) {
    if ($this->domain && strlen($path) && $path[0] !== '/') {
      $path = '/'.$path;
    }
    $this->path = $path;
    return $this;
  }

  public function getPath() {
    return $this->path;
  }

  public function setFragment($fragment) {
    $this->fragment = $fragment;
    return $this;
  }

  public function getFragment() {
    return $this->fragment;
  }

  public function setUser($user) {
    $this->user = $user;
    return $this;
  }

  public function getUser() {
    return $this->user;
  }

  public function setPass($pass) {
    $this->pass = $pass;
    return $this;
  }

  public function getPass() {
    return $this->pass;
  }

  public function alter($key, $value) {
    $altered = clone $this;
    $altered->setQueryParam($key, $value);
    return $altered;
  }

}

