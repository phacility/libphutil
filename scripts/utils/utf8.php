#!/usr/bin/env php
<?php

/*
 * Copyright 2011 Facebook, Inc.
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

require_once dirname(dirname(__FILE__)).'/__init_script__.php';
phutil_require_module('phutil', 'console');

function usage() {
  echo <<<EOUSAGE
utf8.php [-C n] file ...
  Show regions in files which are not valid UTF-8. With "-C n", show n lines
  of context instead of the default of 3. Use "-" to read stdin.

utf8.php -t file ...
  Test for files which are not valid UTF-8. For example, this will find
  all ".php" files under the working directory which aren't valid UTF-8:

    find . -type f -name '*.php' -print0 | xargs -0 -n256 ./utf8.php -t

  If the script exits with no output, all input files were valid UTF-8.


EOUSAGE;
}

$is_test = false;
$context = 3;

$args = array_slice($argv, 1);
$len = count($args);
for ($ii = 0; $ii < $len; $ii++) {
  if ($args[$ii] === '--') {
    break;
  } else if ($args[$ii][0] === '-') {
    switch ($args[$ii]) {
      case '-':
        continue;
      case '-h':
        usage();
        exit(0);
      case '-t':
        $is_test = true;
        unset($args[$ii]);
        break;
      case '-C':
        if ($ii < ($len - 1)) {
          $context = max(0, $args[$ii + 1]);
        } else {
          usage();
          exit(1);
        }
        unset($args[$ii]);
        unset($args[$ii + 1]);
        ++$ii;
        break;
    }
  }
}
$files = array_values($args);

if (empty($files)) {
  usage();
  exit(1);
}

if ($is_test) {
  $err = test($files);
} else {
  $err = show($files, $context);
}
exit($err);


function read($file) {
  if ($file == '-') {
    return file_get_contents('php://stdin');
  } else {
    return Filesystem::readFile($file);
  }
}

function name($file) {
  if ($file == '-') {
    return 'stdin';
  } else {
    return $file;
  }
}

function test(array $files) {
  foreach ($files as $file) {
    $data = read($file);
    if (!phutil_is_utf8($data)) {
      echo name($file)."\n";
    }
  }

  return 0;
}

function show(array $files, $context) {
  foreach ($files as $file) {
    $data = read($file);
    $ok = phutil_is_utf8($data);
    if ($ok) {
      echo "OKAY";
    } else {
      echo "FAIL";
    }
    echo "  ".name($file)."\n";

    if (!$ok) {
      $lines = explode("\n", $data);
      $len = count($lines);
      $map = array();
      $bad = array();
      foreach ($lines as $n => $line) {
        if (phutil_is_utf8($line)) {
          continue;
        }
        $bad[$n] = true;
        for ($jj = max(0, $n - $context);
             $jj < min($len, $n + 1 + $context);
             $jj++) {
          $map[$jj] = true;
        }
      }

      $width = strlen(max(array_keys($map)));

      // Set $last such that we print a newline on the first iteration thorugh
      // the loop.
      $last = -2;
      foreach ($map as $idx => $ignored) {
        if ($idx != $last + 1) {
          printf("\n");
        }
        $last = $idx;

        $line = $lines[$idx];
        if (!empty($bad[$idx])) {
          $line = show_problems($line);
        }

        printf("  % {$width}d  %s\n", $idx + 1, $line);
      }
      echo "\n";
    }

  }
}

function show_problems($line) {
  $regex =
    "/^(".
      "[\x01-\x7F]+".
    "|([\xC2-\xDF][\x80-\xBF])".
    "|([\xE0-\xEF][\x80-\xBF][\x80-\xBF])".
    "|([\xF0-\xF4][\x80-\xBF][\x80-\xBF][\x80-\xBF]))/";

  $out = '';
  while (strlen($line)) {
    $match = null;
    if (preg_match($regex, $line, $match)) {
      $out .= $match[1];
      $line = substr($line, strlen($match[1]));
    } else {
      $chr = sprintf("<0x%0X>", ord($line[0]));
      $chr = phutil_console_format('##%s##', $chr);
      $out .= $chr;
      $line = substr($line, 1);
    }
  }

  return $out;
}
