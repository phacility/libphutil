#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->setTagline(pht('acquire and hold a lockfile'));
$args->setSynopsis(<<<EOHELP
**lock.php** __file__ [__options__]
    Acquire a lockfile and hold it until told to unlock it.

EOHELP
);

$args->parseStandardArguments();
$args->parse(array(
  array(
    'name'      => 'test',
    'help'      => pht('Instead of holding the lock, release it and exit.'),
  ),
  array(
    'name'      => 'hold',
    'help'      => pht('Hold indefinitely without prompting.'),
  ),
  array(
    'name'      => 'wait',
    'param'     => 'n',
    'help'      => pht('Block for up to __n__ seconds waiting for the lock.'),
    'default'   => 0,
  ),
  array(
    'name'      => 'file',
    'wildcard'  => true,
  ),
));


$file = $args->getArg('file');
if (count($file) !== 1) {
  $args->printHelpAndExit();
}
$file = head($file);

$console = PhutilConsole::getConsole();
$console->writeOut(
  "%s\n",
  pht('This process has PID %d. Acquiring lock...', getmypid()));

$lock = PhutilFileLock::newForPath($file);

try {
  $lock->lock($args->getArg('wait'));
} catch (PhutilFileLockException $ex) {
  $console->writeOut(
    "**%s** %s\n",
    pht('UNABLE TO ACQUIRE LOCK:'),
    pht('Lock is already held.'));
  exit(1);
}

// NOTE: This string is magic, the unit tests look for it.
$console->writeOut("%s\n", pht('LOCK ACQUIRED'));
if ($args->getArg('test')) {
  $lock->unlock();
  exit(0);
}

if ($args->getArg('hold')) {
  while (true) {
    sleep(1);
  }
}

while (!$console->confirm(pht('Release lock?'))) {
  // Keep asking until they say yes.
}

$console->writeOut("%s\n", pht('Unlocking...'));
$lock->unlock();

$console->writeOut("%s\n", pht('Done.'));
exit(0);
