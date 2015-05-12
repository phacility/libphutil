<?php

/**
 * Thrown when you prompt the user with @{function:phutil_console_prompt} or
 * @{function:phutil_console_confirm} but stdin is not an interactive TTY so
 * the user can't possibly respond. Usually this means the user ran the command
 * with something piped into stdin.
 */
final class PhutilConsoleStdinNotInteractiveException extends Exception {

  public function __construct() {
    parent::__construct(
      pht(
        'The program is attempting to read user input, but stdin is being '.
        'piped from some other source (not a TTY).'));
  }

}
