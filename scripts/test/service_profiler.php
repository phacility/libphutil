#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../__init_script__.php';

// Simple test script for PhutilServiceProfiler.

PhutilServiceProfiler::installEchoListener();

execx('ls %s', '/tmp');
exec_manual('sleep %d', 1);
phutil_passthru('cat');

echo "\n\n".pht('SERVICE CALL LOG')."\n";
var_dump(PhutilServiceProfiler::getInstance()->getServiceCallLog());
