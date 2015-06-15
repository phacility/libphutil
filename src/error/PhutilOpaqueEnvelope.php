<?php

/**
 * Opaque reference to a string (like a password) that won't put any sensitive
 * data in stack traces, var_dump(), print_r(), error logs, etc. Usage:
 *
 *   $envelope = new PhutilOpaqueEnvelope($password);
 *   do_stuff($envelope);
 *   // ...
 *   $password = $envelope->openEnvelope();
 *
 * Any time you're passing sensitive data into a stack, you should obscure it
 * with an envelope to prevent it leaking if something goes wrong.
 *
 * The key for the envelope is stored elsewhere, in
 * @{class:PhutilOpaqueEnvelopeKey}. This prevents it from appearing in
 * any sort of logs related to the envelope, even if the logger is very
 * aggressive.
 *
 * @task envelope Using Opaque Envelopes
 * @task internal Internals
 */
final class PhutilOpaqueEnvelope extends Phobject {

  private $value;


/* -(  Using Opaque Envelopes  )--------------------------------------------- */


  /**
   * @task envelope
   */
  public function __construct($string) {
    $this->value = $this->mask($string, PhutilOpaqueEnvelopeKey::getKey());
  }


  /**
   * @task envelope
   */
  public function openEnvelope() {
    return $this->mask($this->value, PhutilOpaqueEnvelopeKey::getKey());
  }


  /**
   * @task envelope
   */
  public function __toString() {
    return pht('<opaque envelope>');
  }


/* -(  Internals  )---------------------------------------------------------- */


  /**
   * @task internal
   */
  private function mask($string, $noise) {
    $result = '';
    for ($ii = 0; $ii < strlen($string); $ii++) {
      $s = $string[$ii];
      $n = $noise[$ii % strlen($noise)];

      $result .= chr(ord($s) ^ ord($n));
    }
    return $result;
  }

}
