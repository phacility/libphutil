#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/__init_script__.php';

$target = 'resources/php_compat_info.json';
echo phutil_console_format(
  "%s\n",
  pht(
    'Purpose: Updates %s used by %s.',
    $target,
    'ArcanistXHPASTLinter'));

// PHP CompatInfo is installed via Composer.
//
// You should symlink the Composer vendor directory to
// libphutil/externals/includes/vendor`.
require_once 'vendor/autoload.php';

$output = array();
$output['@'.'generated'] = true;
$output['params'] = array();
$output['functions'] = array();
$output['classes'] = array();
$output['interfaces'] = array();
$output['constants'] = array();

/**
 * Transform compatibility info into a slightly different format.
 *
 * The data returned by PHP CompatInfo is slightly odd in that null data is
 * represented by an empty string.
 *
 * @param  map<string, string>
 * @return map<string, string | null>
 */
function parse_compat_info(array $compat) {
  return array(
    'ext.name' => $compat['ext.name'],
    'ext.min' => nonempty($compat['ext.min'], null),
    'ext.max' => nonempty($compat['ext.max'], null),
    'php.min' => nonempty($compat['php.min'], null),
    'php.max' => nonempty($compat['php.max'], null),
  );
}

$client = new \Bartlett\Reflect\Client();
$api = $client->api('reference');

foreach ($api->dir() as $extension) {
  $result = $api->show(
    $extension->name,
    false,
    false,
    false,
    true,
    true,
    true,
    true,
    true);

  foreach ($result['constants'] as $constant => $compat) {
    $output['constants'][$constant] = parse_compat_info($compat);
  }

  foreach ($result['functions'] as $function => $compat) {
    $output['functions'][$function] = parse_compat_info($compat);

    if (idx($compat, 'parameters')) {
      $output['params'][$function] = explode(', ', $compat['parameters']);
    }
  }

  foreach ($result['classes'] as $class => $compat) {
    $output['classes'][$class] = parse_compat_info($compat);
  }

  foreach ($result['interfaces'] as $interface => $compat) {
    $output['interfaces'][$interface] = parse_compat_info($compat);
  }

  foreach ($result['methods'] as $class => $methods) {
    $output['methods'][$class] = array();

    foreach ($methods as $method => $compat) {
      $output['methods'][$class][$method] = parse_compat_info($compat);
    }
  }

  foreach ($result['static methods'] as $class => $methods) {
    $output['static_methods'][$class] = array();

    foreach ($methods as $method => $compat) {
      $output['static_methods'][$class][$method] = parse_compat_info($compat);
    }
  }
}

ksort($output['params']);
ksort($output['functions']);
ksort($output['classes']);
ksort($output['interfaces']);
ksort($output['constants']);

// Grepped from PHP Manual.
// TODO: Can we get this from PHP CompatInfo?
// See https://github.com/llaville/php-compat-info/issues/185.
$output['functions_windows'] = array(
  'apache_child_terminate' => false,
  'chroot' => false,
  'getrusage' => false,
  'imagecreatefromxpm' => false,
  'lchgrp' => false,
  'lchown' => false,
  'nl_langinfo' => false,
  'strptime' => false,
  'sys_getloadavg' => false,
  'checkdnsrr' => '5.3.0',
  'dns_get_record' => '5.3.0',
  'fnmatch' => '5.3.0',
  'getmxrr' => '5.3.0',
  'getopt' => '5.3.0',
  'imagecolorclosesthwb' => '5.3.0',
  'inet_ntop' => '5.3.0',
  'inet_pton' => '5.3.0',
  'link' => '5.3.0',
  'linkinfo' => '5.3.0',
  'readlink' => '5.3.0',
  'socket_create_pair' => '5.3.0',
  'stream_socket_pair' => '5.3.0',
  'symlink' => '5.3.0',
  'time_nanosleep' => '5.3.0',
  'time_sleep_until' => '5.3.0',
);

Filesystem::writeFile(
  phutil_get_library_root('phutil').'/../'.$target,
  id(new PhutilJSON())->encodeFormatted($output));

echo pht('Done.')."\n";
