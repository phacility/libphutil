#!/usr/bin/env php
<?php

// Simple script to format stacktraces in apache logs, etc., so they are more
// readable.

$f = fopen('php://stdin', 'r');
while (($line = fgets($f)) !== false) {
  echo stripcslashes($line);
}
