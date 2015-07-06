<?php

/**
 * Simple LR(1) parser generator. Generally, build a parser by setting terminals
 * and rules, then calling @{method:processGrammar}. For example, here is a
 * simple grammar which accepts one or more "a" followed by exactly one "b":
 *
 *    $parser = id(new PhutilParserGenerator())
 *      ->setTerminals(array('a', 'b'))
 *      ->setStartRule('S')
 *      ->setRules(
 *        array(
 *          'S' => 'A b',
 *          'A' => array(
 *            'A a',
 *            'a',
 *          )))
 *      ->processGrammar();
 *
 * To actually parse token streams, use @{method:parseTokens}.
 *
 *    $tokens = get_tokens(); // Usually from PhutilLexer
 *    $callback = 'some_callback';
 *    $tree = $parser->parseTokens($tokens, $callback);
 *
 * The callback is invoked when a grammar rule matches. It should have this
 * signature:
 *
 *    function parser_callback($rule, $production, array $tokens) {
 *      // ...
 *    }
 *
 * The `$rule` is the matching rule; the `$production` is the matching
 * production, and `$tokens` is the matching tokens (for terminal rules) or the
 * return value of previous parse callbacks (for nonterminal rules).
 *
 * You should either return a result of evaluation, or some sort of abstract
 * representation of the parse tree (this is more likely to be useful for more
 * complex grammars).
 *
 * NOTE: This class generates LR(1) parsers, which perform less-than-optimally
 * on large grammars. Worse, it is written in PHP. It is suitable only for
 * very simple grammars with few states.
 *
 * NOTE: These parsers silently resolve reduce/reduce conflicts by choosing the
 * first reduction, and silently resolve shift/reduce conflicts by shifting.
 * These are the same rules used by Yacc, but are implicit.
 *
 * @task rules        Grammar Rules
 * @task rvalidation  Rule Validation
 * @task first        Computing First()
 * @task tables       Computing Action and Goto Tables
 * @task inspect      Inspecting Generator State
 */
final class PhutilParserGenerator extends Phobject {

  private $terminals;
  private $rules;
  private $startRule = 'start';
  private $states = array();
  private $sets = array();
  private $successor = array();
  private $setHashes = array();
  private $actionTable;
  private $gotoTable;

  private $rulesValidated = false;
  private $eofSymbol;
  private $initSymbol;
  private $epsilonSymbol;
  private $endSymbol;

  private $firstTable;

  public function processGrammar() {
    $this->validateRules();
    $this->buildFirstTable();

    $init = $this->getInitSymbol();
    $eof = $this->getEOFSymbol();
    $end = $this->getEndSymbol();

    $this->rules[$init] = array(
      array($this->startRule, $end),
    );
    list($is_new, $state) = $this->addState(
      array(
        array($this->getInitSymbol(), 0, 0, $eof),
      ));
    $this->buildSuccessors($state);

    $this->buildTables();

    return $this;
  }


/* -(  Grammar Rules  )------------------------------------------------------ */


  public function setTerminals(array $terminals) {
    $this->terminals = array_fill_keys($terminals, true);
    return $this;
  }

  public function setRules(array $rules) {
    $this->rules = $rules;
    return $this;
  }

  public function setStartRule($rule_name) {
    $this->startRule = $rule_name;
    return $this;
  }

  public function getStartRule() {
    return $this->startRule;
  }

  public function getEOFSymbol() {
    if ($this->eofSymbol === null) {
      throw new PhutilInvalidStateException('processGrammar');
    }
    return $this->eofSymbol;
  }

  public function getInitSymbol() {
    if ($this->initSymbol === null) {
      throw new PhutilInvalidStateException('processGrammar');
    }
    return $this->initSymbol;
  }

  public function getEpsilonSymbol() {
    if ($this->epsilonSymbol === null) {
      throw new PhutilInvalidStateException('processGrammar');
    }
    return $this->epsilonSymbol;
  }

  public function getEndSymbol() {
    if ($this->endSymbol === null) {
      throw new PhutilInvalidStateException('processGrammar');
    }
    return $this->endSymbol;
  }

