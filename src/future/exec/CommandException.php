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
 * Exception thrown when a system command fails.
 * @group exec
 */
final class CommandException extends Exception {

  protected $command;
  protected $stdout;
  protected $stderr;
  protected $error;

  public function __construct($message, $command, $error, $stdout, $stderr) {
    parent::__construct($message);
    $this->command = $command;
    $this->error = $error;
    $this->stdout = $stdout;
    $this->stderr = $stderr;
  }

  public function getCommand() {
    return $this->command;
  }

  public function getError() {
    return $this->error;
  }

  public function getStdout() {
    return $this->stdout;
  }

  public function getStderr() {
    return $this->stderr;
  }
}

