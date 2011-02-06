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
 * @group xhpast
 */
class XHPASTNode {

  protected $id;
  protected $l;
  protected $r;
  protected $typeID;
  protected $children = array();
  protected $tree;
  protected $parentNode;

  public function __construct($id, array $data, XHPASTTree $tree) {
    $this->id = $id;
    $this->typeID = $data[0];
    $this->l = idx($data, 1, -1);
    $this->r = idx($data, 2, -1);
    $this->tree = $tree;
  }

  public function setParentNode($parent_node) {
    $this->parentNode = $parent_node;
    return $this;
  }

  public function getParentNode() {
    return $this->parentNode;
  }

  public function setChildren(array $children) {
    $this->children = $children;
    return $this;
  }

  public function getID() {
    return $this->id;
  }

  public function getTypeID() {
    return $this->typeID;
  }

  public function getTypeName() {
    static $map;
    if (empty($map)) {
      $map = xhp_parser_node_constants();
    }

    $type_id = $this->getTypeID();
    if (empty($map[$type_id])) {
      throw new Exception("No type name for node type ID '{$type_id}'.");
    }

    return $map[$type_id];
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
    return XHPASTNodeList::newFromTreeAndNodes(
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
    static $node_types;
    if (empty($node_types)) {
      $node_types = xhp_parser_node_constants();
      $node_types = array_flip($node_types);
    }

    if (empty($node_types[$type_name])) {
      throw new Exception("Unknown XHPAST Node type name '{$type_name}'!");
    }

    return $node_types[$type_name];
  }

  public function getOffset() {
    $first_token = idx($this->tree->getRawTokenStream(), $this->l);
    if (!$first_token) {
      return null;
    }
    return $first_token->getOffset();
  }

  public function isStaticScalar() {
    return ($this->getTypeName() == 'n_STRING_SCALAR' ||
            $this->getTypeName() == 'n_NUMERIC_SCALAR');
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

  public function getDocblockToken() {
    if ($this->l == -1) {
      return null;
    }
    $tokens = $this->tree->getRawTokenStream();

    for ($ii = $this->l - 1; $ii >= 0; $ii--) {
      if ($tokens[$ii]->getTypeName() == 'T_DOC_COMMENT') {
        return $tokens[$ii];
      }
      if (!$tokens[$ii]->isAnyWhitespace()) {
        return null;
      }
    }

    return null;
  }

  public function evalStatic() {
    switch ($this->getTypeName()) {
      case 'n_STATEMENT':
        return $this->getChildByIndex(0)->evalStatic();
        break;
      case 'n_STRING_SCALAR':
        return (string)$this->getStringLiteralValue();
      case 'n_NUMERIC_SCALAR':
        $value = $this->getSemanticString();
        if (preg_match('/^0x/i', $value)) {
          // Hex
          return (int)base_convert(substr($value, 2), 16, 10);
        } else if (preg_match('/^0\d+$/i', $value)) {
          // Octal
          return (int)base_convert(substr($value, 1),  8, 10);
        } else if (preg_match('/^\d+$/', $value)) {
          return (int)$value;
        } else {
          return (double)$value;
        }
        break;
      case 'n_SYMBOL_NAME':
        $value = $this->getSemanticString();
        if ($value == 'INF') {
          return INF;
        }
        switch (strtolower($value)) {
          case 'true':
            return true;
          case 'false':
            return false;
          case 'null':
            return null;
          default:
            throw new Exception('Unrecognized symbol name.');
        }
        break;
      case 'n_UNARY_PREFIX_EXPRESSION':
        $operator = $this->getChildOfType(0, 'n_OPERATOR');
        $operand = $this->getChildByIndex(1);
        switch ($operator->getSemanticString()) {
          case '-':
            return -$operand->evalStatic();
            break;
          case '+':
            return $operand->evalStatic();
            break;
          default:
            throw new Exception("Unexpected operator in static expression.");
        }
        break;
      case 'n_ARRAY_LITERAL':
        $result = array();
        $values = $this->getChildOfType(0, 'n_ARRAY_VALUE_LIST');
        foreach ($values->getChildren() as $child) {
          $key = $child->getChildByIndex(0);
          $val = $child->getChildByIndex(1);
          if ($key->getTypeName() == 'n_EMPTY') {
            $result[] = $val->evalStatic();
          } else {
            $result[$key->evalStatic()] = $val->evalStatic();
          }
        }
        return $result;
      default:
        throw new Exception("Unexpected node.");
    }
  }

  public function getStringLiteralValue() {
    if ($this->getTypeName() != 'n_STRING_SCALAR') {
      return null;
    }

    $value = $this->getSemanticString();
    $type  = $value[0];
    $value = substr($value, 1, -1);
    $esc   = false;
    $len   = strlen($value);
    $out   = '';

    if ($type == "'") {
      // Single quoted strings treat everything as a literal except "\\" and
      // "\'".
      return str_replace(
        array('\\\\', '\\\''),
        array('\\',   "'"),
        $value);
    }

    // Double quoted strings treat "\X" as a literal if X isn't specifically
    // a character which needs to be escaped -- e.g., "\q" and "\'" are
    // literally "\q" and "\'". stripcslashes() is too aggressive, so find
    // all these under-escaped backslashes and escape them.

    for ($ii = 0; $ii < $len; $ii++) {
      $c = $value[$ii];
      if ($esc) {
        $esc = false;
        switch ($c) {
          case 'x':
            $u = isset($value[$ii + 1]) ? $value[$ii + 1] : null;
            if (!preg_match('/^[a-z0-9]/i', $u)) {
              // PHP treats \x followed by anything which is not a hex digit
              // as a literal \x.
              $out .= '\\\\'.$c;
              break;
            }
          case 'n':
          case 'r':
          case 'f':
          case 'v':
          case '"':
          case '$':
          case 't':
          case '0':
          case '1':
          case '2':
          case '3':
          case '4':
          case '5':
          case '6':
          case '7':
            $out .= '\\'.$c;
            break;
          default:
            $out .= '\\\\'.$c;
            break;
        }
      } else if ($c == '\\') {
        $esc = true;
      } else {
        $out .= $c;
      }
    }

    return stripcslashes($out);
  }

  public function getLineNumber() {
    return idx($this->tree->getOffsetToLineNumberMap(), $this->getOffset());
  }


}
