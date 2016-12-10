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
      return clone $in;
    }

    return self::newFromString($in);
  }

  private static function newFromString($str) {
    if (!preg_match('(^[\d.:a-fA-F]+/[\d]+\z)', $str)) {
      throw new Exception(
        pht(
          'CIDR block "%s" is not formatted correctly. Expected an IP block '.
          'in CIDR notation, like "%s" or "%s".',
          $str,
          '172.30.0.0/16',
          '23:45:67:89::/24'));
    }

    list($ip, $mask) = explode('/', $str);

    $ip = PhutilIPAddress::newAddress($ip);

    if (preg_match('/^0\d/', $mask)) {
      throw new Exception(
        pht(
          'CIDR block "%s" is not formatted correctly. The IP block mask '.
          '("%s") must not have leading zeroes.',
          $str,
          $mask));
    }

    $max_bits = $ip->getBitCount();

    $bits = (int)$mask;
    if ($bits < 0 || $bits > $max_bits) {
      throw new Exception(
        pht(
          'CIDR block "%s" is not formatted correctly. The IP block mask '.
          '("%s") must mask between 0 and %s bits, inclusive.',
          $str,
          $mask,
          new PhutilNumber($max_bits)));
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

    // If the two addresses have different bit widths (IPv4 vs IPv6), this
    // CIDR block does not match the address.
    if ($this->ip->getBitCount() != $address->getBitCount()) {
      return false;
    }

    return (strncmp($block_bits, $address_bits, $this->bits) === 0);
  }

}
