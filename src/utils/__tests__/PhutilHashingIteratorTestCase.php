<?php

final class PhutilHashingIteratorTestCase extends PhutilTestCase {

  public function testHashingIterator() {
    $path = dirname(__FILE__).'/hashingiterator/mostlyprime.txt';

    $stream = fopen($path, 'rb');
    $algorithm = 'sha256';

    $stream_iterator = new PhutilStreamIterator($stream);
    $hashing_iterator = id(new PhutilHashingIterator($stream_iterator))
      ->setAlgorithm($algorithm);

    $rope = new PhutilRope();
    foreach ($hashing_iterator as $block) {
      $rope->append($block);
    }

    $expect_data = Filesystem::readFile($path);
    $actual_data = $rope->getAsString();

    $this->assertEqual(
      $expect_data,
      $actual_data,
      pht('Data should be read correctly.'));

    $expect_hash =
      'd50af03db6c8b63084664f352d12bffb8f58022bdd67e3aba21f01e11c3b8939';

    $single_hash = hash($algorithm, $expect_data, $raw_output = false);
    $actual_hash = $hashing_iterator->getHash();

    $this->assertEqual(
      $expect_hash,
      $single_hash,
      pht('Expected hash should match freshly computed hash.'));

    $this->assertEqual(
      $expect_hash,
      $actual_hash,
      pht('Expected hash should also match iterator actual hash.'));
  }

}
