<?php

final class PhutilProseDiffTestCase extends PhutilTestCase {

  public function testProseDiffsDistance() {
    $this->assertProseParts(
      '',
      '',
      array(),
      pht('Empty'));

    $this->assertProseParts(
      "xxx\nyyy",
      "xxx\nzzz\nyyy",
      array(
        "= xxx\n",
        "+ zzz\n",
        '= yyy',
      ),
      pht('Add Paragraph'));

    $this->assertProseParts(
      "xxx\nzzz\nyyy",
      "xxx\nyyy",
      array(
        "= xxx\n",
        "- zzz\n",
        '= yyy',
      ),
      pht('Remove Paragraph'));


    // Without smoothing, the alogorithm identifies that "shark" and "cat"
    // both contain the letter "a" and tries to express this as a very
    // fine-grained edit which replaces "sh" with "c" and then "rk" with "t".
    // This is technically correct, but it is much easier for human viewers to
    // parse if we smooth this into a single removal and a single addition.

    $this->assertProseParts(
      'They say the shark has nine lives.',
      'They say the cat has nine lives.',
      array(
        '= They say the ',
        '- shark',
        '+ cat',
        '=  has nine lives.',
      ),
      pht('"Shark/cat" word edit smoothenss.'));

    $this->assertProseParts(
      'Rising quickly, she says',
      'Rising quickly, she remarks:',
      array(
        '= Rising quickly, she ',
        '- says',
        '+ remarks:',
      ),
      pht('"Says/remarks" word edit smoothenss.'));

  }

  private function assertProseParts($old, $new, array $expect_parts, $label) {
    $engine = new PhutilProseDifferenceEngine();
    $diff = $engine->getDiff($old, $new);

    $parts = $diff->getParts();

    $actual = array();
    foreach ($parts as $part) {
      $actual[] = $part['type'].' '.$part['text'];
    }

    $this->assertEqual($expect_parts, $actual, $label);
  }


}
