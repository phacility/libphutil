<?php

/**
 * Daemon which fails immediately.
 *
 * @group testcase
 */
final class PhutilFatalDaemon extends PhutilTortureTestDaemon {

  public function run() {
    exit(1);
  }

}
