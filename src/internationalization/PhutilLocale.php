<?php

/**
 * Defines a locale for translations.
 *
 * Examples might include "English (US)" or "Japanese".
 */
abstract class PhutilLocale extends Phobject {

  /**
   * Get the local identifier code, like "en_US".
   *
   * @return string Locale identifier code.
   */
  abstract public function getLocaleCode();


  /**
   * Get the human-readable locale name, like "English (US)".
   *
   * @return string Human-readable locale name.
   */
  abstract public function getLocaleName();


  /**
   * Set a fallback locale which can be used as a default if this locale is
   * missing translations.
   *
   * For locales like "English (Great Britain)", missing translations can be
   * sourced from "English (US)".
   *
   * @return string|null Locale code of fallback locale, or null if there is
   *                     no fallback locale.
   */
  public function getFallbackLocaleCode() {
    return null;
  }


  /**
   * Select a gender variant for this locale. By default, locales use a simple
   * rule with two gender variants, listed in "<male, female>" order.
   *
   * @param const `PhutilPerson` gender constant.
   * @param list<wild> List of variants.
   * @return string Variant for use.
   */
  public function selectGenderVariant($variant, array $translations) {
    if ($variant == PhutilPerson::GENDER_FEMININE) {
      return end($translations);
    } else {
      return reset($translations);
    }
  }


  /**
   * Select a plural variant for this locale. By default, locales use a simple
   * rule with two plural variants, listed in "<singular, plural>" order.
   *
   * @param int Plurality of the value.
   * @param list<wild> List of variants.
   * @return string Variant for use.
   */
  public function selectPluralVariant($variant, array $translations) {
    if ($variant == 1) {
      return reset($translations);
    } else {
      return end($translations);
    }
  }


  /**
   * Flags a locale as silly, like "English (Pirate)".
   *
   * These locales are fun but disastrously inappropriate for serious
   * businesses.
   *
   * @return bool True if this locale is silly.
   */
  public function isSillyLocale() {
    return false;
  }


  /**
   * Flags a locale as a testing locale, like "English (US, ALL CAPS)". These
   * locales are useful for translation development, but not for normal users.
   *
   * @return bool True if this is a locale for testing or development.
   */
  public function isTestLocale() {
    return false;
  }


  /**
   * Indicates that the translator should post-process translations in this
   * locale by calling @{method:didTranslateString}.
   *
   * Doing this incurs a performance penalty, and is not useful for most
   * languages. However, it can be used to implement test translations like
   * "English (US, ALL CAPS)".
   *
   * @return bool True to postprocess strings.
   */
  public function shouldPostProcessTranslations() {
    return false;
  }


  /**
   * Callback for post-processing translations.
   *
   * By default, this callback is not invoked. To activate it, return `true`
   * from @{method:shouldPostProcessTranslations}. Activating this callback
   * incurs a performance penalty.
   *
   * @param string The raw input pattern.
   * @param string The selected translation pattern.
   * @param list<wild> The raw input arguments.
   * @param string The translated string.
   * @return string Post-processed translation string.
   */
  public function didTranslateString(
    $raw_pattern,
    $translated_pattern,
    array $args,
    $result_text) {
    return $result_text;
  }


  /**
   * Load all available locales.
   *
   * @return map<string, PhutilLocale> Map from codes to locale objects.
   */
  public static function loadAllLocales() {
    static $locales;

    if ($locales === null) {
      $objects = id(new PhutilClassMapQuery())
        ->setAncestorClass(__CLASS__)
        ->execute();

      $locale_map = array();
      foreach ($objects as $object) {
        $locale_code = $object->getLocaleCode();
        if (empty($locale_map[$locale_code])) {
          $locale_map[$locale_code] = $object;
        } else {
          throw new Exception(
            pht(
              'Two subclasses of "%s" ("%s" and "%s") define '.
              'locales with the same locale code ("%s"). Each locale must '.
              'have a unique locale code.',
              __CLASS__,
              get_class($object),
              get_class($locale_map[$locale_code]),
              $locale_code));
        }
      }

      foreach ($locale_map as $locale_code => $locale) {
        $fallback_code = $locale->getFallbackLocaleCode();
        if ($fallback_code !== null) {
          if (empty($locale_map[$fallback_code])) {
            throw new Exception(
              pht(
                'The locale "%s" has an invalid fallback locale code ("%s"). '.
                'No locale class exists which defines this locale.',
                get_class($locale),
                $fallback_code));
          }
        }
      }

      foreach ($locale_map as $locale_code => $locale) {
        $seen = array($locale_code => get_class($locale));
        self::checkLocaleFallback($locale_map, $locale, $seen);
      }

      $locales = $locale_map;
    }
    return $locales;
  }


  /**
   * Load a specific locale using a locale code.
   *
   * @param string Locale code.
   * @return PhutilLocale Locale object.
   */
  public static function loadLocale($locale_code) {
    $all_locales = self::loadAllLocales();
    $locale = idx($all_locales, $locale_code);

    if (!$locale) {
      throw new Exception(
        pht(
          'There is no locale with the locale code "%s".',
          $locale_code));
    }

    return $locale;
  }


  /**
   * Recursively check locale fallbacks for cycles.
   *
   * @param map<string, PhutilLocale> Map of locales.
   * @param PhutilLocale Current locale.
   * @param map<string, string> Map of visited locales.
   * @return void
   */
  private static function checkLocaleFallback(
    array $map,
    PhutilLocale $locale,
    array $seen) {

    $fallback_code = $locale->getFallbackLocaleCode();
    if ($fallback_code === null) {
      return;
    }

    if (isset($seen[$fallback_code])) {
      $seen[] = get_class($locale);
      $seen[] = pht('...');
      throw new Exception(
        pht(
          'Locale "%s" is part of a cycle of locales which fall back on '.
          'one another in a loop (%s). Locales which fall back on other '.
          'locales must not loop.',
          get_class($locale),
          implode(' -> ', $seen)));
    }

    $seen[$fallback_code] = get_class($locale);
    self::checkLocaleFallback($map, $map[$fallback_code], $seen);
  }

}
