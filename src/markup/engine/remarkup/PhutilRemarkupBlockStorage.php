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
 * Remarkup prevents several classes of text-processing problems by replacing
 * tokens in the text as they are marked up. For example, if you write something
 * like this:
 *
 *   //D12//
 *
 * It is processed in several stages. First the "D12" matches and is replaced:
 *
 *   //\11Z//
 *
 * Now the italics match and are replaced:
 *
 *   \12Z
 *
 * When processing completes, all the tokens are replaced again in reverse
 * order:
 *
 *   <em>\11Z</em>
 *
 * Then:
 *
 *   <em><a href="http://...">...</a></em>
 *
 * If we didn't do this, the italics rule could match the "//" in "http://",
 * or any other number of processing mistakes could occur, some of which create
 * security risks.
 *
 * This class generates keys, and stores the map of keys to replacement text.
 *
 * @group markup
 */
final class PhutilRemarkupBlockStorage {

  private $map = array();
  private $index;

  public function store($text) {
    $key = "\1".(++$this->index)."Z";
    $this->map[$key] = $text;
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

  public function overwrite($key, $new_text) {
    $this->map[$key] = $new_text;
    return $this;
  }

  public function getMap() {
    return $this->map;
  }

  public function setMap(array $map) {
    $this->map = $map;
    return $this;
  }

}
