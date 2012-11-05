<?php

/**
 * @group aast
 */
abstract class AASTNode {

  protected $id;
  protected $l;
  protected $r;
  protected $typeID;
  protected $tree;

  // These are public only as a microoptimization to make tree construction
  // faster; do not access them directly.
  public $children = array();
  public $parentNode;

  abstract public function isStaticScalar();
  abstract public function getDocblockToken();
  abstract public function evalStatic();
  abstract public function getStringLiteralValue();

  public function __construct($id, array $data, AASTTree $tree) {
    $this->id = $id;
    $this->typeID = $data[0];
    if (isset($data[1])) {
      $this->l = $data[1];
    } else {
      $this->l = -1;
    }
    if (isset($data[2])) {
      $this->r = $data[2];
    } else {
      $this->r = -1;
    }
    $this->tree = $tree;
  }

  public function getParentNode() {
    return $this->parentNode;
  }

  public function getID() {
    return $this->id;
  }

  public function getTypeID() {
    return $this->typeID;
  }

  public function getTypeName() {
    if (empty($this->typeName)) {
      $this->typeName =
        $this->tree->getNodeTypeNameFromTypeID($this->getTypeID());
    }
    return $this->typeName;
  }

  public function getChildren() {
    return $this->children;
  }

  public function getChildOfType($index, $type) {
    $child = $this->getChildByIndex($index);
    if ($child->getTypeName() != $type) {
      throw new Exception(
        "Child in position '{$index}' is not of type '{$type}': ".
        $this->getDescription());
    }

    return $child;
  }

  public function getChildByIndex($index) {
    // NOTE: Microoptimization to avoid calls like array_values() or idx().

    $idx = 0;
    foreach ($this->children as $child) {
      if ($idx == $index) {
        return $child;
      }
      ++$idx;
    }

    throw new Exception("No child with index '{$index}'.");
  }

  /**
   * Build a cache to improve the performance of selectDescendantsOfType(). This
   * cache makes a time/memory tradeoff by aggressively caching node
   * descendants. It may improve the tree's query performance substantially if
   * you make a large number of queries, but also requires a significant amount
   * of memory.
   *
   * This builds a cache for the entire tree and improves performance of all
   * selectDescendantsOfType() calls.
   */
  public function buildSelectCache() {
    $cache = array();
    foreach ($this->getChildren() as $id => $child) {
      $type_id = $child->getTypeID();
      if (empty($cache[$type_id])) {
        $cache[$type_id] = array();
      }
      $cache[$type_id][$id] = $child;
      foreach ($child->buildSelectCache() as $type_id => $nodes) {
        if (empty($cache[$type_id])) {
          $cache[$type_id] = array();
        }
        $cache[$type_id] += $nodes;
      }
    }
    $this->selectCache = $cache;
    return $this->selectCache;
  }

  /**
   * Build a cache to improve the performance of selectTokensOfType(). This
   * cache makes a time/memory tradeoff by aggressively caching token types.
   * It may improve the tree's query performance substantially if you make a
   * large enumber of queries, but also requires a signficant amount of memory.
   *
   * This builds a cache for this node only.
   */
  public function buildTokenCache() {
    $cache = array();
    foreach ($this->getTokens() as $id => $token) {
      $cache[$token->getTypeName()][$id] = $token;
    }
    $this->tokenCache = $cache;
    return $this->tokenCache;
  }


  /**
   * Select all tokens of a given type.
   */
  public function selectTokensOfType($type_name) {
    if (isset($this->tokenCache)) {
      return idx($this->tokenCache, $type_name, array());
    } else {
      $result = array();
      foreach ($this->getTokens() as $id => $token) {
        if ($token->getTypeName() == $type_name) {
          $result[$id] = $token;
        }
      }
      return $result;
    }
  }

  public function selectDescendantsOfType($type_name) {
    $type = $this->getTypeIDFromTypeName($type_name);

    if (isset($this->selectCache)) {
      if (isset($this->selectCache[$type])) {
        $nodes = $this->selectCache[$type];
      } else {
        $nodes = array();
      }
    } else {
      $nodes = $this->executeSelectDescendantsOfType($this, $type);
    }

    return AASTNodeList::newFromTreeAndNodes($this->tree, $nodes);
  }

  protected function executeSelectDescendantsOfType($node, $type) {
    $results = array();
    foreach ($node->getChildren() as $id => $child) {
      if ($child->getTypeID() == $type) {
        $results[$id] = $child;
      }
      $results += $this->executeSelectDescendantsOfType($child, $type);
    }
    return $results;
  }

  public function getTokens() {
    if ($this->l == -1 || $this->r == -1) {
      return array();
    }
    $tokens = $this->tree->getRawTokenStream();
    $result = array();
    foreach (range($this->l, $this->r) as $token_id) {
      $result[$token_id] = $tokens[$token_id];
    }
    return $result;
  }

  public function getConcreteString() {
    $values = array();
    foreach ($this->getTokens() as $token) {
      $values[] = $token->getValue();
    }
    return implode('', $values);
  }

  public function getSemanticString() {
    $tokens = $this->getTokens();
    foreach ($tokens as $id => $token) {
      if ($token->isComment()) {
        unset($tokens[$id]);
      }
    }
    return implode('', mpull($tokens, 'getValue'));
  }

  public function getDescription() {
    $concrete = $this->getConcreteString();
    if (strlen($concrete) > 75) {
      $concrete = substr($concrete, 0, 36).'...'.substr($concrete, -36);
    }

    $concrete = addcslashes($concrete, "\\\n\"");

    return 'a node of type '.$this->getTypeName().': "'.$concrete.'"';
  }

  protected function getTypeIDFromTypeName($type_name) {
    return $this->tree->getNodeTypeIDFromTypeName($type_name);
  }

  public function getOffset() {
    $stream = $this->tree->getRawTokenStream();
    if (empty($stream[$this->l])) {
      return null;
    }
    return $stream[$this->l]->getOffset();
  }

  public function getSurroundingNonsemanticTokens() {
    $before = array();
    $after  = array();

    $tokens = $this->tree->getRawTokenStream();

    if ($this->l != -1) {
      $before = $tokens[$this->l]->getNonsemanticTokensBefore();
    }

    if ($this->r != -1) {
      $after = $tokens[$this->r]->getNonsemanticTokensAfter();
    }

    return array($before, $after);
  }

  public function getLineNumber() {
    return idx($this->tree->getOffsetToLineNumberMap(), $this->getOffset());
  }

  public function dispose() {
    foreach ($this->getChildren() as $child) {
      $child->dispose();
    }

    unset($this->selectCache);
  }

}
