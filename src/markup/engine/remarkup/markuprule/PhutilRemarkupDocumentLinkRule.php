<?php

final class PhutilRemarkupDocumentLinkRule extends PhutilRemarkupRule {

  public function getPriority() {
    return 150.0;
  }

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
      if (strncmp($link, '/', 1) == 0 || strncmp($link, '#', 1) == 0) {
        $base = $this->getEngine()->getConfig('uri.prefix');
        if (strncmp($link, '/', 1) == 0) {
          $base = rtrim($base, '/');
        }
        $text = $base.$text;
      }

      // If present, strip off "mailto:" or "tel:".
      $text = preg_replace('/^(?:mailto|tel):/', '', $text);

      if ($link == $name) {
        return $text;
      }
      return $name.' <'.$text.'>';
    }

    // By default, we open links in a new window or tab. For anchors on the same
    // page, just jump normally.
    $target = '_blank';
    if (strncmp($link, '#', 1) == 0) {
      $target = null;
    }

    $name = preg_replace('/^(?:mailto|tel):/', '', $name);

    if ($this->getEngine()->getState('toc')) {
      return $name;
    } else {
      return phutil_tag(
        'a',
        array(
          'href'    => $link,
          'class'   => 'remarkup-link',
          'target'  => $target,
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
    //   - require the URI to contain a "/" character or "@" character; and
    //   - reject URIs which being with a quote character.

    if ($uri[0] == '"' || $uri[0] == "'" || $uri[0] == '`') {
      return $matches[0];
    }

    if (strpos($uri, '/') === false &&
        strpos($uri, '@') === false &&
        strncmp($uri, 'tel:', 4)) {
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

    // If whatever is being linked to begins with "/" or "#", or has "://",
    // or is "mailto:" or "tel:", treat it as a URI instead of a wiki page.
    $is_uri = preg_match('@(^/)|(://)|(^#)|(^(?:mailto|tel):)@', $uri);

    if ($is_uri && strncmp('/', $uri, 1) && strncmp('#', $uri, 1)) {
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
