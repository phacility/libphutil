<?php

/**
 * @group testcase
 */
final class AbstractDirectedGraphTestCase extends PhutilTestCase {

  public function testTrivialGraph() {
    $graph = array(
      'A' => array(),
    );

    $cycle = $this->findGraphCycle($graph);
    $this->assertEqual(null, $cycle, 'Trivial Graph');
  }

  public function testNoncyclicGraph() {
    $graph = array(
      'A' => array('B', 'C'),
      'B' => array('D'),
      'C' => array(),
      'D' => array(),
    );

    $cycle = $this->findGraphCycle($graph);
    $this->assertEqual(null, $cycle, 'Noncyclic Graph');
  }

  public function testTrivialCyclicGraph() {
    $graph = array(
      'A' => array('A'),
    );

    $cycle = $this->findGraphCycle($graph);
    $this->assertEqual(array('A', 'A'), $cycle, 'Trivial Cycle');
  }

  public function testCyclicGraph() {
    $graph = array(
      'A' => array('B', 'C'),
      'B' => array('D'),
      'C' => array('E', 'F'),
      'D' => array(),
      'E' => array(),
      'F' => array('G', 'C'),
      'G' => array(),
    );

    $cycle = $this->findGraphCycle($graph);
    $this->assertEqual(array('A', 'C', 'F', 'C'), $cycle, 'Cyclic Graph');
  }

  public function testNonTreeGraph() {
    // This graph is non-cyclic, but C is both a child and a grandchild of A.
    // This is permitted.
    $graph = array(
      'A' => array('B', 'C'),
      'B' => array('C'),
      'C' => array(),
    );

    $cycle = $this->findGraphCycle($graph);
    $this->assertEqual(null, $cycle, 'NonTreeGraph');
  }

  public function testEdgeLoadFailure() {
    $graph = array(
      'A' => array('B'),
    );

    $raised = null;
    try {
      $this->findGraphCycle($graph);
    } catch (Exception $ex) {
      $raised = $ex;
    }

    $this->assertEqual(
      true,
      (bool)$raised,
      'Exception raised by unloadable edges.');
  }

  public function testTopographicSortTree() {
    $graph = array(
      'A' => array('B', 'C'),
      'B' => array('D', 'E'),
      'C' => array(),
      'D' => array(),
      'E' => array()
    );

    $sorted = $this->getTopographicSort($graph);

    $this->assertEqual(
      array('A', 'C', 'B', 'E', 'D'),
      $sorted,
      'Topographically sorted tree.');

    $graph = array(
      'A' => array('B', 'C'),
      'B' => array('C'),
      'C' => array('D', 'E'),
      'D' => array('E'),
      'E' => array()
    );

    $sorted = $this->getTopographicSort($graph);

    $this->assertEqual(
      array('A', 'B', 'C', 'D', 'E'),
      $sorted,
      'Topographically sorted tree with nesting.');
  }

  private function findGraphCycle(array $graph, $seed = 'A', $search = 'A') {
    $detector = new TestAbstractDirectedGraph();
    $detector->setTestData($graph);
    $detector->addNodes(array_select_keys($graph, array($seed)));
    $detector->loadGraph();
    return $detector->detectCycles($search);
  }

  private function getTopographicSort(array $graph, $seed = 'A') {
    $detector = new TestAbstractDirectedGraph();
    $detector->setTestData($graph);
    $detector->addNodes(array_select_keys($graph, array($seed)));
    $detector->loadGraph();
    return $detector->getTopographicallySortedNodes();
  }
}
