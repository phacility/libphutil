<?php

final class PhutilSearchQueryCompiler
  extends Phobject {

  private $operators = '+ -><()~*:""&|';
  private $query;
  private $stemmer;

  const OPERATOR_NOT = 'not';
  const OPERATOR_AND = 'and';

  public function setOperators($operators) {
    $this->operators = $operators;
    return $this;
  }

  public function getOperators() {
    return $this->operators;
  }

  public function setQuery($query) {
    $this->query = $query;
    return $this;
  }

  public function getQuery() {
    return $this->query;
  }

  public function setStemmer(PhutilSearchStemmer $stemmer) {
    $this->stemmer = $stemmer;
    return $this;
  }

  public function getStemmer() {
    return $this->stemmer;
  }

  public function compileQuery() {
    $query = $this->getQuery();
    $tokens = $this->tokenizeQuery($query);

    $result = array();
    foreach ($tokens as $token) {
      $result[] = $this->renderToken($token);
    }

    return $this->compileRenderedTokens($result);
  }

  public function compileLiteralQuery() {
    $query = $this->getQuery();
    $tokens = $this->tokenizeQuery($query);

    $result = array();
    foreach ($tokens as $token) {
      if (!$token['quoted']) {
        continue;
      }
      $result[] = $this->renderToken($token);
    }

    return $this->compileRenderedTokens($result);
  }

  public function compileStemmedQuery() {
    $query = $this->getQuery();
    $tokens = $this->tokenizeQuery($query);

    $result = array();
    foreach ($tokens as $token) {
      if ($token['quoted']) {
        continue;
      }
      $result[] = $this->renderToken($token, $this->getStemmer());
    }

    return $this->compileRenderedTokens($result);
  }

  private function compileRenderedTokens(array $list) {
    if (!$list) {
      return null;
    }

    $list = array_unique($list);
    return implode(' ', $list);
  }

  private function tokenizeQuery($query) {
    $maximum_bytes = 1024;

    $query_bytes = strlen($query);
    if ($query_bytes > $maximum_bytes) {
      throw new PhutilSearchQueryCompilerSyntaxException(
        pht(
          'Query is too long (%s bytes, maximum is %s bytes).',
          new PhutilNumber($query_bytes),
          new PhutilNumber($maximum_bytes)));
    }

    $query = phutil_utf8v($query);
    $length = count($query);

    $mode = 'scan';
    $current_operator = array();
    $current_token = array();
    $is_quoted = false;
    $tokens = array();
    for ($ii = 0; $ii < $length; $ii++) {
      $character = $query[$ii];

      if ($mode == 'scan') {
        if (preg_match('/^\s\z/u', $character)) {
          continue;
        }

        $mode = 'operator';
      }

      if ($mode == 'operator') {
        if (preg_match('/^\s\z/u', $character)) {
          continue;
        }

        if (preg_match('/^[+-]\z/', $character)) {
          $current_operator[] = $character;
          continue;
        }

        $mode = 'quote';
      }

      if ($mode == 'quote') {
        if (preg_match('/^"\z/', $character)) {
          $is_quoted = true;
          $mode = 'token';
          continue;
        }

        $mode = 'token';
      }

      if ($mode == 'token') {
        $capture = false;
        $was_quoted = $is_quoted;
        if ($is_quoted) {
          if (preg_match('/^"\z/', $character)) {
            $capture = true;
            $mode = 'scan';
            $is_quoted = false;
          }
        } else {
          if (preg_match('/^\s\z/u', $character)) {
            $capture = true;
            $mode = 'scan';
          }

          if (preg_match('/^"\z/', $character)) {
            $capture = true;
            $mode = 'token';
            $is_quoted = true;
          }
        }

        if ($capture) {
          $tokens[] = array(
            'operator' => $current_operator,
            'quoted' => $was_quoted,
            'value' => $current_token,
          );
          $current_operator = array();
          $current_token = array();
          continue;
        } else {
          $current_token[] = $character;
        }
      }
    }

    if ($is_quoted) {
      throw new PhutilSearchQueryCompilerSyntaxException(
        pht(
          'Query contains unmatched double quotes.'));
    }

    if ($mode == 'operator') {
      throw new PhutilSearchQueryCompilerSyntaxException(
        pht(
          'Query contains operator ("%s") with no search term.',
          implode('', $current_operator)));
    }

    $tokens[] = array(
      'operator' => $current_operator,
      'quoted' => false,
      'value' => $current_token,
    );

    $results = array();
    foreach ($tokens as $token) {
      $value = implode('', $token['value']);
      $operator_string = implode('', $token['operator']);

      if (!strlen($value)) {
        continue;
      }

      switch ($operator_string) {
        case '-':
          $operator = self::OPERATOR_NOT;
          break;
        case '':
        case '+':
          $operator = self::OPERATOR_AND;
          break;
        default:
          throw new PhutilSearchQueryCompilerSyntaxException(
            pht(
              'Query has an invalid sequence of operators ("%s").',
              $operator_string));
      }

      $results[] = array(
        'operator' => $operator,
        'quoted' => $token['quoted'],
        'value' => $value,
      );
    }

    return $results;
  }

  private function renderToken(
    array $token,
    PhutilSearchStemmer $stemmer = null) {
    $value = $token['value'];

    if ($stemmer) {
      $value = $stemmer->stemToken($value);
    }

    $value = $this->quoteToken($value);
    $operator = $token['operator'];
    $prefix = $this->getOperatorPrefix($operator);

    $value = $prefix.$value;

    return $value;
  }

  private function getOperatorPrefix($operator) {
    $operators = $this->operators;

    switch ($operator) {
      case self::OPERATOR_AND:
        $prefix = $operators[0];
        break;
      case self::OPERATOR_NOT:
        $prefix = $operators[2];
        break;
      default:
        throw new PhutilSearchQueryCompilerSyntaxException(
          pht(
            'Unsupported operator prefix "%s".',
            $operator));
    }

    if ($prefix == ' ') {
      $prefix = null;
    }

    return $prefix;
  }

  private function quoteToken($value) {
    $operators = $this->operators;

    $open_quote = $this->operators[10];
    $close_quote = $this->operators[11];

    return $open_quote.$value.$close_quote;
  }


}
