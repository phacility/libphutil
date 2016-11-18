<?php

/**
 * Compute edit distance between two scalar sequences. This class uses
 * Levenshtein (or Damerau-Levenshtein) to compute the edit distance between
 * two inputs. The inputs are arrays containing any scalars (not just strings)
 * so it can be used with, e.g., utf8 sequences.
 *
 *  $matrix = id(new PhutilEditDistanceMatrix())
 *    ->setSequences(str_split('ran'), str_split('rat'));
 *
 *  $cost = $matrix->getEditDistance();
 *
 * Edit distance computation is slow and requires a large amount of memory;
 * both are roughly O(N * M) in the length of the strings.
 *
 * You can customize the cost of insertions, deletions and replacements. By
 * default, each has a cost of 1.
 *
 *   $matrix->setReplaceCost(1);
 *
 * By default, transpositions are not evaluated (i.e., the algorithm is
 * Levenshtein). You can cause transpositions to be evaluated by setting a
 * transpose cost (which will change the algorithm to Damerau-Levenshtein):
 *
 *   $matrix->setTransposeCost(1);
 *
 * You can also provide a cost to alter the type of operation being applied.
 * Many strings have several equivalently expensive edit sequences, but one
 * some sequences are more readable to humans than others. Providing a small
 * cost to alter operation type tends to smooth out the sequence and produce
 * long runs of a single operation, which are generally more readable. For
 * example, these strings:
 *
 *   (x)
 *   ((x))
 *
 * ...have edit strings "issis" and "isssi", which describe edit operations with
 * the same cost, but the latter string is more comprehensible to human viewers.
 *
 * If you set an alter cost, you must call @{method:setComputeString} to enable
 * type computation. The alter cost should generally be smaller than `c / N`,
 * where `c` is the smallest operational cost and `N` is the length of the
 * longest string. For example, if you are using the default costs (insert = 1,
 * delete = 1, replace = 1) and computing edit distances for strings of fewer
 * than 1,000 characters, you might set the alter cost to 0.001.
 */
final class PhutilEditDistanceMatrix extends Phobject {

  private $insertCost    = 1;
  private $deleteCost    = 1;
  private $replaceCost   = 1;
  private $transposeCost = null;
  private $alterCost     = 0;
  private $maximumLength;
  private $computeString;
  private $applySmoothing = self::SMOOTHING_NONE;
  private $reachedMaximumLength;

  private $x;
  private $y;
  private $prefix;
  private $suffix;

  private $distanceMatrix = null;
  private $typeMatrix = null;

  const SMOOTHING_NONE = 'none';
  const SMOOTHING_INTERNAL = 'internal';
  const SMOOTHING_FULL = 'full';

  public function setMaximumLength($maximum_length) {
    $this->maximumLength = $maximum_length;
    return $this;
  }

  public function getMaximumLength() {
    return coalesce($this->maximumLength, $this->getInfinity());
  }

  public function didReachMaximumLength() {
    return $this->reachedMaximumLength;
  }

  public function setComputeString($compute_string) {
    $this->computeString = $compute_string;
    return $this;
  }

  public function getComputeString() {
    return $this->computeString;
  }

  public function setTransposeCost($transpose_cost) {
    $this->transposeCost = $transpose_cost;
    return $this;
  }

  public function getTransposeCost() {
    return $this->transposeCost;
  }

  public function setReplaceCost($replace_cost) {
    $this->replaceCost = $replace_cost;
    return $this;
  }

  public function getReplaceCost() {
    return $this->replaceCost;
  }

  public function setDeleteCost($delete_cost) {
    $this->deleteCost = $delete_cost;
    return $this;
  }

  public function getDeleteCost() {
    return $this->deleteCost;
  }

  public function setInsertCost($insert_cost) {
    $this->insertCost = $insert_cost;
    return $this;
  }

  public function getInsertCost() {
    return $this->insertCost;
  }

  public function setAlterCost($alter_cost) {
    $this->alterCost = $alter_cost;
    return $this;
  }

