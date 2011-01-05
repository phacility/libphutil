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

final class PhutilRemarkupBlockStorage {

  private $map = array();
  private $index;

  public function store($token) {
    $key = "~".(++$this->index)."%";
    $this->map[$key] = $token;
    return $key;
  }

  public function restore($corpus) {
    if ($this->map) {
      $corpus = str_replace(
        array_reverse(array_keys($this->map)),
        array_reverse($this->map),
        $corpus);
      $this->map = array();
    }
    return $corpus;
  }

}
