<?php

/**
 * An abstract abstract syntax tree.
 */
abstract class AASTTree extends Phobject {

  protected $tree = array();
  protected $stream = array();
  protected $lineMap;
  protected $rawSource;

  private $treeType = 'Abstract';
  private $tokenConstants;
  private $tokenReverseMap;
  private $nodeConstants;
  private $nodeReverseMap;

  abstract public function newNode($id, array $data, AASTTree $tree);
  abstract public function newToken(
    $id,
    $type,
    $value,
    $offset,
    AASTTree $tree);

  public function __construct(array $tree, array $stream, $source) {
    $ii = 0;
    $offset = 0;

    foreach ($stream as $token) {
      $this->stream[$ii] = $this->newToken(
        $ii,
        $token[0],
        substr($source, $offset, $token[1]),
        $offset,
        $this);
      $offset += $token[1];
      ++$ii;
    }

    $this->rawSource = $source;
    $this->buildTree(array($tree));
  }

  final public function setTreeType($description) {
    $this->treeType = $description;
    return $this;
  }

  final public function getTreeType() {
    return $this->treeType;
  }

  final public function setTokenConstants(array $token_map) {
    $this->tokenConstants = $token_map;
    $this->tokenReverseMap = array_flip($token_map);
    return $this;
  }

  final public function setNodeConstants(array $node_map) {
    $this->nodeConstants = $node_map;
    $this->nodeReverseMap = array_flip($node_map);
    return $this;
  }

  final public function getNodeTypeNameFromTypeID($type_id) {
    if (empty($this->nodeConstants[$type_id])) {
      $tree_type = $this->getTreeType();
      throw new Exception(
        pht(
          "No type name for node type ID '%s' in '%s' AAST.",
          $type_id,
          $tree_type));
    }

    return $this->nodeConstants[$type_id];
  }

  final public function getNodeTypeIDFromTypeName($type_name) {
    if (empty($this->nodeReverseMap[$type_name])) {
      $tree_type = $this->getTreeType();
      throw new Exception(
        pht(
          "No type ID for node type name '%s' in '%s' AAST.",
          $type_name,
          $tree_type));
    }
    return $this->nodeReverseMap[$type_name];
  }

  final public function getTokenTypeNameFromTypeID($type_id) {
    if (empty($this->tokenConstants[$type_id])) {
      $tree_type = $this->getTreeType();
      throw new Exception(
        pht(
          "No type name for token type ID '%s' in '%s' AAST.",
          $type_id,
          $tree_type));
    }
    return $this->tokenConstants[$type_id];
  }

  final public function getTokenTypeIDFromTypeName($type_name) {
    if (empty($this->tokenReverseMap[$type_name])) {
      $tree_type = $this->getTreeType();
      throw new Exception(
        pht(
          "No type ID for token type name '%s' in '%s' AAST.",
          $type_name,
          $tree_type));
    }
    return $this->tokenReverseMap[$type_name];
  }

  /**
   * Unlink internal datastructures so that PHP will garbage collect the tree.
   *
   * This renders the object useless.
   *
   * @return void
   */
  public function dispose() {
    $this->getRootNode()->dispose();
    unset($this->tree);
    unset($this->stream);
  }

  final public function getRootNode() {
    return $this->tree[0];
  }

  protected function buildTree(array $tree) {
    $ii = count($this->tree);
    $nodes = array();
    foreach ($tree as $node) {
      $this->tree[$ii] = $this->newNode($ii, $node, $this);
      $nodes[$ii] = $node;
      ++$ii;
    }
    foreach ($nodes as $node_id => $node) {
      if (isset($node[3])) {
        $children = $this->buildTree($node[3]);
        $previous_child = null;

        foreach ($children as $ii => $child) {
          $child->setParentNode($this->tree[$node_id]);
          $child->setPreviousSibling($previous_child);

          if ($previous_child) {
            $previous_child->setNextSibling($child);
          }

          $previous_child = $child;
        }

        if ($previous_child) {
          $previous_child->setNextSibling($child);
        }

        $this->tree[$node_id]->setChildren($children);
      }
    }

    $result = array();
    foreach ($nodes as $key => $node) {
      $result[$key] = $this->tree[$key];
    }

    return $result;
  }

  final public function getRawTokenStream() {
    return $this->stream;
  }

  public function getOffsetToLineNumberMap() {
    if ($this->lineMap === null) {
      $src = $this->rawSource;
      $len = strlen($src);
      $lno = 1;
      $map = array();
      for ($ii = 0; $ii < $len; ++$ii) {
        $map[$ii] = $lno;
        if ($src[$ii] == "\n") {
          ++$lno;
        }
      }
      $this->lineMap = $map;
    }
    return $this->lineMap;
  }

}
