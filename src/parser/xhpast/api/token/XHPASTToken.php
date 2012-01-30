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
    $type_id = $this->getTypeID();

    if ($type_id <= 255) {
      return chr($type_id);
    }

    return parent::getTypeName($type_id);
  }

  public function isComment() {
    return ($this->getTypeName() == 'T_COMMENT' ||
            $this->getTypeName() == 'T_DOC_COMMENT');
  }

  public function isAnyWhitespace() {
    return ($this->getTypeName() == 'T_WHITESPACE' ||
            $this->getTypeName() == 'T_XHP_WHITESPACE');
  }

}
