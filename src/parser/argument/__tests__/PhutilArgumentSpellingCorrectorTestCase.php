<?php

final class PhutilArgumentSpellingCorrectorTestCase extends PhutilTestCase {

  public function testCommandCorrection() {
    $this->assertCommandCorrection(
      array('land'),
      'alnd',
      array('land', 'amend'));

    $this->assertCommandCorrection(
      array('branch'),
      'brnach',
      array('branch', 'browse'));

    $this->assertCommandCorrection(
      array(),
      'test',
      array('list', 'unit'));

    $this->assertCommandCorrection(
      array('list'),
      'lists',
      array('list'));

    $this->assertCommandCorrection(
      array('diff'),
      'dfif',
      array('diff'));

    $this->assertCommandCorrection(
      array('unit'),
      'uint',
      array('unit', 'lint', 'list'));

    $this->assertCommandCorrection(
      array('list', 'lint'),
      'nilt',
      array('unit', 'lint', 'list'));
  }

  private function assertCommandCorrection($expect, $input, $commands) {
    $result = PhutilArgumentSpellingCorrector::newCommandCorrector()
      ->correctSpelling($input, $commands);

    sort($result);
    sort($expect);

    $commands = implode(', ', $commands);

    $this->assertEqual(
      $expect,
      $result,
      pht('Correction of %s against: %s', $input, $commands));
  }

  public function testFlagCorrection() {
    $this->assertFlagCorrection(
      array('nolint'),
      'no-lint',
      array('nolint', 'nounit'));

    $this->assertFlagCorrection(
      array('reviewers'),
      'reviewer',
      array('reviewers', 'cc'));

    $this->assertFlagCorrection(
      array(),
      'onlint',
      array('nolint'));

    $this->assertFlagCorrection(
      array(),
      'nolind',
      array('nolint'));
  }

  private function assertFlagCorrection($expect, $input, $flags) {
    $result = PhutilArgumentSpellingCorrector::newFlagCorrector()
      ->correctSpelling($input, $flags);

    sort($result);
    sort($expect);

    $flags = implode(', ', $flags);

    $this->assertEqual(
      $expect,
      $result,
      pht('Correction of %s against: %s', $input, $flags));
  }

}
