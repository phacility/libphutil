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

function phutil_console_format($format /* ... */) {
  $args = func_get_args();
  return call_user_func_array(
    array('PhutilConsoleFormatter', 'formatString'),
    $args);
}

function phutil_console_confirm($prompt, $default_no = true) {

  $prompt_options = $default_no ? '[y/N]' : '[Y/n]';

  do {
    $response = phutil_console_prompt($prompt.' '.$prompt_options);
    $c = trim(strtolower($response));
  } while ($c != 'y' && $c != 'n' && $c != '');
  echo "\n";

  if ($default_no) {
    return ($c == 'y');
  } else {
    return ($c != 'n');
  }
}

function phutil_console_prompt($prompt) {

  $prompt = "\n\n    ".$prompt." ";
  $prompt = phutil_console_wrap($prompt, 4);

  echo $prompt;
  $response = fgets(STDIN);

  return rtrim($response, "\n");
}

function phutil_console_wrap($text, $indent = 0) {
  $indent_string = '';
  if ($indent) {
    $indent_string = str_repeat(' ', $indent);
  }
  return wordwrap($text, 78 - $indent, "\n".$indent_string);
}
