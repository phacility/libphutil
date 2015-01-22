<?php

/**
 * Trap PHP errors while this object is alive, so they can be accessed and
 * included in exceptions or other types of logging. For example, if you have
 * code like this:
 *
 *   $res = proc_open(...);
 *
 * There is no easy way to throw an informative exception if the `proc_open()`
 * fails. In some cases you may be able to use `error_get_last()`, but this is
 * unreliable (if `proc_open()` fails because `disable_functions` is set, it
 * does not capture the error) and can not capture more than one error.
 *
 * You can trap errors while executing this code instead:
 *
 *   $trap = new PhutilErrorTrap();
 *     $res = proc_open(...);
 *     $err = $trap->getErrorsAsString();
 *   $trap->destroy();
 *
 *   if (!$res) {
 *     throw new Exception('proc_open() failed: '.$err);
 *   }
 *
 * IMPORTANT: You must explicitly destroy traps because they register
 * themselves with @{class:PhutilErrorHandler}, and thus will not be destroyed
 * when `unset()`.
 *
 * Some notes on traps:
 *
 *   - Traps catch all errors, including those silenced by `@`.
 *   - Traps do not prevent errors from reaching other standard handlers. You
 *     can use `@` to keep errors out of the logs while still trapping them.
 *   - Traps capture all errors until they are explicitly destroyed. This means
 *     that you should not create long-lived traps, or they may consume
 *     unbounded amounts of memory to hold the error log.
 */
final class PhutilErrorTrap extends Phobject {

  private $destroyed;
  private $errors = array();

  public function addError($num, $str, $file, $line, $ctx) {
    $this->errors[] = array(
      'num' => $num,
      'str' => $str,
      'file' => $file,
      'line' => $line,
      'ctx' => $ctx,
    );
    return $this;
  }

  public function getErrorsAsString() {
    $out = array();
    foreach ($this->errors as $error) {
      $out[] = $error['str'];
    }
    return implode("\n", $out);
  }

  public function destroy() {
    if (!$this->destroyed) {
      PhutilErrorHandler::removeErrorTrap($this);
      $this->errors = array();
      $this->destroyed = true;
    }
  }

  public function getTrapKey() {
    return spl_object_hash($this);
  }

  public function __construct() {
    PhutilErrorHandler::addErrorTrap($this);
  }

  public function __toString() {
    return $this->getErrorsAsString();
  }

}
