<?php

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
