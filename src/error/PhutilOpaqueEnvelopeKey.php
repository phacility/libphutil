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
 * Holds the key for @{class:PhutilOpaqueEnvelope} in a logically distant
 * location so it will never appear in stack traces, etc. You should never need
 * to use this class directly. See @{class:PhutilOpaqueEnvelope} for
 * information about opaque envelopes.
 *
 * @task internal Internals
 */
final class PhutilOpaqueEnvelopeKey {

  private static $key;


/* -(  Internals  )---------------------------------------------------------- */


  /**
   * @task internal
   */
  private function __construct() {
    // <private>
  }


  /**
   * @task internal
   */
  public static function getKey() {
    if (self::$key === null) {
      try {
        self::$key = Filesystem::readRandomBytes(128);
      } catch (Exception $ex) {

        // NOTE: We can't throw here! Otherwise we might get a stack trace
        // including the string that was passed to PhutilOpaqueEnvelope's
        // constructor. Just die() instead.

        die(
          "Unable to read random bytes in PhutilOpaqueEnvelope. (This ".
          "causes an immediate process exit to avoid leaking the envelope ".
          "contents in a stack trace.)");
      }
    }
    return self::$key;
  }

}
