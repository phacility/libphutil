<?php

/*
 * Copyright 2011 Facebook, Inc.
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
    return $this->tree->getNodeTypeNameFromTypeID($this->getTypeID());
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
    $child = idx(array_values($this->children), $index);
    if (!$child) {
      throw new Exception(
        "No child with index '{$index}'.");
    }
    return $child;
  }

  public function selectDescendantsOfType($type_name) {
    $type = $this->getTypeIDFromTypeName($type_name);
    return AASTNodeList::newFromTreeAndNodes(
      $this->tree,
      $this->executeSelectDescendantsOfType($this, $type));
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
    $first_token = idx($this->tree->getRawTokenStream(), $this->l);
    if (!$first_token) {
      return null;
    }
    return $first_token->getOffset();
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

}
