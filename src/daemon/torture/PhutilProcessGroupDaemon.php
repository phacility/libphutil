<?php

/**
 * Daemon which spawns nonterminating, death-resistant children.
 */
final class PhutilProcessGroupDaemon extends PhutilTortureTestDaemon {

  protected function run() {
    $root = phutil_get_library_root('phutil');
    $root = dirname($root);

    execx('%s', $root.'/scripts/daemon/torture/resist-death.php');
  }

}
