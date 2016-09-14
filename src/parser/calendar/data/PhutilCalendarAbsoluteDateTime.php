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

  public static function newFromISO8601($value, $timezone = 'UTC') {
    $pattern =
      '/^'.
      '(?P<y>\d{4})(?P<m>\d{2})(?P<d>\d{2})'.
      '(?:'.
        'T(?P<h>\d{2})(?P<i>\d{2})(?P<s>\d{2})(?<z>Z)?'.
      ')?'.
      '\z/';

    $matches = null;
    $ok = preg_match($pattern, $value, $matches);
    if (!$ok) {
      throw new Exception(
        pht(
          'Expected ISO8601 datetime in the format "19990105T112233Z", '.
          'found "%s".',
          $value));
    }

    if (isset($matches['z'])) {
      if ($timezone != 'UTC') {
        throw new Exception(
          pht(
            'ISO8601 date ends in "Z" indicating UTC, but a timezone other '.
            'than UTC ("%s") was specified.',
            $timezone));
      }
    }

    $datetime = id(new self())
      ->setYear((int)$matches['y'])
      ->setMonth((int)$matches['m'])
      ->setDay((int)$matches['d'])
      ->setTimezone($timezone);

    if (isset($matches['h'])) {
      $datetime
        ->setHour((int)$matches['h'])
        ->setMinute((int)$matches['i'])
        ->setSecond((int)$matches['s']);
    } else {
      $datetime
        ->setIsAllDay(true);
    }

    return $datetime;
  }

  public static function newFromEpoch($epoch, $timezone = 'UTC') {
    $date = new DateTime('@'.$epoch);

    $zone = new DateTimeZone($timezone);
    $date->setTimezone($zone);

    return id(new self())
      ->setYear((int)$date->format('Y'))
      ->setMonth((int)$date->format('m'))
      ->setDay((int)$date->format('d'))
      ->setHour((int)$date->format('H'))
      ->setMinute((int)$date->format('i'))
      ->setSecond((int)$date->format('s'))
      ->setTimezone($timezone);
  }

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
