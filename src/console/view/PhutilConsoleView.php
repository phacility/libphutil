<?php

abstract class PhutilConsoleView extends Phobject {

  private $console;

  abstract protected function drawView();

  final public function setConsole(PhutilConsole $console) {
    $this->console = $console;
    return $this;
  }

  final public function getConsole() {
    if ($this->console) {
      return $this->console;
    }
    return PhutilConsole::getConsole();
  }


  /**
   * Draw a view to the console.
   *
   * @return this
   * @task draw
   */
  final public function draw() {
    $string = $this->drawConsoleString();

    $console = $this->getConsole();
    $console->writeOut('%s', $string);

    return $this;
  }


  /**
   * Draw a view to a string and return it.
   *
   * @return string Console-printable string.
   * @task draw
   */
  final public function drawConsoleString() {
    $view = $this->drawView();
    $parts = $this->reduceView($view);

    $out = array();
    foreach ($parts as $part) {
      $out[] = PhutilTerminalString::escapeStringValue($part, true);
    }

    return implode('', $out);
  }


  /**
   * Reduce a view to a list of simple, unnested parts.
   *
   * @param wild Any drawable view.
   * @return list<wild> List of unnested drawables.
   * @task draw
   */
  private function reduceView($view) {
    if ($view instanceof PhutilConsoleView) {
      $view = $view->drawView();
      return $this->reduceView($view);
    }

    if (is_array($view)) {
      $parts = array();
      foreach ($view as $item) {
        foreach ($this->reduceView($item) as $part) {
          $parts[] = $part;
        }
      }
      return $parts;
    }

    return array($view);
  }

/* -(  Drawing Utilities  )-------------------------------------------------- */


  /**
   * @param list<wild> List of views, one per line.
   * @return wild Each view rendered on a separate line.
   */
  final protected function drawLines(array $parts) {
    $result = array();
    foreach ($parts as $part) {
      if ($part !== null) {
        $result[] = $part;
        $result[] = "\n";
      }
    }

    return $result;
  }

  final protected function implode($separator, array $items) {
    $result = array();
    foreach ($items as $item) {
      $result[] = $item;
      $result[] = $separator;
    }
    array_pop($result);
    return $result;
  }

}
