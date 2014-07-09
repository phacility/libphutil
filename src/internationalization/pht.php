<?php

/**
 * Translate a string. It uses a translator set by
 * `PhutilTranslator::setInstance()` or translations specified by
 * `PhutilTranslator::getInstance()->addTranslations()` and language rules set
 * by `PhutilTranslator::getInstance()->setLanguage()`.
 *
 * @param string Translation identifier with `sprintf()` placeholders.
 * @param mixed Value to select the variant from (e.g. singular or plural).
 * @param ... Next values referenced from $text.
 * @return string Translated string with substituted values.
 */
function pht($text, $variant = null /* , ... */) {
  $args = func_get_args();
  $translator = PhutilTranslator::getInstance();
  return call_user_func_array(array($translator, 'translate'), $args);
}
