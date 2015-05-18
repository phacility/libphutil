#!/usr/bin/env php
<?php

require_once dirname(dirname(__FILE__)).'/__init_script__.php';

$args = new PhutilArgumentParser($argv);
$args->setTagline(pht('utf8 charset test script'));
$args->setSynopsis(<<<EOHELP
**utf8.php** [-C n] __file__ ...
    Show regions in files which are not valid UTF-8. With "-C n",
    show __n__ lines of context instead of the default of 3. Use
    "-" to read stdin.

**utf8.php** --test __file__ ...
    Test for files which are not valid UTF-8. For example, this
    will find all ".php" files under the working directory which
    aren't valid UTF-8:

        find . -type f -name '*.php' | xargs -n256 ./utf8.php -t

    If the script exits with no output, all input files were
    valid UTF-8.
EOHELP
);

$args->parseStandardArguments();
$args->parse(array(
  array(
    'name'      => 'context',
    'short'     => 'C',
    'param'     => 'lines',
    'default'   => 3,
    'help'      => pht(
      'Show __lines__ lines of context instead of the default 3.'),
    'conflicts' => array(
      'test' => pht('with %s, context is not shown.', '--test'),
    ),
  ),
  array(
    'name'      => 'test',
    'short'     => 't',
    'help'      => pht('Print file names containing invalid UTF-8 to stdout.'),
  ),
  array(
    'name'      => 'files',
    'wildcard'  => true,
  ),
));


$is_test = $args->getArg('test');
$context = $args->getArg('context');
$files   = $args->getArg('files');

if (empty($files)) {
  $args->printHelpAndExit();
}

if ($is_test) {
  $err = test($files);
} else {
  $err = show($files, $context);
}
exit($err);


function read($file) {
  if ($file === '-') {
    return file_get_contents('php://stdin');
  } else {
    return Filesystem::readFile($file);
  }
}

function name($file) {
  if ($file === '-') {
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
      echo pht('OKAY');
    } else {
      echo pht('FAIL');
    }
    echo '  '.name($file)."\n";

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

      // Set $last such that we print a newline on the first iteration through
      // the loop.
      $last = -2;
      foreach ($map as $idx => $ignored) {
        if ($idx !== $last + 1) {
          echo "\n";
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

  return 0;
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
      $chr = sprintf('<0x%0X>', ord($line[0]));
      $chr = phutil_console_format('##%s##', $chr);
      $out .= $chr;
      $line = substr($line, 1);
    }
  }

  return $out;
}
