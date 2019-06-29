<?php

final class PhutilHTMLParser extends Phobject {

  private $cursor;

  public function parseDocument($corpus) {
    // Divide the block into sequences of "tag" and "non-tag" content. Tag
    // content is anything between angle brackets ("<" and ">"). Non-tag
    // content is anything else.

    $segment_pos = 0;
    $segments = array();
    $in_tag = false;

    for ($ii = 0; $ii < strlen($corpus); $ii++) {
      $c = $corpus[$ii];

      if ($in_tag && ($c === '>')) {
        if ($segment_pos !== null) {
          $segments[] = array(
            'tag' => $in_tag,
            'pos' => $segment_pos,
            'end' => $ii + 1,
          );
        }

        $segment_pos = $ii + 1;
        $in_tag = false;
        continue;
      }

      if (!$in_tag && ($c === '<')) {
        $segments[] = array(
          'tag' => $in_tag,
          'pos' => $segment_pos,
          'end' => $ii,
        );

        $segment_pos = $ii;
        $in_tag = true;
        continue;
      }
    }

    // Add whatever content was left at the end of the string. If we were in
    // a tag but did not find a closing ">", we treat this as normal content.
    $segments[] = array(
      'tag' => false,
      'pos' => $segment_pos,
      'end' => $ii,
    );

    // Slice the marked segments out of the raw corpus so we get a list of
    // "tag" strings and a list of "non-tag" strings.

    $parts = array();
    $corpus_length = strlen($corpus);
    foreach ($segments as $segment) {
      $tag = $segment['tag'];
      $pos = $segment['pos'];
      $len = $segment['end'] - $pos;

      // If this is a tag, we'll drop the "<" at the beginning and the ">"
      // at the end here.
      if ($tag) {
        $slice_pos = $pos + 1;
        $slice_len = $len - 2;
      } else {
        $slice_pos = $pos;
        $slice_len = $len;
      }

      if (($slice_pos < $corpus_length) && ($slice_len > 0)) {
        $content = substr($corpus, $slice_pos, $slice_len);
      } else {
        $content = '';
      }

      $parts[] = array(
        'tag' => $tag,
        'pos' => $pos,
        'len' => $len,
        'content' => $content,
      );
    }

    $root = new PhutilDOMNode();
    $this->setCursor($root);

    foreach ($parts as $part) {
      $tag = $this->newTagDOMNode($part);

      if ($tag !== null) {
        continue;
      }

      $content = $part['content'];

      // If this part is a tag, restore the angle brackets.
      if ($part['tag']) {
        $content = '<'.$content.'>';
      }

      $node = id(new PhutilDOMNode())
        ->setContent($content)
        ->setRawString($content);

      $this->getCursor()->appendChild($node);
    }

    $root->mergeContent();

    return $root;
  }

  private function newTagDOMNode(array $part) {
    if (!$part['tag']) {
      return null;
    }

    $raw_content = $part['content'];
    $content = $raw_content;

    $content = trim($content);
    $content_len = strlen($content);

    // If the tag content begins with "/", like "</td>", strip the slash
    // off and mark this as a closing tag.
    $is_close = false;
    if ($content_len > 0 && $content[0] === '/') {
      $is_close = true;
      $content = substr($content, 1);
      $content = trim($content);
      $content_len = strlen($content);
    }

    // If the tag content ends with "/", like "<td />", strip the slash off
    // and mark this as self-closing.
    $self_close = false;
    if ($content_len > 0 && $content[$content_len - 1] === '/') {
      $self_close = true;
      $content = substr($content, 0, $content_len - 1);
      $content = trim($content);
      $content_len = strlen($content);
    }

    // If this tag is both a closing tag and a self-closing tag, it is
    // not formatted correctly. Treat it as content.
    if ($self_close && $is_close) {
      return null;
    }

    // Now, split the rest of the tag into the tag name and tag attributes.
    $pieces = preg_split('/\s+/', $content, 2);
    $tag_name = $pieces[0];

    if (count($pieces) > 1) {
      $attributes = $pieces[1];
    } else {
      $attributes = '';
    }

    // If there's no tag name, this tag is not valid. Treat it as content.
    if (!strlen($tag_name)) {
      return null;
    }

    // If this is a closing tag with attributes, it's not valid. Treat it
    // as content.
    if ($is_close && strlen($attributes)) {
      return null;
    }

    $tag_name = phutil_utf8_strtolower($tag_name);

    // If we find a valid closing tag, try to find a matching tag on the stack.
    // If we find a matching tag, close it.
    // If we do not find a matching tag, treat the closing tag as content.
    if ($is_close) {
      $cursor = $this->getCursor();

      while ($cursor) {
        if ($cursor->getTagName() === $tag_name) {
          $parent = $cursor->getParentNode();
          $this->setCursor($parent);
          return true;
        }
        $cursor = $cursor->getParentNode();
      }

      return null;
    }

    if (strlen($attributes)) {
      $attribute_map = $this->parseAttributes($attributes);
      // If the attributes can't be parsed, treat the tag as content.
      if ($attribute_map === null) {
        return null;
      }
    } else {
      $attribute_map = array();
    }

    $node = id(new PhutilDOMNode())
      ->setTagName($tag_name)
      ->setAttributes($attribute_map)
      ->setRawString('<'.$raw_content.'>');

    $cursor = $this->getCursor();
    $cursor->appendChild($node);

    if (!$self_close) {
      $this->setCursor($node);
    }

    return $node;
  }

