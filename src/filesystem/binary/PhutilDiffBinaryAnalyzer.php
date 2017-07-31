<?php

final class PhutilDiffBinaryAnalyzer
  extends PhutilBinaryAnalyzer {

  const BINARY = 'diff';

  protected function newBinaryVersion() {
    list($err, $stdout) = exec_manual('diff --version');

    if ($err) {
      return null;
    }

    return self::parseDiffBinaryVersion($stdout);
  }

  public static function parseDiffBinaryVersion($stdout) {
    $prefix = 'diff (GNU diffutils) ';

    if (preg_match('(^'.preg_quote($prefix).')', $stdout)) {
      $lines = phutil_split_lines($stdout, false);
      $line = head($lines);
      $version = substr($line, strlen($prefix));
      return $version;
    }

    return null;
  }

}
