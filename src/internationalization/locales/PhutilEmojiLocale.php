<?php

/**
 * A picture is worth a thousand words.
 */
final class PhutilEmojiLocale extends PhutilLocale {

  public function getLocaleCode() {
    return 'en_X*';
  }

  public function getLocaleName() {
    return pht('Emoji (Internet)');
  }

  public function getFallbackLocaleCode() {
    return 'en_US';
  }

  public function isSillyLocale() {
    return true;
  }

  public function selectPluralVariant($variant, array $translations) {
    // Emoji have a unique variant for every available value: 0, 1, 2, 3, ...
    if (count($translations) <= $variant) {
      return end($translations);
    }

    return $translations[$variant];
  }

}
