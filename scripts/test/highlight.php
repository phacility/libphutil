#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->setTagline(pht('test syntax highlighters'));
$args->setSynopsis(<<<EOHELP
**highlight.php** [__options__]
    Syntax highlight a corpus read from stdin.
EOHELP
  );
$args->parseStandardArguments();
$args->parse(
  array(
    array(
      'name'  => 'language',
      'param' => 'language',
      'help'  => pht('Choose the highlight language.'),
    ),
  ));

$language = $args->getArg('language');
$corpus = file_get_contents('php://stdin');

echo id(new PhutilDefaultSyntaxHighlighterEngine())
  ->setConfig('pygments.enabled', true)
  ->highlightSource($language, $corpus);
