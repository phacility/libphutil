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

$root = dirname(dirname(dirname(dirname(__FILE__))));
require_once $root.'/scripts/__init_script__.php';

if (!posix_isatty(STDOUT)) {
  $sid = posix_setsid();
  if ($sid <= 0) {
    throw new Exception('Failed to create new process session!');
  }
}


$trace_mode = false;
$trace_memory = false;
$echo_to_stderr = false;
$load = array();
$len = count($argv);
for ($ii = 2; $ii < $len; $ii++) {
  $value = $argv[$ii];
  $matches = null;
  if ($value == '--') {
    break;
  } else if ($value == '--trace') {
    $trace_mode = true;
    unset($argv[$ii]);
  } else if ($value == '--trace-memory') {
    $trace_mode = true;
    $trace_memory = true;
    unset($argv[$ii]);
  } else if (preg_match('/^--log=(.*)$/', $value, $matches)) {
    ini_set('error_log', $matches[1]);
    unset($argv[$ii]);
    $echo_to_stderr = true;
  } else if (preg_match('/^--load-phutil-library=(.*)$/', $value, $matches)) {
    $load[] = $matches[1];
    unset($argv[$ii]);
  }
}

$argv = array_values($argv);

if ($load) {
  phutil_require_module('phutil', 'filesystem');
  foreach ($load as $library) {
    $library = Filesystem::resolvePath($library);
    phutil_load_library($library);
  }
}

phutil_require_module('phutil', 'symbols');

PhutilErrorHandler::initialize();
function phutil_daemon_error_listener($event, $value, array $metadata) {
  $message = idx($metadata, 'default_message');
  if ($message) {
    file_put_contents('php://stderr', $message);
  }
}

if ($echo_to_stderr) {
  // If the caller has used "--log" to redirect the error log to a file, PHP
  // won't output it to stderr so the overseer can't capture it and won't
  // be able to send it to the web console. Install a listener which just echoes
  // errors to stderr, so we always get all the messages in the log and over
  // stdio, so they'll show up in the web console.
  PhutilErrorHandler::setErrorListener('phutil_daemon_error_listener');
}

$daemon = $argv[1];

$argv = array_slice($argv, 2);

PhutilSymbolLoader::loadClass($daemon);
$daemon = newv($daemon, array($argv));
if ($trace_mode) {
  $daemon->setTraceMode();
}
if ($trace_memory) {
  $daemon->setTraceMemory();
}
$daemon->execute();
