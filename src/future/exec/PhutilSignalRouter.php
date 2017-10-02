<?php

final class PhutilSignalRouter extends Phobject {

  private $handlers = array();
  private static $router;

  private function __construct() {
    // <private>
  }

  public static function initialize() {
    if (!self::$router) {
      $router = new self();

      // If pcntl_signal() does not exist (particularly, on Windows), just
      // don't install signal handlers.
      if (function_exists('pcntl_signal')) {
        pcntl_signal(SIGHUP, array($router, 'routeSignal'));
        pcntl_signal(SIGTERM, array($router, 'routeSignal'));
        pcntl_signal(SIGWINCH, array($router, 'routeSignal'));
      }

      self::$router = $router;
    }

    return self::getRouter();
  }

  public static function getRouter() {
    if (!self::$router) {
      throw new Exception(pht('Signal router has not been initialized!'));
    }

    return self::$router;
  }

  public function installHandler($key, PhutilSignalHandler $handler) {
    if (isset($this->handlers[$key])) {
      throw new Exception(
        pht(
          'Signal handler with key "%s" is already installed.',
          $key));
    }

    $this->handlers[$key] = $handler;

    return $this;
  }

  public function getHandler($key) {
    return idx($this->handlers, $key);
  }

  public function routeSignal($signo) {
    $exceptions = array();

    $handlers = $this->handlers;
    foreach ($handlers as $key => $handler) {
      try {
        if ($handler->canHandleSignal($this, $signo)) {
          $handler->handleSignal($this, $signo);
        }
      } catch (Exception $ex) {
        $exceptions[] = $ex;
      }
    }

    if ($exceptions) {
      throw new PhutilAggregateException(
        pht(
          'Signal handlers raised exceptions while handling "%s".',
          phutil_get_signal_name($signo)),
        $exceptions);
    }

    switch ($signo) {
      case SIGTERM:
        // Normally, PHP doesn't invoke destructors when exiting in response to
        // a signal. This forces it to do so, so we have a fighting chance of
        // releasing any locks, leases or resources on our way out.
        exit(128 + $signo);
    }
  }

}
