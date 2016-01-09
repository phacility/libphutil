#!/usr/bin/env php
<?php

$root = dirname(dirname(dirname(__FILE__)));
require_once $root.'/scripts/__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->setTagline(pht('AWS CLI Client for S3'));
$args->setSynopsis(<<<EOSYNOPSIS
**aws-s3** __command__ [__options__]
    Upload and download data from Amazon Simple Storage Service (S3).

EOSYNOPSIS
  );
$args->parseStandardArguments();

$workflows = id(new PhutilClassMapQuery())
  ->setAncestorClass('PhutilAWSS3ManagementWorkflow')
  ->execute();

$workflows[] = new PhutilHelpArgumentWorkflow();
$args->parseWorkflows($workflows);
