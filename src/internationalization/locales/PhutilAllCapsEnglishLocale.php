<?php

/**
 * A test locale which transforms strings into uppercase.
 *
 * This can be helpful for identifying untranslated strings.
 */
final class PhutilAllCapsEnglishLocale extends PhutilLocale {

  public function getLocaleCode() {
    return 'en_A*';
  }

  public function getLocaleName() {
    return pht('English (US, ALL CAPS)');
  }

  public function getFallbackLocaleCode() {
    return 'en_US';
  }

  public function isTestLocale() {
    return true;
  }

  public function shouldPostProcessTranslations() {
    return true;
  }

  public function didTranslateString(
    $raw_pattern,
    $translated_pattern,
    array $args,
    $result_text) {
    return phutil_utf8_strtoupper($result_text);
  }

}
