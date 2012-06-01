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
 * @concrete-extensible (TODO only needed by Facebook at the moment)
 */
class PhutilRemarkupRuleHyperlink
  extends PhutilRemarkupRule {

  public function apply($text) {

    $text = preg_replace_callback(
      '@\B\\[\\[([^|\\]]+)(?:\\|([^\\]]+))?\\]\\]\B@U',
      array($this, 'markupDocumentLink'),
      $text);

    // Hyperlinks with explicit "<>" around them get linked exactly, without
    // the "<>". Angle brackets are basically special and mean "this is a URL
    // with weird characters". This is assumed to be reasonable because they
    // don't appear in normal text or normal URLs.
    $text = preg_replace_callback(
      '@[<](\w{3,}://.+?)[>]@',
      array($this, 'markupHyperlink'),
      $text);

    // Hyperlinks with explicit "()" around them get linked exactly, with the
    // "()". This is simlar to angle brackets, except that people use parens
    // in normal text so we preserve them in the output text.
    $text = preg_replace_callback(
      '@(?<=\\()(\w{3,}://.+?)(?=\\))@',
      array($this, 'markupHyperlink'),
      $text);

    // Anything else we match "ungreedily", which means we'll look for
    // stuff that's probably puncutation or otherwise not part of the URL and
    // not link it. This lets someone write "QuicK! Go to
    // http://www.example.com/!". We also apply some paren balancing rules.
    $text = preg_replace_callback(
      '@(?<=^|\s)(\w{3,}://\S+)(?=\s|$)@',
      array($this, 'markupHyperlinkUngreedy'),
      $text);

    return $text;
  }

  protected function markupHyperlink($matches) {

    $protocols = $this->getEngine()->getConfig(
      'uri.allowed-protocols',
      array());

    $protocol = id(new PhutilURI($matches[1]))->getProtocol();
    if (!idx($protocols, $protocol)) {
      // If this URI doesn't use a whitelisted protocol, don't link it. This
      // is primarily intended to prevent javascript:// silliness.
      return $this->getEngine()->storeText($matches[1]);
    }

    return $this->storeRenderedHyperlink($matches[1]);
  }

  protected function storeRenderedHyperlink($link) {
    return $this->getEngine()->storeText($this->renderHyperlink($link));
  }

  protected function renderHyperlink($link, $name = null) {
    return phutil_render_tag(
      'a',
      array(
        'href'    => $link,
        'target'  => '_blank',
      ),
      phutil_escape_html($name === null ? $link : $name));
  }

  private function markupHyperlinkUngreedy($matches) {
    $match = $matches[1];
    $tail = null;
    $trailing = null;
    if (preg_match('/[;,.:!?]+$/', $match, $trailing)) {
      $tail = $trailing[0];
      $match = substr($match, 0, -strlen($tail));
    }

    // If there's a closing paren at the end but no balancing open paren in
    // the URL, don't link the close paren. This is an attempt to gracefully
    // handle the two common paren cases, Wikipedia links and English language
    // parentheticals, e.g.:
    //
    //  http://en.wikipedia.org/wiki/Noun_(disambiguation)
    //  (see also http://www.example.com)
    //
    // We could apply a craftier heuristic here which tries to actually balance
    // the parens, but this is probably sufficient.
    if (preg_match('/\\)$/', $match) && !preg_match('/\\(/', $match)) {
      $tail = ')'.$tail;
      $match = substr($match, 0, -1);
    }

    return $this->markupHyperlink(array(null, $match)).$tail;
  }

  public function markupDocumentLink($matches) {
    $uri = trim($matches[1]);
    $name = trim(idx($matches, 2, $uri));

    // If whatever is being linked to begins with "/" or has "://", treat it
    // as a URI instead of a wiki page.
    $is_uri = preg_match('@(^/)|(://)@', $uri);

    if ($is_uri) {
      $protocols = $this->getEngine()->getConfig(
        'uri.allowed-protocols',
        array());
      $protocol = id(new PhutilURI($uri))->getProtocol();
      if (!idx($protocols, $protocol)) {
        // Don't treat this as a URI if it's not an allowed protocol.
        $is_uri = false;
      }
    }

    if (!$is_uri) {
      return $matches[0];
    }

    return $this->getEngine()->storeText($this->renderHyperlink($uri, $name));
  }

}
