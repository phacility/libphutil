<?php

/**
 * @group markup
 * @stable
 */
abstract class PhutilRemarkupEngineMultiLineEnclosedBlockRule
  extends PhutilRemarkupEngineBlockRule {

  abstract public function getBlockSpecifier();

  /**
   * Parse the a block from given lines with the start and end marked by
   * a block specifier.
   *
   * @param array $lines
   * @param int   $cursor
   *
   * @return int
   */
  public function getMatchingLineCount(array $lines, $cursor) {
    $spec = $this->getBlockSpecifier();
    $num_lines = 0;
    $match_ticks = null;
    if (preg_match("/^(\s{2,}).+/", $lines[$cursor])) {
      $match_ticks = false;
    } else if (preg_match("/^(${spec})/", $lines[$cursor])) {
      $match_ticks = true;
    } else {
      return $num_lines;
    }

    $num_lines++;

    if ($match_ticks &&
        preg_match("/^({$spec})(.*)(${spec})\s*$/", $lines[$cursor])) {
      return $num_lines;
    }

    $cursor++;

    while (isset($lines[$cursor])) {
      if ($match_ticks) {
        if (preg_match("/{$spec}\s*$/", $lines[$cursor])) {
          $num_lines++;
          break;
        }
        $num_lines++;
      } else {
        if (strlen(trim($lines[$cursor]))) {
          if (!preg_match('/^\s{2,}/', $lines[$cursor])) {
            break;
          }
        }
        $num_lines++;
      }
      $cursor++;
    }

    return $num_lines;
  }

}
