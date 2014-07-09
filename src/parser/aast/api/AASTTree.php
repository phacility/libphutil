<?php

/**
 * An abstract abstract syntax tree.
 */
abstract class AASTTree {

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

  public function setTreeType($description) {
    $this->treeType = $description;
    return $this;
  }

  public function getTreeType() {
    return $this->treeType;
  }

  public function setTokenConstants(array $token_map) {
    $this->tokenConstants = $token_map;
    $this->tokenReverseMap = array_flip($token_map);
    return $this;
  }

  public function setNodeConstants(array $node_map) {
    $this->nodeConstants = $node_map;
    $this->nodeReverseMap = array_flip($node_map);
    return $this;
  }

  public function getNodeTypeNameFromTypeID($type_id) {
    if (empty($this->nodeConstants[$type_id])) {
      $tree_type = $this->getTreeType();
      throw new Exception(
        "No type name for node type ID '{$type_id}' in '{$tree_type}' AAST.");
    }

    return $this->nodeConstants[$type_id];
  }

  public function getNodeTypeIDFromTypeName($type_name) {
    if (empty($this->nodeReverseMap[$type_name])) {
      $tree_type = $this->getTreeType();
      throw new Exception(
        "No type ID for node type name '{$type_name}' in '{$tree_type}' AAST.");
    }
    return $this->nodeReverseMap[$type_name];
  }


  public function getTokenTypeNameFromTypeID($type_id) {
    if (empty($this->tokenConstants[$type_id])) {
      $tree_type = $this->getTreeType();
      throw new Exception(
        "No type name for token type ID '{$type_id}' ".
        "in '{$tree_type}' AAST.");
    }
    return $this->tokenConstants[$type_id];
  }

  public function getTokenTypeIDFromTypeName($type_name) {
    if (empty($this->tokenReverseMap[$type_name])) {
      $tree_type = $this->getTreeType();
      throw new Exception(
        "No type ID for token type name '{$type_name}' ".
        "in '{$tree_type}' AAST.");
    }
    return $this->tokenReverseMap[$type_name];
  }


  /**
   * Unlink internal datastructures so that PHP's will garbage collect the tree.
   * This renders the object useless.
   *
   * @return void
   */
  public function dispose() {
    $this->getRootNode()->dispose();
    unset($this->tree);
    unset($this->stream);
  }

  public function getRootNode() {
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
        foreach ($children as $child) {
          $child->parentNode = $this->tree[$node_id];
        }
        $this->tree[$node_id]->children = $children;
      }
    }

    $result = array();
    foreach ($nodes as $key => $node) {
      $result[$key] = $this->tree[$key];
    }

    return $result;
  }

  public function getRawTokenStream() {
    return $this->stream;
  }

  public function renderAsText() {
    return $this->executeRenderAsText(array($this->getRootNode()), 0);
  }

  protected function executeRenderAsText($list, $depth) {
    $return = '';
    foreach ($list as $node) {
      if ($depth) {
        $return .= str_repeat('  ', $depth);
      }
      $return .= $node->getDescription()."\n";
      $return .= $this->executeRenderAsText($node->getChildren(), $depth + 1);
    }
    return $return;
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
