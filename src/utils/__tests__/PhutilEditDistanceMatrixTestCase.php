<?php

final class PhutilEditDistanceMatrixTestCase extends PhutilTestCase {

  public function testEditDistance() {
    // Empty inputs.
    $this->assertDistance(0, '', '');
    $this->assertDistance(27, '', 'xxx', 9);
    $this->assertDistance(27, 'xxx', '', 1, 9);

    // Both inputs identical.
    $this->assertDistance(0, 'x', 'x');
    $this->assertDistance(0, 'xyzabc', 'xyzabc');

    // Simple edits.
    $this->assertDistance(1, 'cat', 'car');
    $this->assertDistance(1, 'cat', 'cut');
    $this->assertDistance(1, 'cat', 'bat');
    $this->assertDistance(2, 'cat', 'bar');
    $this->assertDistance(3, 'cat', 'dog');

    // Inserts.
    $this->assertDistance(1, 'cat', 'cats');
    $this->assertDistance(1, 'cat', 'cast');
    $this->assertDistance(1, 'cat', 'xcat');
    $this->assertDistance(1, 'cat', 'cxat');

    // Deletes.
    $this->assertDistance(1, 'cat', 'ca');
    $this->assertDistance(1, 'cat', 'ct');
    $this->assertDistance(1, 'cat', 'at');

    // Replacements.
    $this->assertDistance(1, 'xxxxx', 'xxxxy');
    $this->assertDistance(1, 'xxxxx', 'xxyxx');
    $this->assertDistance(1, 'yxxxx', 'xxxxx');

    // Costs.
    $this->assertDistance(27, 'x', 'xxxx', 9);
    $this->assertDistance(27, 'xxxx', 'x', 1, 9);
    $this->assertDistance(27, 'xxxxx', 'xyyyx', 5, 5, 9);

    // Misc.
    $this->assertDistance(
      13,
      'The quick brown fox jumped over the lazy dog!',
      //   dddddd          r            ii         i iii
      'The brown fox pumped over those lazy dogs!~~~');
  }

  public function testDamerauEditDistance() {

    // Simple adjacent transpositions.
    $this->assertDistance(1, 'abcd', 'abdc', 3, 3, 3, 1);
    $this->assertDistance(1, 'abcd', 'bacd', 3, 3, 3, 1);
    $this->assertDistance(2, 'abcd', 'badc', 3, 3, 3, 1);

    // Transpositions with other edits.
    $this->assertDistance(7, 'abcd', 'baaa', 3, 3, 3, 1);
    $this->assertDistance(7, 'abcd', 'babb', 3, 3, 3, 1);

    // Sequences of adjacent transpositions.
    $this->assertDistance(3, 'abcd', 'cbad', 3, 3, 3, 1);
    $this->assertDistance(5, 'abcd', 'dbca', 3, 3, 3, 1);

    // Misc.
    $this->assertDistance(
      11,
      'Cozy lummox gives smart squid who asks for job pen.',
      //        t     d     r      i    i i       ttt ii
      'Cozy lummxo give smarp squid, whom tasks for boj a pen.');
  }

  public function testEditString() {
    $this->assertEditString('', '', '');
    $this->assertEditString('iii', '', 'aaa');
    $this->assertEditString('ddd', 'aaa', '');

    $this->assertEditString('sss', 'aaa', 'aaa');
    $this->assertEditString(
      'xssisssisx',
      'Qz(ab)zQ',
      'Rz((ab))zR',
      1, 1, 1, null, 0.001);

    $this->assertEditString('xxs', 'cat', 'rot');

    $this->assertEditString(
      'xxsssxxsssixsxxxsssdssssssssxssxsixsissssddddsdxxsssss',
      'Cozy lummox gives smart squid who asks for job pen.',
      'Lazy hammock takes mart squad that basks in pen.');
  }

  public function testDamerauEditString() {
    $this->assertEditString('xxss', 'land', 'alnd');
    $this->assertEditString('ttss', 'land', 'alnd', 1, 1, 1, 1);
    $this->assertEditString('tsts', 'land', 'nald', 3, 3, 3, 1);
  }

  public function testEditMatrixMaximumLength() {
    // These tests are hitting the maximum length limit; the expected costs
    // and strings are degenerate.

    $matrix = id(new PhutilEditDistanceMatrix())
      ->setInsertCost(3)
      ->setDeleteCost(7)
      ->setMaximumLength(1)
      ->setSequences(array('X', 'a', 'a', 'Y'), array('Q', 'a', 'a', 'R'));

    $this->assertEqual(
      40,
      $matrix->getEditDistance());

    $this->assertEqual(
      'ddddiiii',
      $matrix->getEditString());

    $matrix = id(new PhutilEditDistanceMatrix())
      ->setInsertCost(3)
      ->setDeleteCost(7)
      ->setMaximumLength(1)
      ->setSequences(
        array('f', 'f', 'X', 'a', 'a', 'Y', 'g', 'g'),
        array('f', 'f', 'Q', 'a', 'a', 'R', 'g', 'g'));

    $this->assertEqual(
      40,
      $matrix->getEditDistance());

    $this->assertEqual(
      'ssddddiiiiss',
      $matrix->getEditString());
  }

  private function assertDistance(
    $expect,
    $x, $y,
    $ins = 1, $del = 1,
    $rep = 1, $trn = null,
    $alt = 0) {

    $matrix = $this->buildMatrix($x, $y, $ins, $del, $rep, $trn, $alt);
    $cost = $matrix->getEditDistance();

    $desc = array($ins, $del, $rep, ($trn === null ? '-' : $trn));
    $desc = implode(', ', $desc);

    $this->assertEqual(
      $expect,
      $cost,
      pht(
        "Edit distance of '%s' -> '%s' with costs (%s).",
        $x,
        $y,
        $desc));
  }

  private function assertEditString(
    $expect,
    $x, $y,
    $ins = 1, $del = 1,
    $rep = 1, $trn = null,
    $alt = 0) {

    $matrix = $this->buildMatrix($x, $y, $ins, $del, $rep, $trn, $alt);
    $matrix->setComputeString(true);

    $string = $matrix->getEditString();

    $desc = array($ins, $del, $rep);
    $desc[] = ($trn === null ? '-' : $trn);
    $desc[] = ($alt === 0 ? '-' : $alt);
    $desc = implode(', ', $desc);

    $this->assertEqual(
      $expect,
      $string,
      pht(
        "Edit string of '%s' -> '%s' with costs (%s).",
        $x,
        $y,
        $desc));
  }

  private function buildMatrix($x, $y, $ins, $del, $rep, $trn, $alt) {
    if (!strlen($x)) {
      $xv = array();
    } else {
      $xv = str_split($x);
    }

    if (!strlen($y)) {
      $yv = array();
    } else {
      $yv = str_split($y);
    }

    return id(new PhutilEditDistanceMatrix())
      ->setSequences($xv, $yv)
      ->setInsertCost($ins)
      ->setDeleteCost($del)
      ->setReplaceCost($rep)
      ->setTransposeCost($trn)
      ->setAlterCost($alt);
  }

}
