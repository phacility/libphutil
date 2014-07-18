#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../__init_script__.php';

$logs = array();
for ($ii = 0; $ii < $argv[1]; $ii++) {
  $logs[] = new PhutilDeferredLog($argv[2], 'abcdefghijklmnopqrstuvwxyz');
}
