<?php

/**
 * Example implementation and test case for @{class:PhutilBufferedIterator}.
 */
final class PhutilExampleBufferedIterator extends PhutilBufferedIterator {

  private $cursor;
  private $data;

  protected function didRewind() {
    $this->cursor = 0;
  }

  protected function loadPage() {
    $result = $this->query($this->cursor, $this->getPageSize());
    $this->cursor += count($result);
    return $result;
  }

  public function setExampleData(array $data) {
    $this->data = $data;
  }

  private function query($cursor, $limit) {
    // NOTE: Normally you'd load or generate results from some external source
    // here. Since this is an example, we just use a premade dataset.

    return array_slice($this->data, $cursor, $limit);
  }

}
