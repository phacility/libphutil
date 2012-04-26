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
 * Very simple class to guess the languages of source files which we failed to
 * determine by examining file name/extension rules.
 *
 * @group util
 */
final class PhutilLanguageGuesser {

  /**
   * Guess which computer programming language a file is written in.
   *
   * @param string Source text of the file.
   * @return mixed Language string, or null if unable to guess.
   */
  public static function guessLanguage($source) {
    static $patterns = array(
      // Capture "#!/usr/bin/env php" sorts of things.
      '@^#!.*bin/env\s+(\S+)@',
      // Capture "#!/usr/bin/php" sorts of things.
      '@^#!.*bin/(\S+)@',
      // Capture initial "<?php", which means PHP.
      '@^\s*<[?](php)@',
      // Capture emacs "mode" header.
      '@^.*-[*]-.*mode\s*:\s*(\S+).*-[*]-.*$@m',
    );

    foreach ($patterns as $pattern) {
      $matches = null;
      if (preg_match($pattern, $source, $matches)) {
        return $matches[1];
      }
    }

    return null;
  }

}
