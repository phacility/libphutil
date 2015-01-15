<?php

/**
 * Daemon which fails immediately.
 */
final class PhutilFatalDaemon extends PhutilTortureTestDaemon {

  protected function run() {
    exit(1);
  }

}
