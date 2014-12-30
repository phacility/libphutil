<?php

final class PhutilIPAddressTestCase extends PhutilTestCase {

  public function testValidIPAddresses() {
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
        'PhutilIPAddress['.$input.']');
    }
  }

  public function testIPAddressToBits() {
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
        'PhutilIPAddress['.$input.']->toBits()');
    }
  }

  public function testValidCIDRBlocks() {
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

  public function testCIDRBlockContains() {
    $cases = array(
      '0.0.0.0/0' => array(
        '0.0.0.0' => true,
        '1.1.1.1' => true,
        '2.3.4.5' => true,
      ),
      '0.0.0.2/32' => array(
        '0.0.0.1' => false,
        '0.0.0.2' => true,
        '0.0.0.3' => false,
      ),
      '172.30.0.0/16' => array(
        '172.29.255.255' => false,
        '172.30.0.0' => true,
        '172.30.255.255' => true,
        '172.31.0.0' => false,
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
