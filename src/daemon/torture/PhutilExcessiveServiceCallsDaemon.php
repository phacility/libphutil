<?php

/**
 * Daemon which makes a lot of service calls.
 */
final class PhutilExcessiveServiceCallsDaemon extends PhutilTortureTestDaemon {

  protected function run() {
    while (true) {
      execx('true');
      $this->stillWorking();
    }
  }

}
