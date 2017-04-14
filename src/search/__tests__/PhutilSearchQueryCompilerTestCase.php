<?php

final class PhutilSearchQueryCompilerTestCase
  extends PhutilTestCase {

  public function testCompileQueries() {
    $tests = array(
      '' => null,
      'cat dog' => '+"cat" +"dog"',
      'cat -dog' => '+"cat" -"dog"',
      'cat-dog' => '+"cat-dog"',

      // If there are spaces after an operator, the operator applies to the
      // next search term.
      'cat - dog' => '+"cat" -"dog"',

      // Double quotes serve as delimiters even if there is no whitespace
      // between terms.
      '"cat"dog' => '+"cat" +"dog"',

      // This query is too long.
      str_repeat('x', 2048) => false,

      // Multiple operators are not permitted.
      '++cat' => false,
      '+-cat' => false,
      '--cat' => false,

      // Stray operators are not permitted.
      '+' => false,
      'cat +' => false,

      // Double quotes must be paired.
      '"' => false,
      'cat "' => false,
      '"cat' => false,
      'A"' => false,
      'A"B"' => '+"A" +"B"',
    );

    $this->assertCompileQueries($tests);

    // Test that we compile queries correctly if the operators have been
    // swapped to use "AND" by default.
    $operator_tests = array(
      'cat dog' => '"cat" "dog"',
      'cat -dog' => '"cat" -"dog"',
    );
    $this->assertCompileQueries($operator_tests, ' |-><()~*:""&\'');


    // Test that we compile queries correctly if the quote operators have
    // been swapped to differ.
    $quote_tests = array(
      'cat dog' => '+[cat] +[dog]',
      'cat -dog' => '+[cat] -[dog]',
    );
    $this->assertCompileQueries($quote_tests, '+ -><()~*:[]&|');

  }

  public function testCompileQueriesWithStemming() {
    $stemming_tests = array(
      'cat dog' => array(
        null,
        '+"cat" +"dog"',
      ),
      'cats dogs' => array(
        null,
        '+"cat" +"dog"',
      ),
      'cats "dogs"' => array(
        '+"dogs"',
        '+"cat"',
      ),
      '"blessed blade" of the windseeker' => array(
        '+"blessed blade"',
        '+"of" +"the" +"windseek"',
      ),
      'mailing users for mentions on tasks' => array(
        null,
        '+"mail" +"user" +"for" +"mention" +"on" +"task"',
      ),
    );

    $stemmer = new PhutilSearchStemmer();
    $this->assertCompileQueries($stemming_tests, null, $stemmer);
  }

  private function assertCompileQueries(
    array $tests,
    $operators = null,
    PhutilSearchStemmer $stemmer = null) {
    foreach ($tests as $input => $expect) {
      $caught = null;

      $query = null;
      $literal_query = null;
      $stemmed_query = null;

      try {
        $compiler = new PhutilSearchQueryCompiler();

        if ($operators !== null) {
          $compiler->setOperators($operators);
        }

        if ($stemmer !== null) {
          $compiler->setStemmer($stemmer);
        }

        $tokens = $compiler->newTokens($input);

        if ($stemmer) {
          $literal_query = $compiler->compileLiteralQuery($tokens);
          $stemmed_query = $compiler->compileStemmedQuery($tokens);
        } else {
          $query = $compiler->compileQuery($tokens);
        }
      } catch (PhutilSearchQueryCompilerSyntaxException $ex) {
        $caught = $ex;
      }

      if ($caught !== null) {
        $query = false;
        $literal_query = false;
        $stemmed_query = false;
      }

      if (!$stemmer) {
        $this->assertEqual(
          $expect,
          $query,
          pht('Compilation of query: %s', $input));
      } else {
        $this->assertEqual(
          $expect,
          ($literal_query === false)
            ? false
            : array($literal_query, $stemmed_query),
          pht('Stemmed compilation of query: %s', $input));
      }
    }
  }

}
