<?php

final class PhutilIPAddressTestCase extends PhutilTestCase {

  public function testValidIPv4Addresses() {
    $cases = array(
      // Valid IP.
      '1.2.3.4' => true,

      // No nonsense.
      '1.2.3' => false,
      'duck' => false,
      '' => false,
      '1 2 3 4' => false,
      '.' => false,
      '1.2.3.4.' => false,
      '1..3.4' => false,

      // No leading zeroes.
      '0.0.0.0' => true,
      '0.0.0.01' => false,

      // No segments > 255.
      '255.255.255.255' => true,
      '255.255.255.256' => false,
    );

    foreach ($cases as $input => $expect) {
      $caught = null;
      try {
        PhutilIPAddress::newAddress($input);
      } catch (Exception $ex) {
        $caught = $ex;
      }

      $this->assertEqual(
        $expect,
        !($caught instanceof Exception),
        'PhutilIPv4Address['.$input.']');
    }
  }

  public function testValidIPv6Addresses() {
    $cases = array(
      '::' => true,
      '::1' => true,
      '1::' => true,
      '1::1' => true,
      '1:2:3:4:5:6:7:8' => true,
      '1:2:3::5:6:7:8' => true,
      '1:2:3::6:7:8' => true,

      // No nonsense.
      'quack:duck' => false,
      '11111:22222::' => false,


      // Too long.
      '1:2:3:4:5:6:7:8:9' => false,

      // Too short.
      '1:2:3' => false,

      // Too many omitted segments.
      '1:2:3:::7:8:9' => false,
      '1::3::7:8:9' => false,
    );

    foreach ($cases as $input => $expect) {
      $caught = null;
      try {
        PhutilIPAddress::newAddress($input);
      } catch (Exception $ex) {
        $caught = $ex;
      }

      $this->assertEqual(
        $expect,
        !($caught instanceof Exception),
        'PhutilIPv6Address['.$input.']');
    }
  }

  public function testIPv4AddressToBits() {
    $cases = array(
      '0.0.0.0'         => '00000000000000000000000000000000',
      '255.255.255.255' => '11111111111111111111111111111111',
      '255.0.0.0'       => '11111111000000000000000000000000',
      '0.0.0.1'         => '00000000000000000000000000000001',
      '0.0.0.2'         => '00000000000000000000000000000010',
      '0.0.0.3'         => '00000000000000000000000000000011',
    );

    foreach ($cases as $input => $expect) {
      $actual = PhutilIPAddress::newAddress($input)->toBits();
      $this->assertEqual(
        $expect,
        $actual,
        'PhutilIPv4Address['.$input.']->toBits()');
    }
  }

  public function testIPv6AddressToBits() {
    $cases = array(
      '::' =>
        '0000000000000000 0000000000000000'.
        '0000000000000000 0000000000000000'.
        '0000000000000000 0000000000000000'.
        '0000000000000000 0000000000000000',
      '::1' =>
        '0000000000000000 0000000000000000'.
        '0000000000000000 0000000000000000'.
        '0000000000000000 0000000000000000'.
        '0000000000000000 0000000000000001',
      '1::' =>
        '0000000000000001 0000000000000000'.
        '0000000000000000 0000000000000000'.
        '0000000000000000 0000000000000000'.
        '0000000000000000 0000000000000000',
      '::ffff:c000:0280' =>
        '0000000000000000 0000000000000000'.
        '0000000000000000 0000000000000000'.
        '0000000000000000 1111111111111111'.
        PhutilIPAddress::newAddress('192.0.2.128')->toBits(),
      '21DA:00D3:0000:2F3B:02AA:00FF:FE28:9C5A' =>
        '0010000111011010 0000000011010011'.
        '0000000000000000 0010111100111011'.
        '0000001010101010 0000000011111111'.
        '1111111000101000 1001110001011010',
      '2001:db8::1' =>
        '0010000000000001 0000110110111000'.
        '0000000000000000 0000000000000000'.
        '0000000000000000 0000000000000000'.
        '0000000000000000 0000000000000001',

    );

    foreach ($cases as $input => $expect) {
      // Remove any spaces, these are just to make the tests above easier to
      // read.
      $expect = str_replace(' ', '', $expect);

      $actual = PhutilIPAddress::newAddress($input)->toBits();
      $this->assertEqual(
        $expect,
        $actual,
        'PhutilIPv6Address['.$input.']->toBits()');
    }
  }

