<?php

final class XHPASTNodeTestCase extends PhutilTestCase {

  public function testGetStringVariables() {
    $this->assertStringVariables(array(), '""');
    $this->assertStringVariables(array(2 => 'abc'), '"$abc"');
    $this->assertStringVariables(array(), '"\$abc"');
    $this->assertStringVariables(array(2 => 'a'), '"$a[1]"');
    $this->assertStringVariables(array(3 => 'a'), '"{$a[1]}"');
    $this->assertStringVariables(array(2 => 'a', 5 => 'a'), '"$a $a"');

    $this->assertStringVariables(array(), "''");
    $this->assertStringVariables(array(), "'\$a'");

    $this->assertStringVariables(array(), "<<<EOT\n\nEOT");
    $this->assertStringVariables(array(8 => 'a'), "<<<EOT\n\$a\nEOT");

    $this->assertStringVariables(array(), "<<<'EOT'\n\$a\nEOT");
  }

  private function assertStringVariables($expected, $string) {
    $statement = XHPASTTree::newStatementFromString($string);
    $this->assertEqual(
      $expected,
      $statement->getChildByIndex(0)->getStringVariables(),
      $string);
  }

  public function testGetNamespace() {
    $dir   = dirname(__FILE__).'/namespace/';
    $files = id(new FileFinder($dir))
      ->withType('f')
      ->withSuffix('php.test')
      ->find();

    foreach ($files as $file) {
      list($tree, $expect) = $this->readTestData($dir.'/'.$file);

      $root    = $tree->getRootNode();
      $classes = $root->selectDescendantsOfType('n_CLASS_DECLARATION');

      foreach ($classes as $class) {
        $id = (string)$class->getID();

        if (idx($expect, $id, false) === false) {
          throw new Exception(
            pht(
              'No expected value for node %d in file "%s".',
              $class->getID(),
              $file));
        }

        $this->assertEqual(
          $expect[$id],
          $class->getNamespace());
      }
    }
  }

  /**
   * Reads and parses test data from a specified file.
   *
   * This method reads and parses test data from a file. The file is expected
   * to have the following structure
   *
   * ```
   * <?php
   * // PHP code goes here.
   * ~~~~~~~~~~
   * {
   *   // JSON dictionary containing expected results from testing method.
   * }
   * ```
   *
   * @param  string                 The path to the test file.
   * @return pair<XHPASTTree, map>  The first element of the pair is the
   *                                `XHPASTTree` contained within the test file.
   *                                The second element of the pair is the
   *                                "expect" data.
   */
  private function readTestData($file) {
    $contents = Filesystem::readFile($file);
    $contents = preg_split('/^~{10}$/m', $contents);

    if (count($contents) < 2) {
      throw new Exception(
        pht(
          "Expected '%s' separating test case and results.",
          '~~~~~~~~~~'));
    }

    list($data, $expect) = $contents;

    $tree = XHPASTTree::newFromData($data);
    $expect = phutil_json_decode($expect);

    return array($tree, $expect);
  }

}
