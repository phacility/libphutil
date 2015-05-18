#!/usr/bin/env php
<?php

require_once dirname(dirname(__FILE__)).'/__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->setTagline(pht('crazy workflow delegation'));
$args->setSynopsis(<<<EOHELP
**subworkflow.php** do echo __args__ ...
  Echo some stuff using a convoluted series of delegate workflows.
EOHELP
);


// This shows how to do manual parsing of raw arguments.
final class PhutilEchoExampleArgumentWorkflow extends PhutilArgumentWorkflow {

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
final class PhutilDoExampleArgumentWorkflow extends PhutilArgumentWorkflow {

  public function isExecutable() {
    return true;
  }

  public function shouldParsePartial() {
    return true;
  }

  public function execute(PhutilArgumentParser $args) {
    $echo_workflow = id(new PhutilEchoExampleArgumentWorkflow())
      ->setName('echo')
      ->setExamples('**echo** __string__ ...')
      ->setSynopsis(pht('Echo __string__.'));

    $args->parseWorkflows(
      array(
        $echo_workflow,
        new PhutilHelpArgumentWorkflow(),
      ));
  }

}


$do_workflow = id(new PhutilDoExampleArgumentWorkflow())
  ->setName('do')
  ->setExamples('**do** __thing__ ...')
  ->setSynopsis(pht('Do __thing__.'));

$args->parseWorkflows(
  array(
    $do_workflow,
    new PhutilHelpArgumentWorkflow(),
  ));
