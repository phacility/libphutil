<?php

/**
 * A test locale which displays the raw strings which are fed into
 * the translation engine.
 */
final class PhutilRawEnglishLocale extends PhutilLocale {

  public function getLocaleCode() {
    return 'en_R*';
  }

  public function getLocaleName() {
    return pht('English (Raw Strings)');
  }

  public function isTestLocale() {
    return true;
  }

}
