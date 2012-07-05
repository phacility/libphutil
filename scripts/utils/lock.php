#!/usr/bin/env php
<?php

/*
 * Copyright 2012 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

require_once dirname(dirname(__FILE__)).'/__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->setTagline('acquire and hold a lockfile');
$args->setSynopsis(<<<EOHELP
**lock.php** __file__ [__options__]
    Acquire a lockfile and hold it until told to unlock it.

EOHELP
);
$args->parseStandardArguments();
$args->parse(array(
  array(
    'name'      => 'test',
    'help'      => 'Instead of holding the lock, release it and exit.',
  ),
  array(
    'name'      => 'hold',
    'help'      => 'Hold indefinitely without prompting.',
  ),
  array(
    'name'      => 'wait',
    'param'     => 'n',
    'help'      => 'Block for up to __n__ seconds waiting for the lock.',
    'default'   => 0,
  ),
  array(
    'name'      => 'file',
    'wildcard'  => true,
  ),
));


$file = $args->getArg('file');
if (count($file) != 1) {
  $args->printHelpAndExit();
}
$file = head($file);

$console = PhutilConsole::getConsole();
$console->writeOut("This process has PID %d. Acquiring lock...\n", getmypid());

$lock = PhutilFileLock::newForPath($file);

try {
  $lock->lock($args->getArg('wait'));
} catch (PhutilFileLockException $ex) {
  $console->writeOut("**UNABLE TO ACQUIRE LOCK:** Lock is already held.\n");
  exit(1);
}

// NOTE: This string is magic, the unit tests look for it.
$console->writeOut("LOCK ACQUIRED\n");
if ($args->getArg('test')) {
  $lock->unlock();
  exit(0);
}

if ($args->getArg('hold')) {
  while (true) {
    sleep(1);
  }
}

while (!$console->confirm("Release lock?")) {
  // Keep asking until they say yes.
}

$console->writeOut("Unlocking...\n");
$lock->unlock();

$console->writeOut("Done.\n");
exit(0);
