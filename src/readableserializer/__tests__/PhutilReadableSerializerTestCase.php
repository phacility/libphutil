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

final class PhutilReadableSerializerTestCase extends PhutilTestCase {

  public function testPrintableValue() {
    $tests = array(
      array(null, 'null'),
      array(true, 'true'),
      array(false, 'false'),
      array(0, '0'),
      array(0.0, '0.0'),
      array(0.1, '0.1'),
      array('test', 'test'),
    );
    foreach ($tests as $test) {
      list($value, $expect) = $test;
      $this->assertEqual(
        $expect,
        PhutilReadableSerializer::printableValue($value));
    }
  }

}