  public function isTerminal($symbol) {
    return isset($this->terminals[$symbol]);
  }

  public function isRule($symbol) {
    return isset($this->rules[$symbol]);
  }


/* -(  Rule Validation  )---------------------------------------------------- */


  /**
   * Perform a battery of tests on the provided rules to detect problems which
   * would prevent us from generating a parser.
   *
   * @return void
   * @task rvalidation
   */
  private function validateRules() {
    // Rules must be specified in the right format.
    $this->parseRules();

    // Rules must contain only known symbols.
    $this->validateRuleSymbols();

    // The start rule must exist and be valid.
    $this->validateStartRule();

    // Now, we select printable names for special symbols (EOF, epsilon, etc)
    // that don't conflict with any symbols in the grammar.
    $this->chooseSpecialSymbols();

    // Make sure every terminal can be reached by some rule.
    $this->validateAllTerminalsReachable();

    // Make sure every rule can be reached.
    $this->validateAllRulesReachable();

    // Make sure every rule has some valid reduction.
    $this->validateAllRulesReducible();

    $this->rulesValidated = true;
  }


  /**
   * @task rvalidation
   */
  private function parseRules() {
    foreach ($this->rules as $rule_name => $rule_variants) {
      if (!is_array($rule_variants)) {
        $rule_variants = array($rule_variants);
        $this->rules[$rule_name] = $rule_variants;
      }
      foreach ($rule_variants as $vkey => $variant) {
        if ($variant === null) {
          $variant = array(null);
        } else if (!is_array($variant)) {
          $variant = preg_split('/\s+/', $variant);
        } else {
          foreach ($variant as $symbol) {
            if (($symbol === null) && count($variant) > 1) {
              throw new PhutilInvalidRuleParserGeneratorException(
                pht(
                  "Rule '%s' contains a production '%s' which is ".
                  "nonempty but has a null in it. A rule with other ".
                  "may not contain null.",
                  $rule_name,
                  $vkey));
            }
          }
        }
        $this->rules[$rule_name][$vkey] = array_values($variant);
      }
    }
  }


  /**
   * @task rvalidation
   */
  private function validateRuleSymbols() {
    foreach ($this->rules as $rule => $productions) {
      foreach ($productions as $production_name => $production) {
        foreach ($production as $symbol) {
          if ($symbol === null) {
            continue;
          }
          if ($this->isTerminal($symbol)) {
            continue;
          }
          if ($this->isRule($symbol)) {
            continue;
          }
          $production_string = implode(' ', $production);
          throw new PhutilUnknownSymbolParserGeneratorException(
            pht(
              "Symbol '%s' in production '%s' ('%s') of rule '%s' does not ".
              "name a rule or terminal. Did you misspell a symbol, fail to ".
              "specify a terminal, or forget a rule?",
              $symbol,
              $production_name,
              $production_string,
              $rule));
        }
      }
    }
  }


  /**
   * @task rvalidation
   */
  private function validateStartRule() {
    $start_rule = $this->getStartRule();
    if (!$this->isRule($start_rule)) {
      throw new PhutilUnknownSymbolParserGeneratorException(
        pht(
          "Start rule '%s' does not appear in the rules for the grammar. Use ".
          "%s to choose a different start rule, or add a rule named '%s'.",
          $start_rule,
          'setStartRule()',
          $start_rule));
    }
  }


  /**
   * @task rvalidation
   */
  private function chooseSpecialSymbols() {
    $special = array(
      'eofSymbol'       => '(end-of-file)',
      'epsilonSymbol'   => '(epsilon)',
      'initSymbol'      => '(init)',
      'endSymbol'       => '(end)',
    );

    foreach ($special as $key => $value) {
      while ($this->isRule($value) || $this->isTerminal($value)) {
        $value .= "'";
      }
      $special[$key] = $value;
    }

    $this->eofSymbol = $special['eofSymbol'];
    $this->epsilonSymbol = $special['epsilonSymbol'];
    $this->initSymbol = $special['initSymbol'];
    $this->endSymbol = $special['endSymbol'];

    foreach ($this->rules as $rule => $productions) {
      foreach ($productions as $production_name => $production) {
        foreach ($production as $key => $symbol) {
          if ($symbol === null) {
            $this->rules[$rule][$production_name][$key] = $this->epsilonSymbol;
          }
        }
        $this->rules[$rule][$production_name][] = $this->endSymbol;
      }
    }

    $this->terminals[$this->getEOFSymbol()] = true;
  }


