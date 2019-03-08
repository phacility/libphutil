<?php

/**
 * Perform type checks using a simple type grammar. The grammar supports the
 * following basic types:
 *
 *    int
 *    float
 *    bool
 *    string
 *    null
 *    callable
 *    regex
 *    wild
 *    AnyClassOrInterfaceName
 *
 * It supports the following complex types:
 *
 *    list<type>
 *    map<type, type>
 *    type|type
 *
 * A type may be marked as optional by suffixing it with "?" or prefixing it
 * with the word "optional":
 *
 *    int?
 *    optional int
 *
 * A type may have a human-readable comment in parentheses, at the end:
 *
 *    int (must be even)
 *
 * For example, these are valid type specifications:
 *
 *    int|string
 *    map<int, bool>
 *    list<list<wild>>
 *    optional int
 *    string (uppercase)
 *
 */
final class PhutilTypeSpec extends Phobject {

  private $type;
  private $subtypes = array();
  private $optional;
  private $comment;

  private function __construct() {}

  public function getType() {
    return $this->type;
  }

  public function check($value, $name = null) {
    switch ($this->type) {
      case 'int':
        if (!is_int($value)) {
          throw new PhutilTypeCheckException($this, $value, $name);
        }
        break;
      case 'float':
        if (!is_float($value)) {
          throw new PhutilTypeCheckException($this, $value, $name);
        }
        break;
      case 'bool':
        if (!is_bool($value)) {
          throw new PhutilTypeCheckException($this, $value, $name);
        }
        break;
      case 'string':
        if (!is_string($value)) {
          throw new PhutilTypeCheckException($this, $value, $name);
        }
        break;
      case 'regex':
        $trap = new PhutilErrorTrap();
          $ok = @preg_match($value, '');
          $err = $trap->getErrorsAsString();
        $trap->destroy();

        if ($ok === false) {
          throw new PhutilTypeCheckException($this, $value, $name, $err);
        }
        break;
      case 'null':
        if (!is_null($value)) {
          throw new PhutilTypeCheckException($this, $value, $name);
        }
        break;
      case 'list':
        if (!is_array($value)) {
          throw new PhutilTypeCheckException($this, $value, $name);
        }
        if ($value && !phutil_is_natural_list($value)) {
          throw new PhutilTypeCheckException($this, $value, $name);
        }
        try {
          foreach ($value as $v) {
            $this->subtypes[0]->check($v);
          }
        } catch (PhutilTypeCheckException $ex) {
          throw new PhutilTypeCheckException($this, $value, $name);
        }
        break;
      case 'map':
        if (!is_array($value)) {
          throw new PhutilTypeCheckException($this, $value, $name);
        }
        try {
          foreach ($value as $k => $v) {
            $this->subtypes[0]->check($k);
            $this->subtypes[1]->check($v);
          }
        } catch (PhutilTypeCheckException $ex) {
          throw new PhutilTypeCheckException($this, $value, $name);
        }
        break;
      case 'or':
        foreach ($this->subtypes as $subtype) {
          try {
            $subtype->check($value);
            return;
          } catch (PhutilTypeCheckException $ex) {
            // Ignore.
          }
        }
        throw new PhutilTypeCheckException($this, $value, $name);
      case 'wild':
        return;
      default:
        if (class_exists($this->type, false)) {
          if ($value instanceof $this->type) {
            return;
          }
        } else if (interface_exists($this->type, false)) {
          if ($value instanceof $this->type) {
            return;
          }
        }

        throw new PhutilTypeCheckException($this, $value, $name);
    }
  }

  public static function checkMap(array $values, array $types) {
    $extra = array_diff_key($values, $types);
    if ($extra) {
      throw new PhutilTypeExtraParametersException($extra);
    }

    $missing = array();
    foreach ($types as $key => $type) {
      $types[$key] = self::newFromString($type);
      if (!array_key_exists($key, $values)) {
        if (!$types[$key]->optional) {
          $missing[] = $key;
        }
      }
    }

    if ($missing) {
      throw new PhutilTypeMissingParametersException($missing);
    }

    foreach ($types as $key => $type) {
      if (array_key_exists($key, $values)) {
        $type->check($values[$key], $key);
      }
    }
  }

