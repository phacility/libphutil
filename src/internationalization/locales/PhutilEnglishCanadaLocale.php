<?php

/**
 * Locale for "English (Canada)".
 */
final class PhutilEnglishCanadaLocale extends PhutilLocale {

  public function getLocaleCode() {
    return 'en_CA';
  }

  public function getLocaleName() {
    return pht('English (Canada)');
  }

  public function getFallbackLocaleCode() {
    return 'en_US';
  }

}
