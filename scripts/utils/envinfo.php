#!/usr/bin/env php
<?php

show_ini('display_errors');
show_ini('error_reporting');
show_ini('error_log');
show_ini('auto_prepend_file');
show_ini('auto_append_file');

show_value('Exception Handler', set_exception_handler('dummy'));
show_value('Error Handler',     set_error_handler('dummy'));
show_value('ob_get_level',      ob_get_level());


function show_ini($key) {
  show_value($key, ini_get($key));
}

function show_value($key, $value) {
  printf('%-20.20s  ', $key);
  var_dump($value);
  echo "\n";
}

function dummy() {
  return;
}
