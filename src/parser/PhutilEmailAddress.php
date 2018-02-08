<?php

/**
 * Basic email address parser. This parser is very liberal and does not attempt
 * to be fully RFC-compliant, because trying to do so is a crazy mess. However,
 * it should parse all reasonable addresses which are actually in use on the
 * internet today.
 */
final class PhutilEmailAddress extends Phobject {

  private $displayName;
  private $localPart;
  private $domainName;

  public function __construct($email_address = null) {
    $email_address = trim($email_address);

    $matches = null;
    if (preg_match('/^(.*)<(.*?)>$/', $email_address, $matches)) {
      $display_name = trim($matches[1], '\'" ');
      if (strpos($matches[2], '@') !== false) {
        list($local_part, $domain_name) = explode('@', $matches[2], 2);
      } else {
        $local_part = $matches[2];
        $domain_name = null;
      }
    } else if (preg_match('/^(.*)@(.*)$/', $email_address, $matches)) {
      $display_name = null;
      $local_part = $matches[1];
      $domain_name = $matches[2];
    } else {
      $display_name = null;
      $local_part = $email_address;
      $domain_name = null;
    }

    $this->displayName = $display_name;
    $this->localPart = $local_part;
    $this->domainName = $domain_name;
  }

  public function __toString() {
    $address = $this->getAddress();
    if (strlen($this->displayName)) {
      $display_name = $this->encodeDisplayName($this->displayName);
      return $display_name.' <'.$address.'>';
    } else {
      return $address;
    }
  }

  public function setDisplayName($display_name) {
    $this->displayName = $display_name;
    return $this;
  }

  public function getDisplayName() {
    return $this->displayName;
  }

  public function setLocalPart($local_part) {
    $this->localPart = $local_part;
    return $this;
  }

  public function getLocalPart() {
    return $this->localPart;
  }

  public function setDomainName($domain_name) {
    $this->domainName = $domain_name;
    return $this;
  }

  public function getDomainName() {
    return $this->domainName;
  }

  public function setAddress($address) {
    $parts = explode('@', $address, 2);

    $this->localPart = $parts[0];
    if (isset($parts[1])) {
      $this->domainName = $parts[1];
    }

    return $this;
  }

  public function getAddress() {
    $address = $this->localPart;
    if (strlen($this->domainName)) {
      $address .= '@'.$this->domainName;
    }
    return $address;
  }

  private function encodeDisplayName($name) {
    // NOTE: This is a reasonable effort based on a cursory reading of
    // RFC2822, but may be significantly misguided.

    // Newlines are not permitted, even when escaped. Discard them.
    $name = preg_replace("/\s*[\r\n]+\s*/", ' ', $name);

    // Escape double quotes and backslashes.
    $name = addcslashes($name, '\\"');

    // Quote the string.
    $name = '"'.$name.'"';

    return $name;
  }

}
