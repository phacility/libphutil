<?php

final class PhutilCalendarRecurrenceRule
  extends PhutilCalendarRecurrenceSource {

  private $frequency;
  private $until;
  private $count;
  private $interval;
  private $bySecond;
  private $byMinute;
  private $byHour;
  private $byDay;
  private $byMonthDay;
  private $byYearDay;
  private $byWeekNumber;
  private $byMonth;
  private $bySetPosition;
  private $weekStart = 'MO';

  public function setFrequency($frequency) {
    $this->frequency = $frequency;
    return $this;
  }

  public function getFrequency() {
    return $this->frequency;
  }

  public function setUntil(PhutilCalendarDateTime $until) {
    $this->until = $until;
    return $this;
  }

  public function getUntil() {
    return $this->until;
  }

  public function setCount($count) {
    $this->count = $count;
    return $this;
  }

  public function getCount() {
    return $this->count;
  }

  public function setInterval($interval) {
    $this->interval = $interval;
    return $this;
  }

  public function getInterval() {
    return $this->interval;
  }

  public function setBySecond($by_second) {
    $this->bySecond = $by_second;
    return $this;
  }

  public function getBySecond() {
    return $this->bySecond;
  }

  public function setByMinute($by_minute) {
    $this->byMinute = $by_minute;
    return $this;
  }

  public function getByMinute() {
    return $this->byMinute;
  }

  public function setByHour($by_hour) {
    $this->byHour = $by_hour;
    return $this;
  }

  public function getByHour() {
    return $this->byHour;
  }

  public function setByDay($by_day) {
    $this->byDay = $by_day;
    return $this;
  }

  public function getByDay() {
    return $this->byDay;
  }

  public function setByMonthDay($by_month_day) {
    $this->byMonthDay = $by_month_day;
    return $this;
  }

  public function getByMonthDay() {
    return $this->byMonthDay;
  }

  public function setByYearDay($by_year_day) {
    $this->byYearDay = $by_year_day;
    return $this;
  }

  public function getByYearDay() {
    return $this->byYearDay;
  }

  public function setByMonth($by_month) {
    $this->byMonth = $by_month;
    return $this;
  }

  public function getByMonth() {
    return $this->byMonth;
  }

  public function setBySetPosition($by_set_position) {
    $this->bySetPosition = $by_set_position;
    return $this;
  }

  public function getBySetPosition() {
    return $this->bySetPosition;
  }

  public function setWeekStart($week_start) {
    $this->weekStart = $week_start;
    return $this;
  }

  public function getWeekStart() {
    return $this->weekStart;
  }

  public function getNextEvent($cursor) {
    throw new PhutilMethodNotImplementedException();
  }

}
