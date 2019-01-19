<?php

final class PhutilArgumentSpellingCorrector extends Phobject {

  private $editDistanceMatrix;
  private $maximumDistance;
  private $mode;

  const MODE_COMMANDS = 'commands';
  const MODE_FLAGS = 'flags';

  /**
   * Build a new corrector with parameters for correcting commands, like
   * fixing "dfif" into "diff" in "arc diff".
   *
   * @return PhutilArgumentSpellingCorrector Configured corrector.
   */
  public static function newCommandCorrector() {
    // When correcting argument spelling, we're relatively liberal about
    // selecting alternatives and allow multiple mistakes.
    $max_distance = 2;

    // Adjust to the scaled edit costs we use below, so "2" roughly means
    // "2 edits".
    $max_distance = $max_distance * 3;

    // These costs are somewhat made up, but the theory is that it is far more
    // likely you will mis-strike a key ("lans" for "land") or press two keys
    // out of order ("alnd" for "land") than omit keys or press extra keys.
    $matrix = id(new PhutilEditDistanceMatrix())
      ->setInsertCost(4)
      ->setDeleteCost(4)
      ->setReplaceCost(3)
      ->setTransposeCost(2);

    return id(new self())
      ->setEditDistanceMatrix($matrix)
      ->setMode(self::MODE_COMMANDS)
      ->setMaximumDistance($max_distance);
  }


  /**
   * Build a new corrector with parameters for correcting flags, like
   * fixing "--nolint" into "--no-lint".
   *
   * @return PhutilArgumentSpellingCorrector Configured corrector.
   */
  public static function newFlagCorrector() {
    // When correcting flag spelling, we're stricter than we are when
    // correcting command spelling: we allow only one inserted or deleted
    // character. It is mainly to handle cases like "--no-lint" versus
    // "--nolint" or "--reviewer" versus "--reviewers".
    $max_distance = 1;

    $matrix = id(new PhutilEditDistanceMatrix())
      ->setInsertCost(1)
      ->setDeleteCost(1)
      ->setReplaceCost(10);

    return id(new self())
      ->setEditDistanceMatrix($matrix)
      ->setMode(self::MODE_FLAGS)
      ->setMaximumDistance($max_distance);
  }

  public function setMode($mode) {
    $this->mode = $mode;
    return $this;
  }

  public function getMode() {
    return $this->mode;
  }

  public function setEditDistanceMatrix(PhutilEditDistanceMatrix $matrix) {
    $this->editDistanceMatrix = $matrix;
    return $this;
  }

  public function getEditDistanceMatrix() {
    return $this->editDistanceMatrix;
  }

  public function setMaximumDistance($maximum_distance) {
    $this->maximumDistance = $maximum_distance;
    return $this;
  }

  public function getMaximumDistance() {
    return $this->maximumDistance;
  }

  public function correctSpelling($input, array $options) {
    $matrix = $this->getEditDistanceMatrix();
    if (!$matrix) {
      throw new PhutilInvalidStateException('setEditDistanceMatrix');
    }

    $max_distance = $this->getMaximumDistance();
    if (!$max_distance) {
      throw new PhutilInvalidStateException('setMaximumDistance');
    }

    // If we're correcting commands, never correct an input which begins
    // with "-", since this is almost certainly intended to be a flag.
    if ($this->getMode() === self::MODE_COMMANDS) {
      if (preg_match('/^-/', $input)) {
        return array();
      }
    }

    $input = $this->normalizeString($input);
    foreach ($options as $key => $option) {
      $options[$key] = $this->normalizeString($option);
    }

    $distances = array();
    $inputv = phutil_utf8v($input);
    foreach ($options as $option) {
      $optionv = phutil_utf8v($option);
      $matrix->setSequences($optionv, $inputv);
      $distances[$option] = $matrix->getEditDistance();
    }

    asort($distances);
    $best = min($max_distance, head($distances));
    foreach ($distances as $option => $distance) {
      if ($distance > $best) {
        unset($distances[$option]);
      }
    }

    // Before filtering, check if we have multiple equidistant matches and
    // return them if we do. This prevents us from, e.g., matching "alnd" with
    // both "land" and "amend", then dropping "land" for being too short, and
    // incorrectly completing to "amend".
    if (count($distances) > 1) {
      return array_keys($distances);
    }

    foreach ($distances as $option => $distance) {
      if (phutil_utf8_strlen($option) < $distance) {
        unset($distances[$option]);
      }
    }

    return array_keys($distances);
  }

  private function normalizeString($string) {
    return phutil_utf8_strtolower($string);
  }

}
