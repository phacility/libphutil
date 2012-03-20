#!/usr/bin/env php
<?php

/*
 * Copyright 2012 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
