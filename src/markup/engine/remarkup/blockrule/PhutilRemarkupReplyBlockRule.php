<?php

final class PhutilRemarkupReplyBlockRule extends PhutilRemarkupBlockRule {

  public function getPriority() {
    return 400.0;
  }

  public function getMatchingLineCount(array $lines, $cursor) {
    $pos = $cursor;

    if (preg_match('/^>>!/', $lines[$pos])) {
      do {
        ++$pos;
      } while (isset($lines[$pos]) && preg_match('/^>/', $lines[$pos]));
    }

    return ($pos - $cursor);
  }

  public function supportsChildBlocks() {
    return true;
  }

  public function extractChildText($text) {
    $text = phutil_split_lines($text, true);

    $head = array();
    $body = array();

    $head = substr(reset($text), 3);

    $body = array_slice($text, 1);

    // Remove the carets.
    foreach ($body as $key => $line) {
      $body[$key] = substr($line, 1);
    }

    // Strip leading empty lines.
    foreach ($body as $key => $line) {
      if (strlen(trim($line))) {
        break;
      }
      unset($body[$key]);
    }

    return array(trim($head), implode('', $body));
  }

  public function markupText($text, $children) {
    $text = $this->applyRules($text);

    if ($this->getEngine()->isTextMode()) {
      $children = phutil_split_lines($children, true);
      foreach ($children as $key => $child) {
        if (strlen(trim($child))) {
          $children[$key] = '> '.$child;
        } else {
          $children[$key] = '>'.$child;
        }
      }
      $children = implode('', $children);

      return $text."\n\n".$children;
    }

    return phutil_tag(
      'blockquote',
      array(
        'class' => 'remarkup-reply-block',
      ),
      array(
        "\n",
        phutil_tag(
          'div',
          array(
            'class' => 'remarkup-reply-head',
          ),
          $text),
        "\n",
        phutil_tag(
          'div',
          array(
            'class' => 'remarkup-reply-body',
          ),
          $children),
        "\n",
      ));
  }

}
