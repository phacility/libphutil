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
 * Basic email address parser. This parser is very liberal and does not attempt
 * to be fully RFC-compliant, because trying to do so is a crazy mess. However,
 * it should parse all reasonable addresses which are actually in use on the
 * internet today.
 *
 * @group util
 */
final class PhutilEmailAddress {

  private $displayName;
  private $localPart;
  private $domainName;

  public function __construct($email_address) {
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
    if ($this->displayName) {
      return $this->displayName.' <'.$address.'>';
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

  public function getAddress() {
    $address = $this->localPart;
    if ($this->domainName) {
      $address .= '@'.$this->domainName;
    }
    return $address;
  }

}

