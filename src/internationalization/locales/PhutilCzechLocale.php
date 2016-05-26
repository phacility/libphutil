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
