<?php

/**
 * Very simple class to guess the languages of source files which we failed to
 * determine by examining file name/extension rules.
 */
final class PhutilLanguageGuesser extends Phobject {

  /**
   * Guess which computer programming language a file is written in.
   *
   * @param string Source text of the file.
   * @return mixed Language string, or null if unable to guess.
   */
  public static function guessLanguage($source) {

    static $patterns = array(
      // Capture "#!/usr/bin/env php" sorts of things.
      '@^#!.*bin/env\s+(\S+)@' => 1,
      // Capture "#!/usr/bin/php" sorts of things.
      '@^#!.*bin/(\S+)@' => 1,
      // Capture initial "<?php", which means PHP.
      '@^\s*<[?](php)@' => 1,
      // Capture emacs "mode" header.
      '@^.*-[*]-.*mode\s*:\s*(\S+).*-[*]-.*$@m' => 1,
      // Look for things that seem to be diffs.
      '/^---.*$\n^[+]{3}.*$\n^@@/m' => 'diff',
      '/^diff --git/' => 'diff',
      // Look for plausible console output.
      '@^(?:\S+[\\\\/] )?[$] @' => 'console',
    );

    foreach ($patterns as $pattern => $language) {
      $matches = null;
      if (preg_match($pattern, $source, $matches)) {
        if (is_numeric($language)) {
          return $matches[$language];
        } else {
          return $language;
        }
      }
    }

    return null;
  }

}
