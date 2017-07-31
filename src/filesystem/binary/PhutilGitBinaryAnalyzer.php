<?php

final class PhutilGitBinaryAnalyzer
  extends PhutilBinaryAnalyzer {

  const BINARY = 'git';

  protected function newBinaryVersion() {
    list($err, $stdout) = exec_manual('git --version');

    if ($err) {
      return null;
    }

    return self::parseGitBinaryVersion($stdout);
  }

  public static function parseGitBinaryVersion($stdout) {
    if (preg_match('/^git version /', $stdout)) {
      $version = substr($stdout, strlen('git version '));
      $version = trim($version);
      return $version;
    }

    return null;
  }

}
