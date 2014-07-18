#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->parseStandardArguments();

echo "PROGRESS BAR TEST SCRIPT\n\n";
echo "This script is a test script for `PhutilConsoleProgressBar`. It will ".
     "draw some progress bars, and generally allow you to test bar behaviors ".
     "and changes.\n\n";

echo "GENERAL NOTES\n\n";
echo "  - When run as `php -f progress_bar.php 2>&1 | more`, no progress bars ".
     "should be shown (stderr is not a tty).\n";
echo "  - When run in a narrow terminal, the bar should resize automatically ".
     "to fit the terminal.\n";
echo "  - When run with `--trace`, the bar should not be drawn.\n";
echo "\n\n";

echo "STANDARD PROGRESS BAR\n";
$n = 80;
$bar = id(new PhutilConsoleProgressBar())
  ->setTotal($n);
for ($ii = 0; $ii < $n; $ii++) {
  $bar->update(1);
  usleep(10000);
}
$bar->done();

echo "\n";
echo "INTERRUPTED PROGRESS BAR\n";
echo "This bar will be interrupted by an exception.\n";
echo "It should clean itself up.\n";
try {
  run_interrupt_bar();
} catch (Exception $ex) {
  echo "Caught exception!\n";
}


function run_interrupt_bar() {
  $bar = id(new PhutilConsoleProgressBar())
    ->setTotal(100);

  for ($ii = 0; $ii < 100; $ii++) {
    if ($ii === 20) {
      throw new Exception('Boo!');
    }
    $bar->update(1);
    usleep(10000);
  }
}
