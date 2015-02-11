<?php

/**
 * Much locale! Very English! Wow!
 */
final class PhutilVeryWowEnglishLocale extends PhutilLocale {

  public function getLocaleCode() {
    return 'en_W*';
  }

  public function getLocaleName() {
    return pht('English (Very Wow)');
  }

  public function getFallbackLocaleCode() {
    return 'en_US';
  }

  public function isSillyLocale() {
    return true;
  }

}
