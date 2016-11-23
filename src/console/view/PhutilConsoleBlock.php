<?php

final class PhutilConsoleBlock extends PhutilConsoleView {

  private $items = array();

  public function addParagraph($item) {
    $this->items[] = array(
      'type' => 'paragraph',
      'item' => $item,
    );
    return $this;
  }

  public function addList(PhutilConsoleList $list) {
    $this->items[] = array(
      'type' => 'list',
      'item' => $list,
    );
    return $this;
  }

  protected function drawView() {
    $output = array();

    foreach ($this->items as $spec) {
      $type = $spec['type'];
      $item = $spec['item'];

      switch ($type) {
        case 'paragraph':
          $item = array(
            tsprintf('%s', $item)->applyWrap(),
            "\n",
          );
          break;
        case 'list':
          $item = $item;
          break;
      }

      $output[] = $item;
    }

    return $this->drawLines($output);
  }

}
