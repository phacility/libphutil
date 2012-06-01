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

require_once dirname(__FILE__).'/__init_script__.php';

$root = idx($argv, 1);

if (!is_dir($root)) {
  echo "Usage: ".basename(__FILE__)." <dir>\n";
  echo "Purpose: Delete __init__.php files and move source files a level up.\n";
  echo "Warning: This will git-reset and git-clean the repository.\n";
  exit(1);
}

echo "Resetting repository...\n";
phutil_passthru('(cd %s; git reset --hard HEAD)', $root);

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

echo "\nDeleting empty directories...\n";
phutil_passthru('(cd %s; git clean -df)', $root);

echo "\nDone.\n";
if ($data) {
  echo "You must manually change the path to test data dirs in test files!\n";
}
