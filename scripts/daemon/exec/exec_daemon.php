#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../../__init_script__.php';

if (!posix_isatty(STDOUT)) {
  $sid = posix_setsid();
  if ($sid <= 0) {
    throw new Exception('Failed to create new process session!');
  }
}

$args = new PhutilArgumentParser($argv);
$args->setTagline('daemon executor');
$args->setSynopsis(<<<EOHELP
**exec_daemon.php** [__options__] __daemon__ ...
    Run an instance of __daemon__.
EOHELP
  );
$args->parse(
  array(
    array(
      'name' => 'trace',
      'help' => 'Enable debug tracing.',
    ),
    array(
      'name' => 'trace-memory',
      'help' => 'Enable debug memory tracing.',
    ),
    array(
      'name'  => 'log',
      'param' => 'file',
      'help'  => 'Send output to __file__.',
    ),
    array(
      'name'    => 'load-phutil-library',
      'param'   => 'library',
      'repeat'  => true,
      'help' => 'Load __library__.',
    ),
    array(
      'name' => 'verbose',
      'help'  => 'Enable verbose activity logging.',
    ),
    array(
      'name'     => 'argv',
      'wildcard' => true,
    ),
  ));

$trace_memory = $args->getArg('trace-memory');
$trace_mode   = $args->getArg('trace') || $trace_memory;
$verbose      = $args->getArg('verbose');

$log = $args->getArg('log');
if ($log) {
  ini_set('error_log', $log);
  $echo_to_stderr = true;
} else {
  $echo_to_stderr = false;
}

$load = $args->getArg('load-phutil-library');
$argv = $args->getArg('argv');

foreach ($load as $library) {
  $library = Filesystem::resolvePath($library);
  phutil_load_library($library);
}

PhutilErrorHandler::initialize();

function phutil_daemon_error_listener($event, $value, array $metadata) {
  $console = PhutilConsole::getConsole();
  $message = idx($metadata, 'default_message');

  if ($message) {
    $console->writeErr("%s\n", $message);
  }
  if (idx($metadata, 'trace')) {
    $trace = PhutilErrorHandler::formatStacktrace($metadata['trace']);
    $console->writeErr("%s\n", $trace);
  }
}

if ($echo_to_stderr) {
  // If the caller has used `--log` to redirect the error log to a file, PHP
  // won't output it to stderr so the overseer can't capture it and won't be
  // able to send it to the web console. Install a listener which just echoes
  // errors to stderr, so we always get all the messages in the log and over
  // stdio, so they'll show up in the web console.
  PhutilErrorHandler::setErrorListener('phutil_daemon_error_listener');
}

$daemon = array_shift($argv);
if (!$daemon) {
  $args->printHelpAndExit();
}

$daemon = newv($daemon, array($argv));
if ($trace_mode) {
  $daemon->setTraceMode();
}
if ($trace_memory) {
  $daemon->setTraceMemory();
}
if ($verbose) {
  $daemon->setVerbose(true);
}

$daemon->execute();
