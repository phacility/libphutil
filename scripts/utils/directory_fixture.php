#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->setTagline(pht('edit directory fixtures'));
$args->setSynopsis(<<<EOHELP
**directory_fixture.php** __file__ --create
  Create a new directory fixture.

**directory_fixture.php** __file__
  Edit an existing directory fixture.

EOHELP
);
$args->parseStandardArguments();
$args->parse(array(
  array(
    'name'      => 'create',
    'help'      => pht('Create a new fixture.'),
  ),
  array(
    'name'      => 'read-only',
    'help'      => pht('Do not save changes made to the fixture.'),
  ),
  array(
    'name'      => 'files',
    'wildcard'  => true,
  ),
));

$is_create    = $args->getArg('create');
$is_read_only = $args->getArg('read-only');
$console = PhutilConsole::getConsole();

$files = $args->getArg('files');
if (count($files) !== 1) {
  throw new PhutilArgumentUsageException(
    pht('Specify exactly one file to create or edit.'));
}
$file = head($files);

if ($is_create) {
  if (Filesystem::pathExists($file)) {
    throw new PhutilArgumentUsageException(
      pht(
        'File "%s" already exists, so you can not %s it.',
        $file,
        '--create'));
  }
  $fixture = PhutilDirectoryFixture::newEmptyFixture();
} else {
  if (!Filesystem::pathExists($file)) {
    throw new PhutilArgumentUsageException(
      pht(
        'File "%s" does not exist! Use %s to create a new fixture.',
        $file,
        '--create'));
  }
  $fixture = PhutilDirectoryFixture::newFromArchive($file);
}

$console->writeOut(
  "%s\n\n",
  pht('Spawning an interactive shell. Working directory is:'));
$console->writeOut(
  "    %s\n\n",
  $fixture->getPath());
if ($is_read_only) {
  $console->writeOut(
    "%s\n",
    pht('Exit the shell when done (this fixture is read-only).'));
} else {
  $console->writeOut(
    "%s\n",
    pht('Exit the shell after making changes.'));
}

$err = phutil_passthru('cd %s && sh', $fixture->getPath());
if ($err) {
  $console->writeOut(
    "%s\n",
    pht('Shell exited with error %d, discarding changes.', $err));
  exit($err);
} else if ($is_read_only) {
  $console->writeOut(
    "%s\n",
    pht('Invoked in read-only mode, discarding changes.'));
} else {
  $console->writeOut("%s\n", pht('Updating archive...'));
  $fixture->saveToArchive($file);
  $console->writeOut("%s\n", pht('Done.'));
}
