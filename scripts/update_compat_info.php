#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/__init_script__.php';

$target = 'resources/php_compat_info.json';
echo "Purpose: Updates {$target} used by ArcanistXHPASTLinter.\n";

require_once 'vendor/autoload.php';

$output = array();
$output['@'.'generated'] = true;
$output['params'] = array();
$output['functions'] = array();
$output['classes'] = array();
$output['interfaces'] = array();
$output['constants'] = array();
$output['classMethods'] = array();

$loader = new \Bartlett\CompatInfo\Reference\ReferenceLoader();
$prefetch = new \Bartlett\CompatInfo\Reference\Strategy\PreFetchStrategy();
$loader->register($prefetch);
$references = $loader->getProvidedReferences();

foreach ($references as $reference) {
  $reference_name = ucfirst(str_replace(' ', '', $reference->name));
  $class_name = "\\Bartlett\\CompatInfo\\Reference".
                "\\Extension\\{$reference_name}Extension";
  $reference = new $class_name();

  foreach ($reference->getFunctions() as $function => $compat) {
    $output['functions'][$function] = array(
      'min' => nonempty($compat['php.min'], null),
      'max' => nonempty($compat['php.max'], null),
      'ref' => $reference->getName(),
    );

    if (idx($compat, 'parameters')) {
      $output['params'][$function] = array_map(
        'trim', explode(',', $compat['parameters']));
    }
  }

  foreach ($reference->getInterfaces() as $interface => $compat) {
    $output['interfaces'][$interface] = array(
      'min' => nonempty($compat['php.min'], null),
      'max' => nonempty($compat['php.max'], null),
    );
  }

  foreach ($reference->getClasses() as $class => $compat) {
    $output['classes'][$class] = array(
      'min' => nonempty($compat['php.min'], null),
      'max' => nonempty($compat['php.max'], null),
    );
  }

  foreach ($reference->getConstants() as $constant => $compat) {
    $output['constants'][$constant] = array(
      'min' => nonempty($compat['php.min'], null),
      'max' => nonempty($compat['php.max'], null),
    );
  }

  foreach ($reference->getClassMethods() as $class => $methods) {
    if (!array_key_exists($class, $output['classMethods'])) {
      $output['classMethods'][$class] = array();
    }

    foreach ($methods as $method => $compat) {
      $output['classMethods'][$class][$method] = array(
        'min' => nonempty($compat['php.min'], null),
        'max' => nonempty($compat['php.max'], null),
      );
    }
  }
}

ksort($output['params']);
ksort($output['functions']);
ksort($output['classes']);
ksort($output['interfaces']);
ksort($output['constants']);
ksort($output['classMethods']);

// Grepped from PHP Manual.
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

echo "Done.\n";
