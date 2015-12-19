<?php

/**
 * Arrr!
 */
final class PhutilPirateEnglishLocale extends PhutilLocale {

  public function getLocaleCode() {
    return 'en_P*';
  }

  public function getLocaleName() {
    return pht('English (Pirate)');
  }

  public function getFallbackLocaleCode() {
    return 'en_US';
  }

  public function isSillyLocale() {
    return true;
  }

}