  private function setCursor(PhutilDOMNode $cursor) {
    $this->cursor = $cursor;
    return $this;
  }

  private function getCursor() {
    return $this->cursor;
  }

  private function parseAttributes($attributes) {
    $state = 'key';

    $whitespace = array(
      ' ' => true,
      "\n" => true,
      "\t" => true,
      "\r" => true,
    );

    $map = array();
    $len = strlen($attributes);
    $key_pos = null;
    for ($ii = 0; $ii < $len; $ii++) {
      $c = $attributes[$ii];
      $is_space = isset($whitespace[$c]);

      switch ($state) {
        case 'key':
          // We're looking for the start of an attribute name.

          // Skip over any whitespace.
          if ($is_space) {
            break;
          }

          // If we see "<tag =...", that isn't valid. Treat this tag as
          // content.
          if ($c === '=') {
            return null;
          }

          // If we see a quotation mark with no attribute name, that isn't
          // valid. Treat this tag as content.
          if ($c === '"') {
            return null;
          }

          // Any other character marks the beginning of an attribute name.
          // Switch the parser state to "name" to parse the name.
          $name_pos = $ii;
          $state = 'name';
          break;
        case 'name':
          // We're looking for the end of an attribute name.

          // Finding a "=" or a space character ends the attribute name.
          // Save it, then figure out what to do with the parser state.
          if ($c === '=' || $is_space) {
            $name_value = substr($attributes, $name_pos, $ii - $name_pos);
            $name_value = phutil_utf8_strtolower($name_value);

            // If this attribute already exists, the tag is invalid. This means
            // the input is something like "<tag a=1 a=2>".
            if (isset($map[$name_value])) {
              return null;
            }
          }

          // If we find an "=", that's the end of the name. Next, we're going
          // to parse a value.
          if ($c === '=') {
            $state = 'value';
            break;
          }

          // If we find whitespace, that's the end of the name. We're going
          // to look for an "=".
          if ($is_space) {
            $state = 'equals';
            break;
          }

          break;
        case 'equals':
          // We've parsed the name of an attribute and are looking for an
          // "=" character.

          // Skip over any whitespace.
          if ($is_space) {
            break;
          }

          // This is the "=" we're looking for, so we're good to go.
          if ($c === '=') {
            $state = 'value';
            break;
          }

          // If this is anything else, this is an attribute name with no
          // value. Treat it as "true" and move on. This corresponds to an
          // input like "<input disabled>".
          $map[$name_value] = true;
          $name_pos = $ii;
          $state = 'name';
          break;
        case 'value':
          // We've parsed an "=" and are looking for the start of a value.

          // Skip over any whitespace.
          if ($is_space) {
            break;
          }

          // Don't accept "<tag a==" to mean that key "a" has a value of
          // "=", since this is silly. To specify a value beginning with "=",
          // you have to quote it.
          if ($c === '=') {
            return null;
          }

          // Anything else is a value.
          $value_pos = $ii;

          // This is a quotation mark, so parse a quoted value.
          if ($c === '"') {
            $value_pos = $value_pos + 1;
            $state = 'quoted';
          } else {
            $state = 'unquoted';
          }
          break;
        case 'quoted':
          // We've started parsing a quoted value, so look for the closing
          // quote.

          // We found the closing quote, so pull out the actual value.
          if ($c === '"') {
            $attr_value = substr($attributes, $value_pos, $ii - $value_pos);

            $map[$name_value] = $attr_value;
            $state = 'key';
            break;
          }

          // Anything else is more text in the quoted value.
          break;
        case 'unquoted':
          // We've started parsing an unquoted value, so look for terminating
          // whitespace.

          // We've found some whitespace, so pull out the actual value.
          if ($is_space) {
            $attr_value = substr($attributes, $value_pos, $ii - $value_pos);

            $map[$name_value] = $attr_value;
            $state = 'key';
            break;
          }

          // Anything else is more text in the unquoted value.
          break;
      }
    }

    switch ($state) {
      case 'key':
        // We were looking for the start of an attribute name, so there's
        // nothing to clean up.
        break;
      case 'name':
        // We were looking for the end of an attribute name. Treat whatever
        // we found as a name.
        $name_value = substr($attributes, $name_pos, $len - $name_pos);

        if (isset($map[$name_value])) {
          return null;
        }

        $map[$name_value] = true;
        break;
      case 'equals':
      case 'value':
        // We found an attribute name followed by whitespace or an "=". Treat
        // whatever we found as a valid attribute name with no value.

        if (isset($map[$name_value])) {
          return null;
        }

        $map[$name_value] = true;
        break;
      case 'quoted':
      case 'unquoted':
        // We were parsing a value but ran out of characters before we found
        // the delimiter or closing quote. Treat whatever we found as a quoted
        // value.

        $attr_value = substr($attributes, $value_pos, $len - $name_pos);

        $map[$name_value] = $attr_value;
        break;
    }

    return $map;
  }

}
