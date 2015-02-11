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

}
