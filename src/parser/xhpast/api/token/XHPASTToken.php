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

class XHPASTToken {

  protected $id;
  protected $typeID;
  protected $value;
  protected $offset;

  public function __construct($id, $type, $value, $offset, XHPASTTree $tree) {
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
    static $map;
    if (empty($map)) {
      $map = xhpast_parser_token_constants();
    }

    $type_id = $this->getTypeID();

    if ($type_id <= 255) {
      return chr($type_id);
    }

    if (empty($map[$type_id])) {
      throw new Exception("No type name for token type ID '{$type_id}'.");
    }

    return $map[$type_id];
  }

  public function getValue() {
    return $this->value;
  }

  public function getOffset() {
    return $this->offset;
  }

  public function isComment() {
    return ($this->getTypeName() == 'T_COMMENT' ||
            $this->getTypeName() == 'T_DOC_COMMENT');
  }

  public function isAnyWhitespace() {
    return ($this->getTypeName() == 'T_WHITESPACE' ||
            $this->getTypeName() == 'T_XHP_WHITESPACE');
  }

  public function isSemantic() {
    return !($this->isComment() || $this->isAnyWhitespace());
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
