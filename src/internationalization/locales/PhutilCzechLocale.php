<?php

/**
 * Locale for "Czech (Czech Republic)".
 */
final class PhutilCzechLocale extends PhutilLocale {

  public function getLocaleCode() {
    return 'cs_CZ';
  }

  public function getLocaleName() {
    return pht('Czech (Czech Republic)');
  }

  public function isTestLocale() {
    // This doesn't have any translations yet so mark it as a test locale
    // for now.
    return true;
  }

  public function selectPluralVariant($variant, array $translations) {
    list($singular, $paucal, $plural) = $translations;

    if ($variant == 1) {
      return $singular;
    }

    if ($variant >= 2 && $variant <= 4) {
      return $paucal;
    }

    return $plural;
  }

}
