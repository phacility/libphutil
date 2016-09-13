<?php

final class PhutilCalendarEventNode
  extends PhutilCalendarNode {

  const NODETYPE = 'event';

  private $name;
  private $description;
  private $startDateTime;
  private $endDateTime;
  private $duration;

  public function setName($name) {
    $this->name = $name;
    return $this;
  }

  public function getName() {
    return $this->name;
  }

  public function setDescription($description) {
    $this->description = $description;
    return $this;
  }

  public function getDescription() {
    return $this->description;
  }

  public function setStartDateTime(PhutilCalendarDateTime $start_date_time) {
    $this->startDateTime = $start_date_time;
    return $this;
  }

  public function getStartDateTime() {
    return $this->startDateTime;
  }

  public function setEndDateTime(PhutilCalendarDateTime $end_date_time) {
    $this->endDateTime = $end_date_time;
    return $this;
  }

  public function getEndDateTime() {
    $end = $this->endDateTime;
    if ($end) {
      return $end;
    }

    $start = $this->getStartDateTime();
    $duration = $this->getDuration();
    if ($start && $duration) {
      return id(new PhutilCalendarRelativeDateTime())
        ->setOrigin($start)
        ->setDuration($duration);
    }

    return null;
  }

  public function setDuration(PhutilCalendarDuration $duration) {
    $this->duration = $duration;
    return $this;
  }

  public function getDuration() {
    return $this->duration;
  }


}
