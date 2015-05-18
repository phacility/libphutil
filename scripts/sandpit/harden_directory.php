#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../__init_script__.php';

if ($argc !== 4) {
  usage();
  exit(1);
}

function usage() {
  echo phutil_console_format(<<<EOUSAGE
usage: harden_directory.php soft_directory link scratch_dir

Massively reduce the disk usage of a readonly directory by using hardlinks to
represent its data. Pass a normal __soft_directory__ to compress, and a
__link__ to symlink to the compressed version once compression is complete.
The directory will be cloned into __scratch_dir__ and replaced with hardlinks.

This is primarily useful if you want to have checkouts of hundreds of different
commits in a version-controlled repository, so you can, e.g., run unit tests or
other readonly processes on them.

EOUSAGE
  );
}

$soft = Filesystem::resolvePath($argv[1]);
$dst  = $argv[2];
$root = Filesystem::resolvePath($argv[3]);

$hash_map = map_directory($soft);
$hardened_id = sha1(Filesystem::readRandomBytes(128));
$hardened_id = hash_path($hardened_id);
$hardened = $root.'/pit/'.$hardened_id;
execx('mkdir -p %s', $hardened);

$obj_root = $root.'/obj/';
foreach ($hash_map as $path => $info) {
  $hash = $info['hash'];
  $type = $info['type'];

  $obj = $obj_root.hash_path($hash);

  $link = $hardened.'/'.$path;
  $dir = dirname($link);
  if (!is_dir($dir)) {
    $ok = mkdir($dir, 0777, $recursive = true);
    if (!$ok) {
      throw new Exception(pht("Failed to make directory for '%s'!", $link));
    }
  }

  // We need to use actual symlinks in this case.
  if ($type == 'link') {
    $ok = symlink(readlink($soft.'/'.$path), $link);
    if (!$ok) {
      throw new Exception(pht("Failed to create symlink '%s'!", $link));
    }
    continue;
  }

  if ($type === 'exec') {
    // Multiple hardlinks share a single executable bit, so we need to keep
    // executable versions separate from non-executable versions.
    $obj .= '.x';
  }

  // Make copies of each object, obj.0, obj.1, etc., after there are too many
  // hardlinks. This can occur for the empty file, particularly.
  $n = 0;
  do {
    $stat = @lstat($obj.'.'.$n);
    if (!$stat) {
      break;
    }
    if ($stat[3] < 32000) {
      // TODO: On NTFS, this needs to be 1023. It is not apparently trivial to
      // determine if a disk is NTFS or not, or what the link limit for a disk
      // is. On linux "df -T /path/to/dir" may be useful, but on OS X this does
      // something totally different...
      break;
    }
    ++$n;
  } while (true);

  $obj = $obj.'.'.$n;

  if ($stat === false) {
    $ok = mkdir(dirname($obj), 0777, $recursive = true);
    if (!$ok) {
      throw new Exception(pht("Failed to make directory for '%s'.", $obj));
    }
    $ok = copy($soft.'/'.$path, $obj);
    if (!$ok) {
      throw new Exception(pht("Failed to copy file '%s/%s'!", $soft, $path));
    }
    if ($type === 'exec') {
      $ok = chmod($obj, 0755);
      if (!$ok) {
        throw new Exception(pht("Failed to chmod file '%s'!", $obj));
      }
    }
  }

  $ok = link($obj, $link);
  if (!$ok) {
    throw new Exception(pht("Failed to hardlink '%s' to '%s'!", $obj, $link));
  }
}

// TODO: Replace link to soft directory with link to hardened directory.
// execx('ln -sf %s %s', $dst, $hardened);

echo $hardened."\n";
exit(0);

function hash_path($hash) {
  return preg_replace('/([a-z0-9]{2})/', '\1/', $hash, 3);
}

function map_directory($dir) {
  try {
    if (Filesystem::pathExists($dir.'/.git')) {
      list($list) = execx(
        '(cd %s && git ls-tree -r --full-tree --abbrev=40 HEAD)',
        $dir);
      $list = trim($list);
      $list = explode("\n", $list);

      $map = array();
      foreach ($list as $line) {
        $matches = null;
        $regexp  = '/^(\d{6}) (\w+) ([a-z0-9]{40})\t(.*)$/';
        if (!preg_match($regexp, $line, $matches)) {
          throw new Exception(pht("Unable to parse line '%s'!", $line));
        }
        $flag = $matches[1];
        $type = $matches[2];
        $hash = $matches[3];
        $file = $matches[4];
        if ($type === 'commit') {
          // Deal with Git submodules.
          $submap = map_directory($dir.'/'.$file);
          foreach ($submap as $subfile => $info) {
            $map[$file.'/'.$subfile] = $info;
          }
        } else {
          $mask = (int)base_convert($flag, 8, 10);
          $type = 'file';
          if ($mask & 0111) {
            echo pht('EXEC: %s', $file)."\n";
            $type = 'exec';
          } else if (($mask & 0120000) === 0120000) {
            $type = 'link';
          }
          $map[$file] = array(
            'hash' => $hash,
            'type' => $type,
          );
        }
      }
      return $map;
    }
  } catch (Exception $ex) {
    phlog($ex);
    // Just drop down and go with the non-git approach.
  }

  $files = id(new FileFinder($dir))
    ->withType('f')
    ->excludePath('*/.git/*')
    ->excludePath('*/.svn/*')
    ->find();
  foreach ($files as $file) {
    if (!strncmp($file, './', 2)) {
      $file = substr($file, 2);
    }
    $data = Filesystem::readFile($dir.'/'.$file);
    $len  = strlen($data);
    $hash = sha1("blob {$len}\0{$data}");

    $type = 'file';
    if (is_link($dir.'/'.$file)) {
      $type = 'link';
    } else if (is_executable($dir.'/'.$file)) {
      $type = 'exec';
    }

    $map[$file] = array(
      'hash' => $hash,
      'type' => $type,
    );
  }

  return $map;
}
