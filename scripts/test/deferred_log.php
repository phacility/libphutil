#!/usr/bin/env php
<?php

$root = dirname(dirname(dirname(__FILE__)));
require_once $root.'/scripts/__init_script__.php';

$logs = array();
for ($ii = 0; $ii < $argv[1]; $ii++) {
  $logs[] = new PhutilDeferredLog(
    $argv[2],
    'abcdefghijklmnopqrstuvwxyz');
}
