<?php

final class PhutilCalendarAbsoluteDateTime
  extends PhutilCalendarDateTime {

  private $year;
  private $month;
  private $day;
  private $hour = 0;
  private $minute = 0;
  private $second = 0;
  private $timezone;
  private $viewerTimezone;

  public function setYear($year) {
    $this->year = $year;
    return $this;
  }

  public function getYear() {
    return $this->year;
  }

  public function setMonth($month) {
    $this->month = $month;
    return $this;
  }

  public function getMonth() {
    return $this->month;
  }

  public function setDay($day) {
    $this->day = $day;
    return $this;
  }

  public function getDay() {
    return $this->day;
  }

  public function setHour($hour) {
    $this->hour = $hour;
    return $this;
  }

  public function getHour() {
    return $this->hour;
  }

  public function setMinute($minute) {
    $this->minute = $minute;
    return $this;
  }

  public function getMinute() {
    return $this->minute;
  }

  public function setSecond($second) {
    $this->second = $second;
    return $this;
  }

  public function getSecond() {
    return $this->second;
  }

  public function setTimezone($timezone) {
    $this->timezone = $timezone;
    return $this;
  }

  public function getTimezone() {
    return $this->timezone;
  }

  private function getEffectiveTimezone() {
    $zone = $this->getTimezone();
    if ($zone !== null) {
      return $zone;
    }

    $zone = $this->getViewerTimezone();
    if ($zone !== null) {
      return $zone;
    }

    throw new Exception(
      pht(
        'Datetime has no timezone or viewer timezone.'));
  }

  protected function newPHPDateTimeZone() {
    $zone = $this->getEffectiveTimezone();
    return new DateTimeZone($zone);
  }

  protected function newPHPDateTime() {
    $zone = $this->newPHPDateTimeZone();

    $y = $this->getYear();
    $m = $this->getMonth();
    $d = $this->getDay();

    $h = $this->getHour();
    $i = $this->getMinute();
    $s = $this->getSecond();

    $format = sprintf('%04d-%02d-%02d %02d:%02d:%02d', $y, $m, $d, $h, $i, $s);

    return new DateTime($format, $zone);
  }

}
