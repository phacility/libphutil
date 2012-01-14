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

$root = dirname(dirname(__FILE__));
require_once $root.'/src/__phutil_library_init__.php';

/**
 * Adjust the runtime language configuration to be reasonable and inline with
 * expectations.
 */
function __phutil_adjust_php_ini() {
  error_reporting(E_ALL | E_STRICT);

  $config_map = array(
    'display_errors'  => true,
    'error_log'       => null,
  );

  foreach ($config_map as $config_key => $config_value) {
    ini_set($config_key, $config_value);
  }
}

__phutil_adjust_php_ini();
