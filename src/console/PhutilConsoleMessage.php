<?php

final class PhutilConsoleMessage extends Phobject {

  const TYPE_CONFIRM    = 'phutil:confirm';
  const TYPE_PROMPT     = 'phutil:prompt';
  const TYPE_INPUT      = 'phutil:in';
  const TYPE_OUT        = 'phutil:out';
  const TYPE_ERR        = 'phutil:err';
  const TYPE_LOG        = 'phutil:log';
  const TYPE_TTY        = 'phutil:tty?';
  const TYPE_IS_TTY     = 'phutil:tty!';
  const TYPE_COLS       = 'phutil:cols?';
  const TYPE_COL_WIDTH  = 'phutil:cols!';
  const TYPE_ENABLED    = 'phutil:enabled?';
  const TYPE_IS_ENABLED = 'phutil:enabled!';

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
