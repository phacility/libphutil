<?php

/**
 * Simple syntax highlighter for console output. We just try to highlight the
 * commands so it's easier to follow transcripts.
 *
 * @group markup
 */
final class PhutilConsoleSyntaxHighlighter {

  private $config = array();
  private $replaceClass;

  public function setConfig($key, $value) {
    $this->config[$key] = $value;
    return $this;
  }

  public function getHighlightFuture($source) {

    $in_command = false;
    $lines = explode("\n", $source);
    foreach ($lines as $key => $line) {
      $matches = null;

      // Parse commands like this:
      //
      //   some/path/ $ ./bin/example # Do things
      //
      // ...into path, command, and comment components.

      $pattern =
        '@'.
        ($in_command ? '()(.*?)' : '^(\S+[\\\\/] )?([$] .*?)').
        '(#.*|\\\\)?$@';

      if (preg_match($pattern, $line, $matches)) {
        $line = '';
        if ($matches[1]) {
          $line .= phutil_escape_html($matches[1]);
        }
        $line .= '<span class="gp">'.phutil_escape_html($matches[2]).'</span>';
        if (!empty($matches[3])) {
          $line .= '<span class="k">'.phutil_escape_html($matches[3]).'</span>';
        }
        $lines[$key] = $line;
        $in_command = (idx($matches, 3) == '\\');
      } else {
        $lines[$key] = '<span class="go">'.phutil_escape_html($line).'</span>';
      }
    }
    $lines = implode("\n", $lines);

    return new ImmediateFuture($lines);
  }

}
