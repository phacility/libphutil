<?php

abstract class PhutilCalendarDateTime
  extends Phobject {

  private $viewerTimezone;

  public function setViewerTimezone($viewer_timezone) {
    $this->viewerTimezone = $viewer_timezone;
    return $this;
  }

  public function getViewerTimezone() {
    return $this->viewerTimezone;
  }

  public function getEpoch() {
    $datetime = $this->newPHPDateTime();
    return (int)$datetime->format('U');
  }

  public function getISO8601() {
    $datetime = $this->newPHPDateTime();
    $datetime->setTimezone(new DateTimeZone('UTC'));
    return $datetime->format('Ymd\\THis\\Z');
  }

  abstract protected function newPHPDateTimeZone();
  abstract protected function newPHPDateTime();

}
