<?php

final class PhutilConsoleConcatenatedView extends PhutilConsoleView {

  private $items = array();

  public function addItem($item) {
    $this->items[] = $item;
    return $this;
  }

  protected function drawView() {
    $output = array();

    foreach ($this->items as $item) {
      $output[] = $this->flattenView($item);
    }

    return implode('', $output);
  }

}
