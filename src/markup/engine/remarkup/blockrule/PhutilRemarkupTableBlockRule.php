<?php

final class PhutilRemarkupTableBlockRule extends PhutilRemarkupBlockRule {

  public function getMatchingLineCount(array $lines, $cursor) {
    $num_lines = 0;

    if (preg_match('/^\s*<table>/i', $lines[$cursor])) {
      $num_lines++;
      $cursor++;

      while (isset($lines[$cursor])) {
        $num_lines++;
        if (preg_match('@</table>$@i', $lines[$cursor])) {
          break;
        }
        $cursor++;
      }
    }

    return $num_lines;
  }

  public function markupText($text, $children) {
    $matches = array();

    if (!preg_match('@^\s*<table>(.*)</table>$@si', $text, $matches)) {
      return $this->fail(
        $text,
        pht('Bad table (expected %s)', '<table>...</table>'));
    }

    $body = $matches[1];

    $row_fragment = '(?:\s*<tr>(.*)</tr>\s*)';
    $cell_fragment = '(?:\s*<(td|th)>(.*)</(?:td|th)>\s*)';

    // Test that the body contains only valid rows.
    if (!preg_match('@^'.$row_fragment.'+$@Usi', $body)) {
      return $this->fail(
        $body,
        pht('Bad table syntax (expected rows %s)', '<tr>...</tr>'));
    }

    // Capture the rows.
    $row_regex = '@'.$row_fragment.'@Usi';
    if (!preg_match_all($row_regex, $body, $matches, PREG_SET_ORDER)) {
      throw new Exception(
        pht('Bug in Remarkup tables, parsing fails for input: %s', $text));
    }

    $out_rows = array();

    $rows = $matches;
    foreach ($rows as $row) {
      $content = $row[1];

      // Test that the row contains only valid cells.
      if (!preg_match('@^'.$cell_fragment.'+$@Usi', $content)) {
        return $this->fail(
          $content,
          pht('Bad table syntax (expected cells %s)', '<td>...</td>'));
      }

      // Capture the cells.
      $cell_regex = '@'.$cell_fragment.'@Usi';
      if (!preg_match_all($cell_regex, $content, $matches, PREG_SET_ORDER)) {
        throw new Exception(
          pht('Bug in Remarkup tables, parsing fails for input: %s', $text));
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
      id(new PhutilUTF8StringTruncator())
      ->setMaximumGlyphs(32000)
      ->truncateString($near));

    if ($this->getEngine()->isTextMode()) {
      return '('.$message.')';
    }

    return hsprintf('<div style="color: red;">%s</div>', $message);
  }

}
