<?php

/**
 * Generate nonsense test data according to a context-free grammar definition.
 */
abstract class PhutilContextFreeGrammar {

  private $limit = 65535;

  abstract protected function getRules();

  public function generate() {
    $count = 0;
    return $this->applyRules('[start]', $count);
  }

  public function applyRules($input, &$count) {
    $rules = $this->getRules();

    if (++$count > $this->limit) {
      throw new Exception("Token replacement count exceeded limit!");
    }

    $matches = null;
    preg_match_all('/(\\[[^\\]]+\\])/', $input, $matches, PREG_OFFSET_CAPTURE);

    foreach (array_reverse($matches[1]) as $token_spec) {
      list($token, $offset) = $token_spec;
      $token_name = substr($token, 1, -1);

      if (empty($rules[$token_name])) {
        throw new Exception("Invalid token '{$token_name}' in grammar.");
      }

      $key = array_rand($rules[$token_name]);
      $replacement = $this->applyRules($rules[$token_name][$key], $count);

      $input = substr_replace($input, $replacement, $offset, strlen($token));
    }

    return $input;
  }

}
