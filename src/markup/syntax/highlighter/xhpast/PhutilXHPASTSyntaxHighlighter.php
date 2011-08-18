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

  private $config = array();

  public function setConfig($key, $value) {
    $this->config[$key] = $value;
    return $this;
  }

  public function getHighlightFuture($source) {
    try {
      $result = $this->applyXHPHighlight($source);
      return new ImmediateFuture($result);
    } catch (Exception $ex) {
      if (!empty($this->config['pygments.enabled'])) {
        // Fall back to Pygments if we failed to highlight using XHP. The XHP
        // highlighter currently uses a parser, not just a lexer, so it fails on
        // snippets which aren't valid syntactically.
        return id(new PhutilPygmentsSyntaxHighlighter())
          ->setConfig('language', 'php')
          ->getHighlightFuture($source);
      } else {
        return id(new PhutilDefaultSyntaxHighlighter())
          ->getHighlightFuture($source);
      }
    }
  }

  private function applyXHPHighlight($source) {

    $scrub = false;
    if (strpos($source, '<?') === false) {
      $source = "<?php\n".$source."\n";
      $scrub = true;
    }

    $tree = XHPASTTree::newFromData($source);

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
        $l = '<span class="'.$class.'">';
        $r = '</span>';

        $value = $l.$value.$r;
        if ($multi) {
          // If the token may have multiple lines in it, make sure each
          // <span> crosses no more than one line so the lines can be put
          // in a table, etc., later.
          $value = str_replace(
            "\n",
            $r."\n".$l,
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

    return rtrim(implode('', $out));
  }

}
