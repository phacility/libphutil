<?php

/**
 * Signal handler for SIGHUP which prints the current backtrace out to a
 * file. This is particularly helpful in debugging hung/spinning processes.
 */
final class PhutilBacktraceSignalHandler extends PhutilSignalHandler {

  public function canHandleSignal(PhutilSignalRouter $router, $signo) {
    return ($signo === SIGHUP);
  }

  public function handleSignal(PhutilSignalRouter $router, $signo) {
    $e = new Exception();
    $pid = getmypid();
    // Some Phabricator daemons may not be attached to a terminal.
    Filesystem::writeFile(
      sys_get_temp_dir().'/phabricator_backtrace_'.$pid,
      $e->getTraceAsString());
  }

}
