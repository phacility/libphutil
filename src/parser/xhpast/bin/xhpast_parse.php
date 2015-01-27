<?php

function xhpast_is_available() {
  static $available;

  if ($available === null) {
    $available = xhpast_version() == 'xhpast version 5.5.8/1g';
  }

  return $available;
}

function xhpast_get_binary_path() {
  if (phutil_is_windows()) {
    return dirname(__FILE__).'\\xhpast.exe';
  }
  return dirname(__FILE__).'/xhpast';
}

function xhpast_get_build_instructions() {
  $root = phutil_get_library_root('phutil');
  $make = $root.'/../scripts/build_xhpast.sh';
  $make = Filesystem::resolvePath($make);
  return <<<EOHELP
Your version of 'xhpast' is unbuilt or out of date. Run this script to build it:

  \$ {$make}

EOHELP;
}

function xhpast_get_parser_future($data) {
  if (!xhpast_is_available()) {
    try {
      // Try to build XHPAST automatically. If we can't then just ask the user
      // to build it themselves.
      xhpast_build();
    } catch (CommandException $ex) {
      throw new PhutilProxyException(xhpast_get_build_instructions(), $ex);
    }
  }
  $future = new ExecFuture('%s', xhpast_get_binary_path());
  $future->write($data);

  return $future;
}

function xhpast_build() {
  $root = phutil_get_library_root('phutil');
  execx('%s', $root.'/../scripts/build_xhpast.sh');
}

function xhpast_version() {
  static $version;

  if ($version === null) {
    $bin = xhpast_get_binary_path();
    if (Filesystem::pathExists($bin)) {
      list($err, $stdout) = exec_manual('%s --version', $bin);
      if (!$err) {
        $version = trim($stdout);
      }
    }
  }

  return $version;
}