  public function getAlterCost() {
    return $this->alterCost;
  }

  public function setApplySmoothing($apply_smoothing) {
    $this->applySmoothing = $apply_smoothing;
    return $this;
  }

  public function getApplySmoothing() {
    return $this->applySmoothing;
  }

  public function setSequences(array $x, array $y) {

    // NOTE: We strip common prefixes and suffixes from the inputs because
    // the runtime of the edit distance algorithm is large and it is common
    // to diff similar strings.

    $xl = count($x);
    $yl = count($y);
    $l = min($xl, $yl);

    $prefix_l = 0;
    $suffix_l = 0;

    for ($ii = 0; $ii < $l; $ii++) {
      if ($x[$ii] !== $y[$ii]) {
        break;
      }
      $prefix_l++;
    }

    for ($ii = 1; $ii <= ($l - $prefix_l); $ii++) {
      if ($x[$xl - $ii] !== $y[$yl - $ii]) {
        break;
      }
      $suffix_l++;
    }

    $this->prefix = array_slice($x, 0, $prefix_l);
    $this->suffix = array_slice($x, $xl - $suffix_l);

    $this->x = array_slice($x, $prefix_l, $xl - ($suffix_l + $prefix_l));
    $this->y = array_slice($y, $prefix_l, $yl - ($suffix_l + $prefix_l));
    $this->distanceMatrix = null;

    return $this;
  }

  private function requireSequences() {
    if ($this->x === null) {
      throw new PhutilInvalidStateException('setSequences');
    }
  }

  public function getEditDistance() {
    $this->requireSequences();

    $x = $this->x;
    $y = $this->y;

    if (!$x) {
      return $this->insertCost * count($y);
    }

    if (!$y) {
      return $this->deleteCost * count($x);
    }

    $max = $this->getMaximumLength();
    if (count($x) > $max || count($y) > $max) {
      $this->reachedMaximumLength = true;
      return ($this->insertCost * count($y)) + ($this->deleteCost * count($x));
    }

    if ($x === $y) {
      return 0;
    }

    $matrix = $this->getDistanceMatrix();

    return $matrix[count($x)][count($y)];
  }

  /**
   * Return a string representing the edits between the sequences. The string
   * has these characters:
   *
   *   - s (same): Same character in both strings.
   *   - i (insert): Character inserted.
   *   - d (delete): Character deleted.
   *   - x (replace): Character replaced.
   *   - t (transpose): Character transposed.
   */
  public function getEditString() {
    $this->requireSequences();

    $x = $this->x;
    $y = $this->y;

    if (!$x && !$y) {
      return $this->padEditString('');
    }

    if (!$x) {
      return $this->padEditString(str_repeat('i', count($y)));
    }

    if (!$y) {
      return $this->padEditString(str_repeat('d', count($x)));
    }

    if ($x === $y) {
      return $this->padEditString(str_repeat('s', count($x)));
    }

    $max = $this->getMaximumLength();
    if (count($x) > $max || count($y) > $max) {
      $this->reachedMaximumLength = true;
      return $this->padEditString(
        str_repeat('d', count($x)).
        str_repeat('i', count($y)));
    }

    $matrix = $this->getTypeMatrix();

    $xx = count($x);
    $yy = count($y);

    $transposes = array();
    $str = '';
    while (true) {
      $type = $matrix[$xx][$yy];

      if (is_array($type)) {
        $chr = 't';
        $transposes[$type[0]][$type[1]] = true;
        $type = $type[2];
      } else {
        $chr = $type;
      }

      if (isset($transposes[$xx][$yy])) {
        $chr = 't';
      }

      if ($type == 's' || $type == 'x') {
        $xx -= 1;
        $yy -= 1;
      } else if ($type == 'i') {
        $yy -= 1;
      } else if ($type == 'd') {
        $xx -= 1;
      } else {
        throw new Exception(pht("Unknown type '%s' in type matrix.", $type));
      }

      $str .= $chr;

      if ($xx <= 0 && $yy <= 0) {
        break;
      }
    }

    $str = strrev($str);

    // For full smoothing, we pad the edit string before smoothing it, so
    // ranges of similar characters at the beginning or end of the string can
    // also be smoothed.

    // For internal smoothing, we only smooth ranges within the change itself.

    $smoothing = $this->getApplySmoothing();
    switch ($smoothing) {
      case self::SMOOTHING_FULL:
        $str = $this->padEditString($str);
        $str = $this->applySmoothing($str, true);
        break;
      case self::SMOOTHING_INTERNAL:
        $str = $this->applySmoothing($str, false);
        $str = $this->padEditString($str);
        break;
      case self::SMOOTHING_NONE:
        $str = $this->padEditString($str);
        break;
      default:
        throw new Exception(
          pht(
            'Unknown smoothing type "%s".',
            $smoothing));
    }

    return $str;
  }

