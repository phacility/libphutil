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

final class PhutilPHPObjectProtocolChannelTestCase extends PhutilTestCase {

  public function testPHPObjectChannelBasics() {
    list($x, $y) = PhutilSocketChannel::newChannelPair();
    $xp = new PhutilPHPObjectProtocolChannel($x);
    $yp = new PhutilPHPObjectProtocolChannel($y);

    $object = (object)array(
      'key' => mt_rand(),
    );

    $xp->write($object);
    $xp->flush();
    $result = $yp->waitForMessage();

    $this->assertEqual(
      true,
      (array)$object === (array)$result,
      "Values are identical.");

    $this->assertEqual(
      false,
      $object === $result,
      "Objects are not the same.");
  }

}
