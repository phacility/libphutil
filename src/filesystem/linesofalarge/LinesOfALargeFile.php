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
 * Read the lines of a file, one at a time. This allows you to process large
 * files without holding them in memory. In most cases, it is more efficient
 * (and certainly simpler) to read the entire file and `explode()` it. For more
 * information, see @{class:LinesOfALarge}. See also
 * @{class:LinesOfALargeExecFuture}, for a similar abstraction that works on
 * executed commands.
 *
 *   foreach (new LinesOfALargeFile('/some/large/logfile.log') as $line) {
 *     // ...
 *   }
 *
 * If the file can not be read, a @{class:FilesystemException} is thrown.
 *
 * @task construct  Construction
 * @task internals  Internals
 * @group filesystem
 */
final class LinesOfALargeFile extends LinesOfALarge {

  private $fileName;
  private $handle;


/* -(  Construction  )------------------------------------------------------- */


  /**
   * To construct, pass the path to a file.
   *
   * @param string File path to read.
   * @return void
   * @task construct
   */
  public function __construct($file_name) {
    $this->fileName = Filesystem::resolvePath((string)$file_name);
  }


/* -(  Internals  )---------------------------------------------------------- */


  /**
   * Closes the file handle.
   *
   * @return void
   * @task internals
   */
  public function __destruct() {
    $this->closeHandle();
  }


  /**
   * Close the file handle, if it is open.
   *
   * @return $this
   * @task internals
   */
  private function closeHandle() {
    if ($this->handle) {
      fclose($this->handle);
      $this->handle = null;
    }
    return $this;
  }


  /**
   * Closes the file handle if it is open, and reopens it.
   *
   * @return void
   * @task internals
   */
  protected function willRewind() {
    $this->closeHandle();
    $this->handle = @fopen($this->fileName, 'r');
    if (!$this->handle) {
      throw new FilesystemException(
        $this->fileName,
        "Failed to open file!");
    }
  }


  /**
   * Read the file chunk-by-chunk.
   *
   * @return  string  Next chunk of the file.
   * @task internals
   */
  public function readMore() {

    // NOTE: At least on OSX in reasonably normal test cases, increasing the
    // size of this read has no impact on performance.

    $more = @fread($this->handle, 2048);
    if ($more === false) {
      throw new FilesystemException(
        $this->fileName,
        "Failed to read file!");
    }
    return $more;
  }

}
