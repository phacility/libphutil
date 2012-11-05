<?php

final class PhutilConsoleMessage {

  const TYPE_CONFIRM    = 'phutil:confirm';
  const TYPE_PROMPT     = 'phutil:prompt';
  const TYPE_INPUT      = 'phutil:in';
  const TYPE_OUT        = 'phutil:out';
  const TYPE_ERR        = 'phutil:err';
  const TYPE_LOG        = 'phutil:log';

  private $type;
  private $data;

  public function setData($data) {
    $this->data = $data;
    return $this;
  }

  public function getData() {
    return $this->data;
  }

  public function setType($type) {
    $this->type = $type;
    return $this;
  }

  public function getType() {
    return $this->type;
  }

}