  public static function getCommonParentClass($class_a, $class_b) {
    // Make sure both classes are really classes.
    try {
      if (!class_exists($class_a) || !class_exists($class_b)) {
        return null;
      }
    } catch (PhutilMissingSymbolException $ex) {
      return null;
    }

    $ancestors_a = array();
    do {
      $ancestors_a[] = $class_a;
    } while ($class_a = get_parent_class($class_a));

    $ancestors_b = array();
    do {
      $ancestors_b[] = $class_b;
    } while ($class_b = get_parent_class($class_b));

    return head(array_intersect($ancestors_a, $ancestors_b));
  }

  public static function getTypeOf($value) {
    if (is_int($value)) {
      return 'int';
    } else if (is_float($value)) {
      return 'float';
    } else if (is_bool($value)) {
      return 'bool';
    } else if (is_string($value)) {
      return 'string';
    } else if (is_null($value)) {
      return 'null';
    } else if (is_object($value)) {
      return get_class($value);
    } else if (is_array($value)) {
      $vtype = self::getTypeOfVector($value);
      if ($value && phutil_is_natural_list($value)) {
        return 'list<'.$vtype.'>';
      } else {
        $ktype = self::getTypeOfVector(array_keys($value));
        return "map<{$ktype}, {$vtype}>";
      }
    } else {
      return 'wild';
    }
  }

  private static function getTypeOfVector(array $vector) {
    if (!$vector) {
      return 'wild';
    }

    $type = null;
    foreach ($vector as $value) {
      $vtype = self::getTypeOf($value);
      if ($type === null) {
        $type = $vtype;
      } else if ($type === $vtype) {
        continue;
      } else {
        $parent = self::getCommonParentClass($type, $vtype);
        if ($parent) {
          $type = $parent;
        } else {
          return 'wild';
        }
      }
    }

    return $type;
  }

  public function toString() {
    $sub = array();
    foreach ($this->subtypes as $subtype) {
      $sub[] = $subtype->toString();
    }

    switch ($this->type) {
      case 'map':
        $string = 'map<'.$sub[0].', '.$sub[1].'>';
        break;
      case 'list':
        $string = 'list<'.$sub[0].'>';
        break;
      case 'or':
        $string = implode('|', $sub);
        break;
      default:
        $string = $this->type;
        break;
    }

    if ($this->optional) {
      $string = 'optional '.$string;
    }

    if ($this->comment) {
      $string .= ' ('.$this->comment.')';
    }

    return $string;
  }

  public static function newFromString($string) {
    $lexer = self::getLexer();
    $tokens = $lexer->getTokens($string);

    // Strip whitespace tokens.
    foreach ($tokens as $key => $token) {
      $type = $token[0];
      if ($type == ' ') {
        unset($tokens[$key]);
      }
    }

    $tokens = array_values($tokens);
    $callback = array(__CLASS__, 'didReduceTokens');
    return self::parseTokens($tokens, $callback);
  }

  public static function didReduceTokens($rule, $production, array $tokens) {
    switch ($rule) {
      case 'start':
      case 'some_type':
      case 'not_or_type':
        return $tokens[0];
      case 'type':
        if ($production == 'yes') {
          $tokens[0]->optional = true;
        }
        return $tokens[0];
      case 'basic_type':
        $obj = new PhutilTypeSpec();
        $obj->type = $tokens[0][1];
        return $obj;
      case 'or_type':
        $l = $tokens[0];
        $r = $tokens[2];

        if ($l->type == 'or') {
          if ($r->type == 'or') {
            foreach ($r->subtypes as $subtype) {
              $l->subtypes[] = $subtype;
            }
          } else {
            $l->subtypes[] = $r;
          }
          return $l;
        } else if ($r->type == 'or') {
          $r->subtypes[] = $l;
          return $r;
        } else {
          $obj = new PhutilTypeSpec();
          $obj->type = 'or';
          $obj->subtypes[] = $l;
          $obj->subtypes[] = $r;
          return $obj;
        }
        break;
      case 'map_type':
        $obj = new PhutilTypeSpec();
        $obj->type = 'map';
        $obj->subtypes[] = $tokens[2];
        $obj->subtypes[] = $tokens[4];
        return $obj;
      case 'list_type':
        $obj = new PhutilTypeSpec();
        $obj->type = 'list';
        $obj->subtypes[] = $tokens[2];
        return $obj;
      case 'maybe_optional':
        if ($production == 'yes') {
          $tokens[1]->optional = true;
          return $tokens[1];
        } else {
          return $tokens[0];
        }
        break;
      case 'maybe_comment':
        if ($production == 'yes') {
          $tokens[0]->comment = $tokens[1];
        }
        return $tokens[0];
      case 'comment':
        return $tokens[1];
      case 'comment_text':
        $result = '';
        foreach ($tokens as $token) {
          if (is_array($token)) {
            $result .= $token[1];
          } else {
            $result .= $token;
          }
        }
        return $result;
      default:
        throw new Exception(pht("Unhandled parser rule '%s'!", $rule));
    }
  }

