<?php

abstract class PhutilCalendarProxyDateTime
  extends PhutilCalendarDateTime {

  private $proxy;

  final protected function setProxy(PhutilCalendarDateTime $proxy) {
    $this->proxy = $proxy;
    return $this;
  }

  final protected function getProxy() {
    return $this->proxy;
  }

  public function setViewerTimezone($timezone) {
    $this->getProxy()->setViewerTimezone($timezone);
    return $this;
  }

  public function getViewerTimezone() {
    return $this->getProxy()->getViewerTimezone();
  }

  public function setIsAllDay($is_all_day) {
    $this->getProxy()->setIsAllDay($is_all_day);
    return $this;
  }

  public function getIsAllDay() {
    return $this->getProxy()->getIsAllDay();
  }

  protected function newPHPDateTimezone() {
    return $this->getProxy()->newPHPDateTimezone();
  }

  protected function newPHPDateTime() {
    return $this->getProxy()->newPHPDateTime();
  }

}
