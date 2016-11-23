<?php

final class PhutilConsoleList extends PhutilConsoleView {

  private $items = array();
  private $wrap = true;
  private $bullet = '-';

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

  public function setBullet($bullet) {
    $this->bullet = $bullet;
    return $this;
  }

  public function getBullet() {
    return $this->bullet;
  }

  public function setWrap($wrap) {
    $this->wrap = $wrap;
    return $this;
  }

  protected function drawView() {
    $indent_depth = 6;
    $indent_string = str_repeat(' ', $indent_depth);

    if ($this->bullet !== null) {
      $bullet = $this->bullet.' ';
      $indent_depth = $indent_depth + phutil_utf8_console_strlen($bullet);
    } else {
      $bullet = '';
    }

    $output = array();
    foreach ($this->getItems() as $item) {
      if ($this->wrap) {
        $item = tsprintf('%s', $item)
          ->applyIndent($indent_depth, false);
      }

      $output[] = $indent_string.$bullet.$item;
    }

    return $this->drawLines($output);
  }

}
