<?php

/**
 * @group markup
 */
final class PhutilRemarkupRuleDocumentLink
  extends PhutilRemarkupRule {

  public function apply($text) {

    // Handle mediawiki-style links: [[ href | name ]]
    $text = preg_replace_callback(
      '@\B\\[\\[([^|\\]]+)(?:\\|([^\\]]+))?\\]\\]\B@U',
      array($this, 'markupDocumentLink'),
      $text);

    // Handle markdown-style links: [name](href)
    $text = preg_replace_callback(
      '@\B\\[([^\\]]+)\\]\\(([^\\)]+)\\)\B@U',
      array($this, 'markupAlternateLink'),
      $text);

    return $text;
  }

  protected function renderHyperlink($link, $name) {
    if ($this->getEngine()->isTextMode()) {
      $text = $link;
      if (strncmp($link, '/', 1) == 0) {
        $text = rtrim($this->getEngine()->getConfig('uri.prefix'), '/').$text;
      }
      if ($link == $name) {
        return $text;
      }
      return $name.' <'.$text.'>';
    }

    if ($this->getEngine()->getState('toc')) {
      return $name;
    } else {
      return phutil_tag(
        'a',
        array(
          'href'    => $link,
          'target'  => '_blank',
        ),
        $name);
    }
  }

  public function markupAlternateLink($matches) {
    $uri = trim($matches[2]);

    // NOTE: We apply some special rules to avoid false positives here. The
    // major concern is that we do not want to convert `x[0][1](y)` in a
    // discussion about C source code into a link. To this end, we:
    //
    //   - Don't match at word boundaries;
    //   - require the URI to contain a "/" character; and
    //   - reject URIs which being with a quote character.

    if ($uri[0] == '"' || $uri[0] == "'" || $uri[0] == '`') {
      return $matches[0];
    }

    if (strpos($uri, '/') === false) {
      return $matches[0];
    }

    return $this->markupDocumentLink(
      array(
        $matches[0],
        $matches[2],
        $matches[1],
      ));
  }

  public function markupDocumentLink($matches) {
    $uri = trim($matches[1]);
    $name = trim(idx($matches, 2, $uri));

    // If whatever is being linked to begins with "/" or has "://", treat it
    // as a URI instead of a wiki page.
    $is_uri = preg_match('@(^/)|(://)@', $uri);

    if ($is_uri && strncmp('/', $uri, 1)) {
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
