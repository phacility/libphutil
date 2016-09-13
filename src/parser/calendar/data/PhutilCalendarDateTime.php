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

  abstract protected function newPHPDateTimeZone();
  abstract protected function newPHPDateTime();

}
