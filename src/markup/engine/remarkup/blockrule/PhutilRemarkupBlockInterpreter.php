<?php

/**
 * @group markup
 * @stable
 */
abstract class PhutilRemarkupBlockInterpreter {

  /**
   * @return string
   */
  abstract public function getInterpreterName();

  abstract public function markupContent($content, array $argv);

}
