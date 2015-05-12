<?php

/**
 * Read the output stream of an @{class:ExecFuture} one line at a time. This
 * abstraction allows you to process large inputs without holding them in
 * memory. If you know your inputs fit in memory, it is generally more efficient
 * (and certainly simpler) to read the entire input and `explode()` it. For
 * more information, see @{class:LinesOfALarge}. See also
 * @{class:LinesOfALargeFile} for a similar abstraction that works on files.
 *
 *   $future = new ExecFuture('hg log ...');
 *   foreach (new LinesOfALargeExecFuture($future) as $line) {
 *     // ...
 *   }
 *
 * If the subprocess exits with an error, a @{class:CommandException} will be
 * thrown.
 *
 * On destruction, this class terminates the subprocess if it has not already
 * exited.
 *
 * @task construct  Construction
 * @task internals  Internals
 */
final class LinesOfALargeExecFuture extends LinesOfALarge {

  private $future;
  private $didRewind;


/* -(  Construction  )------------------------------------------------------- */


  /**
   * To construct, pass an @{class:ExecFuture}.
   *
   * @param ExecFuture Future to wrap.
   * @return void
   * @task construct
   */
  public function __construct(ExecFuture $future) {
    $this->future = $future;
  }


/* -(  Internals  )---------------------------------------------------------- */


  /**
   * On destruction, we terminate the subprocess if it hasn't exited already.
   *
   * @return void
   * @task internals
   */
  public function __destruct() {
    if (!$this->future->isReady()) {
      $this->future->resolveKill();
    }
  }


  /**
   * The PHP `foreach()` construct calls rewind() once, so we allow the first
   * `rewind()`, without effect. Subsequent rewinds mean misuse.
   *
   * @return void
   * @task internals
   */
  protected function willRewind() {
    if ($this->didRewind) {
      throw new Exception(
        pht(
          "You can not reiterate over a %s object. The entire goal of the ".
          "construct is to avoid keeping output in memory. What you are ".
          "attempting to do is silly and doesn't make any sense.",
          __CLASS__));
    }
    $this->didRewind = true;
  }


  /**
   * Read more data from the subprocess.
   *
   * @return string   Bytes read from stdout.
   * @task internals
   */
  protected function readMore() {
    $future = $this->future;

    while (true) {
      // Read is nonblocking, so we need to sit in this loop waiting for input
      // or we'll incorrectly signal EOF to the parent.
      $stdout = $future->readStdout();
      $future->discardStdoutBuffer();

      if (strlen($stdout)) {
        return $stdout;
      }

      // If we didn't read anything, we can exit the loop if the subprocess
      // has exited.

      if ($future->isReady()) {
        // Throw if the process exits with a nonzero status code. This makes
        // error handling simpler, and prevents us from returning part of a line
        // if the process terminates mid-output.
        $future->resolvex();

        // Read and return anything that's left.
        $stdout = $future->readStdout();
        $future->discardStdoutBuffer();

        return $stdout;
      }
    }
  }

}
