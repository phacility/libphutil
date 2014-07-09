<?php

/**
 * Daemon which fails immediately.
 */
final class PhutilFatalDaemon extends PhutilTortureTestDaemon {

  public function run() {
    exit(1);
  }

}
