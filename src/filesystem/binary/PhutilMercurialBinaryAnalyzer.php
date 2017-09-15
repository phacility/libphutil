<?php

final class PhutilMercurialBinaryAnalyzer
  extends PhutilBinaryAnalyzer {

  const BINARY = 'hg';

  const CAPABILITY_FILES = 'files';
  const CAPABILITY_INJECTION = 'injection';

  protected function newBinaryVersion() {
    $future = id(new ExecFuture('hg --version --quiet'))
      ->setEnv(
        array(
          'HGPLAIN' => 1,
        ));

    list($err, $stdout) = $future->resolve();

    if ($err) {
      return null;
    }

    return self::parseMercurialBinaryVersion($stdout);
  }

  public static function parseMercurialBinaryVersion($stdout) {
    // NOTE: At least on OSX, recent versions of Mercurial report this
    // string in this format:
    //
    //   Mercurial Distributed SCM (version 3.1.1+20140916)

    $matches = null;
    $pattern = '/^Mercurial Distributed SCM \(version ([\d.]+)/m';
    if (preg_match($pattern, $stdout, $matches)) {
      return $matches[1];
    }

    return null;
  }

  /**
   * The `locate` command is deprecated as of Mercurial 3.2, to be replaced
   * with `files` command, which supports most of the same arguments. This
   * determines whether the new `files` command should be used instead of
   * the `locate` command.
   *
   * @return boolean  True if the version of Mercurial is new enough to support
   *   the `files` command, or false if otherwise.
   */
  public function isMercurialFilesCommandAvailable() {
    return self::versionHasCapability(
      $this->requireBinaryVersion(),
      self::CAPABILITY_FILES);
  }

  public function isMercurialVulnerableToInjection() {
    return self::versionHasCapability(
      $this->requireBinaryVersion(),
      self::CAPABILITY_INJECTION);
  }


  public static function versionHasCapability(
    $mercurial_version,
    $capability) {

    switch ($capability) {
      case self::CAPABILITY_FILES:
        return version_compare($mercurial_version, '3.2', '>=');
      case self::CAPABILITY_INJECTION:
        return version_compare($mercurial_version, '3.2.4', '<');
      default:
        throw new Exception(
          pht(
            'Unknown Mercurial capability "%s".',
            $capability));
    }

  }


}
