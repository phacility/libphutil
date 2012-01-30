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
 * @group markup
 */
final class PhutilRemarkupEngineRemarkupLiteralBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getBlockPattern() {
    return "/^%%%/";
  }

  public function shouldContinueWithBlock($block, $last_block) {
    // If the first code block begins with %%%, we keep matching blocks until
    // we hit a terminating %%%, regardless of their content.
    if (preg_match($this->getBlockPattern(), $last_block)) {
      if (preg_match('/%%%$/', $last_block)) {
        return false;
      }
      return true;
    }

    return false;
  }

  public function shouldMergeBlocks() {
    return true;
  }

  public function markupText($text) {
    $text = preg_replace('/%%%\s*$/', '', substr($text, 3));
    $text = $this->applyRules($text);
    return $text;
  }
}
