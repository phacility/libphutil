<?php

/**
 * Show a progress bar on the console. Usage:
 *
 *   // Create a progress bar, and configure the total amount of work that
 *   // needs to be done.
 *   $bar = id(new PhutilConsoleProgressBar())
 *     ->setTotal(count($stuff));
 *
 *   // As you complete the work, update the progress bar.
 *   foreach ($stuff as $thing) {
 *     do_stuff($thing);
 *     $bar->update(1);
 *   }
 *
 *   // When complete, mark the work done to clear the bar.
 *   $bar->done();
 *
 * The progress bar attempts to account for various special cases, notably:
 *
 *   - If stderr is not a TTY, the bar will not be drawn (for example, if
 *     it is being piped to a log file).
 *   - If the Phutil log output is enabled (usually because `--trace` was
 *     specified), the bar will not be drawn.
 *   - The bar will be resized to the width of the console if possible.
 *
 */
final class PhutilConsoleProgressBar extends Phobject {

  private $work;
  private $done;
  private $drawn;
  private $console;
  private $finished;
  private $lastUpdate;
  private $quiet = false;

  public function setConsole(PhutilConsole $console) {
    $this->console = $console;
    return $this;
  }

  private function getConsole() {
    if ($this->console) {
      return $this->console;
    }
    return PhutilConsole::getConsole();
  }

  public function setTotal($work) {
    $this->work = $work;
    $this->redraw();
    return $this;
  }

  public function setQuiet($quiet) {
    $this->quiet = $quiet;
    return $this;
  }

  public function update($work) {
    $this->done += $work;
    $this->redraw();
    return $this;
  }

  private function redraw() {
    if ($this->lastUpdate + 0.1 > microtime(true)) {
      // We redrew the bar very recently; skip this update.
      return $this;
    }

    return $this->draw();
  }


  /**
   * Explicitly redraw the bar.
   *
   * Normally, the progress bar is automatically redrawn periodically, but
   * you may want to force it to draw.
   *
   * For example, we force a draw after pre-filling the bar when resuming
   * large file uploads in `arc upload`. Otherwise, the bar may sit at 0%
   * until the first chunk completes.
   */
  public function draw() {
    if ($this->quiet) {
      return;
    }

    if ($this->finished) {
      return;
    }

    if (!$this->work) {
      // There's no work to be done, so don't draw the bar.
      return;
    }

    $console = $this->getConsole();
    if ($console->isErrATTY() === false) {
      return;
    }

    if ($console->isLogEnabled()) {
      return;
    }

    // Width of the stuff other than the progress bar itself.
    $chrome_width = strlen('[] 100.0%   ');

    $char_width = $this->getWidth();
    if ($char_width < $chrome_width) {
      return;
    }

    $this->lastUpdate = microtime(true);

    if (!$this->drawn) {
      $this->drawn = true;
    }

    $percent = $this->done / $this->work;

    $max_width = $char_width - $chrome_width;
    $bar_width = $percent * $max_width;
    $bar_int = floor($bar_width);
    $bar_frac = $bar_width - $bar_int;

    $frac_map = array(
      '',
      '-',
      '~',
    );
    $frac_char = $frac_map[floor($bar_frac * count($frac_map))];

    $pattern = "[%-{$max_width}.{$max_width}s] % 5s%%";
    $out = sprintf(
      $pattern,
      str_repeat('=', $bar_int).$frac_char,
      sprintf('%.1f', 100 * $percent));

    $this->eraseLine();
    $console->writeErr('%s', $out);

    return $this;
  }

  public function done($clean_exit = true) {
    $console = $this->getConsole();
    if ($this->drawn) {
      $this->eraseLine();
      if ($clean_exit) {
        $console->writeErr("%s\n", pht('Done.'));
      }
    }
    $this->finished = true;
  }

  private function eraseLine() {
    $string = str_repeat(' ', $this->getWidth());

    $console = $this->getConsole();
    $console->writeErr("\r%s\r", $string);
  }

  private function getWidth() {
    $console = $this->getConsole();
    $width = $console->getErrCols();
    return min(nonempty($width, 78), 78);
  }

  public function __destruct() {
    $this->done($clean_exit = false);
  }

}
