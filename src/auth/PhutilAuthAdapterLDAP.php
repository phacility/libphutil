<?php

final class PhutilAuthAdapterLDAP extends PhutilAuthAdapter {

  private $hostname;
  private $port = 389;

  private $baseDistinguishedName;
  private $searchAttribute;
  private $usernameAttribute;
  private $realNameAttributes = array();
  private $ldapVersion = 3;
  private $ldapReferrals;
  private $ldapStartTLS;
  private $anonymousUsername;
  private $anonymousPassword;
  private $activeDirectoryDomain;
  private $searchFirst;

  private $loginUsername;
  private $loginPassword;

  private $ldapUserData;
  private $ldapConnection;

  private $console;

  public function printConfiguration() {
    $console = $this->console;
    unset($this->console);

      $properties = (array)$this;

      $pre = "\0PhutilAuthAdapterLDAP";
      $pre_len = strlen($pre);
      foreach ($properties as $key => $value) {
        if (strncmp($key, $pre, $pre_len) === 0) {
          unset($properties[$key]);
          $properties[substr($key, $pre_len)] = $value;
        }
      }
      $config = print_r($properties, true);

    $this->console = $console;
    $this->log("%s\n", $config);
  }

  public function setConsole(PhutilConsole $console) {
    $this->console = $console;
    return $this;
  }

  public function getAdapterType() {
    return 'ldap';
  }

  public function setHostname($host) {
    $this->hostname = $host;
    return $this;
  }

  public function setPort($port) {
    $this->port = $port;
    return $this;
  }

  public function getAdapterDomain() {
    return 'self';
  }

  public function setBaseDistinguishedName($base_distinguished_name) {
    $this->baseDistinguishedName = $base_distinguished_name;
    return $this;
  }

  public function setSearchAttribute($search_attribute) {
    $this->searchAttribute = $search_attribute;
    return $this;
  }

  public function setUsernameAttribute($username_attribute) {
    $this->usernameAttribute = $username_attribute;
    return $this;
  }

  public function setRealNameAttributes(array $attributes) {
    $this->realNameAttributes = $attributes;
    return $this;
  }

  public function setLDAPVersion($ldap_version) {
    $this->ldapVersion = $ldap_version;
    return $this;
  }

  public function setLDAPReferrals($ldap_referrals) {
    $this->ldapReferrals = $ldap_referrals;
    return $this;
  }

  public function setLDAPStartTLS($ldap_start_tls) {
    $this->ldapStartTLS = $ldap_start_tls;
    return $this;
  }

  public function setAnonymousUsername($anonymous_username) {
    $this->anonymousUsername = $anonymous_username;
    return $this;
  }

  public function setAnonymousPassword(
    PhutilOpaqueEnvelope $anonymous_password) {
    $this->anonymousPassword = $anonymous_password;
    return $this;
  }

  public function setLoginUsername($login_username) {
    $this->loginUsername = $login_username;
    return $this;
  }

  public function setLoginPassword(PhutilOpaqueEnvelope $login_password) {
    $this->loginPassword = $login_password;
    return $this;
  }

  public function setSearchFirst($search) {
    $this->searchFirst = $search;
    return $this;
  }

  public function setActiveDirectoryDomain($domain) {
    $this->activeDirectoryDomain = $domain;
    return $this;
  }

  public function getAccountID() {
    $key = coalesce($this->usernameAttribute, $this->searchAttribute);
    return $this->getLDAPUserData($key);
  }

  public function getAccountName() {
    return $this->getAccountID();
  }

  public function getAccountEmail() {
    return $this->getLDAPUserData('mail');
  }

  public function getAccountRealName() {
    $parts = array();
    foreach ($this->realNameAttributes as $attribute) {
      $parts[] = $this->getLDAPUserData($attribute);
    }
    $parts = array_filter($parts);

    if ($parts) {
      return implode(' ', $parts);
    }

    return null;
  }

  private function getLDAPUserData($key, $default = null) {
    if ($this->ldapUserData === null) {
      $this->ldapUserData = $this->loadLDAPUserData();

      $this->log(
        "LDAP USER DATA\n\n%s\n\n",
        print_r($this->ldapUserData, true));
    }

    return $this->readLDAPData($this->ldapUserData, $key, $default);
  }

  private function readLDAPData(array $data, $key, $default = null) {
    $list = idx($data, $key);
    if (!is_array($list)) {
      // At least in some cases (and maybe in all cases) the results from
      // ldap_search() are keyed in lowercase. If we missed on the first
      // try, retry with a lowercase key.
      $list = idx($data, phutil_utf8_strtolower($key));
    }

    if (!is_array($list)) {
      return $default;
    } else {
      return $list[0];
    }
  }

