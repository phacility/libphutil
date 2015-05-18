#!/usr/bin/env php
<?php

require_once dirname(dirname(__FILE__)).'/__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->setTagline(pht('simple calculator example'));
$args->setSynopsis(<<<EOHELP
**calculator.php** __op__ __n__ ...
  Perform a calculation.
EOHELP
);

$add_workflow = id(new PhutilArgumentWorkflow())
  ->setName('add')
  ->setExamples('**add** __n__ ...')
  ->setSynopsis(pht('Compute the sum of a list of numbers.'))
  ->setArguments(
    array(
      array(
        'name'     => 'numbers',
        'wildcard' => true,
      ),
    ));

$mul_workflow = id(new PhutilArgumentWorkflow())
  ->setName('mul')
  ->setExamples('**mul** __n__ ...')
  ->setSynopsis(pht('Compute the product of a list of numbers.'))
  ->setArguments(
    array(
      array(
        'name'     => 'numbers',
        'wildcard' => true,
      ),
    ));

$flow = $args->parseWorkflows(
  array(
    $add_workflow,
    $mul_workflow,
    new PhutilHelpArgumentWorkflow(),
  ));

$nums = $args->getArg('numbers');
if (empty($nums)) {
  echo pht('You must provide one or more numbers!')."\n";
  exit(1);
}

foreach ($nums as $num) {
  if (!is_numeric($num)) {
    echo pht("Number '%s' is not numeric!", $num)."\n";
    exit(1);
  }
}

switch ($flow->getName()) {
  case 'add':
    echo array_sum($nums)."\n";
    break;
  case 'mul':
    echo array_product($nums)."\n";
    break;
}
