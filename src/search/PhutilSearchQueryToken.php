<?php

final class PhutilSearchQueryToken extends Phobject {

  private $isQuoted;
  private $value;
  private $operator;

  public static function newFromDictionary(array $dictionary) {
    $token = new self();

    $token->isQuoted = $dictionary['quoted'];
    $token->operator = $dictionary['operator'];
    $token->value = $dictionary['value'];

    return $token;
  }

  public function isQuoted() {
    return $this->isQuoted;
  }

  public function getValue() {
    return $this->value;
  }

  public function getOperator() {
    return $this->operator;
  }

}
