<?php

final class AASTNodeList implements Iterator, Countable {

  protected $list;
  protected $tree;
  protected $ids;
  protected $pos;

  public function count() {
    return count($this->ids);
  }

  public function current() {
    return $this->list[$this->key()];
  }

  public function rewind() {
    $this->pos = 0;
  }

  public function valid() {
    return $this->pos < count($this->ids);
  }

  public function next() {
    $this->pos++;
  }

  public function key() {
    return $this->ids[$this->pos];
  }

  public static function newFromTreeAndNodes(AASTTree $tree, array $nodes) {
    assert_instances_of($nodes, 'AASTNode');
    $obj = new AASTNodeList();
    $obj->tree = $tree;
    $obj->list = $nodes;
    $obj->ids  = array_keys($nodes);
    return $obj;
  }

  public static function newFromTree(AASTTree $tree) {
    $obj = new AASTNodeList();
    $obj->tree = $tree;
    $obj->list = array(0 => $tree->getRootNode());
    $obj->ids = array(0 => 0);
    return $obj;
  }

  protected function __construct() {}

  public function getDescription() {
    if (empty($this->list)) {
      return 'an empty node list';
    }

    $desc = array();
    $desc[] = 'a list of '.count($this->list).' nodes:';
    foreach ($this->list as $node) {
      $desc[] = '  '.$node->getDescription().';';
    }

    return implode("\n", $desc);
  }



  protected function newList(array $nodes) {
    return AASTNodeList::newFromTreeAndNodes(
      $this->tree,
      $nodes);
  }

  public function selectDescendantsOfType($type_name) {
    $results = array();
    foreach ($this->list as $id => $node) {
      $results += $node->selectDescendantsOfType($type_name)->getRawNodes();
    }
    return $this->newList($results);
  }

  public function selectDescendantsOfTypes(array $type_names) {
    $results = array();
    foreach ($type_names as $type_name) {
      foreach ($this->list as $id => $node) {
        $results += $node->selectDescendantsOfType($type_name)->getRawNodes();
      }
    }
    return $this->newList($results);
  }

  public function getChildrenByIndex($index) {
    $results = array();
    foreach ($this->list as $id => $node) {
      $child = $node->getChildByIndex($index);
      $results[$child->getID()] = $child;
    }
    return $this->newList($results);
  }

  public function add(AASTNodeList $list) {
    foreach ($list->list as $id => $node) {
      $this->list[$id] = $node;
    }
    $this->ids = array_keys($this->list);
    return $this;
  }


  protected function executeSelectDescendantsOfType($node, $type) {
    $results = array();
    foreach ($node->getChildren() as $id => $child) {
      if ($child->getTypeID() == $type) {
        $results[$id] = $child;
      } else {
        $results += $this->executeSelectDescendantsOfType($child, $type);
      }
    }
    return $results;
  }

  public function getTokens() {
    $tokens = array();
    foreach ($this->list as $node) {
      $tokens += $node->getTokens();
    }
    return $tokens;
  }

  public function getRawNodes() {
    return $this->list;
  }

}