  private function padEditString($str) {
    if ($this->prefix) {
      $str = str_repeat('s', count($this->prefix)).$str;
    }
    if ($this->suffix) {
      $str = $str.str_repeat('s', count($this->suffix));
    }
    return $str;
  }

  private function getTypeMatrix() {
    if (!$this->computeString) {
      throw new PhutilInvalidStateException('setComputeString');
    }
    if ($this->typeMatrix === null) {
      $this->computeMatrix($this->x, $this->y);
    }
    return $this->typeMatrix;
  }

  private function getDistanceMatrix() {
    if ($this->distanceMatrix === null) {
      $this->computeMatrix($this->x, $this->y);
    }
    return $this->distanceMatrix;
  }

  private function computeMatrix(array $x, array $y) {
    $xl = count($x);
    $yl = count($y);

    $m = array();

    $infinity = $this->getInfinity();

    $use_damerau = ($this->transposeCost !== null);
    if ($use_damerau) {
      // Initialize the default cost of a transpose.
      $m[-1][-1] = $infinity;

      // Initialize the character position dictionary for Damerau.
      $d = array();
      foreach ($x as $c) {
        $d[$c] = -1;
      }
      foreach ($y as $c) {
        $d[$c] = -1;
      }

      // Initialize the transpose costs for Damerau.
      for ($xx = 0; $xx <= $xl; $xx++) {
        $m[$xx][-1] = $infinity;
      }

      for ($yy = 0; $yy <= $yl; $yy++) {
        $m[-1][$yy] = $infinity;
      }
    }

    // Initialize the top row of the matrix.
    for ($xx = 0; $xx <= $xl; $xx++) {
      $m[$xx][0] = $xx * $this->deleteCost;
    }

    // Initialize the left column of the matrix.
    $cost = 0;
    for ($yy = 0; $yy <= $yl; $yy++) {
      $m[0][$yy] = $yy * $this->insertCost;
    }

    $use_types = ($this->computeString);
    if ($use_types) {
      $t = array();
      for ($xx = 0; $xx <= $xl; $xx++) {
        $t[$xx][0] = 'd';
      }
      for ($yy = 0; $yy <= $yl; $yy++) {
        $t[0][$yy] = 'i';
      }
      $t[0][0] = 's';
    }

    $alt_cost = $this->getAlterCost();
    if ($alt_cost && !$use_types) {
      throw new Exception(
        pht(
          'If you provide an alter cost with %s, you must enable '.
          'type computation with %s.',
          'setAlterCost()',
          'setComputeStrings()'));
    }

    // Build the edit distance matrix.
    for ($xx = 1; $xx <= $xl; $xx++) {
      $last_dy = -1;
      for ($yy = 1; $yy <= $yl; $yy++) {
        if ($use_damerau) {
          $dx = $d[$y[$yy - 1]];
          $dy = $last_dy;
        }

        if ($x[$xx - 1] === $y[$yy - 1]) {
          $rep_cost = $m[$xx - 1][$yy - 1] + 0;
          $rep_type = 's';
        } else {
          $rep_cost = $m[$xx - 1][$yy - 1] + $this->replaceCost;
          $rep_type = 'x';
        }

        $del_cost = $m[$xx - 1][$yy    ] + $this->deleteCost;
        $ins_cost = $m[$xx    ][$yy - 1] + $this->insertCost;
        if ($alt_cost) {
          $del_char = $t[$xx - 1][$yy    ];
          $ins_char = $t[$xx    ][$yy - 1];
          $rep_char = $t[$xx - 1][$yy - 1];

          if ($del_char !== 'd') {
            $del_cost += $alt_cost;
          }
          if ($ins_char !== 'i') {
            $ins_cost += $alt_cost;
          }
          if ($rep_char !== $rep_type) {
            $rep_cost += $alt_cost;
          }
        }

        if ($rep_cost <= $del_cost && $rep_cost <= $ins_cost) {
          $cost = $rep_cost;
          $type = $rep_type;
          if ($rep_type === 's') {
            $last_dy = $yy - 1;
          }
        } else if ($ins_cost <= $del_cost) {
          $cost = $ins_cost;
          $type = 'i';
        } else {
          $cost = $del_cost;
          $type = 'd';
        }

        if ($use_damerau) {
          $trn_count = (($xx - $dx - 2) + ($yy - $dy - 2) + 1);
          $trn_cost = $m[$dx][$dy] + ($trn_count * $this->transposeCost);
          if ($trn_cost < $cost) {
            $cost = $trn_cost;
            $type = array($dx + 1, $dy + 1, $type);
          }
        }

        $m[$xx][$yy] = $cost;
        if ($use_types) {
          $t[$xx][$yy] = $type;
        }
      }

      if ($use_damerau) {
        $d[$x[$xx - 1]] = ($xx - 1);
      }
    }

    $this->distanceMatrix = $m;
    if ($use_types) {
      $this->typeMatrix = $t;
    }
  }

