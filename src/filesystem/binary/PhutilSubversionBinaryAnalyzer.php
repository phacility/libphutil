<?php

final class PhutilSubversionBinaryAnalyzer
  extends PhutilBinaryAnalyzer {

  const BINARY = 'svn';

  protected function newBinaryVersion() {
    list($err, $stdout) = exec_manual('svn --version --quiet');

    if ($err) {
      return null;
    }

    return self::parseSubversionBinaryVersion($stdout);
  }

  public static function parseSubversionBinaryVersion($stdout) {
    return trim($stdout);
  }

}
