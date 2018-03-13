<?php

final class PhutilSortVector
  extends Phobject {

  private $parts = array();

  public function addInt($value) {
    // We need to produce strings for each integer which sort naturally. This
    // requires some careful manipulation.

    if ($value === ~PHP_INT_MAX) {
      // For the minimum integer value (usually -9223372036854775808 on 64
      // bit systems) we just give it a special "A" prefix to make sure it
      // sorts first.
      $prefix = 'A';
    } else if ($value < 0) {
      // For all other negative values, we give them a "B" prefix, then
      // subtract the value from the maximum integer. This sorts values
      // in ascending order when printed.
      $prefix = 'B';
      $value = PHP_INT_MAX + $value;
    } else {
      // For zero and positive values, we give them a "C" prefix.
      $prefix = 'C';
    }

    $this->parts[] = sprintf('%s%020u', $prefix, $value);
    return $this;
  }

  public function addString($value) {
    if (strlen($value) && (strpos("\0", $value) !== false)) {
      throw new Exception(
        pht(
          'String components of a sort vector must not contain NULL bytes.'));
    }

    $this->parts[] = $value;
    return $this;
  }

  public function __toString() {
    return implode("\0", $this->parts);
  }

  /**
   * This allows you to sort a list of sort vectors using @{function:msortv}.
   */
  public function getSelf() {
    return $this;
  }

}
