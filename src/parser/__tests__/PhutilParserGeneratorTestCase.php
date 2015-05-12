<?php

final class PhutilParserGeneratorTestCase extends PhutilTestCase {

  public function testBogusGrammar() {
    $generator = id(new PhutilParserGenerator())
      ->setTerminals(array('a'))
      ->setStartRule('S')
      ->setRules(
        array(
          'S' => 'a b',
        ));

    $caught = null;
    try {
      // Expect "b is not a rule or terminal".
      $generator->processGrammar();
    } catch (PhutilUnknownSymbolParserGeneratorException $ex) {
      $caught = $ex;
    }

    $this->assertTrue($caught instanceof Exception);
  }

  public function testBadStartRule() {
    $generator = id(new PhutilParserGenerator())
      ->setTerminals(array('a'))
      ->setStartRule('Q')
      ->setRules(
        array(
          'S' => 'a',
        ));

    $caught = null;
    try {
      // Expect "no start rule Q".
      $generator->processGrammar();
    } catch (PhutilUnknownSymbolParserGeneratorException $ex) {
      $caught = $ex;
    }

    $this->assertTrue($caught instanceof Exception);
  }

  public function testMessySymbols() {
    // This is testing that internal defaults are correctly changed when they
    // would conflict with the provided grammar. This is a messy test which
    // relies on a lot of implementation details.

    $generator = id(new PhutilParserGenerator())
      ->setTerminals(array('(init)', 'x', 'y', 'start', '(end)'))
      ->setStartRule('(epsilon)')
      ->setRules(
        array(
          '(epsilon)' => array(
            array('s p a c e s'),
          ),
          's p a c e s' => '(init) x start (end-of-file) y',
          '(end-of-file)' => array(
            '(end)',
            null,
          ),
        ))
      ->processGrammar();

    $rules = $generator->inspectRules();

    $init = $generator->getInitSymbol();
    $eof = $generator->getEOFSymbol();
    $epsilon = $generator->getEpsilonSymbol();
    $end = $generator->getEndSymbol();

    $this->assertFalse($init == '(init)');
    $this->assertFalse($eof == '(end-of-file)');
    $this->assertFalse($epsilon == '(epsilon)');
    $this->assertFalse($end == '(end)');

    $keys = array_keys($rules);
    $expect = array('(end-of-file)', '(epsilon)', 's p a c e s', $init);
    sort($keys);
    sort($expect);
    $this->assertEqual($keys, $expect);

    $this->assertEqual(
      array(
        array('s p a c e s', $end),
      ),
      $rules['(epsilon)']);

    $this->assertEqual(
      array(
        array('(end)', $end),
        array($epsilon, $end),
      ),
      $rules['(end-of-file)']);
  }

  public function testUnreachableTerminal() {
    $generator = id(new PhutilParserGenerator())
      ->setTerminals(array('x', 'y'))
      ->setStartRule('S')
      ->setRules(
        array(
          'S' => 'x',
        ));

    $caught = null;
    try {
      $generator->processGrammar();
    } catch (PhutilUnreachableTerminalParserGeneratorException $ex) {
      $caught = $ex;
    }

    $this->assertTrue($caught instanceof Exception);
  }

  public function testUnreachableRule() {
    $generator = id(new PhutilParserGenerator())
      ->setTerminals(array('x'))
      ->setStartRule('S')
      ->setRules(
        array(
          'S' => 'x',
          'A' => 'B',
          'B' => 'x',
        ));

    $caught = null;
    try {
      $generator->processGrammar();
    } catch (PhutilUnreachableRuleParserGeneratorException $ex) {
      $caught = $ex;
    }

    $this->assertTrue($caught instanceof Exception);
  }

