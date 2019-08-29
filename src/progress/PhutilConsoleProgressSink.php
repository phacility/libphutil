<?php

final class PhutilConsoleProgressSink
  extends PhutilProgressSink {

  private $lastUpdate;
  private $isTTY;
  private $width;
  private $lineWidth;

  protected function publishProgress() {
    if (!$this->shouldPublishToConsole()) {
      return;
    }

    $completed = $this->getCompletedWork();
    $total = $this->getTotalWork();

    if ($total !== null) {
      $percent = ($completed / $total);
      $percent = min(1, $percent);
      $percent = max(0, $percent);
    } else {
      $percent = null;
    }

    // TODO: In TTY mode, draw a nice ASCII progress bar.

    if ($percent !== null) {
      $marker = sprintf('% 3.1f%%', 100 * $percent);
    } else {
      $marker = sprintf('% 16d', $completed);
    }

    $message = pht('[%s] Working...', $marker);

    if ($this->isTTY()) {
      $this->overwriteLine($message);
    } else {
      $this->printLine($message."\n");
    }

    $this->didPublishToConsole();
  }

  protected function publishCompletion() {
    $this->printLine("\n");
  }

  protected function publishFailure() {
    $this->printLine("\n");
  }

  private function shouldPublishToConsole() {
    if (!$this->lastUpdate) {
      return true;
    }

    // Limit the number of times per second we actually write to the console.
    if ($this->isTTY()) {
      $writes_per_second = 5;
    } else {
      $writes_per_second = 0.5;
    }

    $now = microtime(true);
    if (($now - $this->lastUpdate) < (1.0 / $writes_per_second)) {
      return false;
    }

    return true;
  }

  private function didPublishToConsole() {
    $this->lastUpdate = microtime(true);
  }

  private function isTTY() {
    if ($this->isTTY === null) {
      $this->isTTY = (function_exists('posix_isatty') && posix_isatty(STDERR));
    }
    return $this->isTTY;
  }

  private function getWidth() {
    if ($this->width === null) {
      $width = phutil_console_get_terminal_width();
      $width = min(nonempty($width, 78), 78);
      $this->width = $width;
    }

    return $this->width;
  }

  private function overwriteLine($line) {
    $head = "\r";
    $tail = '';

    if ($this->lineWidth) {
      $line_len = strlen($line);

      if ($line_len < $this->lineWidth) {
        $tail = str_repeat(' ', $this->lineWidth - $line_len);
      }

      $this->lineWidth = strlen($line);
    }

    $this->printLine($head.$line.$tail);
  }

  private function printLine($line) {
    fprintf(STDERR, '%s', $line);
  }
}
