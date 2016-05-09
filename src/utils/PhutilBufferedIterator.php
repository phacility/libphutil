<?php

/**
 * Simple iterator that loads results page-by-page and handles buffering. In
 * particular, this maps well to iterators that load database results page
 * by page and allows you to implement an iterator over a large result set
 * without needing to hold the entire set in memory.
 *
 * For an example implementation, see @{class:PhutilExampleBufferedIterator}.
 *
 * @task impl     Methods to Implement
 * @task config   Configuration
 * @task iterator Iterator Implementation
 */
abstract class PhutilBufferedIterator extends Phobject implements Iterator {

  private $data;
  private $pageSize = 100;
  private $naturalKey;


/* -(  Methods to Implement  )----------------------------------------------- */


  /**
   * Called when @{method:rewind} is invoked. You should reset any internal
   * cursor your implementation holds.
   *
   * @return void
   * @task impl
   */
  abstract protected function didRewind();


  /**
   * Called when the iterator needs a page of results. You should load the next
   * result page and update your internal cursor to point past it.
   *
   * If possible, you should use @{method:getPageSize} to choose a page size.
   *
   * @return list<wild> List of results.
   * @task impl
   */
  abstract protected function loadPage();


/* -(  Configuration  )------------------------------------------------------ */


  /**
   * Get the configured page size.
   *
   * @return int Page size.
   * @task config
   */
  final public function getPageSize() {
    return $this->pageSize;
  }


  /**
   * Configure the page size. Note that implementations may ignore this.
   *
   * @param int Page size.
   * @return this
   * @task config
   */
  final public function setPageSize($size) {
    $this->pageSize = $size;
    return $this;
  }


/* -(  Iterator Implementation  )-------------------------------------------- */


  /**
   * @task iterator
   */
  final public function rewind() {
    $this->didRewind();
    $this->data = array();
    $this->naturalKey = 0;
    $this->next();
  }


  /**
   * @task iterator
   */
  final public function valid() {
    return (bool)count($this->data);
  }


  /**
   * @task iterator
   */
  final public function current() {
    return end($this->data);
  }


  /**
   * By default, the iterator assigns a "natural" key (0, 1, 2, ...) to each
   * result. This method is intentionally nonfinal so you can substitute a
   * different behavior by overriding it if you prefer.
   *
   * @return scalar Key for the current result (as per @{method:current}).
   * @task iterator
   */
  public function key() {
    return $this->naturalKey;
  }


  /**
   * @task iterator
   */
  final public function next() {
    if ($this->data) {
      $this->naturalKey++;
      array_pop($this->data);
      if ($this->data) {
        return;
      }
    }

    $data = $this->loadPage();

    // NOTE: Reverse the results so we can use array_pop() to discard them,
    // since it doesn't have the O(N) key reassignment behavior of
    // array_shift().

    $this->data = array_reverse($data);
  }

}