  public function testIrreducibleGrammars() {
    $tests = array(
      'trivially irreducible' => array(
        true,
        array(
          'S' => array('E', 'x'),
          'E' => 'E',
        ),
      ),
      'nontrivially irreducible' => array(
        true,
        array(
          'S' => array('X', 'x'),
          'X' => 'Y',
          'Y' => 'Z',
          'Z' => 'X',
        ),
      ),
      'left-recursive reducible' => array(
        false,
        array(
          'S' => 'E',
          'E' => array('E x', 'x'),
        ),
      ),
      'right-recursive reducible' => array(
        false,
        array(
          'S' => 'E',
          'E' => array('x', 'x E'),
        ),
      ),
    );

    foreach ($tests as $test) {
      list($expect, $rules) = $test;

      $generator = id(new PhutilParserGenerator())
        ->setTerminals(array('x'))
        ->setStartRule('S')
        ->setRules($rules);

      $caught = null;
      try {
        $generator->processGrammar();
      } catch (PhutilIrreducibleRuleParserGeneratorException $ex) {
        $caught = $ex;
      }

      $this->assertEqual($expect, ($caught instanceof Exception));
    }
  }

  public function testFirst() {
    $generator = $this->buildABCGenerator()->processGrammar();

    $first = $generator->inspectFirstTable();
    ksort($first);

    foreach ($first as $key => $table) {
      ksort($table);
      $first[$key] = $table;
    }

    $this->assertEqual(
      array(
        'A' => array(
          '(epsilon)' => true,
          'a' => true,
          'b' => true,
        ),
        'B' => array(
          'c' => true,
        ),
        'C' => array(
          '(epsilon)' => true,
          'b' => true,
        ),
        'S' => array(
          'a' => true,
          'b' => true,
          'c' => true,
        ),
      ),
      $first);
  }

  public function testStates() {
    $generator = id(new PhutilParserGenerator())
      ->setTerminals(array('a', 'b'))
      ->setStartRule('S')
      ->setRules(
        array(
          'S' => 'X X',
          'X' => array(
            'a X',
            'b',
          ),
        ))
      ->processGrammar();

    $this->assertTrue(true);
  }

  public function testETParser() {
    $generator = $this->buildETGenerator()->processGrammar();

    $result = $generator->parseTokens(
      array(
        array('n', 3),
        array('+', '+'),
        array('n', 5),
      ),
      array($this, 'didReduceET'));

    $this->assertEqual(8, $result);
  }

  public function didReduceET($rule, $production, array $tokens) {
    switch ($rule) {
      case 'S':
        return $tokens[0];
      case 'E':
        switch ($production) {
          case 0:
            return $tokens[0] + $tokens[2];
          case 1:
            return $tokens[0];
        }
        break;
      case 'T':
        switch ($production) {
          case 0:
            return $tokens[1];
          case 1:
            return $tokens[0][1];
        }
        break;
    }

    throw new Exception(pht('Unexpected rule in ET grammar.'));
  }

  private function buildABCGenerator() {
    $terminals = array(
      'a',
      'b',
      'c',
    );

    $rules = array(
      'S' => 'A B',
      'A' => array('C a', null),
      'B' => array('B a A C', 'c'),
      'C' => array('b', null),
    );

    $generator = id(new PhutilParserGenerator())
      ->setTerminals($terminals)
      ->setStartRule('S')
      ->setRules($rules);

    return $generator;
  }

  private function buildETGenerator() {
    // This grammar and the corresponding tests are based on:
    // http://dragonbook.stanford.edu/lecture-notes/Stanford-CS143/08-Bottom-Up-Parsing.pdf
    // http://dragonbook.stanford.edu/lecture-notes/Stanford-CS143/09-SLR-Parsing.pdf

    $terminals = array(
      '(',
      'n',
      ')',
      '+',
    );

    $rules = array(
      'S' => 'E',
      'E' => array('E + T', 'T'),
      'T' => array('( E )', 'n'),
    );

    $generator = id(new PhutilParserGenerator())
      ->setTerminals($terminals)
      ->setStartRule('S')
      ->setRules($rules);

    return $generator;
  }


}
