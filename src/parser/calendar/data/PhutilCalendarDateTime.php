<?php

abstract class PhutilCalendarDateTime
  extends Phobject {

  private $viewerTimezone;
  private $isAllDay = false;

  public function setViewerTimezone($viewer_timezone) {
    $this->viewerTimezone = $viewer_timezone;
    return $this;
  }

  public function getViewerTimezone() {
    return $this->viewerTimezone;
  }

  public function setIsAllDay($is_all_day) {
    $this->isAllDay = $is_all_day;
    return $this;
  }

  public function getIsAllDay() {
    return $this->isAllDay;
  }

  public function getEpoch() {
    $datetime = $this->newPHPDateTime();
    return (int)$datetime->format('U');
  }

  public function getISO8601() {
    $datetime = $this->newPHPDateTime();
    $datetime->setTimezone(new DateTimeZone('UTC'));

    if ($this->getIsAllDay()) {
      return $datetime->format('Ymd');
    } else {
      return $datetime->format('Ymd\\THis\\Z');
    }
  }

  abstract protected function newPHPDateTimeZone();
  abstract protected function newPHPDateTime();

}