  private static function getLexer() {
    static $lexer;
    if (!$lexer) {
      $lexer = new PhutilTypeLexer();
    }
    return $lexer;
  }

  private static function parseTokens(array $tokens, $callback) {
    // NOTE: This is automatically generated by the script
    // `support/parser/generate-type-parser.php`.

    return PhutilParserGenerator::parseTokensWithTables(
      array(
        0 => array(
          'opt' => array(
            0 => 'S',
            1 => 3,
          ),
          'k' => array(
            0 => 'S',
            1 => 20,
          ),
          'map' => array(
            0 => 'S',
            1 => 21,
          ),
          'list' => array(
            0 => 'S',
            1 => 71,
          ),
        ),
        1 => array(
          '(end-of-file)' => array(
            0 => 'A',
          ),
        ),
        2 => array(
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'start',
              1 => 0,
              2 => 1,
            ),
          ),
        ),
        3 => array(
          'k' => array(
            0 => 'S',
            1 => 20,
          ),
          'map' => array(
            0 => 'S',
            1 => 21,
          ),
          'list' => array(
            0 => 'S',
            1 => 71,
          ),
        ),
        4 => array(
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'maybe_optional',
              1 => 'yes',
              2 => 2,
            ),
          ),
        ),
        5 => array(
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'maybe_comment',
              1 => 'no',
              2 => 1,
            ),
          ),
          '(' => array(
            0 => 'S',
            1 => 7,
          ),
        ),
        6 => array(
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'maybe_comment',
              1 => 'yes',
              2 => 2,
            ),
          ),
        ),
        7 => array(
          'cm' => array(
            0 => 'S',
            1 => 11,
          ),
        ),
        8 => array(
          ')' => array(
            0 => 'S',
            1 => 9,
          ),
          'cm' => array(
            0 => 'S',
            1 => 10,
          ),
        ),
        9 => array(
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'comment',
              1 => 0,
              2 => 3,
            ),
          ),
        ),
        10 => array(
          ')' => array(
            0 => 'R',
            1 => array(
              0 => 'comment_text',
              1 => 0,
              2 => 2,
            ),
          ),
          'cm' => array(
            0 => 'R',
            1 => array(
              0 => 'comment_text',
              1 => 0,
              2 => 2,
            ),
          ),
        ),
        11 => array(
          ')' => array(
            0 => 'R',
            1 => array(
              0 => 'comment_text',
              1 => 1,
              2 => 1,
            ),
          ),
          'cm' => array(
            0 => 'R',
            1 => array(
              0 => 'comment_text',
              1 => 1,
              2 => 1,
            ),
          ),
        ),
        12 => array(
          '(' => array(
            0 => 'R',
            1 => array(
              0 => 'type',
              1 => 'no',
              2 => 1,
            ),
          ),
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'type',
              1 => 'no',
              2 => 1,
            ),
          ),
          '?' => array(
            0 => 'S',
            1 => 13,
          ),
        ),
        13 => array(
          '(' => array(
            0 => 'R',
            1 => array(
              0 => 'type',
              1 => 'yes',
              2 => 2,
            ),
          ),
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'type',
              1 => 'yes',
              2 => 2,
            ),
          ),
        ),
        14 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'some_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '(' => array(
            0 => 'R',
            1 => array(
              0 => 'some_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'some_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'S',
            1 => 15,
          ),
        ),
        15 => array(
          'k' => array(
            0 => 'S',
            1 => 20,
          ),
          'map' => array(
            0 => 'S',
            1 => 21,
          ),
          'list' => array(
            0 => 'S',
            1 => 71,
          ),
        ),
        16 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 0,
              2 => 3,
            ),
          ),
          '(' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 0,
              2 => 3,
            ),
          ),
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 0,
              2 => 3,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 0,
              2 => 3,
            ),
          ),
        ),
        17 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '(' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 0,
              2 => 1,
            ),
          ),
        ),
        18 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 1,
              2 => 1,
            ),
          ),
          '(' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 1,
              2 => 1,
            ),
          ),
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 1,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 1,
              2 => 1,
            ),
          ),
        ),
        19 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 2,
              2 => 1,
            ),
          ),
          '(' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 2,
              2 => 1,
            ),
          ),
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 2,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 2,
              2 => 1,
            ),
          ),
        ),
        20 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'basic_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '(' => array(
            0 => 'R',
            1 => array(
              0 => 'basic_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'basic_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'basic_type',
              1 => 0,
              2 => 1,
            ),
          ),
        ),
        21 => array(
          '<' => array(
            0 => 'S',
            1 => 22,
          ),
        ),
        22 => array(
          'k' => array(
            0 => 'S',
            1 => 57,
          ),
          'map' => array(
            0 => 'S',
            1 => 58,
          ),
          'list' => array(
            0 => 'S',
            1 => 67,
          ),
        ),
        23 => array(
          ',' => array(
            0 => 'S',
            1 => 24,
          ),
        ),
        24 => array(
          'k' => array(
            0 => 'S',
            1 => 35,
          ),
          'map' => array(
            0 => 'S',
            1 => 36,
          ),
          'list' => array(
            0 => 'S',
            1 => 45,
          ),
        ),
        25 => array(
          '>' => array(
            0 => 'S',
            1 => 26,
          ),
        ),
        26 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'map_type',
              1 => 0,
              2 => 6,
            ),
          ),
          '(' => array(
            0 => 'R',
            1 => array(
              0 => 'map_type',
              1 => 0,
              2 => 6,
            ),
          ),
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'map_type',
              1 => 0,
              2 => 6,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'map_type',
              1 => 0,
              2 => 6,
            ),
          ),
        ),
        27 => array(
          '>' => array(
            0 => 'R',
            1 => array(
              0 => 'type',
              1 => 'no',
              2 => 1,
            ),
          ),
          '?' => array(
            0 => 'S',
            1 => 28,
          ),
        ),
        28 => array(
          '>' => array(
            0 => 'R',
            1 => array(
              0 => 'type',
              1 => 'yes',
              2 => 2,
            ),
          ),
        ),
        29 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'some_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '>' => array(
            0 => 'R',
            1 => array(
              0 => 'some_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'S',
            1 => 30,
          ),
        ),
        30 => array(
          'k' => array(
            0 => 'S',
            1 => 35,
          ),
          'map' => array(
            0 => 'S',
            1 => 36,
          ),
          'list' => array(
            0 => 'S',
            1 => 45,
          ),
        ),
        31 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 0,
              2 => 3,
            ),
          ),
          '>' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 0,
              2 => 3,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 0,
              2 => 3,
            ),
          ),
        ),
        32 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '>' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 0,
              2 => 1,
            ),
          ),
        ),
        33 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 1,
              2 => 1,
            ),
          ),
          '>' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 1,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 1,
              2 => 1,
            ),
          ),
        ),
        34 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 2,
              2 => 1,
            ),
          ),
          '>' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 2,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 2,
              2 => 1,
            ),
          ),
        ),
        35 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'basic_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '>' => array(
            0 => 'R',
            1 => array(
              0 => 'basic_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'basic_type',
              1 => 0,
              2 => 1,
            ),
          ),
        ),
        36 => array(
          '<' => array(
            0 => 'S',
            1 => 37,
          ),
        ),
        37 => array(
          'k' => array(
            0 => 'S',
            1 => 57,
          ),
          'map' => array(
            0 => 'S',
            1 => 58,
          ),
          'list' => array(
            0 => 'S',
            1 => 67,
          ),
        ),
        38 => array(
          ',' => array(
            0 => 'S',
            1 => 39,
          ),
        ),
        39 => array(
          'k' => array(
            0 => 'S',
            1 => 35,
          ),
          'map' => array(
            0 => 'S',
            1 => 36,
          ),
          'list' => array(
            0 => 'S',
            1 => 45,
          ),
        ),
        40 => array(
          '>' => array(
            0 => 'S',
            1 => 41,
          ),
        ),
        41 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'map_type',
              1 => 0,
              2 => 6,
            ),
          ),
          '>' => array(
            0 => 'R',
            1 => array(
              0 => 'map_type',
              1 => 0,
              2 => 6,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'map_type',
              1 => 0,
              2 => 6,
            ),
          ),
        ),
        42 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'some_type',
              1 => 1,
              2 => 1,
            ),
          ),
          '>' => array(
            0 => 'R',
            1 => array(
              0 => 'some_type',
              1 => 1,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'S',
            1 => 43,
          ),
        ),
        43 => array(
          'k' => array(
            0 => 'S',
            1 => 35,
          ),
          'map' => array(
            0 => 'S',
            1 => 36,
          ),
          'list' => array(
            0 => 'S',
            1 => 45,
          ),
        ),
        44 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 1,
              2 => 3,
            ),
          ),
          '>' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 1,
              2 => 3,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 1,
              2 => 3,
            ),
          ),
        ),
        45 => array(
          '<' => array(
            0 => 'S',
            1 => 46,
          ),
        ),
        46 => array(
          'k' => array(
            0 => 'S',
            1 => 35,
          ),
          'map' => array(
            0 => 'S',
            1 => 36,
          ),
          'list' => array(
            0 => 'S',
            1 => 45,
          ),
        ),
        47 => array(
          '>' => array(
            0 => 'S',
            1 => 48,
          ),
        ),
        48 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'list_type',
              1 => 0,
              2 => 4,
            ),
          ),
          '>' => array(
            0 => 'R',
            1 => array(
              0 => 'list_type',
              1 => 0,
              2 => 4,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'list_type',
              1 => 0,
              2 => 4,
            ),
          ),
        ),
        49 => array(
          ',' => array(
            0 => 'R',
            1 => array(
              0 => 'type',
              1 => 'no',
              2 => 1,
            ),
          ),
          '?' => array(
            0 => 'S',
            1 => 50,
          ),
        ),
        50 => array(
          ',' => array(
            0 => 'R',
            1 => array(
              0 => 'type',
              1 => 'yes',
              2 => 2,
            ),
          ),
        ),
        51 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'some_type',
              1 => 0,
              2 => 1,
            ),
          ),
          ',' => array(
            0 => 'R',
            1 => array(
              0 => 'some_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'S',
            1 => 52,
          ),
        ),
        52 => array(
          'k' => array(
            0 => 'S',
            1 => 57,
          ),
          'map' => array(
            0 => 'S',
            1 => 58,
          ),
          'list' => array(
            0 => 'S',
            1 => 67,
          ),
        ),
        53 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 0,
              2 => 3,
            ),
          ),
          ',' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 0,
              2 => 3,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 0,
              2 => 3,
            ),
          ),
        ),
        54 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 0,
              2 => 1,
            ),
          ),
          ',' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 0,
              2 => 1,
            ),
          ),
        ),
        55 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 1,
              2 => 1,
            ),
          ),
          ',' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 1,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 1,
              2 => 1,
            ),
          ),
        ),
        56 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 2,
              2 => 1,
            ),
          ),
          ',' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 2,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'not_or_type',
              1 => 2,
              2 => 1,
            ),
          ),
        ),
        57 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'basic_type',
              1 => 0,
              2 => 1,
            ),
          ),
          ',' => array(
            0 => 'R',
            1 => array(
              0 => 'basic_type',
              1 => 0,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'basic_type',
              1 => 0,
              2 => 1,
            ),
          ),
        ),
        58 => array(
          '<' => array(
            0 => 'S',
            1 => 59,
          ),
        ),
        59 => array(
          'k' => array(
            0 => 'S',
            1 => 57,
          ),
          'map' => array(
            0 => 'S',
            1 => 58,
          ),
          'list' => array(
            0 => 'S',
            1 => 67,
          ),
        ),
        60 => array(
          ',' => array(
            0 => 'S',
            1 => 61,
          ),
        ),
        61 => array(
          'k' => array(
            0 => 'S',
            1 => 35,
          ),
          'map' => array(
            0 => 'S',
            1 => 36,
          ),
          'list' => array(
            0 => 'S',
            1 => 45,
          ),
        ),
        62 => array(
          '>' => array(
            0 => 'S',
            1 => 63,
          ),
        ),
        63 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'map_type',
              1 => 0,
              2 => 6,
            ),
          ),
          ',' => array(
            0 => 'R',
            1 => array(
              0 => 'map_type',
              1 => 0,
              2 => 6,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'map_type',
              1 => 0,
              2 => 6,
            ),
          ),
        ),
        64 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'some_type',
              1 => 1,
              2 => 1,
            ),
          ),
          ',' => array(
            0 => 'R',
            1 => array(
              0 => 'some_type',
              1 => 1,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'S',
            1 => 65,
          ),
        ),
        65 => array(
          'k' => array(
            0 => 'S',
            1 => 57,
          ),
          'map' => array(
            0 => 'S',
            1 => 58,
          ),
          'list' => array(
            0 => 'S',
            1 => 67,
          ),
        ),
        66 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 1,
              2 => 3,
            ),
          ),
          ',' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 1,
              2 => 3,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 1,
              2 => 3,
            ),
          ),
        ),
        67 => array(
          '<' => array(
            0 => 'S',
            1 => 68,
          ),
        ),
        68 => array(
          'k' => array(
            0 => 'S',
            1 => 35,
          ),
          'map' => array(
            0 => 'S',
            1 => 36,
          ),
          'list' => array(
            0 => 'S',
            1 => 45,
          ),
        ),
        69 => array(
          '>' => array(
            0 => 'S',
            1 => 70,
          ),
        ),
        70 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'list_type',
              1 => 0,
              2 => 4,
            ),
          ),
          ',' => array(
            0 => 'R',
            1 => array(
              0 => 'list_type',
              1 => 0,
              2 => 4,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'list_type',
              1 => 0,
              2 => 4,
            ),
          ),
        ),
        71 => array(
          '<' => array(
            0 => 'S',
            1 => 72,
          ),
        ),
        72 => array(
          'k' => array(
            0 => 'S',
            1 => 35,
          ),
          'map' => array(
            0 => 'S',
            1 => 36,
          ),
          'list' => array(
            0 => 'S',
            1 => 45,
          ),
        ),
        73 => array(
          '>' => array(
            0 => 'S',
            1 => 74,
          ),
        ),
        74 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'list_type',
              1 => 0,
              2 => 4,
            ),
          ),
          '(' => array(
            0 => 'R',
            1 => array(
              0 => 'list_type',
              1 => 0,
              2 => 4,
            ),
          ),
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'list_type',
              1 => 0,
              2 => 4,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'list_type',
              1 => 0,
              2 => 4,
            ),
          ),
        ),
        75 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'some_type',
              1 => 1,
              2 => 1,
            ),
          ),
          '(' => array(
            0 => 'R',
            1 => array(
              0 => 'some_type',
              1 => 1,
              2 => 1,
            ),
          ),
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'some_type',
              1 => 1,
              2 => 1,
            ),
          ),
          '|' => array(
            0 => 'S',
            1 => 76,
          ),
        ),
        76 => array(
          'k' => array(
            0 => 'S',
            1 => 20,
          ),
          'map' => array(
            0 => 'S',
            1 => 21,
          ),
          'list' => array(
            0 => 'S',
            1 => 71,
          ),
        ),
        77 => array(
          '?' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 1,
              2 => 3,
            ),
          ),
          '(' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 1,
              2 => 3,
            ),
          ),
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 1,
              2 => 3,
            ),
          ),
          '|' => array(
            0 => 'R',
            1 => array(
              0 => 'or_type',
              1 => 1,
              2 => 3,
            ),
          ),
        ),
        78 => array(
          '(end-of-file)' => array(
            0 => 'R',
            1 => array(
              0 => 'maybe_optional',
              1 => 'no',
              2 => 1,
            ),
          ),
        ),
      ),
      array(
        0 => array(
          'start' => 1,
          'maybe_optional' => 2,
          'maybe_comment' => 78,
          'type' => 5,
          'some_type' => 12,
          'or_type' => 14,
          'not_or_type' => 75,
          'basic_type' => 17,
          'map_type' => 18,
          'list_type' => 19,
        ),
        3 => array(
          'maybe_comment' => 4,
          'type' => 5,
          'some_type' => 12,
          'or_type' => 14,
          'not_or_type' => 75,
          'basic_type' => 17,
          'map_type' => 18,
          'list_type' => 19,
        ),
        5 => array(
          'comment' => 6,
        ),
        7 => array(
          'comment_text' => 8,
        ),
        15 => array(
          'not_or_type' => 16,
          'basic_type' => 17,
          'map_type' => 18,
          'list_type' => 19,
        ),
        22 => array(
          'type' => 23,
          'some_type' => 49,
          'or_type' => 51,
          'not_or_type' => 64,
          'basic_type' => 54,
          'map_type' => 55,
          'list_type' => 56,
        ),
        24 => array(
          'type' => 25,
          'some_type' => 27,
          'or_type' => 29,
          'not_or_type' => 42,
          'basic_type' => 32,
          'map_type' => 33,
          'list_type' => 34,
        ),
        30 => array(
          'not_or_type' => 31,
          'basic_type' => 32,
          'map_type' => 33,
          'list_type' => 34,
        ),
        37 => array(
          'type' => 38,
          'some_type' => 49,
          'or_type' => 51,
          'not_or_type' => 64,
          'basic_type' => 54,
          'map_type' => 55,
          'list_type' => 56,
        ),
        39 => array(
          'type' => 40,
          'some_type' => 27,
          'or_type' => 29,
          'not_or_type' => 42,
          'basic_type' => 32,
          'map_type' => 33,
          'list_type' => 34,
        ),
        43 => array(
          'not_or_type' => 44,
          'basic_type' => 32,
          'map_type' => 33,
          'list_type' => 34,
        ),
        46 => array(
          'type' => 47,
          'some_type' => 27,
          'or_type' => 29,
          'not_or_type' => 42,
          'basic_type' => 32,
          'map_type' => 33,
          'list_type' => 34,
        ),
        52 => array(
          'not_or_type' => 53,
          'basic_type' => 54,
          'map_type' => 55,
          'list_type' => 56,
        ),
        59 => array(
          'type' => 60,
          'some_type' => 49,
          'or_type' => 51,
          'not_or_type' => 64,
          'basic_type' => 54,
          'map_type' => 55,
          'list_type' => 56,
        ),
        61 => array(
          'type' => 62,
          'some_type' => 27,
          'or_type' => 29,
          'not_or_type' => 42,
          'basic_type' => 32,
          'map_type' => 33,
          'list_type' => 34,
        ),
        65 => array(
          'not_or_type' => 66,
          'basic_type' => 54,
          'map_type' => 55,
          'list_type' => 56,
        ),
        68 => array(
          'type' => 69,
          'some_type' => 27,
          'or_type' => 29,
          'not_or_type' => 42,
          'basic_type' => 32,
          'map_type' => 33,
          'list_type' => 34,
        ),
        72 => array(
          'type' => 73,
          'some_type' => 27,
          'or_type' => 29,
          'not_or_type' => 42,
          'basic_type' => 32,
          'map_type' => 33,
          'list_type' => 34,
        ),
        76 => array(
          'not_or_type' => 77,
          'basic_type' => 17,
          'map_type' => 18,
          'list_type' => 19,
        ),
      ),
      '(end-of-file)',
      $tokens,
      $callback);
  }

}
