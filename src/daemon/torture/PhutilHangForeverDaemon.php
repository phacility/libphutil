<?php

/**
 * Daemon which hangs immediately.
 */
final class PhutilHangForeverDaemon extends PhutilTortureTestDaemon {

  protected function run() {
    while (true) {
      sleep(60);
    }
  }

}
