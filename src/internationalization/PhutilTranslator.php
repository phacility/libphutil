<?php

/*
 * Copyright 2012 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @group internationalization
 */
final class PhutilTranslator {
  static private $instance;

  private $language = 'en';
  private $translations = array();

  public static function getInstance() {
    if (self::$instance === null) {
      self::$instance = new PhutilTranslator();
    }
    return self::$instance;
  }

  public static function setInstance(PhutilTranslator $instance) {
    self::$instance = $instance;
  }

  public function setLanguage($language) {
    $this->language = $language;
    return $this;
  }

  /**
   * Add translations which will be later used by @{method:translate}.
   * The parameter is an array of strings (for simple translations) or arrays
   * (for translastions with variants). The number of items in the array is
   * language specific. It is `array($singular, $plural)` for English.
   *
   *   array(
   *     'color' => 'colour',
   *     '%d beer(s)' => array('%d beer', '%d beers'),
   *   );
   *
   * The arrays can be nested for strings with more variant parts:
   *
   *   array(
   *     '%d char(s) on %d row(s)' => array(
   *       array('%d char on %d row', '%d char on %d rows'),
   *       array('%d chars on %d row', '%d chars on %d rows'),
   *     ),
   *   );
   *
   * The translation should have the same placeholders as originals. Swapping
   * parameter order is possible:
   *
   *   array(
   *     '%s owns %s.' => '%2$s is owned by %1$s.',
   *   );
   *
   * @param array Identifier in key, translation in value.
   * @return PhutilTranslator Provides fluent interface.
   */
  public function addTranslations(array $translations) {
    $this->translations = array_merge($this->translations, $translations);
    return $this;
  }

  public function translate($text /*, ... */) {
    $translation = idx($this->translations, $text, $text);
    $args = func_get_args();
    while (is_array($translation)) {
      $translation = $this->chooseVariant($translation, next($args));
    }
    array_shift($args);
    return vsprintf($translation, $args);
  }

  private function chooseVariant(array $translations, $variant) {
    switch ($this->language) {

      case 'en':
        list($singular, $plural) = $translations;
        if ($variant == 1) {
          return $singular;
        }
        return $plural;

      case 'cs':
        if ($variant instanceof PhutilPerson) {
          list($male, $female) = $translations;
          if ($variant->getSex() == PhutilPerson::SEX_FEMALE) {
            return $female;
          }
          return $male;
        }

        list($singular, $paucal, $plural) = $translations;
        if ($variant == 1) {
          return $singular;
        }
        if ($variant >= 2 && $variant <= 4) {
          return $paucal;
        }
        return $plural;

      default:
        throw new Exception("Unknown language '{$this->language}'.");
    }
  }

}
