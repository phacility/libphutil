<?php

/**
 * CIDR notation IP block, like "172.30.0.0/16".
 *
 * See @{class:PhutilCIDRList} for discussion.
 */
final class PhutilCIDRBlock extends Phobject {

  private $ip;
  private $bits;

  private function __construct() {
    // <private>
  }

  public static function newBlock($in) {
    if ($in instanceof PhutilCIDRBlock) {
      return $in;
    }

    return self::newFromString($in);
  }

  private static function newFromString($str) {
    if (!preg_match('(^[\d.]+/[\d]+\z)', $str)) {
      throw new Exception(
        pht(
          'CIDR block "%s" is not formatted correctly. Expected an IP block '.
          'in CIDR notation, like "%s".',
          $str,
          '172.30.0.0/16'));
    }

    list($ip, $mask) = explode('/', $str);

    $ip = PhutilIPAddress::newAddress($ip);

    // These rules are for IPv4; some day we'll handle IPv6 too.

    if (preg_match('/^0\d/', $mask)) {
      throw new Exception(
        pht(
          'CIDR block "%s" is not formatted correctly. The IP block mask '.
          '("%s") must not have leading zeroes.',
          $str,
          $mask));
    }

    $bits = (int)$mask;
    if ($bits < 0 || $bits > 32) {
      throw new Exception(
        pht(
          'CIDR block "%s" is not formatted correctly. The IP block mask '.
          '("%s") must mask between 0 and 32 bits, inclusive.',
          $str,
          $mask));
    }

    $obj = new PhutilCIDRBlock();
    $obj->ip = $ip;
    $obj->bits = $bits;

    return $obj;
  }

  public function containsAddress($address) {
    $address = PhutilIPAddress::newAddress($address);

    $block_bits = $this->ip->toBits();
    $address_bits = $address->toBits();

    return (strncmp($block_bits, $address_bits, $this->bits) === 0);
  }

}