  public function testIPv6AddressToAddress() {
    $cases = array(
      '::' => '::',
      '::1' => '::1',
      '::01' => '::1',
      '0::0001' => '::1',
      '0000::0001' => '::1',
      '0000:0000::001' => '::1',

      '1::' => '1::',
      '01::' => '1::',
      '01::0' => '1::',
      '0001::0000' => '1::',

      '1:0::0:2' => '1::2',
      '1::0:2' => '1::2',
      '1:0::2' => '1::2',

      'CAFE::' => 'cafe::',
      '0000:aBe:0:0:1::' => '0:abe:0:0:1::',

      '1:0:0:0:2:0:0:0' => '1::2:0:0:0',
      '1:0:0:2:0:0:0:0' => '1:0:0:2::',
    );

    foreach ($cases as $input => $expect) {
      $actual = PhutilIPAddress::newAddress($input)->getAddress();
      $this->assertEqual(
        $expect,
        $actual,
        'PhutilIPv6Address['.$input.']->getAddress()');
    }
  }

  public function testValidIPv4CIDRBlocks() {
    $cases = array(
      // Valid block.
      '1.0.0.0/16' => true,

      // No nonsense.
      'duck' => false,
      '1/2/3' => false,
      '23/0.0.0.0' => false,
      '0.0.0.0/0.0.0.0' => false,

      // No leading zeroes.
      '1.0.0.0/4' => true,
      '1.0.0.0/04' => false,

      // No out-of-range masks.
      '1.0.0.0/32' => true,
      '1.0.0.0/33' => false,
    );

    foreach ($cases as $input => $expect) {
      $caught = null;
      try {
        PhutilCIDRBlock::newBlock($input);
      } catch (Exception $ex) {
        $caught = $ex;
      }

      $this->assertEqual(
        $expect,
        !($caught instanceof Exception),
        'PhutilCIDRBlock['.$input.']');
    }
  }

  public function testValidIPv6CIDRBlocks() {
    $cases = array(
      // Valid block.
      '::/16' => true,
      '::/128' => true,

      // No nonsense.
      '::/1/2' => false,
      '::/::' => false,
      '::' => false,

      // No leading zeroes.
      '::/01' => false,

      // No out-of-range masks.
      '::/129' => false,
    );

    foreach ($cases as $input => $expect) {
      $caught = null;
      try {
        PhutilCIDRBlock::newBlock($input);
      } catch (Exception $ex) {
        $caught = $ex;
      }

      $this->assertEqual(
        $expect,
        !($caught instanceof Exception),
        'PhutilCIDRBlock['.$input.']');
    }
  }

  public function testIPv4CIDRBlockContains() {
    $cases = array(
      '0.0.0.0/0' => array(
        '0.0.0.0' => true,
        '1.1.1.1' => true,
        '2.3.4.5' => true,
        '::' => false,
        '::1' => false,
        '::ffff:0:0' => false,
      ),
      '0.0.0.2/32' => array(
        '0.0.0.1' => false,
        '0.0.0.2' => true,
        '0.0.0.3' => false,
        '::' => false,
      ),
      '172.30.0.0/16' => array(
        '172.29.255.255' => false,
        '172.30.0.0' => true,
        '172.30.255.255' => true,
        '172.31.0.0' => false,
        '::' => false,
      ),
    );

    foreach ($cases as $input_block => $tests) {
      $block = PhutilCIDRBlock::newBlock($input_block);
      foreach ($tests as $input => $expect) {
        $this->assertEqual(
          $expect,
          $block->containsAddress($input),
          'PhutilCIDRBlock['.$input_block.']->containsAddress('.$input.')');
      }
    }
  }

  public function testIPv6CIDRBlockContains() {
    $cases = array(
      '::/0' => array(
        '1::' => true,
        '2::' => true,
        '127.0.0.1' => false,
      ),
      '::ffff:0:0/96' => array(
        '::ffff:0:0' => true,
        '::ffff:ffff:ffff' => true,
        '::fffe:0:0' => false,
        '127.0.0.1' => false,
      ),
    );

    foreach ($cases as $input_block => $tests) {
      $block = PhutilCIDRBlock::newBlock($input_block);
      foreach ($tests as $input => $expect) {
        $this->assertEqual(
          $expect,
          $block->containsAddress($input),
          'PhutilCIDRBlock['.$input_block.']->containsAddress('.$input.')');
      }
    }
  }

  public function testCIDRList() {
    $list = array(
      '172.30.0.0/16',
      '127.0.0.3/32',
    );

    $cases = array(
      '0.0.0.0' => false,
      '172.30.0.5' => true,
      '127.0.0.2' => false,
      '127.0.0.3' => true,
    );

    $list = PhutilCIDRList::newList($list);

    foreach ($cases as $input => $expect) {
      $this->assertEqual(
        $expect,
        $list->containsAddress($input),
        'PhutilCIDRList->containsAddress('.$input.')');
    }
  }


}
