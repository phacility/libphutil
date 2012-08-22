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
 * @group markup
 */
final class PhutilLexerSyntaxHighlighter extends PhutilSyntaxHighlighter {

  private $config = array();

  public function setConfig($key, $value) {
    $this->config[$key] = $value;
    return $this;
  }

  public function getHighlightFuture($source) {
    $strip = false;
    $state = 'start';
    $lang = idx($this->config, 'language');

    if ($lang == 'php') {
      if (strpos($source, '<?') === false) {
        $state = 'php';
      }
    }

    $lexer = idx($this->config, 'lexer');
    $tokens = $lexer->getTokens($source, $state);
    $tokens = $lexer->mergeTokens($tokens);

    $result = array();
    foreach ($tokens as $token) {
      list($type, $value, $context) = $token;
      $value = phutil_escape_html($value);

      $data_name = null;
      switch ($type) {
        case 'nc':
        case 'nf':
        case 'na':
          $data_name = ' data-symbol-name="'.$value.'"';
          break;
      }

      $data_context = null;
      if ($context) {
        $context = phutil_escape_html($context);
        $data_context = ' data-symbol-context="'.$context.'"';
      }

      $class_name = null;
      if ($type) {
        $class_name = ' class="'.$type.'"';
      }

      if (strpos($value, "\n") !== false) {
        $value = explode("\n", $value);
      } else {
        $value = array($value);
      }
      foreach ($value as $part) {
        if (strlen($part)) {
          if ($class_name) {
            $result[] =
              '<span'.$class_name.$data_context.$data_name.'>'.
                $part.
              '</span>';
          } else {
            $result[] = $part;
          }
        }
        $result[] = "\n";
      }

      // Throw away the last "\n".
      array_pop($result);
    }

    $result = implode('', $result);

    return new ImmediateFuture($result);
  }

}
