<?php

abstract class AASTToken extends Phobject {

  protected $id;
  protected $typeID;
  protected $typeName;
  protected $value;
  protected $offset;
  protected $tree;

  public function __construct($id, $type, $value, $offset, AASTTree $tree) {
    $this->id = $id;
    $this->typeID = $type;
    $this->value = $value;
    $this->offset = $offset;
    $this->tree = $tree;
  }

  final public function getTokenID() {
    return $this->id;
  }

  final public function getTypeID() {
    return $this->typeID;
  }

  public function getTypeName() {
    if (empty($this->typeName)) {
      $this->typeName = $this->tree->getTokenTypeNameFromTypeID($this->typeID);
    }
    return $this->typeName;
  }

  final public function getValue() {
    return $this->value;
  }

  final public function overwriteValue($value) {
    $this->value = $value;
    return $this;
  }

  final public function getOffset() {
    return $this->offset;
  }

  abstract public function isComment();
  abstract public function isAnyWhitespace();

  public function isSemantic() {
    return !($this->isComment() || $this->isAnyWhitespace());
  }

  public function getPrevToken() {
    $tokens = $this->tree->getRawTokenStream();
    return idx($tokens, $this->id - 1);
  }

  public function getNextToken() {
    $tokens = $this->tree->getRawTokenStream();
    return idx($tokens, $this->id + 1);
  }

  public function getNonsemanticTokensBefore() {
    $tokens = $this->tree->getRawTokenStream();
    $result = array();
    $ii = $this->id - 1;
    while ($ii >= 0 && !$tokens[$ii]->isSemantic()) {
      $result[$ii] = $tokens[$ii];
      --$ii;
    }
    return array_reverse($result);
  }

  public function getNonsemanticTokensAfter() {
    $tokens = $this->tree->getRawTokenStream();
    $result = array();
    $ii = $this->id + 1;
    while ($ii < count($tokens) && !$tokens[$ii]->isSemantic()) {
      $result[$ii] = $tokens[$ii];
      ++$ii;
    }
    return $result;
  }

  final public function getLineNumber() {
    return idx($this->tree->getOffsetToLineNumberMap(), $this->getOffset());
  }

}
