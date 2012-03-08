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
final class XHPASTToken extends AASTToken {

  public function getTypeName() {
    if (empty($this->typeName)) {
      $type_id = $this->typeID;
      if ($type_id <= 255) {
        $this->typeName = chr($type_id);
      }
      $this->typeName = parent::getTypeName($type_id);
    }
    return $this->typeName;
  }

  public function isComment() {
    static $type_ids = null;
    if ($type_ids === null) {
      $type_ids = array(
        $this->tree->getTokenTypeIDFromTypeName('T_COMMENT')      => true,
        $this->tree->getTokenTypeIDFromTypeName('T_DOC_COMMENT')  => true,
      );
    }

    return isset($type_ids[$this->typeID]);
  }

  public function isAnyWhitespace() {
    static $type_ids = null;
    if ($type_ids === null) {
      $type_ids = array(
        $this->tree->getTokenTypeIDFromTypeName('T_WHITESPACE') => true,
      );
    }

    return isset($type_ids[$this->typeID]);
  }

}
