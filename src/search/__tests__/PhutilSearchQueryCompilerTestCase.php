<?php

final class PhutilSearchQueryCompilerTestCase
  extends PhutilTestCase {


  public function testCompileQueries() {
    $tests = array(
      '' => '',
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

  private function assertCompileQueries(array $tests, $operators = null) {
    foreach ($tests as $input => $expect) {
      $caught = null;

      try {
        $compiler = id(new PhutilSearchQueryCompiler())
          ->setQuery($input);

        if ($operators !== null) {
          $compiler->setOperators($operators);
        }

        $query = $compiler->compileQuery();
      } catch (PhutilSearchQueryCompilerSyntaxException $ex) {
        $caught = $ex;
      }

      if ($caught !== null) {
        $query = false;
      }

      $this->assertEqual(
        $expect,
        $query,
        pht('Compilation of query: %s', $input));
    }
  }

}
