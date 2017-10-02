<?php

final class PhutilConsoleMetrics extends Phobject {

  const DEFAULT_CONSOLE = 'default';

  private static $consoles = array();

  private $width = false;

  public static function getNamedConsole($key) {
    if (!isset(self::$consoles[$key])) {
      self::$consoles[$key] = new self();
    }

    return self::$consoles[$key];
  }

  public static function getDefaultConsole() {
    return self::getNamedConsole(self::DEFAULT_CONSOLE);
  }

  public function didGetWINCHSignal() {
    // When we receive a "WINCH" ("WINdow CHange") signal, clear the cached
    // information we have about the terminal.
    $this->width = false;

    return $this;
  }

  public function getTerminalWidth() {
    if ($this->width === false) {
      $this->width = $this->computeTerminalWidth();
    }

    return $this->width;
  }

  private function computeTerminalWidth() {
    if (phutil_is_windows()) {
      // TODO: Figure out how to do this on Windows.
      return null;
    }

    $tmp = new TempFile();

    // NOTE: We can't just execute this because it won't be connected to a TTY
    // if we do.
    $err = id(new PhutilExecPassthru('tput cols > %s', $tmp))
      ->resolve();
    $stdout = Filesystem::readFile($tmp);
    unset($tmp);

    if ($err) {
      return null;
    }

    $width = (int)trim($stdout);
    if ($width > 0) {
      return $width;
    }

    return null;
  }
}
