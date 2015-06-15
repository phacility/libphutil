<?php

/**
 * Get information about the current execution environment.
 */
final class PhutilExecutionEnvironment extends Phobject {

  public static function getOSXVersion() {
    if (php_uname('s') != 'Darwin') {
      return null;
    }

    return php_uname('r');
  }

}
