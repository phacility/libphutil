#!/usr/bin/env php
<?php

$root = dirname(dirname(dirname(__FILE__)));
require_once $root.'/scripts/__init_script__.php';

// Simple test script for PhutilServiceProfiler.

PhutilServiceProfiler::installEchoListener();

execx('ls %s', '/tmp');

exec_manual('sleep %s', 1);

phutil_passthru('cat');

echo "\n\nSERVICE CALL LOG\n";
var_dump(PhutilServiceProfiler::getInstance()->getServiceCallLog());
