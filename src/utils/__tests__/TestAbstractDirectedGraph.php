<?php

final class TestAbstractDirectedGraph extends AbstractDirectedGraph {

  private $nodes;

  public function setTestData(array $nodes) {
    $this->nodes = $nodes;
    return $this;
  }

  protected function loadEdges(array $nodes) {
    return array_select_keys($this->nodes, $nodes);
  }

}
