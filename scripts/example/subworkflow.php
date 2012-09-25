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
$args->setTagline('crazy workflow delgation');
$args->setSynopsis(<<<EOHELP
**subworkflow.php** do echo __args__ ...
  Echo some stuff using a convoluted series of delegate workflows.
EOHELP
);

// This shows how to do manual parsing of raw arguments.
final class PhutilArgumentWorkflowEchoExample extends PhutilArgumentWorkflow {

  public function isExecutable() {
    return true;
  }

  public function shouldParsePartial() {
    return true;
  }

  public function execute(PhutilArgumentParser $args) {
    $unconsumed = $args->getUnconsumedArgumentVector();
    echo implode(' ', $unconsumed)."\n";
    return 0;
  }
}


// This shows how to delegate to sub-workflows.
final class PhutilArgumentWorkflowDoExample extends PhutilArgumentWorkflow {

  public function isExecutable() {
    return true;
  }

  public function shouldParsePartial() {
    return true;
  }

  public function execute(PhutilArgumentParser $args) {
    $echo_workflow = id(new PhutilArgumentWorkflowEchoExample())
      ->setName('echo')
      ->setExamples('**echo** __string__ ...')
      ->setSynopsis('Echo __string__.');

    $args->parseWorkflows(
      array(
        $echo_workflow,
        new PhutilHelpArgumentWorkflow(),
      ));
  }
}

$do_workflow = id(new PhutilArgumentWorkflowDoExample())
  ->setName('do')
  ->setExamples('**do** __thing__ ...')
  ->setSynopsis('Do __thing__.');

$args->parseWorkflows(
  array(
    $do_workflow,
    new PhutilHelpArgumentWorkflow(),
  ));