  private function loadLDAPUserData() {
    $conn = $this->establishConnection();

    $login_user = $this->loginUsername;
    $login_pass = $this->loginPassword;
    $distinguished_name = ldap_sprintf(
      '%Q=%s,%Q',
      $this->searchAttribute,
      $login_user,
      $this->baseDistinguishedName);

    if ($this->searchFirst) {
      $user = $this->searchLDAPForUser($this->usernameAttribute, $login_user);
      if (!$user) {
        throw new Exception("Invalid credentials.");
      }
      $login_user = $this->readLDAPData($user, $this->searchAttribute);
      $distinguished_name = $this->readLDAPData($user, 'dn');
    }

    if ($this->activeDirectoryDomain) {
      $distinguished_name = ldap_sprintf(
        '%s@%Q',
        $login_user,
        $this->activeDirectoryDomain);
    }

    $this->bindLDAP($conn, $distinguished_name, $login_pass);

    return $this->searchLDAPForUser($this->searchAttribute, $login_user);
  }

  private function establishConnection() {
    if (!$this->ldapConnection) {
      $host = $this->hostname;
      $port = $this->port;

      $conn = @ldap_connect($host, $this->port);
      if (!$conn) {
        throw new Exception(
          "Unable to connect to LDAP server ({$host}:{$port}).");
      }

      $options = array(
        LDAP_OPT_PROTOCOL_VERSION => $this->ldapVersion,
        LDAP_OPT_REFERRALS        => $this->ldapReferrals,
      );

      foreach ($options as $name => $value) {
        $ok = @ldap_set_option($conn, $name, $value);
        if (!$ok) {
          $this->raiseConnectionException(
            $conn,
            pht(
              "Unable to set LDAP option '%s' to value '%s'!",
              $name,
              $value));
        }
      }

      if ($this->ldapStartTLS) {
        $ok = @ldap_start_tls($conn);
        if (!$ok) {
          $this->raiseConnectionException(
            $conn,
            pht("Unable to start TLS connection when connecting to LDAP."));
        }
      }

      if (strlen($this->anonymousUsername)) {
        $user = $this->anonymousUsername;
        $pass = $this->anonymousPassword;
        $this->bindLDAP($conn, $user, $pass);
      }

      $this->ldapConnection = $conn;
    }

    return $this->ldapConnection;
  }


  private function searchLDAPForUser($attribute, $username) {
    $conn = $this->establishConnection();

    $results = $this->searchLDAP('%Q=%S', $attribute, $username);

    if (!$results) {
      return null;
    }

    if (count($results) > 1) {
      throw new Exception(
        "LDAP user query returned more than one result. It must uniquely ".
        "identify a user.");
    }

    return head($results);
  }

  private function searchLDAP($pattern /* ... */) {
    $args = func_get_args();
    $query = call_user_func_array('ldap_sprintf', $args);

    $conn = $this->establishConnection();

    $this->log(
      "%s\n",
      pht(
        "LDAP: Searching (%s), (%s)...",
        $this->baseDistinguishedName,
        $query));

    $result = @ldap_search($conn, $this->baseDistinguishedName, $query);
    if (!$result) {
      $this->raiseConnectionException(
        $conn,
        pht("LDAP search failed."));
    }

    $entries = @ldap_get_entries($conn, $result);

    if (!$entries) {
      $this->raiseConnectionException(
        $conn,
        pht("Failed to get LDAP entries from search result."));
    }

    $this->log(
      "%s\n",
      pht("LDAP: Found %s entries.", count($entries['count'])));

    $results = array();
    for ($ii = 0; $ii < $entries['count']; $ii++) {
      $results[] = $entries[$ii];
    }

    return $results;
  }

  private function raiseConnectionException($conn, $message, $is_bind = false) {
    $errno = @ldap_errno($conn);
    $error = @ldap_error($conn);

    if ($errno || $error) {
      $full_message = pht(
        "LDAP Exception: %s\nLDAP Error #%d: %s",
        $message,
        $errno,
        $error);
    } else {
      $full_message = pht(
        "LDAP Exception: %s",
        $message);
    }

    throw new Exception($full_message);
  }

  private function bindLDAP($conn, $user, PhutilOpaqueEnvelope $pass) {
    $this->log("%s\n", pht("LDAP: Binding %s...", $user));


    // NOTE: ldap_bind() dumps cleartext passwords into logs by default. Keep
    // it quiet.

    // TODO: We should provide a way to disable PhutilErrorHandler for cases
    // like this; for now, the log is disabled at the Phabricator level
    // instead. See T3351.
    $ok = @ldap_bind($conn, $user, $pass->openEnvelope());

    if (!$ok) {
      $this->raiseConnectionException(
        $conn,
        pht("Failed to bind to LDAP server (as user '%s').", $user),
        $is_bind = true);
    }
  }

  private function log($pattern) {
    $args = func_get_args();
    $console = $this->console;
    if (!$console) {
      return;
    }

    call_user_func_array(array($console, 'writeLog'), $args);
  }


}
