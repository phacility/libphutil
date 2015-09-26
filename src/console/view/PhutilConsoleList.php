<?php

final class PhutilConsoleList extends PhutilConsoleView {

  private $items = array();
  private $wrap = true;

  public function addItem($item) {
    $this->items[] = $item;
    return $this;
  }

  public function addItems(array $items) {
    foreach ($items as $item) {
      $this->addItem($item);
    }
    return $this;
  }

  public function getItems() {
    return $this->items;
  }

  public function setWrap($wrap) {
    $this->wrap = $wrap;
    return $this;
  }

  protected function drawView() {
    $output = array();
    foreach ($this->getItems() as $item) {
      if ($this->wrap) {
        $item = phutil_console_wrap($item, 8);
      }
      $item = '      - '.$item;
      $output[] = $item;
    }

    return $this->drawLines($output);
  }

}
