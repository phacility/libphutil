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

$root = dirname(dirname(dirname(__FILE__)));
require_once $root.'/scripts/__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->setTagline('test InteractiveEditor class');
$args->setSynopsis(<<<EOHELP
**interactive_editor.php** [__options__]
    Edit some content via the InteractiveEditor class. This script
    makes it easier to test changes to InteractiveEditor, which is
    difficult to unit test.
EOHELP
  );
$args->parseStandardArguments();
$args->parse(
  array(
    array(
      'name'  => 'fallback',
      'param' => 'editor',
      'help'  => 'Set the fallback editor.',
    ),
    array(
      'name'  => 'line',
      'short' => 'l',
      'param' => 'number',
      'help'  => 'Open at line number __number__.',
    ),
    array(
      'name'  => 'name',
      'param' => 'filename',
      'help'  => 'Set edited file name.',
    ),
  ));

if ($args->getArg('help')) {
  $args->printHelpAndExit();
}

$editor = new PhutilInteractiveEditor(
  "The wizard quickly\n".
  "jinxed the gnomes\n".
  "before they vaporized.");

$name = $args->getArg('name');
if ($name) {
  $editor->setName($name);
}

$line = $args->getArg('line');
if ($line) {
  $editor->setLineOffset($line);
}

$fallback = $args->getArg('fallback');
if ($fallback) {
  $editor->setFallbackEditor($fallback);
}

$result = $editor->editInteractively();
echo "Edited Text:\n{$result}\n";
