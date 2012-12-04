#!/usr/bin/env php
<?php

$root = dirname(dirname(dirname(__FILE__)));
require_once $root.'/scripts/__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->parseStandardArguments();
$args->parse(
  array(
    array(
      'name'      => 'url',
      'wildcard'  => true,
    ),
  ));

$uri = $args->getArg('url');
if (count($uri) !== 1) {
  throw new PhutilArgumentUsageException(
    "Specify exactly one URL to retrieve.");
}
$uri = head($uri);

$method   = 'GET';
$data     = '';
$timeout  = 30;

$parsed = new PhutilURI($uri);
if ($parsed->getProtocol() == 'https') {
  $future = new HTTPSFuture($uri, $data);
} else {
  $future = new HTTPFuture($uri, $data);
}

$future->setMethod($method);
$future->setTimeout($timeout);

print_r($future->resolve());
