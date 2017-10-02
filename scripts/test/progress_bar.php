#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->parseStandardArguments();

echo pht(
  "PROGRESS BAR TEST SCRIPT\n\n".
  "This script is a test script for `%s`. It will draw some progress bars, ".
  "and generally allow you to test bar behaviors and changes.",
  'PhutilConsoleProgressBar');
echo "\n\n";
echo pht(
  "GENERAL NOTES\n\n".
  "  - When run as `%s`, no progress bars should be shown ".
  "(stderr is not a tty).\n".
  "  - When run in a narrow terminal, the bar should resize automatically ".
  "to fit the terminal.\n".
  "  - When run with `%s`, the bar should not be drawn.\n",
  'php -f progress_bar.php 2>&1 | more',
  '--trace');
echo "\n\n";

echo pht('STANDARD PROGRESS BAR')."\n";
$n = 80;
$bar = id(new PhutilConsoleProgressBar())
  ->setTotal($n);
for ($ii = 0; $ii < $n; $ii++) {
  $bar->update(1);
  usleep(10000);
}
$bar->done();

echo "\n".pht(
  "INTERRUPTED PROGRESS BAR\n".
  "This bar will be interrupted by an exception.\n".
  "It should clean itself up.")."\n";
try {
  run_interrupt_bar();
} catch (Exception $ex) {
  echo pht('Caught exception!')."\n";
}

echo "\n".pht(
  "RESIZING BARS\n".
  "If you resize the window while a progress bars draws, it should more or ".
  "less detect the change.");

$n = 1024;
$bar = id(new PhutilConsoleProgressBar())
  ->setTotal($n);
for ($ii = 0; $ii < $n; $ii++) {
  $bar->update(1);
  usleep(10000);
}
$bar->done();

function run_interrupt_bar() {
  $bar = id(new PhutilConsoleProgressBar())
    ->setTotal(100);

  for ($ii = 0; $ii < 100; $ii++) {
    if ($ii === 20) {
      throw new Exception(pht('Boo!'));
    }
    $bar->update(1);
    usleep(10000);
  }
}
