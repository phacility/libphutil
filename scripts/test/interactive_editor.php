#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->setTagline(pht('test %s class', 'InteractiveEditor'));
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
      'help'  => pht('Set the fallback editor.'),
    ),
    array(
      'name'  => 'line',
      'short' => 'l',
      'param' => 'number',
      'help'  => pht('Open at line number __number__.'),
    ),
    array(
      'name'  => 'name',
      'param' => 'filename',
      'help'  => pht('Set edited file name.'),
    ),
  ));

if ($args->getArg('help')) {
  $args->printHelpAndExit();
}

$editor = new PhutilInteractiveEditor(
  pht("The wizard quickly\njinxed the gnomes\nbefore they vaporized."));

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
echo pht('Edited Text:')."\n{$result}\n";
