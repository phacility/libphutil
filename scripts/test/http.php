#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->parseStandardArguments();
$args->parse(
  array(
    array(
      'name'     => 'attach',
      'param'    => 'file',
      'help'     => pht('Attach a file to the request.'),
    ),
    array(
      'name'     => 'url',
      'wildcard' => true,
    ),
  ));

$uri = $args->getArg('url');
if (count($uri) !== 1) {
  throw new PhutilArgumentUsageException(
    pht('Specify exactly one URL to retrieve.'));
}
$uri = head($uri);

$method  = 'GET';
$data    = '';
$timeout = 30;

$future = id(new HTTPSFuture($uri, $data))
  ->setMethod($method)
  ->setTimeout($timeout);

$attach_file = $args->getArg('attach');
if ($attach_file !== null) {
  $future->attachFileData(
    'file',
    Filesystem::readFile($attach_file),
    basename($attach_file),
    Filesystem::getMimeType($attach_file));
}

print_r($future->resolve());
