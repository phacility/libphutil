<?php

final class PhutilCalendarRecurrenceRule
  extends PhutilCalendarRecurrenceSource {

  private $startDateTime;
  private $frequency;
  private $frequencyScale;
  private $interval = 1;
  private $bySecond = array();
  private $byMinute = array();
  private $byHour = array();
  private $byDay = array();
  private $byMonthDay = array();
  private $byYearDay = array();
  private $byWeekNumber = array();
  private $byMonth = array();
  private $bySetPosition = array();
  private $weekStart = self::WEEKDAY_MONDAY;

  private $cursorSecond;
  private $cursorMinute;
  private $cursorHour;
  private $cursorWeek;
  private $cursorDay;
  private $cursorMonth;
  private $cursorYear;

  private $setSeconds;
  private $setMinutes;
  private $setHours;
  private $setDays;
  private $setMonths;
  private $setYears;

  private $stateSecond;
  private $stateMinute;
  private $stateHour;
  private $stateDay;
  private $stateMonth;
  private $stateYear;

  private $initialMonth;
  private $initialYear;
  private $baseYear;
  private $isAllDay;

  const FREQUENCY_SECONDLY = 'SECONDLY';
  const FREQUENCY_MINUTELY = 'MINUTELY';
  const FREQUENCY_HOURLY = 'HOURLY';
  const FREQUENCY_DAILY = 'DAILY';
  const FREQUENCY_WEEKLY = 'WEEKLY';
  const FREQUENCY_MONTHLY = 'MONTHLY';
  const FREQUENCY_YEARLY = 'YEARLY';

  const SCALE_SECONDLY = 1;
  const SCALE_MINUTELY = 2;
  const SCALE_HOURLY = 3;
  const SCALE_DAILY = 4;
  const SCALE_WEEKLY = 5;
  const SCALE_MONTHLY = 6;
  const SCALE_YEARLY = 7;

  const WEEKDAY_SUNDAY = 'SU';
  const WEEKDAY_MONDAY = 'MO';
  const WEEKDAY_TUESDAY = 'TU';
  const WEEKDAY_WEDNESDAY = 'WE';
  const WEEKDAY_THURSDAY = 'TH';
  const WEEKDAY_FRIDAY = 'FR';
  const WEEKDAY_SATURDAY = 'SA';

  const WEEKINDEX_SUNDAY = 0;
  const WEEKINDEX_MONDAY = 1;
  const WEEKINDEX_TUESDAY = 2;
  const WEEKINDEX_WEDNESDAY = 3;
  const WEEKINDEX_THURSDAY = 4;
  const WEEKINDEX_FRIDAY = 5;
  const WEEKINDEX_SATURDAY = 6;

  private static function getAllWeekdayConstants() {
    return array_keys(self::getWeekdayIndexMap());
  }

  private static function getWeekdayIndexMap() {
    static $map = array(
      self::WEEKDAY_SUNDAY => self::WEEKINDEX_SUNDAY,
      self::WEEKDAY_MONDAY => self::WEEKINDEX_MONDAY,
      self::WEEKDAY_TUESDAY => self::WEEKINDEX_TUESDAY,
      self::WEEKDAY_WEDNESDAY => self::WEEKINDEX_WEDNESDAY,
      self::WEEKDAY_THURSDAY => self::WEEKINDEX_THURSDAY,
      self::WEEKDAY_FRIDAY => self::WEEKINDEX_FRIDAY,
      self::WEEKDAY_SATURDAY => self::WEEKINDEX_SATURDAY,
    );

    return $map;
  }

  private static function getWeekdayIndex($weekday) {
    $map = self::getWeekdayIndexMap();
    if (!isset($map[$weekday])) {
      $constants = array_keys($map);
      throw new Exception(
        pht(
          'Weekday "%s" is not a valid weekday constant. Valid constants '.
          'are: %s.',
          $weekday,
          implode(', ', $constants)));
    }

    return $map[$weekday];
  }

  public function setStartDateTime(PhutilCalendarDateTime $start) {
    $this->startDateTime = $start;
    return $this;
  }

  public function getStartDateTime() {
    return $this->startDateTime;
  }

  public function setFrequency($frequency) {
    static $map = array(
      self::FREQUENCY_SECONDLY => self::SCALE_SECONDLY,
      self::FREQUENCY_MINUTELY => self::SCALE_MINUTELY,
      self::FREQUENCY_HOURLY => self::SCALE_HOURLY,
      self::FREQUENCY_DAILY => self::SCALE_DAILY,
      self::FREQUENCY_WEEKLY => self::SCALE_WEEKLY,
      self::FREQUENCY_MONTHLY => self::SCALE_MONTHLY,
      self::FREQUENCY_YEARLY => self::SCALE_YEARLY,
    );

    if (empty($map[$frequency])) {
      throw new Exception(
        pht(
          'RRULE FREQ "%s" is invalid. Valid frequencies are: %s.',
          $frequency,
          implode(', ', array_keys($map))));
    }

    $this->frequency = $frequency;
    $this->frequencyScale = $map[$frequency];

    return $this;
  }

  public function getFrequency() {
    return $this->frequency;
  }

  public function getFrequencyScale() {
    return $this->frequencyScale;
  }

  public function setInterval($interval) {
    if (!is_int($interval)) {
      throw new Exception(
        pht(
          'RRULE INTERVAL "%s" is invalid: interval must be an integer.',
          $interval));
    }

    if ($interval < 1) {
      throw new Exception(
        pht(
          'RRULE INTERVAL "%s" is invalid: interval must be 1 or more.',
          $interval));
    }

    $this->interval = $interval;
    return $this;
  }

  public function getInterval() {
    return $this->interval;
  }

  public function setBySecond(array $by_second) {
    $this->assertByRange('BYSECOND', $by_second, 0, 60);
    $this->bySecond = array_fuse($by_second);
    return $this;
  }

  public function getBySecond() {
    return $this->bySecond;
  }

  public function setByMinute(array $by_minute) {
    $this->assertByRange('BYMINUTE', $by_minute, 0, 59);
    $this->byMinute = array_fuse($by_minute);
    return $this;
  }

  public function getByMinute() {
    return $this->byMinute;
  }

  public function setByHour(array $by_hour) {
    $this->assertByRange('BYHOUR', $by_hour, 0, 23);
    $this->byHour = array_fuse($by_hour);
    return $this;
  }

  public function getByHour() {
    return $this->byHour;
  }

  public function setByDay(array $by_day) {
    $constants = self::getAllWeekdayConstants();
    $constants = implode('|', $constants);

    $pattern = '/^(?:[+-]?([1-9]\d?))?('.$constants.')\z/';
    foreach ($by_day as $value) {
      $matches = null;
      if (!preg_match($pattern, $value, $matches)) {
        throw new Exception(
          pht(
            'RRULE BYDAY value "%s" is invalid: rule part must be in the '.
            'expected form (like "MO", "-3TH", or "+2SU").',
            $value));
      }

      // The maximum allowed value is 53, which corresponds to "the 53rd
      // Monday every year" or similar when evaluated against a YEARLY rule.

      $maximum = 53;
      $magnitude = (int)$matches[1];
      if ($magnitude > $maximum) {
        throw new Exception(
          pht(
            'RRULE BYDAY value "%s" has an offset with magnitude "%s", but '.
            'the maximum permitted value is "%s".',
            $value,
            $magnitude,
            $maximum));
      }
    }

    $this->byDay = array_fuse($by_day);
    return $this;
  }

  public function getByDay() {
    return $this->byDay;
  }

  public function setByMonthDay(array $by_month_day) {
    $this->assertByRange('BYMONTHDAY', $by_month_day, -31, 31, false);
    $this->byMonthDay = array_fuse($by_month_day);
    return $this;
  }

  public function getByMonthDay() {
    return $this->byMonthDay;
  }

  public function setByYearDay($by_year_day) {
    $this->assertByRange('BYYEARDAY', $by_year_day, -366, 366, false);
    $this->byYearDay = array_fuse($by_year_day);
    return $this;
  }

  public function getByYearDay() {
    return $this->byYearDay;
  }

  public function setByMonth(array $by_month) {
    $this->assertByRange('BYMONTH', $by_month, 1, 12);
    $this->byMonth = array_fuse($by_month);
    return $this;
  }

  public function getByMonth() {
    return $this->byMonth;
  }

  public function setByWeekNumber(array $by_week_number) {
    $this->assertByRange('BYWEEKNO', $by_week_number, -53, 53, false);
    $this->byWeekNumber = array_fuse($by_week_number);
    return $this;
  }

  public function getByWeekNumber() {
    return $this->byWeekNumber;
  }

  public function setBySetPosition(array $by_set_position) {
    $this->assertByRange('BYSETPOS', $by_set_position, -366, 366, false);
    $this->bySetPosition = $by_set_position;
    return $this;
  }

  public function getBySetPosition() {
    return $this->bySetPosition;
  }

  public function setWeekStart($week_start) {
    // Make sure this is a valid weekday constant.
    self::getWeekdayIndex($week_start);

    $this->weekStart = $week_start;
    return $this;
  }

  public function getWeekStart() {
    return $this->weekStart;
  }

  public function resetSource() {
    $date = $this->getStartDateTime();

    $this->cursorSecond = $date->getSecond();
    $this->cursorMinute = $date->getMinute();
    $this->cursorHour = $date->getHour();

    // TODO: Figure this out.
    $this->cursorWeek = null;
    $this->cursorDay = $date->getDay();
    $this->cursorMonth = $date->getMonth();
    $this->cursorYear = $date->getYear();

    $this->setSeconds = array();
    $this->setMinutes = array();
    $this->setHours = array();
    $this->setDays = array();
    $this->setMonths = array();
    $this->setYears = array();

    $this->stateSecond = null;
    $this->stateMinute = null;
    $this->stateHour = null;
    $this->stateDay = null;
    $this->stateMonth = null;
    $this->stateYear = null;

    $this->initialMonth = $this->cursorMonth;
    $this->initialYear = $this->cursorYear;

    $by_hour = $this->getByHour();
    $by_minute = $this->getByMinute();
    $by_second = $this->getBySecond();

    $scale = $this->getFrequencyScale();

    // We return all-day events if the start date is an all-day event and we
    // don't have more granular selectors or a more granular frequency.
    $this->isAllDay = $date->getIsAllDay()
      && !$by_hour
      && !$by_minute
      && !$by_second
      && ($scale > self::SCALE_HOURLY);
  }

  public function getNextEvent($cursor) {
    $this->baseYear = $this->cursorYear;

    if ($this->isAllDay) {
      $this->nextDay();
    } else {
      $this->nextSecond();
    }

    $result = id(new PhutilCalendarAbsoluteDateTime())
      ->setViewerTimezone($this->getViewerTimezone())
      ->setYear($this->stateYear)
      ->setMonth($this->stateMonth)
      ->setDay($this->stateDay);

    if ($this->isAllDay) {
      $result->setIsAllDay(true);
    } else {
      $result
        ->setHour($this->stateHour)
        ->setMinute($this->stateMinute)
        ->setSecond($this->stateSecond);
    }

    return $result;
  }


  protected function nextSecond() {
    if ($this->setSeconds) {
      $this->stateSecond = array_pop($this->setSeconds);
      return;
    }

    $frequency = $this->getFrequency();
    $interval = $this->getInterval();
    $is_secondly = ($frequency == self::FREQUENCY_SECONDLY);
    $by_second = $this->getBySecond();
    $by_setpos = $this->getBySetPosition();

    while (!$this->setSeconds) {
      $this->nextMinute();

      if ($is_secondly || $by_second) {
        $seconds = $this->newSecondsSet(
          ($is_secondly ? $interval : 1),
          $by_second);
      } else {
        $seconds = array(
          $this->cursorSecond,
        );
      }

      if ($is_secondly && $by_setpos) {
        $seconds = $this->applySetPos($seconds, $by_setpos);
      }

      $this->setSeconds = array_reverse($seconds);
    }

    $this->stateSecond = array_pop($this->setSeconds);
  }

  protected function nextMinute() {
    if ($this->setMinutes) {
      $this->stateMinute = array_pop($this->setMinutes);
      return;
    }

    $frequency = $this->getFrequency();
    $interval = $this->getInterval();
    $scale = $this->getFrequencyScale();
    $is_minutely = ($frequency === self::FREQUENCY_MINUTELY);
    $by_minute = $this->getByMinute();
    $by_setpos = $this->getBySetPosition();

    while (!$this->setMinutes) {
      $this->nextHour();

      if ($is_minutely || $by_minute) {
        $minutes = $this->newMinutesSet(
          ($is_minutely ? $interval : 1),
          $by_minute);
      } else if ($scale < self::SCALE_MINUTELY) {
        $minutes = $this->newMinutesSet(
          1,
          array());
      } else {
        $minutes = array(
          $this->cursorMinute,
        );
      }

      if ($is_minutely && $by_setpos) {
        $minutes = $this->applySetPos($minutes, $by_setpos);
      }

      $this->setMinutes = array_reverse($minutes);
    }

    $this->stateMinute = array_pop($this->setMinutes);
  }

  protected function nextHour() {
    if ($this->setHours) {
      $this->stateHour = array_pop($this->setHours);
      return;
    }

    $frequency = $this->getFrequency();
    $interval = $this->getInterval();
    $scale = $this->getFrequencyScale();
    $is_hourly = ($frequency === self::FREQUENCY_HOURLY);
    $by_hour = $this->getByHour();
    $by_setpos = $this->getBySetPosition();

    while (!$this->setHours) {
      $this->nextDay();

      if ($is_hourly || $by_hour) {
        $hours = $this->newHoursSet(
          ($is_hourly ? $interval : 1),
          $by_hour);
      } else if ($scale < self::SCALE_HOURLY) {
        $hours = $this->newHoursSet(
          1,
          array());
      } else {
        $hours = array(
          $this->cursorHour,
        );
      }

      if ($is_hourly && $by_setpos) {
        $hours = $this->applySetPos($hours, $by_setpos);
      }

      $this->setHours = array_reverse($hours);
    }

    $this->stateHour = array_pop($this->setHours);
  }

  protected function nextDay() {
    if ($this->setDays) {
      $this->stateDay = array_pop($this->setDays);
      return;
    }

    $frequency = $this->getFrequency();
    $interval = $this->getInterval();
    $scale = $this->getFrequencyScale();
    $is_daily = ($frequency === self::FREQUENCY_DAILY);
    $is_weekly = ($frequency === self::FREQUENCY_WEEKLY);

    $by_day = $this->getByDay();
    $by_monthday = $this->getByMonthDay();
    $by_yearday = $this->getByYearDay();
    $by_weekno = $this->getByWeekNumber();
    $by_setpos = $this->getBySetPosition();
    $week_start = $this->getWeekStart();

    while (!$this->setDays) {
      $this->nextMonth();

      if ($is_daily || $by_day || $by_monthday || $by_yearday || $by_weekno) {
        $weeks = $this->newDaysSet(
          ($is_daily ? $interval : null),
          ($is_weekly ? $interval : null),
          $by_day,
          $by_monthday,
          $by_yearday,
          $by_weekno,
          $week_start);
      } else if ($scale < self::SCALE_DAILY) {
        $weeks = $this->newDaysSet(
          1,
          null,
          array(),
          array(),
          array(),
          array(),
          $week_start);
      } else {
        // The cursor day may not actually exist in the current month, so
        // make sure the day is valid before we generate a set which contains
        // it.
        $year_map = $this->getYearMap($this->stateYear, $week_start);
        if ($this->cursorDay > $year_map['monthDays'][$this->stateMonth]) {
          $weeks = array(
            array(),
          );
        } else {
          $weeks = array(
            array($this->cursorDay),
          );
        }
      }

      // Apply weekly BYSETPOS, if one exists.
      if ($is_weekly && $by_setpos) {
        $weeks = $this->applySetPos($weeks, $by_setpos);
      }

      // Unpack the weeks into days.
      $days = array_mergev($weeks);

      // Apply daily BYSETPOS, if one exists.
      if ($is_daily && $by_setpos) {
        $days = $this->applySetPos($days, $by_setpos);
      }

      $this->setDays = array_reverse($days);
    }

    $this->stateDay = array_pop($this->setDays);
  }

  protected function nextMonth() {
    if ($this->setMonths) {
      $this->stateMonth = array_pop($this->setMonths);
      return;
    }

    $frequency = $this->getFrequency();
    $interval = $this->getInterval();
    $scale = $this->getFrequencyScale();
    $is_monthly = ($frequency === self::FREQUENCY_MONTHLY);

    $by_month = $this->getByMonth();
    $by_setpos = $this->getBySetPosition();

    // If we have a BYMONTHDAY, we consider that set of days in every month.
    // For example, "FREQ=YEARLY;BYMONTHDAY=3" means "the third day of every
    // month", so we need to expand the month set if the constraint is present.
    $by_monthday = $this->getByMonthDay();

    // Likewise, we need to generate all months if we have BYYEARDAY or
    // BYWEEKNO.
    $by_yearday = $this->getByYearDay();
    $by_weekno = $this->getByWeekNumber();

    while (!$this->setMonths) {
      $this->nextYear();

      $is_dynamic = $is_monthly
        || $by_month
        || $by_monthday
        || $by_yearday
        || $by_weekno
        || ($scale < self::SCALE_MONTHLY);

      if ($is_dynamic) {
        $months = $this->newMonthsSet(
          ($is_monthly ? $interval : 1),
          $by_month);
      } else {
        $months = array(
          $this->cursorMonth,
        );
      }

      if ($is_monthly && $by_setpos) {
        $months = $this->applySetPos($months, $by_setpos);
      }

      $this->setMonths = array_reverse($months);
    }

    $this->stateMonth = array_pop($this->setMonths);
  }

  protected function nextYear() {
    $this->stateYear = $this->cursorYear;

    $frequency = $this->getFrequency();
    $is_yearly = ($frequency === self::FREQUENCY_YEARLY);

    if ($is_yearly) {
      $interval = $this->getInterval();
    } else {
      $interval = 1;
    }

    $this->cursorYear = $this->cursorYear + $interval;

    if ($this->cursorYear > ($this->baseYear + 100)) {
      throw new Exception(
        pht(
          'RRULE evaluation failed to generate more events in the next 100 '.
          'years. This RRULE is likely invalid or degenerate.'));
    }

  }

  private function newSecondsSet($interval, $set) {
    // TODO: This doesn't account for leap seconds. In theory, it probably
    // should, although this shouldn't impact any real events.
    $seconds_in_minute = 60;

    if ($this->cursorSecond >= $seconds_in_minute) {
      $this->cursorSecond -= $seconds_in_minute;
      return array();
    }

    list($cursor, $result) = $this->newIteratorSet(
      $this->cursorSecond,
      $interval,
      $set,
      $seconds_in_minute);

    $this->cursorSecond = ($cursor - $seconds_in_minute);

    return $result;
  }

  private function newMinutesSet($interval, $set) {
    // NOTE: This value is legitimately a constant! Amazing!
    $minutes_in_hour = 60;

    if ($this->cursorMinute >= $minutes_in_hour) {
      $this->cursorMinute -= $minutes_in_hour;
      return array();
    }

    list($cursor, $result) = $this->newIteratorSet(
      $this->cursorMinute,
      $interval,
      $set,
      $minutes_in_hour);

    $this->cursorMinute = ($cursor - $minutes_in_hour);

    return $result;
  }

  private function newHoursSet($interval, $set) {
    // TODO: This doesn't account for hours caused by daylight savings time.
    // It probably should, although this seems unlikely to impact any real
    // events.
    $hours_in_day = 24;

    if ($this->cursorHour >= $hours_in_day) {
      $this->cursorHour -= $hours_in_day;
      return array();
    }

    list($cursor, $result) = $this->newIteratorSet(
      $this->cursorHour,
      $interval,
      $set,
      $hours_in_day);

    $this->cursorHour = ($cursor - $hours_in_day);

    return $result;
  }

  private function newDaysSet(
    $interval_day,
    $interval_week,
    $by_day,
    $by_monthday,
    $by_yearday,
    $by_weekno,
    $week_start) {

    $year_map = $this->getYearMap($this->stateYear, $week_start);

    $selection = array();
    if ($interval_week) {
      while (true) {
        // TODO: This is all garbage?
        if ($this->cursorWeek > $year_map['weekCount']) {
          $this->cursorWeek -= $year_map['weekCount'];
          break;
        }

        foreach ($year_map['weeks'][$this->cursorWeek] as $key) {
          $selection[] = $year_map['info'][$key];
        }

        $last = last($selection);
        if ($last['month'] > $this->stateMonth) {
          break;
        }

        $this->cursorWeek += $interval_week;
      }
    } else {
      $month_idx = $this->stateMonth;

      if (!$interval_day) {
        $interval_day = 1;
      }

      // If we have a BYDAY, BYMONTHDAY, BYYEARDAY or BYWEEKNO selector and
      // this isn't the initial month, reset the day cursor to the first of the
      // month to make sure we examine the entire month. If we don't do this,
      // we can have a situation where an event occurs "every Monday in
      // October", but has a start date on the 19th of August, and misses
      // Mondays in October prior to the 19th.
      if ($by_day || $by_monthday || $by_yearday || $by_weekno) {
        if ($this->stateYear !== $this->initialYear ||
            $this->stateMonth !== $this->initialMonth) {
          $this->cursorDay = 1;
        }
      }

      while (true) {
        $month_days = $year_map['monthDays'][$month_idx];
        if ($this->cursorDay > $month_days) {
          $this->cursorDay -= $month_days;
          break;
        }

        $day_idx = $this->cursorDay;

        $key = "{$month_idx}M{$day_idx}D";
        $selection[] = $year_map['info'][$key];

        $this->cursorDay += $interval_day;
      }
    }

    $weeks = array();
    foreach ($selection as $key => $info) {
      if ($info['month'] != $this->stateMonth) {
        continue;
      }

      if ($by_day) {
        // TODO: This only handles "BYDAY=MO,TU". It does not yet properly
        // handle "BYDAY=+1FR" (e.g., the first Friday in the month).

        if (empty($by_day[$info['weekday']])) {
          continue;
        }
      }

      if ($by_monthday) {
        if (empty($by_monthday[$info['monthday']]) &&
            empty($by_monthday[$info['-monthday']])) {
          continue;
        }
      }

      if ($by_yearday) {
        if (empty($by_yearday[$info['yearday']]) &&
            empty($by_yearday[$info['-yearday']])) {
          continue;
        }
      }

      if ($by_weekno) {
        if (empty($by_weekno[$info['week']]) &&
            empty($by_weekno[$info['-week']])) {
          continue;
        }
      }

      $weeks[$info['week']][] = $info['monthday'];
    }

    return array_values($weeks);
  }

  private function newMonthsSet($interval, $set) {
    // NOTE: This value is also a real constant! Wow!
    $months_in_year = 12;

    if ($this->cursorMonth > $months_in_year) {
      $this->cursorMonth - $months_in_year;
      return array();
    }

    list($cursor, $result) = $this->newIteratorSet(
      $this->cursorMonth,
      $interval,
      $set,
      $months_in_year + 1);

    $this->cursorMonth = ($cursor - $months_in_year);

    return $result;
  }

  public static function getYearMap($year, $week_start) {
    static $maps = array();

    $key = "{$year}/{$week_start}";
    if (isset($maps[$key])) {
      return $maps[$key];
    }

    $map = self::newYearMap($year, $week_start);
    $maps[$key] = $map;

    return $maps[$key];
  }

  private static function newYearMap($year, $weekday_start) {
    $weekday_index = self::getWeekdayIndex($weekday_start);

    $is_leap = (($year % 4 === 0) && ($year % 100 !== 0)) ||
               ($year % 400 === 0);

    // There may be some clever way to figure out which day of the week a given
    // year starts on and avoid the cost of a DateTime construction, but I
    // wasn't able to turn it up and we only need to do this once per year.
    $datetime = new DateTime("{$year}-01-01", new DateTimeZone('UTC'));
    $weekday = (int)$datetime->format('w');

    if ($is_leap) {
      $max_day = 366;
    } else {
      $max_day = 365;
    }

    $month_days = array(
      1 => 31,
      2 => $is_leap ? 29 : 28,
      3 => 31,
      4 => 30,
      5 => 31,
      6 => 30,
      7 => 31,
      8 => 31,
      9 => 30,
      10 => 31,
      11 => 30,
      12 => 31,
    );

    // Per the spec, the first week of the year must contain at least four
    // days. If the week starts on a Monday but the year starts on a Saturday,
    // the first couple of days don't count as a week. In this case, the first
    // week will begin on January 3.
    $first_week_size = 0;
    $first_weekday = $weekday;
    for ($year_day = 1; $year_day <= $max_day; $year_day++) {
      $first_weekday = ($first_weekday + 1) % 7;
      $first_week_size++;
      if ($first_weekday === $weekday_index) {
        break;
      }
    }

    if ($first_week_size >= 4) {
      $week_number = 1;
    } else {
      $week_number = 0;
    }

    $info_map = array();

    $weekday_map = self::getWeekdayIndexMap();
    $weekday_map = array_flip($weekday_map);

    $month_number = 1;
    $month_day = 1;
    for ($year_day = 1; $year_day <= $max_day; $year_day++) {
      $key = "{$month_number}M{$month_day}D";

      $info = array(
        'year' => $year,
        'key' => $key,
        'month' => $month_number,
        'monthday' => $month_day,
        '-monthday' => -$month_days[$month_number] + $month_day - 1,
        'yearday' => $year_day,
        '-yearday' => -$max_day + $year_day - 1,
        'week' => $week_number,
        'weekday' => $weekday_map[$weekday],
      );

      $info_map[$key] = $info;

      $weekday = ($weekday + 1) % 7;
      if ($weekday === $weekday_index) {
        $week_number++;
      }

      $month_day = ($month_day + 1);
      if ($month_day > $month_days[$month_number]) {
        $month_day = 1;
        $month_number++;
      }
    }

    // Check how long the final week is. If it doesn't have four days, this
    // is really the first week of the next year.
    $final_week = array();
    foreach ($info_map as $key => $info) {
      if ($info['week'] == $week_number) {
        $final_week[] = $key;
      }
    }

    if (count($final_week) < 4) {
      $week_number = $week_number - 1;
      $next_year = self::getYearMap($year + 1, $weekday_start);
      $next_year_weeks = $next_year['weekCount'];
    } else {
      $next_year_weeks = null;
    }

    if ($first_week_size < 4) {
      $last_year = self::getYearMap($year - 1, $weekday_start);
      $last_year_weeks = $last_year['weekCount'];
    } else {
      $last_year_weeks = null;
    }

    // Now that we know how many weeks the year has, we can compute the
    // negative offsets.
    foreach ($info_map as $key => $info) {
      $week = $info['week'];

      if ($week === 0) {
        // If this day is part of the first partial week of the year, give
        // it the week number of the last week of the prior year instead.
        $info['week'] = $last_year_weeks;
        $info['-week'] = -1;
      } else if ($week > $week_number) {
        // If this day is part of the last partial week of the year, give
        // it week numbers from the next year.
        $info['week'] = 1;
        $info['-week'] = -$next_year_weeks;
      } else {
        $info['-week'] = -$week_number + $week - 1;
      }

      $info_map[$key] = $info;
    }

    return array(
      'info' => $info_map,
      'weekCount' => $week_number,
      'dayCount' => $max_day,
      'monthDays' => $month_days,
    );
  }

  private function newIteratorSet($cursor, $interval, $set, $limit) {
    if ($interval < 1) {
      throw new Exception(
        pht(
          'Invalid iteration interval ("%d"), must be at least 1.',
          $interval));
    }

    $result = array();
    $seen = array();

    $ii = $cursor;
    while (true) {
      if (!$set || isset($set[$ii])) {
        $result[] = $ii;
      }

      $ii = ($ii + $interval);

      if ($ii >= $limit) {
        break;
      }
    }

    sort($result);
    $result = array_values($result);

    return array($ii, $result);
  }

  private function applySetPos(array $values, array $setpos) {
    $select = array();

    $count = count($values);
    foreach ($setpos as $pos) {
      if ($pos > 0 && $pos <= $count) {
        $select[] = ($pos - 1);
      } else if ($pos < 0 && $pos >= -$count) {
        $select[] = ($count + $pos);
      }
    }

    sort($select);
    return array_select_keys($values, $select);
  }

  private function assertByRange(
    $source,
    array $values,
    $min,
    $max,
    $allow_zero = true) {

    foreach ($values as $value) {
      if (!is_int($value)) {
        throw new Exception(
          pht(
            'Value "%s" in RRULE "%s" parameter is invalid: values must be '.
            'integers.',
            $value,
            $source));
      }

      if ($value < $min || $value > $max) {
        throw new Exception(
          pht(
            'Value "%s" in RRULE "%s" parameter is invalid: it must be '.
            'between %s and %s.',
            $value,
            $source,
            $min,
            $max));
      }

      if (!$value && !$allow_zero) {
        throw new Exception(
          pht(
            'Value "%s" in RRULE "%s" parameter is invalid: it must not '.
            'be zero.',
            $value,
            $source));
      }
    }
  }

}
