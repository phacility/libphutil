<?php

final class PhutilRemarkupReplyBlockRule extends PhutilRemarkupBlockRule {

  public function getPriority() {
    return 400;
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

    if ($this->getEngine()->isHTMLMailMode()) {
      $block_attributes = array(
        'style' => 'border-left: 3px solid #8C98B8;
          color: #6B748C;
          font-style: italic;
          margin: 4px 0 12px 0;
          padding: 8px 12px;
          background-color: #F8F9FC;',
      );
      $head_attributes = array(
        'style' => 'font-style: normal;
          padding-bottom: 4px;',
      );
      $reply_attributes = array(
        'style' => 'margin: 0;
          padding: 0;
          border: 0;
          color: rgb(107, 116, 140);',
      );
    } else {
      $block_attributes = array(
        'class' => 'remarkup-reply-block',
      );
      $head_attributes = array(
        'class' => 'remarkup-reply-head',
      );
      $reply_attributes = array(
        'class' => 'remarkup-reply-body',
      );
    }

    return phutil_tag(
      'blockquote',
      $block_attributes,
      array(
        "\n",
        phutil_tag(
          'div',
          $head_attributes,
          $text),
        "\n",
        phutil_tag(
          'div',
          $reply_attributes,
          $children),
        "\n",
      ));
  }

}
