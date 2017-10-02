<?php

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

function phutil_console_select($prompt, $min, $max) {
  $select_options = '['.$min.' - '.$max.']';
  do {
    $response = phutil_console_prompt($prompt.' '.$select_options);
    $selection = trim($response);

    if (preg_match('/^\d+\z/', $selection)) {
      $selection = (int)$selection;
      if ($selection >= $min && $selection <= $max) {
        return $selection;
      }
    }
  } while (true);
}

function phutil_console_prompt($prompt, $history = '') {
  echo "\n\n";
  $prompt = phutil_console_wrap($prompt.' ', 4);

  try {
    phutil_console_require_tty();
  } catch (PhutilConsoleStdinNotInteractiveException $ex) {
    // Throw after echoing the prompt so the user has some idea what happened.
    echo $prompt;
    throw $ex;
  }

  // `escapeshellarg` makes double quotes in the command below disappear on
  // Windows, which breaks prompts when using history. See T6348
  $use_history = !phutil_is_windows();
  if ($history == '') {
    $use_history = false;
  } else {
    // Test if bash is available by seeing if it can run `true`.
    list($err) = exec_manual('bash -c %s', 'true');
    if ($err) {
      $use_history = false;
    }
  }

  if (!$use_history) {
    echo $prompt;
    $response = fgets(STDIN);
  } else {
    // There's around 0% chance that readline() is available directly in PHP,
    // so we're using bash/read/history instead.
    $command = csprintf(
      'bash -c %s',
      csprintf(
        'history -r %s 2>/dev/null; '.
        'read -e -p %s; '.
        'echo "$REPLY"; '.
        'history -s "$REPLY" 2>/dev/null; '.
        'history -w %s 2>/dev/null',
        $history,
        $prompt,
        $history));

    // execx() doesn't work with input, phutil_passthru() doesn't return output.
    $response = shell_exec($command);
  }

  return rtrim($response, "\r\n");
}


/**
 * Soft wrap text for display on a console, respecting UTF8 character boundaries
 * and ANSI color escape sequences.
 *
 * @param   string  Text to wrap.
 * @param   int     Optional indent level.
 * @param   bool    True to also indent the first line.
 * @return  string  Wrapped text.
 */
function phutil_console_wrap($text, $indent = 0, $with_prefix = true) {
  $lines = array();

  $width = (78 - $indent);
  $esc = chr(27);

  $break_pos = null;
  $len_after_break = 0;
  $line_len = 0;

  $line = array();
  $lines = array();

  $vector = phutil_utf8v($text);
  $vector_len = count($vector);
  for ($ii = 0; $ii < $vector_len; $ii++) {
    $chr = $vector[$ii];

    // If this is an ANSI escape sequence for a color code, just consume it
    // without counting it toward the character limit. This prevents lines
    // with bold/color on them from wrapping too early.
    if ($chr == $esc) {
      for ($ii; $ii < $vector_len; $ii++) {
        $line[] = $vector[$ii];
        if ($vector[$ii] == 'm') {
          break;
        }
      }
      continue;
    }

    $line[] = $chr;

    ++$line_len;
    ++$len_after_break;

    if ($line_len > $width) {
      if ($break_pos !== null) {
        $slice = array_slice($line, 0, $break_pos);
        while (count($slice) && end($slice) == ' ') {
          array_pop($slice);
        }
        $slice[] = "\n";
        $lines[] = $slice;
        $line = array_slice($line, $break_pos);

        $line_len = $len_after_break;
        $len_after_break = 0;
        $break_pos = null;
      }
    }

    if ($chr == ' ') {
      $break_pos = count($line);
      $len_after_break = 0;
    }

    if ($chr == "\n") {
      $lines[] = $line;
      $line = array();

      $len_after_break = 0;
      $line_len = 0;
      $break_pos = null;
    }
  }

  if ($line) {
    if ($line) {
      $lines[] = $line;
    }
  }

  $pre = null;
  if ($indent) {
    $pre = str_repeat(' ', $indent);
  }

  foreach ($lines as $idx => $line) {
    if ($idx == 0 && !$with_prefix) {
      $prefix = null;
    } else {
      $prefix = $pre;
    }

    $lines[$idx] = $prefix.implode('', $line);
  }

  return implode('', $lines);
}


function phutil_console_require_tty() {
  if (function_exists('posix_isatty') && !posix_isatty(STDIN)) {
    throw new PhutilConsoleStdinNotInteractiveException();
  }
}


/**
 * Determine the width of the terminal, if possible. Returns `null` on failure.
 *
 * @return int|null Terminal width in characters, or null on failure.
 */
function phutil_console_get_terminal_width() {
  return PhutilConsoleMetrics::getDefaultConsole()
    ->getTerminalWidth();
}
