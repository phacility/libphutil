<?php

/**
 * List of CIDR notation IP blocks, like "172.30.0.0/16".
 *
 * This class is primarily useful for managing IP whitelists or blacklists.
 * For example, you can check if an address is on a subnet like this:
 *
 *   $whitelist = PhutilCIDRList::newList(array('172.30.0.0/16'));
 *   $ok = $whitelist->containsAddrsss('172.30.0.1');
 */
final class PhutilCIDRList extends Phobject {

  private $blocks;

  private function __construct() {
    // <private>
  }

  public static function newList(array $blocks) {
    foreach ($blocks as $key => $block) {
      $blocks[$key] = PhutilCIDRBlock::newBlock($block);
    }

    $obj = new PhutilCIDRList();
    $obj->blocks = $blocks;
    return $obj;
  }

  public function containsAddress($address) {
    foreach ($this->blocks as $block) {
      if ($block->containsAddress($address)) {
        return true;
      }
    }

    return false;
  }

}
