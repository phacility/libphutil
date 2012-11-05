#!/usr/bin/env php
<?php

require_once dirname(dirname(__FILE__)).'/__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->setTagline('edit directory fixtures');
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
    'help'      => 'Create a new fixture.',
  ),
  array(
    'name'      => 'files',
    'wildcard'  => true,
  ),
));

$is_create = $args->getArg('create');

$files = $args->getArg('files');
if (count($files) !== 1) {
  echo "Specify exactly one file to edit.\n";
  exit(1);
}
$file = head($files);

if ($is_create) {
  if (Filesystem::pathExists($file)) {
    echo "File '{$file}' already exists!\n";
    exit(1);
  }
  $fixture = PhutilDirectoryFixture::newEmptyFixture();
} else {
  if (!Filesystem::pathExists($file)) {
    echo "File '{$file}' does not exist!\n";
    exit(1);
  }
  $fixture = PhutilDirectoryFixture::newFromArchive($file);
}

echo "Spawning an interactive shell. Exit when complete.\n\n";

$err = phutil_passthru('cd %s && sh', $fixture->getPath());
if ($err) {
  exit($err);
}

echo "Updating archive...\n";
$fixture->saveToArchive($file);
echo "Done.\n";
