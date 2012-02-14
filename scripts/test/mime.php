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
$args->setTagline('test Filesystem::getMimeType()');
$args->setSynopsis(<<<EOHELP
**mime.php** [__options__] __file__
    Determine the mime type of a file.
EOHELP
  );
$args->parseStandardArguments();
$args->parse(
  array(
    array(
      'name'  => 'default',
      'param' => 'mimetype',
      'help'  => 'Use __mimetype__ as default instead of builtin default.',
    ),
    array(
      'name' => 'file',
      'wildcard' => true,
    ),
  ));

$file = $args->getArg('file');
if (count($file) !== 1) {
  $args->printHelpAndExit();
}

$file = reset($file);

$default = $args->getArg('default');
if ($default) {
  echo Filesystem::getMimeType($file, $default)."\n";
} else {
  echo Filesystem::getMimeType($file)."\n";
}
