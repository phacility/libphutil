#!/usr/bin/env php
<?php

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
