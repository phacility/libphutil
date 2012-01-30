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
 * @group testcase
 */
final class MFilterTestHelper {

  private $h;
  private $i;
  private $j;

  public function __construct($h_value, $i_value, $j_value) {
    $this->h = $h_value;
    $this->i = $i_value;
    $this->j = $j_value;
  }

  public function getH() {
    return $this->h;
  }

  public function getI() {
    return $this->i;
  }

  public function getJ() {
    return $this->j;
  }

}
