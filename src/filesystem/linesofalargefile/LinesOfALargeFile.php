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
 * Read the lines of a large file. Experimental and probably buggy.
 *
 * @group filesystem
 */
final class LinesOfALargeFile implements Iterator {

  private $file;
  private $handle;

  private $pos;
  private $buf;
  private $num;
  private $line;
  private $valid;

  public function __construct($file) {
    $this->file = $file;
  }

  public function __destruct() {
    $this->closeHandle();
  }

  private function closeHandle() {
    if ($this->handle) {
      fclose($this->handle);
      $this->handle = null;
    }
  }

  public function rewind() {
    $this->closeHandle();
    $this->handle = @fopen($this->file, 'r');
    if (!$this->handle) {
      throw new FilesystemException(
        $this->file,
        "Failed to open file!");
    }

    $this->buf = '';
    $this->pos = 0;
    $this->num = 0;
    $this->valid = true;

    $this->next();
  }

  public function key() {
    return $this->num;
  }

  public function current() {
    return $this->line;
  }

  public function valid() {
    return $this->valid;
  }

  public function next() {
    if (strlen($this->buf)) {
      $endl = strpos($this->buf, "\n", $this->pos);
      if ($endl !== false) {
        $this->num++;
        $this->line = substr($this->buf, $this->pos, ($endl - $this->pos));
        $this->pos = $endl + 1;
        return;
      }
      $this->buf = substr($this->buf, $this->pos);
      $this->pos = 0;
    }

    $more = fread($this->handle, 2048);
    if (strlen($more)) {
      $this->buf .= $more;
      $this->next();
    } else {
      if (strlen($this->buf)) {
        $this->num++;
        $this->line = $this->buf;
        $this->buf = null;
      } else {
        $this->valid = false;
      }
    }
  }

}