  /**
   * @task rvalidation
   */
  private function validateAllTerminalsReachable() {
    $seen = array();
    foreach ($this->rules as $rule => $productions) {
      foreach ($productions as $production) {
        foreach ($production as $symbol) {
          $seen[$symbol] = true;
        }
      }
    }

    $missing = array_diff_key($this->terminals, $seen);
    unset($missing[$this->getEOFSymbol()]);
    if ($missing) {
      $missing_terminals = array_keys($missing);
      $missing_terminals = implode(', ', $missing_terminals);
      throw new PhutilUnreachableTerminalParserGeneratorException(
        pht(
          'Some terminals do not appear in any rule: %s',
          $missing_terminals));
    }
  }


  /**
   * @task rvalidation
   */
  private function validateAllRulesReachable() {
    $stack = array();
    $reachable = $this->computeReachableRules($this->getStartRule(), $stack);

    $missing = array_diff_key($this->rules, $reachable);
    unset($missing[$this->getStartRule()]);

    if ($missing) {
      $missing_rules = array_keys($missing);
      $missing_rules = implode(', ', $missing_rules);
      throw new PhutilUnreachableRuleParserGeneratorException(
        pht(
          'Some rules can never be reached from any production: %s',
          $missing_rules));
    }
  }


  /**
   * @task rvalidation
   */
  private function computeReachableRules($rule, array &$stack) {
    if (isset($stack[$rule])) {
      return $stack[$rule];
    }

    $stack[$rule] = array();

    foreach ($this->rules[$rule] as $production) {
      foreach ($production as $symbol) {
        if ($this->isRule($symbol)) {
          $stack[$rule][$symbol] = true;
          $stack[$rule] += $this->computeReachableRules($symbol, $stack);
        }
      }
    }

    return $stack[$rule];
  }


  /**
   * @task rvalidation
   */
  private function validateAllRulesReducible() {
    $reducible = array();
    foreach ($this->rules as $rule => $productions) {
      if (!$this->isRuleReducible($rule, $reducible)) {
        throw new PhutilIrreducibleRuleParserGeneratorException(
          pht(
            "Rule '%s' can never be reduced: it recurses indefinitely ".
            "and reaches no production of terminals.",
            $rule));
      }
    }
  }


  /**
   * @task rvalidation
   */
  private function isRuleReducible($rule, array &$reducible) {
    if (isset($reducible[$rule])) {
      return $reducible[$rule];
    }

    // Set this ahead of time so we don't end up in an infinite loop if
    // rules recurse. We'll overwrite it if we find a reduction.
    $reducible[$rule] = false;
    $reducible[$rule] = $this->computeRuleReducible($rule, $reducible);
    return $reducible[$rule];
  }


