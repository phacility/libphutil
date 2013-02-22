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
 */
final class PhutilEditDistanceMatrix {

  private $insertCost    = 1;
  private $deleteCost    = 1;
  private $replaceCost   = 1;
  private $transposeCost = null;
  private $computeString;

  private $distanceMatrix = null;
  private $typeMatrix = null;

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

  public function setSequences(array $x, array $y) {
    $this->x = array_values($x);
    $this->y = array_values($y);
    $this->distanceMatrix = null;
    return $this;
  }

  private function requireSequences() {
    if ($this->x === null) {
      throw new Exception(
        "Call setSequences() before performing useful work!");
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
      return '';
    }

    if (!$x) {
      return str_repeat('i', count($y));
    }

    if (!$y) {
      return str_repeat('d', count($x));
    }

    if ($x === $y) {
      return str_repeat('s', count($x));
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
        throw new Exception("Unknown type '{$type}' in type matrix.");
      }

      $str .= $chr;

      if ($xx <= 0 && $yy <= 0) {
        break;
      }
    }

    return strrev($str);
  }

  private function getTypeMatrix() {
    if (!$this->computeString) {
      throw new Exception(
        "Call setComputeString() before getTypeMatrix().");
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
          // If the two positions are the same, we have no edit and thus no
          // cost.
          $cost = $m[$xx - 1][$yy - 1];
          $last_dy = $yy - 1;
          $type = 's';
        } else {
          $del_cost = $m[$xx - 1][$yy    ] + $this->deleteCost;
          $ins_cost = $m[$xx    ][$yy - 1] + $this->insertCost;
          $rep_cost = $m[$xx - 1][$yy - 1] + $this->replaceCost;

          if ($rep_cost <= $del_cost && $rep_cost <= $ins_cost) {
            $cost = $rep_cost;
            $type = 'x';
          } else if ($ins_cost <= $del_cost) {
            $cost = $ins_cost;
            $type = 'i';
          } else {
            $cost = $del_cost;
            $type = 'd';
          }

          if ($use_types) {
            // If we can reach a position in two different ways that cost the
            // same amount (for example, through "R" or through "D"), stick with
            // the same type we used previously.
            $del_type = $t[$xx - 1][$yy    ];
            $ins_type = $t[$xx    ][$yy - 1];

            if ($del_type == 'd' && $del_cost == $cost) {
              $type = 'd';
            } else if ($ins_type == 'i' && $ins_cost == $cost) {
              $type = 'i';
            }
          }
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

    $p = '% 5s ';
    printf($p, ' ');
    foreach (head($m) as $yk => $yv) {
      printf($p, idx($x, $yk - 1, '-'));
    }
    echo "\n";
    foreach ($m as $xk => $xv) {
      printf($p, idx($y, $xk - 1, '-'));
      foreach ($xv as $yk => $yv) {
        printf($p, ($yv == $this->getInfinity() ? 'inf' : $yv));
      }
      echo "\n";
    }
  }

}
