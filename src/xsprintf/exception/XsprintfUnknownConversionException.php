<?php

final class XsprintfUnknownConversionException
  extends InvalidArgumentException {

  public function __construct($conversion) {
    parent::__construct("Unknown conversion {$conversion}.");
  }

}
