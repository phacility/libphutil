#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->setTagline(pht('test console prompting'));
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
      'help'    => pht('Use specified history __file__.'),
    ),
    array(
      'name'    => 'prompt',
      'param'   => 'text',
      'default' => pht('Enter some text:'),
      'help'    => pht('Change the prompt text to __text__.'),
    ),
  ));

$result = phutil_console_prompt(
  $args->getArg('prompt'),
  $args->getArg('history'));

$console = PhutilConsole::getConsole();
$console->writeOut("%s\n", pht('Input is: %s', $result));
