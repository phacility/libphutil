<?php

final class PhutilMissingSymbolException extends Exception {

  public function __construct($symbol, $type, $reason) {
    parent::__construct(
      pht(
        "Failed to load %s '%s': %s ".
        "If this symbol was recently added or moved, your library map may ".
        "be out of date. You can rebuild the map by running '%s'. ".
        "For more information, see: %s",
        $type,
        $symbol,
        $reason,
        'arc liberate',
        'http://www.phabricator.com/docs/phabricator/article/'.
        'libphutil_Libraries_User_Guide.html'));
  }

}
