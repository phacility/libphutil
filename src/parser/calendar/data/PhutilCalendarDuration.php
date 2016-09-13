<?php

final class PhutilCalendarDuration extends Phobject {

  private $isNegative = false;
  private $days = 0;
  private $weeks = 0;
  private $hours = 0;
  private $minutes = 0;
  private $seconds = 0;

  public function setIsNegative($is_negative) {
    $this->isNegative = $is_negative;
    return $this;
  }

  public function getIsNegative() {
    return $this->isNegative;
  }

  public function setDays($days) {
    $this->days = $days;
    return $this;
  }

  public function getDays() {
    return $this->days;
  }

  public function setWeeks($weeks) {
    $this->weeks = $weeks;
    return $this;
  }

  public function getWeeks() {
    return $this->weeks;
  }

  public function setHours($hours) {
    $this->hours = $hours;
    return $this;
  }

  public function getHours() {
    return $this->hours;
  }

  public function setMinutes($minutes) {
    $this->minutes = $minutes;
    return $this;
  }

  public function getMinutes() {
    return $this->minutes;
  }

  public function setSeconds($seconds) {
    $this->seconds = $seconds;
    return $this;
  }

  public function getSeconds() {
    return $this->seconds;
  }

}
