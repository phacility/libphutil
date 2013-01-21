<?php

/**
 * Test cases for @{class:PhutilRemarkupEngine}.
 *
 * @group testcase
 */
final class PhutilRemarkupEngineTestCase extends PhutilTestCase {

  public function testEngine() {
    $root = dirname(__FILE__).'/remarkup/';
    foreach (Filesystem::listDirectory($root, $hidden = false) as $file) {
      $this->markupText($root.$file);
    }
  }

  private function markupText($markup_file) {
    $contents = Filesystem::readFile($markup_file);
    $file = basename($markup_file);

    $parts = explode("\n~~~~~~~~~~\n", $contents);
    $this->assertEqual(2, count($parts));

    list($input_remarkup, $expected_output) = $parts;
    $expected_output = preg_replace('/\n\z/', '', $expected_output);

    $engine = $this->buildNewTestEngine();

    switch ($file) {
      case 'raw-escape.txt':

        // NOTE: Here, we want to test PhutilRemarkupRuleEscapeRemarkup and
        // PhutilRemarkupBlockStorage, which are triggered by "\1". In the
        // test, "~" is used as a placeholder for "\1" since it's hard to type
        // "\1".

        $input_remarkup = str_replace("~", "\1", $input_remarkup);
        $expected_output = str_replace("~", "\1", $expected_output);
        break;
      case 'toc.txt':
        $engine->setConfig('header.generate-toc', true);
        break;
    }

    $actual_output = $engine->markupText($input_remarkup);

    switch ($file) {
      case 'toc.txt':
        $table_of_contents =
          PhutilRemarkupEngineRemarkupHeaderBlockRule::renderTableOfContents(
            $engine);
        $actual_output = $table_of_contents."\n\n".$actual_output;
        break;
    }

    $this->assertEqual(
      $expected_output,
      $actual_output,
      "Failed to markup file '{$file}'.");
  }

  private function buildNewTestEngine() {
    $engine = new PhutilRemarkupEngine();

    $engine->setConfig(
      'uri.allowed-protocols',
      array(
        'http' => true,
      ));

    $rules = array();
    $rules[] = new PhutilRemarkupRuleEscapeRemarkup();
    $rules[] = new PhutilRemarkupRuleMonospace();
    $rules[] = new PhutilRemarkupRuleDocumentLink();
    $rules[] = new PhutilRemarkupRuleHyperlink();
    $rules[] = new PhutilRemarkupRuleEscapeHTML();
    $rules[] = new PhutilRemarkupRuleBold();
    $rules[] = new PhutilRemarkupRuleItalic();
    $rules[] = new PhutilRemarkupRuleDel();

    $blocks = array();
    $blocks[] = new PhutilRemarkupEngineRemarkupHeaderBlockRule();
    $blocks[] = new PhutilRemarkupEngineRemarkupListBlockRule();
    $blocks[] = new PhutilRemarkupEngineRemarkupCodeBlockRule();
    $blocks[] = new PhutilRemarkupEngineRemarkupNoteBlockRule();
    $blocks[] = new PhutilRemarkupEngineRemarkupSimpleTableBlockRule();
    $blocks[] = new PhutilRemarkupEngineRemarkupDefaultBlockRule();

    foreach ($blocks as $block) {
      if (!($block instanceof PhutilRemarkupEngineRemarkupCodeBlockRule)) {
        $block->setMarkupRules($rules);
      }
    }

    $engine->setBlockRules($blocks);

    return $engine;
  }

}
