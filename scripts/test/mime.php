#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->setTagline(pht('test %s', 'Filesystem::getMimeType()'));
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
      'help'  => pht(
        'Use __mimetype__ as default instead of built-in default.'),
    ),
    array(
      'name'     => 'file',
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
