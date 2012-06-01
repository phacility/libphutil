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
 * Thrown when you prompt the user with @{function:phutil_console_prompt} or
 * @{function:phutil_console_confirm} but stdin is not an interactive TTY so
 * the user can't possibly respond. Usually this means the user ran the command
 * with something piped into stdin.
 *
 * @group console
 */
final class PhutilConsoleStdinNotInteractiveException extends Exception {
  public function __construct() {
    parent::__construct(
      "The program is attempting to read user input, but stdin is being piped ".
      "from some other source (not a TTY).");
  }
}
