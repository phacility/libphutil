<?php

final class PhutilXHPASTBinary {

  /**
   * The expected XHPAST version.
   *
   * This is the version that would be obtained with an up-to-date XHPAST
   * build. The //actual// XHPAST build version may vary.
   */
  const EXPECTED_VERSION = 'xhpast version 5.5.8/1g';

  /**
   * The XHPAST build version.
   *
   * Cache the result from @{method:getVersion} to prevent excessive calls to
   * @{function:execx}.
   */
  private static $version;

  /**
   * Builds XHPAST automatically.
   *
   * Attempts to build the XHPAST binary automatically. Throws a
   * @{class:CommandException} in the event of a failure.
   *
   * @return void
   */
  public static function build() {
    execx('%s', self::getBuildPath());
    self::$version = null;
  }

  /**
   * Returns human-readable instructions for building XHPAST.
   *
   * @return string
   */
  public static function getBuildInstructions() {
    return phutil_console_format(
      "%s:\n\n  \$ %s\n",
      pht(
        "Your version of '%s' is unbuilt or out of date. Run this ".
        "script to build it",
        'xhpast'),
      self::getBuildPath());
  }

  /**
   * Returns the path to the script used to build XHPAST.
   *
   * @return string
   */
  private static function getBuildPath() {
    $root = phutil_get_library_root('phutil');
    $make = $root.'/../scripts/build_xhpast.sh';
    return Filesystem::resolvePath($make);
  }

  /**
   * Constructs an @{class:ExecFuture} for XHPAST.
   *
   * @param  wild        Data to pass to the future.
   * @return ExecFuture
   */
  public static function getParserFuture($data) {
    if (!self::isAvailable()) {
      try {
        // Try to build XHPAST automatically. If we can't then just ask the
        // user to build it themselves.
        self::build();
      } catch (CommandException $ex) {
        throw new PhutilProxyException(self::getBuildInstructions(), $ex);
      }
    }
    $future = new ExecFuture('%s', self::getPath());
    $future->write($data);

    return $future;
  }

  /**
   * Returns the path to the XHPAST binary.
   *
   * @return string
   */
  public static function getPath() {
    if (phutil_is_windows()) {
      return dirname(__FILE__).'\\xhpast.exe';
    }
    return dirname(__FILE__).'/xhpast';
  }

  /**
   * Returns the XHPAST version.
   *
   * @return string
   */
  public static function getVersion() {
    if (self::$version === null) {
      $bin = self::getPath();

      if (Filesystem::pathExists($bin)) {
        list($err, $stdout) = exec_manual('%s --version', $bin);
        if (!$err) {
          self::$version = trim($stdout);
        }
      }
    }

    return self::$version;
  }

  /**
   * Checks if XHPAST is built and up-to-date.
   *
   * @return bool
   */
  public static function isAvailable() {
    return self::getVersion() == self::EXPECTED_VERSION;
  }

}
