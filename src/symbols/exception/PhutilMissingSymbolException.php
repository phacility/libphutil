<?php

/**
 * @group library
 */
final class PhutilMissingSymbolException extends Exception {
  public function __construct($symbol) {
    parent::__construct(
      "Failed to load symbol '{$symbol}'. ".
      "If this symbol was recently added or moved, your library map may ".
      "be out of date. You can rebuild the map by running 'arc liberate'. ".
      "For more information, see: ".
      "http://www.phabricator.com/docs/phabricator/article/".
      "libphutil_Libraries_User_Guide.html");
  }
}
