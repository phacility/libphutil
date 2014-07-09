<?php

/**
 * Test cases for @{class:PhutilArray} subclasses.
 */
final class PhutilArrayTestCase extends PhutilTestCase {

  public function testPhutilArrayWithDefaultValue() {
    $a = new PhutilArrayWithDefaultValue();

    $this->assertEqual(0, $a[99]);
    $a[99] = 1;
    $this->assertEqual(1, $a[99]);

    $a->setDefaultValue('default');
    $this->assertEqual('default', $a['key']);

    $this->assertEqual(
      array(
        99      => 1,
        'key'   => 'default',
      ),
      $a->toArray());

    $init = array(
      'apple' => 'red',
    );

    $b = new PhutilArrayWithDefaultValue($init);
    $this->assertEqual($init, $b->toArray());

    $fruits = array(
      'apple',
      'cherry',
      'banana',
      'cherry',
      'cherry',
      'apple',
      'banana',
      'plum',
      'cherry',
      'cherry',
    );

    $counts = new PhutilArrayWithDefaultValue();
    foreach ($fruits as $fruit) {
      $counts[$fruit] += 1;
    }
    $this->assertEqual(
      array(
        'apple' => 2,
        'cherry' => 5,
        'banana' => 2,
        'plum' => 1,
      ),
      $counts->toArray());

    $masks = array(
      1,
      2,
      4,
    );

    $bitmask = new PhutilArrayWithDefaultValue();
    foreach ($masks as $mask) {
      $bitmask['value'] |= $mask;
    }

    $this->assertEqual(7, $bitmask['value']);
  }

}
