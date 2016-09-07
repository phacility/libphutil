<?php


final class PhutilCallbackSignalHandler extends PhutilSignalHandler {

  private $signal;
  private $callback;

  public function __construct($signal, $callback) {
    $this->signal = $signal;
    $this->callback = $callback;
  }

  public function canHandleSignal(PhutilSignalRouter $router, $signo) {
    return ($signo === $this->signal);
  }

  public function handleSignal(PhutilSignalRouter $router, $signo) {
    call_user_func($this->callback, $signo);
  }

}
