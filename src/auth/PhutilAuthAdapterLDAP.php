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
    return $this->readLDAPRecordAccountID($this->getLDAPUserData());
  }

  public function getAccountName() {
    return $this->readLDAPRecordAccountName($this->getLDAPUserData());
  }

  public function getAccountRealName() {
    return $this->readLDAPRecordRealName($this->getLDAPUserData());
  }

  public function getAccountEmail() {
    return $this->readLDAPRecordEmail($this->getLDAPUserData());
  }

  public function readLDAPRecordAccountID(array $record) {
    $key = $this->usernameAttribute;
    if (!strlen($key)) {
      $key = $this->searchAttribute;
    }
    return $this->readLDAPData($record, $key);
  }

  public function readLDAPRecordAccountName(array $record) {
    return $this->readLDAPRecordAccountID($record);
  }

  public function readLDAPRecordRealName(array $record) {
    $parts = array();
    foreach ($this->realNameAttributes as $attribute) {
      $parts[] = $this->readLDAPData($record, $attribute);
    }
    $parts = array_filter($parts);

    if ($parts) {
      return implode(' ', $parts);
    }

    return null;
  }

  public function readLDAPRecordEmail(array $record) {
    return $this->readLDAPData($record, 'mail');
  }

  private function getLDAPUserData() {
    if ($this->ldapUserData === null) {
      $this->ldapUserData = $this->loadLDAPUserData();
    }

    return $this->ldapUserData;
  }

  private function readLDAPData(array $data, $key, $default = null) {
    $list = idx($data, $key);
    if ($list === null) {
      // At least in some cases (and maybe in all cases) the results from
      // ldap_search() are keyed in lowercase. If we missed on the first
      // try, retry with a lowercase key.
      $list = idx($data, phutil_utf8_strtolower($key));
    }

    // NOTE: In most cases, the property is an array, like:
    //
    //   array(
    //     'count' => 1,
    //     0 => 'actual-value-we-want',
    //   )
    //
    // However, in at least the case of 'dn' after we "searchFirst", the
    // property is a bare string.

    if (is_scalar($list) && strlen($list)) {
      return $list;
    } else if (is_array($list)) {
      return $list[0];
    } else {
      return $default;
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

      $profiler = PhutilServiceProfiler::getInstance();
      $call_id = $profiler->beginServiceCall(
        array(
          'type' => 'ldap',
          'call' => 'connect',
          'host' => $host,
          'port' => $this->port,
        ));

      $conn = @ldap_connect($host, $this->port);

      $profiler->endServiceCall(
        $call_id,
        array(
          'ok' => (bool)$conn,
        ));

      if (!$conn) {
        throw new Exception(
          "Unable to connect to LDAP server ({$host}:{$port}).");
      }

      $options = array(
        LDAP_OPT_PROTOCOL_VERSION => (int)$this->ldapVersion,
        LDAP_OPT_REFERRALS        => (int)$this->ldapReferrals,
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
        $profiler = PhutilServiceProfiler::getInstance();
        $call_id = $profiler->beginServiceCall(
          array(
            'type' => 'ldap',
            'call' => 'start-tls',
          ));

        // NOTE: This boils down to a function call to ldap_start_tls_s() in
        // C, which is a service call.
        $ok = @ldap_start_tls($conn);

        $profiler->endServiceCall(
          $call_id,
          array());

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

  public function searchLDAP($pattern /* ... */) {
    $args = func_get_args();
    $query = call_user_func_array('ldap_sprintf', $args);

    $conn = $this->establishConnection();

    $profiler = PhutilServiceProfiler::getInstance();
    $call_id = $profiler->beginServiceCall(
      array(
        'type'  => 'ldap',
        'call'  => 'search',
        'dn'    => $this->baseDistinguishedName,
        'query' => $query,
      ));

    $result = @ldap_search($conn, $this->baseDistinguishedName, $query);

    $profiler->endServiceCall($call_id, array());

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
    $profiler = PhutilServiceProfiler::getInstance();
    $call_id = $profiler->beginServiceCall(
      array(
        'type' => 'ldap',
        'call' => 'bind',
        'user' => $user,
      ));

    // NOTE: ldap_bind() dumps cleartext passwords into logs by default. Keep
    // it quiet.
    $ok = @ldap_bind($conn, $user, $pass->openEnvelope());

    $profiler->endServiceCall($call_id, array());

    if (!$ok) {
      $this->raiseConnectionException(
        $conn,
        pht("Failed to bind to LDAP server (as user '%s').", $user),
        $is_bind = true);
    }
  }

}
