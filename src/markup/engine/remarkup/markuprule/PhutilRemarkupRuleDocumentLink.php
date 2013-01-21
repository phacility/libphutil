<?php

/**
 * @group markup
 */
final class PhutilRemarkupRuleDocumentLink
  extends PhutilRemarkupRule {

  public function apply($text) {

    $text = preg_replace_callback(
      '@\B\\[\\[([^|\\]]+)(?:\\|([^\\]]+))?\\]\\]\B@U',
      array($this, 'markupDocumentLink'),
      $text);

    return $text;
  }

  protected function renderHyperlink($link, $name) {
    if ($this->getEngine()->getState('toc')) {
      return phutil_escape_html($name);
    } else {
      return phutil_render_tag(
        'a',
        array(
          'href'    => $link,
          'target'  => '_blank',
        ),
        phutil_escape_html($name));
    }
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
