<?php

final class PhutilPygmentizeBinaryAnalyzer
  extends PhutilBinaryAnalyzer {

  const BINARY = 'pygmentize';

  protected function newBinaryVersion() {
    list($err, $stdout) = exec_manual('pygmentize -V');

    if ($err) {
      return null;
    }

    return self::parsePygmentizeBinaryVersion($stdout);
  }

  public static function parsePygmentizeBinaryVersion($stdout) {
    // These look like:
    //   Pygments version 2.0.1, (c) 2006-2014 by Georg Brandl.

    $pattern = '(^Pygments version ([^,]+),)';
    $matches = null;
    if (preg_match($pattern, $stdout, $matches)) {
      return $matches[1];
    }

    return null;
  }

}
