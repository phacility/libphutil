<?php

/**
 * Compute the phase of the terran moon for a given epoch.
 *
 *   $moon = new PhutilLunarPhase(time());
 *   $moon->isFull();
 */
final class PhutilLunarPhase extends Phobject {

  private $epoch;

  public function __construct($epoch) {
    $this->epoch = $epoch;
  }

  private function getPhase() {
    // (Aug 11, 1999) A new moon.
    $new_moon_epoch = 934354800;

    // Number of seconds in the lunar phase.
    $phase_length = 2551442.8768992;

    return fmod($this->epoch - $new_moon_epoch, $phase_length) / $phase_length;
  }

  public function isFull() {
    return abs($this->getPhase() - 0.5) < 0.02;
  }

  public function isNew() {
    return $this->getPhase() < 0.02 || $this->getPhase() > 0.98;
  }

  public function isWaxing() {
    return $this->getPhase() < 0.5;
  }

  public function isWaning() {
    return $this->getPhase() > 0.5;
  }

}
