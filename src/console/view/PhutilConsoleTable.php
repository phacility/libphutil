<?php

/**
 * Show a table in the console. Usage:
 *
 *   $table = id(new PhutilConsoleTable())
 *     ->addColumn('id', array('title' => 'ID', 'align' => 'right'))
 *     ->addColumn('name', array('title' => 'Username', 'align' => 'center'))
 *     ->addColumn('email', array('title' => 'Email Address'))
 *
 *     ->addRow(array(
 *       'id'    => 12345,
 *       'name'  => 'alicoln',
 *       'email' => 'abraham@lincoln.com',
 *     ))
 *     ->addRow(array(
 *       'id'    => 99999999,
 *       'name'  => 'jbloggs',
 *       'email' => 'joe@bloggs.com',
 *     ))
 *
 *     ->setBorders(true)
 *     ->draw();
 */
final class PhutilConsoleTable extends PhutilConsoleView {

  private $columns = array();
  private $data    = array();
  private $widths  = array();
  private $borders = false;
  private $padding = 1;
  private $showHeader = true;

  const ALIGN_LEFT    = 'left';
  const ALIGN_CENTER  = 'center';
  const ALIGN_RIGHT   = 'right';


/* -(  Configuration  )------------------------------------------------------ */


  public function setBorders($borders) {
    $this->borders = $borders;
    return $this;
  }

  public function setPadding($padding) {
    $this->padding = $padding;
    return $this;
  }

  public function setShowHeader($show_header) {
    $this->showHeader = $show_header;
    return $this;
  }


/* -(  Data  )--------------------------------------------------------------- */

  public function addColumn($key, array $column) {
    PhutilTypeSpec::checkMap($column, array(
      'title' => 'string',
      'align' => 'optional string',
    ));
    $this->columns[$key] = $column;
    return $this;
  }

  public function addColumns(array $columns) {
    foreach ($columns as $key => $column) {
      $this->addColumn($key, $column);
    }
    return $this;
  }

  public function addRow(array $data) {
    $this->data[] = $data;

    foreach ($data as $key => $value) {
      $this->widths[$key] = max(
        idx($this->widths, $key, 0),
        phutil_utf8_console_strlen($value));
    }

    return $this;
  }


/* -(  Drawing  )------------------------------------------------------------ */

  protected function drawView() {
    return $this->drawLines(
      array_merge(
        $this->getHeader(),
        $this->getBody(),
        $this->getFooter()));
  }

  private function getHeader() {
    $output = array();

    if ($this->borders) {
      $output[] = $this->formatSeparator('=');
    }

    if (!$this->showHeader) {
      return $output;
    }

    $columns = array();
    foreach ($this->columns as $key => $column) {
      $title = tsprintf('**%s**', $column['title']);

      if ($this->shouldAddSpacing($key, $column)) {
        $title = $this->alignString(
          $title,
          $this->getWidth($key),
          idx($column, 'align', self::ALIGN_LEFT));
      }

      $columns[] = $title;
    }

    $output[] = $this->formatRow($columns);

    if ($this->borders) {
      $output[] = $this->formatSeparator('=');
    }

    return $output;
  }

  private function getBody() {
    $output = array();

    foreach ($this->data as $data) {
      $columns = array();

      foreach ($this->columns as $key => $column) {
        if (!$this->shouldAddSpacing($key, $column)) {
          $columns[] = idx($data, $key, '');
        } else {
          $columns[] = $this->alignString(
            idx($data, $key, ''),
            $this->getWidth($key),
            idx($column, 'align', self::ALIGN_LEFT));
        }
      }

      $output[] = $this->formatRow($columns);
    }

    return $output;
  }

  private function getFooter() {
    $output = array();

    if ($this->borders) {
      $columns = array();

      foreach ($this->getColumns() as $column) {
        $columns[] = str_repeat('=', $this->getWidth($column));
      }

      $output[] = array(
        '+',
        $this->implode('+', $columns),
        '+',
      );
    }

    return $output;
  }


/* -(  Internals  )---------------------------------------------------------- */

  /**
   * Returns if the specified column should have spacing added.
   *
   * @return bool
   */
  private function shouldAddSpacing($key, $column) {
    if (!$this->borders) {
      if (last_key($this->columns) === $key) {
        if (idx($column, 'align', self::ALIGN_LEFT) === self::ALIGN_LEFT) {
          // Don't add extra spaces to this column since it's the last column,
          // left aligned, and we're not showing borders.  This prevents
          // unnecessary empty lines from appearing when the extra spaces
          // wrap around the terminal.
          return false;
        }
      }
    }

    return true;
  }

  /**
   * Returns the column IDs.
   *
   * @return list<string>
   */
  protected function getColumns() {
    return array_keys($this->columns);
  }

  /**
   * Get the width of a specific column, including padding.
   *
   * @param  string
   * @return int
   */
  protected function getWidth($key) {
    $width = max(
      idx($this->widths, $key),
      phutil_utf8_console_strlen(
        idx(idx($this->columns, $key, array()), 'title', '')));

    return $width + 2 * $this->padding;
  }

  protected function alignString($string, $width, $align) {
    $num_padding = $width -
      (2 * $this->padding) - phutil_utf8_console_strlen($string);

    switch ($align) {
      case self::ALIGN_LEFT:
        $num_left_padding  = 0;
        $num_right_padding = $num_padding;
        break;

      case self::ALIGN_CENTER:
        $num_left_padding  = (int)($num_padding / 2);
        $num_right_padding = $num_padding - $num_left_padding;
        break;

      case self::ALIGN_RIGHT:
        $num_left_padding  = $num_padding;
        $num_right_padding = 0;
        break;
    }

    $left_padding  = str_repeat(' ', $num_left_padding);
    $right_padding = str_repeat(' ', $num_right_padding);

    return array(
      $left_padding,
      $string,
      $right_padding,
    );
  }

  /**
   * Format cells into an entire row.
   *
   * @param  list<string>
   * @return string
   */
  protected function formatRow(array $columns) {
    $padding = str_repeat(' ', $this->padding);

    if ($this->borders) {
      $separator = $padding.'|'.$padding;
      return array(
        '|'.$padding,
        $this->implode($separator, $columns),
        $padding.'|',
      );
    } else {
      return $this->implode($padding, $columns);
    }
  }

  protected function formatSeparator($string) {
    $columns = array();

    if ($this->borders) {
      $separator = '+';
    } else {
      $separator = '';
    }

    foreach ($this->getColumns() as $column) {
      $columns[] = str_repeat($string, $this->getWidth($column));
    }

    return array(
      $separator,
      $this->implode($separator, $columns),
      $separator,
    );
  }

}
