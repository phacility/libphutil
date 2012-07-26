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
 * Example implementation and test case for @{class:PhutilBufferedIterator}.
 *
 * @group util
 */
final class PhutilBufferedIteratorExample extends PhutilBufferedIterator {

  private $cursor;
  private $data;

  protected function didRewind() {
    $this->cursor = 0;
  }

  protected function loadPage() {
    $result = $this->query($this->cursor, $this->getPageSize());
    $this->cursor += count($result);
    return $result;
  }

  public function setExampleData(array $data) {
    $this->data = $data;
  }

  private function query($cursor, $limit) {
    // NOTE: Normally you'd load or generate results from some external source
    // here. Since this is an example, we just use a premade dataset.

    return array_slice($this->data, $cursor, $limit);
  }

}
