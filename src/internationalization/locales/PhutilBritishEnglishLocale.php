<?php

/**
 * Serious, legitimate British English locale.
 */
final class PhutilBritishEnglishLocale extends PhutilLocale {

  public function getLocaleCode() {
    return 'en_GB';
  }

  public function getLocaleName() {
    return pht('English (Great Britain)');
  }

  public function getFallbackLocaleCode() {
    return 'en_US';
  }

}
