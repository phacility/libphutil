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
 * @group xhpast
 */
abstract class AASTToken {

  protected $id;
  protected $typeID;
  protected $value;
  protected $offset;
  protected $tree;

  public function __construct($id, $type, $value, $offset, AASTTree $tree) {
    $this->id = $id;
    $this->typeID = $type;
    $this->offset = $offset;
    $this->value = $value;
    $this->tree = $tree;
  }

  public function getTypeID() {
    return $this->typeID;
  }

  public function getTypeName() {
    if (empty($this->typeName)) {
      $this->typeName = $this->tree->getTokenTypeNameFromTypeID($this->typeID);
    }
    return $this->typeName;
  }

  public function getValue() {
    return $this->value;
  }

  public function getOffset() {
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


}
