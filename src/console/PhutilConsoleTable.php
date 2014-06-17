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
final class PhutilConsoleTable extends Phobject {

  private $columns = array();
  private $data    = array();
  private $widths  = array();
  private $borders = false;
  private $padding = 1;
  private $showHeader = true;
  private $console;

  const ALIGN_LEFT    = 'left';
  const ALIGN_CENTER  = 'center';
  const ALIGN_RIGHT   = 'right';


/* -(  Console  )------------------------------------------------------------ */

  protected function getConsole() {
    if ($this->console) {
      return $this->console;
    }
    return PhutilConsole::getConsole();
  }

  public function setConsole(PhutilConsole $console) {
    $this->console = $console;
    return $this;
  }


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

  public function draw() {
    $console = $this->getConsole();

    $console->writeOut('%s', $this->getHeader());
    $console->writeOut('%s', $this->getBody());
    $console->writeOut('%s', $this->getFooter());
  }

  private function getHeader() {
    $output = '';

    if ($this->borders) {
      $output .= $this->formatSeparator('=');
    }

    if (!$this->showHeader) {
      return $output;
    }

    $columns = array();
    foreach ($this->columns as $key => $column) {
      $columns[] = PhutilConsoleFormatter::formatString(
        '**%s**',
        $this->alignString(
          $column['title'],
          $this->getWidth($key),
          idx($column, 'align', self::ALIGN_LEFT)));
    }

    $output .= $this->formatRow($columns);

    if ($this->borders) {
      $output .= $this->formatSeparator('=');
    }

    return $output;
  }

  private function getBody() {
    $output = '';

    foreach ($this->data as $data) {
      $columns = array();

      foreach ($this->columns as $key => $column) {
        $columns[] = $this->alignString(
          (string)idx($data, $key, ''),
          $this->getWidth($key),
          idx($column, 'align', self::ALIGN_LEFT));
      }

      $output .= $this->formatRow($columns);
    }

    return $output;
  }

  private function getFooter() {
    $output = '';

    if ($this->borders) {
      $columns = array();

      foreach ($this->getColumns() as $column) {
        $columns[] = str_repeat('=', $this->getWidth($column));
      }

      $output .= '+'.implode('+', $columns)."+\n";
    }

    return $output;
  }


/* -(  Internals  )---------------------------------------------------------- */

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

    return $left_padding.$string.$right_padding;
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
      return '|'.$padding.implode($separator, $columns).$padding."|\n";
    } else {
      return implode($padding, $columns)."\n";
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

    return $separator.implode($separator, $columns).$separator."\n";
  }

}
