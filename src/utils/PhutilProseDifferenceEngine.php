<?php

final class PhutilProseDifferenceEngine extends Phobject {

  public function getDiff($u, $v) {
    $diff = id(new PhutilProseDiff());

    $this->buildDiff($diff, $u, $v, 1);
    $diff->reorderParts();

    return $diff;
  }

  private function buildDiff(PhutilProseDiff $diff, $u, $v, $level) {
    if ($level == 4) {
      $diff->addPart('-', $u);
      $diff->addPart('+', $v);
      return;
    }

    $u_parts = $this->splitCorpus($u, $level);
    $v_parts = $this->splitCorpus($v, $level);

    $matrix = id(new PhutilEditDistanceMatrix())
      ->setSequences($u_parts, $v_parts)
      ->setComputeString(true);

    // For word-level and character-level changes, smooth the output string
    // to reduce the choppiness of the diff.
    if ($level > 1) {
      $matrix->setApplySmoothing(PhutilEditDistanceMatrix::SMOOTHING_FULL);
    }

    $u_pos = 0;
    $v_pos = 0;

    $edits = $matrix->getEditString();
    $edits_length = strlen($edits);

    for ($ii = 0; $ii < $edits_length; $ii++) {
      $c = $edits[$ii];
      if ($c == 's') {
        $diff->addPart('=', $u_parts[$u_pos]);
        $u_pos++;
        $v_pos++;
      } else if ($c == 'd') {
        $diff->addPart('-', $u_parts[$u_pos]);
        $u_pos++;
      } else if ($c == 'i') {
        $diff->addPart('+', $v_parts[$v_pos]);
        $v_pos++;
      } else if ($c == 'x') {
        $this->buildDiff($diff, $u_parts[$u_pos], $v_parts[$v_pos], $level + 1);
        $u_pos++;
        $v_pos++;
      } else {
        throw new Exception(
          pht(
            'Unexpected character ("%s") in edit string.',
            $c));
      }
    }
  }

  private function splitCorpus($corpus, $level) {
    switch ($level) {
      case 1:
        // Level 1: Split into sentences.
        $expr = '/([\n,!;?\.]+)/';
        break;
      case 2:
        // Level 2: Split into words.
        $expr = '/(\s+)/';
        break;
      case 3:
        // Level 3: Split into characters.
        return phutil_utf8v_combined($corpus);
    }

    $pieces = preg_split($expr, $corpus, -1, PREG_SPLIT_DELIM_CAPTURE);
    return $this->stitchPieces($pieces);
  }

  private function stitchPieces(array $pieces) {
    $results = array();
    $count = count($pieces);
    for ($ii = 0; $ii < $count; $ii += 2) {
      $result = $pieces[$ii];
      if ($ii + 1 < $count) {
        $result .= $pieces[$ii + 1];
      }
      $results[] = $result;
    }

    // If the input ended with a delimiter, we can get an empty final piece.
    // Just discard it.
    if (last($results) == '') {
      array_pop($results);
    }

    return $results;
  }

}
