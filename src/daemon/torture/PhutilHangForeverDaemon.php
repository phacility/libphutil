<?php

/**
 * Daemon which hangs immediately.
 */
final class PhutilHangForeverDaemon extends PhutilTortureTestDaemon {

  public function run() {
    while (true) {
      sleep(60);
    }
  }

}
