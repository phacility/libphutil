<?php

abstract class PhutilTranslation extends Phobject {

  /**
   * Get the locale code which this class translates text for, like
   * "en_GB".
   *
   * This should correspond to a valid subclass of @{class:PhutilLocale}.
   *
   * @return string Locale code for this translation.
   */
  abstract public function getLocaleCode();


  /**
   * Return a map of all translations.
   *
   * @return map<string, wild> Map of raw strings to translations.
   */
  abstract protected function getTranslations();


  /**
   * Return a filtered map of all strings in this translation.
   *
   * Filters out empty/placeholder translations.
   *
   * @return map<string, wild> Map of raw strings to translations.
   */
  final public function getFilteredTranslations() {
    $translations = $this->getTranslations();

    foreach ($translations as $key => $translation) {
      if ($translation === null) {
        unset($translations[$key]);
      }
    }

    return $translations;
  }


  /**
   * Load all available translation objects.
   *
   * @return list<PhutilTranslation> List of available translation sources.
   */
  public static function loadAllTranslations() {
    return id(new PhutilClassMapQuery())
      ->setAncestorClass(__CLASS__)
      ->execute();
  }


  /**
   * Load the complete translation map for a locale.
   *
   * This will compile primary and fallback translations into a single
   * translation map.
   *
   * @param string Locale code, like "en_US".
   * @return map<string, wild> Map of all avialable translations.
   */
  public static function getTranslationMapForLocale($locale_code) {
    $locale = PhutilLocale::loadLocale($locale_code);

    $translations = self::loadAllTranslations();

    $results = array();
    foreach ($translations as $translation) {
      if ($translation->getLocaleCode() == $locale_code) {
        $results += $translation->getFilteredTranslations();
      }
    }

    $fallback_code = $locale->getFallbackLocaleCode();
    if ($fallback_code !== null) {
      $results += self::getTranslationMapForLocale($fallback_code);
    }

    return $results;
  }

}
