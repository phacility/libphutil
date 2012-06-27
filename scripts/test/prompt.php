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
$args->setTagline('test console prompting');
$args->setSynopsis(<<<EOHELP
**prompt.php** __options__
    Test console prompting.
EOHELP
);
$args->parseStandardArguments();
$args->parse(
  array(
    array(
      'name'    => 'history',
      'param'   => 'file',
      'default' => '',
      'help'    => 'Use specified history __file__.',
    ),
    array(
      'name'    => 'prompt',
      'param'   => 'text',
      'default' => 'Enter some text:',
      'help'    => 'Change the prompt text to __text__.'
    ),
  ));

$result = phutil_console_prompt(
  $args->getArg('prompt'),
  $args->getArg('history'));

$console = PhutilConsole::getConsole();
$console->writeOut("Input is: %s\n", $result);
