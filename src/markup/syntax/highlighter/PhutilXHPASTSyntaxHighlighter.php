<?php

final class PhutilXHPASTSyntaxHighlighter extends Phobject {

  public function getHighlightFuture($source) {
    $scrub = false;
    if (strpos($source, '<?') === false) {
      $source = "<?php\n".$source."\n";
      $scrub = true;
    }

    return new PhutilXHPASTSyntaxHighlighterFuture(
      PhutilXHPASTBinary::getParserFuture($source),
      $source,
      $scrub);
  }

}
