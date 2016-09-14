<?php

final class PhutilCalendarEventNode
  extends PhutilCalendarNode {

  const NODETYPE = 'event';

  private $uid;
  private $name;
  private $description;
  private $startDateTime;
  private $endDateTime;
  private $duration;
  private $createdDateTime;
  private $modifiedDateTime;

  public function setUID($uid) {
    $this->uid = $uid;
    return $this;
  }

  public function getUID() {
    return $this->uid;
  }

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

  public function setStartDateTime(PhutilCalendarDateTime $start) {
    $this->startDateTime = $start;
    return $this;
  }

  public function getStartDateTime() {
    return $this->startDateTime;
  }

  public function setEndDateTime(PhutilCalendarDateTime $end) {
    $this->endDateTime = $end;
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

  public function setCreatedDateTime(PhutilCalendarDateTime $created) {
    $this->createdDateTime = $created;
    return $this;
  }

  public function getCreatedDateTime() {
    return $this->createdDateTime;
  }

  public function setModifiedDateTime(PhutilCalendarDateTime $modified) {
    $this->modifiedDateTime = $modified;
    return $this;
  }

  public function getModifiedDateTime() {
    return $this->modifiedDateTime;
  }

}
