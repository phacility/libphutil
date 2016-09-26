<?php

final class PhutilCalendarRecurrenceRule
  extends PhutilCalendarRecurrenceSource {

  private $startDateTime;
  private $frequency;
  private $until;
  private $count;
  private $interval = 1;
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

  private $maps = array();

  public function setStartDateTime(PhutilCalendarDateTime $start) {
    $this->startDateTime = $start;
    return $this;
  }

  public function getStartDateTime() {
    return $this->startDateTime;
  }

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

  public function setByWeekNumber($by_week_number) {
    $this->byWeekNumber = $by_week_number;
    return $this;
  }

  public function getByWeekNumber() {
    return $this->byWeekNumber;
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
  }

  public function getNextEvent($cursor) {
    $date = $this->getStartDateTime();

    $all_day = $date->getIsAllDay();
    if ($all_day) {
      $this->nextDay();
    } else {
      $this->nextSecond();
    }

    $result = id(new PhutilCalendarAbsoluteDateTime())
      ->setViewerTimezone($this->getViewerTimezone())
      ->setYear($this->stateYear)
      ->setMonth($this->stateMonth)
      ->setDay($this->stateDay);

    if ($all_day) {
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
    $is_secondly = ($frequency == 'SECONDLY');
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
    $is_secondly = ($frequency === 'SECONDLY');
    $is_minutely = ($frequency === 'MINUTELY');
    $by_minute = $this->getByMinute();
    $by_setpos = $this->getBySetPosition();

    while (!$this->setMinutes) {
      $this->nextHour();

      if ($is_minutely || $by_minute) {
        $minutes = $this->newMinutesSet(
          ($is_minutely ? $interval : 1),
          $by_minute);
      } else if ($is_secondly) {
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
    $is_secondly = ($frequency === 'SECONDLY');
    $is_minutely = ($frequency === 'MINUTELY');
    $is_hourly = ($frequency === 'HOURLY');
    $by_hour = $this->getByHour();
    $by_setpos = $this->getBySetPosition();

    while (!$this->setHours) {
      $this->nextDay();

      if ($is_minutely || $by_hour) {
        $hours = $this->newHoursSet(
          ($is_hourly ? $interval : 1),
          $by_hour);
      } else if ($is_secondly || $is_minutely) {
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
    $is_secondly = ($frequency === 'SECONDLY');
    $is_minutely = ($frequency === 'MINUTELY');
    $is_hourly = ($frequency === 'HOURLY');
    $is_daily = ($frequency === 'DAILY');
    $is_weekly = ($frequency === 'WEEKLY');

    $by_day = $this->getByDay();
    $by_monthday = $this->getByMonthDay();
    $by_yearday = $this->getByYearDay();
    $by_weekno = $this->getByWeekNumber();
    $by_setpos = $this->getBySetPosition();

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
          $this->getWeekStart());
      } else if ($is_secondly || $is_minutely || $is_hourly) {
        $all_values = true;
        $weeks = $this->newDaysSet(
          1,
          null,
          array(),
          array(),
          array(),
          array(),
          $this->getWeekStart());
      } else {
        $weeks = array(
          array($this->cursorDay),
        );
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
    $is_secondly = ($frequency === 'SECONDLY');
    $is_minutely = ($frequency === 'MINUTELY');
    $is_hourly = ($frequency === 'HOURLY');
    $is_daily = ($frequency === 'DAILY');
    $is_weekly = ($frequency === 'WEEKLY');
    $is_monthly = ($frequency === 'MONTHLY');

    $by_month = $this->getByMonth();
    $by_setpos = $this->getBySetPosition();

    while (!$this->setMonths) {
      $this->nextYear();

      if ($is_monthly || $by_month) {
        $months = $this->newMonthsSet(
          ($is_monthly ? $interval : 1),
          $by_month);
      } else if (
          $is_secondly || $is_minutely || $is_hourly ||
          $is_daily || $is_weekly) {
        $months = $this->newMonthsSet(
          1,
          array());
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
    $is_yearly = ($frequency === 'YEARLY');

    if ($is_yearly) {
      $interval = $this->getInterval();
    } else {
      $interval = 1;
    }

    $this->cursorYear = $this->cursorYear + $interval;
  }

  private function newSecondsSet($interval, $set) {
    // TODO: This doesn't account for leap sections. In theory, it probably
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

    $year_map = $this->getYearMap($this->cursorYear, $week_start);

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
        if ($last['month'] > $this->cursorMonth) {
          break;
        }

        $this->cursorWeek += $interval_week;
      }
    } else {
      $calendar = $year_map['calendar'];
      $month_idx = $this->cursorMonth;

      if (!$interval_day) {
        $interval_day = 1;
      }

      while (true) {
        $month_days = $year_map['monthDays'][$month_idx];
        if ($this->cursorDay > $month_days) {
          $this->cursorDay -= $month_days;
          break;
        }

        $day_idx = $this->cursorDay;

        $key = $calendar[$month_idx][$day_idx]['key'];
        $selection[] = $year_map['info'][$key];

        $this->cursorDay += $interval_day;
      }
    }

    if ($by_day) {
      $by_day = array_fuse($by_day);
    }

    if ($by_monthday) {
      $by_monthday = array_fuse($by_monthday);
    }

    if ($by_yearday) {
      $by_yearday = array_fuse($by_yearday);
    }

    if ($by_weekno) {
      $by_weekno = array_fuse($by_weekno);
    }

    $weeks = array();
    foreach ($selection as $key => $info) {
      if ($info['month'] != $this->cursorMonth) {
        continue;
      }

      if ($by_day) {
        // TODO: Implement weekday stuff.
      }

      if ($by_monthday) {
        if (empty($by_monthday[$info['monthday']]) &&
            empty($by_monthday[$info['-monthday']])) {
          continue;
        }
      }

      if ($by_yearday) {
        if (empty($by_monthday[$info['yearday']]) &&
            empty($by_monthday[$info['-yearday']])) {
          continue;
        }
      }

      if ($by_weekno) {
        // TODO: Implement week number stuff.
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

  private function getYearMap($year, $week_start) {
    $key = "{$year}/{$week_start}";
    if (isset($this->maps[$key])) {
      return $this->maps[$key];
    }

    $map = self::newYearMap($year, $week_start);
    $this->maps[$key] = $map;

    return $this->maps[$key];
  }

  public static function newYearMap($year, $week_start) {
    $is_leap = (($year % 4 === 0) && ($year % 100 !== 0)) ||
               ($year % 400 === 0);

    // There may be some clever way to figure out which day of the week a given
    // year starts on and avoid the cost of a DateTime construction, but I
    // wasn't able to turn it up and we only need to do this once per year.
    $datetime = new DateTime("{$year}-01-01", new DateTimeZone('UTC'));
    $weekday = $datetime->format('w');

    // TODO: Week 1 must contain at least 4 days!

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

    $info_map = array();
    $calendar_map = array();
    $week_map = array();
    $yearday_map = array();

    $month_number = 1;
    $month_day = 1;
    $week_number = 1;
    for ($year_day = 1; $year_day <= $max_day; $year_day++) {
      $key = $month_number.'/'.$month_day;

      $info = array(
        'key' => $key,
        'month' => $month_number,
        'monthday' => $month_day,
        '-monthday' => -$month_days[$month_number] + $month_day - 1,
        'yearday' => $year_day,
        '-yearday' => -$max_day + $year_day - 1,
        'week' => $week_number,
      );

      $info_map[$key] = $info;
      $calendar_map[$month_number][$month_day] = $info;
      $week_map[$week_number][] = $info;
      $yearday_map[$year_day] = $info;

      $weekday = ($weekday + 1) % 7;
      if ($weekday === $week_start) {
        $week_number++;
      }

      $month_day = ($month_day + 1);
      if ($month_day > $month_days[$month_number]) {
        $month_day = 1;
        $month_number++;
      }
    }

    return array(
      'info' => $info_map,
      'calendar' => $calendar_map,
      'weeks' => $week_map,
      'yeardays' => $yearday_map,
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

    if ($set) {
      $set = array_fuse($set);
    } else {
      $set = array();
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


}
