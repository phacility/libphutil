<?php

final class PhutilConsoleMetricsSignalHandler extends PhutilSignalHandler {

  public function canHandleSignal(PhutilSignalRouter $router, $signo) {
    return ($signo === SIGWINCH);
  }

  public function handleSignal(PhutilSignalRouter $router, $signo) {
    PhutilConsoleMetrics::getDefaultConsole()
      ->didGetWINCHSignal();
  }

}
