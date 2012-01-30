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
 * Exception thrown by Filesystem to indicate an error accessing the file
 * system.
 *
 * @group filesystem
 */
final class FilesystemException extends Exception {

  protected $path;

  /**
   * Create a new FilesystemException, providing a path and a message.
   *
   * @param  string  Path that caused the failure.
   * @param  string  Description of the failure.
   */
  public function __construct($path, $message) {
    $this->path = $path;
    parent::__construct($message);
  }


  /**
   * Retrieve the path associated with the exception. Generally, this is
   * something like a path that couldn't be read or written, or a path that
   * was expected to exist but didn't.
   *
   * @return string  Path associated with the exception.
   */
  public function getPath() {
    return $this->path;
  }

}