  /**
   * @task rvalidation
   */
  private function computeRuleReducible($rule, array &$reducible) {
    $epsilon = $this->getEpsilonSymbol();
    $end = $this->getEndSymbol();

    $productions = $this->rules[$rule];

    // In the first pass, try to find a trivially reducible production, e.g. one
    // with epsilon or only terminals. Also, remove recursive productions (those
    // which directly involve the rule itself) because we know we won't be able
    // to reduce them. If we're lucky, this will allow us to determine that the
    // rule is reducible without recursion. For example, we can immediately
    // reduce these productions:
    //
    //    R -> a
    //    R -> b c d
    //    R -> (epsilon)
    //
    // We can never reduce these productions:
    //
    //    R -> R
    //    R -> a R b
    //
    // We might be able to reduce these productions, but they aren't as cheap
    // or easy to figure out, since we need to first determine if other rules
    // can be reduced:
    //
    //    R -> X Y
    //    R -> X a
    //
    // If we find a reduction, we return immediately.

    foreach ($productions as $key => $production) {
      $has_only_terminals = true;
      foreach ($production as $symbol) {
        if ($symbol == $end) {
          break;
        } else if ($symbol == $epsilon) {
          // The rule contains an epsilon production, which can always reduce
          // it.
          return true;
        } else if ($symbol == $rule) {
          // The rule contains itself; this production is never reducible. We
          // must find another reducible production.
          unset($productions[$key]);
          continue 2;
        } else if ($this->isTerminal($symbol)) {
          // This is a terminal; keep looking. We'll be able to reduce the
          // production if it contains only terminals.
          continue;
        } else {
          // This is a rule, so we can't trivially reduce it. We'll keep it
          // for the next round if we can't find any trivial reductions.
          $has_only_terminals = false;
          break;
        }
      }

      if ($has_only_terminals) {
        return true;
      }
    }

    // If we have no productions left, this rule can't be reduced.
    if (empty($productions)) {
      return false;
    }

    // We have remaining productions which include other rules. Look for a
    // nontrivial reduction. For example:
    //
    //    R -> X Y
    //    X -> x
    //    Y -> y
    //
    // In this case, X and Y are both reducible, so "X Y" is reducible and thus
    // R is reducible.
    foreach ($productions as $production) {
      $can_reduce = true;
      foreach ($production as $symbol) {
        // NOTE: We don't need to check for epsilon here, because we would
        // already have determined the rule was reducible if we had an epsilon
        // production.
        if ($symbol == $end) {
          break;
        } else if ($this->isTerminal($symbol)) {
          continue;
        } else if (!$this->isRuleReducible($symbol, $reducible)) {
          $can_reduce = false;
          break;
        }
      }

      if ($can_reduce) {
        // The production contained only terminals and reducible rules, so it
        // is reducible. We're good and don't need to examine remaining
        // productions.
        return true;
      }
    }

    // We didn't find any reducible productions.
    return false;
  }


/* -(  Computing First()  )-------------------------------------------------- */


  private function buildFirstTable() {
    $this->firstTable = array();
    foreach ($this->rules as $rule => $productions) {
      $this->buildRuleFirst($rule);
    }
  }

  private function buildRuleFirst($rule) {
    if (isset($this->firstTable[$rule])) {
      return $this->firstTable[$rule];
    }

    $this->firstTable[$rule] = array();
    $productions = $this->rules[$rule];
    foreach ($productions as $key => $production) {
      $this->firstTable[$rule] += $this->getFirstForProduction($production);
    }

    return $this->firstTable[$rule];
  }

  private function getFirstForProduction(array $production) {
    $set = array();

    $end = $this->getEndSymbol();
    $epsilon = $this->getEpsilonSymbol();
    $eof = $this->getEOFSymbol();

    $accept_epsilon = true;
    foreach ($production as $symbol) {
      if ($symbol === $end) {
        break;
      } else if ($symbol === $epsilon) {
        break;
      } else if ($this->isTerminal($symbol)) {
        $set[$symbol] = true;
        $accept_epsilon = false;
        break;
      } else {
        $symbol_set = $this->buildRuleFirst($symbol);

        $has_epsilon = isset($symbol_set[$epsilon]);
        unset($symbol_set[$epsilon]);
        $set += $symbol_set;
        if (!$has_epsilon) {
          $accept_epsilon = false;
          break;
        }
      }
    }

    if ($accept_epsilon) {
      $set[$epsilon] = true;
    }

    return $set;
  }


/* -(  Computing States  )--------------------------------------------------- */


