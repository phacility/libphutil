<?php

/*
 * Copyright 2012 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @group testcase
 */
final class AbstractDirectedGraphTestCase extends ArcanistPhutilTestCase {

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

  private function findGraphCycle(array $graph, $seed = 'A', $search = 'A') {
    $detector = new TestAbstractDirectedGraph();
    $detector->setTestData($graph);
    $detector->addNodes(array_select_keys($graph, array($seed)));
    $detector->loadGraph();
    return $detector->detectCycles($search);
  }
}
