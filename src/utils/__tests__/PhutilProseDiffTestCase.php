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