  private function addState(array $set) {
    $seen = array();
    foreach ($set as $item) {
      $seen[$item[0]][$item[1]][$item[2]][$item[3]] = true;
    }

    $end = $this->getEndSymbol();
    $epsilon = $this->getEpsilonSymbol();

    for ($ii = 0; $ii < count($set); $ii++) {
      $item = $set[$ii];

      $production = $this->rules[$item[0]][$item[1]];
      $next = $production[$item[2]];
      if ($this->isTerminal($next)) {
        continue;
      } else if ($next === $epsilon) {
        continue;
      } else if ($next === $end) {
        continue;
      }

      $v = array_slice($production, $item[2] + 1, -1);
      $v[] = $item[3];
      $v[] = $end;

      $firsts = $this->getFirstForProduction($v);

      foreach ($firsts as $nfirst => $ignored) {
        if (!$this->isTerminal($nfirst)) {
          unset($firsts[$nfirst]);
        }
      }

      foreach ($this->rules[$next] as $pkey => $nproduction) {
        foreach ($firsts as $nfirst => $ignored) {
          if (isset($seen[$next][$pkey][0][$nfirst])) {
            continue;
          }
          $set[] = array($next, $pkey, 0, $nfirst);
          $seen[$next][$pkey][0][$nfirst] = true;
        }
      }
    }

    $hash = $this->hashSet($set);
    if (isset($this->setHashes[$hash])) {
      return array(false, $this->setHashes[$hash]);
    }

    $this->states[] = $set;
    $state = last_key($this->states);
    $this->setHashes[$hash] = $state;

    return array(true, $state);
  }

  private function buildSuccessors($start_state) {
    $end = $this->getEndSymbol();

    $nexts = array();
    foreach ($this->states[$start_state] as $item) {
      $next = $this->rules[$item[0]][$item[1]][$item[2]];
      if ($next === $end) {
        continue;
      }
      $nexts[$next][] = array(
        $item[0],
        $item[1],
        $item[2] + 1,
        $item[3],
      );
    }

    foreach ($nexts as $next => $items) {
      list($is_new, $state) = $this->addState($items);
      $this->successor[$start_state][$next] = $state;
      if ($is_new) {
        $this->buildSuccessors($state);
      }
    }
  }

  private function hashSet(array $set) {
    foreach ($set as $k => $item) {
      $set[$k] = implode("\0", $item);
    }
    sort($set);
    $set = implode("\1", $set);

    return md5($set);
  }


  private function buildTables() {
    $action = array();
    $goto = array();

    $end = $this->getEndSymbol();
    $eof = $this->getEOFSymbol();
    $init = $this->getInitSymbol();

    foreach ($this->states as $state => $items) {
      $shift = array();
      $reduce = array();
      $accept = false;
      foreach ($items as $item) {
        $next = $this->rules[$item[0]][$item[1]][$item[2]];
        if ($next == $end) {
          if ($item[0] !== $init) {
            $reduce[$item[3]][] = $item;
          } else if ($item[0] === $init && $item[3] === $eof) {
            $accept = $item;
          }
        } else if ($this->isTerminal($next)) {
          $shift[$next] = $item;
        } else {
          $goto[$state][$next] = $this->successor[$state][$next];
        }
      }

      foreach ($reduce as $next => $reductions) {
        if (count($reductions) > 1) {
          $ways = array();
          foreach ($reductions as $reduction) {
            $ways[] = "{$reduction[0]}/{$reduction[1]}";
          }
          $ways = implode('; ', $ways);

          // TODO: As below, we should have more explicit handling of
          // reduce/reduce conflicts. For now, just pick the first one.

          if (false) {
            throw new Exception(
              pht(
                "Reduce/reduce conflict: from state '%s', when a ".
                "'%s' is encountered, it may be reduced in multiple ".
                "ways: %s",
                $state,
                $next,
                $ways));
          }
        }
        $reduce[$next] = head($reductions);
      }

      $srconflicts = array_intersect_key($shift, $reduce);
      foreach ($srconflicts as $next => $ignored) {

        // TODO: We should probably have better or more explicit handling of
        // shift/reduce conflicts. For now, we just shift.

        if (false) {
          $what = $reduce[$next][0];
          throw new Exception(
            pht(
              "Shift/reduce conflict: from state '%s', when a '%s' ".
              "is encountered, shifting conflicts with reducing '%s'.",
              $state,
              $next,
              $what));
        } else {
          // Resolve the shift/reduce by shifting.
          $reduce = array();
        }
      }

      if ($accept && isset($shift[$eof])) {
        throw new Exception(pht('Accept/shift conflict!'));
      }

      if ($accept && isset($reduce[$eof])) {
        throw new Exception(pht('Accept/reduce conflict!'));
      }

      foreach ($reduce as $next => $item) {
        $action[$state][$next] = array(
          'R',
          array(
            $item[0],
            $item[1],
            count($this->rules[$item[0]][$item[1]]) - 1,
          ),
        );
      }

      foreach ($shift as $next => $item) {
        $action[$state][$next] = array(
          'S',
          $this->successor[$state][$next],
        );
      }

      if ($accept) {
        $action[$state][$eof] = array('A');
      }
    }

    $this->actionTable = $action;
    $this->gotoTable = $goto;
  }

