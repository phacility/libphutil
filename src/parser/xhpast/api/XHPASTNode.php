<?php

final class XHPASTNode extends AASTNode {

  public function isStaticScalar() {
    return ($this->getTypeName() == 'n_STRING_SCALAR' ||
            $this->getTypeName() == 'n_NUMERIC_SCALAR');
  }

  public function getDocblockToken() {
    if ($this->l == -1) {
      return null;
    }
    $tokens = $this->tree->getRawTokenStream();

    for ($ii = $this->l - 1; $ii >= 0; $ii--) {
      if ($tokens[$ii]->getTypeName() == 'T_DOC_COMMENT') {
        return $tokens[$ii];
      }
      if (!$tokens[$ii]->isAnyWhitespace()) {
        return null;
      }
    }

    return null;
  }

  public function evalStatic() {
    switch ($this->getTypeName()) {
      case 'n_STATEMENT':
        return $this->getChildByIndex(0)->evalStatic();
        break;
      case 'n_STRING_SCALAR':
        return (string)$this->getStringLiteralValue();
      case 'n_NUMERIC_SCALAR':
        $value = $this->getSemanticString();
        if (preg_match('/^0x/i', $value)) {
          // Hex
          $value = base_convert(substr($value, 2), 16, 10);
        } else if (preg_match('/^0\d+$/i', $value)) {
          // Octal
          $value = base_convert(substr($value, 1),  8, 10);
        }
        return +$value;
      case 'n_SYMBOL_NAME':
        $value = $this->getSemanticString();
        if ($value == 'INF') {
          return INF;
        }
        switch (strtolower($value)) {
          case 'true':
            return true;
          case 'false':
            return false;
          case 'null':
            return null;
          default:
            throw new Exception('Unrecognized symbol name.');
        }
        break;
      case 'n_UNARY_PREFIX_EXPRESSION':
        $operator = $this->getChildOfType(0, 'n_OPERATOR');
        $operand = $this->getChildByIndex(1);
        switch ($operator->getSemanticString()) {
          case '-':
            return -$operand->evalStatic();
            break;
          case '+':
            return $operand->evalStatic();
            break;
          default:
            throw new Exception('Unexpected operator in static expression.');
        }
        break;
      case 'n_ARRAY_LITERAL':
        $result = array();
        $values = $this->getChildOfType(0, 'n_ARRAY_VALUE_LIST');
        foreach ($values->getChildren() as $child) {
          $key = $child->getChildByIndex(0);
          $val = $child->getChildByIndex(1);
          if ($key->getTypeName() == 'n_EMPTY') {
            $result[] = $val->evalStatic();
          } else {
            $result[$key->evalStatic()] = $val->evalStatic();
          }
        }
        return $result;
      case 'n_CONCATENATION_LIST':
        $result = '';
        foreach ($this->getChildren() as $child) {
          if ($child->getTypeName() == 'n_OPERATOR') {
            continue;
          }
          $result .= $child->evalStatic();
        }
        return $result;
      default:
        throw new Exception(
          pht(
            'Unexpected node during static evaluation, of type: %s',
            $this->getTypeName()));
    }
  }

  public function isConstantString() {
    switch ($this->getTypeName()) {
      case 'n_HEREDOC':
      case 'n_STRING_SCALAR':
        return !$this->getStringVariables();

      case 'n_CONCATENATION_LIST':
        foreach ($this->getChildren() as $child) {
          if ($child->getTypeName() == 'n_OPERATOR') {
            continue;
          }
          if (!$child->isConstantString()) {
            return false;
          }
        }
        return true;

      default:
        return false;
    }
  }

  public function getStringVariables() {
    $value = $this->getConcreteString();

    switch ($this->getTypeName()) {
      case 'n_HEREDOC':
        if (preg_match("/^<<<\s*'/", $value)) { // Nowdoc: <<<'EOT'
          return array();
        }
        break;

      case 'n_STRING_SCALAR':
        if ($value[0] == "'") {
          return array();
        }
        break;

      default:
        throw new Exception('Unexpected type '.$this->getTypeName().'.');
    }

    // We extract just the variable names and ignore properties and array keys.
    $re = '/\\\\.|(\$|\{\$|\${)([a-z_\x7F-\xFF][a-z0-9_\x7F-\xFF]*)/i';
    $matches = null;
    preg_match_all($re, $value, $matches, PREG_OFFSET_CAPTURE);
    return ipull(array_filter($matches[2]), 0, 1);
  }

  public function getStringLiteralValue() {
    if ($this->getTypeName() != 'n_STRING_SCALAR') {
      return null;
    }

    $value = $this->getSemanticString();
    $type  = $value[0];
    $value = preg_replace('/^b?[\'"]|[\'"]$/i', '', $value);
    $esc   = false;
    $len   = strlen($value);
    $out   = '';

    if ($type == "'") {
      // Single quoted strings treat everything as a literal except "\\" and
      // "\'".
      return str_replace(
        array('\\\\', '\\\''),
        array('\\',   "'"),
        $value);
    }

    // Double quoted strings treat "\X" as a literal if X isn't specifically
    // a character which needs to be escaped -- e.g., "\q" and "\'" are
    // literally "\q" and "\'". stripcslashes() is too aggressive, so find
    // all these under-escaped backslashes and escape them.

    for ($ii = 0; $ii < $len; $ii++) {
      $c = $value[$ii];
      if ($esc) {
        $esc = false;
        switch ($c) {
          case 'x':
            $u = isset($value[$ii + 1]) ? $value[$ii + 1] : null;
            if (!preg_match('/^[a-f0-9]/i', $u)) {
              // PHP treats \x followed by anything which is not a hex digit
              // as a literal \x.
              $out .= '\\\\'.$c;
              break;
            }
            /* fallthrough */
          case 'n':
          case 'r':
          case 'f':
          case 'v':
          case '"':
          case '$':
          case 't':
          case '0':
          case '1':
          case '2':
          case '3':
          case '4':
          case '5':
          case '6':
          case '7':
            $out .= '\\'.$c;
            break;
          case 'e':
            // Since PHP 5.4.0, this means "esc". However, stripcslashes() does
            // not perform this conversion.
            $out .= chr(27);
            break;
          default:
            $out .= '\\\\'.$c;
            break;
        }
      } else if ($c == '\\') {
        $esc = true;
      } else {
        $out .= $c;
      }
    }

    return stripcslashes($out);
  }

  public function getLineNumber() {
    return idx($this->tree->getOffsetToLineNumberMap(), $this->getOffset());
  }

}
