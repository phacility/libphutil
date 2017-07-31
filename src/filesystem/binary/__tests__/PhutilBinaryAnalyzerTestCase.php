<?php

final class PhutilBinaryAnalyzerTestCase
  extends PhutilTestCase {

  public function testParseGitBinaryVersions() {
    $map = array(
      "git version 2.11.0\n" => '2.11.0',
      'definitely git 7.0' => null,
    );

    foreach ($map as $input => $expect) {
      $actual = PhutilGitBinaryAnalyzer::parseGitBinaryVersion($input);
      $this->assertEqual($expect, $actual, $input);
    }
  }

  public function getParseMercurialBinaryVersions() {
    $map = array(
      "Mercurial Distributed SCM (version 3.5.2+20151001)\n"
        => '3.5.2',
      'This Is Mercurial 22.0' => null,
    );

    foreach ($map as $input => $expect) {
      $actual =
        PhutilMercurialBinaryAnalyzer::parseMercurialBinaryVersion(
          $input);
      $this->assertEqual($expect, $actual, $input);
    }
  }

  public function testParseSubversionBinaryVersions() {
    $map = array(
      "1.7.20\n" => '1.7.20',
    );

    foreach ($map as $input => $expect) {
      $actual =
        PhutilSubversionBinaryAnalyzer::parseSubversionBinaryVersion(
          $input);
      $this->assertEqual($expect, $actual, $input);
    }
  }

  public function testParseDiffBinaryVersions() {
    $diff_version_281 = <<<EOTEXT
diff (GNU diffutils) 2.8.1
Copyright (C) 2002 Free Software Foundation, Inc.

This program comes with NO WARRANTY, to the extent permitted by law.
You may redistribute copies of this program
under the terms of the GNU General Public License.
For more information about these matters, see the file named COPYING.

Written by Paul Eggert, Mike Haertel, David Hayes,
Richard Stallman, and Len Tower.
EOTEXT;

    $map = array(
      $diff_version_281 => '2.8.1',
      'diff version 1.2.3' => null,
    );

    foreach ($map as $input => $expect) {
      $actual = PhutilDiffBinaryAnalyzer::parseDiffBinaryVersion($input);
      $this->assertEqual($expect, $actual, $input);
    }
  }

  public function testParsePygmentizeBinaryVersions() {
    $map = array(
      "Pygments version 2.0.1, (c) 2006-2014 by Georg Brandl.\n"
        => '2.0.1',
      'pygments 3.4' => null,
    );

    foreach ($map as $input => $expect) {
      $actual =
        PhutilPygmentizeBinaryAnalyzer::parsePygmentizeBinaryVersion(
          $input);
      $this->assertEqual($expect, $actual, $input);
    }
  }

  public function testMercurialFilesCommandVersions() {
    $cases = array(
      PhutilMercurialBinaryAnalyzer::CAPABILITY_FILES => array(
        '2.6.2' => false,
        '2.9' => false,
        '3.1' => false,
        '3.2' => true,
        '3.3' => true,
        '3.5.2' => true,
      ),
      PhutilMercurialBinaryAnalyzer::CAPABILITY_INJECTION => array(
        '2.0' => true,
        '3.2.3' => true,
        '3.2.4' => false,
      ),
    );

    foreach ($cases as $capability => $map) {
      foreach ($map as $input => $expect) {
        $actual = PhutilMercurialBinaryAnalyzer::versionHasCapability(
          $input,
          $capability);
        $this->assertEqual(
          $expect,
          $actual,
          pht('%s on %s', $capability, $input));
      }
    }

  }

}
