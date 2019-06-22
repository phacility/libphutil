<?php

final class AbstractDirectedGraphTestCase extends PhutilTestCase {

  public function testTrivialGraph() {
    $graph = array(
      'A' => array(),
    );

    $cycle = $this->findGraphCycle($graph);
    $this->assertEqual(null, $cycle, pht('Trivial Graph'));
  }

  public function testNoncyclicGraph() {
    $graph = array(
      'A' => array('B', 'C'),
      'B' => array('D'),
      'C' => array(),
      'D' => array(),
    );

    $cycle = $this->findGraphCycle($graph);
    $this->assertEqual(null, $cycle, pht('Noncyclic Graph'));
  }

  public function testTrivialCyclicGraph() {
    $graph = array(
      'A' => array('A'),
    );

    $cycle = $this->findGraphCycle($graph);
    $this->assertEqual(array('A', 'A'), $cycle, pht('Trivial Cycle'));
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
    $this->assertEqual(array('A', 'C', 'F', 'C'), $cycle, pht('Cyclic Graph'));
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
    $this->assertEqual(null, $cycle, pht('Non-tree graph'));
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

    $this->assertTrue(
      (bool)$raised,
      pht('Exception raised by unloadable edges.'));
  }

  public function testTopologicalOrder() {
    $graph = array(
      'A' => array('B', 'C'),
      'B' => array('D', 'E'),
      'C' => array(),
      'D' => array(),
      'E' => array(),
    );

    $sorted = $this->getTopologicalOrder($graph);

    $this->assertEqual(
      array('A', 'C', 'B', 'E', 'D'),
      $sorted,
      pht('Topologically sorted tree.'));

    $graph = array(
      'A' => array('B', 'C'),
      'B' => array('C'),
      'C' => array('D', 'E'),
      'D' => array('E'),
      'E' => array(),
    );

    $sorted = $this->getTopologicalOrder($graph);

    $this->assertEqual(
      array('A', 'B', 'C', 'D', 'E'),
      $sorted,
      pht('Topologically sorted tree with nesting.'));
  }

  public function testRoughTopologicalOrder() {
    $graph = array(
      'A' => array('B', 'C'),
      'B' => array('D', 'E'),
      'C' => array(),
      'D' => array(),
      'E' => array(),
      'F' => array('H'),
      'G' => array('F', 'E'),
      'H' => array('G'),
    );

    $sorted = $this->getRoughTopologicalOrder($graph);

    $this->assertEqual(count($graph), count($sorted));

    $this->assertEqual('C', $sorted[0]['node']);
    $this->assertEqual('D', $sorted[1]['node']);
    $this->assertEqual('E', $sorted[2]['node']);
    $this->assertEqual('B', $sorted[3]['node']);
    $this->assertEqual('A', $sorted[4]['node']);
    $this->assertEqual('F', $sorted[5]['node']);
    $this->assertEqual('G', $sorted[6]['node']);
    $this->assertEqual('H', $sorted[7]['node']);

    $this->assertEqual(0, $sorted[0]['depth']);
    $this->assertEqual(0, $sorted[1]['depth']);
    $this->assertEqual(0, $sorted[2]['depth']);
    $this->assertEqual(1, $sorted[3]['depth']);
    $this->assertEqual(2, $sorted[4]['depth']);
    $this->assertEqual(3, $sorted[5]['depth']);
    $this->assertEqual(3, $sorted[6]['depth']);
    $this->assertEqual(3, $sorted[7]['depth']);

    $this->assertEqual(false, $sorted[0]['cycle']);
    $this->assertEqual(false, $sorted[1]['cycle']);
    $this->assertEqual(false, $sorted[2]['cycle']);
    $this->assertEqual(false, $sorted[3]['cycle']);
    $this->assertEqual(false, $sorted[4]['cycle']);
    $this->assertEqual(true, $sorted[5]['cycle']);
    $this->assertEqual(true, $sorted[6]['cycle']);
    $this->assertEqual(true, $sorted[7]['cycle']);
  }

  private function findGraphCycle(array $graph, $seed = 'A', $search = 'A') {
    $detector = new TestAbstractDirectedGraph();
    $detector->setTestData($graph);
    $detector->addNodes(array_select_keys($graph, array($seed)));
    $detector->loadGraph();
    return $detector->detectCycles($search);
  }

  private function getTopologicalOrder(array $graph, $seed = 'A') {
    $detector = new TestAbstractDirectedGraph();
    $detector->setTestData($graph);
    $detector->addNodes(array_select_keys($graph, array($seed)));
    $detector->loadGraph();
    return $detector->getNodesInTopologicalOrder();
  }

  private function getRoughTopologicalOrder(array $graph) {
    $detector = new TestAbstractDirectedGraph();
    $detector->setTestData($graph);
    $detector->addNodes(array_keys($graph));
    return $detector->getNodesInRoughTopologicalOrder();
  }

}