  public function generateParserFunction($name) {
    $out = array();
    $out[] = 'function '.$name.'(array $tokens, $callback) {';
    $out[] = '  return '.__CLASS__.'::parseTokensWithTables(';
    $out[] = '    '.$this->formatAndIndent($this->actionTable, 4).',';
    $out[] = '    '.$this->formatAndIndent($this->gotoTable, 4).',';
    $out[] = '    '.$this->formatAndIndent($this->getEOFSymbol(), 4).',';
    $out[] = '    $tokens,';
    $out[] = '    $callback);';
    $out[] = '}';
    return implode("\n", $out);
  }

  private function formatAndIndent($var, $depth) {
    $var = phutil_var_export($var);
    $var = str_replace("\n", "\n".str_repeat(' ', $depth), $var);

    return $var;
  }

  public function parseTokens(array $tokens, $callback) {
    return self::parseTokensWithTables(
      $this->actionTable,
      $this->gotoTable,
      $this->getEOFSymbol(),
      $tokens,
      $callback);
  }

  public static function parseTokensWithTables(
    $action_table,
    $goto_table,
    $eof_symbol,
    array $tokens,
    $callback) {

    $state_stack = array(0);
    $token_stack = array();

    $tokens = array_reverse($tokens);
    while (true) {
      $state = end($state_stack);

      if (empty($tokens)) {
        $next = $eof_symbol;
      } else {
        $next_token = end($tokens);
        $next = $next_token[0];
      }

      if (!isset($action_table[$state][$next])) {
        $expected = implode(', ', array_keys($action_table[$state]));
        throw new Exception(
          pht(
            "Unexpected '%s' in state %s! Expected: %s",
            $next,
            $state,
            $expected));
      }

      $action = $action_table[$state][$next];

      switch ($action[0]) {
        case 'S':
          $state_stack[] = $action[1];
          $token_stack[] = array_pop($tokens);
          break;
        case 'R':
          $r_rule = $action[1][0];
          $r_prod = $action[1][1];
          $r_size = $action[1][2];

          $token_v = array();
          while ($r_size--) {
            $token_v[] = array_pop($token_stack);
            array_pop($state_stack);
          }
          $token_v = array_reverse($token_v);
          $token_stack[] = call_user_func_array(
            $callback,
            array($r_rule, $r_prod, $token_v));
          $goto = $goto_table[end($state_stack)][$r_rule];
          $state_stack[] = $goto;
          break;
        case 'A':
          break 2;
      }
    }

    return head($token_stack);
  }


/* -(  Inspecting Generator State  )----------------------------------------- */


  /**
   * @task inspect
   */
  public function inspectRules() {
    if (!$this->rulesValidated) {
      throw new PhutilInvalidStateException('processGrammar');
    }
    return $this->rules;
  }


  /**
   * @task inspect
   */
  public function inspectFirstTable() {
    if ($this->firstTable === null) {
      throw new PhutilInvalidStateException('processGrammar');
    }
    return $this->firstTable;
  }


}
