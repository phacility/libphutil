<?php

/**
 * Simple wrapper to create a temporary file and guarantee it will be deleted on
 * object destruction. Used like a string to path:
 *
 *    $temp = new TempFile();
 *    Filesystem::writeFile($temp, 'Hello World');
 *    echo "Wrote data to path: ".$temp;
 *
 * Throws Filesystem exceptions for errors.
 *
 * @task  create    Creating a Temporary File
 * @task  config    Configuration
 * @task  internal  Internals
 */
final class TempFile extends Phobject {

  private $dir;
  private $file;
  private $preserve;
  private $destroyed = false;

/* -(  Creating a Temporary File  )------------------------------------------ */


  /**
   * Create a new temporary file.
   *
   * @param string? Filename hint. This is useful if you intend to edit the
   *                file with an interactive editor, so the user's editor shows
   *                "commit-message" instead of "p3810hf-1z9b89bas".
   * @param string? Root directory to hold the file. If omitted, the system
   *                temporary directory (often "/tmp") will be used by default.
   * @task create
   */
  public function __construct($filename = null, $root_directory = null) {
    $this->dir = Filesystem::createTemporaryDirectory(
      '',
      0700,
      $root_directory);
    if ($filename === null) {
      $this->file = tempnam($this->dir, getmypid().'-');
    } else {
      $this->file = $this->dir.'/'.$filename;
    }

    // If we fatal (e.g., call a method on NULL), destructors are not called.
    // Make sure our destructor is invoked.
    register_shutdown_function(array($this, '__destruct'));

    Filesystem::writeFile($this, '');
  }


/* -(  Configuration  )------------------------------------------------------ */


  /**
   * Normally, the file is deleted when this object passes out of scope. You
   * can set it to be preserved instead.
   *
   * @param bool True to preserve the file after object destruction.
   * @return this
   * @task config
   */
  public function setPreserveFile($preserve) {
    $this->preserve = $preserve;
    return $this;
  }


/* -(  Internals  )---------------------------------------------------------- */


  /**
   * Get the path to the temporary file. Normally you can just use the object
   * in a string context.
   *
   * @return string Absolute path to the temporary file.
   * @task internal
   */
  public function __toString() {
    return $this->file;
  }


  /**
   * When the object is destroyed, it destroys the temporary file. You can
   * change this behavior with @{method:setPreserveFile}.
   *
   * @task internal
   */
  public function __destruct() {
    if ($this->destroyed) {
      return;
    }

    if ($this->preserve) {
      return;
    }

    Filesystem::remove($this->dir);

    // NOTE: tempnam() doesn't guarantee it will return a file inside the
    // directory you passed to the function, so we make sure to nuke the file
    // explicitly.

    Filesystem::remove($this->file);

    $this->file = null;
    $this->dir = null;
    $this->destroyed = true;
  }

}
