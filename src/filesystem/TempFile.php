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

/**
 * Simple wrapper to guarantee temp file will be deleted on
 * object destruction. Used like a string to path:
 *
 *    $temp = new TempFile();
 *    Filesystem::writeFile($temp, 'Hello World');
 *    echo "wrote data to path: {$temp}";
 *
 * The extra parameter $dir can be used to specify which temporary diretcory
 * you want to create your file inside.  If not specified, it will create a
 * temp directory for your temp file.
 *
 * The class tries to be smart about what you mean to do.  For example, if you
 * don't specify a $dir to write to but give a filename, then it thinks you need
 * a temporary file of that exact filename.  If however you do specify a
 * temporary directory to write to, then it assumes you can't guarantee that
 * $filename is unique and that you want this class to handle the automatic
 * destruction of $filename when done.
 *
 * Throws Filesystem exceptions for errors.
 *
 * @group filesystem
 */
final class TempFile {
  protected $dir;
  protected $file;

  public function __construct($filename = null, $dir = null) {
    $this->dir  = Filesystem::createTemporaryDirectory();
    if ($filename === null) {
      $this->file = tempnam($this->dir, getmypid().'-');
    } else {
      $this->file = $this->dir.'/'.$filename;
    }

    Filesystem::writeFile($this, '');
  }

  public function __toString() {
    return $this->file;
  }

  public function __destruct() {
    Filesystem::remove($this->dir);
    // Note that the function tempnam() doesn't guarantee it will return a
    // file inside the dir you passed to the function.
    if (file_exists($this->file)) {
      unlink($this->file);
    }
  }

  public function preserve() {
    $this->destroy = false;
  }
}
