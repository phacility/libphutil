<?php

/**
 * Abstraction for processing large inputs without holding them in memory. This
 * class implements line-oriented, buffered reads of some external stream, where
 * a "line" is characterized by some delimiter character. This provides a
 * straightforward interface for most large-input tasks, with relatively good
 * performance.
 *
 * If your stream is not large, it is generally more efficient (and certainly
 * simpler) to read the entire stream first and then process it (e.g., with
 * `explode()`).
 *
 * This class is abstract. The concrete implementations available are:
 *
 *   - @{class:LinesOfALargeFile}, for reading large files; and
 *   - @{class:LinesOfALargeExecFuture}, for reading large output from
 *     subprocesses.
 *
 * For example:
 *
 *   foreach (new LinesOfALargeFile('/path/to/file.log') as $line) {
 *     // ...
 *   }
 *
 * By default, a line is delimited by "\n". The delimiting character is
 * not returned. You can change the character with @{method:setDelimiter}. The
 * last part of the file is returned as the last $line, even if it does not
 * include a terminating character (if it does, the terminating character is
 * stripped).
 *
 * @task  config    Configuration
 * @task  internals Internals
 * @task  iterator  Iterator Interface
 */
abstract class LinesOfALarge extends Phobject implements Iterator {

  private $pos;
  private $buf;
  private $num;
  private $line;
  private $valid;
  private $eof;

  private $delimiter = "\n";


/* -(  Configuration  )------------------------------------------------------ */


  /**
   * Change the "line" delimiter character, which defaults to "\n". This is
   * used to determine where each line ends.
   *
   * If you pass `null`, data will be read from source as it becomes available,
   * without looking for delimiters. You can use this to stream a large file or
   * the output of a command which returns a large amount of data.
   *
   * @param string|null A one-byte delimiter character.
   * @return this
   * @task config
   */
  final public function setDelimiter($character) {
    if (($character !== null) && (strlen($character) !== 1)) {
      throw new Exception(
        pht('Delimiter character must be one byte in length or null.'));
    }
    $this->delimiter = $character;
    return $this;
  }


/* -(  Internals  )---------------------------------------------------------- */


  /**
   * Hook, called before @{method:rewind()}. Allows a concrete implementation
   * to open resources or reset state.
   *
   * @return void
   * @task internals
   */
  abstract protected function willRewind();


  /**
   * Called when the iterator needs more data. The subclass should return more
   * data, or empty string to indicate end-of-stream.
   *
   * @return string Data, or empty string for end-of-stream.
   * @task internals
   */
  abstract protected function readMore();


/* -(  Iterator Interface  )------------------------------------------------- */


  /**
   * @task iterator
   */
  final public function rewind() {
    $this->willRewind();

    $this->buf = '';
    $this->pos = 0;
    $this->num = 0;
    $this->eof = false;
    $this->valid = true;

    $this->next();
  }


  /**
   * @task iterator
   */
  final public function key() {
    return $this->num;
  }


  /**
   * @task iterator
   */
  final public function current() {
    return $this->line;
  }


  /**
   * @task iterator
   */
  final public function valid() {
    return $this->valid;
  }


  /**
   * @task iterator
   */
  final public function next() {
    // Consume the stream a chunk at a time into an internal buffer, then
    // read lines out of that buffer. This gives us flexibility (stream sources
    // only need to be able to read blocks of bytes) and performance (we can
    // read in reasonably-sized chunks of many lines), at the cost of some
    // complexity in buffer management.

    // We do this in a loop to avoid recursion when consuming more bytes, in
    // case the size of a line is very large compared to the chunk size we
    // read.
    while (true) {
      if (strlen($this->buf)) {

        // If we don't have a delimiter, return the entire buffer.
        if ($this->delimiter === null) {
          $this->num++;
          $this->line = substr($this->buf, $this->pos);
          $this->buf = '';
          $this->pos = 0;
          return;
        }

        // If we already have some data buffered, try to get the next line from
        // the buffer. Search through the buffer for a delimiter. This should be
        // the common case.
        $endl = strpos($this->buf, $this->delimiter, $this->pos);

        if ($endl !== false) {
          // We found a delimiter, so return the line it delimits. We leave
          // the buffer as-is so we don't need to reallocate it, in case it is
          // large relative to the size of a line. Instead, we move our cursor
          // within the buffer forward.
          $this->num++;
          $this->line = substr($this->buf, $this->pos, ($endl - $this->pos));
          $this->pos = $endl + 1;
          return;
        }

        // We only have part of a line left in the buffer (no delimiter in the
        // remaining piece), so throw away the part we've already emitted and
        // continue below.
        $this->buf = substr($this->buf, $this->pos);
        $this->pos = 0;
      }

      // We weren't able to produce the next line from the bytes we already had
      // buffered, so read more bytes from the input stream.

      if ($this->eof) {
        // NOTE: We keep track of EOF (an empty read) so we don't make any more
        // reads afterward. Normally, we'll return from the first EOF read,
        // emit the line, and then next() will be called again. Without tracking
        // EOF, we'll attempt another read. A well-behaved implementation should
        // still return empty string, but we can protect against any issues
        // here by keeping a flag.
        $more = '';
      } else {
        $more = $this->readMore();
      }

      if (strlen($more)) {
        // We got some bytes, so add them to the buffer and then try again.
        $this->buf .= $more;
        continue;
      } else {
        // No more bytes. If we have a buffer, return its contents. We
        // potentially return part of a line here if the last line had no
        // delimiter, but that currently seems reasonable as a default
        // behavior. If we don't have a buffer, we're done.
        $this->eof = true;
        if (strlen($this->buf)) {
          $this->num++;
          $this->line = $this->buf;
          $this->buf = null;
        } else {
          $this->valid = false;
        }
        break;
      }
    }
  }

}