  private function getInfinity() {
    return INF;
  }

  private function printMatrix(array $m) {
    $x = $this->x;
    $y = $this->y;

    $p = '% 8s ';
    printf($p, ' ');
    foreach (head($m) as $yk => $yv) {
      printf($p, idx($y, $yk - 1, '-'));
    }
    echo "\n";
    foreach ($m as $xk => $xv) {
      printf($p, idx($x, $xk - 1, '-'));
      foreach ($xv as $yk => $yv) {
        printf($p, ($yv == $this->getInfinity() ? 'inf' : $yv));
      }
      echo "\n";
    }
  }

  private function printTypeMatrix(array $t) {
    $x = $this->x;
    $y = $this->y;

    $p = '% 8s ';
    printf($p, ' ');
    foreach (head($t) as $yk => $yv) {
      printf($p, idx($y, $yk - 1, '-'));
    }
    echo "\n";
    foreach ($t as $xk => $xv) {
      printf($p, idx($x, $xk - 1, '-'));
      foreach ($xv as $yk => $yv) {
        printf($p, ($yv == $this->getInfinity() ? 'inf' : $yv));
      }
      echo "\n";
    }
  }

  private function applySmoothing($str, $full) {
    if ($full) {
      $prefix = '(^|[xdi])';
      $suffix = '([xdi]|\z)';
    } else {
      $prefix = '([xdi])';
      $suffix = '([xdi])';
    }

    // Smooth the string out, by replacing short runs of similar characters
    // with 'x' operations. This makes the result more readable to humans,
    // since there are fewer choppy runs of short added and removed substrings.
    do {
      $original = $str;
      $str = preg_replace('/'.$prefix.'(s{3})'.$suffix.'/', '$1xxx$3', $str);
      $str = preg_replace('/'.$prefix.'(s{2})'.$suffix.'/', '$1xx$3', $str);
      $str = preg_replace('/'.$prefix.'(s{1})'.$suffix.'/', '$1x$3', $str);
    } while ($str != $original);

    return $str;
  }

}
