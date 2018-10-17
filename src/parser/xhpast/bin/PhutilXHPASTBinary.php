<?php

final class PhutilXHPASTBinary extends Phobject {

  /**
   * The expected XHPAST version.
   *
   * This is the version that would be obtained with an up-to-date XHPAST
   * build. The //actual// XHPAST build version may vary.
   */
  const EXPECTED_VERSION = '7.1.3';

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
   * Attempts to build the XHPAST binary automatically.
   *
   * @return void
   */
  public static function build() {
    if (Filesystem::binaryExists('gmake')) {
      $command = 'gmake';
    } else {
      $command = 'make';
    }

    $root = phutil_get_library_root('phutil');
    $path = Filesystem::resolvePath($root.'/../support/xhpast');

    // Run the build.
    execx(
      '%s -C %s %Ls',
      $command,
      $path,
      array('SKIP_PARSER=1', 'SKIP_SCANNER=1', 'clean', 'all', 'install'));

    self::$version = null;

    // Test the binary.
    if (!self::isAvailable()) {
      throw new Exception(pht('%s is broken.', 'xhpast'));
    }
  }

  /**
   * Returns human-readable instructions for building XHPAST.
   *
   * @return string
   */
  public static function getBuildInstructions() {
    $root = phutil_get_library_root('phutil');
    $make = Filesystem::resolvePath($root.'/../scripts/build_xhpast.php');

    return phutil_console_format(
      "%s:\n\n  \$ %s\n",
      pht(
        "Your version of '%s' is unbuilt or out of date. Run this ".
        "script to build it.",
        'xhpast'),
      $make);
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
