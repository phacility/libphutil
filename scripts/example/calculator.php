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

require_once dirname(dirname(__FILE__)).'/__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->setTagline('simple calculator example');
$args->setSynopsis(<<<EOHELP
**calculator.php** __op__ __n__ ...
Perform a calculation.
EOHELP
);

$add_workflow = id(new PhutilArgumentWorkflow())
  ->setName('add')
  ->setExamples('**add** __n__ ...')
  ->setSynopsis('Compute the sum of a list of numbers.')
  ->setArguments(
    array(
      array(
        'name'       => 'numbers',
        'wildcard'   => true,
      ),
    ));

$mul_workflow = id(new PhutilArgumentWorkflow())
  ->setName('mul')
  ->setExamples('**mul** __n__ ...')
  ->setSynopsis('Compute the product of a list of numbers.')
  ->setArguments(
    array(
      array(
        'name'       => 'numbers',
        'wildcard'   => true,
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
  echo "You must provide one or more numbers!\n";
  exit(1);
}

foreach ($nums as $num) {
  if (!is_numeric($num)) {
    echo "Number '{$num}' is not numeric!\n";
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
