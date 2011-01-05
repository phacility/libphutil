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

class PhutilRemarkupEngineRemarkupHeaderBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getBlockPattern() {
    return '/^(={1,5})(.*?)\\1?\s*$/';
  }

  public function shouldMergeBlocks() {
    return false;
  }

  public function markupText($text) {
    $level = 1;
    for ($ii = 0; $ii < min(5, strlen($text)); $ii++) {
      if ($text[$ii] == '=') {
        ++$level;
      }
    }
    $text = trim($text, ' =');

    return '<h'.$level.'>'.$this->applyRules($text).'</h'.$level.'>';
  }

}
