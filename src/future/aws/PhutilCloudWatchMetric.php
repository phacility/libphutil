<?php

final class PhutilCloudWatchMetric extends Phobject {
  private $name;
  private $value;
  private $unit = 'None';
  private $dimensions = array();

  public function setName($name) {
    $this->name = $name;
    return $this;
  }

  public function getName() {
    return $this->name;
  }

  public function setValue($value) {
    $this->value = $value;
    return $this;
  }

  public function getValue() {
    return $this->value;
  }

  public function setUnit($unit) {
    $this->unit = $unit;
    return $this;
  }

  public function getUnit() {
    return $this->unit;
  }

  public function setDimensions(array $dimensions) {
    $this->dimensions = $dimensions;
    return $this;
  }

  public function getDimensions() {
    return $this->dimensions;
  }

  public function addDimension($name, $value) {
    $this->dimensions[$name] = $value;
    return $this;
  }

}
