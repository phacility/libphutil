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

abstract class PhutilRemarkupEngineBlockRule {

  private $storage;
  private $engine;
  private $rules;

  abstract public function getBlockPattern();
  abstract public function shouldMergeBlocks();
  abstract public function markupText($text);

  final public function setEngine(PhutilRemarkupEngine $engine) {
    $this->engine = $engine;
    return $this;
  }

  final protected function getEngine() {
    return $this->engine;
  }

  public function setMarkupRules(array $rules) {
    $this->rules = $rules;
    return $this;
  }

  final private function getMarkupRules() {
    return $this->rules;
  }

  final protected function applyRules($text) {
    $engine = $this->getEngine();
    foreach ($this->getMarkupRules() as $rule) {
      $rule->setEngine($engine);
      $text = $rule->apply($text);
    }
    return $text;
  }


}
