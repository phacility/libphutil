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

/**
 * PHP API for `find`.
 *
 * @group filesystem
 */
class FileFinder {

  protected $root;
  protected $exclude = array();
  protected $paths = array();
  protected $suffix = array();
  protected $type;
  protected $generateChecksums = false;

  public function __construct($root) {
    $this->root = $root;
  }

  public function excludePath($path) {
    $this->exclude[] = $path;
    return $this;
  }

  public function withSuffix($suffix) {
    $this->suffix[] = '*.'.$suffix;
    return $this;
  }

  public function withPath($path) {
    $this->paths[] = $path;
    return $this;
  }

  public function withType($type) {
    $this->type = $type;
    return $this;
  }

  public function setGenerateChecksums($generate) {
    $this->generateChecksums = $generate;
    return $this;
  }

  public function find() {
    $args = array();
    $command = array();

    $command[] = '(cd %s; ';
    $args[] = $this->root;

    $command[] = 'find .';

    if ($this->exclude) {
      $command[] = $this->generateList('path', $this->exclude).' -prune';
      $command[] = '-o';
    }

    if ($this->type) {
      $command[] = '-type %s';
      $args[] = $this->type;
    }

    if ($this->suffix) {
      $command[] = $this->generateList('name', $this->suffix);
    }

    if ($this->paths) {
      $command[] = $this->generateList('wholename', $this->paths);
    }

    $command[] = '-print0';

    if ($this->generateChecksums) {
      static $md5sum_binary = null;
      if ($md5sum_binary == null) {

        $options = array(
          'md5sum' => 'md5sum',
          'md5'    => 'md5 -r',
        );
        foreach ($options as $bin => $choose) {
          list($err) = exec_manual('which %s', $bin);
          if ($err == 0) {
            $md5sum_binary = $choose;
            break;
          }
        }
        if ($md5sum_binary === null) {
          throw new Exception(
            "Unable to locate the md5/md5sum binary for this system.");
        }
      }
      $command[] = ' | xargs -0 -n512 '.$md5sum_binary;
    }

    $command[] = ')';

    list($stdout) = call_user_func_array(
      'execx',
      array_merge(
        array(implode(' ', $command)),
        $args));

    if (!$this->generateChecksums) {
      return explode("\0", trim($stdout));
    } else {
      $stdout = trim($stdout);
      $map = array();
      foreach (explode("\n", $stdout) as $line) {
        $file = substr($line, 34);
        if ($file == '-') {
          continue;
        }
        // This mess is to make this class work on both mainline Linux systems
        // and OSX, which has subtly different 'find' semantics.
        $file = $this->root.ltrim($file, '.');
        $map[$file] = substr($line, 0, 32);
      }
      return $map;
    }
  }

  protected function generateList($flag, array $items) {
    $items = array_map('escapeshellarg', $items);
    foreach ($items as $key => $item) {
      $items[$key] = '-'.$flag.' '.$item;
    }
    $items = implode(' -o ', $items);
    return '\\( '.$items.' \\)';
  }
}

