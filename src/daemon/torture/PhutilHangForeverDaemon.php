<?php

/**
 * Daemon which hangs immediately.
 *
 * @group testcase
 */
final class PhutilHangForeverDaemon extends PhutilTortureTestDaemon {

  public function run() {
    while (true) {
      sleep(60);
    }
  }

}
