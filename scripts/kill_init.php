#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/__init_script__.php';

$root = idx($argv, 1);

if ($root === null || !is_dir($root)) {
  echo "Usage: ".basename(__FILE__)." <dir>\n";
  echo "Purpose: Delete __init__.php files and move source files a level up.\n";
  exit(1);
}

$inits = id(new FileFinder($root))
  ->withType('f')
  ->withPath('*/__init__.php')
  ->find();
echo "\nDeleting ".count($inits)." __init__.php...\n";
if ($inits) {
  phutil_passthru('(cd %s; git rm %Ls)', $root, $inits);
}

$phps = id(new FileFinder($root))
  ->excludePath('./docs/*')
  ->excludePath('*/__tests__/*')
  ->withType('f')
  ->withPath('./*/*/*')
  ->find();
echo "\nMoving ".count($phps)." files...\n";
foreach ($phps as $file) {
  echo $file."\n";
  $target = dirname(dirname($file));
  phutil_passthru('(cd %s; git mv %s %s)', $root, $file, $target);
}

$tests = id(new FileFinder($root))
  ->withType('f')
  ->withPath('./*/*/__tests__/*.php')
  ->find();
echo "\nMoving ".count($tests)." tests...\n";
foreach ($tests as $file) {
  echo $file."\n";
  $target = dirname(dirname(dirname($file))).'/__tests__/';
  if (!file_exists($root.'/'.$target)) {
    mkdir($root.'/'.$target);
  }
  phutil_passthru('(cd %s; git mv %s %s)', $root, $file, $target);
}

$data = id(new FileFinder($root))
  ->withType('d')
  ->withPath('./*/*/__tests__/data')
  ->find();
echo "\nMoving ".count($data)." test data dirs...\n";
foreach ($data as $dir) {
  echo $dir."\n";
  $target = dirname(dirname($dir));
  $target = dirname($target).'/__tests__/'.basename($target);
  phutil_passthru('(cd %s; git mv %s %s)', $root, $dir, $target);
}

echo "\nDone.\n";
echo "Consider running `git clean -df`.\n";
if ($data) {
  echo "You must manually change the path to test data dirs in test files!\n";
}
