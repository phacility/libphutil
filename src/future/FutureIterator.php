<?php

/**
 * FutureIterator aggregates @{class:Future}s and allows you to respond to them
 * in the order they resolve. This is useful because it minimizes the amount of
 * time your program spends waiting on parallel processes.
 *
 *   $futures = array(
 *     'a.txt' => new ExecFuture('wc -c a.txt'),
 *     'b.txt' => new ExecFuture('wc -c b.txt'),
 *     'c.txt' => new ExecFuture('wc -c c.txt'),
 *   );
 *
 *   foreach (new FutureIterator($futures) as $key => $future) {
 *     // IMPORTANT: keys are preserved but the order of elements is not. This
 *     // construct iterates over the futures in the order they resolve, so the
 *     // fastest future is the one you'll get first. This allows you to start
 *     // doing followup processing as soon as possible.
 *
 *     list($err, $stdout) = $future->resolve();
 *     do_some_processing($stdout);
 *   }
 *
 * For a general overview of futures, see @{article:Using Futures}.
 *
 * @task  basics    Basics
 * @task  config    Configuring Iteration
 * @task  iterator  Iterator Interface
 * @task  internal  Internals
 */
final class FutureIterator extends Phobject implements Iterator {

  protected $wait     = array();
  protected $work     = array();
  protected $futures  = array();
  protected $key;

  protected $limit;

  protected $timeout;
  protected $isTimeout = false;


/* -(  Basics  )------------------------------------------------------------- */


  /**
   * Create a new iterator over a list of futures.
   *
   * @param list  List of @{class:Future}s to resolve.
   * @task basics
   */
  public function __construct(array $futures) {
    assert_instances_of($futures, 'Future');
    $this->futures = $futures;
  }


  /**
   * Block until all futures resolve.
   *
   * @return void
   * @task basics
   */
  public function resolveAll() {
    foreach ($this as $future) {
      $future->resolve();
    }
  }

  /**
   * Add another future to the set of futures. This is useful if you have a
   * set of futures to run mostly in parallel, but some futures depend on
   * others.
   *
   * @param Future  @{class:Future} to add to iterator
   * @task basics
   */
  public function addFuture(Future $future, $key = null) {
    if ($key === null) {
      $this->futures[] = $future;
      $this->wait[] = last_key($this->futures);
    } else if (!isset($this->futures[$key])) {
      $this->futures[$key] = $future;
      $this->wait[] = $key;
    } else {
      throw new Exception(pht('Invalid key %s', $key));
    }

    // Start running the future if we don't have $this->limit futures running
    // already. updateWorkingSet() won't start running the future if there's no
    // limit, so we'll manually poke it here in that case.
    $this->updateWorkingSet();
    if (!$this->limit) {
      $future->isReady();
    }
    return $this;
  }


/* -(  Configuring Iteration  )---------------------------------------------- */


  /**
   * Set a maximum amount of time you want to wait before the iterator will
   * yield a result. If no future has resolved yet, the iterator will yield
   * null for key and value. Among other potential uses, you can use this to
   * show some busy indicator:
   *
   *   $futures = id(new FutureIterator($futures))
   *     ->setUpdateInterval(1);
   *   foreach ($futures as $future) {
   *     if ($future === null) {
   *       echo "Still working...\n";
   *     } else {
   *       // ...
   *     }
   *   }
   *
   * This will echo "Still working..." once per second as long as futures are
   * resolving. By default, FutureIterator never yields null.
   *
   * @param float Maximum number of seconds to block waiting on futures before
   *              yielding null.
   * @return this
   *
   * @task config
   */
  public function setUpdateInterval($interval) {
    $this->timeout = $interval;
    return $this;
  }


  /**
   * Limit the number of simultaneously executing futures.
   *
   *  $futures = id(new FutureIterator($futures))
   *    ->limit(4);
   *  foreach ($futures as $future) {
   *    // Run no more than 4 futures simultaneously.
   *  }
   *
   * @param int Maximum number of simultaneous jobs allowed.
   * @return this
   *
   * @task config
   */
  public function limit($max) {
    $this->limit = $max;
    return $this;
  }


/* -(  Iterator Interface  )------------------------------------------------- */


  /**
   * @task iterator
   */
  public function rewind() {
    $this->wait = array_keys($this->futures);
    $this->work = null;
    $this->updateWorkingSet();
    $this->next();
  }

  /**
   * @task iterator
   */
  public function next() {
    $this->key = null;
    if (!count($this->wait)) {
      return;
    }

    $read_sockets = array();
    $write_sockets = array();

    $start = microtime(true);
    $timeout = $this->timeout;
    $this->isTimeout = false;

    $check = $this->getWorkingSet();
    $resolve = null;
    do {
      $read_sockets    = array();
      $write_sockets   = array();
      $can_use_sockets = true;
      $wait_time       = 1;
      foreach ($check as $wait => $key) {
        $future = $this->futures[$key];
        try {
          if ($future->getException()) {
            $resolve = $wait;
            continue;
          }
          if ($future->isReady()) {
            if ($resolve === null) {
              $resolve = $wait;
            }
            continue;
          }

          $got_sockets = false;
          $socks = $future->getReadSockets();
          if ($socks) {
            $got_sockets = true;
            foreach ($socks as $socket) {
              $read_sockets[] = $socket;
            }
          }

          $socks = $future->getWriteSockets();
          if ($socks) {
            $got_sockets = true;
            foreach ($socks as $socket) {
              $write_sockets[] = $socket;
            }
          }

          // If any currently active future had neither read nor write sockets,
          // we can't wait for the current batch of items using sockets.
          if (!$got_sockets) {
            $can_use_sockets = false;
          } else {
            $wait_time = min($wait_time, $future->getDefaultWait());
          }
        } catch (Exception $ex) {
          $this->futures[$key]->setException($ex);
          $resolve = $wait;
          break;
        }
      }
      if ($resolve === null) {

        // Check for a setUpdateInterval() timeout.
        if ($timeout !== null) {
          $elapsed = microtime(true) - $start;
          if ($elapsed > $timeout) {
            $this->isTimeout = true;
            return;
          } else {
            $wait_time = $timeout - $elapsed;
          }
        }

        if ($can_use_sockets) {
          Future::waitForSockets($read_sockets, $write_sockets, $wait_time);
        } else {
          usleep(1000);
        }
      }
    } while ($resolve === null);

    $this->key = $this->wait[$resolve];
    unset($this->wait[$resolve]);
    $this->updateWorkingSet();
  }

  /**
   * @task iterator
   */
  public function current() {
    if ($this->isTimeout) {
      return null;
    }
    return $this->futures[$this->key];
  }

  /**
   * @task iterator
   */
  public function key() {
    if ($this->isTimeout) {
      return null;
    }
    return $this->key;
  }

  /**
   * @task iterator
   */
  public function valid() {
    if ($this->isTimeout) {
      return true;
    }
    return ($this->key !== null);
  }


/* -(  Internals  )---------------------------------------------------------- */


  /**
   * @task internal
   */
  protected function getWorkingSet() {
    if ($this->work === null) {
      return $this->wait;
    }

    return $this->work;
  }

  /**
   * @task internal
   */
  protected function updateWorkingSet() {
    if (!$this->limit) {
      return;
    }

    $old = $this->work;
    $this->work = array_slice($this->wait, 0, $this->limit, true);

    //  If we're using a limit, our futures are sleeping and need to be polled
    //  to begin execution, so poll any futures which weren't in our working set
    //  before.
    foreach ($this->work as $work => $key) {
      if (!isset($old[$work])) {
        $this->futures[$key]->isReady();
      }
    }
  }

}
