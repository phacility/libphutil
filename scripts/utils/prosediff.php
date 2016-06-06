#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->setTagline(pht('show prose differences'));
$args->setSynopsis(<<<EOHELP
**prosediff.php** __old__ __new__ [__options__]
    Diff two prose files.

EOHELP
);

$args->parseStandardArguments();
$args->parse(
  array(
    array(
      'name'      => 'files',
      'wildcard'  => true,
    ),
  ));

$files = $args->getArg('files');
if (count($files) !== 2) {
  $args->printHelpAndExit();
}
$old_file = head($files);
$new_file = last($files);

$old_data = Filesystem::readFile($old_file);
$new_data = Filesystem::readFile($new_file);

$engine = new PhutilProseDifferenceEngine();

$prose_diff = $engine->getDiff($old_data, $new_data);

foreach ($prose_diff->getParts() as $part) {
  switch ($part['type']) {
    case '-':
      echo tsprintf('<bg:red>%B</bg>', $part['text']);
      break;
    case '+':
      echo tsprintf('<bg:green>%B</bg>', $part['text']);
      break;
    case '=':
      echo tsprintf('%B', $part['text']);
      break;
  }
}
