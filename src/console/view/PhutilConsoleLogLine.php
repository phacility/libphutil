<?php

abstract class PhutilConsoleLogLine extends PhutilConsoleView {

  private $kind;
  private $message;

  abstract protected function getLogLineColor();

  public function __construct($kind, $message) {
    $this->kind = $kind;
    $this->message = $message;
  }

  protected function drawView() {
    $color = $this->getLogLineColor();

    return tsprintf(
      "<bg:".$color.">** %s **</bg> %s\n",
      $this->kind,
      $this->message);
  }

}
