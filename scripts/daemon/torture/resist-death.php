#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../../__init_script__.php';

// This script just creates a process which is difficult to terminate. It is
// used for daemon resilience tests.

declare(ticks = 1);
pcntl_signal(SIGTERM, 'ignore');
pcntl_signal(SIGINT,  'ignore');

function ignore($signo) {
  return;
}

echo pht('Resisting death; sleeping forever...')."\n";

while (true) {
  sleep(60);
}
