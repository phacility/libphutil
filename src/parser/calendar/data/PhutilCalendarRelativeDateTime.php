<?php

final class PhutilCalendarRelativeDateTime
  extends PhutilCalendarProxyDateTime {

  private $duration;

  public function setOrigin(PhutilCalendarDateTime $origin) {
    return $this->setProxy($origin);
  }

  public function getOrigin() {
    return $this->getProxy();
  }

  public function setDuration(PhutilCalendarDuration $duration) {
    $this->duration = $duration;
    return $this;
  }

  public function getDuration() {
    return $this->duration;
  }

  protected function newPHPDateTime() {
    $datetime = parent::newPHPDateTime();
    $duration = $this->getDuration();

    if ($duration->getIsNegative()) {
      $sign = '-';
    } else {
      $sign = '+';
    }

    $map = array(
      'weeks' => $duration->getWeeks(),
      'days' => $duration->getDays(),
      'hours' => $duration->getHours(),
      'minutes' => $duration->getMinutes(),
      'seconds' => $duration->getSeconds(),
    );

    foreach ($map as $unit => $value) {
      if (!$value) {
        continue;
      }
      $datetime->modify("{$sign}{$value} {$unit}");
    }

    return $datetime;
  }

}
