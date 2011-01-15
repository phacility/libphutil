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
 * @group markup
 */
class PhutilXHPASTSyntaxHighlighter {

  public function setConfig($key, $value) {
    return $this;
  }

  public function highlightSource($text) {
    $scrub = false;
    if (strpos($text, '<?') === false) {
      $text = "<?php\n".$text;
      $scrub = true;
    }

    $tree = XHPASTTree::newFromData($text);

    $out = array();
    $next = null;
    foreach ($tree->getRootNode()->getTokens() as $token) {
      $value = phutil_escape_html($token->getValue());
      $class = null;
      $multi = false;
      switch ($token->getTypeName()) {
        case 'T_WHITESPACE':
          break;
        case 'T_DOC_COMMENT':
          $class = 'dc';
          $multi = true;
          break;
        case 'T_COMMENT':
          $class = 'c';
          $multi = true;
          break;
        case 'T_CONSTANT_ENCAPSED_STRING':
        case 'T_ENCAPSED_AND_WHITESPACE':
        case 'T_INLINE_HTML':
          $class = 's';
          $multi = true;
          break;
        case 'T_VARIABLE':
          $class = 'nv';
          break;
        case 'T_OPEN_TAG':
        case 'T_OPEN_TAG_WITH_ECHO':
        case 'T_CLOSE_TAG':
          $class = 'o';
          break;
        case 'T_OBJECT_OPERATOR':
          $next = 'na';
          $class = 'k';
          break;
        case 'T_LNUMBER':
        case 'T_DNUMBER':
          $class = 'm';
          break;
        case 'T_STRING':
          static $magic = array(
            'true' => true,
            'false' => true,
            'null' => true,
          );
          if (isset($magic[$value])) {
            $class = 'k';
            break;
          }
          if ($next) {
            $class = $next;
            $next = null;
          } else {
            $class = 'nx';
          }
          break;
        default:
          $class = 'k';
          break;
      }
      if ($class) {
        $value = '<span class="'.$class.'">'.$value.'</span>';
        if ($multi) {
          $value = str_replace(
            "\n",
            "</span>\n<span=\"{$class}\">",
            $value);
        }
        $out[] = $value;
      } else {
        $out[] = $value;
      }
    }

    if ($scrub) {
      array_shift($out);
    }

    return implode('', $out);
  }
}
