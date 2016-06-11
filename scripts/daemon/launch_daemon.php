#!/usr/bin/env php
<?php

declare(ticks = 1);

$root = dirname(dirname(dirname(__FILE__)));
require_once $root.'/scripts/__init_script__.php';
$overseer = new PhutilDaemonOverseer($argv);
$overseer->run();
