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

}
