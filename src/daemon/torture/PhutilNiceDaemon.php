<?php

/**
 * Daemon which behaves properly.
 */
final class PhutilNiceDaemon extends PhutilTortureTestDaemon {

  protected function run() {
    while (true) {
      $this->log(date('r'));
      $this->stillWorking();
      sleep(1);
    }
  }

}
