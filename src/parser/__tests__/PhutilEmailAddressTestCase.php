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

  public function testEmailEncoding() {
    $cases = array(
      array(
        'Tangerine Q. Hawthorne',
        'thawthorne@blackspire.bunker',
        '"Tangerine Q. Hawthorne" <thawthorne@blackspire.bunker>',
      ),
      array(
        'Hector "\\" Backslash',
        'hector@backslash',
        '"Hector \\"\\\\\\" Backslash" <hector@backslash>',
      ),
      array(
        'My Middle Name "<name@domain>" Is My Email',
        'name@domain',
        '"My Middle Name \\"<name@domain>\\" Is My Email" <name@domain>',
      ),
      array(
        "My Legal Name\nContains A Newline",
        'newline@example',
        '"My Legal Name Contains A Newline" <newline@example>',
      ),
    );

    foreach ($cases as $case) {
      list($name, $address, $expect) = $case;
      $actual = (string)id(new PhutilEmailAddress())
        ->setDisplayName($name)
        ->setAddress($address);
      $this->assertEqual(
        $expect,
        $actual,
        pht('Email: %s + %s -> %s', $name, $address, $expect));
    }
  }

}
