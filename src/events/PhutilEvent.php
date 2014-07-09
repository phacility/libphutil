<?php

/**
 * @concrete-extensible
 */
class PhutilEvent {

  private $type;
  private $data;
  private $stop = false;

  public function __construct($type, array $data = array()) {
    $this->type = $type;
    $this->data = $data;
  }

  public function getType() {
    return $this->type;
  }

  public function getValue($key, $default = null) {
    return idx($this->data, $key, $default);
  }

  public function setValue($key, $value) {
    $this->data[$key] = $value;
    return $this;
  }

  public function stop() {
    $this->stop = true;
    return $this;
  }

  public function isStopped() {
    return $this->stop;
  }

}
