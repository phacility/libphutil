#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->setTagline('test context-free grammars');
$args->setSynopsis(<<<EOHELP
**lipsum.php** __class__
    Generate output from a named context-free grammar.
EOHELP
  );
$args->parseStandardArguments();
$args->parse(
  array(
    array(
      'name'     => 'class',
      'wildcard' => true,
    ),
  ));

$class = $args->getArg('class');
if (count($class) !== 1) {
  $args->printHelpAndExit();
}
$class = reset($class);

$symbols = id(new PhutilSymbolLoader())
  ->setAncestorClass('PhutilContextFreeGrammar')
  ->setConcreteOnly(true)
  ->selectAndLoadSymbols();
$symbols = ipull($symbols, 'name', 'name');

if (empty($symbols[$class])) {
  $available = implode(', ', array_keys($symbols));
  throw new PhutilArgumentUsageException(
    "Class '{$class}' is not a defined, concrete subclass of ".
    "PhutilContextFreeGrammar. Available classes are: {$available}");
}

$object = newv($class, array());
echo $object->generate()."\n";
