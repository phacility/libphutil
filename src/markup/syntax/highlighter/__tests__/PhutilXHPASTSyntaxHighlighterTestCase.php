<?php

final class PhutilXHPASTSyntaxHighlighterTestCase extends PhutilTestCase {

  private function highlight($source) {
    $highlighter = new PhutilXHPASTSyntaxHighlighter();
    $future = $highlighter->getHighlightFuture($source);
    return $future->resolve();
  }

  private function read($file) {
    $path = dirname(__FILE__).'/xhpast/'.$file;
    return Filesystem::readFile($path);
  }

  public function testBuiltinClassnames() {
    $this->assertEqual(
      $this->read('builtin-classname.expect'),
      (string)$this->highlight($this->read('builtin-classname.source')),
      'Builtin classnames should not be marked as linkable symbols.');
    $this->assertEqual(
      $this->read('trailing-comment.expect'),
      (string)$this->highlight($this->read('trailing-comment.source')),
      'Trailing comments should not be dropped.');
    $this->assertEqual(
      $this->read('multiline-token.expect'),
      (string)$this->highlight($this->read('multiline-token.source')),
      'Multi-line tokens should be split across lines.');
  }

}
