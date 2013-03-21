<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngineRemarkupTableBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getBlockPattern() {
    return '/^<table>/i';
  }

  public function shouldContinueWithBlock($block, $last_block) {
    // Until we consume a '</table>', keep merging blocks.
    if (preg_match('@</table>$@i', $last_block)) {
      return false;
    }

    return true;
  }

  public function shouldMergeBlocks() {
    return true;
  }

  public function markupText($text) {
    $matches = array();

    if (!preg_match('@^<table>(.*)</table>$@si', $text, $matches)) {
      return $this->fail(
        $text,
        'Bad table (expected <table>...</table>)');
    }

    $body = $matches[1];

    $row_fragment = '(?:\s*<tr>(.*)</tr>\s*)';
    $cell_fragment = '(?:\s*<(td|th)>(.*)</(?:td|th)>\s*)';

    // Test that the body contains only valid rows.
    if (!preg_match('@^'.$row_fragment.'+$@Usi', $body)) {
      return $this->fail(
        $body,
        'Bad table syntax (expected rows <tr>...</tr>)');
    }

    // Capture the rows.
    $row_regex = '@'.$row_fragment.'@Usi';
    if (!preg_match_all($row_regex, $body, $matches, PREG_SET_ORDER)) {
      throw new Exception(
        "Bug in Remarkup tables, parsing fails for input: ".$text);
    }

    $out_rows = array();

    $rows = $matches;
    foreach ($rows as $row) {
      $content = $row[1];

      // Test that the row contains only valid cells.
      if (!preg_match('@^'.$cell_fragment.'+$@Usi', $content)) {
        return $this->fail(
          $content,
          'Bad table syntax (expected cells <td>...</td>)');
      }

      // Capture the cells.
      $cell_regex = '@'.$cell_fragment.'@Usi';
      if (!preg_match_all($cell_regex, $content, $matches, PREG_SET_ORDER)) {
        throw new Exception(
          "Bug in Remarkup tables, parsing fails for input: ".$text);
      }

      $out_cells = array();
      foreach ($matches as $cell) {
        $cell_type = $cell[1];
        $cell_content = $cell[2];

        $out_cells[] = array(
          'type'      => $cell_type,
          'content'   => $this->applyRules($cell_content),
        );
      }

      $out_rows[] = array(
        'type'    => 'tr',
        'content' => $out_cells,
      );
    }

    return $this->renderRemarkupTable($out_rows);
  }

  private function fail($near, $message) {
    $message = sprintf(
      '%s near: %s',
      $message,
      phutil_utf8_shorten($near, 32000));

    if ($this->getEngine()->isTextMode()) {
      return '('.$message.')';
    }

    return hsprintf('<div style="color: red;">%s</div>', $message);
  }

}
