<?php

/**
 * Daemon which makes a lot of service calls.
 *
 * @group testcase
 */
final class PhutilExcessiveServiceCallsDaemon extends PhutilTortureTestDaemon {

  public function run() {
    while (true) {
      execx('true');
      $this->stillWorking();
    }
  }

}
