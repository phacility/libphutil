<?php

/**
 * Test cases for @{class:PhutilEmailAddress} parser.
 */
final class PhutilEmailAddressTestCase extends PhutilTestCase {

  public function testEmailParsing() {
    $email = new PhutilEmailAddress('Abraham Lincoln <alincoln@logcabin.com>');
    $this->assertEqual(
      'Abraham Lincoln',
      $email->getDisplayName());
    $this->assertEqual(
      'alincoln',
      $email->getLocalPart());
    $this->assertEqual(
      'logcabin.com',
      $email->getDomainName());
    $this->assertEqual(
      'alincoln@logcabin.com',
      $email->getAddress());

    $email = new PhutilEmailAddress('alincoln@logcabin.com');
    $this->assertEqual(
      null,
      $email->getDisplayName());
    $this->assertEqual(
      'alincoln',
      $email->getLocalPart());
    $this->assertEqual(
      'logcabin.com',
      $email->getDomainName());
    $this->assertEqual(
      'alincoln@logcabin.com',
      $email->getAddress());

    $email = new PhutilEmailAddress('"Abraham" <alincoln@logcabin.com>');
    $this->assertEqual(
      'Abraham',
      $email->getDisplayName());
    $this->assertEqual(
      'alincoln',
      $email->getLocalPart());
    $this->assertEqual(
      'logcabin.com',
      $email->getDomainName());
    $this->assertEqual(
      'alincoln@logcabin.com',
      $email->getAddress());

    $email = new PhutilEmailAddress('    alincoln@logcabin.com     ');
    $this->assertEqual(
      null,
      $email->getDisplayName());
    $this->assertEqual(
      'alincoln',
      $email->getLocalPart());
    $this->assertEqual(
      'logcabin.com',
      $email->getDomainName());
    $this->assertEqual(
      'alincoln@logcabin.com',
      $email->getAddress());

    $email = new PhutilEmailAddress('alincoln');
    $this->assertEqual(
      null,
      $email->getDisplayName());
    $this->assertEqual(
      'alincoln',
      $email->getLocalPart());
    $this->assertEqual(
      null,
      $email->getDomainName());
    $this->assertEqual(
      'alincoln',
      $email->getAddress());

    $email = new PhutilEmailAddress('alincoln <alincoln at logcabin dot com>');
    $this->assertEqual(
      'alincoln',
      $email->getDisplayName());
    $this->assertEqual(
      'alincoln at logcabin dot com',
      $email->getLocalPart());
    $this->assertEqual(
      null,
      $email->getDomainName());
    $this->assertEqual(
      'alincoln at logcabin dot com',
      $email->getAddress());
  }

}
