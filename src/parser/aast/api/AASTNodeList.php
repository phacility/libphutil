<?php

final class AASTNodeList
  extends Phobject
  implements Countable, Iterator {

  protected $list;
  protected $tree;
  protected $ids;
  protected $pos;

  protected function __construct() {}

  protected function newList(array $nodes) {
    return self::newFromTreeAndNodes($this->tree, $nodes);
  }

  public function selectDescendantsOfType($type_name) {
    return $this->selectDescendantsOfTypes(array($type_name));
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

  public static function newFromTreeAndNodes(AASTTree $tree, array $nodes) {
    // We could do `assert_instances_of($nodes, 'AASTNode')` here, but doing
    // so imposes an observable performance penalty for linting.

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


/* -(  Countable  )---------------------------------------------------------- */

  public function count() {
    return count($this->ids);
  }


/* -(  Iterator  )----------------------------------------------------------- */

  public function current() {
    return $this->list[$this->key()];
  }

  public function key() {
    return $this->ids[$this->pos];
  }

  public function next() {
    $this->pos++;
  }

  public function rewind() {
    $this->pos = 0;
  }

  public function valid() {
    return $this->pos < count($this->ids);
  }

}
