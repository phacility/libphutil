<?php

/**
 * Holds the key for @{class:PhutilOpaqueEnvelope} in a logically distant
 * location so it will never appear in stack traces, etc. You should never need
 * to use this class directly. See @{class:PhutilOpaqueEnvelope} for
 * information about opaque envelopes.
 *
 * @task internal Internals
 */
final class PhutilOpaqueEnvelopeKey extends Phobject {

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
      // NOTE: We're using a weak random source because cryptographic levels
      // of security aren't terribly important here and it allows us to use
      // envelopes on systems which don't have a strong random source. Notably,
      // this lets us make it to the readability check for `/dev/urandom` in
      // Phabricator on systems where we can't read it.
      self::$key = '';
      for ($ii = 0; $ii < 8; $ii++) {
        self::$key .= md5(mt_rand(), $raw_output = true);
      }
    }
    return self::$key;
  }

}
